
/* $destdir\u58.c        Machine generated C code */

/* Signature: 00000000 07-Oct-2010 */

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


/* Code for evalsymsubset */

static Lisp_Object CC_evalsymsubset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v23, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsymsubset");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    v22 = v21;
    v22 = qcar(v22);
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v24 = v22;
    v23 = v21;
    v22 = v23;
    v21 = elt(env, 1); /* union */
    if (!consp(v22)) goto v25;
    v22 = qcar(v22);
    if (!(v22 == v21)) goto v25;
    v22 = v24;
    v21 = v23;
    v21 = qcdr(v21);
    v21 = Lmember(nil, v22, v21);
    goto v26;

v26:
    if (!(v21 == nil)) return onevalue(v21);
    v22 = v24;
    v21 = elt(env, 3); /* intersection */
    if (!consp(v22)) goto v27;
    v22 = qcar(v22);
    if (!(v22 == v21)) goto v27;
    v22 = v23;
    v21 = v24;
    v21 = qcdr(v21);
    v21 = Lmember(nil, v22, v21);
    goto v28;

v28:
    if (!(v21 == nil)) return onevalue(v21);
    v22 = v24;
    v21 = elt(env, 4); /* setdiff */
    if (!consp(v22)) goto v29;
    v22 = qcar(v22);
    if (!(v22 == v21)) goto v29;
    v21 = v24;
    v21 = qcdr(v21);
    v22 = qcar(v21);
    v21 = v23;
    v21 = (equal(v22, v21) ? lisp_true : nil);
    if (!(v21 == nil)) return onevalue(v21);
    v22 = v23;
    v21 = elt(env, 1); /* union */
    if (!consp(v22)) goto v30;
    v22 = qcar(v22);
    if (!(v22 == v21)) goto v30;
    v21 = v24;
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v22 = v23;
    v22 = qcdr(v22);
    v21 = Lmember(nil, v21, v22);
    return onevalue(v21);

v30:
    v21 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v21);

v29:
    v21 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v21);

v27:
    v21 = qvalue(elt(env, 2)); /* nil */
    goto v28;

v25:
    v21 = qvalue(elt(env, 2)); /* nil */
    goto v26;
}



/* Code for all_defined */

static Lisp_Object CC_all_defined(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    v36 = v0;
/* end of prologue */
    stack[-1] = v36;
    fn = elt(env, 1); /* map__edges */
    v37 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v36 = stack[0];
    fn = elt(env, 2); /* defined_append */
    v36 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    {
        Lisp_Object v38 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* all_defined_map_ */
        return (*qfn2(fn))(qenv(fn), v38, v36);
    }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for dp!=prod */

static Lisp_Object CC_dpMprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    v45 = v0;
/* end of prologue */
    v44 = v45;
    if (v44 == nil) goto v47;
    v44 = stack[-1];
    if (v44 == nil) goto v47;
    stack[-2] = nil;
    v44 = v45;
    stack[0] = v44;
    goto v37;

v37:
    v44 = stack[0];
    if (v44 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v44 = stack[0];
    v44 = qcar(v44);
    v45 = v44;
    v46 = qcdr(v45);
    v45 = qcar(v44);
    v44 = stack[-1];
    fn = elt(env, 2); /* dp_times_bcmo */
    v45 = (*qfnn(fn))(qenv(fn), 3, v46, v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v44 = stack[-2];
    fn = elt(env, 3); /* dp_sum */
    v44 = (*qfn2(fn))(qenv(fn), v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    stack[-2] = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v37;

v47:
    v44 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v44); }
/* error exit handlers */
v48:
    popv(4);
    return nil;
}



/* Code for getsetvarlis */

static Lisp_Object CC_getsetvarlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getsetvarlis");
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
    goto v47;

v47:
    v63 = stack[0];
    if (v63 == nil) goto v3;
    v63 = stack[0];
    if (!consp(v63)) goto v36;
    v63 = stack[0];
    v63 = qcar(v63);
    if (!consp(v63)) goto v65;
    v63 = stack[0];
    v63 = qcar(v63);
    v64 = qcar(v63);
    v63 = elt(env, 9); /* (setel setk) */
    v63 = Lmemq(nil, v64, v63);
    if (v63 == nil) goto v66;
    v63 = stack[0];
    v63 = qcar(v63);
    v63 = qcdr(v63);
    v63 = qcar(v63);
    v64 = CC_getsetvarlis(env, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v63 = stack[-1];
    v63 = cons(v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    stack[-1] = v63;
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v47;

v66:
    v63 = stack[0];
    v63 = qcar(v63);
    v64 = qcar(v63);
    v63 = elt(env, 10); /* setq */
    if (v64 == v63) goto v68;
    v63 = stack[0];
    v64 = qcar(v63);
    v63 = stack[-1];
    v63 = cons(v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    stack[-1] = v63;
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v47;

v68:
    v63 = stack[0];
    v63 = qcar(v63);
    v63 = qcdr(v63);
    v63 = qcar(v63);
    v64 = Lmkquote(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v63 = stack[-1];
    v63 = cons(v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    stack[-1] = v63;
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v47;

v65:
    v63 = stack[0];
    v64 = qcar(v63);
    v63 = stack[-1];
    v63 = cons(v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    stack[-1] = v63;
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v47;

v36:
    v63 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 11); /* terpri!* */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v63 = elt(env, 2); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 12); /* lprie */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v64 = elt(env, 3); /* "getsetvarlis" */
    v63 = stack[0];
    v63 = list2(v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    fn = elt(env, 13); /* printty */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v64 = elt(env, 4); /* " " */
    v63 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 14); /* lpriw */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v63 = elt(env, 6); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v64 = v63;
    v63 = v64;
    qvalue(elt(env, 7)) = v63; /* errmsg!* */
    v63 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v63 == nil)) goto v69;
    v63 = v64;
    fn = elt(env, 12); /* lprie */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    goto v69;

v69:
    v63 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v63 = nil;
    {
        Lisp_Object v70 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v70, v63);
    }

v3:
    v63 = stack[-1];
    {
        popv(3);
        fn = elt(env, 15); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v63);
    }
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for pe_inv */

static Lisp_Object CC_pe_inv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pe_inv");
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
    v74 = stack[-3];
    fn = elt(env, 2); /* upbve */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    v74 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    v74 = Lmkvect(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    stack[-4] = v74;
    v74 = (Lisp_Object)17; /* 1 */
    stack[-2] = v74;
    goto v20;

v20:
    v74 = stack[-3];
    fn = elt(env, 2); /* upbve */
    v44 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    v74 = stack[-2];
    v74 = difference2(v44, v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    v74 = Lminusp(nil, v74);
    env = stack[-5];
    if (!(v74 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v74 = stack[-2];
    v74 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    v74 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v74/(16/CELL)));
    v44 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    v74 = stack[-2];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v44/(16/CELL))) = v74;
    v74 = stack[-2];
    v74 = add1(v74);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-5];
    stack[-2] = v74;
    goto v20;
/* error exit handlers */
v48:
    popv(6);
    return nil;
}



/* Code for radf */

static Lisp_Object CC_radf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v175, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for radf");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v31;
    stack[-8] = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-2] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = qvalue(elt(env, 2)); /* !*mcd */
    qvalue(elt(env, 2)) = nil; /* !*mcd */
    v174 = stack[-8];
    if (v174 == nil) goto v25;
    v174 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v174; /* !*mcd */
    qvalue(elt(env, 1)) = v174; /* !*gcd */
    v174 = (Lisp_Object)17; /* 1 */
    stack[-9] = v174;
    v174 = (Lisp_Object)17; /* 1 */
    stack[-3] = v174;
    goto v38;

v38:
    v174 = stack[-8];
    if (!consp(v174)) goto v177;
    v174 = stack[-8];
    v174 = qcar(v174);
    if (!consp(v174)) goto v177;
    v174 = stack[-8];
    fn = elt(env, 15); /* comfac */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-4] = v174;
    v174 = stack[-4];
    v174 = qcar(v174);
    if (v174 == nil) goto v179;
    v174 = qvalue(elt(env, 5)); /* !*precise_complex */
    if (v174 == nil) goto v180;
    v175 = (Lisp_Object)1; /* 0 */
    v174 = stack[-4];
    v174 = qcar(v174);
    v174 = qcdr(v174);
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    goto v60;

v60:
    stack[-5] = v174;
    v174 = stack[-5];
    v175 = qcar(v174);
    v174 = (Lisp_Object)1; /* 0 */
    if (v175 == v174) goto v181;
    v174 = stack[-5];
    v174 = qcar(v174);
    v174 = Levenp(nil, v174);
    env = stack[-10];
    if (v174 == nil) goto v182;
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v176 = qcar(v174);
    v174 = stack[-5];
    v175 = qcar(v174);
    v174 = (Lisp_Object)17; /* 1 */
    v174 = acons(v176, v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v183;

v183:
    v174 = stack[-9];
    fn = elt(env, 16); /* multf */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-9] = v174;
    goto v181;

v181:
    v174 = stack[-5];
    v175 = qcdr(v174);
    v174 = (Lisp_Object)1; /* 0 */
    if (v175 == v174) goto v179;
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcar(v174);
    if (!consp(v174)) goto v184;
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcar(v174);
    if (!consp(v174)) goto v184;
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v175 = qcar(v174);
    v174 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 17); /* prepf1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    v174 = v175;
    if (v174 == nil) goto v185;
    v174 = v175;
    fn = elt(env, 18); /* replus */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    goto v186;

v186:
    v175 = v174;
    v174 = stack[-5];
    v176 = qcdr(v174);
    v174 = (Lisp_Object)17; /* 1 */
    if (v176 == v174) goto v187;
    v176 = elt(env, 8); /* expt */
    v174 = stack[-5];
    v174 = qcdr(v174);
    v174 = list3(v176, v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v188;

v188:
    v174 = stack[-6];
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-6] = v174;
    goto v179;

