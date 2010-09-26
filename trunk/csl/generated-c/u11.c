
/* $destdir\u11.c        Machine generated C code */

/* Signature: 00000000 26-Sep-2010 */

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
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
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
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 
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
#define UNWIND_ERROR      0x100       
#define UNWIND_UNWIND     0x200       
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
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
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
#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20
#define verbos_flag (miscflags & GC_MSG_BITS)
 
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
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
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
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow");
#else
#define if_check_stack
#endif
extern int32_t software_ticks, countdown;
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol;
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
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
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
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method;
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
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
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
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
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
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
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
                              size_t n, char *dirn, FILE *old_file);
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
#define validate_string(a) 0
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
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
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
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
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
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
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
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
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
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
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
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
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
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
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


/* Code for matsm!*1 */

static Lisp_Object CC_matsmH1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm*1");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    stack[-8] = elt(env, 1); /* mat */
    stack[-7] = v28;
    v28 = stack[-7];
    if (v28 == nil) goto v30;
    v28 = stack[-7];
    v28 = qcar(v28);
    stack[-3] = v28;
    v28 = stack[-3];
    if (v28 == nil) goto v31;
    v28 = stack[-3];
    v28 = qcar(v28);
    fn = elt(env, 5); /* subs2!* */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v29 = v28;
    v28 = qvalue(elt(env, 3)); /* !*nosq */
    if (v28 == nil) goto v33;
    v28 = v29;
    fn = elt(env, 6); /* prepsqxx */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v34;

