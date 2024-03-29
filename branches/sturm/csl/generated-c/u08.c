
/* $destdir\u08.c        Machine generated C code */

/* $Id: $ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
      } while (0)
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_FOREIGN        TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(font, code)                                      \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0x001fffff)
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
#ifdef DEBUG
#define SHOW_FNAME  (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)
#endif
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments",
    "too many arguments",
    "object not valid as a function (apply,",
    "macroexpand-hook failure",
    "block tag not found",
    "go tag not found",
    "too many arguments provided",
    "not enough arguments provided",
    "bad item in bound variable list",
    "bad keyword arguments",
    "write-error on file",
    "endp used on badly terminated list",
    "environment parameter 'fasldir' not set",
    "loadable module not found for loading",
    "file could not be opened",
    "unable to establish pipe",
    "stack overflow",
    "top bit of address has unexpected value",
    "memory block spans the zero address",
    "this error code available for re-use",
    "unable to find a directory for temporary files",
    "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
    void *end;
    int type;
} page_map_t;
#endif
extern int32_t pages_count,
               heap_pages_count, vheap_pages_count,
               bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
               new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
extern Lisp_Object multiplication_buffer;
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (e); \
                          memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack("@" __FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
  if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
extern volatile int blipflag;
extern int64_t blipcount, startblip;
#if defined __linux__ && defined DEBUG
#define HANDLE_BLIP                                                       \
    if (blipflag)                                                         \
    {   blipflag = 0;                                                     \
        if (startblip >= 0 && ++blipcount > startblip)                    \
        {   fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__);  \
            fflush(stderr);                                               \
        }                                                                 \
    }
#else
#define HANDLE_BLIP
#endif
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space, eof_symbol, call_stack;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define modulus_is_large      BASE[32]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#define trap_time             BASE[158]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
#define eof_symbol            BASE[187]
#define call_stack            BASE[188]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
extern Lisp_Object characterify(Lisp_Object a);
extern Lisp_Object char_to_id(int ch);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern Lisp_Object noisy_Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname, int noisy);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name, int noisy);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, const char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#define noisy_eval(a, b) noisy_Ceval(a, b)
#define noisy_voideval(a, b) noisy_Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#define noisy_eval(a, b) \
    (is_cons(a) ? noisy_Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define noisy_voideval(a, b) \
    if (is_cons(a)) noisy_Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
extern setup_type const
                    u01_setup[], u02_setup[], u03_setup[], u04_setup[],
       u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
       u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
       u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
       u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
       u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
       u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
       u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
       u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
       u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
       u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
       u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
       u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp, int noisy);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
             *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
#endif
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracesetfunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracesetinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltraceset(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracesetfunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracesetinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetfunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for wuorderp */

static Lisp_Object CC_wuorderp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0021, v0022, v0023, v0024, v0025;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wuorderp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0001;
    v0025 = v0000;
/* end of prologue */
    v0022 = nil;
    v0021 = v0025;
    v0020 = v0024;
    if (v0021 == v0020) goto v0026;
    v0020 = qvalue(elt(env, 2)); /* wukord!* */
    v0023 = v0020;
    goto v0027;

v0027:
    v0020 = v0023;
    if (v0020 == nil) goto v0028;
    v0020 = v0022;
    if (!(v0020 == nil)) goto v0028;
    v0021 = v0025;
    v0020 = v0023;
    v0020 = qcar(v0020);
    if (v0021 == v0020) goto v0029;
    v0021 = v0024;
    v0020 = v0023;
    v0020 = qcar(v0020);
    if (v0021 == v0020) goto v0030;
    v0020 = v0023;
    v0020 = qcdr(v0020);
    v0023 = v0020;
    goto v0027;

v0030:
    v0021 = v0025;
    v0020 = v0023;
    v0020 = qcdr(v0020);
    v0020 = Lmemq(nil, v0021, v0020);
    if (v0020 == nil) goto v0031;
    v0020 = elt(env, 4); /* no */
    goto v0032;

v0032:
    v0022 = v0020;
    goto v0027;

v0031:
    v0020 = elt(env, 3); /* yes */
    goto v0032;

v0029:
    v0021 = v0024;
    v0020 = v0023;
    v0020 = qcdr(v0020);
    v0020 = Lmemq(nil, v0021, v0020);
    if (v0020 == nil) goto v0033;
    v0020 = elt(env, 3); /* yes */
    goto v0034;

v0034:
    v0022 = v0020;
    goto v0027;

v0033:
    v0020 = elt(env, 4); /* no */
    goto v0034;

v0028:
    v0020 = v0022;
    if (v0020 == nil) goto v0035;
    v0020 = v0022;
    v0021 = elt(env, 3); /* yes */
    v0020 = (v0020 == v0021 ? lisp_true : nil);
    return onevalue(v0020);

v0035:
    v0020 = v0025;
    v0021 = v0024;
    v0020 = Lorderp(nil, v0020, v0021);
    errexit();
    v0020 = (v0020 == nil ? lisp_true : nil);
    return onevalue(v0020);

v0026:
    v0020 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0020);
}



/* Code for rl_prepat */

static Lisp_Object CC_rl_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_prepat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_prepat!* */
    v0037 = ncons(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    {
        Lisp_Object v0039 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0039, v0037);
    }
/* error exit handlers */
v0038:
    popv(2);
    return nil;
}



/* Code for xxsort */

static Lisp_Object CC_xxsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xxsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0000;
/* end of prologue */
    v0037 = v0040;
    v0040 = elt(env, 1); /* lambda_idn438f46io4 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0037, v0040);
    }
}



/* Code for lambda_idn438f46io4 */

static Lisp_Object CC_lambda_idn438f46io4(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_idn438f46io4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0043 = v0001;
    v0028 = v0000;
/* end of prologue */
    v0028 = qcar(v0028);
    v0043 = qcar(v0043);
    fn = elt(env, 1); /* termorder */
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0043);
    errexit();
    v0043 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0028, v0043);
}



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_comp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0042 = v0001;
    v0041 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v0042 = list2(v0041, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    {
        Lisp_Object v0027 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0027, v0042);
    }
/* error exit handlers */
v0028:
    popv(2);
    return nil;
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retimes1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0053;

v0053:
    v0022 = stack[0];
    if (v0022 == nil) goto v0036;
    v0022 = stack[0];
    v0023 = qcar(v0022);
    v0022 = (Lisp_Object)17; /* 1 */
    if (v0023 == v0022) goto v0038;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = Lminusp(nil, v0022);
    env = stack[-2];
    if (v0022 == nil) goto v0054;
    v0022 = qvalue(elt(env, 1)); /* !*bool */
    v0022 = (v0022 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0022; /* !*bool */
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0023 = negate(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    stack[0] = v0022;
    goto v0053;

v0054:
    v0022 = stack[0];
    v0022 = qcar(v0022);
    if (!consp(v0022)) goto v0029;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0023 = qcar(v0022);
    v0022 = elt(env, 2); /* minus */
    if (v0023 == v0022) goto v0033;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0023 = qcar(v0022);
    v0022 = elt(env, 3); /* times */
    if (v0023 == v0022) goto v0056;
    v0022 = stack[0];
    v0023 = qcar(v0022);
    v0022 = stack[-1];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    stack[-1] = v0022;
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0053;

v0056:
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0023 = qcdr(v0022);
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0022 = Lappend(nil, v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    stack[0] = v0022;
    goto v0053;

v0033:
    v0022 = qvalue(elt(env, 1)); /* !*bool */
    v0022 = (v0022 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0022; /* !*bool */
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    stack[0] = v0022;
    goto v0053;

v0029:
    v0022 = stack[0];
    v0023 = qcar(v0022);
    v0022 = stack[-1];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    stack[-1] = v0022;
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0053;

v0038:
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0053;

v0036:
    v0022 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0022);
    }
/* error exit handlers */
v0055:
    popv(3);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mintype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0057 = v0000;
/* end of prologue */
    v0038 = v0057;
    if (!consp(v0038)) return onevalue(v0057);
    v0057 = qcar(v0057);
    return onevalue(v0057);
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0054, v0059;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evtdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0054 = v0000;
/* end of prologue */
    v0058 = (Lisp_Object)1; /* 0 */
    goto v0060;

v0060:
    v0059 = v0054;
    if (v0059 == nil) return onevalue(v0058);
    v0059 = v0054;
    v0059 = qcar(v0059);
    v0058 = (Lisp_Object)(int32_t)((int32_t)v0059 + (int32_t)v0058 - TAG_FIXNUM);
    v0054 = qcdr(v0054);
    goto v0060;
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0084, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0060;

v0060:
    v0083 = stack[-2];
    if (v0083 == nil) goto v0038;
    v0083 = stack[-1];
    if (v0083 == nil) goto v0086;
    v0083 = stack[-2];
    v0083 = qcar(v0083);
    v0084 = qcar(v0083);
    v0083 = (Lisp_Object)17; /* 1 */
    if (v0084 == v0083) goto v0087;
    v0083 = stack[-1];
    v0083 = qcar(v0083);
    v0084 = qcar(v0083);
    v0083 = (Lisp_Object)17; /* 1 */
    if (v0084 == v0083) goto v0088;
    v0083 = stack[-2];
    v0083 = qcar(v0083);
    v0084 = qcar(v0083);
    v0083 = stack[-1];
    v0083 = qcar(v0083);
    v0083 = qcar(v0083);
    if (equal(v0084, v0083)) goto v0089;
    v0083 = stack[-2];
    v0083 = qcar(v0083);
    v0084 = qcar(v0083);
    v0083 = stack[-1];
    v0083 = qcar(v0083);
    v0083 = qcar(v0083);
    fn = elt(env, 1); /* ordop */
    v0083 = (*qfn2(fn))(qenv(fn), v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    if (v0083 == nil) goto v0091;
    v0083 = stack[-2];
    v0084 = qcar(v0083);
    v0083 = stack[0];
    v0083 = cons(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[0] = v0083;
    v0083 = stack[-2];
    v0083 = qcdr(v0083);
    stack[-2] = v0083;
    goto v0060;

v0091:
    v0083 = stack[-1];
    v0084 = qcar(v0083);
    v0083 = stack[0];
    v0083 = cons(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[0] = v0083;
    v0083 = stack[-1];
    v0083 = qcdr(v0083);
    stack[-1] = v0083;
    goto v0060;

v0089:
    stack[-3] = stack[0];
    v0083 = stack[-2];
    v0083 = qcar(v0083);
    v0084 = qcdr(v0083);
    v0083 = stack[-1];
    v0083 = qcar(v0083);
    v0083 = qcdr(v0083);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0083 = stack[-2];
    v0084 = qcdr(v0083);
    v0083 = stack[-1];
    v0083 = qcdr(v0083);
    v0083 = CC_addpf(env, v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0084 = stack[0];
    v0085 = v0084;
    v0085 = qcar(v0085);
    if (v0085 == nil) goto v0092;
    v0085 = stack[-2];
    v0085 = qcar(v0085);
    v0085 = qcar(v0085);
    v0083 = acons(v0085, v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    goto v0092;

v0092:
    {
        Lisp_Object v0093 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0093, v0083);
    }

v0088:
    v0084 = stack[-1];
    v0083 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v0083 = (*qfn2(fn))(qenv(fn), v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    {
        Lisp_Object v0094 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0094, v0083);
    }

v0087:
    v0084 = stack[-2];
    v0083 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v0083 = (*qfn2(fn))(qenv(fn), v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    {
        Lisp_Object v0095 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0095, v0083);
    }

v0086:
    v0084 = stack[0];
    v0083 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0084, v0083);
    }

v0038:
    v0084 = stack[0];
    v0083 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0084, v0083);
    }
/* error exit handlers */
v0090:
    popv(5);
    return nil;
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0105;
    Lisp_Object fn;
    Lisp_Object v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for layout-formula");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0045;
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v0048 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v0048; /* overflowed!* */
    qvalue(elt(env, 5)) = v0048; /* pline!* */
    v0048 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0048; /* ymax!* */
    qvalue(elt(env, 2)) = v0048; /* ymin!* */
    qvalue(elt(env, 1)) = v0048; /* ycoord!* */
    v0048 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v0048; /* posn!* */
    v0048 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v0048; /* testing!-width!* */
    v0048 = stack[-6];
    if (v0048 == nil) goto v0080;
    v0105 = stack[-6];
    v0048 = elt(env, 11); /* inbrackets */
    if (v0105 == v0048) goto v0086;
    v0048 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-10];
    goto v0080;

v0080:
    v0105 = stack[-8];
    v0048 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v0048 = (*qfn2(fn))(qenv(fn), v0105, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-10];
    v0105 = stack[-6];
    v0048 = elt(env, 11); /* inbrackets */
    if (!(v0105 == v0048)) goto v0029;
    v0048 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-10];
    goto v0029;

