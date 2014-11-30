% genparser.red

% Author: Arthur Norman

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Id$

module 'genparser;


%=============================================================================
%
% This is an LALR(1) parser generator, which can take the
% specification of a grammar and construct tables that direct the
% generic parser skeleton.
%
%=============================================================================

%
% The entry-point of thie code will be lalr_construct_parser, defined
% towards the end of the file.
%

%
% A grammar is represented as a list of rules. A rule
%      sym : x y z { p q r }
%          | x y z { p q r }
%          ;
% maps onto the list
%      (sym   ((x y z) p q r)
%             ((x y z) p q r))
% and items on the right hand side can be symbols or strings. Strings
% stand for terminals. Symbols that are mentioned on a left hand side of
% a production are non-terminals, terminals should be written as strings
% or one of a range of special markers such as !:symbol, !:number,
% !:string or !:list.
% The term !:list refers to a Reduce-style Lisp quoted expression introduced
% with either a forward or a back-quote, as in
%       '(some quoted lisp-like data)
%

% Precedence can be applied using a call such as
%   lalr_precedence '(!:right "^" !:left ("*" "/") ("+" "-"));
% where terminal symbols are listed from highest to lowest precedence. The
% words !:left and !:right indicate that until further notice symbols
% associate in that direction. Symbols (represented as strings) can either
% be listed individually or put in groups that will then all share the same
% precedence levels. So in the above "^" has the highest precedence and
% it associates to the right. Next "*" and "/" associate to the left and
% have the same precedence - so for instance P*Q/R*S will mean (((P*Q)/R)*S).
% Finally "+" and "-" have equal but lower precedence. The default
% associativity will be !:left.
%                                   [not implemented yet]

% Here is an example of a rather trivial grammar where I have not put in
% an actions at all:

%    ((E    ((S))            The first symbol defined is the top-level
%           ((E "+" S))      target for the grammar.
%           ((E "-" S)))
%     (S    ((P))
%           ((S "*" P))
%           ((S "/" P)))
%     (P    (( "(" E ")" ))
%           ((!:symbol))     "!:symbol" and "!:number" are
%           ((!:number))))   items known to the lexer.