v34:
    v28 = ncons(v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    stack[-1] = v28;
    stack[-2] = v28;
    goto v35;

v35:
    v28 = stack[-3];
    v28 = qcdr(v28);
    stack[-3] = v28;
    v28 = stack[-3];
    if (v28 == nil) goto v36;
    stack[0] = stack[-1];
    v28 = stack[-3];
    v28 = qcar(v28);
    fn = elt(env, 5); /* subs2!* */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v29 = v28;
    v28 = qvalue(elt(env, 3)); /* !*nosq */
    if (v28 == nil) goto v37;
    v28 = v29;
    fn = elt(env, 6); /* prepsqxx */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v38;

v38:
    v28 = ncons(v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v28 = Lrplacd(nil, stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v35;

v37:
    v28 = v29;
    fn = elt(env, 7); /* mk!*sq */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v38;

v36:
    v28 = stack[-2];
    goto v39;

v39:
    v28 = ncons(v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    stack[-5] = v28;
    stack[-6] = v28;
    goto v40;

v40:
    v28 = stack[-7];
    v28 = qcdr(v28);
    stack[-7] = v28;
    v28 = stack[-7];
    if (v28 == nil) goto v41;
    stack[-4] = stack[-5];
    v28 = stack[-7];
    v28 = qcar(v28);
    stack[-3] = v28;
    v28 = stack[-3];
    if (v28 == nil) goto v42;
    v28 = stack[-3];
    v28 = qcar(v28);
    fn = elt(env, 5); /* subs2!* */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v29 = v28;
    v28 = qvalue(elt(env, 3)); /* !*nosq */
    if (v28 == nil) goto v43;
    v28 = v29;
    fn = elt(env, 6); /* prepsqxx */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v44;

v44:
    v28 = ncons(v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    stack[-1] = v28;
    stack[-2] = v28;
    goto v45;

v45:
    v28 = stack[-3];
    v28 = qcdr(v28);
    stack[-3] = v28;
    v28 = stack[-3];
    if (v28 == nil) goto v46;
    stack[0] = stack[-1];
    v28 = stack[-3];
    v28 = qcar(v28);
    fn = elt(env, 5); /* subs2!* */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v29 = v28;
    v28 = qvalue(elt(env, 3)); /* !*nosq */
    if (v28 == nil) goto v47;
    v28 = v29;
    fn = elt(env, 6); /* prepsqxx */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v48;

v48:
    v28 = ncons(v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v28 = Lrplacd(nil, stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v45;

v47:
    v28 = v29;
    fn = elt(env, 7); /* mk!*sq */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v48;

v46:
    v28 = stack[-2];
    goto v49;

v49:
    v28 = ncons(v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v28 = Lrplacd(nil, stack[-4], v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v28 = stack[-5];
    v28 = qcdr(v28);
    stack[-5] = v28;
    goto v40;

v43:
    v28 = v29;
    fn = elt(env, 7); /* mk!*sq */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v44;

v42:
    v28 = qvalue(elt(env, 2)); /* nil */
    goto v49;

v41:
    v28 = stack[-6];
    goto v50;

v50:
    v28 = cons(stack[-8], v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    v29 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 4)) = v29; /* !*sub2 */
    { popv(10); return onevalue(v28); }

v33:
    v28 = v29;
    fn = elt(env, 7); /* mk!*sq */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-9];
    goto v34;

v31:
    v28 = qvalue(elt(env, 2)); /* nil */
    goto v39;

v30:
    v28 = qvalue(elt(env, 2)); /* nil */
    goto v50;
/* error exit handlers */
v32:
    popv(10);
    return nil;
}



/* Code for setdmode1 */

static Lisp_Object CC_setdmode1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94, v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdmode1");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v94 = v51;
    stack[-5] = v0;
/* end of prologue */
    v95 = stack[-5];
    v93 = elt(env, 1); /* tag */
    v93 = get(v95, v93);
    env = stack[-7];
    stack[-6] = v93;
    v93 = qvalue(elt(env, 2)); /* dmode!* */
    stack[-4] = v93;
    v93 = v94;
    if (v93 == nil) goto v97;
    v94 = stack[-5];
    v93 = elt(env, 13); /* (rounded complex!-rounded) */
    v93 = Lmemq(nil, v94, v93);
    if (v93 == nil) goto v4;
    fn = elt(env, 21); /* !!mfefix */
    v93 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    goto v4;

v4:
    v94 = stack[-6];
    v93 = stack[-4];
    if (v94 == v93) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v94 = stack[-6];
    v93 = elt(env, 14); /* realtype */
    v93 = get(v94, v93);
    env = stack[-7];
    stack[-3] = v93;
    if (!(v93 == nil)) goto v45;
    v93 = stack[-6];
    stack[-3] = v93;
    goto v45;

v45:
    v93 = qvalue(elt(env, 15)); /* domainlist!* */
    stack[-2] = v93;
    goto v13;

v13:
    v93 = stack[-2];
    if (v93 == nil) goto v99;
    v93 = stack[-2];
    v93 = qcar(v93);
    stack[-1] = v93;
    v94 = stack[-1];
    v93 = elt(env, 16); /* !:gi!: */
    if (v94 == v93) goto v100;
    v94 = stack[-1];
    v93 = stack[-3];
    if (v94 == v93) goto v100;
    v93 = elt(env, 17); /* !* */
    stack[0] = Lexplode(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v94 = stack[-1];
    v93 = elt(env, 4); /* dname */
    v93 = get(v94, v93);
    env = stack[-7];
    v93 = Lexplode(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v93 = Lappend(nil, stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v93 = Lcompress(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v94 = Lintern(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v93 = qvalue(elt(env, 3)); /* nil */
    v93 = Lset(nil, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    goto v100;

v100:
    v93 = stack[-2];
    v93 = qcdr(v93);
    stack[-2] = v93;
    goto v13;

v99:
    v94 = qvalue(elt(env, 5)); /* !*sqvar!* */
    v93 = qvalue(elt(env, 3)); /* nil */
    v93 = Lrplaca(nil, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v93 = qvalue(elt(env, 6)); /* t */
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    qvalue(elt(env, 5)) = v93; /* !*sqvar!* */
    v93 = qvalue(elt(env, 3)); /* nil */
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    qvalue(elt(env, 7)) = v93; /* alglist!* */
    v94 = stack[-4];
    v93 = elt(env, 4); /* dname */
    v93 = get(v94, v93);
    env = stack[-7];
    stack[-4] = v93;
    v93 = stack[-4];
    if (v93 == nil) goto v101;
    v93 = qvalue(elt(env, 18)); /* !*msg */
    if (v93 == nil) goto v101;
    stack[0] = elt(env, 9); /* "***" */
    v96 = elt(env, 19); /* "Domain mode" */
    v95 = stack[-4];
    v94 = elt(env, 20); /* "changed to" */
    v93 = stack[-5];
    v93 = list4(v96, v95, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    fn = elt(env, 22); /* lpriw */
    v93 = (*qfn2(fn))(qenv(fn), stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    goto v101;

v101:
    v93 = stack[-6];
    qvalue(elt(env, 2)) = v93; /* dmode!* */
    qvalue(elt(env, 8)) = v93; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v97:
    v93 = stack[-4];
    if (v93 == nil) goto v102;
    v95 = stack[-5];
    v94 = stack[-4];
    v93 = elt(env, 4); /* dname */
    v93 = get(v94, v93);
    env = stack[-7];
    stack[-4] = v93;
    if (v95 == v93) goto v27;
    stack[-2] = elt(env, 9); /* "***" */
    stack[-1] = elt(env, 10); /* "Failed attempt to turn off" */
    stack[-3] = stack[-5];
    stack[0] = elt(env, 11); /* "when" */
    v94 = stack[-4];
    v93 = elt(env, 12); /* "is on" */
    v93 = list2(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v93 = list3star(stack[-1], stack[-3], stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    {
        Lisp_Object v103 = stack[-2];
        popv(8);
        fn = elt(env, 22); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v103, v93);
    }

v27:
    v94 = qvalue(elt(env, 5)); /* !*sqvar!* */
    v93 = qvalue(elt(env, 3)); /* nil */
    v93 = Lrplaca(nil, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    v93 = qvalue(elt(env, 6)); /* t */
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    qvalue(elt(env, 5)) = v93; /* !*sqvar!* */
    v93 = qvalue(elt(env, 3)); /* nil */
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-7];
    qvalue(elt(env, 7)) = v93; /* alglist!* */
    v93 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v93; /* dmode!* */
    qvalue(elt(env, 8)) = v93; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v102:
    v93 = qvalue(elt(env, 3)); /* nil */
    { popv(8); return onevalue(v93); }
/* error exit handlers */
v98:
    popv(8);
    return nil;
}



/* Code for map__edges */

static Lisp_Object CC_map__edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for map__edges");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v110;

v110:
    v91 = stack[0];
    if (v91 == nil) goto v111;
    v91 = stack[0];
    v109 = qcar(v91);
    v91 = stack[-1];
    v91 = cons(v109, v91);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    stack[-1] = v91;
    v91 = stack[0];
    v91 = qcdr(v91);
    stack[0] = v91;
    goto v110;

v111:
    v91 = qvalue(elt(env, 1)); /* nil */
    v109 = v91;
    goto v50;

v50:
    v91 = stack[-1];
    if (v91 == nil) { popv(3); return onevalue(v109); }
    v91 = stack[-1];
    v91 = qcar(v91);
    fn = elt(env, 2); /* union_edges */
    v91 = (*qfn2(fn))(qenv(fn), v91, v109);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v109 = v91;
    v91 = stack[-1];
    v91 = qcdr(v91);
    stack[-1] = v91;
    goto v50;
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for command */

static Lisp_Object MS_CDECL CC_command(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152, v153, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-2] = qvalue(elt(env, 2)); /* loopdelimslist!* */
    qvalue(elt(env, 2)) = nil; /* loopdelimslist!* */
    v151 = qvalue(elt(env, 3)); /* !*demo */
    if (v151 == nil) goto v2;
    v151 = qvalue(elt(env, 4)); /* ifl!* */
    if (v151 == nil) goto v2;
    fn = elt(env, 33); /* commdemo */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v111;

v111:
    qvalue(elt(env, 2)) = stack[-2]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-3]; /* errmsg!* */
    { popv(5); return onevalue(v151); }

v2:
    v151 = qvalue(elt(env, 5)); /* !*slin */
    if (v151 == nil) goto v50;
    v151 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (!(v151 == nil)) goto v50;
    v151 = qvalue(elt(env, 4)); /* ifl!* */
    if (v151 == nil) goto v23;
    v151 = qvalue(elt(env, 4)); /* ifl!* */
    v153 = qcar(v151);
    v152 = (Lisp_Object)17; /* 1 */
    v151 = qvalue(elt(env, 8)); /* curline!* */
    v151 = list2star(v153, v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v156;

v156:
    qvalue(elt(env, 9)) = v151; /* cloc!* */
    v151 = qvalue(elt(env, 10)); /* lreadfn!* */
    if (v151 == nil) goto v84;
    v151 = qvalue(elt(env, 10)); /* lreadfn!* */
    v152 = v151;
    if (!consp(v152)) goto v21;
    v152 = elt(env, 11); /* "Apply called with non-id arg" */
    v151 = list2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v152 = v151;
    v151 = v152;
    qvalue(elt(env, 1)) = v151; /* errmsg!* */
    v151 = qvalue(elt(env, 12)); /* !*protfg */
    if (!(v151 == nil)) goto v157;
    v151 = v152;
    fn = elt(env, 34); /* lprie */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v157;

v157:
    v151 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = nil;
    goto v27;

v27:
    stack[-1] = v151;
    goto v158;

v158:
    v151 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v151 == nil) goto v14;
    v151 = qvalue(elt(env, 29)); /* !*debug */
    if (v151 == nil) goto v159;
    v151 = elt(env, 30); /* "Parse: " */
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[0] = stack[-1];
    v151 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    fn = elt(env, 35); /* superprinm */
    v151 = (*qfn2(fn))(qenv(fn), stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v159;

v159:
    v152 = qvalue(elt(env, 16)); /* key!* */
    v151 = elt(env, 31); /* !*semicol!* */
    if (v152 == v151) goto v50;
    v151 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v151 == nil) goto v160;
    v151 = stack[-1];
    fn = elt(env, 36); /* n_form */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-1] = v151;
    goto v161;

v161:
    v151 = qvalue(elt(env, 29)); /* !*debug */
    if (v151 == nil) goto v162;
    v151 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = elt(env, 32); /* "Form: " */
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[0] = stack[-1];
    v151 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    fn = elt(env, 35); /* superprinm */
    v151 = (*qfn2(fn))(qenv(fn), stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v162;

v162:
    v151 = stack[-1];
    goto v111;

v160:
    v151 = stack[-1];
    fn = elt(env, 37); /* form */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-1] = v151;
    goto v161;

v50:
    fn = elt(env, 38); /* readch1 */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    qvalue(elt(env, 13)) = v151; /* crchar!* */
    v152 = qvalue(elt(env, 13)); /* crchar!* */
    v151 = qvalue(elt(env, 14)); /* !$eol!$ */
    if (equal(v152, v151)) goto v50;
    fn = elt(env, 39); /* scan */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = qvalue(elt(env, 4)); /* ifl!* */
    if (v151 == nil) goto v3;
    v151 = qvalue(elt(env, 4)); /* ifl!* */
    v153 = qcar(v151);
    v152 = (Lisp_Object)17; /* 1 */
    v151 = qvalue(elt(env, 8)); /* curline!* */
    v151 = list2star(v153, v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v163;

v163:
    qvalue(elt(env, 9)) = v151; /* cloc!* */
    v151 = qvalue(elt(env, 15)); /* cursym!* */
    qvalue(elt(env, 16)) = v151; /* key!* */
    v151 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 40); /* xread1 */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-1] = v151;
    goto v158;

v3:
    v151 = qvalue(elt(env, 7)); /* nil */
    goto v163;

v14:
    v151 = qvalue(elt(env, 17)); /* !*struct */
    if (v151 == nil) goto v76;
    v151 = stack[-1];
    fn = elt(env, 41); /* structchk */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-1] = v151;
    goto v76;

v76:
    v151 = qvalue(elt(env, 18)); /* !*pret */
    if (v151 == nil) goto v164;
    v151 = stack[-1];
    if (!consp(v151)) goto v165;
    v151 = stack[-1];
    v152 = qcar(v151);
    v151 = elt(env, 19); /* (in out shut) */
    v151 = Lmemq(nil, v152, v151);
    if (!(v151 == nil)) goto v164;

v165:
    v151 = stack[-1];
    if (!(v151 == nil)) goto v166;
    v152 = qvalue(elt(env, 15)); /* cursym!* */
    v151 = elt(env, 20); /* end */
    if (!(v152 == v151)) goto v166;
    v151 = elt(env, 20); /* end */
    fn = elt(env, 42); /* rprint */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v164;

v164:
    v151 = qvalue(elt(env, 5)); /* !*slin */
    if (v151 == nil) goto v67;
    v152 = elt(env, 21); /* symbolic */
    v151 = stack[-1];
    v151 = list2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v111;

v67:
    v151 = stack[-1];
    fn = elt(env, 37); /* form */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v152 = v151;
    v153 = qvalue(elt(env, 16)); /* key!* */
    v151 = elt(env, 22); /* modefn */
    v151 = Lflagp(nil, v153, v151);
    env = stack[-4];
    if (v151 == nil) goto v167;
    v151 = qvalue(elt(env, 16)); /* key!* */
    goto v168;

v168:
    stack[0] = v151;
    v154 = v152;
    v153 = qvalue(elt(env, 7)); /* nil */
    v152 = elt(env, 21); /* symbolic */
    fn = elt(env, 43); /* convertmode1 */
    v151 = (*qfnn(fn))(qenv(fn), 4, v154, v153, v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = list2(stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v111;

v167:
    v151 = v152;
    if (!consp(v151)) goto v169;
    v151 = v152;
    v153 = qcar(v151);
    v151 = elt(env, 23); /* quote */
    if (v153 == v151) goto v169;
    v151 = v152;
    v151 = qcar(v151);
    if (!(symbolp(v151))) goto v170;
    v151 = v152;
    v153 = qcar(v151);
    v151 = elt(env, 24); /* nochange */
    v151 = Lflagp(nil, v153, v151);
    env = stack[-4];
    if (!(v151 == nil)) goto v171;
    v151 = v152;
    v153 = qcar(v151);
    v151 = elt(env, 25); /* intfn */
    v151 = Lflagp(nil, v153, v151);
    env = stack[-4];
    if (!(v151 == nil)) goto v171;
    v151 = v152;
    v153 = qcar(v151);
    v151 = elt(env, 26); /* list */
    if (!(v153 == v151)) goto v170;

v171:
    v151 = v152;
    v153 = qcar(v151);
    v151 = elt(env, 27); /* (setq setel setf) */
    v151 = Lmemq(nil, v153, v151);
    if (v151 == nil) goto v169;
    v151 = v152;
    v151 = qcdr(v151);
    v151 = qcdr(v151);
    v153 = qcar(v151);
    v151 = elt(env, 23); /* quote */
    if (!consp(v153)) goto v169;
    v153 = qcar(v153);
    if (!(v153 == v151)) goto v169;

v170:
    v151 = elt(env, 21); /* symbolic */
    goto v168;

v169:
    v151 = qvalue(elt(env, 28)); /* !*mode */
    goto v168;

v166:
    v151 = stack[-1];
    fn = elt(env, 42); /* rprint */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v164;

v21:
    v152 = v151;
    v151 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 44); /* apply */
    v151 = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v27;

v84:
    v151 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v27;

v23:
    v151 = qvalue(elt(env, 7)); /* nil */
    goto v156;
/* error exit handlers */
v155:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-2]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-3]; /* errmsg!* */
    popv(5);
    return nil;
}



/* Code for simpminus */

static Lisp_Object CC_simpminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpminus");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v143 = v0;
/* end of prologue */
    v150 = v143;
    v150 = qcdr(v150);
    if (v150 == nil) goto v73;
    v143 = elt(env, 1); /* "Wrong number of arguments to" */
    v150 = elt(env, 2); /* minus */
    v150 = list2(v143, v150);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v143 = v150;
    v150 = v143;
    qvalue(elt(env, 3)) = v150; /* errmsg!* */
    v150 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v150 == nil)) goto v149;
    v150 = v143;
    fn = elt(env, 5); /* lprie */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    goto v149;

v149:
    v150 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v150 = nil;
    goto v52;

v52:
    fn = elt(env, 6); /* simp */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    stack[0] = v150;
    v150 = stack[0];
    v150 = qcar(v150);
    fn = elt(env, 7); /* negf */
    v143 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v26;
    v150 = stack[0];
    v150 = qcdr(v150);
    popv(2);
    return cons(v143, v150);

v73:
    v150 = v143;
    v150 = qcar(v150);
    goto v52;
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for red!-ratios1 */

static Lisp_Object CC_redKratios1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91, v109, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios1");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v0;
/* end of prologue */

v175:
    v90 = stack[-1];
    if (v90 == nil) goto v73;
    v90 = stack[-1];
    v150 = qcdr(v90);
    v90 = stack[0];
    v109 = qcdr(v90);
    v90 = stack[-1];
    v91 = qcar(v90);
    v90 = stack[0];
    v90 = qcar(v90);
    fn = elt(env, 2); /* red!-ratios2 */
    v90 = (*qfnn(fn))(qenv(fn), 4, v150, v109, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    if (!(v90 == nil)) { popv(3); return onevalue(v90); }
    v90 = stack[-1];
    v91 = qcdr(v90);
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[-1] = v91;
    stack[0] = v90;
    goto v175;

v73:
    v90 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v90); }
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for mtchk */

static Lisp_Object CC_mtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133, v188, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtchk");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v51;
    stack[-8] = v0;
/* end of prologue */
    stack[-3] = nil;
    v132 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v132 == nil) goto v97;
    v132 = stack[-8];
    v132 = qcar(v132);
    fn = elt(env, 3); /* noncomp1 */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    goto v189;

v189:
    stack[-9] = v132;
    goto v15;

v15:
    v132 = stack[-7];
    if (v132 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v132 = stack[-7];
    v132 = qcar(v132);
    stack[-6] = v132;
    v132 = stack[-6];
    v132 = qcar(v132);
    stack[-5] = v132;
    goto v17;

v17:
    v132 = stack[-5];
    if (v132 == nil) goto v32;
    v170 = stack[-8];
    v132 = stack[-5];
    v188 = qcar(v132);
    v132 = stack[-6];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v133 = qcar(v132);
    v132 = stack[-6];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v132 = qcdr(v132);
    fn = elt(env, 4); /* mtchp1 */
    v132 = (*qfnn(fn))(qenv(fn), 4, v170, v188, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    stack[-4] = v132;
    goto v16;

v16:
    v132 = stack[-4];
    if (v132 == nil) goto v2;
    v132 = stack[-4];
    stack[0] = qcar(v132);
    v132 = stack[-5];
    v133 = qcar(v132);
    v132 = stack[-6];
    v132 = qcar(v132);
    v132 = Ldelete(nil, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    stack[-2] = Lsubla(nil, stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    v132 = stack[-4];
    v133 = qcar(v132);
    v132 = stack[-6];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    stack[-1] = Lsubla(nil, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    v132 = stack[-4];
    v133 = qcar(v132);
    v132 = stack[-6];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v132 = qcar(v132);
    stack[0] = Lsubla(nil, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    v132 = stack[-4];
    v133 = qcar(v132);
    v132 = stack[-5];
    v132 = qcar(v132);
    v133 = Lsubla(nil, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    v132 = stack[-6];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v132 = cons(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    v132 = list2(stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    v132 = list2star(stack[-2], stack[-1], v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    stack[0] = v132;
    v132 = qcar(v132);
    if (v132 == nil) goto v190;
    v133 = stack[0];
    v132 = stack[-3];
    v132 = cons(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    stack[-3] = v132;
    goto v148;

v148:
    v132 = stack[-4];
    v132 = qcdr(v132);
    stack[-4] = v132;
    goto v16;

v190:
    v132 = stack[-4];
    v133 = qcar(v132);
    v132 = stack[-6];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v132 = qcdr(v132);
    v132 = Lsubla(nil, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    fn = elt(env, 5); /* eval */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    if (v132 == nil) goto v148;
    v132 = stack[0];
    popv(11);
    return ncons(v132);

v2:
    v132 = stack[-9];
    if (v132 == nil) goto v191;
    v132 = stack[-6];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v132 = qcar(v132);
    if (v132 == nil) goto v32;
    v132 = stack[-5];
    fn = elt(env, 6); /* nocp */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    if (!(v132 == nil)) goto v40;

v32:
    stack[0] = stack[-3];
    v132 = stack[-6];
    v132 = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    v132 = Lnconc(nil, stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-10];
    stack[-3] = v132;
    goto v40;

v40:
    v132 = stack[-7];
    v132 = qcdr(v132);
    stack[-7] = v132;
    goto v15;

v191:
    v132 = stack[-5];
    v132 = qcdr(v132);
    stack[-5] = v132;
    goto v17;

v97:
    v132 = qvalue(elt(env, 2)); /* nil */
    goto v189;
/* error exit handlers */
v130:
    popv(11);
    return nil;
}



/* Code for th_match0 */

static Lisp_Object CC_th_match0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v192, v88;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match0");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    v88 = v0;
/* end of prologue */
    v35 = v88;
    v192 = qcar(v35);
    v35 = stack[0];
    v35 = qcar(v35);
    if (equal(v192, v35)) goto v97;
    v35 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v35); }

v97:
    v35 = v88;
    v35 = qcdr(v35);
    v35 = qcar(v35);
    stack[-1] = Llength(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = Llength(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v193;
    v35 = (equal(stack[-1], v35) ? lisp_true : nil);
    { popv(3); return onevalue(v35); }
/* error exit handlers */
v193:
    popv(3);
    return nil;
}



/* Code for b!:ordexn */

static Lisp_Object CC_bTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v201;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:ordexn");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v51;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    goto v111;

v111:
    v200 = stack[-1];
    if (v200 == nil) goto v108;
    v201 = stack[-2];
    v200 = stack[-1];
    v200 = qcar(v200);
    if (equal(v201, v200)) goto v25;
    v200 = stack[-2];
    if (v200 == nil) goto v22;
    v201 = stack[-2];
    v200 = stack[-1];
    v200 = qcar(v200);
    v200 = (Lisp_Object)greaterp2(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v200 = v200 ? lisp_true : nil;
    env = stack[-4];
    if (v200 == nil) goto v22;
    v201 = stack[-2];
    v200 = stack[-3];
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    v201 = Lreverse(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    v200 = stack[-1];
    v200 = Lappend(nil, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v41;
    {
        Lisp_Object v202 = stack[0];
        popv(5);
        return cons(v202, v200);
    }

v22:
    v200 = stack[-1];
    v201 = qcar(v200);
    v200 = stack[-3];
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    stack[-3] = v200;
    v200 = stack[-1];
    v200 = qcdr(v200);
    stack[-1] = v200;
    v200 = stack[0];
    v200 = (v200 == nil ? lisp_true : nil);
    stack[0] = v200;
    goto v111;

v25:
    v200 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v200); }

v108:
    v201 = stack[-2];
    v200 = stack[-3];
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    v200 = Lreverse(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v41;
    {
        Lisp_Object v203 = stack[0];
        popv(5);
        return cons(v203, v200);
    }
/* error exit handlers */
v41:
    popv(5);
    return nil;
}



/* Code for tr_write */

static Lisp_Object CC_tr_write(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tr_write");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v156 = v0;
/* end of prologue */
    v149 = qvalue(elt(env, 1)); /* !*trsolve */
    if (v149 == nil) goto v73;
    v149 = v156;
    stack[0] = v149;
    goto v1;

v1:
    v149 = stack[0];
    if (v149 == nil) goto v158;
    v149 = stack[0];
    v149 = qcar(v149);
    v149 = Lprinc(nil, v149);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v149 = stack[0];
    v149 = qcdr(v149);
    stack[0] = v149;
    goto v1;

v158:
        popv(2);
        return Lterpri(nil, 0);

v73:
    v149 = nil;
    { popv(2); return onevalue(v149); }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for cl_varl2 */

static Lisp_Object MS_CDECL CC_cl_varl2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v51,
                         Lisp_Object v106, Lisp_Object v53, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v230, v231, v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_varl2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_varl2");
#endif
    if (stack >= stacklimit)
    {
        push4(v53,v106,v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v51,v106,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v53;
    stack[0] = v106;
    stack[-3] = v51;
    stack[-4] = v0;
/* end of prologue */

v175:
    v229 = stack[-4];
    if (!consp(v229)) goto v15;
    v229 = stack[-4];
    v229 = qcar(v229);
    goto v1;

v1:
    v231 = v229;
    v230 = v231;
    v229 = elt(env, 1); /* true */
    if (v230 == v229) goto v105;
    v230 = v231;
    v229 = elt(env, 2); /* false */
    if (v230 == v229) goto v105;
    v230 = v231;
    v229 = elt(env, 3); /* or */
    if (v230 == v229) goto v34;
    v230 = v231;
    v229 = elt(env, 4); /* and */
    if (v230 == v229) goto v34;
    v230 = v231;
    v229 = elt(env, 5); /* not */
    if (v230 == v229) goto v34;
    v230 = v231;
    v229 = elt(env, 6); /* impl */
    if (v230 == v229) goto v34;
    v230 = v231;
    v229 = elt(env, 7); /* repl */
    if (v230 == v229) goto v34;
    v230 = v231;
    v229 = elt(env, 8); /* equiv */
    if (v230 == v229) goto v34;
    v230 = v231;
    v229 = elt(env, 10); /* ex */
    if (v230 == v229) goto v48;
    v230 = v231;
    v229 = elt(env, 11); /* all */
    if (v230 == v229) goto v48;
    v230 = v231;
    v229 = elt(env, 12); /* bex */
    if (v230 == v229) goto v233;
    v230 = v231;
    v229 = elt(env, 13); /* ball */
    if (v230 == v229) goto v233;
    v229 = stack[-4];
    fn = elt(env, 14); /* rl_varlat */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    stack[-1] = v229;
    goto v235;

v235:
    v229 = stack[-1];
    if (v229 == nil) goto v236;
    v229 = stack[-1];
    v229 = qcar(v229);
    v231 = v229;
    v230 = v231;
    v229 = stack[0];
    v229 = Lmemq(nil, v230, v229);
    if (!(v229 == nil)) goto v237;
    v230 = v231;
    v229 = stack[-3];
    fn = elt(env, 15); /* lto_insertq */
    v229 = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    stack[-3] = v229;
    goto v237;

v237:
    v229 = stack[-1];
    v229 = qcdr(v229);
    stack[-1] = v229;
    goto v235;

v236:
    v230 = stack[-3];
    v229 = stack[-2];
    popv(6);
    return cons(v230, v229);

v233:
    v229 = stack[-4];
    v229 = qcdr(v229);
    stack[-1] = qcar(v229);
    v229 = stack[-4];
    v229 = qcdr(v229);
    v229 = qcdr(v229);
    v229 = qcdr(v229);
    v232 = qcar(v229);
    v231 = stack[-3];
    v230 = qvalue(elt(env, 9)); /* nil */
    v229 = qvalue(elt(env, 9)); /* nil */
    v229 = CC_cl_varl2(env, 4, v232, v231, v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    v229 = qcar(v229);
    fn = elt(env, 16); /* delq */
    v229 = (*qfn2(fn))(qenv(fn), stack[-1], v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    stack[-1] = v229;
    v229 = stack[-4];
    v229 = qcdr(v229);
    v229 = qcdr(v229);
    stack[-3] = qcar(v229);
    v229 = stack[-4];
    v229 = qcdr(v229);
    v230 = qcar(v229);
    v229 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    v229 = stack[-4];
    v229 = qcdr(v229);
    v230 = qcar(v229);
    v229 = stack[-2];
    v229 = cons(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    v229 = CC_cl_varl2(env, 4, stack[-3], stack[-1], stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    stack[-1] = v229;
    v229 = stack[-4];
    v229 = qcdr(v229);
    v230 = qcar(v229);
    v229 = stack[-1];
    v229 = qcar(v229);
    fn = elt(env, 16); /* delq */
    v230 = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    v229 = stack[-1];
    v229 = qcdr(v229);
    popv(6);
    return cons(v230, v229);

v48:
    v229 = stack[-4];
    v229 = qcdr(v229);
    v229 = qcdr(v229);
    stack[-1] = qcar(v229);
    v229 = stack[-4];
    v229 = qcdr(v229);
    v230 = qcar(v229);
    v229 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    v229 = stack[-4];
    v229 = qcdr(v229);
    v230 = qcar(v229);
    v229 = stack[-2];
    v229 = cons(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    stack[-4] = stack[-1];
    stack[-2] = v229;
    goto v175;

v34:
    v229 = stack[-4];
    v229 = qcdr(v229);
    stack[-1] = v229;
    goto v238;

v238:
    v229 = stack[-1];
    if (v229 == nil) goto v180;
    v229 = stack[-1];
    v229 = qcar(v229);
    v232 = v229;
    v231 = stack[-3];
    v230 = stack[0];
    v229 = stack[-2];
    v229 = CC_cl_varl2(env, 4, v232, v231, v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-5];
    v230 = v229;
    v229 = v230;
    v229 = qcar(v229);
    stack[-3] = v229;
    v229 = v230;
    v229 = qcdr(v229);
    stack[-2] = v229;
    v229 = stack[-1];
    v229 = qcdr(v229);
    stack[-1] = v229;
    goto v238;

v180:
    v230 = stack[-3];
    v229 = stack[-2];
    popv(6);
    return cons(v230, v229);

v105:
    v230 = stack[-3];
    v229 = stack[-2];
    popv(6);
    return cons(v230, v229);

v15:
    v229 = stack[-4];
    goto v1;
/* error exit handlers */
v234:
    popv(6);
    return nil;
}



/* Code for integerom */

static Lisp_Object CC_integerom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integerom");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v1 = elt(env, 1); /* "<OMI> " */
    fn = elt(env, 3); /* printout */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v1 = stack[0];
    v1 = Lprinc(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v1 = elt(env, 2); /* " </OMI>" */
    v1 = Lprinc(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v17;
    v1 = nil;
    { popv(2); return onevalue(v1); }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for findnewvars */

static Lisp_Object CC_findnewvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findnewvars");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v239 = stack[0];
    if (!consp(v239)) goto v52;
    v239 = stack[0];
    stack[-3] = v239;
    goto v173;

v173:
    v239 = stack[-3];
    if (v239 == nil) goto v24;
    v239 = stack[-3];
    v239 = qcar(v239);
    v239 = CC_findnewvars(env, v239);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[-2] = v239;
    v239 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[-1] = v239;
    v239 = stack[-3];
    v239 = qcdr(v239);
    stack[-3] = v239;
    v239 = stack[-1];
    if (!consp(v239)) goto v173;
    else goto v149;

v149:
    v239 = stack[-3];
    if (v239 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v239 = stack[-3];
    v239 = qcar(v239);
    v239 = CC_findnewvars(env, v239);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v239 = Lrplacd(nil, stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v239 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[-1] = v239;
    v239 = stack[-3];
    v239 = qcdr(v239);
    stack[-3] = v239;
    goto v149;

v24:
    v239 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v239); }

v52:
    v239 = stack[0];
    fn = elt(env, 3); /* genp */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    if (v239 == nil) goto v92;
    v239 = stack[0];
    popv(5);
    return ncons(v239);

v92:
    v239 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v239); }
/* error exit handlers */
v198:
    popv(5);
    return nil;
}



/* Code for vevlcm */

static Lisp_Object CC_vevlcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v197, v242;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevlcm");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v0;
/* end of prologue */
    v242 = nil;
    goto v50;

v50:
    v198 = stack[-1];
    if (v198 == nil) goto v111;
    v198 = stack[0];
    if (v198 == nil) goto v111;
    v198 = stack[-1];
    v197 = qcar(v198);
    v198 = stack[0];
    v198 = qcar(v198);
    if (((int32_t)(v197)) > ((int32_t)(v198))) goto v149;
    v198 = stack[0];
    v198 = qcar(v198);
    goto v107;

v107:
    v197 = v242;
    v198 = cons(v198, v197);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v242 = v198;
    v198 = stack[-1];
    v198 = qcdr(v198);
    stack[-1] = v198;
    v198 = stack[0];
    v198 = qcdr(v198);
    stack[0] = v198;
    goto v50;

v149:
    v198 = stack[-1];
    v198 = qcar(v198);
    goto v107;

v111:
    v198 = v242;
    v198 = Lnreverse(nil, v198);
    env = stack[-2];
    v242 = v198;
    v198 = stack[-1];
    if (v198 == nil) goto v87;
    v197 = v242;
    v198 = stack[-1];
    v198 = Lnconc(nil, v197, v198);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v242 = v198;
    { popv(3); return onevalue(v242); }

v87:
    v198 = stack[0];
    if (v198 == nil) { popv(3); return onevalue(v242); }
    v197 = v242;
    v198 = stack[0];
    v198 = Lnconc(nil, v197, v198);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v242 = v198;
    { popv(3); return onevalue(v242); }
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for listeval */

static Lisp_Object CC_listeval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v51;
    stack[0] = v0;
/* end of prologue */
    v62 = qvalue(elt(env, 1)); /* simpcount!* */
    v63 = add1(v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    qvalue(elt(env, 1)) = v63; /* simpcount!* */
    v62 = qvalue(elt(env, 2)); /* simplimit!* */
    v62 = (Lisp_Object)greaterp2(v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v62 = v62 ? lisp_true : nil;
    env = stack[-6];
    if (v62 == nil) goto v52;
    v62 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v62; /* simpcount!* */
    v62 = elt(env, 3); /* "Simplification recursion too deep" */
    v63 = v62;
    v62 = v63;
    qvalue(elt(env, 4)) = v62; /* errmsg!* */
    v62 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v62 == nil)) goto v172;
    v62 = v63;
    fn = elt(env, 12); /* lprie */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    goto v172;

v172:
    v62 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    goto v52;

v52:
    v62 = stack[0];
    if (!consp(v62)) goto v89;
    v62 = stack[0];
    v63 = qcar(v62);
    v62 = elt(env, 8); /* list */
    if (v63 == v62) goto v200;
    v62 = stack[0];
    v63 = qcar(v62);
    v62 = elt(env, 10); /* listfn */
    v62 = get(v63, v62);
    env = stack[-6];
    v63 = v62;
    v62 = v63;
    if (v62 == nil) goto v252;
    v250 = v63;
    v62 = stack[0];
    v63 = qcdr(v62);
    v62 = stack[-4];
    v62 = Lapply2(nil, 3, v250, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    goto v18;

v18:
    stack[0] = v62;
    v62 = qvalue(elt(env, 1)); /* simpcount!* */
    v62 = sub1(v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    qvalue(elt(env, 1)) = v62; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v252:
    v62 = elt(env, 11); /* "Illegal operation on lists" */
    v63 = v62;
    v62 = v63;
    qvalue(elt(env, 4)) = v62; /* errmsg!* */
    v62 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v62 == nil)) goto v134;
    v62 = v63;
    fn = elt(env, 12); /* lprie */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    goto v134;

v134:
    v62 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v62 = nil;
    goto v18;

v200:
    stack[-5] = elt(env, 8); /* list */
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[-3] = v62;
    v62 = stack[-3];
    if (v62 == nil) goto v3;
    v62 = stack[-3];
    v62 = qcar(v62);
    v63 = v62;
    v62 = stack[-4];
    fn = elt(env, 13); /* reval1 */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v62 = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    stack[-1] = v62;
    stack[-2] = v62;
    goto v138;

v138:
    v62 = stack[-3];
    v62 = qcdr(v62);
    stack[-3] = v62;
    v62 = stack[-3];
    if (v62 == nil) goto v78;
    stack[0] = stack[-1];
    v62 = stack[-3];
    v62 = qcar(v62);
    v63 = v62;
    v62 = stack[-4];
    fn = elt(env, 13); /* reval1 */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v62 = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v62 = Lrplacd(nil, stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v62 = stack[-1];
    v62 = qcdr(v62);
    stack[-1] = v62;
    goto v138;

v78:
    v62 = stack[-2];
    goto v253;

v253:
    v62 = cons(stack[-5], v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    goto v18;

v3:
    v62 = qvalue(elt(env, 9)); /* nil */
    goto v253;

v89:
    v63 = stack[0];
    v62 = elt(env, 6); /* avalue */
    v62 = get(v63, v62);
    env = stack[-6];
    v250 = v62;
    v63 = stack[0];
    v62 = elt(env, 7); /* share */
    v62 = Lflagp(nil, v63, v62);
    env = stack[-6];
    if (v62 == nil) goto v87;
    v62 = stack[0];
    fn = elt(env, 14); /* eval */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v63 = v62;
    goto v27;

v27:
    v62 = stack[-4];
    v62 = CC_listeval(env, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    goto v18;

v87:
    v62 = v250;
    if (v62 == nil) goto v19;
    v62 = v250;
    v62 = qcdr(v62);
    v62 = qcar(v62);
    v63 = v62;
    goto v27;

v19:
    v63 = stack[0];
    v62 = elt(env, 8); /* list */
    fn = elt(env, 15); /* typerr */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v63 = v62;
    goto v27;
/* error exit handlers */
v251:
    popv(7);
    return nil;
}



/* Code for cut!:mt */

static Lisp_Object CC_cutTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v238, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:mt");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v51;
    stack[-2] = v0;
/* end of prologue */
    v139 = stack[-2];
    v238 = elt(env, 1); /* !:rd!: */
    if (!consp(v139)) goto v255;
    v139 = qcar(v139);
    if (!(v139 == v238)) goto v255;
    v238 = stack[-2];
    v238 = qcdr(v238);
    if (!consp(v238)) goto v255;
    v238 = stack[-1];
    v238 = integerp(v238);
    if (v238 == nil) goto v255;
    v139 = stack[-1];
    v238 = (Lisp_Object)1; /* 0 */
    v238 = (Lisp_Object)greaterp2(v139, v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v238 = v238 ? lisp_true : nil;
    env = stack[-4];
    if (v238 == nil) goto v255;
    v238 = stack[-2];
    v238 = qcdr(v238);
    v238 = qcar(v238);
    v238 = Labsval(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    fn = elt(env, 3); /* msd */
    v139 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    v238 = stack[-1];
    v139 = difference2(v139, v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    stack[-1] = v139;
    v238 = (Lisp_Object)1; /* 0 */
    v238 = (Lisp_Object)lesseq2(v139, v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v238 = v238 ? lisp_true : nil;
    env = stack[-4];
    if (!(v238 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v238 = stack[-2];
    v238 = qcdr(v238);
    stack[0] = qcar(v238);
    v238 = stack[-1];
    v238 = negate(v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    v238 = stack[-2];
    v238 = qcdr(v238);
    v139 = qcdr(v238);
    v238 = stack[-1];
    v238 = plus2(v139, v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    {
        Lisp_Object v257 = stack[-3];
        Lisp_Object v10 = stack[0];
        popv(5);
        return list2star(v257, v10, v238);
    }

v255:
    stack[0] = (Lisp_Object)1; /* 0 */
    v139 = elt(env, 2); /* "Invalid argument to" */
    v238 = elt(env, 0); /* cut!:mt */
    v238 = list2(v139, v238);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    {
        Lisp_Object v12 = stack[0];
        popv(5);
        fn = elt(env, 4); /* error */
        return (*qfn2(fn))(qenv(fn), v12, v238);
    }
/* error exit handlers */
v256:
    popv(5);
    return nil;
}



/* Code for !*kp2f */

static Lisp_Object CC_Hkp2f(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *kp2f");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v0;
/* end of prologue */
    v23 = stack[0];
    v156 = (Lisp_Object)1; /* 0 */
    v156 = (Lisp_Object)greaterp2(v23, v156);
    nil = C_nil;
    if (exception_pending()) goto v18;
    v156 = v156 ? lisp_true : nil;
    env = stack[-2];
    if (v156 == nil) goto v102;
    v23 = stack[-1];
    v156 = stack[0];
    fn = elt(env, 1); /* mksq */
    v156 = (*qfn2(fn))(qenv(fn), v23, v156);
    nil = C_nil;
    if (exception_pending()) goto v18;
    v156 = qcar(v156);
    { popv(3); return onevalue(v156); }

v102:
    v156 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v156); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for statep!* */

static Lisp_Object CC_statepH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for statep*");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    fn = elt(env, 2); /* getphystype */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[0];
    v17 = elt(env, 1); /* state */
    v15 = (v15 == v17 ? lisp_true : nil);
    { popv(1); return onevalue(v15); }
/* error exit handlers */
v16:
    popv(1);
    return nil;
}



/* Code for mkinds */

static Lisp_Object CC_mkinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkinds");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v0;
/* end of prologue */
    v150 = stack[0];
    v109 = (Lisp_Object)1; /* 0 */
    if (v150 == v109) goto v73;
    v150 = stack[-1];
    v109 = stack[0];
    v109 = cons(v150, v109);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v109;
    v109 = stack[0];
    v109 = sub1(v109);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    v109 = CC_mkinds(env, stack[-1], v109);
    nil = C_nil;
    if (exception_pending()) goto v34;
    {
        Lisp_Object v33 = stack[-2];
        popv(4);
        return cons(v33, v109);
    }

v73:
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v109); }
/* error exit handlers */
v34:
    popv(4);
    return nil;
}



/* Code for sqp */

static Lisp_Object CC_sqp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqp");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v30 = stack[0];
    v30 = Lconsp(nil, v30);
    env = stack[-1];
    if (v30 == nil) goto v52;
    v30 = stack[0];
    v30 = qcar(v30);
    fn = elt(env, 2); /* sfpx */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    if (v30 == nil) goto v158;
    v30 = stack[0];
    v30 = qcdr(v30);
    {
        popv(2);
        fn = elt(env, 2); /* sfpx */
        return (*qfn1(fn))(qenv(fn), v30);
    }

v158:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v30); }

v52:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v30); }
/* error exit handlers */
v108:
    popv(2);
    return nil;
}



/* Code for make!-term */

static Lisp_Object MS_CDECL CC_makeKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v51,
                         Lisp_Object v106, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v265, v220, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-term");
#endif
    if (stack >= stacklimit)
    {
        push3(v106,v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v51,v106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v106;
    stack[-4] = v51;
    stack[-5] = v0;
/* end of prologue */
    v265 = (Lisp_Object)1; /* 0 */
    stack[-2] = v265;
    v265 = (Lisp_Object)1; /* 0 */
    stack[0] = v265;
    goto v108;

v108:
    v220 = stack[-4];
    v265 = stack[0];
    v220 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v265/(16/CELL)));
    v265 = (Lisp_Object)1; /* 0 */
    v265 = (Lisp_Object)lessp2(v220, v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    v265 = v265 ? lisp_true : nil;
    env = stack[-7];
    if (v265 == nil) goto v105;
    v265 = (Lisp_Object)-15; /* -1 */
    stack[-2] = v265;
    goto v16;

v16:
    v265 = (Lisp_Object)49; /* 3 */
    v265 = Lmkvect(nil, v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-7];
    stack[-6] = v265;
    v220 = stack[-2];
    v265 = (Lisp_Object)17; /* 1 */
    if (v220 == v265) goto v177;
    v220 = stack[-5];
    v265 = elt(env, 3); /* cos */
    if (v220 == v265) goto v177;
    stack[-1] = stack[-6];
    stack[0] = (Lisp_Object)1; /* 0 */
    v220 = elt(env, 4); /* (-1 . 1) */
    v265 = stack[-3];
    fn = elt(env, 5); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), v220, v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v265;
    goto v178;

v178:
    v60 = stack[-6];
    v220 = (Lisp_Object)17; /* 1 */
    v265 = stack[-5];
    *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v220/(16/CELL))) = v265;
    v220 = stack[-2];
    v265 = (Lisp_Object)-15; /* -1 */
    if (!(v220 == v265)) goto v65;
    v265 = (Lisp_Object)113; /* 7 */
    v265 = Lmkvect(nil, v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-7];
    stack[-2] = v265;
    v265 = (Lisp_Object)1; /* 0 */
    stack[-3] = v265;
    goto v190;

v190:
    v220 = (Lisp_Object)113; /* 7 */
    v265 = stack[-3];
    v265 = difference2(v220, v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-7];
    v265 = Lminusp(nil, v265);
    env = stack[-7];
    if (v265 == nil) goto v47;
    v265 = stack[-2];
    stack[-4] = v265;
    goto v65;

v65:
    v60 = stack[-6];
    v220 = (Lisp_Object)33; /* 2 */
    v265 = stack[-4];
    *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v220/(16/CELL))) = v265;
    v220 = stack[-6];
    v265 = (Lisp_Object)49; /* 3 */
    v60 = qvalue(elt(env, 2)); /* nil */
    *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v265/(16/CELL))) = v60;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v47:
    stack[-1] = stack[-2];
    stack[0] = stack[-3];
    v220 = stack[-4];
    v265 = stack[-3];
    v265 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v265/(16/CELL)));
    v265 = negate(v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v265;
    v265 = stack[-3];
    v265 = add1(v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-7];
    stack[-3] = v265;
    goto v190;

v177:
    v60 = stack[-6];
    v220 = (Lisp_Object)1; /* 0 */
    v265 = stack[-3];
    *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v220/(16/CELL))) = v265;
    goto v178;

v105:
    v220 = stack[-4];
    v265 = stack[0];
    v220 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v265/(16/CELL)));
    v265 = (Lisp_Object)1; /* 0 */
    v265 = (Lisp_Object)greaterp2(v220, v265);
    nil = C_nil;
    if (exception_pending()) goto v219;
    v265 = v265 ? lisp_true : nil;
    env = stack[-7];
    if (v265 == nil) goto v86;
    v265 = (Lisp_Object)17; /* 1 */
    stack[-2] = v265;
    goto v16;

v86:
    v220 = stack[0];
    v265 = (Lisp_Object)113; /* 7 */
    if (v220 == v265) goto v36;
    v265 = stack[0];
    v265 = (Lisp_Object)((int32_t)(v265) + 0x10);
    stack[0] = v265;
    goto v108;

v36:
    v220 = stack[-5];
    v265 = elt(env, 1); /* sin */
    if (!(v220 == v265)) goto v16;
    v265 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v265); }
/* error exit handlers */
v219:
    popv(8);
    return nil;
}



/* Code for sizchk */

static Lisp_Object CC_sizchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sizchk");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v110;

v110:
    v90 = stack[-1];
    if (v90 == nil) goto v158;
    v90 = stack[-1];
    v90 = qcar(v90);
    v90 = qcar(v90);
    v91 = Llength(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-3];
    v90 = stack[0];
    v90 = (Lisp_Object)greaterp2(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v90 = v90 ? lisp_true : nil;
    env = stack[-3];
    if (v90 == nil) goto v39;
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-1] = v90;
    goto v110;

v39:
    v90 = stack[-1];
    v91 = qcar(v90);
    v90 = stack[-2];
    v90 = cons(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-3];
    stack[-2] = v90;
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-1] = v90;
    goto v110;

v158:
    v90 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v90);
    }
/* error exit handlers */
v27:
    popv(4);
    return nil;
}



/* Code for dd */

static Lisp_Object CC_dd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v203, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dd");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-2] = v0;
/* end of prologue */
    v203 = stack[0];
    v202 = stack[-2];
    fn = elt(env, 5); /* dquot */
    v202 = (*qfn2(fn))(qenv(fn), v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v79 = v202;
    v202 = v79;
    if (v202 == nil) goto v173;
    v203 = qvalue(elt(env, 1)); /* ordering */
    v202 = elt(env, 2); /* lex */
    if (v203 == v202) goto v31;
    v202 = v79;
    v202 = qcdr(v202);
    v79 = v202;
    goto v31;

v31:
    v202 = v79;
    fn = elt(env, 6); /* leftzeros */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    stack[-3] = v202;
    v202 = qvalue(elt(env, 3)); /* nc */
    if (!(v202 == nil)) goto v254;
    stack[-1] = stack[-3];
    v202 = qvalue(elt(env, 4)); /* varlist */
    stack[0] = Llength(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v202 = stack[-2];
    fn = elt(env, 7); /* class */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v202 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v202 + TAG_FIXNUM);
    if (((int32_t)(stack[-1])) < ((int32_t)(v202))) goto v254;
    v202 = (Lisp_Object)49; /* 3 */
    { popv(5); return onevalue(v202); }

v254:
    v202 = qvalue(elt(env, 3)); /* nc */
    if (v202 == nil) goto v184;
    stack[0] = stack[-3];
    v202 = qvalue(elt(env, 4)); /* varlist */
    v202 = Llength(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v203 = qvalue(elt(env, 3)); /* nc */
    v202 = (Lisp_Object)(int32_t)((int32_t)v202 - (int32_t)v203 + TAG_FIXNUM);
    if (((int32_t)(stack[0])) < ((int32_t)(v202))) goto v184;
    v202 = (Lisp_Object)65; /* 4 */
    { popv(5); return onevalue(v202); }

v184:
    v202 = (Lisp_Object)33; /* 2 */
    { popv(5); return onevalue(v202); }

v173:
    v203 = stack[-2];
    v202 = stack[0];
    fn = elt(env, 8); /* dless */
    v202 = (*qfn2(fn))(qenv(fn), v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v139;
    if (v202 == nil) goto v35;
    v202 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v202); }

v35:
    v202 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v202); }
/* error exit handlers */
v139:
    popv(5);
    return nil;
}



/* Code for pv_neg */

static Lisp_Object CC_pv_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_neg");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v111;

v111:
    v88 = stack[0];
    if (v88 == nil) goto v110;
    v88 = stack[0];
    v88 = qcar(v88);
    v88 = qcar(v88);
    v31 = negate(v88);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v88 = stack[0];
    v88 = qcar(v88);
    v89 = qcdr(v88);
    v88 = stack[-1];
    v88 = acons(v31, v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    stack[-1] = v88;
    v88 = stack[0];
    v88 = qcdr(v88);
    stack[0] = v88;
    goto v111;

v110:
    v88 = stack[-1];
        popv(3);
        return Lnreverse(nil, v88);
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v174, v90;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v0;
/* end of prologue */
    v105 = v90;
    v105 = qcdr(v105);
    if (is_number(v105)) goto v52;
    v105 = v90;
    v105 = qcdr(v105);
    v174 = qcar(v105);
    v105 = elt(env, 1); /* !:rn!: */
    if (!(v174 == v105)) goto v31;
    v105 = v90;
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    v174 = qcdr(v105);
    v105 = (Lisp_Object)17; /* 1 */
    if (!(v174 == v105)) goto v31;
    v105 = v90;
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    v105 = qcar(v105);
    return onevalue(v105);

v31:
    v105 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v105);

v52:
    v105 = v90;
    v105 = qcdr(v105);
    return onevalue(v105);
}



/* Code for next!-random!-number */

static Lisp_Object MS_CDECL CC_nextKrandomKnumber(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v226, v225, v144;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "next-random-number");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for next-random-number");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v226 = qvalue(elt(env, 1)); /* unidev_next!* */
    v37 = (Lisp_Object)865; /* 54 */
    if (v226 == v37) goto v110;
    v37 = qvalue(elt(env, 1)); /* unidev_next!* */
    v37 = (Lisp_Object)((int32_t)(v37) + 0x10);
    qvalue(elt(env, 1)) = v37; /* unidev_next!* */
    goto v102;

v102:
    v226 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v37 = (Lisp_Object)865; /* 54 */
    if (v226 == v37) goto v108;
    v37 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v37 = (Lisp_Object)((int32_t)(v37) + 0x10);
    qvalue(elt(env, 2)) = v37; /* unidev_nextp!* */
    goto v174;

v174:
    v226 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v37 = qvalue(elt(env, 1)); /* unidev_next!* */
    v225 = *(Lisp_Object *)((char *)v226 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v226 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v37 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v37 = *(Lisp_Object *)((char *)v226 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v37 = (Lisp_Object)(int32_t)((int32_t)v225 - (int32_t)v37 + TAG_FIXNUM);
    v225 = v37;
    v37 = v225;
    v37 = ((intptr_t)(v37) < 0 ? lisp_true : nil);
    if (v37 == nil) goto v240;
    v226 = v225;
    v37 = qvalue(elt(env, 4)); /* randommodulus!* */
    v37 = (Lisp_Object)(int32_t)((int32_t)v226 + (int32_t)v37 - TAG_FIXNUM);
    v225 = v37;
    goto v240;

v240:
    v226 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v144 = qvalue(elt(env, 1)); /* unidev_next!* */
    v37 = v225;
    *(Lisp_Object *)((char *)v226 + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL))) = v37;
    return onevalue(v225);

v108:
    v37 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v37; /* unidev_nextp!* */
    goto v174;

v110:
    v37 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v37; /* unidev_next!* */
    goto v102;
}