v0029:
    v0048 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v0048 == nil) goto v0107;
    v0048 = qvalue(elt(env, 8)); /* nil */
    goto v0057;

v0057:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v0048); }

v0107:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v0105 = qvalue(elt(env, 4)); /* posn!* */
    v0048 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v0105, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-10];
    v0105 = qvalue(elt(env, 2)); /* ymin!* */
    v0048 = qvalue(elt(env, 3)); /* ymax!* */
    v0048 = cons(v0105, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-10];
    v0048 = acons(stack[-7], stack[-6], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-10];
    goto v0057;

v0086:
    v0048 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-10];
    goto v0080;
/* error exit handlers */
v0106:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0057 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v0038 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    v0057 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v0038, v0057);
    }
/* error exit handlers */
v0108:
    popv(2);
    return nil;
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0012, v0079;
    Lisp_Object fn;
    Lisp_Object v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sroad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0045;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0079 = nil;
    goto v0096;

v0096:
    v0050 = stack[0];
    if (v0050 == nil) goto v0040;
    v0012 = stack[-2];
    v0050 = stack[0];
    v0050 = qcar(v0050);
    if (equal(v0012, v0050)) goto v0054;
    v0050 = stack[0];
    v0050 = qcar(v0050);
    v0012 = v0079;
    v0050 = cons(v0050, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0079 = v0050;
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    stack[0] = v0050;
    goto v0096;

v0054:
    stack[-2] = v0079;
    v0012 = stack[-1];
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    v0050 = Lappend(nil, v0012, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    {
        Lisp_Object v0111 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0111, v0050);
    }

v0040:
    v0050 = v0079;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0050);
    }
/* error exit handlers */
v0110:
    popv(4);
    return nil;
}



/* Code for formc */

static Lisp_Object MS_CDECL CC_formc(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0117, v0008, v0076;
    Lisp_Object fn;
    Lisp_Object v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0045;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0116 = qvalue(elt(env, 1)); /* !*rlisp88 */
    if (v0116 == nil) goto v0015;
    v0117 = stack[-2];
    v0116 = elt(env, 2); /* modefn */
    v0116 = Lflagpcar(nil, v0117, v0116);
    env = stack[-3];
    if (v0116 == nil) goto v0015;
    v0116 = stack[-2];
    v0117 = qcar(v0116);
    v0116 = elt(env, 3); /* symbolic */
    if (v0117 == v0116) goto v0015;
    v0117 = elt(env, 4); /* "algebraic expression" */
    v0116 = elt(env, 5); /* "Rlisp88 form" */
    {
        popv(4);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0117, v0116);
    }

v0015:
    v0117 = stack[0];
    v0116 = elt(env, 6); /* algebraic */
    if (v0117 == v0116) goto v0109;
    v0116 = qvalue(elt(env, 7)); /* nil */
    goto v0080;

v0080:
    if (!(v0116 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0076 = stack[-2];
    v0008 = stack[-1];
    v0117 = elt(env, 3); /* symbolic */
    v0116 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0076, v0008, v0117, v0116);
    }

v0109:
    v0117 = stack[-2];
    v0116 = stack[-1];
    fn = elt(env, 10); /* intexprnp */
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    goto v0080;
/* error exit handlers */
v0031:
    popv(4);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=ecart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0060;

v0060:
    v0019 = stack[0];
    if (v0019 == nil) goto v0096;
    v0019 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v0034 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0019 = stack[-1];
    v0019 = cons(v0034, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    stack[-1] = v0019;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0060;

v0096:
    v0019 = (Lisp_Object)1; /* 0 */
    v0034 = v0019;
    goto v0036;

v0036:
    v0019 = stack[-1];
    if (v0019 == nil) { popv(3); return onevalue(v0034); }
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0019 = Lmax2(nil, v0019, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0034 = v0019;
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    goto v0036;
/* error exit handlers */
v0029:
    popv(3);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oprin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0120 = stack[0];
    if (!symbolp(v0120)) v0120 = nil;
    else { v0120 = qfastgets(v0120);
           if (v0120 != nil) { v0120 = elt(v0120, 37); /* prtch */
#ifdef RECORD_GET
             if (v0120 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0120 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0120 == SPID_NOPROP) v0120 = nil; }}
#endif
    stack[-1] = v0120;
    v0120 = stack[-1];
    if (v0120 == nil) goto v0096;
    v0120 = qvalue(elt(env, 2)); /* !*fort */
    if (v0120 == nil) goto v0017;
    v0120 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0120);
    }

v0017:
    v0120 = qvalue(elt(env, 3)); /* !*list */
    if (v0120 == nil) goto v0027;
    v0120 = qvalue(elt(env, 4)); /* obrkp!* */
    if (v0120 == nil) goto v0027;
    v0121 = stack[0];
    v0120 = elt(env, 5); /* (plus minus) */
    v0120 = Lmemq(nil, v0121, v0120);
    if (v0120 == nil) goto v0027;
    v0120 = qvalue(elt(env, 6)); /* testing!-width!* */
    if (v0120 == nil) goto v0015;
    v0120 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v0120; /* overflowed!* */
    { popv(3); return onevalue(v0120); }

v0015:
    v0120 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0120 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0120);
    }

v0027:
    v0120 = stack[0];
    if (!symbolp(v0120)) v0120 = nil;
    else { v0120 = qfastgets(v0120);
           if (v0120 != nil) { v0120 = elt(v0120, 61); /* spaced */
#ifdef RECORD_GET
             if (v0120 == SPID_NOPROP)
                record_get(elt(fastget_names, 61), 0),
                v0120 = nil;
             else record_get(elt(fastget_names, 61), 1),
                v0120 = lisp_true; }
           else record_get(elt(fastget_names, 61), 0); }
#else
             if (v0120 == SPID_NOPROP) v0120 = nil; else v0120 = lisp_true; }}
#endif
    if (v0120 == nil) goto v0122;
    v0120 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0120 = stack[-1];
    fn = elt(env, 9); /* prin2!* */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0120 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0120);
    }

v0122:
    v0120 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0120);
    }

v0096:
    v0120 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0120 = stack[0];
    fn = elt(env, 9); /* prin2!* */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0120 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0120);
    }
/* error exit handlers */
v0049:
    popv(3);
    return nil;
}



/* Code for !*i2ar */

static Lisp_Object CC_Hi2ar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2ar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0000;
/* end of prologue */
    v0037 = elt(env, 1); /* !:ar!: */
    return cons(v0037, v0040);
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0010;
    Lisp_Object fn;
    Lisp_Object v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for divide:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0045;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = stack[-1];
    v0049 = stack[-2];
    v0049 = qcdr(v0049);
    v0049 = qcar(v0049);
    v0049 = Labsval(nil, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0049 = add1(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0049 = plus2(stack[0], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v0049 = (*qfn2(fn))(qenv(fn), stack[-3], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    stack[-3] = v0049;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0049 = stack[-3];
    v0049 = qcdr(v0049);
    v0010 = qcar(v0049);
    v0049 = stack[-2];
    v0049 = qcdr(v0049);
    v0049 = qcar(v0049);
    stack[0] = quot2(v0010, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0049 = stack[-3];
    v0049 = qcdr(v0049);
    v0010 = qcdr(v0049);
    v0049 = stack[-2];
    v0049 = qcdr(v0049);
    v0049 = qcdr(v0049);
    v0049 = difference2(v0010, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0049 = list2star(stack[-4], stack[0], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    stack[-3] = v0049;
    v0010 = stack[-3];
    v0049 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0010, v0049);
    }
/* error exit handlers */
v0075:
    popv(6);
    return nil;
}



/* Code for ordpa */

static Lisp_Object CC_ordpa(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0128, v0002, v0003, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordpa");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0002 = v0001;
    v0003 = v0000;
/* end of prologue */

v0053:
    v0128 = v0003;
    if (v0128 == nil) goto v0036;
    v0128 = v0002;
    if (v0128 == nil) goto v0038;
    v0128 = v0003;
    v0128 = Lsimple_vectorp(nil, v0128);
    env = stack[0];
    if (v0128 == nil) goto v0042;
    v0128 = v0002;
    v0128 = Lsimple_vectorp(nil, v0128);
    env = stack[0];
    if (v0128 == nil) goto v0113;
    v0128 = v0003;
    {
        popv(1);
        fn = elt(env, 3); /* ordpv */
        return (*qfn2(fn))(qenv(fn), v0128, v0002);
    }

v0113:
    v0128 = v0002;
    v0128 = (consp(v0128) ? nil : lisp_true);
    { popv(1); return onevalue(v0128); }

v0042:
    v0128 = v0003;
    if (!consp(v0128)) goto v0112;
    v0128 = v0002;
    if (!consp(v0128)) goto v0129;
    v0128 = v0003;
    v0044 = qcar(v0128);
    v0128 = v0002;
    v0128 = qcar(v0128);
    if (equal(v0044, v0128)) goto v0098;
    v0128 = v0003;
    v0128 = qcar(v0128);
    v0003 = v0128;
    v0128 = v0002;
    v0128 = qcar(v0128);
    v0002 = v0128;
    goto v0053;

v0098:
    v0128 = v0003;
    v0128 = qcdr(v0128);
    v0003 = v0128;
    v0128 = v0002;
    v0128 = qcdr(v0128);
    v0002 = v0128;
    goto v0053;

v0129:
    v0128 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0128); }

v0112:
    v0128 = v0002;
    if (!consp(v0128)) goto v0019;
    v0128 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0128); }

v0019:
    v0128 = v0003;
    if (is_number(v0128)) goto v0078;
    v0128 = v0002;
    if (symbolp(v0128)) goto v0130;
    v0128 = v0002;
    v0128 = (is_number(v0128) ? lisp_true : nil);
    { popv(1); return onevalue(v0128); }

v0130:
    v0128 = v0003;
        popv(1);
        return Lorderp(nil, v0128, v0002);

v0078:
    v0128 = v0002;
    if (is_number(v0128)) goto v0033;
    v0128 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0128); }

v0033:
    v0128 = v0003;
    v0128 = (Lisp_Object)lessp2(v0128, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    v0128 = v0128 ? lisp_true : nil;
    v0128 = (v0128 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0128); }

v0038:
    v0128 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0128); }

v0036:
    v0128 = v0002;
    v0128 = (v0128 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0128); }
/* error exit handlers */
v0020:
    popv(1);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0082;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0081 = v0000;
/* end of prologue */

v0053:
    v0082 = stack[0];
    if (v0082 == nil) { popv(2); return onevalue(v0081); }
    v0082 = v0081;
    if (v0082 == nil) goto v0057;
    v0082 = stack[0];
    v0082 = qcar(v0082);
    v0081 = Ldelete(nil, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-1];
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    stack[0] = v0082;
    goto v0053;

v0057:
    v0081 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0081); }
/* error exit handlers */
v0103:
    popv(2);
    return nil;
}



/* Code for qqe_number!-of!-tails!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKtailsKinKqterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_number-of-tails-in-qterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0006:
    v0082 = stack[0];
    if (!consp(v0082)) goto v0096;
    v0082 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0104 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-1];
    v0082 = elt(env, 1); /* (ladd radd) */
    v0082 = Lmemq(nil, v0104, v0082);
    if (v0082 == nil) goto v0086;
    v0082 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-1];
    stack[0] = v0082;
    goto v0006;