v179:
    stack[0] = stack[-8];
    v174 = stack[-4];
    v174 = qcar(v174);
    if (v174 == nil) goto v189;
    v174 = stack[-4];
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    goto v190;

v190:
    fn = elt(env, 19); /* quotf */
    v174 = (*qfn2(fn))(qenv(fn), stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-5] = v174;
    v174 = stack[-4];
    v174 = qcdr(v174);
    stack[-8] = v174;
    v174 = qvalue(elt(env, 9)); /* !*reduced */
    if (v174 == nil) goto v191;
    v174 = stack[-5];
    fn = elt(env, 20); /* minusf */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    if (v174 == nil) goto v191;
    v174 = stack[-5];
    fn = elt(env, 21); /* negf */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-5] = v174;
    v174 = stack[-8];
    fn = elt(env, 21); /* negf */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-8] = v174;
    goto v191;

v191:
    v175 = qvalue(elt(env, 10)); /* dmode!* */
    v174 = elt(env, 11); /* field */
    v174 = Lflagp(nil, v175, v174);
    env = stack[-10];
    if (v174 == nil) goto v192;
    v174 = stack[-5];
    fn = elt(env, 22); /* lnc */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-4] = v174;
    v175 = stack[-4];
    v174 = (Lisp_Object)17; /* 1 */
    if (v175 == v174) goto v192;
    v175 = stack[-5];
    v174 = stack[-4];
    fn = elt(env, 19); /* quotf */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-5] = v174;
    v175 = stack[-4];
    v174 = stack[-3];
    fn = elt(env, 23); /* multd */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-3] = v174;
    goto v192;

v192:
    v175 = stack[-5];
    v174 = (Lisp_Object)17; /* 1 */
    if (v175 == v174) goto v38;
    v174 = qvalue(elt(env, 5)); /* !*precise_complex */
    if (v174 == nil) goto v193;
    v175 = stack[-5];
    v174 = (Lisp_Object)17; /* 1 */
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v194;

v194:
    v174 = stack[-7];
    fn = elt(env, 24); /* radf1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-5] = v174;
    v174 = stack[-5];
    v174 = qcar(v174);
    stack[-4] = v174;
    v175 = stack[-4];
    v174 = (Lisp_Object)17; /* 1 */
    if (v175 == v174) goto v195;
    v174 = qvalue(elt(env, 6)); /* !*precise */
    if (v174 == nil) goto v196;
    v174 = stack[-7];
    v174 = Levenp(nil, v174);
    env = stack[-10];
    if (v174 == nil) goto v196;
    stack[0] = elt(env, 7); /* abs */
    v175 = stack[-4];
    v174 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 17); /* prepf1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    v174 = v175;
    if (v174 == nil) goto v197;
    v174 = v175;
    fn = elt(env, 18); /* replus */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    goto v198;

v198:
    v174 = list2(stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    fn = elt(env, 25); /* fkern */
    v175 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 26); /* getpower */
    v175 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = (Lisp_Object)17; /* 1 */
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-4] = v174;
    goto v196;

v196:
    v175 = stack[-4];
    v174 = stack[-9];
    fn = elt(env, 16); /* multf */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-9] = v174;
    goto v195;

v195:
    v175 = stack[-6];
    v174 = stack[-5];
    v174 = qcdr(v174);
    v174 = Lappend(nil, v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-6] = v174;
    goto v38;

v197:
    v174 = (Lisp_Object)1; /* 0 */
    goto v198;

v193:
    v174 = stack[-5];
    fn = elt(env, 27); /* sqfrf */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v194;

v189:
    v174 = stack[-4];
    v174 = qcdr(v174);
    goto v190;

v187:
    v174 = v175;
    v175 = v174;
    goto v188;

v185:
    v174 = (Lisp_Object)1; /* 0 */
    goto v186;

v184:
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcar(v174);
    goto v186;

v182:
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v176 = qcar(v174);
    v174 = stack[-4];
    v174 = qcar(v174);
    v175 = qcdr(v174);
    v174 = (Lisp_Object)17; /* 1 */
    v174 = acons(v176, v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[0] = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = qvalue(elt(env, 6)); /* !*precise */
    if (v174 == nil) goto v199;
    v174 = stack[-7];
    v174 = Levenp(nil, v174);
    env = stack[-10];
    if (v174 == nil) goto v199;
    v175 = elt(env, 7); /* abs */
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = list2(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v176 = v174;
    goto v67;

v67:
    v174 = stack[-5];
    v175 = qcar(v174);
    v174 = (Lisp_Object)17; /* 1 */
    v174 = acons(v176, v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = stack[-7];
    fn = elt(env, 28); /* check!-radf!-sign */
    v174 = (*qfnn(fn))(qenv(fn), 3, stack[0], v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v183;

v199:
    v174 = stack[-8];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcar(v174);
    v176 = v174;
    goto v67;

v180:
    v174 = stack[-4];
    v174 = qcar(v174);
    v175 = qcdr(v174);
    v174 = stack[-7];
    v174 = Ldivide(nil, v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    goto v60;

v177:
    v175 = stack[-8];
    v174 = (Lisp_Object)17; /* 1 */
    if (v175 == v174) goto v200;
    v175 = stack[-8];
    v174 = stack[-7];
    fn = elt(env, 29); /* radd */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-5] = v174;
    v174 = stack[-5];
    v175 = qcar(v174);
    v174 = stack[-9];
    fn = elt(env, 16); /* multf */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-9] = v174;
    v174 = stack[-5];
    v175 = qcdr(v174);
    v174 = stack[-6];
    v174 = Lappend(nil, v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-6] = v174;
    goto v200;

v200:
    v175 = stack[-3];
    v174 = (Lisp_Object)17; /* 1 */
    if (v175 == v174) goto v201;
    v174 = qvalue(elt(env, 12)); /* !*numval */
    if (v174 == nil) goto v202;
    stack[-5] = elt(env, 8); /* expt */
    stack[-4] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v174 = stack[-7];
    fn = elt(env, 30); /* !:recip */
    v175 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = (Lisp_Object)17; /* 1 */
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v174 = acons(stack[-4], stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    fn = elt(env, 31); /* domainvalchk */
    v174 = (*qfn2(fn))(qenv(fn), stack[-5], v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-4] = v174;
    if (v174 == nil) goto v202;
    v174 = stack[-4];
    v175 = qcdr(v174);
    v174 = (Lisp_Object)17; /* 1 */
    if (v175 == v174) goto v203;
    v174 = stack[-4];
    v174 = qcar(v174);
    if (v174 == nil) goto v204;
    v175 = stack[-4];
    v174 = elt(env, 13); /* prepf */
    fn = elt(env, 32); /* sqform */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v205;

v205:
    v174 = elt(env, 14); /* polynomial */
    fn = elt(env, 33); /* typerr */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v206;

v206:
    v174 = stack[-9];
    fn = elt(env, 23); /* multd */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-9] = v174;
    goto v201;

v201:
    v175 = stack[-9];
    v174 = stack[-6];
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    goto v71;

v71:
    qvalue(elt(env, 2)) = stack[-1]; /* !*mcd */
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    { popv(11); return onevalue(v174); }

v204:
    v174 = (Lisp_Object)1; /* 0 */
    v175 = v174;
    goto v205;

v203:
    v174 = stack[-4];
    v174 = qcar(v174);
    v175 = v174;
    goto v206;

v202:
    v175 = stack[-3];
    v174 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 17); /* prepf1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    v174 = v175;
    if (v174 == nil) goto v207;
    v174 = v175;
    fn = elt(env, 18); /* replus */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    v175 = v174;
    goto v208;

v208:
    v174 = stack[-6];
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    stack[-6] = v174;
    goto v201;

v207:
    v174 = (Lisp_Object)1; /* 0 */
    v175 = v174;
    goto v208;

v25:
    v174 = stack[-8];
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-10];
    goto v71;
/* error exit handlers */
v178:
    env = stack[-10];
    qvalue(elt(env, 2)) = stack[-1]; /* !*mcd */
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    popv(11);
    return nil;
}



/* Code for cl_pnf1 */

static Lisp_Object CC_cl_pnf1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pnf1");
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
    v18 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cl_rename!-vars */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    fn = elt(env, 2); /* cl_pnf2 */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    stack[-1] = v18;
    v18 = stack[-1];
    v18 = qcdr(v18);
    if (v18 == nil) goto v3;
    v18 = stack[-1];
    v18 = qcar(v18);
    fn = elt(env, 3); /* cl_qb */
    stack[0] = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    v18 = stack[-1];
    v18 = qcdr(v18);
    v18 = qcar(v18);
    fn = elt(env, 3); /* cl_qb */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    v18 = (Lisp_Object)lessp2(stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v11;
    v18 = v18 ? lisp_true : nil;
    if (!(v18 == nil)) goto v3;
    v18 = stack[-1];
    v18 = qcdr(v18);
    v18 = qcar(v18);
    { popv(3); return onevalue(v18); }

v3:
    v18 = stack[-1];
    v18 = qcar(v18);
    { popv(3); return onevalue(v18); }
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for ofsf_smdbgetrel */

static Lisp_Object CC_ofsf_smdbgetrel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v18, v211, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smdbgetrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v211 = v31;
    v62 = v0;
/* end of prologue */

v33:
    v18 = v62;
    v210 = v211;
    v210 = qcar(v210);
    v210 = qcdr(v210);
    v210 = qcdr(v210);
    if (equal(v18, v210)) goto v3;
    v210 = v211;
    v210 = qcdr(v210);
    if (v210 == nil) goto v42;
    v210 = v211;
    v210 = qcdr(v210);
    v211 = v210;
    goto v33;

v42:
    v210 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v210);

v3:
    v210 = v211;
    v210 = qcar(v210);
    v210 = qcdr(v210);
    v210 = qcar(v210);
    return onevalue(v210);
}



