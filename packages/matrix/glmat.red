module glmat; % Routines for inverting matrices and finding eigen-values
              % and vectors. Methods are the same as in glsolve module.

% Author: Eberhard Schruefer.
% Modification: James Davenport and Fran Burstall.

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


fluid '(!*cramer !*factor !*gcd !*sqfree !*sub2 kord!*);

global '(!!arbint);

if null !!arbint then !!arbint := 0;

switch cramer;

put('cramer,'simpfg,
    '((t (put 'mat 'lnrsolvefn 'clnrsolve)
     (put 'mat 'inversefn 'matinv))
      (nil (put 'mat 'lnrsolvefn 'lnrsolve)
       (put 'mat 'inversefn 'matinverse))));

% algebraic operator arbcomplex;

% Done this way since it's also defined in the solve1 module.

deflist('((arbcomplex simpiden)),'simpfn);

symbolic procedure clnrsolve(u,v);
   % Interface to matrix package.
   multm(matinv u,v);

symbolic procedure minv u;
   matinv matsm u;

put('minv,'rtypefn,'quotematrix);

%put('mateigen,'rtypefn,'quotematrix);

remprop('mateigen,'rtypefn);

symbolic procedure matinv u;
   % U is a matrix form. Result is the inverse of matrix u.
   begin scalar sgn,x,y,z,!*exp;
     integer l,m,lm;
     !*exp := t;
     z := 1;
     lm := length car u;
     for each v in u do
       <<y := 1;
     for each w in v do y := lcm(y,denr w);
     m := lm;
     x := list(nil . (l := l + 1)) .* negf y .+ nil;
     for each j in reverse v do
       <<if numr j then
        x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
         m := m - 1>>;
     z := c!:extmult(x,z)>>;
      if singularchk lpow z then rerror(matrix,13,"Singular matrix");
     sgn := evenp length lpow z;
      return for each k in lpow z collect
          <<sgn := not sgn;
            for each j in lpow z collect mkglimat(k,z,sgn,j)>>
   end;

symbolic procedure singularchk u; pairp car lastpair u;

flag('(mateigen),'opfn);

flag('(mateigen),'noval);

symbolic procedure mateigen(u,eival);
   % U is a matrix form, eival an indeterminate naming the eigenvalues.
   % Result is a list of lists:
   %   {{eival-eq1,multiplicity1,eigenvector1},....},
   % where eival-eq is a polynomial and eigenvector is a matrix.
%    How much should we attempt to solve the eigenvalue eq.? sqfr?
%    Sqfr is necessary if we want to have the full eigenspace. If there
%    are multiple roots another pass through eigenvector calculation
%    is needed(done).
%    We should actually perform the calculations in the extension
%    field generated by the eigenvalue equation(done inside).
  begin scalar arbvars,exu,sgn,q,r,s,x,y,z,eivec,!*factor,!*sqfree,
               !*exp;
        integer l;
     !*exp := t;
     if not(getrtype u eq 'matrix) then typerr(u,"matrix");
     eival := !*a2k eival;
     kord!* := eival . kord!*;
     exu := mateigen1(matsm u,eival);
     q := car exu;
     y := cadr exu;
     z := caddr exu;
     exu := cdddr exu;
     !*sqfree := t;
     for each j in cdr fctrf numr subs2(lc z ./ 1)
          do if null domainp car j and mvar car j eq eival
                then s := (if null red car j
                              then !*k2f mvar car j . (ldeg car j*cdr j)
                            else j) . s;
     for each j in q
       do (if x then rplacd(x,cdr x + cdr j)
             else s := (y . cdr j) . s)
            where x := assoc(y,s) where y := absf reorder car j;
     l := length s;
     r := 'list .
       for each j in s collect
     <<if null((cdr j = 1) and (l = 1)) then
         <<y := 1;
           for each k in exu do
         if x := reduce!-mod!-eig(car j,c!:extmult(k,y))
           then y := x>>;
       arbvars := nil;
       for each k in lpow z do
          if (y=1) or null(k member lpow y) then
         arbvars := (k . makearbcomplex()) . arbvars;
       sgn := (y=1) or evenp length lpow y;
       eivec := 'mat . for each k in lpow z collect list
                           if x := assoc(k,arbvars)
                              then mvar cdr x
                            else prepsq!* mkgleig(k,y,
                                    sgn := not sgn,arbvars);
       list('list,prepsq!*(car j ./ 1),cdr j,eivec)>>;
     kord!* := cdr kord!*;
     return r
   end;

symbolic procedure mateigen1(u,eival);
   begin scalar q,x,y,z; integer l,lm,m;
      lm := length car u;
      z := 1;
      u := for each v in u collect
          <<y := 1;
        for each w in v do y := lcm(y,denr w);
        m := lm;
        l := l + 1;
        x := nil;
        for each j in reverse v do
          <<if numr j or l = m then
            x := list m .* multf(if l = m then
                                  addf(numr j,
                                       negf multf(!*k2f eival,
                                                  denr j)) else numr j,
                                 quotf(y,denr j)) .+ x;
            m := m - 1>>;
        y := z;
        z := c!:extmult(if null red x then <<
               q := (if p then (car p  . (cdr p + 1)) . delete(p,q)
                      else (lc x  . 1) . q) where p = assoc(lc x,q);
                        !*p2f lpow x>> else x,z);
        x>>;
      return q . y . z . u
   end;

symbolic procedure reduce!-mod!-eig(u,v);
   % Reduces exterior product v wrt eigenvalue equation u.
   begin scalar x,y;
     for each j on v do
       if numr(y := reduce!-mod!-eigf(u,lc j)) then
      x := lpow j .* y .+ x;
     y := 1;
     for each j on x do y := lcm(y,denr lc j);
     return for each j on reverse x collect
          lpow j .* multf(numr lc j,quotf(y,denr lc j))
   end;

symbolic procedure reduce!-mod!-eigf(u,v);
   (subs2 reduce!-eival!-powers(lpow u . negsq cancel(red u ./ lc u),v))
    where !*sub2 = !*sub2;

symbolic procedure reduce!-eival!-powers(v,u);
   if domainp u or null(mvar u eq caar v) then u ./ 1
    else reduce!-eival!-powers1(v,u ./ 1);

symbolic procedure reduce!-eival!-powers1(v,u);
   % Reduces powers with the help of the eigenvalue polynomial.
   if domainp numr u or (ldeg numr u<pdeg car v) then u
    else if ldeg numr u=pdeg car v then
        addsq(multsq(cdr v,lc numr u ./ denr u),
          red numr u ./ denr u)
   else reduce!-eival!-powers1(v,
    addsq(multsq(multpf(mvar numr u .** (ldeg numr u-pdeg car v),
                lc numr u) ./ denr u,
         cdr v),red numr u ./ denr u));

% Determinant calculation using exterior multiplication.

symbolic procedure detex u;
   % U is a matrix form, result is determinant of u.
   begin scalar f,x,y,z;
     integer m,lm;
     z := 1;
     u := matsm car u;
     lm := length car u;
     f := 1;
     for each v in u do
       <<y := 1;
     for each w in v do y := lcm(y,denr w);
     f := multf(y,f);
     m := lm;
     x := nil;
     for each j in v do
       <<if numr j then
        x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
         m := m - 1>>;
     z := c!:extmult(x,z)>>;
      return cancel(lc z ./ f)
   end;

% Not supported at algebraic user level since it is in general slower
% than other methods.

% put('detex,'simpfn,'detex);

symbolic procedure mkglimat(u,v,sgn,k);
   begin scalar s,x,y;
     x := nil ./ 1;
     y := lpow v;
     for each j on red v do
       if s := glmatterm(u,y,j,k)
      then x := addsq(cancel(s ./ lc v),x);
     return if sgn then negsq x else x
   end;

symbolic procedure glmatterm(u,v,w,k);
   begin scalar x,y,sgn;
     x := lpow w;
     a: if null x then return
       if pairp car y and (cdar y = k) then lc w else nil;
    if car x = u then return nil
         else if car x member v then <<x := cdr x;
                     if y then sgn := not sgn>>
         else if y then return nil
               else <<y := list car x; x := cdr x>>;
        go to a
   end;

symbolic procedure mkgleig(u,v,sgn,arbvars);
   begin scalar s,x,y,!*gcd;
     x := nil ./ 1;
     y := lpow v;
     !*gcd := t;
     for each j on red v do
       if s := glsoleig(u,y,j,arbvars)
      then x := addsq(cancel(s ./ lc v),x);
     return if sgn then negsq x else x
   end;

symbolic procedure glsoleig(u,v,w,arbvars);
   begin scalar x,y,sgn;
     x := lpow w;
     a: if null x then return
           if null car y then lc w
        else multf(cdr assoc(car y,arbvars),
               if sgn then negf lc w else lc w);
        if car x = u then return nil
         else if car x member v then <<x := cdr x;
                     if y then sgn := not sgn>>
         else if y then return nil
               else <<y := list car x; x := cdr x>>;
        go to a
   end;


%**** Support for exterior multiplication ****
% Data structure is lpow ::= list of col.-ind. in exterior product
%                            | nil . number of eq. for inhomog. terms.
%                   lc   ::= standard form


% Exterior multiplication and p-forms:
% Let V be a vector space of dimension n.
% We call the elements of V 1-forms and build new objects called
% p-forms as follows: define a multiplication on 1-forms ^ such that
%                v^w=-w^v
% then the linear span of such objects is the space of 2-forms and has
% dimension n(n-1)/2.  Indeed, if v_1,...,v_n is a basis of V then
% v_i^v_j for i<j is a basis for the 2-forms.
% We extend this multiplication (called exterior multiplication)
% to get products of p vectors, linear combinations of which are
% called p-forms: this extension is defined by the rule that v_1^...^v_p
% vanishes whenever some v_i=v_j (for i not j).  Thus the effect of
% permuting the order of the vectors in such a product is to multiply
% the product by the sign of the permutation.
% Using this it is not difficult to show:
% Theorem: Vectors v_1,...,v_p are linear independent iff their exterior
% product v_1^...^v_p is non-zero.
%
% For more information see F. Warner "Foundations of Differentiable
% Manifolds and Lie Groups" (Springer) Chapter 2. (Or any other book
% on differential geometry or multilinear algebra

symbolic procedure c!:extmult(u,v);
   % Special exterior multiplication routine. Degree of form v is
   % arbitrary, u is a one-form.
   if null u or null v then  nil
    else if v = 1 then u                   %unity
%   else (if x then cdr x .* (if car x
%                        then negf c!:subs2multf(lc u,lc v)
%          else c!:subs2multf(lc u,lc v))
%             .+ c!:extadd(c!:extmult(!*t2f lt u,red v),
%             ^^ this is bogus: .+ may not be valid in this circumstance
%                      c!:extmult(red u,v))
    else (if x then
             c!:extadd(cdr x .* (if car x
                                 then negf c!:subs2multf(lc u,lc v)
                   else c!:subs2multf(lc u,lc v)) .+ nil,
                       c!:extadd(c!:extmult(!*t2f lt u,red v),
                                 c!:extmult(red u,v)))
       else c!:extadd(c!:extmult(!*t2f lt u,red v),
              c!:extmult(red u,v)))
      where x = c!:ordexn(car lpow u,lpow v);

symbolic procedure c!:subs2multf(u,v);
   (if denr x neq 1 then rerror(matrix,14,"Sub error in glnrsolve")
     else numr x)
   where x = subs2(multf(u,v) ./ 1) where !*sub2 = !*sub2;


symbolic procedure c!:extadd(u,v);
   if null u then v
    else if null v then u
    else if lpow u = lpow v then
            (lambda x,y; if null x then y else lpow u .* x .+ y)
        (addf(lc u,lc v),c!:extadd(red u,red v))
    else if c!:ordexp(lpow u,lpow v) then lt u .+ c!:extadd(red u,v)
    else lt v .+ c!:extadd(u,red v);

symbolic procedure c!:ordexp(u,v);
   if null u then t
    else if car u = car v then c!:ordexp(cdr u,cdr v)
    else c!:ordxp(car u,car v);

symbolic procedure c!:ordexn(u,v);
   % U is a single index, v a list. Returns nil if u is a member
   % of v or a dotted pair of a permutation indicator and the ordered
   % list of u merged into v.
   begin scalar s,x;
     a: if null v then return(s . reverse(u . x))
     else if (u = car v) or (pairp u and pairp car v)
         then return nil
     else if c!:ordxp(u,car v) then
         return(s . append(reverse(u . x),v))
         else  <<x := car v . x;
                 v := cdr v;
                 s := not s>>;
         go to a
   end;

symbolic procedure c!:ordxp(u,v);
   if pairp u then if pairp v then cdr u < cdr v
            else nil
    else if pairp v then t
    else u < v;

endmodule;

end;