v0086:
    v0082 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-1];
    v0082 = CC_qqe_numberKofKtailsKinKqterm(env, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    popv(2);
    return add1(v0082);

v0096:
    v0082 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0082); }
/* error exit handlers */
v0127:
    popv(2);
    return nil;
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0032, v0130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_varlt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0130 = v0000;
/* end of prologue */
    v0032 = v0130;
    v0018 = (Lisp_Object)1; /* 0 */
    if (v0032 == v0018) goto v0037;
    v0032 = v0130;
    v0018 = (Lisp_Object)17; /* 1 */
    v0018 = (v0032 == v0018 ? lisp_true : nil);
    goto v0040;

v0040:
    if (v0018 == nil) goto v0060;
    v0018 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0018); }

v0060:
    v0018 = v0130;
    if (symbolp(v0018)) goto v0051;
    v0018 = v0130;
    fn = elt(env, 3); /* ibalp_argn */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    stack[-1] = v0018;
    goto v0029;

v0029:
    v0018 = stack[-1];
    if (v0018 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0018 = stack[-1];
    v0018 = qcar(v0018);
    v0032 = v0018;
    v0018 = stack[0];
    v0018 = CC_ibalp_varlt1(env, v0032, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    stack[0] = v0018;
    v0018 = stack[-1];
    v0018 = qcdr(v0018);
    stack[-1] = v0018;
    goto v0029;

v0051:
    v0032 = v0130;
    v0018 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v0032, v0018);
    }