/* Code for find!-non!-zero */

static Lisp_Object CC_findKnonKzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-non-zero");
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
    v45 = (Lisp_Object)17; /* 1 */
    stack[0] = v45;
    goto v4;

v4:
    v45 = (Lisp_Object)17; /* 1 */
    v12 = v45;
    v45 = stack[-1];
    v45 = qcar(v45);
    stack[-2] = v45;
    goto v36;

v36:
    v45 = stack[-2];
    v46 = qcar(v45);
    v45 = (Lisp_Object)1; /* 0 */
    if (v46 == v45) goto v34;
    v45 = stack[0];
    v46 = v12;
    popv(4);
    return cons(v45, v46);

v34:
    v45 = stack[-2];
    v45 = qcdr(v45);
    stack[-2] = v45;
    v45 = v12;
    v45 = add1(v45);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    v12 = v45;
    v45 = stack[-2];
    if (!(v45 == nil)) goto v36;
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    v45 = stack[0];
    v45 = add1(v45);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[0] = v45;
    v45 = stack[-1];
    if (!(v45 == nil)) goto v4;
    v45 = elt(env, 0); /* find!-non!-zero */
    fn = elt(env, 1); /* confusion */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    goto v4;
/* error exit handlers */
v180:
    popv(4);
    return nil;
}



/* Code for giremainder */

static Lisp_Object CC_giremainder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v142, v246;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giremainder");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v142 = v31;
    v246 = v0;
/* end of prologue */
    v144 = v246;
    v144 = qcdr(v144);
    v144 = qcar(v144);
    stack[-7] = v144;
    v144 = v246;
    v144 = qcdr(v144);
    v144 = qcdr(v144);
    stack[-6] = v144;
    v144 = v142;
    v144 = qcdr(v144);
    v144 = qcar(v144);
    stack[-5] = v144;
    v144 = v142;
    v144 = qcdr(v144);
    v144 = qcdr(v144);
    stack[-4] = v144;
    v142 = stack[-5];
    v144 = stack[-5];
    stack[0] = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = stack[-4];
    v144 = stack[-4];
    v144 = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = plus2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-3] = v144;
    v142 = stack[-7];
    v144 = stack[-5];
    stack[0] = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = stack[-6];
    v144 = stack[-4];
    v144 = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = plus2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-2] = v144;
    v142 = stack[-6];
    v144 = stack[-5];
    stack[0] = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = stack[-4];
    v144 = stack[-7];
    v144 = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = difference2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-1] = v144;
    v142 = (Lisp_Object)33; /* 2 */
    v144 = stack[-2];
    stack[0] = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = stack[-2];
    v144 = (Lisp_Object)1; /* 0 */
    v144 = (Lisp_Object)lessp2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v144 = v144 ? lisp_true : nil;
    env = stack[-8];
    if (v144 == nil) goto v165;
    v144 = stack[-3];
    v144 = negate(v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = add1(v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    goto v2;

v2:
    stack[0] = plus2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = (Lisp_Object)33; /* 2 */
    v144 = stack[-3];
    v144 = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = Ldivide(nil, stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = qcar(v144);
    stack[-2] = v144;
    v142 = (Lisp_Object)33; /* 2 */
    v144 = stack[-1];
    stack[0] = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = stack[-1];
    v144 = (Lisp_Object)1; /* 0 */
    v144 = (Lisp_Object)lessp2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v144 = v144 ? lisp_true : nil;
    env = stack[-8];
    if (v144 == nil) goto v247;
    v144 = stack[-3];
    v144 = negate(v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = add1(v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    goto v248;

v248:
    stack[0] = plus2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = (Lisp_Object)33; /* 2 */
    v144 = stack[-3];
    v144 = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = Ldivide(nil, stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = qcar(v144);
    stack[-1] = v144;
    stack[-3] = stack[-7];
    v142 = stack[-2];
    v144 = stack[-5];
    stack[0] = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = stack[-1];
    v144 = stack[-4];
    v144 = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = difference2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = difference2(stack[-3], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[0] = v144;
    stack[-3] = stack[-6];
    v142 = stack[-1];
    v144 = stack[-5];
    stack[-1] = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = stack[-2];
    v144 = stack[-4];
    v144 = times2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = plus2(stack[-1], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v144 = difference2(stack[-3], v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v142 = v144;
    v246 = elt(env, 1); /* !:gi!: */
    v144 = stack[0];
    popv(9);
    return list2star(v246, v144, v142);

v247:
    v144 = stack[-3];
    v144 = sub1(v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    goto v248;

v165:
    v144 = stack[-3];
    v144 = sub1(v144);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    goto v2;
/* error exit handlers */
v189:
    popv(9);
    return nil;
}



/* Code for ofsf_facequal */

static Lisp_Object CC_ofsf_facequal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v168, v256;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facequal");
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
    v255 = v0;
/* end of prologue */
    fn = elt(env, 7); /* fctrf */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-4];
    v255 = qcdr(v255);
    stack[-3] = v255;
    v255 = stack[-3];
    if (v255 == nil) goto v26;
    v255 = stack[-3];
    v255 = qcar(v255);
    v256 = elt(env, 2); /* equal */
    v168 = qcar(v255);
    v255 = qvalue(elt(env, 1)); /* nil */
    v255 = list3(v256, v168, v255);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-4];
    v255 = ncons(v255);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-4];
    stack[-1] = v255;
    stack[-2] = v255;
    goto v4;

v4:
    v255 = stack[-3];
    v255 = qcdr(v255);
    stack[-3] = v255;
    v255 = stack[-3];
    if (v255 == nil) goto v11;
    stack[0] = stack[-1];
    v255 = stack[-3];
    v255 = qcar(v255);
    v256 = elt(env, 2); /* equal */
    v168 = qcar(v255);
    v255 = qvalue(elt(env, 1)); /* nil */
    v255 = list3(v256, v168, v255);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-4];
    v255 = ncons(v255);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-4];
    v255 = Lrplacd(nil, stack[0], v255);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-4];
    v255 = stack[-1];
    v255 = qcdr(v255);
    stack[-1] = v255;
    goto v4;

v11:
    v255 = stack[-2];
    goto v90;

v90:
    v168 = v255;
    v255 = v168;
    if (v255 == nil) goto v59;
    v255 = v168;
    v255 = qcdr(v255);
    if (v255 == nil) goto v59;
    v255 = elt(env, 3); /* or */
    popv(5);
    return cons(v255, v168);

v59:
    v255 = v168;
    if (v255 == nil) goto v30;
    v255 = v168;
    v255 = qcar(v255);
    { popv(5); return onevalue(v255); }

v30:
    v168 = elt(env, 3); /* or */
    v255 = elt(env, 4); /* and */
    if (v168 == v255) goto v257;
    v255 = elt(env, 6); /* false */
    { popv(5); return onevalue(v255); }

v257:
    v255 = elt(env, 5); /* true */
    { popv(5); return onevalue(v255); }

v26:
    v255 = qvalue(elt(env, 1)); /* nil */
    goto v90;
/* error exit handlers */
v1:
    popv(5);
    return nil;
}



/* Code for pasf_evalatp */

static Lisp_Object CC_pasf_evalatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v10, v9, v260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_evalatp");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v10 = v31;
    v9 = v0;
/* end of prologue */
    v59 = v9;
    v59 = Lconsp(nil, v59);
    env = stack[0];
    if (v59 == nil) goto v65;
    v59 = v9;
    v260 = qcar(v59);
    v59 = elt(env, 1); /* (cong ncong) */
    v59 = Lmemq(nil, v260, v59);
    if (v59 == nil) goto v65;
    v59 = v9;
    v59 = qcdr(v59);
    if (!consp(v59)) goto v17;
    v59 = v9;
    v59 = qcdr(v59);
    v59 = qcar(v59);
    if (!consp(v59)) goto v17;
    v59 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v59 == nil)) goto v40;
    v59 = elt(env, 3); /* "pasf_evalatp : parametric modulus in input" 
*/
    v59 = ncons(v59);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[0];
    fn = elt(env, 5); /* lprie */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[0];
    goto v40;

v40:
    v59 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v261;
    v59 = nil;
    { popv(1); return onevalue(v59); }

v17:
    v59 = v9;
    v59 = qcar(v59);
    v9 = qcdr(v9);
    {
        popv(1);
        fn = elt(env, 6); /* pasf_evalatpm */
        return (*qfnn(fn))(qenv(fn), 3, v59, v10, v9);
    }

v65:
    v59 = qvalue(elt(env, 4)); /* nil */
    {
        popv(1);
        fn = elt(env, 6); /* pasf_evalatpm */
        return (*qfnn(fn))(qenv(fn), 3, v9, v10, v59);
    }
/* error exit handlers */
v261:
    popv(1);
    return nil;
}



/* Code for aex_mvar */

static Lisp_Object CC_aex_mvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mvar");
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
    v36 = v0;
/* end of prologue */
    fn = elt(env, 2); /* aex_freeids */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-1];
    stack[0] = v36;
    if (!(v36 == nil)) goto v90;
    v36 = elt(env, 1); /* "***** aex_mvar: invalid argument" */
    v36 = Lprinc(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-1];
    v36 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v262;
    goto v90;

v90:
    v36 = stack[0];
    v36 = qcar(v36);
    { popv(2); return onevalue(v36); }
/* error exit handlers */
v262:
    popv(2);
    return nil;
}



/* Code for groerevlist */

static Lisp_Object CC_groerevlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groerevlist");
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
    v69 = v0;
/* end of prologue */
    v74 = v69;
    if (!(symbolp(v74))) goto v78;
    fn = elt(env, 2); /* reval */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    goto v78;

v78:
    fn = elt(env, 3); /* getrlist */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    stack[-3] = v69;
    v69 = stack[-3];
    if (v69 == nil) goto v36;
    v69 = stack[-3];
    v69 = qcar(v69);
    fn = elt(env, 2); /* reval */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    stack[-1] = v69;
    stack[-2] = v69;
    goto v25;