/* Code for cl_atfp */

static Lisp_Object CC_cl_atfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v244, v180;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atfp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v244 = v0;
/* end of prologue */
    v267 = v244;
    if (!consp(v267)) goto v52;
    v267 = v244;
    v267 = qcar(v267);
    goto v53;

v53:
    v180 = v267;
    v244 = v180;
    v267 = elt(env, 1); /* true */
    v267 = (v244 == v267 ? lisp_true : nil);
    if (!(v267 == nil)) goto v187;
    v244 = v180;
    v267 = elt(env, 2); /* false */
    v267 = (v244 == v267 ? lisp_true : nil);
    goto v187;

v187:
    if (!(v267 == nil)) goto v2;
    v244 = v180;
    v267 = elt(env, 3); /* or */
    v267 = (v244 == v267 ? lisp_true : nil);
    if (!(v267 == nil)) goto v91;
    v244 = v180;
    v267 = elt(env, 4); /* and */
    v267 = (v244 == v267 ? lisp_true : nil);
    goto v91;

v91:
    if (!(v267 == nil)) goto v105;
    v244 = v180;
    v267 = elt(env, 5); /* not */
    v267 = (v244 == v267 ? lisp_true : nil);
    goto v105;

v105:
    if (!(v267 == nil)) goto v31;
    v244 = v180;
    v267 = elt(env, 6); /* impl */
    v267 = (v244 == v267 ? lisp_true : nil);
    if (!(v267 == nil)) goto v31;
    v244 = v180;
    v267 = elt(env, 7); /* repl */
    v267 = (v244 == v267 ? lisp_true : nil);
    if (!(v267 == nil)) goto v31;
    v244 = v180;
    v267 = elt(env, 8); /* equiv */
    v267 = (v244 == v267 ? lisp_true : nil);
    goto v31;