v0037:
    v0018 = qvalue(elt(env, 1)); /* t */
    goto v0040;
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multiom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0115 = stack[0];
    v0081 = Llength(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    v0115 = (Lisp_Object)17; /* 1 */
    if (v0081 == v0115) goto v0060;
    v0115 = stack[0];
    v0115 = qcar(v0115);
    fn = elt(env, 2); /* objectom */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0115 = CC_multiom(env, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    goto v0053;

v0053:
    v0115 = nil;
    { popv(2); return onevalue(v0115); }

v0060:
    v0115 = stack[0];
    v0115 = qcar(v0115);
    fn = elt(env, 2); /* objectom */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    goto v0053;
/* error exit handlers */
v0104:
    popv(2);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0134, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for putpline");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0134 = qvalue(elt(env, 1)); /* posn!* */
    v0133 = stack[0];
    v0133 = qcar(v0133);
    v0133 = qcdr(v0133);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v0134 + (int32_t)v0133 - TAG_FIXNUM);
    v0133 = qvalue(elt(env, 2)); /* nil */
    v0134 = Llinelength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    v0133 = qvalue(elt(env, 3)); /* spare!* */
    v0133 = (Lisp_Object)(int32_t)((int32_t)v0134 - (int32_t)v0133 + TAG_FIXNUM);
    v0133 = (Lisp_Object)greaterp2(stack[-1], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-2];
    if (v0133 == nil) goto v0078;
    v0133 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    goto v0078;

v0078:
    v0134 = qvalue(elt(env, 1)); /* posn!* */
    v0133 = qvalue(elt(env, 5)); /* orig!* */
    v0035 = (Lisp_Object)(int32_t)((int32_t)v0134 - (int32_t)v0133 + TAG_FIXNUM);
    v0134 = qvalue(elt(env, 6)); /* ycoord!* */
    v0133 = stack[0];
    v0133 = qcar(v0133);
    v0133 = qcar(v0133);
    fn = elt(env, 11); /* update!-pline */
    v0134 = (*qfnn(fn))(qenv(fn), 3, v0035, v0134, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    v0133 = qvalue(elt(env, 7)); /* pline!* */
    v0133 = Lappend(nil, v0134, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    qvalue(elt(env, 7)) = v0133; /* pline!* */
    v0134 = qvalue(elt(env, 1)); /* posn!* */
    v0133 = stack[0];
    v0133 = qcar(v0133);
    v0133 = qcdr(v0133);
    v0133 = (Lisp_Object)(int32_t)((int32_t)v0134 + (int32_t)v0133 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v0133; /* posn!* */
    v0035 = qvalue(elt(env, 8)); /* ymin!* */
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0134 = qcar(v0133);
    v0133 = qvalue(elt(env, 6)); /* ycoord!* */
    v0133 = (Lisp_Object)(int32_t)((int32_t)v0134 + (int32_t)v0133 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v0133 = (*qfn2(fn))(qenv(fn), v0035, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0133; /* ymin!* */
    v0035 = qvalue(elt(env, 9)); /* ymax!* */
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0134 = qcdr(v0133);
    v0133 = qvalue(elt(env, 6)); /* ycoord!* */
    v0133 = (Lisp_Object)(int32_t)((int32_t)v0134 + (int32_t)v0133 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v0133 = (*qfn2(fn))(qenv(fn), v0035, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    qvalue(elt(env, 9)) = v0133; /* ymax!* */
    v0133 = nil;
    { popv(3); return onevalue(v0133); }
/* error exit handlers */
v0074:
    popv(3);
    return nil;
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0138, v0074, v0128;
    Lisp_Object fn;
    Lisp_Object v0009, v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "red-ratios2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    v0009 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0045,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0045;
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */

v0139:
    v0137 = stack[-4];
    if (v0137 == nil) goto v0037;
    v0138 = stack[-2];
    v0137 = stack[-3];
    v0137 = qcar(v0137);
    stack[0] = times2(v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    stack[-5] = stack[0];
    v0138 = stack[-1];
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    v0137 = times2(v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    if (equal(stack[0], v0137)) goto v0029;
    v0137 = qvalue(elt(env, 1)); /* nil */
    goto v0042;

v0042:
    if (v0137 == nil) goto v0105;
    v0138 = stack[-1];
    v0137 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v0138, v0137);
    }

v0105:
    v0137 = stack[-4];
    v0128 = qcdr(v0137);
    v0137 = stack[-3];
    v0074 = qcdr(v0137);
    v0138 = stack[-2];
    v0137 = stack[-1];
    stack[-4] = v0128;
    stack[-3] = v0074;
    stack[-2] = v0138;
    stack[-1] = v0137;
    goto v0139;

v0029:
    v0138 = stack[-5];
    v0137 = (Lisp_Object)1; /* 0 */
    if (v0138 == v0137) goto v0097;
    v0138 = stack[-1];
    v0137 = stack[-2];
    v0138 = Lgcd(nil, v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    v0137 = stack[-1];
    v0138 = Cremainder(v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    v0137 = (Lisp_Object)1; /* 0 */
    v0137 = (v0138 == v0137 ? lisp_true : nil);
    goto v0042;

v0097:
    v0137 = qvalue(elt(env, 1)); /* nil */
    goto v0042;

v0037:
    v0137 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0137); }
/* error exit handlers */
v0023:
    popv(7);
    return nil;
}



/* Code for gperm2 */

static Lisp_Object MS_CDECL CC_gperm2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0052, v0015, v0019;
    Lisp_Object fn;
    Lisp_Object v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gperm2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0045;
    stack[-1] = v0001;
    v0014 = v0000;
/* end of prologue */

v0096:
    v0052 = v0014;
    if (v0052 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0052 = v0014;
    v0052 = qcdr(v0052);
    stack[-2] = v0052;
    v0052 = qcar(v0014);
    v0014 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* rev */
    v0019 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0015 = stack[-1];
    v0052 = qvalue(elt(env, 1)); /* nil */
    v0014 = stack[0];
    fn = elt(env, 3); /* gperm1 */
    v0014 = (*qfnn(fn))(qenv(fn), 4, v0019, v0015, v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[0] = v0014;
    v0014 = stack[-2];
    goto v0096;
/* error exit handlers */
v0029:
    popv(4);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    v0052 = v0015;
    if (v0052 == nil) goto v0006;
    v0052 = v0015;
    v0052 = qcdr(v0052);
    if (v0052 == nil) { popv(2); return onevalue(v0015); }
    v0052 = v0015;
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    if (v0052 == nil) goto v0041;
    v0052 = v0015;
    stack[0] = qcar(v0052);
    v0052 = v0015;
    v0052 = qcdr(v0052);
    v0052 = CC_ordn(env, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    {
        Lisp_Object v0102 = stack[0];
        popv(2);
        fn = elt(env, 2); /* ordad */
        return (*qfn2(fn))(qenv(fn), v0102, v0052);
    }

v0041:
    v0052 = v0015;
    v0052 = qcar(v0052);
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    {
        popv(2);
        fn = elt(env, 3); /* ord2 */
        return (*qfn2(fn))(qenv(fn), v0052, v0015);
    }

v0006:
    v0052 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0052); }
/* error exit handlers */
v0034:
    popv(2);
    return nil;
}



/* Code for lalr_action */

static Lisp_Object CC_lalr_action(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0043, v0028;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_action");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0043 = v0001;
    v0041 = v0000;
/* end of prologue */
    v0028 = v0043;
    v0043 = v0041;
    v0041 = elt(env, 1); /* produces */
    v0041 = get(v0043, v0041);
    v0041 = Lassoc(nil, v0028, v0041);
    v0041 = qcdr(v0041);
    return onevalue(v0041);
}



/* Code for comfac */

static Lisp_Object CC_comfac(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    v0146 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0146)) v0146 = nil;
    else { v0146 = qfastgets(v0146);
           if (v0146 != nil) { v0146 = elt(v0146, 3); /* field */
#ifdef RECORD_GET
             if (v0146 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0146 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0146 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0146 == SPID_NOPROP) v0146 = nil; else v0146 = lisp_true; }}
#endif
    if (v0146 == nil) goto v0054;
    v0146 = stack[-2];
    fn = elt(env, 4); /* lnc */
    v0147 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    stack[-3] = v0147;
    v0146 = (Lisp_Object)17; /* 1 */
    v0146 = Lneq(nil, v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    goto v0057;

v0057:
    if (v0146 == nil) goto v0036;
    v0146 = stack[-3];
    fn = elt(env, 5); /* !:recip */
    v0147 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    v0146 = stack[-2];
    fn = elt(env, 6); /* multd */
    v0146 = (*qfn2(fn))(qenv(fn), v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    stack[-2] = v0146;
    goto v0036;

v0036:
    v0146 = stack[-2];
    v0146 = qcdr(v0146);
    if (v0146 == nil) goto v0080;
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    stack[-3] = v0146;
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    v0146 = qcar(v0146);
    v0146 = qcar(v0146);
    stack[-1] = v0146;
    goto v0060;

v0060:
    v0146 = stack[-2];
    v0146 = qcdr(v0146);
    stack[-2] = v0146;
    v0147 = stack[-2];
    v0146 = stack[-1];
    fn = elt(env, 7); /* degr */
    v0147 = (*qfn2(fn))(qenv(fn), v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    v0146 = (Lisp_Object)1; /* 0 */
    if (v0147 == v0146) goto v0075;
    v0146 = stack[-2];
    v0146 = qcdr(v0146);
    if (v0146 == nil) goto v0149;
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    v0147 = qcdr(v0146);
    v0146 = stack[-3];
    fn = elt(env, 8); /* gcdf */
    v0146 = (*qfn2(fn))(qenv(fn), v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    stack[-3] = v0146;
    goto v0060;

v0149:
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    stack[0] = qcar(v0146);
    v0147 = stack[-3];
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    fn = elt(env, 8); /* gcdf */
    v0146 = (*qfn2(fn))(qenv(fn), v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    {
        Lisp_Object v0063 = stack[0];
        popv(5);
        return cons(v0063, v0146);
    }

v0075:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0146 = stack[-2];
    if (!consp(v0146)) goto v0136;
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    v0146 = (consp(v0146) ? nil : lisp_true);
    goto v0135;

v0135:
    if (v0146 == nil) goto v0092;
    v0146 = qvalue(elt(env, 3)); /* t */
    goto v0031;

v0031:
    if (v0146 == nil) goto v0072;
    v0147 = stack[-3];
    v0146 = stack[-2];
    fn = elt(env, 8); /* gcdf */
    v0146 = (*qfn2(fn))(qenv(fn), v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    goto v0097;

v0097:
    {
        Lisp_Object v0064 = stack[0];
        popv(5);
        return cons(v0064, v0146);
    }

v0072:
    v0146 = (Lisp_Object)17; /* 1 */
    goto v0097;

v0092:
    v0146 = stack[-1];
    fn = elt(env, 9); /* noncomp */
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    if (v0146 == nil) goto v0046;
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    v0146 = qcar(v0146);
    v0146 = qcar(v0146);
    fn = elt(env, 9); /* noncomp */
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-4];
    goto v0004;

v0004:
    v0146 = (v0146 == nil ? lisp_true : nil);
    goto v0031;

v0046:
    v0146 = qvalue(elt(env, 2)); /* nil */
    goto v0004;

v0136:
    v0146 = qvalue(elt(env, 3)); /* t */
    goto v0135;

v0080:
    v0146 = stack[-2];
    v0146 = qcar(v0146);
    { popv(5); return onevalue(v0146); }

v0054:
    v0146 = qvalue(elt(env, 2)); /* nil */
    goto v0057;
/* error exit handlers */
v0148:
    popv(5);
    return nil;
}



/* Code for cl_simplat */

static Lisp_Object CC_cl_simplat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0119, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simplat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0119 = v0001;
    v0113 = v0000;
/* end of prologue */
    v0127 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v0127 == nil) goto v0026;
    v0127 = v0113;
    fn = elt(env, 3); /* rl_simplat1 */
    v0119 = (*qfn2(fn))(qenv(fn), v0127, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[0];
    v0127 = elt(env, 2); /* cl_identifyat */
    {
        popv(1);
        fn = elt(env, 4); /* cl_apply2ats */
        return (*qfn2(fn))(qenv(fn), v0119, v0127);
    }

v0026:
    v0127 = v0113;
    {
        popv(1);
        fn = elt(env, 3); /* rl_simplat1 */
        return (*qfn2(fn))(qenv(fn), v0127, v0119);
    }
/* error exit handlers */
v0114:
    popv(1);
    return nil;
}



/* Code for cl_susiminlevel */

static Lisp_Object CC_cl_susiminlevel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0114, v0140, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiminlevel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0140 = v0001;
    v0051 = v0000;
/* end of prologue */
    v0114 = v0051;
    v0113 = elt(env, 1); /* ignore */
    if (v0114 == v0113) return onevalue(v0140);
    v0114 = v0140;
    v0113 = elt(env, 1); /* ignore */
    if (v0114 == v0113) return onevalue(v0051);
    v0113 = v0051;
    v0114 = v0140;
    {
        fn = elt(env, 2); /* min */
        return (*qfn2(fn))(qenv(fn), v0113, v0114);
    }
}



/* Code for ibalp_mk2 */

static Lisp_Object MS_CDECL CC_ibalp_mk2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0016, v0017;
    Lisp_Object v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0108 = v0045;
    v0016 = v0001;
    v0017 = v0000;
/* end of prologue */
    return list3(v0017, v0016, v0108);
}



/* Code for bcone!? */

static Lisp_Object CC_bconeW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0052, v0015;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcone?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0014 == nil) goto v0028;
    v0052 = v0015;
    v0014 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v0052, v0014);

v0028:
    v0014 = v0015;
    v0052 = qcdr(v0014);
    v0014 = (Lisp_Object)17; /* 1 */
    if (v0052 == v0014) goto v0081;
    v0014 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0014);

v0081:
    v0014 = v0015;
    v0052 = qcar(v0014);
    v0014 = (Lisp_Object)17; /* 1 */
    v0014 = (v0052 == v0014 ? lisp_true : nil);
    return onevalue(v0014);
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deg*farg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    v0052 = v0015;
    v0052 = qcdr(v0052);
    if (v0052 == nil) goto v0006;
    stack[-1] = nil;
    v0052 = v0015;
    stack[0] = v0052;
    goto v0041;

v0041:
    v0052 = stack[0];
    if (v0052 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0052 = stack[0];
    v0052 = qcar(v0052);
    fn = elt(env, 2); /* deg!*form */
    v0015 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0052 = stack[-1];
    fn = elt(env, 3); /* addf */
    v0052 = (*qfn2(fn))(qenv(fn), v0015, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    stack[-1] = v0052;
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    goto v0041;

v0006:
    v0052 = v0015;
    v0052 = qcar(v0052);
    {
        popv(3);
        fn = elt(env, 2); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
/* error exit handlers */
v0102:
    popv(3);
    return nil;
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-set");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    v0057 = v0037;
    v0037 = elt(env, 1); /* set!-ordp */
    fn = elt(env, 2); /* sort */
    v0037 = (*qfn2(fn))(qenv(fn), v0057, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* makelist */
        return (*qfn1(fn))(qenv(fn), v0037);
    }
/* error exit handlers */
v0038:
    popv(1);
    return nil;
}



/* Code for lessp!: */

static Lisp_Object CC_lesspT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lessp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0057 = v0001;
    v0037 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v0057, v0037);
    }
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0034 = stack[0];
    v0102 = Llength(nil, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    v0034 = (Lisp_Object)33; /* 2 */
    if (!(v0102 == v0034)) goto v0028;
    v0034 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    goto v0028;

v0028:
    v0102 = qvalue(elt(env, 1)); /* nil */
    v0034 = (Lisp_Object)17; /* 1 */
    v0034 = cons(v0102, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    stack[-1] = v0034;
    goto v0053;

v0053:
    v0034 = stack[0];
    if (v0034 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0034 = stack[0];
    fn = elt(env, 3); /* simpcar */
    v0102 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    v0034 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v0034 = (*qfn2(fn))(qenv(fn), v0102, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    stack[-1] = v0034;
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0053;
/* error exit handlers */
v0078:
    popv(3);
    return nil;
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnquotient:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0127 = stack[-1];
    v0127 = qcdr(v0127);
    v0119 = qcar(v0127);
    v0127 = stack[0];
    v0127 = qcdr(v0127);
    v0127 = qcdr(v0127);
    stack[-2] = times2(v0119, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-3];
    v0127 = stack[-1];
    v0127 = qcdr(v0127);
    v0119 = qcdr(v0127);
    v0127 = stack[0];
    v0127 = qcdr(v0127);
    v0127 = qcar(v0127);
    v0127 = times2(v0119, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-3];
    {
        Lisp_Object v0112 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0112, v0127);
    }
/* error exit handlers */
v0051:
    popv(4);
    return nil;
}



/* Code for lalr_first */

static Lisp_Object CC_lalr_first(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0150, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_first");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    stack[0] = nil;
    goto v0036;

v0036:
    v0089 = stack[-1];
    if (v0089 == nil) goto v0096;
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    if (is_number(v0089)) goto v0051;
    v0126 = qvalue(elt(env, 1)); /* nil */
    v0089 = stack[-1];
    v0150 = qcar(v0089);
    v0089 = elt(env, 0); /* lalr_first */
    v0089 = get(v0150, v0089);
    env = stack[-3];
    stack[0] = v0089;
    v0089 = Lmember(nil, v0126, v0089);
    goto v0017;

v0017:
    if (v0089 == nil) goto v0096;
    v0150 = qvalue(elt(env, 1)); /* nil */
    v0089 = stack[0];
    v0150 = Ldeleq(nil, v0150, v0089);
    env = stack[-3];
    v0089 = stack[-2];
    fn = elt(env, 2); /* union */
    v0089 = (*qfn2(fn))(qenv(fn), v0150, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-3];
    stack[-2] = v0089;
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    goto v0036;

v0096:
    v0089 = stack[-1];
    if (v0089 == nil) goto v0123;
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    if (is_number(v0089)) goto v0097;
    v0150 = stack[0];
    v0089 = stack[-2];
    fn = elt(env, 2); /* union */
    v0089 = (*qfn2(fn))(qenv(fn), v0150, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    stack[-2] = v0089;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0097:
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    v0150 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-3];
    v0089 = stack[-2];
    fn = elt(env, 2); /* union */
    v0089 = (*qfn2(fn))(qenv(fn), v0150, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    stack[-2] = v0089;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0123:
    v0150 = qvalue(elt(env, 1)); /* nil */
    v0089 = stack[-2];
    v0089 = cons(v0150, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    stack[-2] = v0089;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0051:
    v0089 = qvalue(elt(env, 1)); /* nil */
    goto v0017;
/* error exit handlers */
v0004:
    popv(4);
    return nil;
}



/* Code for anform1 */

static Lisp_Object CC_anform1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for anform1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0073 = stack[-1];
    v0073 = qcar(v0073);
    stack[-2] = v0073;
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    stack[-1] = v0073;
    v0073 = stack[-2];
    if (!consp(v0073)) goto v0037;
    v0073 = stack[-2];
    v0073 = CC_anform1(env, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    v0073 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0037:
    v0073 = stack[-2];
    if (symbolp(v0073)) goto v0115;
    v0073 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0073); }

v0115:
    v0072 = stack[-2];
    v0073 = elt(env, 2); /* dclglb */
    v0073 = Lflagp(nil, v0072, v0073);
    env = stack[-3];
    if (v0073 == nil) goto v0010;
    v0072 = stack[-2];
    v0073 = elt(env, 3); /* glb2rf */
    v0073 = Lflagp(nil, v0072, v0073);
    env = stack[-3];
    if (!(v0073 == nil)) goto v0114;
    v0073 = stack[-2];
    v0072 = ncons(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    v0073 = elt(env, 3); /* glb2rf */
    v0073 = Lflag(nil, v0072, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    v0072 = stack[-2];
    v0073 = qvalue(elt(env, 4)); /* globs!* */
    v0073 = cons(v0072, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0073; /* globs!* */
    goto v0114;

v0114:
    v0073 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0010:
    v0072 = stack[-2];
    v0073 = qvalue(elt(env, 5)); /* locls!* */
    v0073 = Lassoc(nil, v0072, v0073);
    if (v0073 == nil) goto v0043;
    v0073 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0043:
    v0073 = stack[-2];
    fn = elt(env, 9); /* add2calls */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    stack[0] = stack[-2];
    v0073 = stack[-1];
    v0073 = Llength(nil, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    fn = elt(env, 10); /* checkargcount */
    v0073 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    v0072 = stack[-2];
    v0073 = elt(env, 6); /* noanl */
    v0073 = Lflagp(nil, v0072, v0073);
    env = stack[-3];
    if (!(v0073 == nil)) goto v0136;
    v0072 = stack[-2];
    v0073 = elt(env, 7); /* anlfn */
    v0073 = get(v0072, v0073);
    env = stack[-3];
    v0072 = v0073;
    if (v0073 == nil) goto v0024;
    v0073 = stack[-1];
    v0073 = Lapply1(nil, v0072, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    goto v0136;

v0136:
    v0073 = nil;
    { popv(4); return onevalue(v0073); }

v0024:
    v0073 = stack[-1];
    fn = elt(env, 8); /* anforml */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    goto v0136;
/* error exit handlers */
v0152:
    popv(4);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0019, v0034, v0102, v0124, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0124 = v0001;
    v0029 = v0000;
/* end of prologue */
    v0015 = v0029;
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    v0102 = v0015;
    v0015 = v0124;
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    v0034 = v0015;
    v0019 = v0102;
    v0015 = v0034;
    if (equal(v0019, v0015)) goto v0119;
    v0015 = v0102;
    v0019 = v0034;
    fn = elt(env, 1); /* ordp */
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0019);
    errexit();
    v0015 = (v0015 == nil ? lisp_true : nil);
    return onevalue(v0015);

v0119:
    v0015 = v0029;
    v0015 = qcar(v0015);
    v0019 = v0124;
    v0019 = qcar(v0019);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v0015, v0019);
    }
}



/* Code for ofsf_smwmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smwmkatl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0014, v0052, v0015, v0019;
    Lisp_Object fn;
    Lisp_Object v0009, v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwmkatl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    v0009 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0009;
    v0052 = v0045;
    v0015 = v0001;
    v0019 = v0000;
/* end of prologue */
    v0080 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0080 == nil) goto v0059;
    v0080 = v0019;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0080, v0015, v0052, v0014);
    }

v0059:
    v0080 = v0019;
    {
        fn = elt(env, 3); /* ofsf_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0080, v0015, v0052, v0014);
    }
}



/* Code for wulessp!* */

static Lisp_Object CC_wulesspH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wulessp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0051 = stack[-1];
    v0140 = stack[0];
    fn = elt(env, 3); /* wulessp */
    v0140 = (*qfn2(fn))(qenv(fn), v0051, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    if (v0140 == nil) goto v0041;
    v0140 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0140); }

v0041:
    v0051 = stack[0];
    v0140 = stack[-1];
    fn = elt(env, 3); /* wulessp */
    v0140 = (*qfn2(fn))(qenv(fn), v0051, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    if (v0140 == nil) goto v0082;
    v0140 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0140); }

v0082:
    v0051 = stack[-1];
    v0140 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* totallessp */
        return (*qfn2(fn))(qenv(fn), v0051, v0140);
    }
/* error exit handlers */
v0014:
    popv(3);
    return nil;
}



/* Code for poly!-abs */

static Lisp_Object CC_polyKabs(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-abs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0038 = stack[0];
    fn = elt(env, 1); /* poly!-minusp */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    if (v0038 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0038 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v0038);
    }
/* error exit handlers */
v0108:
    popv(2);
    return nil;
}



/* Code for symbol */

static Lisp_Object CC_symbol(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbol");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0000;
/* end of prologue */
    v0037 = elt(env, 1); /* symbol!-character */
    return get(v0040, v0037);
}



/* Code for pasf_deci */

static Lisp_Object CC_pasf_deci(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0059, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_deci");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0054 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* pasf_dec */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    errexit();
    v0115 = v0054;
    v0054 = v0115;
    v0059 = qcar(v0054);
    v0054 = v0115;
    v0054 = qcdr(v0054);
    if (v0054 == nil) goto v0017;
    v0054 = v0115;
    v0054 = qcdr(v0054);
    goto v0037;

v0037:
    return cons(v0059, v0054);

v0017:
    v0054 = (Lisp_Object)1; /* 0 */
    goto v0037;
}



/* Code for objectom */

static Lisp_Object CC_objectom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0124, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for objectom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0124 = v0000;
/* end of prologue */
    v0102 = v0124;
    v0102 = Lconsp(nil, v0102);
    env = stack[-1];
    if (v0102 == nil) goto v0052;
    v0102 = v0124;
    v0029 = qcar(v0102);
    v0102 = qvalue(elt(env, 1)); /* ir2mml!* */
    v0102 = Lassoc(nil, v0029, v0102);
    v0029 = v0102;
    if (v0102 == nil) goto v0140;
    v0102 = v0029;
    v0102 = qcdr(v0102);
    v0102 = qcdr(v0102);
    v0102 = qcdr(v0102);
    stack[0] = qcar(v0102);
    v0102 = v0124;
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    fn = elt(env, 3); /* apply */
    v0102 = (*qfn2(fn))(qenv(fn), stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    goto v0060;

v0060:
    v0102 = nil;
    { popv(2); return onevalue(v0102); }

v0140:
    v0102 = v0124;
    fn = elt(env, 4); /* fnom */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    goto v0060;

v0052:
    v0102 = v0124;
    fn = elt(env, 5); /* basicom */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    goto v0060;
/* error exit handlers */
v0087:
    popv(2);
    return nil;
}



/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0196, v0197, v0198;
    Lisp_Object fn;
    Lisp_Object v0009, v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    v0009 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for letmtr3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0045,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0009;
    stack[-3] = v0045;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = nil;
    v0195 = stack[-5];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    if (v0195 == nil) goto v0115;
    v0196 = stack[-3];
    v0195 = elt(env, 1); /* sparsemat */
    if (!consp(v0196)) goto v0021;
    v0196 = qcar(v0196);
    if (!(v0196 == v0195)) goto v0021;
    v0195 = stack[-5];
    v0195 = qcdr(v0195);
    fn = elt(env, 9); /* revlis */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    stack[-6] = v0195;
    fn = elt(env, 10); /* numlis */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    if (v0195 == nil) goto v0200;
    v0195 = stack[-6];
    v0196 = Llength(nil, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    v0195 = (Lisp_Object)33; /* 2 */
    v0195 = Lneq(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    goto v0142;

v0142:
    if (v0195 == nil) goto v0201;
    v0196 = stack[-5];
    v0195 = elt(env, 6); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0201:
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = stack[-6];
    v0195 = qcar(v0195);
    v0195 = *(Lisp_Object *)((char *)v0196 + (CELL-TAG_VECTOR) + ((int32_t)v0195/(16/CELL)));
    v0198 = v0195;
    v0195 = v0198;
    if (v0195 == nil) goto v0202;
    v0195 = stack[-6];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = v0198;
    v0195 = Latsoc(nil, v0196, v0195);
    v0197 = v0195;
    v0195 = v0197;
    if (v0195 == nil) goto v0203;
    v0196 = stack[-4];
    v0195 = (Lisp_Object)1; /* 0 */
    if (v0196 == v0195) goto v0204;
    v0195 = qvalue(elt(env, 7)); /* nil */
    goto v0205;

v0205:
    if (v0195 == nil) goto v0206;
    v0195 = v0198;
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    if (v0195 == nil) goto v0207;
    stack[0] = v0198;
    v0195 = v0197;
    v0196 = v0198;
    v0195 = Ldelete(nil, v0195, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = Lrplacd(nil, stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    goto v0017;

v0017:
    v0195 = nil;
    { popv(8); return onevalue(v0195); }

v0207:
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = stack[-6];
    v0195 = qcar(v0195);
    v0197 = qvalue(elt(env, 7)); /* nil */
    *(Lisp_Object *)((char *)v0196 + (CELL-TAG_VECTOR) + ((int32_t)v0195/(16/CELL))) = v0197;
    goto v0017;

v0206:
    v0196 = v0197;
    v0195 = stack[-4];
    v0195 = Lrplacd(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    goto v0017;

v0204:
    v0196 = stack[-2];
    v0195 = elt(env, 8); /* cx */
    v0195 = (v0196 == v0195 ? lisp_true : nil);
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0205;

v0203:
    v0196 = stack[-4];
    v0195 = (Lisp_Object)1; /* 0 */
    if (v0196 == v0195) goto v0208;
    v0195 = qvalue(elt(env, 7)); /* nil */
    goto v0209;

v0209:
    if (!(v0195 == nil)) goto v0017;
    v0195 = stack[-6];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0197 = v0198;
    v0195 = stack[-4];
    fn = elt(env, 12); /* sortcolelem */
    v0195 = (*qfnn(fn))(qenv(fn), 3, v0196, v0197, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    goto v0017;

v0208:
    v0196 = stack[-2];
    v0195 = elt(env, 8); /* cx */
    v0195 = (v0196 == v0195 ? lisp_true : nil);
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0209;

v0202:
    v0196 = stack[-4];
    v0195 = (Lisp_Object)1; /* 0 */
    if (v0196 == v0195) goto v0210;
    v0195 = qvalue(elt(env, 7)); /* nil */
    goto v0085;

v0085:
    if (!(v0195 == nil)) goto v0017;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    stack[-2] = qcar(v0195);
    v0195 = stack[-6];
    stack[-1] = qcar(v0195);
    v0195 = qvalue(elt(env, 7)); /* nil */
    stack[0] = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    v0195 = stack[-6];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = stack[-4];
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    v0195 = list2(stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0195;
    goto v0017;

v0210:
    v0196 = stack[-2];
    v0195 = elt(env, 8); /* cx */
    v0195 = (v0196 == v0195 ? lisp_true : nil);
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0085;

v0200:
    v0195 = qvalue(elt(env, 5)); /* t */
    goto v0142;

v0021:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0197 = elt(env, 3); /* "Matrix" */
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = elt(env, 4); /* "not set" */
    v0195 = list3(v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0195 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    goto v0201;

v0115:
    v0196 = stack[-3];
    v0195 = elt(env, 1); /* sparsemat */
    if (!consp(v0196)) goto v0114;
    v0196 = qcar(v0196);
    if (!(v0196 == v0195)) goto v0114;
    v0195 = stack[-5];
    v0195 = qcdr(v0195);
    fn = elt(env, 9); /* revlis */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    stack[-6] = v0195;
    fn = elt(env, 10); /* numlis */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    if (v0195 == nil) goto v0111;
    v0195 = stack[-6];
    v0196 = Llength(nil, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    v0195 = (Lisp_Object)17; /* 1 */
    v0195 = Lneq(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    goto v0110;

v0110:
    if (v0195 == nil) goto v0129;
    v0196 = stack[-5];
    v0195 = elt(env, 6); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0129:
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0197 = qcar(v0195);
    v0195 = stack[-5];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = stack[-4];
    *(Lisp_Object *)((char *)v0197 + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL))) = v0195;
    goto v0017;

v0111:
    v0195 = qvalue(elt(env, 5)); /* t */
    goto v0110;

v0114:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0197 = elt(env, 3); /* "Matrix" */
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = elt(env, 4); /* "not set" */
    v0195 = list3(v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0195 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    goto v0129;
/* error exit handlers */
v0199:
    popv(8);
    return nil;
}



/* Code for testred */

static Lisp_Object CC_testred(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0191, v0192, v0212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0192 = qvalue(elt(env, 2)); /* maxvar */
    v0191 = stack[0];
    v0191 = plus2(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-2];
    v0192 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0191/(16/CELL)));
    v0191 = (Lisp_Object)1; /* 0 */
    v0191 = *(Lisp_Object *)((char *)v0192 + (CELL-TAG_VECTOR) + ((int32_t)v0191/(16/CELL)));
    if (v0191 == nil) goto v0053;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0192 = qvalue(elt(env, 2)); /* maxvar */
    v0191 = stack[0];
    v0191 = plus2(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-2];
    v0192 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0191/(16/CELL)));
    v0191 = (Lisp_Object)17; /* 1 */
    v0191 = *(Lisp_Object *)((char *)v0192 + (CELL-TAG_VECTOR) + ((int32_t)v0191/(16/CELL)));
    v0191 = qcar(v0191);
    v0192 = qcar(v0191);
    v0191 = (Lisp_Object)33; /* 2 */
    v0191 = (Lisp_Object)lessp2(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    v0191 = v0191 ? lisp_true : nil;
    env = stack[-2];
    if (v0191 == nil) goto v0053;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0192 = qvalue(elt(env, 2)); /* maxvar */
    v0191 = stack[0];
    v0191 = plus2(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-2];
    v0212 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0191/(16/CELL)));
    v0192 = (Lisp_Object)1; /* 0 */
    v0191 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0212 + (CELL-TAG_VECTOR) + ((int32_t)v0192/(16/CELL))) = v0191;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0192 = qvalue(elt(env, 2)); /* maxvar */
    v0191 = stack[0];
    v0191 = plus2(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-2];
    v0192 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0191/(16/CELL)));
    v0191 = (Lisp_Object)65; /* 4 */
    v0191 = *(Lisp_Object *)((char *)v0192 + (CELL-TAG_VECTOR) + ((int32_t)v0191/(16/CELL)));
    stack[-1] = v0191;
    goto v0131;

v0131:
    v0191 = stack[-1];
    if (v0191 == nil) goto v0002;
    v0191 = stack[-1];
    v0191 = qcar(v0191);
    stack[0] = v0191;
    v0191 = stack[0];
    v0192 = qcar(v0191);
    v0191 = stack[0];
    v0191 = qcdr(v0191);
    v0191 = qcar(v0191);
    fn = elt(env, 4); /* downwght1 */
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-2];
    v0191 = stack[0];
    v0191 = qcar(v0191);
    v0191 = CC_testred(env, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-2];
    v0191 = stack[-1];
    v0191 = qcdr(v0191);
    stack[-1] = v0191;
    goto v0131;

v0002:
    v0191 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0191); }