v25:
    v69 = stack[-3];
    v69 = qcdr(v69);
    stack[-3] = v69;
    v69 = stack[-3];
    if (v69 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v69 = stack[-3];
    v69 = qcar(v69);
    fn = elt(env, 2); /* reval */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    v69 = Lrplacd(nil, stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    v69 = stack[-1];
    v69 = qcdr(v69);
    stack[-1] = v69;
    goto v25;

v36:
    v69 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v69); }
/* error exit handlers */
v263:
    popv(5);
    return nil;
}



/* Code for weak_xreduce */

static Lisp_Object CC_weak_xreduce(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v58, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for weak_xreduce");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v57 = qvalue(elt(env, 1)); /* nil */
    v57 = ncons(v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    stack[-2] = v57;
    v57 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v57 == nil) goto v245;
    v57 = stack[-1];
    fn = elt(env, 7); /* preppf */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v57 = Lmkquote(nil, v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    fn = elt(env, 8); /* eval */
    v183 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v58 = qvalue(elt(env, 1)); /* nil */
    v57 = nil;
    fn = elt(env, 9); /* assgnpri */
    v57 = (*qfnn(fn))(qenv(fn), 3, v183, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v57 = elt(env, 3); /* " =" */
    fn = elt(env, 8); /* eval */
    v183 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v58 = qvalue(elt(env, 1)); /* nil */
    v57 = elt(env, 4); /* last */
    fn = elt(env, 9); /* assgnpri */
    v57 = (*qfnn(fn))(qenv(fn), 3, v183, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    goto v245;

v245:
    v183 = stack[-1];
    v58 = stack[0];
    v57 = stack[-2];
    fn = elt(env, 10); /* weak_xreduce1 */
    v57 = (*qfnn(fn))(qenv(fn), 3, v183, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    stack[0] = v57;
    v57 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v57 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v57 = elt(env, 5); /* "   " */
    fn = elt(env, 8); /* eval */
    v183 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v58 = qvalue(elt(env, 1)); /* nil */
    v57 = elt(env, 6); /* first */
    fn = elt(env, 9); /* assgnpri */
    v57 = (*qfnn(fn))(qenv(fn), 3, v183, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v57 = stack[0];
    fn = elt(env, 7); /* preppf */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v57 = Lmkquote(nil, v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    fn = elt(env, 8); /* eval */
    v183 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v58 = qvalue(elt(env, 1)); /* nil */
    v57 = elt(env, 4); /* last */
    fn = elt(env, 9); /* assgnpri */
    v57 = (*qfnn(fn))(qenv(fn), 3, v183, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v257;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v257:
    popv(4);
    return nil;
}



/* Code for subsetneqp */

static Lisp_Object CC_subsetneqp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsetneqp");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v265 = stack[-1];
    v72 = stack[0];
    fn = elt(env, 2); /* subsetp */
    v72 = (*qfn2(fn))(qenv(fn), v265, v72);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    if (v72 == nil) goto v47;
    v265 = stack[0];
    v72 = stack[-1];
    fn = elt(env, 2); /* subsetp */
    v72 = (*qfn2(fn))(qenv(fn), v265, v72);
    nil = C_nil;
    if (exception_pending()) goto v254;
    v72 = (v72 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v72); }

v47:
    v72 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v72); }
/* error exit handlers */
v254:
    popv(3);
    return nil;
}



/* Code for edge_bind */

static Lisp_Object CC_edge_bind(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v222, v277;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edge_bind");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v31;
    stack[-7] = v0;
/* end of prologue */
    v221 = stack[-7];
    if (v221 == nil) goto v47;
    stack[-2] = nil;
    v221 = stack[-7];
    v221 = qcar(v221);
    v222 = v221;
    v221 = v222;
    v221 = qcdr(v221);
    stack[-1] = v221;
    v221 = v222;
    v221 = qcar(v221);
    v222 = v221;
    v221 = stack[-7];
    v221 = qcdr(v221);
    stack[-7] = v221;
    v221 = v222;
    v221 = qcar(v221);
    stack[-5] = v221;
    v221 = v222;
    v221 = qcdr(v221);
    v221 = qcar(v221);
    stack[-8] = v221;
    v221 = stack[-8];
    v222 = qcar(v221);
    v221 = stack[-6];
    v221 = Lassoc(nil, v222, v221);
    stack[-4] = v221;
    v221 = stack[-8];
    v222 = qcdr(v221);
    v221 = stack[-6];
    v221 = Lassoc(nil, v222, v221);
    stack[-3] = v221;
    v221 = stack[-4];
    if (v221 == nil) goto v29;
    v221 = stack[-3];
    if (!(v221 == nil)) goto v244;

v29:
    stack[0] = elt(env, 0); /* edge_bind */
    v222 = stack[-8];
    v221 = stack[-6];
    v221 = list2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    fn = elt(env, 3); /* set_error_real */
    v221 = (*qfn2(fn))(qenv(fn), stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    goto v244;

v244:
    v221 = stack[-4];
    v222 = qcdr(v221);
    v221 = stack[-3];
    v221 = qcdr(v221);
    v221 = cons(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    stack[-8] = v221;
    v221 = stack[-8];
    v222 = qcar(v221);
    v221 = stack[-8];
    v221 = qcdr(v221);
    v221 = difference2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    v221 = Labsval(nil, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    stack[-4] = v221;
    v221 = stack[-8];
    v222 = qcar(v221);
    v221 = stack[-8];
    v221 = qcdr(v221);
    v221 = plus2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    stack[-3] = v221;
    v221 = qvalue(elt(env, 1)); /* ndim!* */
    if (!(is_number(v221))) goto v53;
    v222 = stack[-3];
    v221 = qvalue(elt(env, 1)); /* ndim!* */
    fn = elt(env, 4); /* min */
    v221 = (*qfn2(fn))(qenv(fn), v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    stack[-3] = v221;
    v222 = stack[-4];
    v221 = qvalue(elt(env, 1)); /* ndim!* */
    v221 = (Lisp_Object)greaterp2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    v221 = v221 ? lisp_true : nil;
    env = stack[-9];
    if (v221 == nil) goto v53;
    v221 = qvalue(elt(env, 2)); /* nil */
    { popv(10); return onevalue(v221); }

v53:
    v221 = stack[-4];
    stack[-4] = v221;
    goto v236;

v236:
    v222 = stack[-4];
    v221 = stack[-3];
    v221 = (Lisp_Object)greaterp2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    v221 = v221 ? lisp_true : nil;
    env = stack[-9];
    if (!(v221 == nil)) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    stack[0] = stack[-1];
    v277 = stack[-5];
    v222 = stack[-4];
    v221 = stack[-6];
    v221 = acons(v277, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    fn = elt(env, 5); /* can_be_proved */
    v221 = (*qfn2(fn))(qenv(fn), stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    if (v221 == nil) goto v149;
    stack[0] = stack[-7];
    v277 = stack[-5];
    v222 = stack[-4];
    v221 = stack[-6];
    v221 = acons(v277, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    v222 = CC_edge_bind(env, stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    v221 = stack[-2];
    v221 = Lappend(nil, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    stack[-2] = v221;
    goto v149;

v149:
    v222 = stack[-4];
    v221 = (Lisp_Object)33; /* 2 */
    v221 = plus2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-9];
    stack[-4] = v221;
    goto v236;

v47:
    v221 = stack[-6];
    popv(10);
    return ncons(v221);
/* error exit handlers */
v278:
    popv(10);
    return nil;
}



/* Code for compactf0 */

static Lisp_Object MS_CDECL CC_compactf0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v64, v236, v284;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf0");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v51;
    stack[-6] = v31;
    stack[-1] = v0;
/* end of prologue */
    v64 = stack[-1];
    v63 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    stack[-7] = v63;
    v64 = stack[-6];
    v63 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    stack[0] = v63;
    v64 = elt(env, 2); /* !~ */
    v63 = stack[-6];
    v63 = Lsmemq(nil, v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    if (v63 == nil) goto v28;
    v64 = stack[-7];
    v63 = stack[0];
    fn = elt(env, 4); /* compactfmatch */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    stack[-3] = v63;
    goto v44;

v44:
    v63 = stack[-3];
    if (v63 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v63 = stack[-3];
    v63 = qcar(v63);
    stack[-2] = v63;
    v63 = stack[-2];
    if (v63 == nil) goto v260;
    stack[0] = elt(env, 2); /* !~ */
    v64 = stack[-2];
    v63 = stack[-5];
    v63 = Lsublis(nil, v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    stack[-4] = v63;
    v63 = Lsmemq(nil, stack[0], v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    if (!(v63 == nil)) goto v260;
    v63 = stack[-4];
    fn = elt(env, 5); /* eval */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    if (v63 == nil) goto v260;
    stack[0] = elt(env, 2); /* !~ */
    v64 = stack[-6];
    v63 = stack[-2];
    fn = elt(env, 6); /* subf */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    v63 = qcar(v63);
    stack[-4] = v63;
    v63 = Lsmemq(nil, stack[0], v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    if (!(v63 == nil)) goto v260;
    stack[-2] = stack[-1];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v64 = stack[-4];
    v63 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    fn = elt(env, 7); /* compactf1 */
    v63 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v63);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-8];
    stack[-1] = v63;
    goto v260;

v260:
    v63 = stack[-3];
    v63 = qcdr(v63);
    stack[-3] = v63;
    goto v44;

v28:
    v284 = stack[-1];
    v236 = stack[-6];
    v64 = stack[-7];
    v63 = stack[0];
    {
        popv(9);
        fn = elt(env, 7); /* compactf1 */
        return (*qfnn(fn))(qenv(fn), 4, v284, v236, v64, v63);
    }
/* error exit handlers */
v285:
    popv(9);
    return nil;
}



/* Code for mod!* */

static Lisp_Object CC_modH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod*");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v28 = stack[0];
    fn = elt(env, 2); /* dpmat_coldegs */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    stack[-2] = qvalue(elt(env, 1)); /* cali!=degrees */
    qvalue(elt(env, 1)) = v28; /* cali!=degrees */
    v28 = stack[-1];
    fn = elt(env, 3); /* dp_neworder */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    stack[-1] = v28;
    v28 = stack[0];
    fn = elt(env, 4); /* dpmat_list */
    stack[0] = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    v27 = (Lisp_Object)1; /* 0 */
    v28 = stack[-1];
    fn = elt(env, 5); /* bas_make */
    v28 = (*qfn2(fn))(qenv(fn), v27, v28);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    fn = elt(env, 6); /* red_redpol */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    stack[0] = v28;
    v28 = stack[0];
    v28 = qcar(v28);
    fn = elt(env, 7); /* bas_dpoly */
    v27 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    v28 = stack[0];
    v28 = qcdr(v28);
    v28 = cons(v27, v28);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* cali!=degrees */
    { popv(4); return onevalue(v28); }
/* error exit handlers */
v60:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* cali!=degrees */
    popv(4);
    return nil;
v171:
    popv(4);
    return nil;
}



/* Code for put!-avalue */

static Lisp_Object MS_CDECL CC_putKavalue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v293, v294, v295, v296, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "put-avalue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for put-avalue");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v51;
    stack[-2] = v31;
    stack[0] = v0;
/* end of prologue */
    v294 = stack[-2];
    v293 = elt(env, 1); /* scalar */
    if (v294 == v293) goto v262;
    v294 = stack[0];
    v293 = stack[-1];
    fn = elt(env, 9); /* smember */
    v293 = (*qfn2(fn))(qenv(fn), v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    if (v293 == nil) goto v49;
    v228 = qvalue(elt(env, 3)); /* nil */
    v296 = stack[0];
    v295 = elt(env, 4); /* "improperly defined in terms of itself" */
    v294 = qvalue(elt(env, 3)); /* nil */
    v293 = qvalue(elt(env, 5)); /* t */
    {
        popv(5);
        fn = elt(env, 10); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v228, v296, v295, v294, v293);
    }

v49:
    stack[-3] = stack[0];
    stack[0] = elt(env, 8); /* avalue */
    v294 = stack[-2];
    v293 = stack[-1];
    v293 = list2(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v297;
    {
        Lisp_Object v231 = stack[-3];
        Lisp_Object v163 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v231, v163, v293);
    }

v262:
    v294 = stack[-1];
    v293 = elt(env, 2); /* !*sq */
    if (!consp(v294)) goto v35;
    v294 = qcar(v294);
    if (!(v294 == v293)) goto v35;
    v294 = stack[0];
    v293 = stack[-1];
    v293 = qcdr(v293);
    v293 = qcar(v293);
    v293 = qcar(v293);
    fn = elt(env, 11); /* sf_member */
    v293 = (*qfn2(fn))(qenv(fn), v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    if (!(v293 == nil)) goto v44;
    v294 = stack[0];
    v293 = stack[-1];
    v293 = qcdr(v293);
    v293 = qcar(v293);
    v293 = qcdr(v293);
    fn = elt(env, 11); /* sf_member */
    v293 = (*qfn2(fn))(qenv(fn), v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    if (!(v293 == nil)) goto v44;

v35:
    v293 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v293 == nil) goto v8;
    v295 = stack[0];
    v294 = stack[-1];
    v293 = elt(env, 7); /* generic */
    {
        popv(5);
        fn = elt(env, 12); /* putobject */
        return (*qfnn(fn))(qenv(fn), 3, v295, v294, v293);
    }

v8:
    stack[-3] = stack[0];
    stack[0] = elt(env, 8); /* avalue */
    v294 = stack[-2];
    v293 = stack[-1];
    v293 = list2(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v297;
    {
        Lisp_Object v298 = stack[-3];
        Lisp_Object v299 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v298, v299, v293);
    }

v44:
    v228 = qvalue(elt(env, 3)); /* nil */
    v296 = stack[0];
    v295 = elt(env, 4); /* "improperly defined in terms of itself" */
    v294 = qvalue(elt(env, 3)); /* nil */
    v293 = qvalue(elt(env, 5)); /* t */
    {
        popv(5);
        fn = elt(env, 10); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v228, v296, v295, v294, v293);
    }
/* error exit handlers */
v297:
    popv(5);
    return nil;
}



/* Code for restorealldfs */

static Lisp_Object CC_restorealldfs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v292, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for restorealldfs");
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
    v292 = v0;
/* end of prologue */
    fn = elt(env, 2); /* fullcopy */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[-2] = v292;
    v292 = stack[-2];
    stack[-1] = v292;
    goto v4;

v4:
    v292 = stack[-2];
    if (!consp(v292)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v292 = stack[-2];
    v292 = qcar(v292);
    if (!consp(v292)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v292 = stack[-2];
    v292 = qcar(v292);
    v292 = qcar(v292);
    v292 = qcar(v292);
    if (!consp(v292)) goto v16;
    v292 = stack[-2];
    v292 = qcar(v292);
    v292 = qcar(v292);
    v292 = qcar(v292);
    v250 = qcar(v292);
    v292 = elt(env, 1); /* translate2 */
    v292 = get(v250, v292);
    env = stack[-3];
    v250 = v292;
    if (v292 == nil) goto v16;
    v292 = stack[-2];
    v292 = qcar(v292);
    stack[0] = qcar(v292);
    v292 = v250;
    v250 = qcar(v292);
    v292 = stack[-2];
    v292 = qcar(v292);
    v292 = qcar(v292);
    v292 = qcar(v292);
    v292 = Lapply1(nil, v250, v292);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v292 = (*qfn2(fn))(qenv(fn), stack[0], v292);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    goto v16;

v16:
    v292 = stack[-2];
    v292 = qcar(v292);
    v292 = qcdr(v292);
    stack[-2] = v292;
    goto v4;
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for makemainvar */

static Lisp_Object CC_makemainvar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makemainvar");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v172 = stack[-1];
    if (!consp(v172)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v172 = stack[-1];
    v172 = qcar(v172);
    if (!consp(v172)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v173 = stack[0];
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcar(v172);
    if (equal(v173, v172)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v172 = stack[-1];
    v172 = qcar(v172);
    v173 = qcdr(v172);
    v172 = stack[0];
    v59 = CC_makemainvar(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-3];
    v172 = stack[-1];
    v172 = qcar(v172);
    v173 = qcar(v172);
    v172 = stack[0];
    fn = elt(env, 1); /* mulcoeffsby */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v59, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-3];
    v172 = stack[-1];
    v173 = qcdr(v172);
    v172 = stack[0];
    v173 = CC_makemainvar(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-3];
    v172 = stack[0];
    {
        Lisp_Object v275 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* mergeadd */
        return (*qfnn(fn))(qenv(fn), 3, v275, v173, v172);
    }
/* error exit handlers */
v261:
    popv(4);
    return nil;
}



/* Code for constant_exprp */

static Lisp_Object CC_constant_exprp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v301, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constant_exprp");
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
    v301 = v0;
/* end of prologue */
    v1 = v301;
    if (!consp(v1)) goto v77;
    v1 = v301;
    v21 = qcar(v1);
    v1 = elt(env, 5); /* realvalued */
    v1 = Lflagp(nil, v21, v1);
    env = stack[0];
    if (!(v1 == nil)) goto v14;
    v1 = v301;
    v21 = qcar(v1);
    v1 = elt(env, 6); /* alwaysrealvalued */
    v1 = Lflagp(nil, v21, v1);
    env = stack[0];
    if (!(v1 == nil)) goto v14;
    v1 = v301;
    v21 = qcar(v1);
    v1 = elt(env, 7); /* (plus minus difference times quotient) */
    v1 = Lmemq(nil, v21, v1);
    if (!(v1 == nil)) goto v14;
    v1 = v301;
    v21 = qcar(v1);
    v1 = elt(env, 8); /* !:rd!: */
    v1 = get(v21, v1);
    env = stack[0];
    if (!(v1 == nil)) goto v14;
    v1 = qvalue(elt(env, 9)); /* !*complex */
    if (v1 == nil) goto v15;
    v1 = v301;
    v21 = qcar(v1);
    v1 = elt(env, 10); /* !:cr!: */
    v1 = get(v21, v1);
    env = stack[0];
    if (!(v1 == nil)) goto v14;

v15:
    v1 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v1); }

v14:
    v1 = v301;
    v1 = qcdr(v1);
    if (!consp(v1)) goto v291;
    v1 = v301;
    v1 = qcdr(v1);
    {
        popv(1);
        fn = elt(env, 11); /* constant_expr_listp */
        return (*qfn1(fn))(qenv(fn), v1);
    }

v291:
    v1 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v1); }

v77:
    v1 = v301;
    v1 = (is_number(v1) ? lisp_true : nil);
    if (!(v1 == nil)) { popv(1); return onevalue(v1); }
    v21 = v301;
    v1 = elt(env, 1); /* constant */
    v1 = Lflagp(nil, v21, v1);
    env = stack[0];
    if (!(v1 == nil)) { popv(1); return onevalue(v1); }
    v1 = elt(env, 2); /* i */
    if (v301 == v1) goto v62;
    v1 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v1); }

v62:
    v1 = elt(env, 2); /* i */
    v301 = elt(env, 4); /* idvalfn */
    popv(1);
    return get(v1, v301);
}



/* Code for znumr */

static Lisp_Object CC_znumr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v252, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for znumr");
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
    v252 = v0;
/* end of prologue */
    v180 = v252;
    v180 = qcar(v180);
    v252 = v180;
    v180 = (v180 == nil ? lisp_true : nil);
    if (!(v180 == nil)) { popv(1); return onevalue(v180); }
    v180 = v252;
    if (is_number(v180)) goto v209;
    v180 = qvalue(elt(env, 1)); /* nil */
    goto v33;

v33:
    if (!(v180 == nil)) { popv(1); return onevalue(v180); }
    v180 = v252;
    if (!consp(v180)) goto v262;
    v180 = v252;
    if (!consp(v180)) goto v62;
    v180 = v252;
    v180 = qcar(v180);
    if (!consp(v180)) goto v62;
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v180); }

v62:
    v180 = v252;
    v29 = qcar(v180);
    v180 = elt(env, 2); /* zerop */
    v180 = get(v29, v180);
    env = stack[0];
    v29 = v180;
    v180 = v29;
    if (v180 == nil) goto v15;
    v180 = v29;
        popv(1);
        return Lapply1(nil, v180, v252);

v15:
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v180); }

v262:
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v180); }

