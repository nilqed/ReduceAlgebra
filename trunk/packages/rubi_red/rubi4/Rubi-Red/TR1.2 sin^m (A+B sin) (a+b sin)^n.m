(* ::Package:: *)

(************************************************************************)
(* This file was generated automatically by the Mathematica front end.  *)
(* It contains Initialization cells from a Notebook file, which         *)
(* typically will have the same name as this file except ending in      *)
(* ".nb" instead of ".m".                                               *)
(*                                                                      *)
(* This file is intended to be loaded into the Mathematica kernel using *)
(* the package loading commands Get or Needs.  Doing so is equivalent   *)
(* to using the Evaluate Initialization Cells menu command in the front *)
(* end.                                                                 *)
(*                                                                      *)
(* DO NOT EDIT THIS FILE.  This entire file is regenerated              *)
(* automatically each time the parent Notebook file is saved in the     *)
(* Mathematica front end.  Any changes you make to this file will be    *)
(* overwritten.                                                         *)
(************************************************************************)



(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(b_*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  A*Int[(b*Sin[c+d*x])^n,x] + B/b*Int[(b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{b,c,d,A,B,n},x]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  B/b*Int[(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B,n},x] && ZeroQ[A*b-a*B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  (2*a*A+b*B)*x/2 - b*B*Cos[c+d*x]*Sin[c+d*x]/(2*d) /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A*b+a*B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  (2*a*A+b*B)*x/2 - b*B*Cos[c+d*x]*Sin[c+d*x]/(2*d) + (A*b+a*B)*Int[Sin[c+d*x],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[A*b+a*B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  B*x/b + (A*b-a*B)/b*Int[1/(a+b*Sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(d*(n+1)) /;
FreeQ[{a,b,c,d,A,B,n},x] && ZeroQ[a^2-b^2] && ZeroQ[B*a*n+A*b*(n+1)]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(d*(n+1)) + 
  (a*B*n+A*b*(n+1))/(b*(n+1))*Int[(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[n] && n>-1 && n!=1 && NonzeroQ[a*B*n+A*b*(n+1)]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  (A*b-a*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(a*d*(2*n+1)) + 
  (a*B*n+A*b*(n+1))/(a*b*(2*n+1))*Int[(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1 && NonzeroQ[a*B*n+A*b*(n+1)]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(d*(n+1)) + 
  1/(n+1)*Int[Simp[b*B*n+a*A*(n+1)+(a*B*n+A*b*(n+1))*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^(n-1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[n] && n>0 && n!=1


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  B/b*Int[Sqrt[a+b*Sin[c+d*x]],x] +
  (A*b-a*B)/b*Int[1/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(A*b-a*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(d*(n+1)*(a^2-b^2)) +
  1/((n+1)*(a^2-b^2))*
    Int[Simp[(a*A-b*B)*(n+1)-(A*b-a*B)*(n+2)*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Defer[Int][(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,n},x]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_+B_.*sin[c_.+d_.*x_])*(b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  1/b^m*Int[(A+B*Sin[c+d*x])*(b*Sin[c+d*x])^(m+n),x] /;
FreeQ[{b,c,d,A,B,n},x] && IntegerQ[m]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(b_*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  b^(n-1/2)*Sqrt[b*Sin[c+d*x]]/Sqrt[Sin[c+d*x]]*Int[Sin[c+d*x]^(m+n)*(A+B*Sin[c+d*x]),x] /;
FreeQ[{b,c,d,A,B},x] && Not[IntegerQ[m]] && PositiveIntegerQ[n+1/2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(b_*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  b^(n+1/2)*Sqrt[Sin[c+d*x]]/Sqrt[b*Sin[c+d*x]]*Int[Sin[c+d*x]^(m+n)*(A+B*Sin[c+d*x]),x] /;
FreeQ[{b,c,d,A,B},x] && Not[IntegerQ[m]] && NegativeIntegerQ[n-1/2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  (b*Sin[c+d*x])^n/Sin[c+d*x]^n*Int[Sin[c+d*x]^(m+n)*(A+B*Sin[c+d*x]),x] /;
FreeQ[{b,c,d,A,B,m,n},x] && Not[IntegerQ[m]] && Not[IntegerQ[n-1/2]]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  B/b*Int[Sin[c+d*x]^m*(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B,m,n},x] && ZeroQ[A*b-a*B]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -b*B*Cos[c+d*x]*Sin[c+d*x]^(m+1)/(d*(m+2)) + 
  1/(m+2)*Int[Sin[c+d*x]^m*Simp[a*A*(m+2)+b*B*(m+1)+(A*b+a*B)*(m+2)*Sin[c+d*x],x],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && RationalQ[m] && m>=-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  a*A*Cos[c+d*x]*Sin[c+d*x]^(m+1)/(d*(m+1)) + 
  1/(m+1)*Int[Sin[c+d*x]^(m+1)*Simp[(A*b+a*B)*(m+1)+(a*A*(m+2)+b*B*(m+1))*Sin[c+d*x],x],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && RationalQ[m] && m<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -B*Cos[c+d*x]/(b*d) + 
  (A*b-a*B)/b*Int[Sin[c+d*x]/(a+b*Sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+2)) + 
  1/(b*(n+2))*Int[Simp[b*B*(n+1)-(a*B-A*b*(n+2))*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && RationalQ[n] && n>-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(a*A-b*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(a*d*(2*n+1)) + 
  1/(a^2*(2*n+1))*Int[Simp[n*(A*b-a*B)+b*B*(2*n+1)*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && RationalQ[n] && n<-1 && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  a*(A*b-a*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+1)*(a^2-b^2)) - 
  1/(b*(n+1)*(a^2-b^2))*
    Int[Simp[b*(n+1)*(A*b-a*B)+(a^2*B-a*A*b*(n+2)+b^2*B*(n+1))*Sin[c+d*x],x]*
      (a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && RationalQ[n] && n<-1 && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -A*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^n/(d*(n+1)) /;
FreeQ[{a,b,c,d,A,B,m,n},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && ZeroQ[m+n+2] && ZeroQ[A*b*n+a*B*(n+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -A*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^n/(d*(n+1)) + 
  (A*b*n+a*B*(n+1))/(a*(n+1))*Int[Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && NonzeroQ[A*b*n+a*B*(n+1)] && RationalQ[m,n] && m+n+2==0 && n>-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(A*b-a*B)*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^n/(b*d*(2*n+1)) + 
  (A*b*n+a*B*(n+1))/(a^2*(2*n+1))*Int[Sin[c+d*x]^m*(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && NonzeroQ[A*b*n+a*B*(n+1)] && RationalQ[m,n] && m+n+2==0 && n<=-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  a*A*Cos[c+d*x]*Sin[c+d*x]^(m+1)/(d*(m+1)*Sqrt[a+b*Sin[c+d*x]]) /;
FreeQ[{a,b,c,d,A,B,m},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && ZeroQ[2*a*B*(m+1)+A*b*(2*m+3)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -2*b*B*Cos[c+d*x]*Sin[c+d*x]^(m+1)/(d*(2*m+3)*Sqrt[a+b*Sin[c+d*x]]) + 
  (2*a*B*(m+1)+A*b*(2*m+3))/(b*(2*m+3))*Int[Sin[c+d*x]^m*Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && NonzeroQ[2*a*B*(m+1)+A*b*(2*m+3)] && RationalQ[m] && m>=-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  a*A*Cos[c+d*x]*Sin[c+d*x]^(m+1)/(d*(m+1)*Sqrt[a+b*Sin[c+d*x]]) + 
  (2*a*B*(m+1)+A*b*(2*m+3))/(2*a*(m+1))*Int[Sin[c+d*x]^(m+1)*Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && NonzeroQ[2*a*B*(m+1)+A*b*(2*m+3)] && RationalQ[m] && m<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -b*B*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^(n-1)/(d*(m+n+1)) + 
  1/(m+n+1)*
    Int[Sin[c+d*x]^m*Simp[a*A*n+(a*A+b*B)*(m+1)+(A*b+a*B*n+(A*b+a*B)*(m+n))*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^(n-1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[m,n] && n>1 && m>=-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  a*A*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^(n-1)/(d*(m+1)) + 
  1/(m+1)*
    Int[Sin[c+d*x]^(m+1)*Simp[(A*b+a*B)*(m+1)-A*b*(n-1)+(a*A*n+(a*A+b*B)*(m+1))*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^(n-1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[m,n] && n>1 && m<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -2*B*Cos[c+d*x]*Sin[c+d*x]^m/(d*(2*m+1)*Sqrt[a+b*Sin[c+d*x]]) + 
  1/(a*(2*m+1))*
    Int[Sin[c+d*x]^(m-1)*Simp[2*a*B*m-(b*B-a*A*(2*m+1))*Sin[c+d*x],x]/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[m] && m>0


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  A/a*Int[Sqrt[a+b*Sin[c+d*x]]/Sin[c+d*x],x] - 
  (A*b-a*B)/a*Int[1/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  B/b*Int[Sqrt[a+b*Sin[c+d*x]]/Sqrt[Sin[c+d*x]],x] + 
  (A*b-a*B)/b*Int[1/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  A*Cos[c+d*x]*Sin[c+d*x]^(m+1)/(d*(m+1)*Sqrt[a+b*Sin[c+d*x]]) + 
  1/(2*a*(m+1))*
    Int[Sin[c+d*x]^(m+1)*Simp[2*a*B*(m+1)+A*b+a*A*(2*m+3)*Sin[c+d*x],x]/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[m] && m<=-2


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  (A*b-a*B)*Cos[c+d*x]*Sin[c+d*x]^m*(a+b*Sin[c+d*x])^n/(a*d*(2*n+1)) + 
  1/(a^2*(2*n+1))*
    Int[Sin[c+d*x]^(m-1)*Simp[-m*(A*b-a*B)+(b*B*n+a*A*(n+1)+m*(a*A-b*B))*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[m,n] && n<=-1 && m>0


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(A*b-a*B)*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^n/(b*d*(2*n+1)) + 
  1/(b^2*(2*n+1))*
    Int[Sin[c+d*x]^m*Simp[a*A*(2*n+1)+(a*A-b*B)*(m+1)-(A*b-a*B)*(m+n+2)*Sin[c+d*x],x]*(a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && ZeroQ[a^2-b^2] && RationalQ[m,n] && n<=-1 && m<0


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -2*B*Cos[c+d*x]*Sin[c+d*x]^m*Sqrt[a+b*Sin[c+d*x]]/(d*(2*m+3)) + 
  1/(2*m+3)*
    Int[Sin[c+d*x]^(m-1)*Simp[2*a*B*m+(2*a*A+(a*A+b*B)*(2*m+1))*Sin[c+d*x]+((A*b+a*B)+2*A*b*(m+1))*Sin[c+d*x]^2,x]/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m] && m>0


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]]/sin[c_.+d_.*x_],x_Symbol] :=
  B*Int[Sqrt[a+b*Sin[c+d*x]],x] + 
  A*Int[Sqrt[a+b*Sin[c+d*x]]/Sin[c+d*x],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]]/Sqrt[sin[c_.+d_.*x_]],x_Symbol] :=
  1/2*Int[Simp[a*(2*A-B)+(2*A*b+a*B)*Sin[c+d*x],x]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] + 
  B/2*Int[Simp[a+a*Sin[c+d*x]+2*b*Sin[c+d*x]^2,x]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]]/sin[c_.+d_.*x_]^(3/2),x_Symbol] :=
  (b*(A-B)+a*(A+B))*Int[1/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] + 
  Int[Simp[a*A-(a*A-b*B)*Sin[c+d*x]+b*B*Sin[c+d*x]^2,x]/(Sin[c+d*x]^(3/2)*Sqrt[a+b*Sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  A*Cos[c+d*x]*Sin[c+d*x]^(m+1)*Sqrt[a+b*Sin[c+d*x]]/(d*(m+1)) + 
  1/(2*(m+1))*
    Int[Sin[c+d*x]^(m+1)*Simp[2*a*B*(m+1)-A*b+2*(a*A+(a*A+b*B)*(m+1))*Sin[c+d*x]+A*b*(2*m+5)*Sin[c+d*x]^2,x]/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m] && m<=-2


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -b*B*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^(n-1)/(d*(m+n+1)) + 
  1/(m+n+1)*
    Int[Sin[c+d*x]^m*
      Simp[a*(a*A*n+(a*A+b*B)*(m+1))+
        (a*(2*A*b+a*B)+(a^2*B+2*a*A*b+b^2*B)*(m+n))*Sin[c+d*x]+
        b*(a*B*(n-1)+(A*b+a*B)*(m+n+1))*Sin[c+d*x]^2,x]*
      (a+b*Sin[c+d*x])^(n-2),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && n>1 && m>=-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  a*A*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^(n-1)/(d*(m+1)) + 
  1/(m+1)*
    Int[Sin[c+d*x]^(m+1)*
      Simp[a*((A*b+a*B)*(m+1)-A*b*(n-1))+
        (a^2*A+(a^2*A+2*a*b*B+b^2*A)*(m+1))*Sin[c+d*x]+
        b*(a*A*n+(a*A+b*B)*(m+1))*Sin[c+d*x]^2,x]*
      (a+b*Sin[c+d*x])^(n-2),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && n>1 && m<-1


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  B/b*Int[Sqrt[Sin[c+d*x]],x] + 
  (A*b-a*B)/b*Int[Sqrt[Sin[c+d*x]]/(a+b*Sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -B*Cos[c+d*x]*Sin[c+d*x]^(m-1)/(b*d*m) + 
  1/(b*m)*
    Int[Sin[c+d*x]^(m-2)*Simp[a*B*(m-1)+b*B*(m-1)*Sin[c+d*x]+m*(A*b-a*B)*Sin[c+d*x]^2,x]/(a+b*Sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m] && m>1


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]*(a_+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  A/a*Int[1/Sin[c+d*x],x] - 
  (A*b-a*B)/a*Int[1/(a+b*Sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  B/b*Int[1/Sqrt[Sin[c+d*x]],x] + 
  (A*b-a*B)/b*Int[1/(Sqrt[Sin[c+d*x]]*(a+b*Sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  A*Cos[c+d*x]*Sin[c+d*x]^(m+1)/(a*d*(m+1)) + 
  1/(a*(m+1))*
    Int[Sin[c+d*x]^(m+1)*Simp[(a*B-A*b)*(m+1)+a*A*(m+2)*Sin[c+d*x]+A*b*(m+2)*Sin[c+d*x]^2,x]/(a+b*Sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m] && m<-1


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  1/(2*b)*Int[Simp[-a*B+(2*A*b-a*B)*Sin[c+d*x],x]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] + 
  B/(2*b)*Int[Simp[a+a*Sin[c+d*x]+2*b*Sin[c+d*x]^2,x]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -2*B*Cos[c+d*x]*Sin[c+d*x]^(m-1)*Sqrt[a+b*Sin[c+d*x]]/(b*d*(2*m+1)) + 
  1/(b*(2*m+1))*
    Int[Sin[c+d*x]^(m-2)*Simp[2*a*B*(m-1)+b*B*(2*m-1)*Sin[c+d*x]+(A*b+2*m*(A*b-a*B))*Sin[c+d*x]^2,x]/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m] && m>1


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  B*Int[1/Sqrt[a+b*Sin[c+d*x]],x] + 
  A*Int[1/(Sin[c+d*x]*Sqrt[a+b*Sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  4*A/(d*Sqrt[a+b])*EllipticPi[-1,-ArcSin[Cos[c+d*x]/(1+Sin[c+d*x])],-(a-b)/(a+b)] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A-B] && PositiveQ[b] && PositiveQ[b^2-a^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  4*A*Sqrt[1+Sin[c+d*x]]/(d*Sqrt[a+b*Sin[c+d*x]])*
    Sqrt[(a+b*Sin[c+d*x])/((a+b)*(1+Sin[c+d*x]))]*
    EllipticPi[-1,-ArcSin[Cos[c+d*x]/(1+Sin[c+d*x])],-(a-b)/(a+b)] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A-B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  B*Int[(1+Sin[c+d*x])/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] + 
  (A-B)*Int[1/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[A-B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]^(3/2)*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  -2*A*Cos[c+d*x]*Sqrt[a+b*Sin[c+d*x]]/(a*d*Sqrt[Sin[c+d*x]]*(1+Sin[c+d*x])) - 
  2*A/a*Int[Sqrt[a+b*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*(1+Sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && ZeroQ[A+B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]^(3/2)*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  (A+B)*Int[1/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] + 
  A*Int[(1-Sin[c+d*x])/(Sin[c+d*x]^(3/2)*Sqrt[a+b*Sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[A+B]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  A*Cos[c+d*x]*Sin[c+d*x]^(m+1)*Sqrt[a+b*Sin[c+d*x]]/(a*d*(m+1)) + 
  1/(2*a*(m+1))*
    Int[Sin[c+d*x]^(m+1)*Simp[2*(a*B-A*b)*(m+1)-A*b+2*a*A*(m+2)*Sin[c+d*x]+A*b*(2*m+5)*Sin[c+d*x]^2,x]/Sqrt[a+b*Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m] && m<=-2


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])^(3/2)),x_Symbol] :=
  -2*A*(a-b)*Cos[c+d x]*Sqrt[Sin[c+d*x]]/(a*d*(a+b)*Sqrt[a+b*Sin[c+d*x]]*(1+Sin[c+d x])) + 
  2*A/(a*(a+b))*Int[Sqrt[a+b*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*(1+Sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && ZeroQ[A-B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])^(3/2)),x_Symbol] :=
  (A-B)/(a-b)*Int[1/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] - 
  (A*b-a*B)/(a-b)*Int[(1+Sin[c+d*x])/(Sqrt[Sin[c+d*x]]*(a+b*Sin[c+d*x])^(3/2)),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && NonzeroQ[A-B]


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_])^(3/2),x_Symbol] :=
  B/b*Int[(1+Sin[c+d*x])/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]),x] + 
  1/b*Int[Simp[-a*B+(A*b-(a+b)*B)*Sin[c+d*x],x]/(Sqrt[Sin[c+d*x]]*(a+b*Sin[c+d*x])^(3/2)),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(A*b-a*B)*Cos[c+d*x]*Sqrt[Sin[c+d*x]]*(a+b*Sin[c+d*x])^(n+1)/(d*(n+1)*(a^2-b^2)) + 
  1/(2*(n+1)*(a^2-b^2))*
    Int[Simp[A*b-a*B+2*(a*A-b*B)*(n+1)*Sin[c+d*x]-(A*b-a*B)*(2*n+5)*Sin[c+d*x]^2,x]*(a+b*Sin[c+d*x])^(n+1)/Sqrt[Sin[c+d*x]],x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  a*(A*b-a*B)*Cos[c+d*x]*Sin[c+d*x]^(m-1)*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+1)*(a^2-b^2)) - 
  1/(b*(n+1)*(a^2-b^2))*
    Int[Sin[c+d*x]^(m-2)*
      Simp[a*(A*b-a*B)*(m-1)+b*(A*b-a*B)*(n+1)*Sin[c+d*x]-
        (b*(a*A-b*B)*(n+1)+a*m*(A*b-a*B))*Sin[c+d*x]^2,x]*
      (a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && n<-1 && m>1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  b*(A*b-a*B)*Cos[c+d*x]*Sin[c+d*x]^(m+1)*(a+b*Sin[c+d*x])^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  1/(a*(n+1)*(a^2-b^2))*
    Int[Sin[c+d*x]^m*
      Simp[A*(a^2-b^2)*(n+1)-b*(A*b-a*B)*(m+1)-a*(A*b-a*B)*(n+1)*Sin[c+d*x]+
        b*(A*b-a*B)*(m+n+3)*Sin[c+d*x]^2,x]*
      (a+b*Sin[c+d*x])^(n+1),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A*b-a*B] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && n<-1 && m<0


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_+B_.*sin[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Defer[Int][Sin[c+d*x]^m*(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n},x]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Csc[c+d*x]^m*Sin[c+d*x]^m*Int[(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n/Sin[c+d*x]^m,x] /;
FreeQ[{a,b,c,d,A,B,m,n},x] && Not[IntegerQ[m]]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_*sin[c_.+d_.*x_]^q_.*(A_.+B_.*sin[c_.+d_.*x_]),x_Symbol] :=
  Csc[c+d*x]^m*Sin[c+d*x]^m*Int[Sin[c+d*x]^(q-m)*(A+B*Sin[c+d*x]),x] /;
FreeQ[{c,d,A,B,m,q},x] && Not[IntegerQ[m]]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_*sin[c_.+d_.*x_]^q_.*(A_.+B_.*sin[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Csc[c+d*x]^m*Sin[c+d*x]^m*Int[Sin[c+d*x]^(q-m)*(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,q},x] && Not[IntegerQ[m]]


(* ::Code:: *)
Int[(A_+B_.*csc[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[(B+A*Sin[c+d*x])*(a+b*Sin[c+d*x])^n/Sin[c+d*x],x] /;
FreeQ[{a,b,c,d,A,B,n},x]


(* ::Code:: *)
Int[(A_+B_.*csc[c_.+d_.*x_])*(b_*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[(B+A*Sin[c+d*x])*(b*Sin[c+d*x])^n/Sin[c+d*x],x] /;
FreeQ[{b,c,d,A,B,n},x]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_+B_.*csc[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Sin[c+d*x]^(m-1)*(B+A*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n},x]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_*(A_+B_.*csc[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Csc[c+d*x]^m*Sin[c+d*x]^m*Int[(B+A*Sin[c+d*x])*(a+b*Sin[c+d*x])^n/Sin[c+d*x]^(m+1),x] /;
FreeQ[{a,b,c,d,A,B,m,n},x] && Not[IntegerQ[m]]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_*sin[c_.+d_.*x_]^q_.*(A_+B_.*csc[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Csc[c+d*x]^m*Sin[c+d*x]^m*Int[Sin[c+d*x]^(q-m)*(A+B*Csc[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n},x] && Not[IntegerQ[m]]


(* ::Code:: *)
Int[(A_*sin[c_.+d_.*x_]^p_.+B_.*sin[c_.+d_.*x_]^p1_.)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Sin[c+d*x]^p*(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,n,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*sin[c_.+d_.*x_]^q_.*(A_*sin[c_.+d_.*x_]^p_.+B_.*sin[c_.+d_.*x_]^p1_.),x_Symbol] :=
  Int[Csc[c+d*x]^m*Sin[c+d*x]^(p+q)*(A+B*Sin[c+d*x]),x] /;
FreeQ[{c,d,A,B,m,p,q},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_*sin[c_.+d_.*x_]^p_.+B_.*sin[c_.+d_.*x_]^p1_.),x_Symbol] :=
  Int[Sin[c+d*x]^(m+p)*(A+B*Sin[c+d*x]),x] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*(A_*sin[c_.+d_.*x_]^p_.+B_.*sin[c_.+d_.*x_]^p1_.),x_Symbol] :=
  Int[Csc[c+d*x]^m*Sin[c+d*x]^p*(A+B*Sin[c+d*x]),x] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*sin[c_.+d_.*x_]^q_.*(A_*sin[c_.+d_.*x_]^p_.+B_.*sin[c_.+d_.*x_]^p1_.)*
	(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Csc[c+d*x]^m*Sin[c+d*x]^(p+q)*(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p,q},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_*sin[c_.+d_.*x_]^p_.+B_.*sin[c_.+d_.*x_]^p1_.)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Sin[c+d*x]^(m+p)*(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*(A_*sin[c_.+d_.*x_]^p_.+B_.*sin[c_.+d_.*x_]^p1_.)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Csc[c+d*x]^m*Sin[c+d*x]^p*(A+B*Sin[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[(A_*csc[c_.+d_.*x_]^p_.+B_.*csc[c_.+d_.*x_]^p1_.)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Csc[c+d*x]^p*(A+B*Csc[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,n,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*sin[c_.+d_.*x_]^q_.*(A_*csc[c_.+d_.*x_]^p_.+B_.*csc[c_.+d_.*x_]^p1_.),x_Symbol] :=
  Int[Csc[c+d*x]^(m+p)*Sin[c+d*x]^q*(A+B*Csc[c+d*x]),x] /;
FreeQ[{c,d,A,B,m,p,q},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_*csc[c_.+d_.*x_]^p_.+B_.*csc[c_.+d_.*x_]^p1_.),x_Symbol] :=
  Int[Csc[c+d*x]^p*Sin[c+d*x]^m*(A+B*Csc[c+d*x]),x] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*(A_*csc[c_.+d_.*x_]^p_.+B_.*csc[c_.+d_.*x_]^p1_.),x_Symbol] :=
  Int[Csc[c+d*x]^(m+p)*(A+B*Csc[c+d*x]),x] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*sin[c_.+d_.*x_]^q_.*(A_*csc[c_.+d_.*x_]^p_.+B_.*csc[c_.+d_.*x_]^p1_.)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Csc[c+d*x]^(m+p)*Sin[c+d*x]^q*(A+B*Csc[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p,q},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_*csc[c_.+d_.*x_]^p_.+B_.*csc[c_.+d_.*x_]^p1_.)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Csc[c+d*x]^p*Sin[c+d*x]^m*(A+B*Csc[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[p1-(p+1)]


(* ::Code:: *)
Int[csc[c_.+d_.*x_]^m_.*(A_*csc[c_.+d_.*x_]^p_.+B_.*csc[c_.+d_.*x_]^p1_.)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  Int[Csc[c+d*x]^(m+p)*(A+B*Csc[c+d*x])*(a+b*Sin[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[p1-(p+1)]