v31:
    if (!(v267 == nil)) goto v2;
    v244 = v180;
    v267 = elt(env, 9); /* ex */
    v267 = (v244 == v267 ? lisp_true : nil);
    if (!(v267 == nil)) goto v202;
    v244 = v180;
    v267 = elt(env, 10); /* all */
    v267 = (v244 == v267 ? lisp_true : nil);
    goto v202;

v202:
    if (!(v267 == nil)) goto v2;
    v244 = v180;
    v267 = elt(env, 11); /* bex */
    v267 = (v244 == v267 ? lisp_true : nil);
    if (!(v267 == nil)) goto v2;
    v267 = v180;
    v244 = elt(env, 12); /* ball */
    v267 = (v267 == v244 ? lisp_true : nil);
    goto v2;

v2:
    v267 = (v267 == nil ? lisp_true : nil);
    return onevalue(v267);

v52:
    v267 = v244;
    goto v53;
}



/* Code for searchpl */

static Lisp_Object CC_searchpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for searchpl");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v110;

v110:
    v19 = stack[-1];
    if (!consp(v19)) goto v111;
    v19 = stack[-1];
    v19 = qcar(v19);
    if (!consp(v19)) goto v111;
    v19 = stack[-1];
    v19 = qcar(v19);
    if (!consp(v19)) goto v149;
    v19 = stack[-1];
    v19 = qcar(v19);
    v19 = qcar(v19);
    if (!consp(v19)) goto v149;
    v19 = stack[-1];
    v19 = qcar(v19);
    v19 = qcar(v19);
    stack[0] = qcar(v19);
    v19 = stack[-1];
    v19 = qcar(v19);
    v19 = qcdr(v19);
    v19 = CC_searchpl(env, v19);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-3];
    v19 = cons(stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-3];
    v20 = v19;
    goto v107;