v209:
    v180 = v252;
    v180 = (Lisp_Object)zerop(v180);
    v180 = v180 ? lisp_true : nil;
    env = stack[0];
    goto v33;
}



/* Code for ofsf_qesubiord */

static Lisp_Object MS_CDECL CC_ofsf_qesubiord(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v51, Lisp_Object v78, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v72, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_qesubiord");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubiord");
#endif
    if (stack >= stacklimit)
    {
        push4(v78,v51,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v31,v51,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v78;
    stack[-1] = v51;
    v213 = v31;
    v72 = v0;
/* end of prologue */
    stack[-2] = v72;
    v72 = v213;
    v213 = stack[-1];
    fn = elt(env, 1); /* sfto_reorder */
    v265 = (*qfn2(fn))(qenv(fn), v72, v213);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    v72 = stack[-1];
    v213 = stack[0];
    {
        Lisp_Object v210 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* ofsf_qesubiord1 */
        return (*qfnn(fn))(qenv(fn), 4, v210, v265, v72, v213);
    }
/* error exit handlers */
v17:
    popv(4);
    return nil;
}



/* Code for ofsf_smmkatl!-and1 */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKand1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v304, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-and1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and1");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v51;
    stack[0] = v31;
    stack[-6] = v0;
/* end of prologue */
    v234 = stack[0];
    v304 = qcar(v234);
    v234 = (Lisp_Object)17; /* 1 */
    v234 = cons(v304, v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-7] = v234;
    v234 = stack[0];
    v234 = qcdr(v234);
    stack[-4] = v234;
    goto v20;

v20:
    v234 = stack[-4];
    if (v234 == nil) goto v265;
    v234 = stack[-4];
    v234 = qcar(v234);
    stack[0] = v234;
    v234 = stack[0];
    v304 = qcar(v234);
    v234 = stack[-5];
    if (equal(v304, v234)) goto v69;
    v234 = nil;
    goto v62;

v62:
    stack[-3] = v234;
    v234 = stack[-3];
    fn = elt(env, 4); /* lastpair */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-2] = v234;
    v234 = stack[-4];
    v234 = qcdr(v234);
    stack[-4] = v234;
    v234 = stack[-2];
    if (!consp(v234)) goto v20;
    else goto v19;

