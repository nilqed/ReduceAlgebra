% "buildrlisp.lsp"
%
% Build a parser for Rlisp.
%

(rdf "vslcompat.lsp")

(dotimes (i 1000000) nil)

(de concat (u v)
    (compress (cons '!" (append (explode2 u)
                                (nconc (explode2 v) (list '!"))))))

(global '(oldchan!*))

(setq prolog_file 'cslprolo)

(setq rend_file 'cslrend)

(setq !*argnochk t)

(setq !*int nil)                    % Prevents input buffer being saved.

(setq !*msg nil)

% This is dervived fron the Standard LISP BOOT File.
% Author: Anthony C. Hearn.
% Copyright (c) 1991 RAND.  All Rights Reserved.

(fluid '(fname!* !*blockp !*lower !*mode))

(global '(oldchan!*))

(setq oldchan!* nil)

(global '(!*raise crchar!* cursym!* nxtsym!* ttype!* !$eol!$))

(put '!; 'switch!* '(nil !*semicol!*))

(put '!( 'switch!* '(nil !*lpar!*))

(put '!) 'switch!* '(nil !*rpar!*))

(put '!, 'switch!* '(nil !*comma!*))

(put '!. 'switch!* '(nil cons))

(put '!: 'switch!* '(((!= nil setq)) !*colon!*))

(put '!*comma!* 'infix 1)

(put 'setq 'infix 2)

(put 'cons 'infix 3)

(flag '(!*comma!*) 'nary)

(flag '(!*colon!* !*semicol!* end then else) 'delim)

(put 'begin 'stat 'blockstat)

(put 'if 'stat 'ifstat)

(put 'symbolic 'stat 'procstat)

(de begin2 nil
   (prog nil
      (setq cursym!* '!*semicol!*)
a     (cond
         ((eq cursym!* 'end) (progn (rds oldchan!*) (return nil)))
         (t (prin2 (errorset '(eval (form (xread nil))) t t)) ))
      (go a)))

(de form (u) u)

(de xread (u) (progn (scan) (xread1 u)))

(de xread1 (u)
   (prog (v w x y z z2)
a     (setq z cursym!*)
a1    (cond
         ((or (null (atom z)) (numberp z)) (setq y nil))
         ((flagp z 'delim) (go end1))
         ((eq z '!*lpar!*) (go lparen))
         ((eq z '!*rpar!*) (go end1))
         ((setq y (get z 'infix)) (go infx))
         ((setq y (get z 'stat)) (go stat)))
a3    (setq w (cons z w))
next  (setq z (scan))
      (go a1)
lparen(setq y nil)
      (cond
         ((eq (scan) '!*rpar!*)
            (and w (setq w (cons (list (car w)) (cdr w)))) )
         ((eqcar (setq z (xread1 'paren)) '!*comma!*)
            (setq w (cons (cons (car w) (cdr z)) (cdr w))))
         (t (go a3)))
      (go next)
infx  (setq z2 (mkvar (car w) z))
un1   (setq w (cdr w))
      (cond
         ((null w) (go un2))
         (t (setq z2 (cons (car w) (list z2)))) )
      (go un1)
un2   (setq v (cons z2 v))
preced(cond ((null x) (go pr4)) ((lessp y (car (car x))) (go pr2)))
pr1   (setq x (cons (cons y z) x))
      (go next)
pr2   (setq v
         (cons
            (cond
               ((and (eqcar (car v) (cdar x)) (flagp (cdar x) 'nary))
                  (cons (cdar x) (cons (cadr v) (cdar v))))
               (t (cons (cdar x) (list (cadr v) (car v)))) )
            (cdr (cdr v))))
      (setq x (cdr x))
      (go preced)
stat  (setq w (cons (eval (list y)) w))
      (setq y nil)
      (go a)
end1  (cond
         ((and (and (null v) (null w)) (null x)) (return nil))
         (t (setq y 0)))
      (go infx)
pr4   (cond ((null (equal y 0)) (go pr1)) (t (return (car v)))) ))

(de eqcar (u v) (and (null (atom u)) (eq (car u) v)))

(de mksetq (u v) (list 'setq u v))

(de mkvar (u v) u)

(de rread nil
   (prog (x)
      (setq x (token))
      (return
         (cond
            ((and (equal ttype!* 3) (eq x '!()) (rrdls))
            (t x)))) )

(de rrdls nil
   (prog (x r)
a     (setq x (rread))
      (cond
         ((null (equal ttype!* 3)) (go b))
         ((eq x '!)) (return (reverse r)))   % REVERSIP not yet defined.
         ((null (eq x '!.)) (go b)))
      (setq x (rread))
      (token)
      (return (nconc (reverse r) x))
b     (setq r (cons x r))
      (go a)))

(de token nil
   (prog (x y)
      (setq x crchar!*)
a     (cond
         ((seprp x) (go sepr))
         ((digit x) (go number))
         ((liter x) (go letter))
         ((eq x '!%) (go coment))
         ((eq x '!!) (go escape))
         ((eq x '!') (go quote))
         ((eq x '!") (go string)))
      (setq ttype!* 3)
      (cond ((delcp x) (go d)))
      (setq nxtsym!* x)
a1    (setq crchar!* (readch))
      (go c)
escape(setq y (cons x y))
      (setq x (readch))
letter(setq ttype!* 0)
let1  (setq y (cons x y))
      (cond
         ((or (digit (setq x (readch))) (liter x)) (go let1))
         ((eq x '!!) (go escape)))
      (setq nxtsym!* (intern (compress (reverse y))))
b     (setq crchar!* x)
c     (return nxtsym!*)
number(setq ttype!* 2)
num1  (setq y (cons x y))
      (cond ((digit (setq x (readch))) (go num1)))
      (setq nxtsym!* (compress (reverse y)))
      (go b)
quote (setq crchar!* (readch))
      (setq nxtsym!* (list 'quote (rread)))
      (setq ttype!* 4)
      (go c)
string(prog (raise !*lower)
         (setq raise !*raise)
         (setq !*raise nil)
   strinx(setq y (cons x y))
         (cond ((null (eq (setq x (readch)) '!")) (go strinx)))
         (setq y (cons x y))
         (setq nxtsym!* (mkstrng (compress (reverse y))))
         (setq !*raise raise))
      (setq ttype!* 1)
      (go a1)
coment(cond ((null (eq (readch) !$eol!$)) (go coment)))
sepr  (setq x (readch))
      (go a)
d     (setq nxtsym!* x)
      (setq crchar!* '! )
      (go c)))

(setq crchar!* '! )

(de delcp (u) (or (eq u '!;) (eq u '!$)))

(de mkstrng (u) u)

(de seprp (u) (or (eq u blank) (eq u tab) (eq u !$eol!$)))

(de scan nil
   (prog (x y)
      (cond ((null (eq cursym!* '!*semicol!*)) (go b)))
a     (setq nxtsym!* (token))
b     (cond
         ((or (null (atom nxtsym!*)) (numberp nxtsym!*)) (go l))
         ((and (setq x (get nxtsym!* 'newnam)) (setq nxtsym!* x))
            (go b))
         ((eq nxtsym!* 'comment) (go comm))
         ((and
             (eq nxtsym!* '!')
             (setq cursym!* (list 'quote (rread))))
            (go l1))
         ((null (setq x (get nxtsym!* 'switch!*))) (go l))
         ((eq (cadr x) '!*semicol!*)
            (return (setq cursym!* (cadr x)))) )
sw1   (setq nxtsym!* (token))
      (cond
         ((or
             (null (car x))
             (null (setq y (assoc nxtsym!* (car x)))) )
            (return (setq cursym!* (cadr x)))) )
      (setq x (cdr y))
      (go sw1)
comm  (cond ((eq (readch) '!;) (setq crchar!* '! )) (t (go comm)))
      (go a)
l     (setq cursym!*
         (cond
            ((null (eqcar nxtsym!* 'string)) nxtsym!*)
            (t (cons 'quote (cdr nxtsym!*)))) )
l1    (setq nxtsym!* (token))
      (return cursym!*)))

(de ifstat nil
   (prog (condx condit)
a     (setq condx (xread t))
      (setq condit (nconc condit (list (list condx (xread t)))) )
      (cond
         ((null (eq cursym!* 'else)) (go b))
         ((eq (scan) 'if) (go a))
         (t (setq condit
               (nconc condit (list (list t (xread1 t)))) )))
b     (return (cons 'cond condit))))

(de procstat nil
   (prog (x y)
      (cond ((eq cursym!* 'symbolic) (scan)))
      (cond
         ((eq cursym!* '!*semicol!*)
            (return (null (setq !*mode 'symbolic)))) )
      (setq fname!* (scan))
      (cond ((atom (setq x (xread1 nil))) (setq x (list x))))
      (setq y (xread nil))
      (cond ((flagp (car x) 'lose) (return nil)))
      (putd (car x) 'expr (list 'lambda (cdr x) y))
      (setq fname!* nil)
      (return (list 'quote (car x)))) )

(de blockstat nil
   (prog (x hold varlis !*blockp)
a0    (setq !*blockp t)
      (scan)
      (cond
         ((null (or (eq cursym!* 'integer) (eq cursym!* 'scalar)))
            (go a)))
      (setq x (xread nil))
      (setq varlis
         (nconc
            (cond ((eqcar x '!*comma!*) (cdr x)) (t (list x)))
            varlis))
      (go a0)
a     (setq hold (nconc hold (list (xread1 nil))))
      (setq x cursym!*)
      (scan)
      (cond ((not (eq x 'end)) (go a)))
      (return (mkprog varlis hold))))

(de mkprog (u v) (cons 'prog (cons u v)))

(de gostat nil
   (prog (x) (scan) (setq x (scan)) (scan) (return (list 'go x))))

(put 'go 'stat 'gostat)

(de rlis nil
   (prog (x)
      (setq x cursym!*)
      (return (list x (list 'quote (list (xread t)))))))

(de endstat nil (prog (x) (setq x cursym!*) (scan) (return (list x))))

% Now we have just enough to be able to start to express ourselves in
% (a subset of) rlisp.

(begin2)

rds(xxx := open("../packages/support/build.red", 'input));

(close xxx)

(load!-package!-sources prolog_file 'support)

(load!-package!-sources 'rlisp 'rlisp)

%(load!-package!-sources 'smacros 'support)

(load!-package!-sources rend_file 'support)

(load!-package!-sources 'poly 'poly)

(load!-package!-sources 'alg 'alg)

(load!-package!-sources 'arith 'arith)  %  Needed by roots, specfn*, (psl).

(load!-package!-sources 'entry 'support)

(load!-package!-sources 'remake 'support)

(setq !*comp nil)

%(load!-package!-sources 'support       'support)
%(load!-package!-sources 'rlisp         'rlisp)
%(load!-package!-sources 'alg           'alg)
%(load!-package!-sources 'poly          'poly)
(load!-package!-sources 'polydiv       'poly)
%(load!-package!-sources 'arith         'arith)
(load!-package!-sources 'mathpr        'mathpr)
(load!-package!-sources 'ezgcd         'factor)
(load!-package!-sources 'factor        'factor)
(load!-package!-sources 'hephys        'hephys)
(load!-package!-sources 'int           'int)
(load!-package!-sources 'matrix        'matrix)
% rlisp88 could change the syntax!
%(load!-package!-sources 'rlisp88       'rlisp88)
(load!-package!-sources 'rprint        'rprint)
(load!-package!-sources 'fmprint       'rprint)
(load!-package!-sources 'pretty        'rprint)
(load!-package!-sources 'solve         'solve)
(load!-package!-sources 'desir         'solve)
(load!-package!-sources 'ineq          'solve)
(load!-package!-sources 'modsr         'solve)
(load!-package!-sources 'rsolve        'solve)
(load!-package!-sources 'algint        'algint)
(load!-package!-sources 'arnum         'arnum)
(load!-package!-sources 'assist        'assist)
(load!-package!-sources 'dummy         'assist)
(load!-package!-sources 'cantens       'assist)
(load!-package!-sources 'atensor       'atensor)
% avector confuses many other packages by redefining "^".
%(load!-package!-sources 'avector       'avector)
(load!-package!-sources 'invbase       'invbase)
(load!-package!-sources 'misc          'misc)
(load!-package!-sources 'boolean       'misc)
(load!-package!-sources 'cedit         'misc)
(load!-package!-sources 'rcref         'misc)
(load!-package!-sources 'reset         'misc)
(load!-package!-sources 'cali          'cali)
(load!-package!-sources 'camal         'camal)
(load!-package!-sources 'changevr      'misc)
(load!-package!-sources 'compact       'misc)
(load!-package!-sources 'dfpart        'misc)
(load!-package!-sources 'lie           'misc)

(setq !*int t)

(preserve 'begin)

(stop 0)