v107:
    v19 = stack[-2];
    v19 = cons(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-3];
    stack[-2] = v19;
    v19 = stack[-1];
    v19 = qcdr(v19);
    stack[-1] = v19;
    goto v110;

v149:
    v19 = qvalue(elt(env, 1)); /* nil */
    v20 = v19;
    goto v107;

v111:
    v19 = qvalue(elt(env, 1)); /* nil */
    v20 = v19;
    goto v50;

v50:
    v19 = stack[-2];
    if (v19 == nil) { popv(4); return onevalue(v20); }
    v19 = stack[-2];
    v19 = qcar(v19);
    fn = elt(env, 2); /* setunion */
    v19 = (*qfn2(fn))(qenv(fn), v19, v20);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-3];
    v20 = v19;
    v19 = stack[-2];
    v19 = qcdr(v19);
    stack[-2] = v19;
    goto v50;
/* error exit handlers */
v249:
    popv(4);
    return nil;
}



/* Code for ibalp_vmember */

static Lisp_Object CC_ibalp_vmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_vmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v0;
/* end of prologue */

v175:
    v39 = stack[0];
    if (v39 == nil) goto v73;
    v35 = stack[-1];
    v39 = stack[0];
    v39 = qcar(v39);
    fn = elt(env, 2); /* ibalp_vequal */
    v39 = (*qfn2(fn))(qenv(fn), v35, v39);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    if (!(v39 == nil)) { popv(3); return onevalue(v39); }
    v35 = stack[-1];
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[-1] = v35;
    stack[0] = v39;
    goto v175;