v19:
    v234 = stack[-4];
    if (v234 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v234 = stack[-4];
    v234 = qcar(v234);
    stack[0] = v234;
    v234 = stack[0];
    v304 = qcar(v234);
    v234 = stack[-5];
    if (equal(v304, v234)) goto v50;
    v234 = nil;
    goto v68;

v68:
    v234 = Lrplacd(nil, stack[-1], v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v234 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-2] = v234;
    v234 = stack[-4];
    v234 = qcdr(v234);
    stack[-4] = v234;
    goto v19;

v50:
    v234 = stack[0];
    v234 = qcdr(v234);
    v304 = qcar(v234);
    v234 = elt(env, 2); /* (lessp greaterp) */
    v234 = Lmemq(nil, v304, v234);
    if (v234 == nil) goto v305;
    v234 = stack[-6];
    v181 = qcdr(v234);
    v234 = stack[0];
    v304 = qcdr(v234);
    v234 = stack[-7];
    fn = elt(env, 5); /* ofsf_smmkat!-and2 */
    v234 = (*qfnn(fn))(qenv(fn), 3, v181, v304, v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v304 = v234;
    if (v234 == nil) goto v305;
    v234 = v304;
    v234 = ncons(v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    goto v68;

v305:
    v181 = elt(env, 3); /* and */
    v234 = stack[0];
    v304 = qcdr(v234);
    v234 = stack[-7];
    fn = elt(env, 6); /* ofsf_entry2at */
    v234 = (*qfnn(fn))(qenv(fn), 3, v181, v304, v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v234 = ncons(v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    goto v68;

v69:
    v234 = stack[0];
    v234 = qcdr(v234);
    v304 = qcar(v234);
    v234 = elt(env, 2); /* (lessp greaterp) */
    v234 = Lmemq(nil, v304, v234);
    if (v234 == nil) goto v251;
    v234 = stack[-6];
    v181 = qcdr(v234);
    v234 = stack[0];
    v304 = qcdr(v234);
    v234 = stack[-7];
    fn = elt(env, 5); /* ofsf_smmkat!-and2 */
    v234 = (*qfnn(fn))(qenv(fn), 3, v181, v304, v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v304 = v234;
    if (v234 == nil) goto v251;
    v234 = v304;
    v234 = ncons(v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    goto v62;

v251:
    v181 = elt(env, 3); /* and */
    v234 = stack[0];
    v304 = qcdr(v234);
    v234 = stack[-7];
    fn = elt(env, 6); /* ofsf_entry2at */
    v234 = (*qfnn(fn))(qenv(fn), 3, v181, v304, v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v234 = ncons(v234);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    goto v62;

v265:
    v234 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v234); }
/* error exit handlers */
v270:
    popv(9);
    return nil;
}



/* Code for available!*p */

static Lisp_Object CC_availableHp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for available*p");
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
    v72 = stack[0];
    if (symbolp(v72)) goto v37;
    v72 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v72 == nil)) goto v16;
    v72 = elt(env, 2); /* "this is no group identifier" */
    fn = elt(env, 4); /* lprie */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    goto v16;

v16:
    v72 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    goto v37;

v37:
    v72 = stack[0];
    v265 = elt(env, 3); /* available */
        popv(2);
        return Lflagp(nil, v72, v265);
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for pasf_leqp */

static Lisp_Object CC_pasf_leqp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v292, v250, v258;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_leqp");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v292 = v31;
    v250 = v0;
/* end of prologue */
    v65 = v250;
    if (!(v65 == nil)) goto v90;
    v65 = (Lisp_Object)1; /* 0 */
    v250 = v65;
    goto v90;

v90:
    v65 = v292;
    if (!(v65 == nil)) goto v20;
    v65 = (Lisp_Object)1; /* 0 */
    v292 = v65;
    goto v20;

v20:
    v258 = v250;
    v65 = elt(env, 1); /* minf */
    if (v258 == v65) goto v36;
    v258 = v292;
    v65 = elt(env, 2); /* pinf */
    if (v258 == v65) goto v36;
    v258 = v250;
    v65 = elt(env, 2); /* pinf */
    if (v258 == v65) goto v37;
    v258 = v292;
    v65 = elt(env, 1); /* minf */
    if (v258 == v65) goto v37;
    v65 = v250;
    v65 = (Lisp_Object)lesseq2(v65, v292);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v65 = v65 ? lisp_true : nil;
    env = stack[0];
    if (!(v65 == nil)) goto v36;

v37:
    v65 = nil;
    { popv(1); return onevalue(v65); }

v36:
    v65 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v65); }
/* error exit handlers */
v172:
    popv(1);
    return nil;
}



/* Code for radf1 */

static Lisp_Object CC_radf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v162, v308;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for radf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v31;
    v162 = v0;
/* end of prologue */
    stack[-4] = nil;
    v237 = (Lisp_Object)17; /* 1 */
    stack[-6] = v237;
    v237 = v162;
    stack[-2] = v237;
    goto v16;