v0053:
    v0191 = nil;
    { popv(3); return onevalue(v0191); }
/* error exit handlers */
v0142:
    popv(3);
    return nil;
}



/* Code for diplength */

static Lisp_Object CC_diplength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diplength");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0060;

v0060:
    v0015 = stack[0];
    if (v0015 == nil) goto v0096;
    v0019 = (Lisp_Object)17; /* 1 */
    v0015 = stack[-1];
    v0015 = cons(v0019, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    stack[-1] = v0015;
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    stack[0] = v0015;
    goto v0060;

v0096:
    v0015 = (Lisp_Object)1; /* 0 */
    v0019 = v0015;
    goto v0036;

v0036:
    v0015 = stack[-1];
    if (v0015 == nil) { popv(3); return onevalue(v0019); }
    v0015 = stack[-1];
    v0015 = qcar(v0015);
    v0015 = plus2(v0015, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0019 = v0015;
    v0015 = stack[-1];
    v0015 = qcdr(v0015);
    stack[-1] = v0015;
    goto v0036;
/* error exit handlers */
v0124:
    popv(3);
    return nil;
}



/* Code for dim!<deg */

static Lisp_Object CC_dimRdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dim<deg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0115 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 4); /* deg!*farg */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    fn = elt(env, 5); /* negf */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    fn = elt(env, 6); /* addf */
    v0115 = (*qfn2(fn))(qenv(fn), stack[0], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    v0081 = v0115;
    v0115 = v0081;
    if (!(is_number(v0115))) goto v0058;
    v0115 = v0081;
    v0115 = Lminusp(nil, v0115);
    env = stack[-1];
    if (v0115 == nil) goto v0058;
    v0115 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0115); }