v73:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v39); }
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for omiir */

static Lisp_Object MS_CDECL CC_omiir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omiir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omiir");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 2); /* lex */
    v158 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    v158 = qvalue(elt(env, 1)); /* char */
    v158 = Lcompress(nil, v158);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    stack[0] = v158;
    fn = elt(env, 2); /* lex */
    v158 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v15;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for inshisto */

static Lisp_Object CC_inshisto(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v9, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inshisto");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v9 = qvalue(elt(env, 2)); /* maxvar */
    v221 = stack[-3];
    v221 = plus2(v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-5];
    v9 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    v221 = (Lisp_Object)1; /* 0 */
    v221 = *(Lisp_Object *)((char *)v9 + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    if (v221 == nil) goto v73;
    v9 = stack[-3];
    v221 = (Lisp_Object)1; /* 0 */
    v221 = (Lisp_Object)geq2(v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    v221 = v221 ? lisp_true : nil;
    env = stack[-5];
    if (v221 == nil) goto v73;
    stack[0] = qvalue(elt(env, 3)); /* codhisto */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v9 = qvalue(elt(env, 2)); /* maxvar */
    v221 = stack[-3];
    v221 = plus2(v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-5];
    v9 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    v221 = (Lisp_Object)17; /* 1 */
    v221 = *(Lisp_Object *)((char *)v9 + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    v9 = qcdr(v221);
    v221 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 6); /* min */
    v221 = (*qfn2(fn))(qenv(fn), v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-5];
    stack[-2] = v221;
    v221 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    stack[-4] = v221;
    if (v221 == nil) goto v11;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v9 = qvalue(elt(env, 2)); /* maxvar */
    v221 = stack[-4];
    v221 = plus2(v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-5];
    v9 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    v221 = (Lisp_Object)113; /* 7 */
    v9 = *(Lisp_Object *)((char *)v9 + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    v221 = stack[-3];
    v221 = Lrplaca(nil, v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-5];
    goto v76;

v76:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v9 = qvalue(elt(env, 2)); /* maxvar */
    v221 = stack[-3];
    v221 = plus2(v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-5];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL)));
    stack[0] = (Lisp_Object)113; /* 7 */
    v9 = qvalue(elt(env, 5)); /* nil */
    v221 = stack[-4];
    v221 = cons(v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v221;
    v8 = qvalue(elt(env, 3)); /* codhisto */
    v9 = stack[-2];
    v221 = stack[-3];
    *(Lisp_Object *)((char *)v8 + (CELL-TAG_VECTOR) + ((int32_t)v9/(16/CELL))) = v221;
    v221 = nil;
    { popv(6); return onevalue(v221); }

v11:
    v9 = stack[-2];
    v221 = qvalue(elt(env, 4)); /* headhisto */
    v221 = (Lisp_Object)greaterp2(v9, v221);
    nil = C_nil;
    if (exception_pending()) goto v274;
    v221 = v221 ? lisp_true : nil;
    env = stack[-5];
    if (v221 == nil) goto v76;
    v221 = stack[-2];
    qvalue(elt(env, 4)) = v221; /* headhisto */
    goto v76;

v73:
    v221 = nil;
    { popv(6); return onevalue(v221); }
/* error exit handlers */
v274:
    popv(6);
    return nil;
}



/* Code for mkuwedge */

static Lisp_Object CC_mkuwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuwedge");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v108 = v0;
/* end of prologue */
    v172 = v108;
    v172 = qcdr(v172);
    if (v172 == nil) goto v189;
    v172 = elt(env, 1); /* wedge */
    v108 = cons(v172, v108);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    fn = elt(env, 2); /* fkern */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v108 = qcar(v108);
    { popv(1); return onevalue(v108); }

v189:
    v108 = qcar(v108);
    { popv(1); return onevalue(v108); }
/* error exit handlers */
v102:
    popv(1);
    return nil;
}