v16:
    v237 = stack[-2];
    if (v237 == nil) goto v64;
    v237 = stack[-2];
    v237 = qcar(v237);
    stack[-1] = v237;
    v237 = stack[-1];
    v162 = qcdr(v237);
    v237 = stack[-5];
    v237 = Ldivide(nil, v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    stack[-3] = v237;
    v237 = stack[-3];
    v162 = qcar(v237);
    v237 = (Lisp_Object)1; /* 0 */
    if (v162 == v237) goto v57;
    v162 = stack[-1];
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    stack[0] = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    v237 = stack[-1];
    v162 = qcar(v237);
    v237 = stack[-3];
    v237 = qcar(v237);
    fn = elt(env, 3); /* exptf */
    v162 = (*qfn2(fn))(qenv(fn), v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    v237 = stack[-5];
    fn = elt(env, 4); /* check!-radf!-sign */
    v162 = (*qfnn(fn))(qenv(fn), 3, stack[0], v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    v237 = stack[-6];
    fn = elt(env, 5); /* multf */
    v237 = (*qfn2(fn))(qenv(fn), v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    stack[-6] = v237;
    goto v57;

v57:
    v237 = stack[-3];
    v162 = qcdr(v237);
    v237 = (Lisp_Object)1; /* 0 */
    if (v162 == v237) goto v169;
    v237 = stack[-1];
    v162 = qcar(v237);
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    fn = elt(env, 6); /* prepsq!* */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    v162 = v237;
    v237 = stack[-3];
    v308 = qcdr(v237);
    v237 = (Lisp_Object)17; /* 1 */
    if (v308 == v237) goto v54;
    v308 = elt(env, 2); /* expt */
    v237 = stack[-3];
    v237 = qcdr(v237);
    v237 = list3(v308, v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    v162 = v237;
    goto v290;

v290:
    v237 = stack[-4];
    v237 = cons(v162, v237);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-7];
    stack[-4] = v237;
    goto v169;

v169:
    v237 = stack[-2];
    v237 = qcdr(v237);
    stack[-2] = v237;
    goto v16;

v54:
    v237 = v162;
    v162 = v237;
    goto v290;

v64:
    v162 = stack[-6];
    v237 = stack[-4];
    popv(8);
    return cons(v162, v237);
/* error exit handlers */
v309:
    popv(8);
    return nil;
}



/* Code for ps!:minus!-erule */

static Lisp_Object CC_psTminusKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:minus-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v212 = v31;
    v213 = v0;
/* end of prologue */
    v213 = qcdr(v213);
    v213 = qcar(v213);
    fn = elt(env, 1); /* ps!:evaluate */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-1];
    stack[0] = v212;
    v212 = stack[0];
    v212 = qcar(v212);
    fn = elt(env, 2); /* negf */
    v213 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v265;
    v212 = stack[0];
    v212 = qcdr(v212);
    popv(2);
    return cons(v213, v212);
/* error exit handlers */
v265:
    popv(2);
    return nil;
}



/* Code for to!*scheme */

static Lisp_Object CC_toHscheme(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v339, v340, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for to*scheme");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)49; /* 3 */
    v339 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    if (is_number(v339)) goto v3;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)33; /* 2 */
    v340 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = elt(env, 3); /* plus */
    if (!(v340 == v339)) goto v3;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)65; /* 4 */
    v339 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v340 = Llength(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v339 = (Lisp_Object)17; /* 1 */
    if (!(v340 == v339)) goto v3;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)81; /* 5 */
    v339 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    if (!(v339 == nil)) goto v3;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)65; /* 4 */
    v339 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = qcar(v339);
    stack[-7] = v339;
    v339 = stack[-7];
    v339 = qcar(v339);
    stack[-5] = v339;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)97; /* 6 */
    v339 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    stack[-4] = v339;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    stack[0] = (Lisp_Object)97; /* 6 */
    v339 = stack[-7];
    v339 = qcdr(v339);
    v340 = qcar(v339);
    v339 = stack[-4];
    fn = elt(env, 7); /* dm!-expt */
    v339 = (*qfn2(fn))(qenv(fn), v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v339;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-5];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)49; /* 3 */
    stack[-3] = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    stack[-2] = elt(env, 4); /* varlst!* */
    stack[-1] = elt(env, 5); /* times */
    stack[0] = stack[-6];
    v340 = stack[-4];
    v339 = stack[-7];
    v339 = qcdr(v339);
    v339 = qcdr(v339);
    v339 = cons(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    fn = elt(env, 8); /* getcind */
    v339 = (*qfnn(fn))(qenv(fn), 5, stack[-3], stack[-2], stack[-1], stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    stack[-7] = v339;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-5];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    stack[-3] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    stack[-2] = (Lisp_Object)65; /* 4 */
    stack[-1] = stack[-6];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-5];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)65; /* 4 */
    v339 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    fn = elt(env, 9); /* delyzz */
    v339 = (*qfn2(fn))(qenv(fn), stack[-1], v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v339;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    stack[0] = (Lisp_Object)65; /* 4 */
    v339 = stack[-7];
    v339 = ncons(v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v339;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v340 = qvalue(elt(env, 2)); /* maxvar */
    v339 = stack[-6];
    v339 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-8];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL)));
    v339 = (Lisp_Object)33; /* 2 */
    v192 = elt(env, 5); /* times */
    *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v339/(16/CELL))) = v192;
    goto v3;

v3:
    v339 = nil;
    { popv(9); return onevalue(v339); }
/* error exit handlers */
v341:
    popv(9);
    return nil;
}



/* Code for dip2a1 */

static Lisp_Object CC_dip2a1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip2a1");
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
    stack[-4] = nil;
    goto v47;