v0058:
    v0115 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0115); }
/* error exit handlers */
v0104:
    popv(2);
    return nil;
}



/* Code for rread */

static Lisp_Object MS_CDECL CC_rread(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rread");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v0006 = elt(env, 1); /* " '" */
    fn = elt(env, 2); /* prin2x */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* rread1 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0053:
    popv(1);
    return nil;
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0043 = v0000;
/* end of prologue */
    v0028 = v0043;
    v0043 = stack[0];
    v0043 = qcar(v0043);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    popv(1);
    return cons(v0028, v0043);
/* error exit handlers */
v0118:
    popv(1);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_kern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0039 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v0039 = sub1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0039 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0039/(16/CELL)));
    v0039 = qcdr(v0039);
    v0039 = qcdr(v0039);
    v0039 = qcar(v0039);
    { popv(1); return onevalue(v0039); }
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for gintequiv!: */

static Lisp_Object CC_gintequivT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0027, v0118;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gintequiv:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0118 = v0000;
/* end of prologue */
    v0028 = v0118;
    v0028 = qcdr(v0028);
    v0027 = qcdr(v0028);
    v0028 = (Lisp_Object)1; /* 0 */
    if (v0027 == v0028) goto v0006;
    v0028 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0028);

v0006:
    v0028 = v0118;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    return onevalue(v0028);
}



/* Code for canonsq */

static Lisp_Object CC_canonsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0225, v0226, v0227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for canonsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0225 = stack[-2];
    v0226 = qcdr(v0225);
    v0225 = (Lisp_Object)17; /* 1 */
    if (v0226 == v0225) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0225 = stack[-2];
    v0225 = qcar(v0225);
    if (v0225 == nil) goto v0043;
    stack[-1] = nil;
    v0225 = qvalue(elt(env, 2)); /* asymplis!* */
    if (v0225 == nil) goto v0119;
    v0225 = stack[-2];
    v0226 = qcar(v0225);
    v0225 = stack[-2];
    v0225 = qcdr(v0225);
    fn = elt(env, 7); /* gcdf */
    v0226 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-3] = v0226;
    v0225 = (Lisp_Object)17; /* 1 */
    if (v0226 == v0225) goto v0119;
    v0225 = stack[-2];
    v0226 = qcar(v0225);
    v0225 = stack[-3];
    fn = elt(env, 8); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0225 = stack[-2];
    v0226 = qcdr(v0225);
    v0225 = stack[-3];
    fn = elt(env, 8); /* quotf */
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0225 = cons(stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-2] = v0225;
    goto v0119;

v0119:
    v0225 = stack[-2];
    v0225 = qcdr(v0225);
    fn = elt(env, 9); /* lnc */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-3] = v0225;
    v0226 = stack[-3];
    v0225 = (Lisp_Object)17; /* 1 */
    if (v0226 == v0225) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0225 = stack[-3];
    if (!consp(v0225)) goto v0056;
    v0225 = stack[-3];
    v0225 = qcar(v0225);
    if (!symbolp(v0225)) v0226 = nil;
    else { v0226 = qfastgets(v0225);
           if (v0226 != nil) { v0226 = elt(v0226, 30); /* minusp */
#ifdef RECORD_GET
             if (v0226 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0226 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0226 == SPID_NOPROP) v0226 = nil; }}
#endif
    v0225 = stack[-3];
    v0225 = Lapply1(nil, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    if (v0225 == nil) goto v0100;
    v0225 = stack[-2];
    v0225 = qcar(v0225);
    fn = elt(env, 10); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0225 = stack[-2];
    v0225 = qcdr(v0225);
    fn = elt(env, 10); /* negf */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0225 = cons(stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-2] = v0225;
    v0225 = stack[-3];
    v0226 = qcar(v0225);
    v0225 = elt(env, 3); /* difference */
    stack[0] = get(v0226, v0225);
    env = stack[-4];
    v0225 = stack[-3];
    v0225 = qcar(v0225);
    if (!symbolp(v0225)) v0226 = nil;
    else { v0226 = qfastgets(v0225);
           if (v0226 != nil) { v0226 = elt(v0226, 34); /* i2d */
#ifdef RECORD_GET
             if (v0226 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0226 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0226 == SPID_NOPROP) v0226 = nil; }}
#endif
    v0225 = (Lisp_Object)1; /* 0 */
    v0226 = Lapply1(nil, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0225 = stack[-3];
    v0225 = Lapply2(nil, 3, stack[0], v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-3] = v0225;
    goto v0100;

v0100:
    v0225 = stack[-3];
    if (is_number(v0225)) goto v0229;
    v0226 = qvalue(elt(env, 4)); /* dmode!* */
    v0225 = elt(env, 5); /* unitsfn */
    v0225 = get(v0226, v0225);
    env = stack[-4];
    stack[-1] = v0225;
    goto v0230;

v0230:
    if (v0225 == nil) goto v0231;
    v0227 = stack[-1];
    v0226 = stack[-2];
    v0225 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v0227, v0226, v0225);

v0231:
    v0225 = qvalue(elt(env, 4)); /* dmode!* */
    if (!symbolp(v0225)) v0225 = nil;
    else { v0225 = qfastgets(v0225);
           if (v0225 != nil) { v0225 = elt(v0225, 3); /* field */
#ifdef RECORD_GET
             if (v0225 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0225 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0225 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0225 == SPID_NOPROP) v0225 = nil; else v0225 = lisp_true; }}
#endif
    if (v0225 == nil) goto v0232;
    v0225 = qvalue(elt(env, 6)); /* t */
    goto v0233;

v0233:
    if (v0225 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0226 = stack[-3];
    v0225 = stack[-2];
    {
        popv(5);
        fn = elt(env, 11); /* fieldconv */
        return (*qfn2(fn))(qenv(fn), v0226, v0225);
    }

v0232:
    v0225 = stack[-3];
    if (!consp(v0225)) goto v0178;
    v0225 = stack[-3];
    v0225 = qcar(v0225);
    if (!symbolp(v0225)) v0225 = nil;
    else { v0225 = qfastgets(v0225);
           if (v0225 != nil) { v0225 = elt(v0225, 3); /* field */
#ifdef RECORD_GET
             if (v0225 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0225 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0225 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0225 == SPID_NOPROP) v0225 = nil; else v0225 = lisp_true; }}
#endif
    goto v0233;

v0178:
    v0225 = qvalue(elt(env, 1)); /* nil */
    goto v0233;

v0229:
    v0225 = qvalue(elt(env, 1)); /* nil */
    goto v0230;

v0056:
    v0225 = stack[-3];
    v0225 = Lminusp(nil, v0225);
    env = stack[-4];
    if (v0225 == nil) goto v0100;
    v0225 = stack[-2];
    v0225 = qcar(v0225);
    fn = elt(env, 10); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0225 = stack[-2];
    v0225 = qcdr(v0225);
    fn = elt(env, 10); /* negf */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0225 = cons(stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-2] = v0225;
    v0225 = stack[-3];
    v0225 = negate(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-3] = v0225;
    goto v0100;

v0043:
    v0226 = qvalue(elt(env, 1)); /* nil */
    v0225 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0226, v0225);
/* error exit handlers */
v0228:
    popv(5);
    return nil;
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0101, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0079 = v0001;
    v0033 = v0000;
/* end of prologue */
    v0101 = v0033;
    v0101 = qcar(v0101);
    if (v0101 == v0079) goto v0042;
    v0079 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0079); }

v0042:
    v0079 = v0033;
    v0101 = qcdr(v0079);
    v0079 = (Lisp_Object)17; /* 1 */
    if (v0101 == v0079) goto v0016;
    v0079 = v0033;
    stack[-1] = qcdr(v0079);
    v0079 = v0033;
    stack[0] = qcar(v0079);
    v0079 = v0033;
    v0079 = qcdr(v0079);
    v0079 = sub1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    fn = elt(env, 2); /* to */
    v0101 = (*qfn2(fn))(qenv(fn), stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    v0079 = (Lisp_Object)17; /* 1 */
    v0079 = cons(v0101, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    {
        Lisp_Object v0151 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multd */
        return (*qfn2(fn))(qenv(fn), v0151, v0079);
    }

v0016:
    v0079 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0079); }
/* error exit handlers */
v0111:
    popv(3);
    return nil;
}



/* Code for powers1 */

static Lisp_Object CC_powers1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0043 = v0000;
/* end of prologue */
    stack[0] = v0043;
    v0028 = v0043;
    v0043 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* powers3 */
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    v0043 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0086 = stack[0];
        popv(2);
        fn = elt(env, 3); /* powers2 */
        return (*qfnn(fn))(qenv(fn), 3, v0086, v0028, v0043);
    }
/* error exit handlers */
v0118:
    popv(2);
    return nil;
}



/* Code for preptayexp */

static Lisp_Object CC_preptayexp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for preptayexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0057 = v0038;
    if (!consp(v0057)) return onevalue(v0038);
    v0057 = v0038;
    {
        fn = elt(env, 1); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v0057);
    }
}



/* Code for ibalp_istotal */

static Lisp_Object CC_ibalp_istotal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0054;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_istotal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0058 = v0000;
/* end of prologue */

v0139:
    v0054 = v0058;
    if (v0054 == nil) goto v0006;
    v0054 = v0058;
    v0054 = qcar(v0054);
    v0054 = qcdr(v0054);
    v0054 = qcdr(v0054);
    v0054 = qcar(v0054);
    if (v0054 == nil) goto v0057;
    v0058 = qcdr(v0058);
    goto v0139;

v0057:
    v0058 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0058);

v0006:
    v0058 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0058);
}



/* Code for expression */

