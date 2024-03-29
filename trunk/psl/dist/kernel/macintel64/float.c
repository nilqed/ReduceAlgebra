/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:FLOAT.C
% Description:  Miscellaneous floating point support routines.
% Author:       Leigh Stoller
% Created:      29-Oct-86 
% Modified:     
% Mode:         Text
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1982, University of Utah
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%  
% 05-May-87 (Leigh Stoller)
%  Added C defintions for external float routines used in fast-math.sl.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <string.h>
#include <math.h>
#include <fenv.h>
#include <stdio.h>

#ifdef USE_CRLIBM
#include "crlibm.h"

#define sin     sin_rn
#define cos     cos_rn
#define tan     tan_rn
#define asin    asin_rn
#define acos    acos_rn
#define atan    atan_rn
#define exp     exp_rn
#define log     log_rn

#endif


/* Tag( uxfloat )
 */
void
uxfloat(f,i)
     double *f;
     long long i;
{
  *f = i;
}

/* Tag( uxfix )
 */
long long uxfix(f)
     double *f;
{
  return *f;
}

/* Tag( uxassign )
 */
void
uxassign(f1,f2)
     double *f1, *f2;
{
  *f1 = *f2;
}

fexcept_t flagp;

int
uxminus(f1,f2)
     double *f1, *f2;
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  *f1 = -*f2;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}


/* Tag( uxplus2 )
 */
int
uxplus2(f1,f2,f3)
     double *f1, *f2, *f3;
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  *f1 = *f2 + *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

/* Tag( uxdifference )
 */
int
uxdifference(f1,f2,f3)
     double *f1, *f2, *f3;
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  *f1 = *f2 - *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

/* Tag( uxtimes2 )
 */
int
uxtimes2(f1,f2,f3)
     double *f1, *f2, *f3;
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  *f1 = *f2 * *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

/* Tag( uxquotient )
 */
int
uxquotient(f1,f2,f3)
     double *f1, *f2, *f3;
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  *f1 = *f2 / *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

/* Tag( uxgreaterp )
 */
long long uxgreaterp(f1,f2,val1,val2)
     double *f1, *f2;
     long long val1, val2;
{
  if (*f1 > *f2)
    return val1;
  else
    return val2;
}

/* Tag( uxlessp )
 */
long long uxlessp(f1,f2,val1,val2)
     double *f1, *f2;
     long long val1, val2;
{
  if (*f1 < *f2)
    return val1;
  else
    return val2;
}

/* Tag( uxwritefloat )
 */
void
uxwritefloat(buf, flt, convstr)
     char *buf;          /* String buffer to return float int */
     double *flt;        /* Pointer to the float */
     char *convstr;      /* String containing conversion field for sprintf */
{
  char *temps, *dot, *e;
  char tempbuf[100]; /* reasonable size limit */
  float  tempf;

  temps = buf + 8;       /* Skip over lisp string length to write data */

  sprintf(temps,convstr, *flt);

  /* Make sure that there is a trailing .0
   */
  dot = rindex(temps, '.');
  if (dot == NULL)
    {
    /* Check to see if the number is in scientific notation. If so, we need
     *  add the .0 into the middle of the string, just before the e.
     */
    if ((e = rindex(temps, 'e')) || (e = rindex(temps, 'E')))
      {
	strcpy(tempbuf, e);       /* save save exponent part */
	*e = '\0'; 
	strcat(temps, ".0");     /* Add .0 ono original string */
	strcat(temps, tempbuf);  /* add the exponent part onto the end */
      }
    else
    {
      strcat(temps, ".0");
    }
  }

  /* Install the length of the string into the Lisp header word
   */
  *((long long *)buf) = strlen(temps) - 1;
}


void
uxwritefloat8(buf, flt, convstr,dummy)
     char *buf;          /* String buffer to return float int */
     double *flt;        /* Pointer to the float */
     char *convstr;      /* String containing conversion field for sprintf */
     int dummy;  /* We need to have 128 bit alingemnt of the stack */
{ uxwritefloat(buf, flt, convstr); }



/* Tag( uxdoubletofloat )
 */
void
uxdoubletofloat (dbl,flt)
     double *dbl;
     float  *flt;
{
  *flt = (float) *dbl;
}

void
uxfloattodouble (flt,dbl)
     float  *flt;             
     double *dbl;             
{
  *dbl = (double) *flt;
}

/* Functions for fast-math.sl (Unix C replacement for mathlib.) */
void
uxsin (r, x)
     double *r, *x;
{
    *r = sin( *x );
}

void
uxcos (r, x)
     double *r, *x;
{
    *r = cos( *x );
}

void
uxtan (r, x)
     double *r, *x;
{
    *r = tan( *x );
}

void
uxasin (r, x)
     double *r, *x;
{
    *r = asin( *x );
}

void
uxacos (r, x)
     double *r, *x;
{
    *r = acos( *x );
}

void
uxatan (r, x)
     double *r, *x;
{
    *r = atan( *x );
}

void
uxsqrt (r, x)
     double *r, *x;
{
    *r = sqrt( *x );
}

void
uxexp (r, x)
     double *r, *x;
{
    *r = exp( *x );
}

void
uxlog (r, x)
     double *r, *x;
{
    *r = log( *x );
}

void
uxatan2 (r, y, x)
     double *r, *y, *x;
{
    *r = atan2( *y, *x );
}