% It will also be possible to put a sequence of semantic actions associated
% with each production. For instance the start of the above could have
% read
%    ((E    ((S)         (print !$1))
%           ((E "+" S)   (list 'plus !$1 !$3))
%           ...
% and in semantic actions the symbol !$1 (etc) refer to the semantic
% values associated with the corresponding entity in the production. There
% may be several actions in a sequence and the value yielded by the final
% one is the value returned. If no semantic action is specified a default
% value will be returned. If there is only one symbol making up the
% right hand size of the production then the value is the value derived
% from that, otherwise it is a list of the values from each symbol.
% Thus to revisit the current example the default behaviour is as from
%    ((E    ((S)         !$1)
%           ((E "+" S)   (list !$1 !$2 !$3))


inline procedure lalr_productions x;
    get(x, 'produces);

inline procedure lalr_set_productions(x, y);
    put(x, 'produces, y);

%
% lalr_set_grammar G expects that G will be a list of productions
% in the format described earlier. The symbol mentioned on the left of the
% first production will be taken as the starting symbol. This just
% stores the grammar in places where I can work on it and collects
% simple basic information about it.
%

symbolic procedure lalr_set_grammar g;
  begin
    scalar name, vals, tnum, w;

    lex_cleanup();       % So that any previous grammar does not interfere.
    terminals := non_terminals := nil;

% I will start by augmenting the grammar with an initial production of the
% form "S' ::= S". For this to be valid the user had better not have used
% S' as the name of an existing non-terminal. The purpose of having an
% augmented grammar like this is so that when S' is ready to reduce the
% parser will "accept". Note I make that a capital "S" here. To be generous
% I will only do this if the name !S!' is not already being used, but if
% the user supplies a production for !S!' directly they had better do so in a
% way that does not upset things!
    if not assoc('!S!', g) then
      g := list('!S!', list list caar g) . g;

% Before doing a lot more I collect lists of symbols present in the grammar.
    for each x in g do <<
      name := car x; vals := cdr x;
% I build a list of the names that appear on the left of productions, and
% these are my non-terminals. I think this allows me to have several
% rules defining one non-terminal and the code collects and consolidates
% all the things it might have on the right hand side of productions.
      if name member non_terminals then
        vals := append(vals, lalr_productions name)
      else non_terminals := name . non_terminals;
      lalr_set_productions(name, vals) >>;

% Next I will collect the set of terminals. There are a few special
% symbols that will stand for predefined classes of item. Well maybe at
% some stage I will want to partition !:number into !:integer and
% !:float, or add !:space, !:eol ... but right now the list set up
% here is all I support. The meaning of these is:
%  !:eof         End of file.
%  !:symbol      Symbols can be either a single punctuation mark or
%                a letter followed by letters, digits and underscores,
%                subject to the sequence concerned not forming a terminal.
%                Any characters that is prefixed with an exclamation mark
%                is treated as a letter, but the poresence of an exclamation
%                mark will prevent the resulting item being accepred as
%                a terminal. Thus probably "<" would come out as a special
%                token for "less than" while "!<" is a !:symbol whose name
%                is spelt "<".
%  !:number      A string of digits, optionally followed by a "." and
%                perhaps more digits, optionally followed by and "e"
%                or "E", an optional sign and yet more digits. I expect that
%                at some stage I will add support for hex values as in
%                "0xffff" but that is not done yet.
%  !:string      Strings and enclosed in double quotes. A doubled
%                double-quote within can be used to include a single '"'
%                character within the string.
%  !:list        A "'" or "`" character followed by a Lisp-like S-expression.
%                This is a notation as used in Rlisp.

    terminals := nil;

    for each x in g do            % Each rule...
      for each vv in cdr x do   % ... may have multiple options
        for each v in car vv do if stringp v then % tokens in a production
          terminals := union(list v, terminals);
% I inform the lexer of the terminals that are to be processed, This will
% allocate numeric codes which are stored as the lex_code property of the
% symbol whose name matches the string concerned.
    lex_keywords terminals;
%
% It is handy to have a list of all the symbols that might arise - including
% both terminals and non-terminals. 
    symbols := append(non_terminals,
      append('(!:eof !:symbol !:string !:number !:list), terminals));
% I reverse the list of non-terminals here so that the starting symbol
% will be the first item.
    non_terminals := reversip non_terminals;
% Now I allocate numeric codes for all non-terminals, with 0 for the
% start symbol. On the stack terminals should be used to look up actions
% an non-terminals to look up gotos so I might believe I could re-use the
% same sequence of integer codes - but maybe would be cleaner to use non-
% overlapping ranges of values?
    tnum := -1;
    for each v in non_terminals do
      put(v, 'non_terminal_code, tnum := tnum+1);

    goto_cache := mkhash(length non_terminals, 1, 1.5);
    if !*lalr_verbose then lalr_display_symbols();

% Map all terminals in the productions onto their numeric codes. Start by
% building an association list that will help.
    w := nil;
    for each s in terminals do
      w := (s . get(intern s, 'lex_code)) . w;
    for each s in '(!:eof !:symbol !:string !:number !:list) do
      w := (s . get(s, 'lex_fixed_code)) . w;
% Use the map to re-work the list of productions.
    for each x in non_terminals do
      lalr_set_productions(x, 
        for each y in lalr_productions x collect
          sublis(w, car y) . cdr y);

% Map all actions onto numeric codes, such that identical actions all have the
% same code
    action_map := nil;
    tnum := -1;
    for each x in non_terminals do
      for each a in lalr_productions x do <<
% I will alloacte one action code for each case where I have a distinct
% non-terminal A with a number n of items in the associated production
% and a particular semantic action S.
        w := assoc((x . length car a) . cdr a, action_map);
        if null w then <<
          w := ((x . length car a) . cdr a) . (tnum := tnum + 1);
          action_map := w . action_map >>;
% I update the actual production to put the action's numeric code in
% in place of the action itself.
        rplacd(a, list cdr w) >>;
    action_map := reversip action_map;
    action_fn := mkvect sub1 tnum;
    action_n := mkvect8 sub1 tnum;
    action_A := mkvect16 sub1 tnum;
    action_first_error := tnum;
    if !*lalr_verbose then lalr_print_action_map();

% Now whenever I start to set up a new grammar I need the FIRST information
% so I may as well compute it here.
    lalr_calculate_first non_terminals;
% OK that is enough for now. I have accepted the grammar and set up basic
% information about it...
  end;

%
% Especially while I develop and debug this it matters to me that I have
% code that can display the LR-states and other bits of information that
% are worked with here - ideally in as neat a way as reasonable.

symbolic procedure lalr_prin_symbol x;
  begin
    scalar w;
% Item zero is a pseudo-token used to mark the end of input.
    if x = 0 then princ "$"
    else if x = nil then princ "<empty>"
    else if x = '!. then princ "."
    else if numberp x and (w := assoc(x, lex_codename)) then prin cdr w
    else if stringp x then prin x
% I print the name of the symbol in upper case even if it was in lower or
% mixed case internally. I might worry about the consequences if both (say)
% "L" and "l" occur in the same grammar!
    else for each c in explode2uc x do princ c
  end;

symbolic procedure lalr_decode_symbol x;
  begin
    scalar w;
    if x = 0 then return '!$eof!$
    else if x = nil then return nil
    else if x = '!. then return "."
    else if numberp x and (w := assoc(x, lex_codename)) then
      return cdr w
    else if stringp x then return x
    else return intern list2string (for each c in explode2uc x collect c)
  end;

symbolic procedure lalr_display_symbols();
  begin
    if not zerop posn() then terpri();
    princ "Terminal symbols are:"; terpri();
    for each x in '(!:eof !:symbol !:string !:number !:list) do <<
      princ " "; prin x;
      princ ":"; prin get(x, 'lex_fixed_code) >>;
    for each x in terminals do <<
      princ " "; prin x;
      princ ":"; prin get(intern x, 'lex_code) >>;
    terpri();
    princ "Non-terminal symbols are:"; terpri();
    for each x in non_terminals do begin
      scalar w;
      princ "["; prin get(x, 'non_terminal_code); princ "]";
      lalr_prin_symbol x;
      w := ":";
      for each y in lalr_productions x do <<
        ttab 20; princ w; w := "|";
        for each z in car y do << princ " "; lalr_prin_symbol z >>;
        if posn() > 48 then terpri();
        ttab 48;
        princ "{";
        if cdr y then for each z in cadr y do << princ " "; prin z >>;
        princ " }";
        terpri() >>;
      ttab 20;
      princ ";";
      terpri() end;
    terpri();
  end;

symbolic procedure lalr_print_action_map();
  begin
    princ "Action map:"; terpri();
    for each x in action_map do <<
      prin cdr x; princ ":"; ttab 12; prin cdar x; terpri() >>
  end;

% The intent is that lalr_cleanup() should tidy up ALL global state used
% while parse tables are being constructed. But it leaves the parse
% tables that are needed in use.

symbolic procedure lalr_cleanup();
  begin
    for each x in append(terminals, non_terminals) do <<
      remprop(x, 'produces);
      remprop(x, 'lalr_first);
      remprop(x, 'non_terminal_code) >>;
%   terminals := nil;
%   non_terminals := nil;    % needed by find_goto!
    symbols := nil;
    goto_cache := action_map := nil;
%   lex_cleanup()     % @@@@ review this!
  end;

symbolic procedure lalr_action(lhs, rhs);
  cdr assoc(rhs, lalr_productions lhs);

symbolic procedure lalr_print_firsts g;
  begin
    princ "FIRST sets for each non-terminal:"; terpri();
    for each x in g do <<
      lalr_prin_symbol x;
      princ ": ";
      ttab 15;
      for each y in sort(get(x, 'lalr_first), function ordp) do <<
        princ " "; lalr_prin_symbol y >>;
      terpri() >>
  end;

symbolic procedure lalr_calculate_first g;
% The "first" set associated with a non-terminal is a collection of all
% the terminals that could possibly be the first symbol of a string
% derived from it. Thus if there is any chain
%    S :   P Q R
%    P :   X Y Z
%    X :   a ...
% then a is in the first set of S.
%
% As an added complication if it is necessary to allow for cases such as
%    S :   P Q R  note that because P may be empty the first symbol of
%                 S may come from Q not P.
%    P :   X Y    note that there is a derivation from P to empty.
%    X :          note empty right hand size here.
%    Y :
%    Q :   a ...
  begin
    scalar w, y, z, more_added;
%   princ "lalr_calculate_first "; print g;
    for each x in g do
      if assoc(nil, lalr_productions x) then put(x, 'lalr_first, '(nil));
    repeat <<
      more_added := nil;
      for each x in g do <<
        z := get(x, 'lalr_first);
%       if !*lalr_verbose then <<
%         princ "[calculate_first] Scan "; prin x; princ " : "; prin z;
%         princ " / "; print lalr_productions x >>;
        for each y1 in lalr_productions x do <<
          y := car y1;
          while y and
                not numberp car y
                and member(nil, (w := get(car y, 'lalr_first))) do <<
            z := union(w, z);
            y := cdr y >>;
          if null y then nil
          else if numberp car y then z := union(list car y, z)
          else z := union(get(car y, 'lalr_first), z) >>;
        if z neq get(x, 'lalr_first) then more_added := t;
        put(x, 'lalr_first, z) >>
    >> until not more_added;
    if !*lalr_verbose then lalr_print_firsts g;
    return nil
  end;

symbolic procedure lalr_first l;
  begin
    scalar r, w;
    while l and
          not numberp car l and
          (nil member (w := get(car l, 'lalr_first))) do <<
      r := union(delete(nil, w), r);
      l := cdr l >>;
    if null l then r := nil . r
    else if numberp car l then r := union(list car l, r)
    else r := union(w, r);
    return r
  end;


% The next few procedures are as documented in Figure 4.38 of Red Dragon

symbolic procedure lalr_print_items(heading, cc);
  begin
    princ heading;
    terpri();
    for each y in cc do <<
      princ "Item number "; prin cdr y; terpri();
      for each x in sort(car y, function ordp) do <<
        princ "  "; lalr_prin_symbol caar x; princ " ->";
        for each y in cdar x do << princ " "; lalr_prin_symbol y >>;
        princ "  :  ";
        lalr_prin_symbol cadr x;
        terpri() >>;
      for each x in sort(hashcontents goto_cache, function ordp) do
        for each xx in cdr x do
          if car xx = cdr y then <<
            ttab 10; lalr_prin_symbol car x;
            princ " GOTO state "; prin cdr xx; terpri() >> >>;
    princ "End of ";
    printc heading
  end;

symbolic procedure lalr_items();
  begin
    scalar c, val, done, w, w1, w2, n, x1;
    val := lalr_productions '!S!';
    if cdr val then error(0, "Starting state must only reduce to one thing")
    else val := caar val;
    n := 0;
% This is where I introduce code zero for "$", the notional symbol that
% exists after the material that I actually parse.
    c := list (lalr_closure list list(('!S!' . '!. . val), 0) . n);
    repeat <<
      done := nil;
      for each i in c do
        for each x in symbols do <<
          x1 := (stringp x and get(intern x, 'lex_code)) or
                (idp x and get(x, 'lex_fixed_code));
          if null x1 then x1 := x;
          if w := lalr_goto(car i, x1) then <<
% The lalr_goto computed here is a new set of states. If it is EXACTLY
% one that has already been seen then all I need to do is update the
% goto cache.
            w1 := assoc(w, c);
            if w1 then <<
              w2 := gethash(x1, goto_cache);
              if not assoc(cdr i, w2) then
                puthash(x1, goto_cache, (cdr i . cdr w1) . w2) >>
% Here I should check if the core of the new item is the same as the core
% of any existing one, and if so I can merge. This operation is the one
% that will make this a characteristically LALR parser and performing the
% merge here will be the key to efficient generation of parsing tables.
% @@@@@@@@@@@@ work to do here @@@@@@@@@@@@@
%
%
% If the set has not been seen at all before then it should be allocated
% a number and added to my collection.
              else <<
                c := (w . (n := n + 1)) . c;
                puthash(x1, goto_cache,
                           (cdr i . n) . gethash(x1, goto_cache));
                done := t >> >> >>
    >> until not done;
    c := reversip c;   % So that item numbers come out in nicer order.
%
% I think that I can now manage without seeing the LR(1) items...
%   if !*lalr_verbose then lalr_print_items("LR(1) Items:", c);
%
    return c
  end;

% The closure of an item is obtained by taking a set of productions that
% each have a dot and adding new ones using the rule that if the
% sequence ... DOT v ... is present and the grammar contains a rule
% v : x y z then "v : DOT x y z" will be added to the set. 

symbolic procedure lalr_closure i;
  begin
    scalar pending, a, rule, tail, done, ff, w;
    pending := i;
    while pending do <<
      ff := car pending;  % [(A -> alpha . B beta), a]
      pending := cdr pending;
      rule := car ff; a := cadr ff; tail := cdr ('!. member rule);
      if tail and not numberp car tail then <<
        ff := lalr_first append(cdr tail, list a);
        for each p in lalr_productions car tail do
          for each b in ff do <<
            w := list(car tail . '!. . car p, b);
% It might be better to store items as hash tables, since then the
% member-check here would be much faster.
            if not (w member i) then <<
              i := w . i;
              pending := w . pending >> >> >> >>;
    return i
  end;


% A key operation in the construction of the parsing tables is that
% of moving an index along a list of symbols. The index is conventionally
% indicted by a dot.
%    lalr_move_dot(z, x)
% takes a list which should have a dot somewhere in it, and if it finds
%      ... DOT x ...
% it will return an updated list with the dot moved, i.e.
%      ... x DOT ...
% while if the symbol after the dot is not an x it will return nil as
% an indication that moving the dot is not to be done here.

symbolic procedure lalr_move_dot(z, x);
  begin
    scalar r;
    while not (car z = '!.) do <<
      r := car z . r;
      z := cdr z >>;
    z := cdr z;
    if not (z and car z = x) then return nil;
    z := car z . '!. . cdr z;
    while r do <<
      z := car r . z;
      r := cdr r >>;
    return z
  end;

% lalr_goto(i, x) takes a list of states (which contain lists each with a
% dot in) and a symbol x. It uses lalr_move_dot to try to move the dot
% forward across an x. It collects all the resulting new configurations.
% At the end it forms the closure of what it has found.

symbolic procedure lalr_goto(i, x);
  begin
    scalar j, w;
    for each z in i do <<
      w := lalr_move_dot(car z, x);
      if w then j := list(w, cadr z) . j >>;
    return lalr_closure j
  end;

symbolic procedure lalr_cached_goto(i, x);
  cdr assoc(i, gethash(x, goto_cache));

% Next part of Algorithm 4.11 from the Red Dragon

symbolic procedure lalr_remove_duplicates x;
  begin
    scalar r;
    if null x then return nil;
    x := sort(x, function ordp);
    r := list car x;
    x := cdr x;
    while x do <<
      if not (car x = car r) then r := car x . r;
      x := cdr x >>;
    return r
  end;

symbolic procedure lalr_core i;
  lalr_remove_duplicates for each x in car i collect car x;

symbolic procedure lalr_same_core(i1, i2);
  lalr_core i1 = lalr_core i2;

% cc is a list of items, while i is a single item. If cc already contains
% an item with the same core as I then merge i into that, and adjust any
% goto records either out of or into i to refer now to the thing merged
% with.

symbolic procedure lalr_insert_core(i, cc);
 if null cc then list i
 else if lalr_same_core(i, car cc) then <<
   renamings := (cdr i . cdar cc) . renamings;
   (union(car i, caar cc) . cdar cc) . cdr cc >>
 else car cc . lalr_insert_core(i, cdr cc);

symbolic procedure lalr_rename_gotos();
  begin
    scalar w, x1;
    for each x in symbols do <<
      x1 := (stringp x and get(intern x, 'lex_code)) or
            (idp x and get(x, 'lex_fixed_code));
      if null x1 then x1 := x;
      w := sublis(renamings, gethash(x1, goto_cache));
      puthash(x1, goto_cache, lalr_remove_duplicates w) >>
  end;

% Part of Algorithm 4.10 of the Red Dragon

symbolic procedure lalr_print_actions action_table;
  begin
    scalar w;
    princ "Actions:"; terpri();
    for each x in action_table do
      for each xx in cdr x do <<
        prin car x;  ttab 20;
        lalr_prin_symbol car xx; ttab 40;
        w := cadr xx;
        if eqcar(w, 'reduce) then <<
          princ "reduce ";
          lalr_prin_symbol caadr w;
          princ " ->";
          for each v in cdadr w do << princ " "; lalr_prin_symbol v >>;
          princ " {";
          for each v in caddr w do << princ " "; prin v >>;
          princ " }";
          terpri() >>
        else << prin w; terpri() >> >>
  end;

fluid '(lalr_action_counter);
lalr_action_counter := 0;

% I create names for the functions that implement semantic actions. Well
% I could base them on a checksum of the action itself, but using a simple
% sequence is easier.

symbolic procedure lalr_gensym();
  intern concat("lalr_action_function_",
    list2string explode (lalr_action_counter := add1 lalr_action_counter));

symbolic procedure lalr_make_arglist n;
  for i := 1:n collect
    intern list2string ('!$ . explode2 i);

symbolic procedure lalr_make_actions c;
  begin
    scalar action_table, aa, j, w;
    for each i in c do <<
      aa := nil;
      for each r in car i do <<
        w := cdr ('!. member cdar r);
        if w and numberp car w then <<
          j := lalr_cached_goto(cdr i, car w);
          aa := list(car w, list('shift, j)) . aa >>
        else if null w and not (caar r = '!S!') then <<
          w := reverse cdr reverse car r;
          aa := list(cadr r, list('reduce, w, lalr_action(car w, cdr w))) .
                aa >>
        else if null w and caar r = '!S!' then
          aa := list(0, 'accept) . aa >>;
        action_table := (cdr i . lalr_remove_duplicates aa) . action_table >>;
    action_index := mkvect16 caar action_table;
    action_table := reversip action_table;
    if !*lalr_verbose then lalr_print_actions action_table;
    printc "ACTION_TABLE = ";
    for each x in action_table do <<
      princ "(";
      prin car x;
      for each y in cdr x do <<
        if cdr x and cadr x neq y then terpri(); % all but first
        ttab 6;
        prin y >>;
      printc ")" >>;
    j := 0; w := nil;
    for each x in action_table do <<
      putv16(action_index, car x, j);
      for each y on cdr x do begin
        scalar tt, rr, rx, ff, fn, rn, rA;
% The final terminal in each search-chunk will be stored as
% "-1" which is a wild-card. This will then be the action that is
% carried out if a syntax error is present.
        if null cdr y then tt := -1 else tt := caar y;
        rr := cadar y;
        if rr = 'accept then rr := 0
        else if car rr = 'shift then rr := cadr rr
        else <<  % (reduce (A b c d) (rule#))
          rr := cdr rr;
%         princ "REDUCE "; prin car rr; princ " : "; print cadr rr;
          rx := caadr rr;       % index of semantic action
          ra := caar rr;        % non-terminal to reduce to
          rn := length cdar rr; % number of items to pop
%         princ "Semantic Action "; prin list rn;
%         princ "  "; print rassoc(rx, action_map);
          ff := rassoc(rx, action_map);
          if ff then ff := car ff;
% ff is now ((A . n) . '(s1 s2 ...)) where A is the non-terminal,
% n the number of items on the RHS of the production and the sequence
% s1, s2,... is the semantic action list. If the action list is empty
% I will put nil as the action function, otherwise I will construct
% a function to call.
%print list("rx=", rx, "rn=", rn, "ra=", ra);
          if null cdr ff then putv(action_fn, rx-1, nil)
          else <<
            fn := cdr ff;
            ff := 'lambda . lalr_make_arglist cdar ff . fn;
%           prettyprint ff; % @@@
            fn := lalr_gensym(); % Name for generated function
% I do not want messages from the Lisp compiler here!
            putd(fn, 'expr, ff) where !*pwrds = nil;
            putv(action_fn, rx-1, fn) >>;
          putv8(action_n, rx-1, rn);
          putv16(action_A, rx-1, get(ra, 'non_terminal_code));
          rr := -rx >>;
          w := (tt . rr) . w;
          j := j + 1 end >>;
    action_terminal := mkvect16 sub1 j;
    action_result := mkvect16 sub1 j;
    while j > 0 do <<
      j := j - 1;
      putv16(action_terminal, j, caar w);
      putv16(action_result, j, cdar w);
      w := cdr w >>
  end;

symbolic procedure lalr_most_common_dest p;
  begin
    scalar r, w;
    for each x in p do
      if (w := assoc(cdr x, r)) then rplacd(w, cdr w + 1)
      else r := (cdr x . 1) . r;
    w := car r;
    for each x in cdr r do if cdr x > cdr w then w := x;
    return car w
  end;

symbolic procedure printvec v;
  begin
    scalar ch;
    ch := '![;
    for i := 0:upbv v do <<
      princ ch;
      ch := '! ;
      prin getv(v, i) >>;
    princ '!];
    terpri();
    return v
  end;

% I display something that is notionally a vector of bytes using the
% format
%      #V8[b0, b1, ..., bn]
% and one that will contain 16-bit values as
%      #V16[w0, w1, ..., wn]
% and in CSL I have specialist arrays that provide support for just that -
% however I can use regular Lisp arrays instead with only modest waste of
% space and that is what I do on PSL.

symbolic procedure print8 v;
  begin
    scalar ch;
    ch := '!#!V8![;
    for i := 0:upbv v do <<
      princ ch;
      ch := '! ;
      prin getv8(v, i) >>;
    princ '!];
    terpri();
    return v
  end;

symbolic procedure print16 v;
  begin
    scalar ch;
    ch := '!#!V16![;
    for i := 0:upbv v do <<
      princ ch;
      ch := '! ;
      prin getv16(v, i) >>;
    princ '!];
    terpri();
    return v
  end;

symbolic procedure lalr_make_gotos();
  begin
    scalar p, r1, w, r;
    p := 0;
    for each x in sort(hashcontents goto_cache, function ordp) do
      if not numberp car x then <<
        if !*lalr_verbose then
          for each xx in cdr x do <<
            prin car xx; ttab 10; lalr_prin_symbol car x;
          princ " GOTO state "; prin cdr xx; terpri() >>;
          w := get(car x, 'non_terminal_code);
          if not fixp w then error(99, list('lalr_make_gotos, x, w));
          r1 := (w . p) . r1;
          if cdr x then <<
            w := lalr_most_common_dest cdr x;
            for each xx in cdr x do if not (cdr xx = w) then <<
              r := xx . r;
              p := p + 1 >>;
            r := ((-1) . w) . r;
            p := p + 1 >> >>;
    goto_index := mkvect16 sub1 length non_terminals;
    goto_old_state := mkvect16 sub1 p;
    goto_new_state := mkvect16 sub1 p;
    for each x in r1 do putv16(goto_index, car x, cdr x);
    while p > 0 do <<
      p := p - 1;
      putv16(goto_old_state, p, caar r);
      putv16(goto_new_state, p, cdar r);
      r := cdr r >>;
    princ "goto_index: ";     print16 goto_index;
    princ "goto_old_state: "; print16 goto_old_state;
    princ "goto_new_state: "; print16 goto_new_state
  end;

% A main driver function that performs all the steps involved
% in building parse tables for a given grammar.

symbolic procedure lalr_construct_parser g;
  begin
    scalar c, cc, renamings;
    lalr_set_grammar g;
%
% The procedure used here at present is a naive one that first creates
% a full set of LR(1) items and only then detects commonalities. For
% medium to large grammars this will be infeasibly inefficient, so it
% will be important to do the merging on-the-fly as the various sets
% are collected. However this one is simple (or at least simpler) to
% understand and code and maybe works well enough for small grammars.
%
    c := lalr_items();
    renamings := nil;
    for each i in c do cc := lalr_insert_core(i, cc);
    lalr_rename_gotos();
    if !*lalr_verbose then lalr_print_items("Merged Items:", cc);
    lalr_make_actions cc;
    princ "action_index "; print16 action_index;
    princ "action_terminal "; print16 action_terminal;
    princ "action_result "; print16 action_result;
    princ "action_fn "; printvec action_fn;
    princ "action_n "; print8 action_n;
    princ "action_A "; print16 action_A;
    lalr_make_gotos();
    lalr_cleanup()
  end;

endmodule;

end;