static Lisp_Object CC_expression(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0004, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expression");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0046 = v0000;
/* end of prologue */
    v0005 = v0046;
    if (!consp(v0005)) goto v0096;
    v0005 = v0046;
    v0004 = qcar(v0005);
    v0005 = elt(env, 1); /* !:rd!: */
    if (v0004 == v0005) goto v0057;
    v0005 = v0046;
    v0004 = qcar(v0005);
    v0005 = qvalue(elt(env, 2)); /* unary!* */
    v0005 = Lassoc(nil, v0004, v0005);
    v0004 = v0005;
    if (v0005 == nil) goto v0100;
    v0005 = v0004;
    v0005 = qcdr(v0005);
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    if (v0005 == nil) goto v0029;
    v0005 = v0004;
    v0005 = qcdr(v0005);
    stack[0] = qcar(v0005);
    v0005 = v0046;
    v0005 = qcdr(v0005);
    v0004 = qcdr(v0004);
    v0004 = qcdr(v0004);
    v0004 = qcar(v0004);
    v0005 = list2(v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v0005 = (*qfn2(fn))(qenv(fn), stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    goto v0060;

v0060:
    v0005 = nil;
    { popv(2); return onevalue(v0005); }

v0029:
    v0005 = v0004;
    v0005 = qcdr(v0005);
    stack[0] = qcar(v0005);
    v0005 = v0046;
    v0005 = qcdr(v0005);
    v0005 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v0005 = (*qfn2(fn))(qenv(fn), stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    goto v0060;

v0100:
    v0005 = v0046;
    v0004 = qcar(v0005);
    v0005 = elt(env, 3); /* !*sq */
    if (v0004 == v0005) goto v0007;
    v0005 = v0046;
    fn = elt(env, 6); /* operator_fn */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    goto v0060;

v0007:
    v0005 = v0046;
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    fn = elt(env, 7); /* prepsq */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-1];
    v0005 = CC_expression(env, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    goto v0060;

v0057:
    v0005 = v0046;
    fn = elt(env, 8); /* printout */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    goto v0060;

v0096:
    v0005 = v0046;
    fn = elt(env, 9); /* f4 */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    goto v0060;
/* error exit handlers */
v0133:
    popv(2);
    return nil;
}



/* Code for c!:extmult */

static Lisp_Object CC_cTextmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0236, v0237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:extmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0236 = stack[-2];
    if (v0236 == nil) goto v0026;
    v0236 = stack[-1];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0036;

v0036:
    if (v0236 == nil) goto v0043;
    v0236 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0236); }

v0043:
    v0237 = stack[-1];
    v0236 = (Lisp_Object)17; /* 1 */
    if (v0237 == v0236) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    fn = elt(env, 3); /* c!:ordexn */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0237 = v0236;
    v0236 = v0237;
    if (v0236 == nil) goto v0223;
    v0236 = v0237;
    stack[0] = qcdr(v0236);
    v0236 = v0237;
    v0236 = qcar(v0236);
    if (v0236 == nil) goto v0132;
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    fn = elt(env, 4); /* c!:subs2multf */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    fn = elt(env, 5); /* negf */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    goto v0110;

v0110:
    v0236 = cons(stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-3] = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0237 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[0] = CC_cTextmult(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0236 = stack[-2];
    v0237 = qcdr(v0236);
    v0236 = stack[-1];
    v0236 = CC_cTextmult(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    fn = elt(env, 6); /* c!:extadd */
    v0236 = (*qfn2(fn))(qenv(fn), stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    {
        Lisp_Object v0238 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v0238, v0236);
    }

v0132:
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    fn = elt(env, 4); /* c!:subs2multf */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    goto v0110;

v0223:
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0237 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[0] = CC_cTextmult(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0236 = stack[-2];
    v0237 = qcdr(v0236);
    v0236 = stack[-1];
    v0236 = CC_cTextmult(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    {
        Lisp_Object v0065 = stack[0];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v0065, v0236);
    }

v0026:
    v0236 = qvalue(elt(env, 1)); /* t */
    goto v0036;
/* error exit handlers */
v0190:
    popv(5);
    return nil;
}



/* Code for quotk */

static Lisp_Object CC_quotk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0130, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0130 = qcdr(v0032);
    v0032 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v0032 = (*qfn2(fn))(qenv(fn), v0130, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    stack[-2] = v0032;
    v0032 = stack[-2];
    if (v0032 == nil) goto v0107;
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    if (v0032 == nil) goto v0059;
    v0032 = stack[-1];
    v0130 = qcdr(v0032);
    v0032 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v0032 = (*qfn2(fn))(qenv(fn), v0130, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0130 = v0032;
    v0032 = v0130;
    if (v0032 == nil) goto v0077;
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0075 = qcar(v0032);
    v0032 = stack[-2];
    popv(4);
    return acons(v0075, v0032, v0130);

v0077:
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0032); }

v0059:
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0130 = qcar(v0032);
    v0032 = stack[-2];
    v0032 = cons(v0130, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    popv(4);
    return ncons(v0032);

v0107:
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0032); }
/* error exit handlers */
v0116:
    popv(4);
    return nil;
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0234, v0223, v0149, v0193, v0240, v0191, v0192;
    Lisp_Object fn;
    Lisp_Object v0009, v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    v0009 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convertmode1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0045,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0149 = v0009;
    v0193 = v0045;
    v0240 = v0001;
    v0191 = v0000;
/* end of prologue */
    v0223 = v0149;
    v0234 = elt(env, 1); /* real */
    if (!(v0223 == v0234)) goto v0086;
    v0234 = elt(env, 2); /* algebraic */
    v0149 = v0234;
    goto v0086;

v0086:
    v0223 = v0193;
    v0234 = elt(env, 1); /* real */
    if (!(v0223 == v0234)) goto v0114;
    v0234 = elt(env, 2); /* algebraic */
    v0193 = v0234;
    goto v0114;

v0114:
    v0223 = v0193;
    v0234 = v0149;
    if (v0223 == v0234) { popv(1); return onevalue(v0191); }
    v0234 = v0191;
    if (!(symbolp(v0234))) goto v0004;
    v0223 = v0191;
    v0234 = v0240;
    v0234 = Latsoc(nil, v0223, v0234);
    v0192 = v0234;
    if (v0234 == nil) goto v0004;
    v0234 = v0192;
    v0223 = qcdr(v0234);
    v0234 = elt(env, 3); /* (integer scalar real) */
    v0234 = Lmemq(nil, v0223, v0234);
    if (v0234 == nil) goto v0032;
    v0234 = qvalue(elt(env, 4)); /* nil */
    goto v0110;

v0110:
    if (v0234 == nil) goto v0004;
    v0234 = v0191;
    v0223 = v0240;
    v0149 = v0193;
    v0193 = v0192;
    v0193 = qcdr(v0193);
    {
        popv(1);
        fn = elt(env, 5); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0234, v0223, v0149, v0193);
    }

v0004:
    v0223 = v0149;
    v0234 = v0193;
    v0234 = get(v0223, v0234);
    env = stack[0];
    v0192 = v0234;
    if (v0234 == nil) goto v0074;
    v0234 = v0192;
    v0223 = v0191;
    v0149 = v0240;
        popv(1);
        return Lapply2(nil, 3, v0234, v0223, v0149);

v0074:
    v0234 = v0149;
    v0223 = v0193;
    fn = elt(env, 6); /* typerr */
    v0234 = (*qfn2(fn))(qenv(fn), v0234, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0234 = nil;
    { popv(1); return onevalue(v0234); }

v0032:
    v0234 = v0192;
    v0223 = qcdr(v0234);
    v0234 = v0149;
    v0234 = (v0223 == v0234 ? lisp_true : nil);
    v0234 = (v0234 == nil ? lisp_true : nil);
    goto v0110;
/* error exit handlers */
v0212:
    popv(1);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0108 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    v0108 = stack[0];
    fn = elt(env, 2); /* simpcar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    fn = elt(env, 3); /* simpminus */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    {
        Lisp_Object v0041 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0041, v0108);
    }
/* error exit handlers */
v0042:
    popv(3);
    return nil;
}



/* Code for mo!=lexcomp */

static Lisp_Object CC_moMlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0012, v0079, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0012 = v0001;
    v0079 = v0000;
/* end of prologue */

v0053:
    v0050 = v0079;
    if (v0050 == nil) goto v0036;
    v0050 = v0012;
    if (v0050 == nil) goto v0043;
    v0050 = v0079;
    v0101 = qcar(v0050);
    v0050 = v0012;
    v0050 = qcar(v0050);
    if (equal(v0101, v0050)) goto v0086;
    v0050 = v0079;
    v0050 = qcar(v0050);
    v0012 = qcar(v0012);
    if (((int32_t)(v0050)) > ((int32_t)(v0012))) goto v0112;
    v0050 = (Lisp_Object)-15; /* -1 */
    return onevalue(v0050);

v0112:
    v0050 = (Lisp_Object)17; /* 1 */
    return onevalue(v0050);

v0086:
    v0050 = v0079;
    v0050 = qcdr(v0050);
    v0079 = v0050;
    v0050 = v0012;
    v0050 = qcdr(v0050);
    v0012 = v0050;
    goto v0053;

v0043:
    v0050 = elt(env, 1); /* (0) */
    v0012 = v0050;
    goto v0053;

v0036:
    v0050 = v0012;
    if (v0050 == nil) goto v0038;
    v0050 = elt(env, 1); /* (0) */
    v0079 = v0050;
    goto v0053;

v0038:
    v0050 = (Lisp_Object)1; /* 0 */
    return onevalue(v0050);
}



/* Code for general!-modular!-minus */

static Lisp_Object CC_generalKmodularKminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0058, v0054;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0054 = v0000;
/* end of prologue */
    v0058 = v0054;
    v0086 = (Lisp_Object)1; /* 0 */
    if (v0058 == v0086) return onevalue(v0054);
    v0086 = qvalue(elt(env, 1)); /* current!-modulus */
    v0058 = v0054;
    return difference2(v0086, v0058);
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0103, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for carx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0103 = v0001;
    v0127 = v0000;
/* end of prologue */
    v0104 = v0127;
    v0104 = qcdr(v0104);
    if (v0104 == nil) goto v0053;
    stack[-1] = elt(env, 1); /* alg */
    stack[0] = (Lisp_Object)81; /* 5 */
    v0104 = elt(env, 2); /* "Wrong number of arguments to" */
    v0104 = list2(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    {
        Lisp_Object v0140 = stack[-1];
        Lisp_Object v0051 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0140, v0051, v0104);
    }

v0053:
    v0104 = v0127;
    v0104 = qcar(v0104);
    { popv(3); return onevalue(v0104); }
/* error exit handlers */
v0114:
    popv(3);
    return nil;
}



/* Code for exptf */

static Lisp_Object CC_exptf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0075, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0075 = stack[0];
    v0130 = (Lisp_Object)1; /* 0 */
    v0130 = (Lisp_Object)lessp2(v0075, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-2];
    if (v0130 == nil) goto v0060;
    v0030 = elt(env, 1); /* "exptf" */
    v0075 = stack[-1];
    v0130 = stack[0];
    v0130 = list3(v0030, v0075, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* errach */
        return (*qfn1(fn))(qenv(fn), v0130);
    }

v0060:
    v0130 = stack[-1];
    if (!consp(v0130)) goto v0104;
    v0130 = stack[-1];
    v0130 = qcar(v0130);
    v0130 = (consp(v0130) ? nil : lisp_true);
    goto v0082;

v0082:
    if (v0130 == nil) goto v0115;
    v0075 = stack[-1];
    v0130 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v0075, v0130);
    }

v0115:
    v0130 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v0130 == nil)) goto v0079;
    v0130 = stack[-1];
    fn = elt(env, 6); /* kernlp */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    if (!(v0130 == nil)) goto v0079;
    v0075 = stack[-1];
    v0130 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* mksfpf */
        return (*qfn2(fn))(qenv(fn), v0075, v0130);
    }

v0079:
    v0075 = stack[-1];
    v0130 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* exptf1 */
        return (*qfn2(fn))(qenv(fn), v0075, v0130);
    }

v0104:
    v0130 = qvalue(elt(env, 2)); /* t */
    goto v0082;
/* error exit handlers */
v0116:
    popv(3);
    return nil;
}



/* Code for outdefr */

static Lisp_Object CC_outdefr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0086, v0058, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for outdefr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0118 = v0001;
    v0086 = v0000;
/* end of prologue */
    v0058 = v0086;
    v0054 = qcar(v0058);
    v0058 = v0086;
    v0058 = qcdr(v0058);
    v0058 = qcar(v0058);
    v0086 = qcdr(v0086);
    v0086 = qcdr(v0086);
    v0086 = qcar(v0086);
    {
        fn = elt(env, 1); /* outref */
        return (*qfnn(fn))(qenv(fn), 4, v0054, v0058, v0086, v0118);
    }
}



/* Code for prepsq!*2 */

static Lisp_Object CC_prepsqH2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0108, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0039 = v0000;
/* end of prologue */
    v0016 = v0039;
    v0108 = (Lisp_Object)17; /* 1 */
    v0039 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepsq!*1 */
    v0039 = (*qfnn(fn))(qenv(fn), 3, v0016, v0108, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v0039);
    }