/* Code for dcombine */

static Lisp_Object MS_CDECL CC_dcombine(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v51,
                         Lisp_Object v106, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v311, v312, v313, v314, v315;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dcombine");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dcombine");
#endif
    if (stack >= stacklimit)
    {
        push3(v106,v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v51,v106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v106;
    stack[-2] = v51;
    stack[-3] = v0;
/* end of prologue */
    v311 = stack[-3];
    if (!consp(v311)) goto v189;
    v311 = stack[-2];
    if (!consp(v311)) goto v186;
    v311 = stack[-3];
    v312 = qcar(v311);
    v311 = stack[-2];
    v311 = qcar(v311);
    if (v312 == v311) goto v203;
    v311 = stack[-3];
    v312 = qcar(v311);
    v311 = stack[-2];
    v311 = qcar(v311);
    stack[-4] = v312;
    stack[0] = v311;
    v312 = stack[-4];
    v311 = stack[0];
    v313 = get(v312, v311);
    env = stack[-5];
    v312 = elt(env, 2); /* (!:crn!: !:gi!:) */
    v311 = elt(env, 3); /* (!:rd!: !:cr!:) */
    v315 = v313;
    v314 = v312;
    v313 = v311;
    v311 = v315;
    if (v311 == nil) goto v135;
    v311 = v315;
    if (!(!consp(v311))) goto v135;
    v312 = stack[-4];
    v311 = elt(env, 4); /* cmpxfn */
    v311 = get(v312, v311);
    env = stack[-5];
    if (v311 == nil) goto v221;
    v312 = stack[0];
    v311 = elt(env, 4); /* cmpxfn */
    v311 = get(v312, v311);
    env = stack[-5];
    if (!(v311 == nil)) goto v221;

v252:
    v312 = stack[0];
    v311 = elt(env, 5); /* !:ps!: */
    if (!(v312 == v311)) goto v135;

v161:
    v312 = v315;
    v311 = stack[-3];
    v311 = Lapply1(nil, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    stack[-3] = v311;
    v312 = stack[0];
    v311 = stack[-1];
    v311 = get(v312, v311);
    env = stack[-5];
    v315 = v311;
    goto v204;

v204:
    v313 = v315;
    v312 = stack[-3];
    v311 = stack[-2];
    v311 = Lapply2(nil, 3, v313, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    goto v73;

v73:
    stack[-3] = v311;
    v311 = qvalue(elt(env, 12)); /* !*rounded */
    if (v311 == nil) goto v317;
    v311 = qvalue(elt(env, 13)); /* !*roundall */
    if (v311 == nil) goto v317;
    v311 = stack[-3];
    if (!consp(v311)) goto v317;
    v311 = stack[-3];
    v312 = qcar(v311);
    stack[-2] = v312;
    v311 = elt(env, 9); /* !:rn!: */
    if (!(v312 == v311)) goto v318;
    v311 = stack[-3];
    v311 = qcdr(v311);
    v312 = qcdr(v311);
    v311 = (Lisp_Object)17; /* 1 */
    if (v312 == v311) goto v318;
    v311 = stack[-3];
    v311 = qcdr(v311);
    fn = elt(env, 16); /* r2bf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    v312 = v311;
    v311 = qvalue(elt(env, 14)); /* !*!*roundbf */
    if (v311 == nil) goto v319;
    v311 = v312;
    goto v320;

v320:
    v312 = v311;
    if (!(!consp(v312))) goto v321;
    v312 = elt(env, 7); /* !:rd!: */
    v311 = cons(v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    goto v321;

v321:
    {
        popv(6);
        fn = elt(env, 17); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v311);
    }

v319:
    v311 = v312;
    fn = elt(env, 18); /* bf2flck */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    goto v320;

v318:
    v312 = stack[-2];
    v311 = elt(env, 11); /* !:crn!: */
    if (!(v312 == v311)) goto v322;
    v311 = stack[-3];
    v311 = qcdr(v311);
    v311 = qcar(v311);
    v312 = qcdr(v311);
    v311 = (Lisp_Object)17; /* 1 */
    if (!(v312 == v311)) goto v323;
    v311 = stack[-3];
    v311 = qcdr(v311);
    v311 = qcdr(v311);
    v312 = qcdr(v311);
    v311 = (Lisp_Object)17; /* 1 */
    if (!(v312 == v311)) goto v323;

v322:
    v311 = stack[-3];
    goto v321;

v323:
    v311 = stack[-3];
    fn = elt(env, 19); /* !*crn2cr */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    goto v321;

v317:
    v312 = stack[-1];
    v311 = elt(env, 15); /* divide */
    if (v312 == v311) goto v324;
    v311 = stack[-3];
    {
        popv(6);
        fn = elt(env, 17); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v311);
    }

v324:
    v311 = stack[-3];
    v311 = qcar(v311);
    fn = elt(env, 17); /* int!-equiv!-chk */
    stack[0] = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    v311 = stack[-3];
    v311 = qcdr(v311);
    fn = elt(env, 17); /* int!-equiv!-chk */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    {
        Lisp_Object v325 = stack[0];
        popv(6);
        return cons(v325, v311);
    }

v135:
    v312 = stack[0];
    v311 = elt(env, 6); /* noconvert */
    v311 = Lflagp(nil, v312, v311);
    env = stack[-5];
    if (!(v311 == nil)) goto v161;
    v312 = stack[-4];
    v311 = v314;
    v311 = Lmemq(nil, v312, v311);
    if (v311 == nil) goto v233;
    v312 = stack[0];
    v311 = elt(env, 7); /* !:rd!: */
    if (!(v312 == v311)) goto v233;

v59:
    v312 = stack[-4];
    v311 = elt(env, 8); /* !:cr!: */
    v312 = get(v312, v311);
    env = stack[-5];
    v311 = stack[-3];
    v311 = Lapply1(nil, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    stack[-3] = v311;
    v311 = elt(env, 8); /* !:cr!: */
    stack[-4] = v311;
    goto v326;

v326:
    v312 = stack[0];
    v311 = stack[-4];
    v312 = get(v312, v311);
    env = stack[-5];
    v311 = stack[-2];
    v311 = Lapply1(nil, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    stack[-2] = v311;
    v312 = stack[-4];
    v311 = stack[-1];
    v311 = get(v312, v311);
    env = stack[-5];
    v315 = v311;
    goto v204;

v233:
    v312 = stack[-4];
    v311 = elt(env, 7); /* !:rd!: */
    if (!(v312 == v311)) goto v327;
    v311 = stack[0];
    v312 = v314;
    v311 = Lmemq(nil, v311, v312);
    if (!(v311 == nil)) goto v59;

v327:
    v312 = stack[-4];
    v311 = elt(env, 9); /* !:rn!: */
    if (!(v312 == v311)) goto v328;
    v312 = stack[0];
    v311 = elt(env, 10); /* !:gi!: */
    if (!(v312 == v311)) goto v328;

v329:
    v312 = stack[-4];
    v311 = elt(env, 11); /* !:crn!: */
    v312 = get(v312, v311);
    env = stack[-5];
    v311 = stack[-3];
    v311 = Lapply1(nil, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    stack[-3] = v311;
    v311 = elt(env, 11); /* !:crn!: */
    stack[-4] = v311;
    goto v326;

v328:
    v312 = stack[-4];
    v311 = elt(env, 10); /* !:gi!: */
    if (!(v312 == v311)) goto v326;
    v312 = stack[0];
    v311 = elt(env, 9); /* !:rn!: */
    if (v312 == v311) goto v329;
    else goto v326;

v221:
    v312 = stack[-4];
    v311 = v313;
    v311 = Lmemq(nil, v312, v311);
    if (v311 == nil) goto v161;
    v311 = stack[0];
    v312 = v313;
    v311 = Lmemq(nil, v311, v312);
    if (v311 == nil) goto v252;
    else goto v161;

v203:
    v311 = stack[-3];
    v312 = qcar(v311);
    v311 = stack[-1];
    v313 = get(v312, v311);
    env = stack[-5];
    v312 = stack[-3];
    v311 = stack[-2];
    v311 = Lapply2(nil, 3, v313, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    goto v73;

v186:
    v311 = stack[-3];
    v312 = qcar(v311);
    v311 = stack[-1];
    stack[-4] = get(v312, v311);
    env = stack[-5];
    stack[0] = stack[-3];
    v311 = stack[-3];
    v312 = qcar(v311);
    v311 = elt(env, 1); /* i2d */
    v312 = get(v312, v311);
    env = stack[-5];
    v311 = stack[-2];
    v311 = Lapply1(nil, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    v311 = Lapply2(nil, 3, stack[-4], stack[0], v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    goto v73;

v189:
    v311 = stack[-2];
    v312 = qcar(v311);
    v311 = stack[-1];
    stack[0] = get(v312, v311);
    env = stack[-5];
    v311 = stack[-2];
    v312 = qcar(v311);
    v311 = elt(env, 1); /* i2d */
    v312 = get(v312, v311);
    env = stack[-5];
    v311 = stack[-3];
    v312 = Lapply1(nil, v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    v311 = stack[-2];
    v311 = Lapply2(nil, 3, stack[0], v312, v311);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    goto v73;
/* error exit handlers */
v316:
    popv(6);
    return nil;
}



/* Code for sq2sscfpl */

static Lisp_Object CC_sq2sscfpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v51)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v254, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sscfpl");
#endif
    if (stack >= stacklimit)
    {
        push2(v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v0;
/* end of prologue */
    v254 = stack[-1];
    if (v254 == nil) goto v73;
    v254 = stack[-1];
    if (!consp(v254)) goto v189;
    v254 = stack[-1];
    v254 = qcar(v254);
    if (!consp(v254)) goto v189;
    v254 = stack[-1];
    v186 = qcar(v254);
    v254 = stack[0];
    fn = elt(env, 2); /* sq2sstm */
    stack[-2] = (*qfn2(fn))(qenv(fn), v186, v254);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    v254 = stack[-1];
    v186 = qcdr(v254);
    v254 = stack[0];
    v254 = CC_sq2sscfpl(env, v186, v254);
    nil = C_nil;
    if (exception_pending()) goto v185;
    {
        Lisp_Object v195 = stack[-2];
        popv(4);
        return Lappend(nil, v195, v254);
    }

v189:
    v254 = stack[0];
    v254 = qcdr(v254);
    v254 = add1(v254);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    fn = elt(env, 3); /* mkzl */
    v186 = (*qfn1(fn))(qenv(fn), v254);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    v254 = stack[-1];
    v254 = cons(v186, v254);
    nil = C_nil;
    if (exception_pending()) goto v185;
    popv(4);
    return ncons(v254);

v73:
    v254 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v254); }
/* error exit handlers */
v185:
    popv(4);
    return nil;
}



/* Code for chknewnam */

static Lisp_Object CC_chknewnam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89, v31, v193;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chknewnam");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */

v15:
    v89 = v31;
    v88 = elt(env, 1); /* newnam */
    v88 = get(v89, v88);
    env = stack[0];
    v193 = v88;
    if (v88 == nil) { popv(1); return onevalue(v31); }
    v89 = v193;
    v88 = v31;
    if (v89 == v88) { popv(1); return onevalue(v31); }
    v88 = v193;
    if (!(symbolp(v88))) { popv(1); return onevalue(v193); }
    v88 = v193;
    v31 = v88;
    goto v15;
}



/* Code for simptimes */

static Lisp_Object CC_simptimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simptimes");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    v3 = stack[-1];
    if (v3 == nil) goto v40;
    v4 = qvalue(elt(env, 1)); /* tstack!* */
    v3 = (Lisp_Object)1; /* 0 */
    if (!(v4 == v3)) goto v110;
    v3 = qvalue(elt(env, 2)); /* mul!* */
    if (v3 == nil) goto v110;
    v3 = qvalue(elt(env, 2)); /* mul!* */
    stack[-2] = v3;
    v3 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v3; /* mul!* */
    goto v110;

v110:
    v3 = qvalue(elt(env, 1)); /* tstack!* */
    v3 = add1(v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    qvalue(elt(env, 1)) = v3; /* tstack!* */
    v3 = stack[-1];
    v3 = qcar(v3);
    fn = elt(env, 5); /* simp */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    stack[0] = v3;
    goto v111;

v111:
    v3 = stack[-1];
    v3 = qcdr(v3);
    stack[-1] = v3;
    v3 = stack[0];
    v3 = qcar(v3);
    if (v3 == nil) goto v158;
    v3 = stack[-1];
    if (v3 == nil) goto v50;
    v3 = stack[-1];
    v3 = qcar(v3);
    fn = elt(env, 5); /* simp */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    fn = elt(env, 6); /* multsq */
    v3 = (*qfn2(fn))(qenv(fn), stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    stack[0] = v3;
    goto v111;

v50:
    v3 = qvalue(elt(env, 2)); /* mul!* */
    if (v3 == nil) goto v158;
    v4 = qvalue(elt(env, 1)); /* tstack!* */
    v3 = (Lisp_Object)17; /* 1 */
    v3 = (Lisp_Object)greaterp2(v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    v3 = v3 ? lisp_true : nil;
    env = stack[-3];
    if (!(v3 == nil)) goto v158;
    v3 = qvalue(elt(env, 2)); /* mul!* */
    v4 = qcar(v3);
    v3 = stack[0];
    v3 = Lapply1(nil, v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    stack[0] = v3;
    v3 = qvalue(elt(env, 3)); /* nil */
    v3 = ncons(v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    qvalue(elt(env, 4)) = v3; /* alglist!* */
    v3 = qvalue(elt(env, 2)); /* mul!* */
    v3 = qcdr(v3);
    qvalue(elt(env, 2)) = v3; /* mul!* */
    goto v50;

v158:
    v3 = qvalue(elt(env, 1)); /* tstack!* */
    v3 = sub1(v3);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    qvalue(elt(env, 1)) = v3; /* tstack!* */
    v4 = qvalue(elt(env, 1)); /* tstack!* */
    v3 = (Lisp_Object)1; /* 0 */
    if (!(v4 == v3)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v3 = stack[-2];
    qvalue(elt(env, 2)) = v3; /* mul!* */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v40:
    v4 = (Lisp_Object)17; /* 1 */
    v3 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v4, v3);
/* error exit handlers */
v10:
    popv(4);
    return nil;
}



/* Code for listtest */

static Lisp_Object MS_CDECL CC_listtest(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v51,
                         Lisp_Object v106, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91, v109;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "listtest");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listtest");
#endif
    if (stack >= stacklimit)
    {
        push3(v106,v51,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v51,v106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v106;
    stack[-1] = v51;
    stack[-2] = v0;
/* end of prologue */

v110:
    v90 = stack[-2];
    if (v90 == nil) goto v158;
    v109 = stack[0];
    v90 = stack[-2];
    v91 = qcar(v90);
    v90 = stack[-1];
    v90 = Lapply2(nil, 3, v109, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    if (v90 == nil) goto v193;
    v90 = stack[-2];
    v90 = qcar(v90);
    if (v90 == nil) goto v25;
    v90 = stack[-2];
    v90 = qcar(v90);
    { popv(4); return onevalue(v90); }

v25:
    v90 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v90); }

v193:
    v90 = stack[-2];
    v90 = qcdr(v90);
    stack[-2] = v90;
    goto v110;

v158:
    v90 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v90); }
/* error exit handlers */
v26:
    popv(4);
    return nil;
}



setup_type const u11_setup[] =
{
    {"matsm*1",                 CC_matsmH1,     too_many_1,    wrong_no_1},
    {"setdmode1",               too_few_2,      CC_setdmode1,  wrong_no_2},
    {"map__edges",              CC_map__edges,  too_many_1,    wrong_no_1},
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"simpminus",               CC_simpminus,   too_many_1,    wrong_no_1},
    {"red-ratios1",             too_few_2,      CC_redKratios1,wrong_no_2},
    {"mtchk",                   too_few_2,      CC_mtchk,      wrong_no_2},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"b:ordexn",                too_few_2,      CC_bTordexn,   wrong_no_2},
    {"tr_write",                CC_tr_write,    too_many_1,    wrong_no_1},
    {"cl_varl2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_varl2},
    {"integerom",               CC_integerom,   too_many_1,    wrong_no_1},
    {"findnewvars",             CC_findnewvars, too_many_1,    wrong_no_1},
    {"vevlcm",                  too_few_2,      CC_vevlcm,     wrong_no_2},
    {"listeval",                too_few_2,      CC_listeval,   wrong_no_2},
    {"cut:mt",                  too_few_2,      CC_cutTmt,     wrong_no_2},
    {"*kp2f",                   too_few_2,      CC_Hkp2f,      wrong_no_2},
    {"statep*",                 CC_statepH,     too_many_1,    wrong_no_1},
    {"mkinds",                  too_few_2,      CC_mkinds,     wrong_no_2},
    {"sqp",                     CC_sqp,         too_many_1,    wrong_no_1},
    {"make-term",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKterm},
    {"sizchk",                  too_few_2,      CC_sizchk,     wrong_no_2},
    {"dd",                      too_few_2,      CC_dd,         wrong_no_2},
    {"pv_neg",                  CC_pv_neg,      too_many_1,    wrong_no_1},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"next-random-number",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nextKrandomKnumber},
    {"cl_atfp",                 CC_cl_atfp,     too_many_1,    wrong_no_1},
    {"searchpl",                CC_searchpl,    too_many_1,    wrong_no_1},
    {"ibalp_vmember",           too_few_2,      CC_ibalp_vmember,wrong_no_2},
    {"omiir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omiir},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"dcombine",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_dcombine},
    {"sq2sscfpl",               too_few_2,      CC_sq2sscfpl,  wrong_no_2},
    {"chknewnam",               CC_chknewnam,   too_many_1,    wrong_no_1},
    {"simptimes",               CC_simptimes,   too_many_1,    wrong_no_1},
    {"listtest",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_listtest},
    {NULL, (one_args *)"u11", (two_args *)"20794 3602637 5267791", 0}
};

/* end of generated code */