v47:
    v173 = stack[-3];
    if (v173 == nil) goto v3;
    v173 = stack[-3];
    v173 = qcdr(v173);
    stack[0] = qcar(v173);
    v173 = stack[-3];
    v173 = qcar(v173);
    fn = elt(env, 2); /* expvec2a */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    stack[-2] = stack[0];
    stack[-1] = v173;
    v173 = stack[-2];
    fn = elt(env, 3); /* bcminus!? */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    if (v173 == nil) goto v12;
    stack[0] = elt(env, 1); /* minus */
    v173 = stack[-2];
    fn = elt(env, 4); /* bcneg */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    fn = elt(env, 5); /* bc2a */
    v59 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    v173 = stack[-1];
    v173 = cons(v59, v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    fn = elt(env, 6); /* dipretimes */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    v173 = list2(stack[0], v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    v59 = v173;
    goto v35;

v35:
    v173 = stack[-4];
    v173 = cons(v59, v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    stack[-4] = v173;
    v173 = stack[-3];
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    stack[-3] = v173;
    goto v47;

v12:
    v173 = stack[-2];
    fn = elt(env, 5); /* bc2a */
    v59 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    v173 = stack[-1];
    v173 = cons(v59, v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    fn = elt(env, 6); /* dipretimes */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-5];
    v59 = v173;
    goto v35;

v3:
    v173 = stack[-4];
    {
        popv(6);
        fn = elt(env, 7); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v173);
    }
/* error exit handlers */
v264:
    popv(6);
    return nil;
}



/* Code for round!:dec1 */

static Lisp_Object CC_roundTdec1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v383, v100, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round:dec1");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-11] = v31;
    stack[-12] = v0;
/* end of prologue */
    v383 = stack[-12];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = (Lisp_Object)1; /* 0 */
    if (v100 == v383) goto v47;
    v383 = qvalue(elt(env, 1)); /* !:bprec!: */
    stack[-13] = qvalue(elt(env, 1)); /* !:bprec!: */
    qvalue(elt(env, 1)) = v383; /* !:bprec!: */
    stack[-10] = nil;
    stack[-8] = nil;
    v383 = stack[-12];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = (Lisp_Object)1; /* 0 */
    v383 = (Lisp_Object)lessp2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v383 = v383 ? lisp_true : nil;
    env = stack[-14];
    if (v383 == nil) goto v9;
    v383 = qvalue(elt(env, 2)); /* t */
    stack[-8] = v383;
    stack[0] = elt(env, 3); /* !:rd!: */
    v383 = stack[-12];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    v100 = negate(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = stack[-12];
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = list2star(stack[0], v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-12] = v383;
    goto v9;

v9:
    v383 = stack[-12];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = (Lisp_Object)1; /* 0 */
    if (v100 == v383) goto v59;
    v383 = stack[-12];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    v383 = Labsval(nil, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = stack[-12];
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = sub1(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = plus2(stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    goto v173;

v173:
    stack[-6] = v383;
    v383 = stack[-6];
    v383 = Labsval(nil, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-5] = v383;
    stack[0] = qvalue(elt(env, 4)); /* !!nbfpd */
    v100 = stack[-5];
    v383 = (Lisp_Object)113; /* 7 */
    v383 = plus2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    fn = elt(env, 10); /* max */
    v383 = (*qfn2(fn))(qenv(fn), stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-4] = qvalue(elt(env, 1)); /* !:bprec!: */
    qvalue(elt(env, 1)) = v383; /* !:bprec!: */
    v383 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 11); /* !:log2 */
    stack[0] = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v383 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 12); /* !:log10 */
    v100 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v383 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 13); /* divide!: */
    v383 = (*qfnn(fn))(qenv(fn), 3, stack[0], v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    stack[-9] = v383;
    v101 = elt(env, 3); /* !:rd!: */
    v100 = stack[-6];
    v383 = (Lisp_Object)1; /* 0 */
    v383 = list2star(v101, v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    stack[-2] = v383;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v383 = stack[-2];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = stack[-9];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    stack[0] = times2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v383 = stack[-2];
    v383 = qcdr(v383);
    v100 = qcdr(v383);
    v383 = stack[-9];
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = plus2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v383 = list2star(stack[-1], stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v100 = v383;
    v100 = qcdr(v100);
    v100 = qcar(v100);
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = Lash1(nil, v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    stack[-7] = v383;
    stack[-3] = stack[-7];
    stack[0] = elt(env, 3); /* !:rd!: */
    v383 = stack[-6];
    v100 = add1(v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v383 = (Lisp_Object)1; /* 0 */
    v383 = list2star(stack[0], v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    stack[-2] = v383;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v383 = stack[-2];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = stack[-9];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    stack[0] = times2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v383 = stack[-2];
    v383 = qcdr(v383);
    v100 = qcdr(v383);
    v383 = stack[-9];
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = plus2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v383 = list2star(stack[-1], stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    v100 = v383;
    v100 = qcdr(v100);
    v100 = qcar(v100);
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = Lash1(nil, v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-14];
    if (!(equal(stack[-3], v383))) goto v385;
    v383 = qvalue(elt(env, 2)); /* t */
    stack[-10] = v383;
    goto v385;

v385:
    qvalue(elt(env, 1)) = stack[-4]; /* !:bprec!: */
    v100 = qvalue(elt(env, 1)); /* !:bprec!: */
    v383 = stack[-5];
    v383 = plus2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    qvalue(elt(env, 1)) = v383; /* !:bprec!: */
    v100 = stack[-6];
    v383 = (Lisp_Object)1; /* 0 */
    v383 = (Lisp_Object)lessp2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v383 = v383 ? lisp_true : nil;
    env = stack[-14];
    if (v383 == nil) goto v323;
    v383 = stack[-7];
    v383 = sub1(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-7] = v383;
    goto v323;

v323:
    v100 = stack[-7];
    v383 = stack[-11];
    v383 = difference2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = add1(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-1] = v383;
    v100 = stack[-1];
    v383 = (Lisp_Object)1; /* 0 */
    v383 = (Lisp_Object)lessp2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v383 = v383 ? lisp_true : nil;
    env = stack[-14];
    if (v383 == nil) goto v318;
    stack[0] = stack[-12];
    v383 = stack[-1];
    v383 = negate(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    fn = elt(env, 14); /* multiply!-by!-power!-of!-ten */
    v383 = (*qfn2(fn))(qenv(fn), stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-12] = v383;
    goto v326;

v326:
    v383 = stack[-10];
    if (!(v383 == nil)) goto v386;
    v383 = stack[-12];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = stack[-12];
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = Lash1(nil, v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = Lexplode(nil, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = Llength(nil, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-5] = v383;
    v100 = stack[-5];
    v383 = stack[-11];
    v383 = (Lisp_Object)lessp2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v383 = v383 ? lisp_true : nil;
    env = stack[-14];
    if (v383 == nil) goto v387;
    v383 = qvalue(elt(env, 6)); /* bften!* */
    stack[-3] = v383;
    stack[-2] = elt(env, 3); /* !:rd!: */
    v383 = stack[-12];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = stack[-3];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    stack[0] = times2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = stack[-12];
    v383 = qcdr(v383);
    v100 = qcdr(v383);
    v383 = stack[-3];
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = plus2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = list2star(stack[-2], stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-12] = v383;
    v383 = stack[-1];
    v383 = sub1(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-1] = v383;
    goto v386;

v386:
    v100 = stack[-12];
    v383 = qvalue(elt(env, 7)); /* bfhalf!* */
    fn = elt(env, 15); /* plus!: */
    v383 = (*qfn2(fn))(qenv(fn), v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-12] = v383;
    stack[0] = stack[-12];
    v100 = elt(env, 8); /* 0.1 */
    v383 = (Lisp_Object)289; /* 18 */
    v383 = Lexpt(nil, v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    fn = elt(env, 16); /* fl2bf */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    fn = elt(env, 15); /* plus!: */
    v383 = (*qfn2(fn))(qenv(fn), stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-12] = v383;
    v383 = stack[-12];
    v383 = qcdr(v383);
    v100 = qcar(v383);
    v383 = stack[-12];
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = Lash1(nil, v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[0] = v383;
    v383 = stack[0];
    v383 = Lexplode(nil, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v100 = Llength(nil, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = stack[-11];
    v383 = (Lisp_Object)greaterp2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v383 = v383 ? lisp_true : nil;
    env = stack[-14];
    if (v383 == nil) goto v388;
    v100 = stack[0];
    v383 = (Lisp_Object)81; /* 5 */
    v100 = plus2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    v383 = (Lisp_Object)161; /* 10 */
    v383 = quot2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[0] = v383;
    v383 = stack[-1];
    v383 = add1(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-1] = v383;
    goto v388;

v388:
    v383 = stack[-8];
    if (v383 == nil) goto v389;
    v383 = stack[0];
    v383 = negate(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[0] = v383;
    goto v389;

v389:
    v100 = stack[0];
    v383 = stack[-1];
    v383 = cons(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    qvalue(elt(env, 1)) = stack[-13]; /* !:bprec!: */
    { popv(15); return onevalue(v383); }

v387:
    v100 = stack[-5];
    v383 = stack[-11];
    v383 = (Lisp_Object)greaterp2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v383 = v383 ? lisp_true : nil;
    env = stack[-14];
    if (v383 == nil) goto v386;
    v101 = stack[-12];
    v100 = qvalue(elt(env, 6)); /* bften!* */
    v383 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 13); /* divide!: */
    v383 = (*qfnn(fn))(qenv(fn), 3, v101, v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-12] = v383;
    v383 = stack[-1];
    v383 = add1(v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-1] = v383;
    goto v386;

v318:
    v100 = stack[-1];
    v383 = (Lisp_Object)1; /* 0 */
    v383 = (Lisp_Object)greaterp2(v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v383 = v383 ? lisp_true : nil;
    env = stack[-14];
    if (v383 == nil) goto v326;
    v100 = stack[-12];
    v383 = stack[-1];
    fn = elt(env, 17); /* divide!-by!-power!-of!-ten */
    v383 = (*qfn2(fn))(qenv(fn), v100, v383);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-14];
    stack[-12] = v383;
    goto v326;

v59:
    v383 = (Lisp_Object)1; /* 0 */
    goto v173;

v47:
    v383 = stack[-12];
    v383 = qcdr(v383);
    { popv(15); return onevalue(v383); }
/* error exit handlers */
v384:
    env = stack[-14];
    qvalue(elt(env, 1)) = stack[-4]; /* !:bprec!: */
    qvalue(elt(env, 1)) = stack[-13]; /* !:bprec!: */
    popv(15);
    return nil;
v94:
    env = stack[-14];
    qvalue(elt(env, 1)) = stack[-13]; /* !:bprec!: */
    popv(15);
    return nil;
}



/* Code for declared!-as!-float */

static Lisp_Object CC_declaredKasKfloat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for declared-as-float");
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
    v42 = v0;
/* end of prologue */
    v254 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* symtabget */
    v42 = (*qfn2(fn))(qenv(fn), v254, v42);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[0];
    v254 = v42;
    if (v42 == nil) goto v4;
    v42 = v254;
    v42 = qcdr(v42);
    v42 = qcar(v42);
    v254 = elt(env, 2); /* (real real!*8 real!*16 double! precision double float) 
*/
    v42 = Lmemq(nil, v42, v254);
    { popv(1); return onevalue(v42); }

v4:
    v42 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v42); }
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for third_eq_indexp */

static Lisp_Object CC_third_eq_indexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v180, v252;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for third_eq_indexp");
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
    v252 = v0;
/* end of prologue */
    v180 = v252;
    v48 = qvalue(elt(env, 1)); /* dindices!* */
    v48 = Lassoc(nil, v180, v48);
    stack[-2] = v48;
    if (v48 == nil) goto v37;
    v48 = stack[-2];
    v48 = qcdr(v48);
    if (!(v48 == nil)) goto v90;
    stack[-1] = v252;
    stack[0] = qvalue(elt(env, 3)); /* t */
    v180 = stack[-2];
    v48 = qvalue(elt(env, 1)); /* dindices!* */
    v48 = Ldelete(nil, v180, v48);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    v48 = acons(stack[-1], stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    qvalue(elt(env, 1)) = v48; /* dindices!* */
    goto v90;

v90:
    v48 = stack[-2];
    if (v48 == nil) goto v12;
    v48 = stack[-2];
    v48 = qcdr(v48);
    { popv(4); return onevalue(v48); }

v12:
    v48 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v48); }

v37:
    v180 = qvalue(elt(env, 2)); /* nil */
    v48 = qvalue(elt(env, 1)); /* dindices!* */
    v48 = acons(v252, v180, v48);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    qvalue(elt(env, 1)) = v48; /* dindices!* */
    goto v90;
/* error exit handlers */
v250:
    popv(4);
    return nil;
}



setup_type const u58_setup[] =
{
    {"evalsymsubset",           CC_evalsymsubset,too_many_1,   wrong_no_1},
    {"all_defined",             too_few_2,      CC_all_defined,wrong_no_2},
    {"dp=prod",                 too_few_2,      CC_dpMprod,    wrong_no_2},
    {"getsetvarlis",            CC_getsetvarlis,too_many_1,    wrong_no_1},
    {"pe_inv",                  CC_pe_inv,      too_many_1,    wrong_no_1},
    {"radf",                    too_few_2,      CC_radf,       wrong_no_2},
    {"cl_pnf1",                 CC_cl_pnf1,     too_many_1,    wrong_no_1},
    {"ofsf_smdbgetrel",         too_few_2,      CC_ofsf_smdbgetrel,wrong_no_2},
    {"find-non-zero",           CC_findKnonKzero,too_many_1,   wrong_no_1},
    {"giremainder",             too_few_2,      CC_giremainder,wrong_no_2},
    {"ofsf_facequal",           CC_ofsf_facequal,too_many_1,   wrong_no_1},
    {"pasf_evalatp",            too_few_2,      CC_pasf_evalatp,wrong_no_2},
    {"aex_mvar",                CC_aex_mvar,    too_many_1,    wrong_no_1},
    {"groerevlist",             CC_groerevlist, too_many_1,    wrong_no_1},
    {"weak_xreduce",            too_few_2,      CC_weak_xreduce,wrong_no_2},
    {"subsetneqp",              too_few_2,      CC_subsetneqp, wrong_no_2},
    {"edge_bind",               too_few_2,      CC_edge_bind,  wrong_no_2},
    {"compactf0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf0},
    {"mod*",                    too_few_2,      CC_modH,       wrong_no_2},
    {"put-avalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKavalue},
    {"restorealldfs",           CC_restorealldfs,too_many_1,   wrong_no_1},
    {"makemainvar",             too_few_2,      CC_makemainvar,wrong_no_2},
    {"constant_exprp",          CC_constant_exprp,too_many_1,  wrong_no_1},
    {"znumr",                   CC_znumr,       too_many_1,    wrong_no_1},
    {"ofsf_qesubiord",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubiord},
    {"ofsf_smmkatl-and1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKand1},
    {"available*p",             CC_availableHp, too_many_1,    wrong_no_1},
    {"pasf_leqp",               too_few_2,      CC_pasf_leqp,  wrong_no_2},
    {"radf1",                   too_few_2,      CC_radf1,      wrong_no_2},
    {"ps:minus-erule",          too_few_2,      CC_psTminusKerule,wrong_no_2},
    {"to*scheme",               CC_toHscheme,   too_many_1,    wrong_no_1},
    {"dip2a1",                  CC_dip2a1,      too_many_1,    wrong_no_1},
    {"round:dec1",              too_few_2,      CC_roundTdec1, wrong_no_2},
    {"declared-as-float",       CC_declaredKasKfloat,too_many_1,wrong_no_1},
    {"third_eq_indexp",         CC_third_eq_indexp,too_many_1, wrong_no_1},
    {NULL, (one_args *)"u58", (two_args *)"3408 7686339 1126787", 0}
};

/* end of generated code */