/* error exit handlers */
v0017:
    popv(1);
    return nil;
}



/* Code for qqe_ofsf_prepat */

static Lisp_Object CC_qqe_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_prepat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0108 = stack[0];
    fn = elt(env, 1); /* qqe_op */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    fn = elt(env, 2); /* qqe_rqopp */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    if (v0108 == nil) goto v0037;
    v0108 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* qqe_prepat */
        return (*qfn1(fn))(qenv(fn), v0108);
    }

v0037:
    v0108 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* ofsf_prepat */
        return (*qfn1(fn))(qenv(fn), v0108);
    }
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for qsort */

static Lisp_Object CC_qsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0116 = v0000;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    v0097 = v0116;
    if (v0097 == nil) goto v0057;
    v0097 = v0116;
    v0097 = qcar(v0097);
    stack[-3] = v0097;
    v0097 = v0116;
    v0097 = qcdr(v0097);
    stack[0] = v0097;
    goto v0036;

v0036:
    v0097 = stack[0];
    if (v0097 == nil) goto v0111;
    v0116 = stack[-3];
    v0097 = stack[0];
    v0097 = qcar(v0097);
    fn = elt(env, 2); /* ordop */
    v0097 = (*qfn2(fn))(qenv(fn), v0116, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    if (v0097 == nil) goto v0087;
    v0097 = stack[0];
    v0116 = qcar(v0097);
    v0097 = stack[-1];
    v0097 = cons(v0116, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    stack[-1] = v0097;
    goto v0054;

v0054:
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    stack[0] = v0097;
    goto v0036;

v0087:
    v0097 = stack[0];
    v0116 = qcar(v0097);
    v0097 = stack[-2];
    v0097 = cons(v0116, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    stack[-2] = v0097;
    goto v0054;

v0111:
    v0097 = stack[-2];
    stack[0] = CC_qsort(env, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    stack[-2] = stack[-3];
    v0097 = stack[-1];
    v0097 = CC_qsort(env, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0097 = cons(stack[-2], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    {
        Lisp_Object v0100 = stack[0];
        popv(5);
        return Lappend(nil, v0100, v0097);
    }

v0057:
    v0097 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0097); }
/* error exit handlers */
v0099:
    popv(5);
    return nil;
}



/* Code for ibalp_litlp */

static Lisp_Object CC_ibalp_litlp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_litlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0139:
    v0118 = stack[0];
    if (v0118 == nil) goto v0006;
    v0118 = stack[0];
    v0118 = qcar(v0118);
    fn = elt(env, 3); /* ibalp_litp */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    if (v0118 == nil) goto v0057;
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    stack[0] = v0118;
    goto v0139;

v0057:
    v0118 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0118); }

v0006:
    v0118 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0118); }
/* error exit handlers */
v0058:
    popv(2);
    return nil;
}



/* Code for zeropp */

static Lisp_Object CC_zeropp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0058, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zeropp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0054 = v0000;
/* end of prologue */
    v0086 = v0054;
    if (!consp(v0086)) goto v0006;
    v0086 = v0054;
    v0058 = qcar(v0086);
    v0086 = elt(env, 1); /* !:rd!: */
    if (v0058 == v0086) goto v0026;
    v0086 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0086);

v0026:
    v0086 = v0054;
    {
        fn = elt(env, 3); /* rd!:zerop */
        return (*qfn1(fn))(qenv(fn), v0086);
    }

v0006:
    v0086 = v0054;
        return Lzerop(nil, v0086);
}



/* Code for off_mod_reval */

static Lisp_Object CC_off_mod_reval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off_mod_reval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0118 = qvalue(elt(env, 1)); /* !*modular */
    if (v0118 == nil) goto v0042;
    v0118 = elt(env, 2); /* modular */
    v0118 = ncons(v0118);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    fn = elt(env, 4); /* off */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    v0118 = stack[0];
    fn = elt(env, 5); /* reval */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    stack[0] = v0118;
    v0118 = elt(env, 2); /* modular */
    v0118 = ncons(v0118);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    fn = elt(env, 6); /* on */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0042:
    v0118 = stack[0];
    fn = elt(env, 5); /* reval */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    stack[0] = v0118;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0058:
    popv(2);
    return nil;
}



/* Code for evenfree */

static Lisp_Object CC_evenfree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evenfree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0019 = stack[0];
    if (v0019 == nil) goto v0006;
    v0019 = stack[0];
    if (is_number(v0019)) goto v0038;
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0034 = ncons(v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0019 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0019 = (*qfn2(fn))(qenv(fn), v0034, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0019 = qcdr(v0019);
    fn = elt(env, 3); /* absf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    v0019 = CC_evenfree(env, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    {
        Lisp_Object v0078 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v0078, v0019);
    }

v0038:
    v0034 = stack[0];
    v0019 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0019 = (*qfn2(fn))(qenv(fn), v0034, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0019 = qcdr(v0019);
    {
        popv(3);
        fn = elt(env, 3); /* absf */
        return (*qfn1(fn))(qenv(fn), v0019);
    }

v0006:
    v0019 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0019); }
/* error exit handlers */
v0029:
    popv(3);
    return nil;
}



/* Code for opnum!* */

static Lisp_Object CC_opnumH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0010, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opnum*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    stack[-1] = nil;
    v0049 = v0010;
    if (symbolp(v0049)) goto v0036;
    stack[0] = v0010;
    v0049 = v0010;
    fn = elt(env, 3); /* collectindices */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    fn = elt(env, 4); /* removeindices */
    v0049 = (*qfn2(fn))(qenv(fn), stack[0], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0010 = v0049;
    goto v0036;

v0036:
    v0049 = v0010;
    if (symbolp(v0049)) goto v0118;
    v0049 = v0010;
    v0049 = qcar(v0049);
    v0010 = qcdr(v0010);
    stack[-1] = v0010;
    goto v0113;

v0113:
    v0010 = v0049;
    v0049 = elt(env, 2); /* opnum */
    v0049 = get(v0010, v0049);
    env = stack[-2];
    v0107 = v0049;
    v0010 = stack[-1];
    v0049 = v0107;
    v0049 = Lassoc(nil, v0010, v0049);
    v0010 = v0049;
    if (v0049 == nil) goto v0033;
    v0049 = v0010;
    v0049 = qcdr(v0049);
    { popv(3); return onevalue(v0049); }

v0033:
    v0049 = qvalue(elt(env, 1)); /* nil */
    v0010 = v0107;
    v0049 = Lassoc(nil, v0049, v0010);
    v0049 = qcdr(v0049);
    { popv(3); return onevalue(v0049); }

v0118:
    v0049 = v0010;
    goto v0113;
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for contrsp */

static Lisp_Object CC_contrsp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0112, v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contrsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    v0080 = qcar(v0051);
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    v0051 = qcdr(v0051);
    v0112 = qcar(v0051);
    v0051 = stack[0];
    fn = elt(env, 1); /* contrsp2 */
    v0051 = (*qfnn(fn))(qenv(fn), 3, v0080, v0112, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    if (!(v0051 == nil)) { popv(3); return onevalue(v0051); }
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    v0051 = qcdr(v0051);
    v0080 = qcar(v0051);
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    v0112 = qcar(v0051);
    v0051 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* contrsp2 */
        return (*qfnn(fn))(qenv(fn), 3, v0080, v0112, v0051);
    }
/* error exit handlers */
v0015:
    popv(3);
    return nil;
}



/* Code for condterpri */

static Lisp_Object MS_CDECL CC_condterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "condterpri");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for condterpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0033 = qvalue(elt(env, 1)); /* !*output */
    if (v0033 == nil) goto v0009;
    v0033 = qvalue(elt(env, 3)); /* !*echo */
    if (v0033 == nil) goto v0037;
    v0033 = qvalue(elt(env, 4)); /* !*extraecho */
    if (v0033 == nil) goto v0041;
    v0033 = qvalue(elt(env, 5)); /* !*int */
    if (v0033 == nil) goto v0104;
    v0033 = qvalue(elt(env, 7)); /* ifl!* */
    goto v0082;

v0082:
    if (v0033 == nil) goto v0059;
    v0033 = qvalue(elt(env, 8)); /* !*defn */
    if (v0033 == nil) goto v0015;
    v0033 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0033);

v0015:
    v0033 = qvalue(elt(env, 9)); /* !*demo */
    if (v0033 == nil) goto v0029;
    v0033 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0033);

v0029:
        return Lterpri(nil, 0);

v0059:
    v0033 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0033);

v0104:
    v0033 = qvalue(elt(env, 6)); /* t */
    goto v0082;

v0041:
    v0033 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0033);

v0037:
    v0033 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0033);

v0009:
    v0033 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0033);
}



/* Code for bas_make1 */

static Lisp_Object MS_CDECL CC_bas_make1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0115;
    Lisp_Object fn;
    Lisp_Object v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bas_make1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0045 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bas_make1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0045;
    stack[-3] = v0001;
    v0059 = v0000;
/* end of prologue */
    stack[-4] = v0059;
    stack[-1] = stack[-3];
    v0059 = stack[-3];
    stack[0] = Llength(nil, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-5];
    v0059 = stack[-3];
    fn = elt(env, 1); /* dp_ecart */
    v0115 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-5];
    v0059 = stack[-2];
    v0059 = list2(v0115, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    {
        Lisp_Object v0113 = stack[-4];
        Lisp_Object v0114 = stack[-1];
        Lisp_Object v0140 = stack[0];
        popv(6);
        return list3star(v0113, v0114, v0140, v0059);
    }
/* error exit handlers */
v0119:
    popv(6);
    return nil;
}



setup_type const u08_setup[] =
{
    {"wuorderp",                too_few_2,      CC_wuorderp,   wrong_no_2},
    {"rl_prepat",               CC_rl_prepat,   too_many_1,    wrong_no_1},
    {"xxsort",                  CC_xxsort,      too_many_1,    wrong_no_1},
    {"lambda_idn438f46io4",     too_few_2,      CC_lambda_idn438f46io4,wrong_no_2},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"*i2ar",                   CC_Hi2ar,       too_many_1,    wrong_no_1},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"ordpa",                   too_few_2,      CC_ordpa,      wrong_no_2},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"lalr_action",             too_few_2,      CC_lalr_action,wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"cl_susiminlevel",         too_few_2,      CC_cl_susiminlevel,wrong_no_2},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"lessp:",                  too_few_2,      CC_lesspT,     wrong_no_2},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"lalr_first",              CC_lalr_first,  too_many_1,    wrong_no_1},
    {"anform1",                 CC_anform1,     too_many_1,    wrong_no_1},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"ofsf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwmkatl},
    {"wulessp*",                too_few_2,      CC_wulesspH,   wrong_no_2},
    {"poly-abs",                CC_polyKabs,    too_many_1,    wrong_no_1},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"pasf_deci",               CC_pasf_deci,   too_many_1,    wrong_no_1},
    {"objectom",                CC_objectom,    too_many_1,    wrong_no_1},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"rread",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"gintequiv:",              CC_gintequivT,  too_many_1,    wrong_no_1},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"powers1",                 CC_powers1,     too_many_1,    wrong_no_1},
    {"preptayexp",              CC_preptayexp,  too_many_1,    wrong_no_1},
    {"ibalp_istotal",           CC_ibalp_istotal,too_many_1,   wrong_no_1},
    {"expression",              CC_expression,  too_many_1,    wrong_no_1},
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"general-modular-minus",   CC_generalKmodularKminus,too_many_1,wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"exptf",                   too_few_2,      CC_exptf,      wrong_no_2},
    {"outdefr",                 too_few_2,      CC_outdefr,    wrong_no_2},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"qqe_ofsf_prepat",         CC_qqe_ofsf_prepat,too_many_1, wrong_no_1},
    {"qsort",                   CC_qsort,       too_many_1,    wrong_no_1},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"zeropp",                  CC_zeropp,      too_many_1,    wrong_no_1},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {"opnum*",                  CC_opnumH,      too_many_1,    wrong_no_1},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"condterpri",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_condterpri},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {NULL, (one_args *)"u08", (two_args *)"22977 8353573 8113430", 0}
};

/* end of generated code */
