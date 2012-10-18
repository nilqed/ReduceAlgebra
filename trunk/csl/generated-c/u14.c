
/* $destdir\u14.c        Machine generated C code */

/* Signature: 00000000 27-Aug-2011 */

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
#ifdef OLD_VERSION
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
#else 
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF ((Lisp_Object)(int32_t)0xff000402)
#endif  
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
extern char *C_stack_limit;
extern CSLbool restartp;
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
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
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
extern int csl_argc;
extern char **csl_argv;
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
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count;
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



/* Code for chk */

static Lisp_Object CC_chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v38, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chk");
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

v57:
    v21 = stack[0];
    if (v21 == nil) goto v58;
    v38 = stack[0];
    v21 = qvalue(elt(env, 1)); /* t */
    if (v38 == v21) goto v17;
    v21 = stack[0];
    v21 = qcar(v21);
    fn = elt(env, 3); /* bsubs */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    stack[-1] = v21;
    v21 = stack[-1];
    fn = elt(env, 4); /* freexp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    if (v21 == nil) goto v60;
    v21 = stack[0];
    v21 = qcdr(v21);
    v21 = CC_chk(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v38 = v21;
    v21 = v38;
    if (v21 == nil) goto v61;
    v21 = v38;
    v37 = qvalue(elt(env, 1)); /* t */
    if (v21 == v37) goto v62;
    v21 = stack[-1];
    popv(3);
    return cons(v21, v38);

v62:
    v21 = stack[-1];
    popv(3);
    return ncons(v21);

v61:
    v21 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v21); }

v60:
    v21 = stack[-1];
    fn = elt(env, 5); /* reval */
    v38 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v21 = qvalue(elt(env, 1)); /* t */
    if (v38 == v21) goto v63;
    v21 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v21); }

v63:
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v57;

v17:
    v21 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v21); }

v58:
    v21 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v21); }
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for add_minus */

static Lisp_Object CC_add_minus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v88;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_minus");
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
    v29 = stack[-1];
    if (!consp(v29)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v29 = stack[-1];
    v88 = qcar(v29);
    v29 = elt(env, 1); /* !:rd!: */
    if (v88 == v29) goto v89;
    v29 = qvalue(elt(env, 2)); /* nil */
    goto v16;

v16:
    if (!(v29 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v29 = stack[-1];
    v88 = qcar(v29);
    v29 = elt(env, 1); /* !:rd!: */
    if (v88 == v29) goto v54;
    v29 = qvalue(elt(env, 2)); /* nil */
    goto v61;

v61:
    if (v29 == nil) goto v59;
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = Labsval(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v29 = cons(stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v91 = stack[-2];
        popv(4);
        return list2(v91, v29);
    }

v59:
    v29 = stack[-1];
    v88 = qcar(v29);
    v29 = elt(env, 3); /* minus */
    if (v88 == v29) goto v92;
    v29 = qvalue(elt(env, 2)); /* nil */
    goto v37;

v37:
    if (!(v29 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v29 = stack[-1];
    v88 = qcar(v29);
    v29 = elt(env, 3); /* minus */
    if (v88 == v29) goto v49;
    v29 = qvalue(elt(env, 2)); /* nil */
    goto v93;

v93:
    if (v29 == nil) goto v94;
    stack[0] = elt(env, 1); /* !:rd!: */
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = qcar(v29);
    v29 = qcdr(v29);
    v29 = Labsval(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v95 = stack[0];
        popv(4);
        return cons(v95, v29);
    }

v94:
    v29 = stack[-1];
    v88 = qcar(v29);
    v29 = elt(env, 3); /* minus */
    if (v88 == v29) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v29 = stack[-1];
    v88 = qcdr(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)lessp2(v88, v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    if (v29 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = Labsval(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v29 = cons(stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v96 = stack[-2];
        popv(4);
        return list2(v96, v29);
    }

v49:
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = qcar(v29);
    v88 = qcdr(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)lessp2(v88, v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    goto v93;

v92:
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = qcar(v29);
    v29 = (is_number(v29) ? lisp_true : nil);
    goto v37;

v54:
    v29 = stack[-1];
    v88 = qcdr(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)lessp2(v88, v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    goto v61;

v89:
    v29 = stack[-1];
    v88 = qcdr(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)geq2(v88, v29);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    goto v16;
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for fctlength */

static Lisp_Object CC_fctlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctlength");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v0;
/* end of prologue */
    fn = elt(env, 1); /* fctargs */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    errexit();
        return Llength(nil, v97);
}



/* Code for trwrite */

static Lisp_Object CC_trwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for trwrite");
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
    v27 = stack[0];
    v26 = qcar(v27);
    v27 = elt(env, 1); /* tracing */
    v27 = Lflagp(nil, v26, v27);
    env = stack[-1];
    if (v27 == nil) goto v100;
    v27 = elt(env, 3); /* "**in procedure: " */
    v27 = Lprinc(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v27 = stack[0];
    v27 = qcar(v27);
    v27 = Lprinc(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v27 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v25;

v25:
    v27 = stack[0];
    if (v27 == nil) goto v23;
    v27 = stack[0];
    v27 = qcar(v27);
    v27 = Lprinc(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v25;

v23:
    v27 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v27 = nil;
    { popv(2); return onevalue(v27); }

v100:
    v27 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v27); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for endstat */

static Lisp_Object MS_CDECL CC_endstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endstat");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    v101 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v101;
    v101 = elt(env, 2); /* end */
    fn = elt(env, 3); /* comm1 */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v15;
    v101 = stack[0];
    popv(1);
    return ncons(v101);
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for evalequal */

static Lisp_Object CC_evalequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v102;
    stack[-2] = v0;
/* end of prologue */
    v107 = stack[-2];
    fn = elt(env, 3); /* getrtype */
    stack[0] = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    stack[-3] = stack[0];
    v107 = stack[-1];
    fn = elt(env, 3); /* getrtype */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    if (equal(stack[0], v107)) goto v101;
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v107); }

v101:
    v107 = stack[-3];
    if (v107 == nil) goto v25;
    v108 = stack[-2];
    v107 = stack[-1];
    v107 = (equal(v108, v107) ? lisp_true : nil);
    { popv(5); return onevalue(v107); }

v25:
    v109 = elt(env, 2); /* difference */
    v108 = stack[-2];
    v107 = stack[-1];
    v107 = list3(v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    fn = elt(env, 4); /* reval */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    stack[-3] = v107;
    if (is_number(v107)) goto v61;
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v107); }

v61:
    v107 = stack[-3];
        popv(5);
        return Lzerop(nil, v107);
/* error exit handlers */
v110:
    popv(5);
    return nil;
}



/* Code for listtest */

static Lisp_Object MS_CDECL CC_listtest(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113, v62;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "listtest");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listtest");
#endif
    if (stack >= stacklimit)
    {
        push3(v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v102,v111);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v111;
    stack[-1] = v102;
    stack[-2] = v0;
/* end of prologue */

v114:
    v112 = stack[-2];
    if (v112 == nil) goto v101;
    v62 = stack[0];
    v112 = stack[-2];
    v113 = qcar(v112);
    v112 = stack[-1];
    v112 = Lapply2(nil, 3, v62, v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    if (v112 == nil) goto v103;
    v112 = stack[-2];
    v112 = qcar(v112);
    if (v112 == nil) goto v25;
    v112 = stack[-2];
    v112 = qcar(v112);
    { popv(4); return onevalue(v112); }

v25:
    v112 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v112); }

v103:
    v112 = stack[-2];
    v112 = qcdr(v112);
    stack[-2] = v112;
    goto v114;

v101:
    v112 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v112); }
/* error exit handlers */
v26:
    popv(4);
    return nil;
}



/* Code for ad_numsort */

static Lisp_Object CC_ad_numsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_numsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v15 = v1;
    v1 = elt(env, 1); /* lambda_lqlbvc_3 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v15, v1);
    }
}



/* Code for lambda_lqlbvc_3 */

static Lisp_Object CC_lambda_lqlbvc_3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqlbvc_3");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v102;
    v17 = v0;
/* end of prologue */
        return Lleq(nil, v17, v15);
}



/* Code for moduntag */

static Lisp_Object CC_moduntag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moduntag");
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
    goto v15;

v15:
    v117 = stack[0];
    v54 = elt(env, 1); /* !:mod!: */
    if (!consp(v117)) goto v101;
    v117 = qcar(v117);
    if (!(v117 == v54)) goto v101;
    v117 = stack[-1];
    v54 = stack[0];
    v54 = qcdr(v54);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v117, v54);
    }

v101:
    v54 = stack[0];
    if (!consp(v54)) goto v18;
    v54 = stack[0];
    v54 = qcar(v54);
    v117 = CC_moduntag(env, v54);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-2];
    v54 = stack[-1];
    v54 = cons(v117, v54);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-2];
    stack[-1] = v54;
    v54 = stack[0];
    v54 = qcdr(v54);
    stack[0] = v54;
    goto v15;

v18:
    v117 = stack[-1];
    v54 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v117, v54);
    }
/* error exit handlers */
v109:
    popv(3);
    return nil;
}



/* Code for image!-of!-power */

static Lisp_Object CC_imageKofKpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v118, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for image-of-power");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v118 = stack[-1];
    v62 = qvalue(elt(env, 1)); /* image!-set */
    v62 = Lassoc(nil, v118, v62);
    stack[-2] = v62;
    v62 = stack[-2];
    if (v62 == nil) goto v40;
    v62 = stack[-2];
    v62 = qcdr(v62);
    stack[-2] = v62;
    goto v31;

v31:
    v118 = stack[-2];
    v62 = stack[0];
        popv(4);
        return Lmodular_expt(nil, v118, v62);

v40:
    fn = elt(env, 2); /* next!-random!-number */
    v62 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v62 = Lmodular_number(nil, v62);
    env = stack[-3];
    stack[-2] = v62;
    v115 = stack[-1];
    v118 = stack[-2];
    v62 = qvalue(elt(env, 1)); /* image!-set */
    v62 = acons(v115, v118, v62);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    qvalue(elt(env, 1)) = v62; /* image!-set */
    goto v31;
/* error exit handlers */
v33:
    popv(4);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113, v62, v118, v115, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v102;
    v27 = v0;
/* end of prologue */
    v112 = v27;
    v112 = qcdr(v112);
    v112 = qcar(v112);
    v118 = v112;
    v112 = v115;
    v112 = qcdr(v112);
    v112 = qcar(v112);
    v62 = v112;
    v113 = v118;
    v112 = v62;
    if (equal(v113, v112)) goto v35;
    v112 = v118;
    v113 = v62;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v112, v113);
    }

v35:
    v112 = v27;
    v112 = qcar(v112);
    v113 = v115;
    v113 = qcar(v113);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v112, v113);
    }
}



/* Code for polynomheadreduceby */

static Lisp_Object CC_polynomheadreduceby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomheadreduceby");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v102;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v101;

v101:
    v60 = stack[-2];
    v60 = qcar(v60);
    if (v60 == nil) goto v50;
    v60 = stack[-3];
    if (!(v60 == nil)) goto v50;
    v60 = stack[-2];
    v121 = qcar(v60);
    v60 = stack[-1];
    v60 = qcar(v60);
    fn = elt(env, 4); /* monomisdivisibleby */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    if (v60 == nil) goto v122;
    v60 = stack[-2];
    v121 = qcar(v60);
    v60 = stack[-1];
    v60 = qcar(v60);
    fn = elt(env, 5); /* monomdivide */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    stack[0] = stack[-2];
    v121 = stack[-1];
    fn = elt(env, 6); /* polynommultiplybymonom */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    fn = elt(env, 7); /* polynomadd */
    v60 = (*qfn2(fn))(qenv(fn), stack[0], v60);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    goto v101;

v122:
    v60 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v60;
    goto v101;

v50:
    v60 = qvalue(elt(env, 3)); /* fluidbibasisreductionsmade */
    v60 = (Lisp_Object)((int32_t)(v60) + 0x10);
    qvalue(elt(env, 3)) = v60; /* fluidbibasisreductionsmade */
    v60 = nil;
    { popv(5); return onevalue(v60); }
/* error exit handlers */
v19:
    popv(5);
    return nil;
}



/* Code for simpg3 */

static Lisp_Object CC_simpg3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpg3");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v15 = v1;
    v1 = elt(env, 1); /* g3 */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v15, v1);
    }
}



/* Code for remove!-free!-vars!* */

static Lisp_Object CC_removeKfreeKvarsH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars*");
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
    v100 = v0;
/* end of prologue */
    v114 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    qvalue(elt(env, 2)) = v114; /* !*!*noremove!*!* */
    v114 = v100;
    fn = elt(env, 3); /* remove!-free!-vars */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    { popv(2); return onevalue(v114); }
/* error exit handlers */
v101:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    popv(2);
    return nil;
}



/* Code for cl_susiupdknowl1 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, Lisp_Object v105, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl1");
#endif
    if (stack >= stacklimit)
    {
        push4(v105,v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v102,v111,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v111;
    v120 = v102;
    v108 = v0;
/* end of prologue */
    v109 = v108;
    v108 = elt(env, 1); /* and */
    if (v109 == v108) goto v89;
    v108 = v120;
    fn = elt(env, 2); /* rl_negateat */
    v109 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v108 = stack[0];
    v120 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v109 = stack[-1];
    v108 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v120, v109, v108);
    }

v89:
    v109 = v120;
    v108 = stack[0];
    v120 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v109 = stack[-1];
    v108 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v120, v109, v108);
    }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for rl_simp1 */

static Lisp_Object CC_rl_simp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v153, v154, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simp1");
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
    stack[0] = v0;
/* end of prologue */

v57:
    v152 = qvalue(elt(env, 1)); /* rl_cid!* */
    if (!(v152 == nil)) goto v114;
    v152 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v152 == nil)) goto v16;
    v152 = elt(env, 3); /* "select a context" */
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    fn = elt(env, 13); /* lprie */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    goto v16;

v16:
    v152 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    goto v114;

v114:
    v152 = stack[0];
    if (!consp(v152)) goto v86;
    v152 = stack[0];
    fn = elt(env, 14); /* argnochk */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v152 = stack[0];
    v153 = qcar(v152);
    v152 = elt(env, 4); /* rl_simpfn */
    v152 = get(v153, v152);
    env = stack[-5];
    v154 = v152;
    if (v152 == nil) goto v21;
    v153 = v154;
    v152 = elt(env, 5); /* full */
    v152 = Lflagp(nil, v153, v152);
    env = stack[-5];
    if (v152 == nil) goto v60;
    stack[-1] = v154;
    v152 = stack[0];
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    {
        Lisp_Object v157 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v157, v152);
    }

v60:
    stack[-1] = v154;
    v152 = stack[0];
    v152 = qcdr(v152);
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    {
        Lisp_Object v158 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v158, v152);
    }

v21:
    v152 = stack[0];
    v154 = qcar(v152);
    v152 = qvalue(elt(env, 1)); /* rl_cid!* */
    v153 = qcar(v152);
    v152 = elt(env, 6); /* simpfnname */
    v152 = get(v153, v152);
    env = stack[-5];
    v152 = get(v154, v152);
    env = stack[-5];
    v154 = v152;
    if (v152 == nil) goto v43;
    v153 = v154;
    v152 = elt(env, 5); /* full */
    v152 = Lflagp(nil, v153, v152);
    env = stack[-5];
    if (v152 == nil) goto v159;
    stack[-1] = v154;
    v152 = stack[0];
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    {
        Lisp_Object v160 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v160, v152);
    }

v159:
    stack[-1] = v154;
    v152 = stack[0];
    v152 = qcdr(v152);
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    {
        Lisp_Object v161 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v161, v152);
    }

v43:
    v152 = stack[0];
    v153 = qcar(v152);
    v152 = elt(env, 7); /* psopfn */
    v152 = get(v153, v152);
    env = stack[-5];
    v154 = v152;
    if (v152 == nil) goto v6;
    v153 = v154;
    v152 = stack[0];
    v152 = qcdr(v152);
    v152 = Lapply1(nil, v153, v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    stack[0] = v152;
    goto v57;

v6:
    v152 = stack[0];
    v153 = qcar(v152);
    v152 = elt(env, 8); /* opfn */
    v152 = Lflagp(nil, v153, v152);
    env = stack[-5];
    if (v152 == nil) goto v162;
    v152 = stack[0];
    stack[-4] = qcar(v152);
    v152 = stack[0];
    v152 = qcdr(v152);
    stack[-3] = v152;
    v152 = stack[-3];
    if (v152 == nil) goto v88;
    v152 = stack[-3];
    v152 = qcar(v152);
    fn = elt(env, 16); /* reval */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    stack[-1] = v152;
    stack[-2] = v152;
    goto v163;

v163:
    v152 = stack[-3];
    v152 = qcdr(v152);
    stack[-3] = v152;
    v152 = stack[-3];
    if (v152 == nil) goto v164;
    stack[0] = stack[-1];
    v152 = stack[-3];
    v152 = qcar(v152);
    fn = elt(env, 16); /* reval */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v152 = Lrplacd(nil, stack[0], v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v152 = stack[-1];
    v152 = qcdr(v152);
    stack[-1] = v152;
    goto v163;

v164:
    v152 = stack[-2];
    goto v64;

v64:
    fn = elt(env, 15); /* apply */
    v152 = (*qfn2(fn))(qenv(fn), stack[-4], v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    stack[0] = v152;
    goto v57;

v88:
    v152 = qvalue(elt(env, 9)); /* nil */
    goto v64;

v162:
    v152 = stack[0];
    v153 = qcar(v152);
    v152 = elt(env, 10); /* prepfn2 */
    v152 = get(v153, v152);
    env = stack[-5];
    v154 = v152;
    if (v152 == nil) goto v165;
    stack[-1] = v154;
    v152 = stack[0];
    v152 = ncons(v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    fn = elt(env, 15); /* apply */
    v152 = (*qfn2(fn))(qenv(fn), stack[-1], v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    stack[0] = v152;
    goto v57;

v165:
    v152 = stack[0];
    v153 = qcar(v152);
    v152 = elt(env, 11); /* "predicate" */
    fn = elt(env, 17); /* rl_redmsg */
    v152 = (*qfn2(fn))(qenv(fn), v153, v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v152 = stack[0];
    v155 = qcar(v152);
    v152 = qvalue(elt(env, 1)); /* rl_cid!* */
    v153 = qcar(v152);
    v152 = elt(env, 6); /* simpfnname */
    v154 = get(v153, v152);
    env = stack[-5];
    v152 = qvalue(elt(env, 1)); /* rl_cid!* */
    v153 = qcar(v152);
    v152 = elt(env, 12); /* simpdefault */
    v152 = get(v153, v152);
    env = stack[-5];
    v152 = Lputprop(nil, 3, v155, v154, v152);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v152 = stack[0];
    stack[0] = v152;
    goto v57;

v86:
    v152 = stack[0];
    {
        popv(6);
        fn = elt(env, 18); /* rl_simpatom */
        return (*qfn1(fn))(qenv(fn), v152);
    }
/* error exit handlers */
v156:
    popv(6);
    return nil;
}



/* Code for nary */

static Lisp_Object CC_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nary");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v60 = stack[-1];
    v121 = qcar(v60);
    v60 = elt(env, 1); /* e */
    if (v121 == v60) goto v166;
    v60 = qvalue(elt(env, 3)); /* nil */
    goto v1;

v1:
    if (v60 == nil) goto v119;
    v60 = stack[-1];
    v121 = qcdr(v60);
    v60 = elt(env, 4); /* exp */
    fn = elt(env, 10); /* unary */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    goto v114;

v114:
    v60 = nil;
    { popv(3); return onevalue(v60); }

v119:
    v60 = elt(env, 5); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = elt(env, 6); /* "<" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = stack[0];
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = stack[-1];
    v121 = qcar(v60);
    v60 = elt(env, 7); /* "/" */
    fn = elt(env, 12); /* attributesml */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 13); /* indent!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = stack[-1];
    v60 = qcdr(v60);
    fn = elt(env, 14); /* multi_elem */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    goto v114;

v166:
    v121 = stack[0];
    v60 = elt(env, 2); /* power */
    v60 = (v121 == v60 ? lisp_true : nil);
    goto v1;
/* error exit handlers */
v167:
    popv(3);
    return nil;
}



/* Code for opmtch */

static Lisp_Object CC_opmtch(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v180, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtch");
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
    stack[-7] = nil;
    v179 = stack[-6];
    v180 = qcar(v179);
    v179 = elt(env, 0); /* opmtch */
    v179 = get(v180, v179);
    env = stack[-8];
    stack[-5] = v179;
    if (v179 == nil) goto v16;
    v179 = qvalue(elt(env, 2)); /* subfg!* */
    if (v179 == nil) goto v89;
    v179 = qvalue(elt(env, 3)); /* !*uncached */
    if (v179 == nil) goto v104;
    v179 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v39:
    if (v179 == nil) goto v17;
    v179 = stack[-7];
    v179 = qcdr(v179);
    { popv(9); return onevalue(v179); }

v17:
    v179 = stack[-6];
    v179 = qcdr(v179);
    stack[-4] = v179;
    v179 = stack[-4];
    if (v179 == nil) goto v122;
    v179 = stack[-4];
    v179 = qcar(v179);
    stack[0] = v179;
    v179 = stack[0];
    if (!consp(v179)) goto v79;
    v179 = stack[0];
    v179 = CC_opmtch(env, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v180 = v179;
    v179 = v180;
    if (v179 == nil) goto v183;
    v179 = v180;
    goto v80;

v80:
    v179 = ncons(v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    stack[-2] = v179;
    stack[-3] = v179;
    goto v108;

v108:
    v179 = stack[-4];
    v179 = qcdr(v179);
    stack[-4] = v179;
    v179 = stack[-4];
    if (v179 == nil) goto v78;
    stack[-1] = stack[-2];
    v179 = stack[-4];
    v179 = qcar(v179);
    stack[0] = v179;
    v179 = stack[0];
    if (!consp(v179)) goto v4;
    v179 = stack[0];
    v179 = CC_opmtch(env, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v180 = v179;
    v179 = v180;
    if (v179 == nil) goto v184;
    v179 = v180;
    goto v3;

v3:
    v179 = ncons(v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v179 = Lrplacd(nil, stack[-1], v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v179 = stack[-2];
    v179 = qcdr(v179);
    stack[-2] = v179;
    goto v108;

v184:
    v179 = stack[0];
    goto v3;

v4:
    v179 = stack[0];
    goto v3;

v78:
    v179 = stack[-3];
    goto v107;

v107:
    stack[0] = v179;
    goto v50;

v50:
    v179 = stack[-5];
    if (v179 == nil) goto v1;
    v181 = stack[0];
    v179 = stack[-5];
    v179 = qcar(v179);
    v180 = qcar(v179);
    v179 = stack[-6];
    v179 = qcar(v179);
    fn = elt(env, 5); /* mcharg */
    v179 = (*qfnn(fn))(qenv(fn), 3, v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    stack[-1] = v179;
    goto v101;

v101:
    v179 = stack[-1];
    if (v179 == nil) goto v71;
    v179 = stack[-1];
    v180 = qcar(v179);
    v179 = stack[-5];
    v179 = qcar(v179);
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v179 = qcdr(v179);
    v179 = Lsubla(nil, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    if (v179 == nil) goto v185;
    v179 = stack[-1];
    v180 = qcar(v179);
    v179 = stack[-5];
    v179 = qcar(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v179 = Lsubla(nil, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    stack[-7] = v179;
    goto v1;

v1:
    v179 = qvalue(elt(env, 3)); /* !*uncached */
    if (!(v179 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    stack[0] = qvalue(elt(env, 4)); /* alglist!* */
    v181 = stack[-6];
    v180 = stack[-7];
    v179 = qvalue(elt(env, 4)); /* alglist!* */
    v179 = qcdr(v179);
    v179 = acons(v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v179 = Lrplacd(nil, stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }

v185:
    v179 = stack[-1];
    v179 = qcdr(v179);
    stack[-1] = v179;
    goto v101;

v71:
    v179 = stack[-5];
    v179 = qcdr(v179);
    stack[-5] = v179;
    goto v50;

v183:
    v179 = stack[0];
    goto v80;

v79:
    v179 = stack[0];
    goto v80;

v122:
    v179 = qvalue(elt(env, 1)); /* nil */
    goto v107;

v104:
    v180 = stack[-6];
    v179 = qvalue(elt(env, 4)); /* alglist!* */
    v179 = qcdr(v179);
    v179 = Lassoc(nil, v180, v179);
    stack[-7] = v179;
    goto v39;

v89:
    v179 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v179); }

v16:
    v179 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v179); }
/* error exit handlers */
v182:
    popv(9);
    return nil;
}



/* Code for unchecked_getmatelem */

static Lisp_Object CC_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v121, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unchecked_getmatelem");
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
    v60 = stack[0];
    v121 = qcar(v60);
    v80 = v121;
    v60 = elt(env, 1); /* mat */
    if (!consp(v121)) goto v56;
    v121 = qcar(v121);
    if (!(v121 == v60)) goto v56;
    v60 = v80;
    v121 = qcdr(v60);
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    fn = elt(env, 6); /* pnth */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-1];
    v121 = qcar(v60);
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    fn = elt(env, 6); /* pnth */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v60 = qcar(v60);
    { popv(2); return onevalue(v60); }

v56:
    v80 = elt(env, 2); /* "Matrix" */
    v60 = stack[0];
    v121 = qcar(v60);
    v60 = elt(env, 3); /* "not set" */
    v60 = list3(v80, v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-1];
    v121 = v60;
    v60 = v121;
    qvalue(elt(env, 4)) = v60; /* errmsg!* */
    v60 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v60 == nil)) goto v186;
    v60 = v121;
    fn = elt(env, 7); /* lprie */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-1];
    goto v186;

v186:
    v60 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v60 = nil;
    { popv(2); return onevalue(v60); }
/* error exit handlers */
v167:
    popv(2);
    return nil;
}



/* Code for evaluate1 */

static Lisp_Object CC_evaluate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v185, v71, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate1");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v185 = v102;
    v71 = v0;
/* end of prologue */
    v46 = v71;
    if (is_number(v46)) goto v97;
    v46 = v71;
    if (v46 == nil) goto v97;
    v46 = v71;
    v46 = Lconsp(nil, v46);
    env = stack[0];
    if (v46 == nil) goto v18;
    v46 = v71;
    v70 = qcar(v46);
    v46 = elt(env, 1); /* dname */
    v46 = get(v70, v46);
    env = stack[0];
    if (!(v46 == nil)) { popv(1); return onevalue(v71); }

v18:
    v70 = v71;
    v46 = v185;
    v46 = Lassoc(nil, v70, v46);
    v70 = v46;
    v46 = v70;
    if (v46 == nil) goto v113;
    v46 = v70;
    v46 = qcdr(v46);
    { popv(1); return onevalue(v46); }

v113:
    v46 = v71;
    if (!consp(v46)) goto v107;
    v46 = v71;
    v46 = qcar(v46);
    v71 = qcdr(v71);
    {
        popv(1);
        fn = elt(env, 13); /* evaluate2 */
        return (*qfnn(fn))(qenv(fn), 3, v46, v71, v185);
    }

v107:
    v185 = v71;
    v46 = elt(env, 2); /* i */
    if (v185 == v46) goto v189;
    v185 = v71;
    v46 = elt(env, 8); /* e */
    if (v185 == v46) goto v41;
    v185 = v71;
    v46 = elt(env, 10); /* pi */
    v46 = (v185 == v46 ? lisp_true : nil);
    goto v190;

v190:
    if (v46 == nil) goto v42;
    v46 = v71;
    fn = elt(env, 14); /* simp */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[0];
    v46 = qcar(v46);
    {
        popv(1);
        fn = elt(env, 15); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v46);
    }

v42:
    v46 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 11)) = v46; /* !*evaluateerror */
    v185 = v71;
    v46 = elt(env, 12); /* "number" */
    {
        popv(1);
        fn = elt(env, 16); /* typerr */
        return (*qfn2(fn))(qenv(fn), v185, v46);
    }

v41:
    v46 = qvalue(elt(env, 9)); /* t */
    goto v190;

v189:
    v185 = qvalue(elt(env, 3)); /* dmode!* */
    v46 = elt(env, 4); /* ivalue */
    v46 = get(v185, v46);
    env = stack[0];
    v71 = v46;
    if (v46 == nil) goto v38;
    v185 = v71;
    v46 = elt(env, 5); /* (nil) */
    fn = elt(env, 17); /* apply */
    v46 = (*qfn2(fn))(qenv(fn), v185, v46);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v46 = qcar(v46);
    { popv(1); return onevalue(v46); }

v38:
    v46 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v46 == nil)) goto v147;
    v46 = elt(env, 7); /* "i used as indeterminate value" */
    fn = elt(env, 18); /* lprie */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[0];
    goto v147;

v147:
    v46 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v46 = nil;
    { popv(1); return onevalue(v46); }

v97:
    v46 = v71;
    {
        popv(1);
        fn = elt(env, 15); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v46);
    }
/* error exit handlers */
v142:
    popv(1);
    return nil;
}



/* Code for lispassignp */

static Lisp_Object CC_lispassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v15 = elt(env, 1); /* setq */
        return Leqcar(nil, v1, v15);
}



/* Code for assert_uninstall1 */

static Lisp_Object CC_assert_uninstall1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v189, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall1");
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
    v189 = stack[0];
    v63 = elt(env, 1); /* assert_installed */
    v63 = get(v189, v63);
    env = stack[-2];
    if (v63 == nil) goto v58;
    v60 = stack[0];
    v189 = stack[0];
    v63 = elt(env, 6); /* assert_noassertfn */
    v63 = get(v189, v63);
    env = stack[-2];
    fn = elt(env, 7); /* copyd */
    v63 = (*qfn2(fn))(qenv(fn), v60, v63);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v189 = stack[0];
    v63 = elt(env, 1); /* assert_installed */
    v60 = qvalue(elt(env, 3)); /* nil */
        popv(3);
        return Lputprop(nil, 3, v189, v63, v60);

v58:
    v63 = qvalue(elt(env, 2)); /* !*msg */
    if (v63 == nil) goto v40;
    stack[-1] = elt(env, 4); /* "***" */
    v189 = elt(env, 5); /* "assert not installed for" */
    v63 = stack[0];
    v63 = list2(v189, v63);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    {
        Lisp_Object v167 = stack[-1];
        popv(3);
        fn = elt(env, 8); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v167, v63);
    }

v40:
    v63 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v63); }
/* error exit handlers */
v79:
    popv(3);
    return nil;
}



/* Code for dp_times_bcmo */

static Lisp_Object MS_CDECL CC_dp_times_bcmo(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dp_times_bcmo");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bcmo");
#endif
    if (stack >= stacklimit)
    {
        push3(v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v102,v111);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v191 = v111;
    stack[-5] = v102;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = v191;
    v191 = stack[-7];
    if (v191 == nil) goto v16;
    v191 = stack[-7];
    v191 = qcar(v191);
    stack[-1] = v191;
    v192 = stack[-5];
    v191 = stack[-1];
    v191 = qcar(v191);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v192 = stack[-6];
    v191 = stack[-1];
    v191 = qcdr(v191);
    fn = elt(env, 3); /* bc_prod */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v191 = cons(stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    stack[-3] = v191;
    stack[-4] = v191;
    goto v101;

v101:
    v191 = stack[-7];
    v191 = qcdr(v191);
    stack[-7] = v191;
    v191 = stack[-7];
    if (v191 == nil) { Lisp_Object res = stack[-4]; popv(9); return onevalue(res); }
    stack[-2] = stack[-3];
    v191 = stack[-7];
    v191 = qcar(v191);
    stack[-1] = v191;
    v192 = stack[-5];
    v191 = stack[-1];
    v191 = qcar(v191);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v192 = stack[-6];
    v191 = stack[-1];
    v191 = qcdr(v191);
    fn = elt(env, 3); /* bc_prod */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v191 = cons(stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v191 = Lrplacd(nil, stack[-2], v191);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v191 = stack[-3];
    v191 = qcdr(v191);
    stack[-3] = v191;
    goto v101;

v16:
    v191 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v191); }
/* error exit handlers */
v193:
    popv(9);
    return nil;
}



/* Code for addgt */

static Lisp_Object CC_addgt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addgt");
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
    v35 = qvalue(elt(env, 1)); /* ordering */
    v39 = elt(env, 2); /* lex */
    if (v35 == v39) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v35 = elt(env, 3); /* plus */
    v39 = stack[0];
    v39 = cons(v35, v39);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    fn = elt(env, 4); /* eval */
    v35 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v186;
    v39 = stack[0];
    popv(2);
    return cons(v35, v39);
/* error exit handlers */
v186:
    popv(2);
    return nil;
}



/* Code for wi_new */

static Lisp_Object CC_wi_new(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wi_new");
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
    stack[-2] = v0;
/* end of prologue */
    v25 = qvalue(elt(env, 1)); /* wi_number */
    v25 = add1(v25);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    qvalue(elt(env, 1)) = v25; /* wi_number */
    v24 = elt(env, 2); /* !: */
    v25 = qvalue(elt(env, 1)); /* wi_number */
    fn = elt(env, 4); /* mkid */
    v25 = (*qfn2(fn))(qenv(fn), v24, v25);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v25 = Lintern(nil, v25);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[-3] = v25;
    stack[-1] = stack[-3];
    stack[0] = elt(env, 3); /* windex */
    v25 = stack[-2];
    v25 = ncons(v25);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v25 = Lputprop(nil, 3, stack[-1], stack[0], v25);
    nil = C_nil;
    if (exception_pending()) goto v186;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v186:
    popv(5);
    return nil;
}



/* Code for tensorp */

static Lisp_Object CC_tensorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v56 = v30;
    if (!consp(v56)) goto v40;
    v56 = v30;
    v56 = qcar(v56);
    v30 = elt(env, 1); /* tensor */
        return Lflagp(nil, v56, v30);

v40:
    v56 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v56);
}



/* Code for dfprint */

static Lisp_Object CC_dfprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfprint");
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
    v109 = qvalue(elt(env, 1)); /* dfprint!* */
    if (v109 == nil) goto v97;
    stack[-1] = qvalue(elt(env, 1)); /* dfprint!* */
    v109 = stack[0];
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    {
        Lisp_Object v110 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }

v97:
    v109 = qvalue(elt(env, 2)); /* cmsg!* */
    if (v109 == nil) goto v86;
    v109 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v109); }

v86:
    v120 = stack[0];
    v109 = elt(env, 4); /* progn */
    if (!consp(v120)) goto v35;
    v120 = qcar(v120);
    if (!(v120 == v109)) goto v35;

v62:
    v109 = stack[0];
    v109 = qcdr(v109);
    stack[0] = v109;
    v109 = stack[0];
    if (v109 == nil) goto v34;
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = CC_dfprint(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    goto v62;

v34:
    v109 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v109); }

v35:
    v109 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    fn = elt(env, 6); /* superprinm */
    v109 = (*qfn2(fn))(qenv(fn), stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v109 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v109 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v109); }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for ofsf_entry2at */

static Lisp_Object MS_CDECL CC_ofsf_entry2at(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v186, v104, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at");
#endif
    if (stack >= stacklimit)
    {
        push3(v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v102,v111);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v186 = v111;
    v104 = v102;
    v31 = v0;
/* end of prologue */
    v195 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v195 == nil) goto v116;
    v195 = v31;
    fn = elt(env, 2); /* ofsf_entry2at1 */
    v195 = (*qfnn(fn))(qenv(fn), 3, v195, v104, v186);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cl_identifyat */
        return (*qfn1(fn))(qenv(fn), v195);
    }

v116:
    v195 = v31;
    {
        popv(1);
        fn = elt(env, 2); /* ofsf_entry2at1 */
        return (*qfnn(fn))(qenv(fn), 3, v195, v104, v186);
    }
/* error exit handlers */
v103:
    popv(1);
    return nil;
}



/* Code for squared!+matrix!+p */

static Lisp_Object CC_squaredLmatrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for squared+matrix+p");
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
    v87 = stack[0];
    fn = elt(env, 2); /* matrix!+p */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    if (v87 == nil) goto v97;
    v87 = stack[0];
    fn = elt(env, 3); /* get!+row!+nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v87 = stack[0];
    fn = elt(env, 4); /* get!+col!+nr */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    if (!(equal(stack[-1], v87))) goto v97;
    v87 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v87); }

v97:
    v87 = nil;
    { popv(3); return onevalue(v87); }
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for mri_realvarp */

static Lisp_Object CC_mri_realvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_realvarp");
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
    v98 = v0;
/* end of prologue */
    v89 = v98;
    if (symbolp(v89)) goto v194;
    v89 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v89); }

v194:
    v89 = elt(env, 2); /* mri_type */
    v89 = get(v98, v89);
    env = stack[0];
    v98 = elt(env, 3); /* real */
    v89 = (v89 == v98 ? lisp_true : nil);
    { popv(1); return onevalue(v89); }
}



/* Code for searchpl */

static Lisp_Object CC_searchpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v59;
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
    goto v114;

v114:
    v183 = stack[-1];
    if (!consp(v183)) goto v106;
    v183 = stack[-1];
    v183 = qcar(v183);
    v183 = (consp(v183) ? nil : lisp_true);
    goto v2;

v2:
    if (v183 == nil) goto v89;
    v183 = qvalue(elt(env, 2)); /* nil */
    v59 = v183;
    goto v50;

v50:
    v183 = stack[-2];
    if (v183 == nil) { popv(4); return onevalue(v59); }
    v183 = stack[-2];
    v183 = qcar(v183);
    fn = elt(env, 3); /* setunion */
    v183 = (*qfn2(fn))(qenv(fn), v183, v59);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-3];
    v59 = v183;
    v183 = stack[-2];
    v183 = qcdr(v183);
    stack[-2] = v183;
    goto v50;

v89:
    v183 = stack[-1];
    v183 = qcar(v183);
    if (!consp(v183)) goto v104;
    v183 = stack[-1];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v183 = (consp(v183) ? nil : lisp_true);
    goto v186;

v186:
    if (v183 == nil) goto v55;
    v183 = qvalue(elt(env, 2)); /* nil */
    v59 = v183;
    goto v52;

v52:
    v183 = stack[-2];
    v183 = cons(v59, v183);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-3];
    stack[-2] = v183;
    v183 = stack[-1];
    v183 = qcdr(v183);
    stack[-1] = v183;
    goto v114;

v55:
    v183 = stack[-1];
    v183 = qcar(v183);
    v183 = qcar(v183);
    stack[0] = qcar(v183);
    v183 = stack[-1];
    v183 = qcar(v183);
    v183 = qcdr(v183);
    v183 = CC_searchpl(env, v183);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-3];
    v183 = cons(stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-3];
    v59 = v183;
    goto v52;

v104:
    v183 = qvalue(elt(env, 1)); /* t */
    goto v186;

v106:
    v183 = qvalue(elt(env, 1)); /* t */
    goto v2;
/* error exit handlers */
v191:
    popv(4);
    return nil;
}



/* Code for ibalp_var!-satlist */

static Lisp_Object CC_ibalp_varKsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-satlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v102;
    v204 = v0;
/* end of prologue */
    stack[-5] = v204;
    goto v114;

v114:
    v204 = stack[-5];
    if (v204 == nil) goto v1;
    v204 = stack[-5];
    v204 = qcar(v204);
    stack[-3] = v204;
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    if (!(v204 == nil)) goto v206;
    v204 = stack[-3];
    v204 = qcar(v204);
    stack[-2] = v204;
    goto v24;

v24:
    v204 = stack[-2];
    if (v204 == nil) goto v25;
    v204 = stack[-2];
    v204 = qcar(v204);
    stack[-1] = v204;
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    stack[0] = qcdr(v204);
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    v204 = sub1(v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    stack[0] = qcdr(v204);
    v204 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    v204 = stack[-2];
    v204 = qcdr(v204);
    stack[-2] = v204;
    goto v24;

v25:
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = qcar(v204);
    stack[-2] = v204;
    goto v183;

v183:
    v204 = stack[-2];
    if (v204 == nil) goto v92;
    v204 = stack[-2];
    v204 = qcar(v204);
    stack[-1] = v204;
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    stack[0] = qcdr(v204);
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    v204 = sub1(v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    stack[0] = qcdr(v204);
    v204 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    v204 = stack[-2];
    v204 = qcdr(v204);
    stack[-2] = v204;
    goto v183;

v92:
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    stack[-1] = v204;
    goto v207;

v207:
    v204 = stack[-1];
    if (v204 == nil) goto v208;
    v204 = stack[-1];
    v204 = qcar(v204);
    v205 = v204;
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    stack[0] = qcdr(v205);
    v205 = stack[-3];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    fn = elt(env, 4); /* delq */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    v204 = stack[-1];
    v204 = qcdr(v204);
    stack[-1] = v204;
    goto v207;

v208:
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v205 = qcdr(v204);
    v204 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    goto v206;

v206:
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    stack[0] = qcdr(v204);
    v205 = stack[-4];
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-6];
    v204 = stack[-5];
    v204 = qcdr(v204);
    stack[-5] = v204;
    goto v114;

v1:
    v204 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v204); }
/* error exit handlers */
v130:
    popv(7);
    return nil;
}



/* Code for quotfail1 */

static Lisp_Object MS_CDECL CC_quotfail1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v195, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "quotfail1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail1");
#endif
    if (stack >= stacklimit)
    {
        push3(v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v102,v111);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v111;
    v195 = v102;
    v186 = v0;
/* end of prologue */
    v35 = v186;
    if (v35 == nil) goto v114;
    v35 = v186;
    fn = elt(env, 2); /* quotf */
    v35 = (*qfn2(fn))(qenv(fn), v35, v195);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v195 = v35;
    v35 = v195;
    if (!(v35 == nil)) { popv(2); return onevalue(v195); }
    v35 = stack[0];
    fn = elt(env, 3); /* errorf */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v35 = nil;
    { popv(2); return onevalue(v35); }

v114:
    v35 = qvalue(elt(env, 1)); /* polyzero */
    { popv(2); return onevalue(v35); }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for variableom */

static Lisp_Object CC_variableom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variableom");
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
    v108 = stack[0];
    v109 = Lintern(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = qvalue(elt(env, 1)); /* constantsom!* */
    v108 = Lassoc(nil, v109, v108);
    stack[-1] = v108;
    v108 = stack[-1];
    if (v108 == nil) goto v83;
    v108 = elt(env, 2); /* "<OMS " */
    fn = elt(env, 9); /* printout */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = elt(env, 3); /* "cd=""" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = stack[-1];
    v108 = qcdr(v108);
    v108 = qcar(v108);
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = elt(env, 4); /* """ " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = elt(env, 5); /* "name=""" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = stack[-1];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v108 = qcar(v108);
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = elt(env, 6); /* """/>" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    goto v106;

v106:
    v108 = nil;
    { popv(3); return onevalue(v108); }

v83:
    v108 = stack[0];
    if (v108 == nil) goto v106;
    v108 = elt(env, 8); /* "<OMV " */
    fn = elt(env, 9); /* printout */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = elt(env, 5); /* "name=""" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = stack[0];
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v108 = elt(env, 6); /* """/>" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v85;
    goto v106;
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for bcquot */

static Lisp_Object CC_bcquot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v191, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcquot");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v209 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v209 == nil) goto v114;
    v209 = stack[0];
    v209 = Lmodular_reciprocal(nil, v209);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v209 = times2(stack[-1], v209);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v209);
    }

v114:
    v209 = qvalue(elt(env, 2)); /* !*vdpinteger */
    if (v209 == nil) goto v37;
    v192 = stack[-1];
    v191 = stack[0];
    v209 = elt(env, 3); /* quotientx */
    fn = elt(env, 8); /* bcint2op */
    v209 = (*qfnn(fn))(qenv(fn), 3, v192, v191, v209);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    if (!(v209 == nil)) { popv(3); return onevalue(v209); }
    v209 = qvalue(elt(env, 4)); /* !*exp */
    if (v209 == nil) goto v27;
    v209 = qvalue(elt(env, 6)); /* !*mcd */
    v209 = (v209 == nil ? lisp_true : nil);
    goto v115;

v115:
    if (v209 == nil) goto v121;
    v209 = stack[-1];
    v191 = qcar(v209);
    v209 = stack[0];
    v209 = qcar(v209);
    fn = elt(env, 9); /* quotf */
    v209 = (*qfn2(fn))(qenv(fn), v191, v209);
    nil = C_nil;
    if (exception_pending()) goto v210;
    v191 = v209;
    goto v103;

v103:
    v209 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v191, v209);

v121:
    v209 = stack[-1];
    v191 = qcar(v209);
    v209 = stack[0];
    v209 = qcar(v209);
    fn = elt(env, 10); /* quotfx1 */
    v209 = (*qfn2(fn))(qenv(fn), v191, v209);
    nil = C_nil;
    if (exception_pending()) goto v210;
    v191 = v209;
    goto v103;

v27:
    v209 = qvalue(elt(env, 5)); /* t */
    goto v115;

v37:
    v209 = stack[0];
    fn = elt(env, 11); /* invsq */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    {
        Lisp_Object v149 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* multsq */
        return (*qfn2(fn))(qenv(fn), v149, v209);
    }
/* error exit handlers */
v210:
    popv(3);
    return nil;
}



/* Code for bcneg */

static Lisp_Object CC_bcneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcneg");
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
    v113 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v113 == nil) goto v35;
    v62 = stack[0];
    v113 = (Lisp_Object)1; /* 0 */
    v113 = Leqn(nil, v62, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-1];
    if (!(v113 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v62 = qvalue(elt(env, 2)); /* current!-modulus */
    v113 = stack[0];
    v113 = (Lisp_Object)(int32_t)((int32_t)v62 - (int32_t)v113 + TAG_FIXNUM);
    { popv(2); return onevalue(v113); }

v35:
    v113 = stack[0];
    v113 = qcar(v113);
    fn = elt(env, 3); /* negf */
    v62 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v113 = stack[0];
    v113 = qcdr(v113);
    popv(2);
    return cons(v62, v113);
/* error exit handlers */
v115:
    popv(2);
    return nil;
}



/* Code for xord_gradlex */

static Lisp_Object CC_xord_gradlex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_gradlex");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = (Lisp_Object)17; /* 1 */
    if (v85 == v84) goto v97;
    v84 = stack[0];
    v85 = qcar(v84);
    v84 = (Lisp_Object)17; /* 1 */
    if (v85 == v84) goto v40;
    v84 = stack[-1];
    stack[-2] = Llength(nil, v84);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v84 = stack[0];
    v84 = Llength(nil, v84);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    if (equal(stack[-2], v84)) goto v83;
    v84 = stack[-1];
    stack[-1] = Llength(nil, v84);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v84 = stack[0];
    v84 = Llength(nil, v84);
    nil = C_nil;
    if (exception_pending()) goto v36;
    {
        Lisp_Object v53 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v53, v84);
    }

v83:
    v85 = stack[-1];
    v84 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v85, v84);
    }

v40:
    v84 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v84); }

v97:
    v84 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v84); }
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for delete!-dups */

static Lisp_Object CC_deleteKdups(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v118, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete-dups");
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
    v115 = nil;
    goto v97;

v97:
    v62 = stack[0];
    if (v62 == nil) goto v61;
    v62 = stack[0];
    v118 = qcar(v62);
    v62 = stack[0];
    v62 = qcdr(v62);
    v62 = Lmember(nil, v118, v62);
    if (v62 == nil) goto v24;
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[0] = v62;
    goto v97;

v24:
    v62 = stack[0];
    v62 = qcar(v62);
    v118 = v115;
    v62 = cons(v62, v118);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v115 = v62;
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[0] = v62;
    goto v97;

v61:
    v62 = v115;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v62);
    }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for cut!:mt */

static Lisp_Object CC_cutTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:mt");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v102;
    stack[-2] = v0;
/* end of prologue */
    v184 = stack[-2];
    v211 = elt(env, 1); /* !:rd!: */
    if (!consp(v184)) goto v52;
    v184 = qcar(v184);
    if (!(v184 == v211)) goto v52;
    v211 = stack[-2];
    v211 = qcdr(v211);
    v211 = (consp(v211) ? nil : lisp_true);
    v211 = (v211 == nil ? lisp_true : nil);
    goto v17;

v17:
    if (v211 == nil) goto v27;
    v211 = stack[-1];
    v211 = integerp(v211);
    if (v211 == nil) goto v39;
    v184 = stack[-1];
    v211 = (Lisp_Object)1; /* 0 */
    v211 = (Lisp_Object)greaterp2(v184, v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v211 = v211 ? lisp_true : nil;
    env = stack[-4];
    goto v50;

v50:
    if (v211 == nil) goto v4;
    v211 = stack[-2];
    v211 = qcdr(v211);
    v211 = qcar(v211);
    v211 = Labsval(nil, v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    fn = elt(env, 4); /* msd */
    v184 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    v211 = stack[-1];
    v184 = difference2(v184, v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    stack[-1] = v184;
    v211 = (Lisp_Object)1; /* 0 */
    v211 = (Lisp_Object)lesseq2(v184, v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v211 = v211 ? lisp_true : nil;
    env = stack[-4];
    if (!(v211 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v211 = stack[-2];
    v211 = qcdr(v211);
    stack[0] = qcar(v211);
    v211 = stack[-1];
    v211 = negate(v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    v211 = stack[-2];
    v211 = qcdr(v211);
    v184 = qcdr(v211);
    v211 = stack[-1];
    v211 = plus2(v184, v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    {
        Lisp_Object v213 = stack[-3];
        Lisp_Object v188 = stack[0];
        popv(5);
        return list2star(v213, v188, v211);
    }

v4:
    stack[0] = (Lisp_Object)1; /* 0 */
    v184 = elt(env, 3); /* "Invalid argument to" */
    v211 = elt(env, 0); /* cut!:mt */
    v211 = list2(v184, v211);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    {
        Lisp_Object v14 = stack[0];
        popv(5);
        fn = elt(env, 5); /* error */
        return (*qfn2(fn))(qenv(fn), v14, v211);
    }

v39:
    v211 = qvalue(elt(env, 2)); /* nil */
    goto v50;

v27:
    v211 = qvalue(elt(env, 2)); /* nil */
    goto v50;

v52:
    v211 = qvalue(elt(env, 2)); /* nil */
    goto v17;
/* error exit handlers */
v212:
    popv(5);
    return nil;
}



/* Code for mv!-domainlist!-!* */

static Lisp_Object CC_mvKdomainlistKH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-*");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v114;

v114:
    v195 = stack[0];
    if (v195 == nil) goto v101;
    v186 = stack[-1];
    v195 = stack[0];
    v195 = qcar(v195);
    v186 = times2(v186, v195);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v195 = stack[-2];
    v195 = cons(v186, v195);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    stack[-2] = v195;
    v195 = stack[0];
    v195 = qcdr(v195);
    stack[0] = v195;
    goto v114;

v101:
    v195 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v195);
    }
/* error exit handlers */
v83:
    popv(4);
    return nil;
}



/* Code for groeb!=better */

static Lisp_Object CC_groebMbetter(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=better");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v60 = stack[-1];
    v60 = qcdr(v60);
    v121 = qcar(v60);
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = (Lisp_Object)lessp2(v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v60 = v60 ? lisp_true : nil;
    env = stack[-2];
    if (v60 == nil) goto v87;
    v60 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v60); }

v87:
    v60 = stack[-1];
    v60 = qcdr(v60);
    v121 = qcar(v60);
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    if (equal(v121, v60)) goto v115;
    v60 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v60); }

v115:
    v121 = stack[-1];
    v60 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    stack[-1] = qcar(v60);
    v121 = stack[0];
    v60 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v60 = (*qfn2(fn))(qenv(fn), v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v60 = qcar(v60);
    fn = elt(env, 4); /* mo_compare */
    v121 = (*qfn2(fn))(qenv(fn), stack[-1], v60);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v60 = (Lisp_Object)1; /* 0 */
        popv(3);
        return Lleq(nil, v121, v60);
/* error exit handlers */
v167:
    popv(3);
    return nil;
}



/* Code for gperm3 */

static Lisp_Object CC_gperm3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v18, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm3");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v18 = v102;
    v24 = v0;
/* end of prologue */

v114:
    v39 = v24;
    if (v39 == nil) { popv(2); return onevalue(v18); }
    v39 = v24;
    v39 = qcdr(v39);
    stack[0] = v39;
    v39 = v18;
    v18 = qcar(v24);
    v24 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* gperm2 */
    v24 = (*qfnn(fn))(qenv(fn), 3, v39, v18, v24);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v18 = v24;
    v24 = stack[0];
    goto v114;
/* error exit handlers */
v195:
    popv(2);
    return nil;
}



/* Code for next!-random!-number */

static Lisp_Object MS_CDECL CC_nextKrandomKnumber(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v92, v183, v59;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "next-random-number");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for next-random-number");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v92 = qvalue(elt(env, 1)); /* unidev_next!* */
    v37 = (Lisp_Object)865; /* 54 */
    if (v92 == v37) goto v114;
    v37 = qvalue(elt(env, 1)); /* unidev_next!* */
    v37 = (Lisp_Object)((int32_t)(v37) + 0x10);
    qvalue(elt(env, 1)) = v37; /* unidev_next!* */
    goto v116;

v116:
    v92 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v37 = (Lisp_Object)865; /* 54 */
    if (v92 == v37) goto v87;
    v37 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v37 = (Lisp_Object)((int32_t)(v37) + 0x10);
    qvalue(elt(env, 2)) = v37; /* unidev_nextp!* */
    goto v119;

v119:
    v92 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v37 = qvalue(elt(env, 1)); /* unidev_next!* */
    v183 = *(Lisp_Object *)((char *)v92 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v92 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v37 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v37 = *(Lisp_Object *)((char *)v92 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v37 = (Lisp_Object)(int32_t)((int32_t)v183 - (int32_t)v37 + TAG_FIXNUM);
    v183 = v37;
    v37 = v183;
    v37 = ((intptr_t)(v37) < 0 ? lisp_true : nil);
    if (v37 == nil) goto v51;
    v92 = v183;
    v37 = qvalue(elt(env, 4)); /* randommodulus!* */
    v37 = (Lisp_Object)(int32_t)((int32_t)v92 + (int32_t)v37 - TAG_FIXNUM);
    v183 = v37;
    goto v51;

v51:
    v92 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v59 = qvalue(elt(env, 1)); /* unidev_next!* */
    v37 = v183;
    *(Lisp_Object *)((char *)v92 + (CELL-TAG_VECTOR) + ((int32_t)v59/(16/CELL))) = v37;
    return onevalue(v183);

v87:
    v37 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v37; /* unidev_nextp!* */
    goto v119;

v114:
    v37 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v37; /* unidev_next!* */
    goto v116;
}



/* Code for general!-reduce!-mod!-p */

static Lisp_Object CC_generalKreduceKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-mod-p");
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
    v107 = stack[-1];
    if (v107 == nil) goto v58;
    v107 = stack[-1];
    if (!consp(v107)) goto v17;
    v107 = stack[-1];
    v107 = qcar(v107);
    v107 = (consp(v107) ? nil : lisp_true);
    goto v15;

v15:
    if (v107 == nil) goto v31;
    v107 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-number */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v108 = v107;
    v107 = v108;
    v107 = (Lisp_Object)zerop(v107);
    v107 = v107 ? lisp_true : nil;
    env = stack[-3];
    if (v107 == nil) { popv(4); return onevalue(v108); }
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v107); }

v31:
    v107 = stack[-1];
    v107 = qcar(v107);
    stack[-2] = qcar(v107);
    v107 = stack[-1];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    stack[0] = CC_generalKreduceKmodKp(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = CC_generalKreduceKmodKp(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    {
        Lisp_Object v122 = stack[-2];
        Lisp_Object v110 = stack[0];
        popv(4);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v122, v110, v107);
    }

v17:
    v107 = qvalue(elt(env, 2)); /* t */
    goto v15;

v58:
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v107); }
/* error exit handlers */
v85:
    popv(4);
    return nil;
}



/* Code for nonlnrsys */

static Lisp_Object CC_nonlnrsys(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnrsys");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */

v57:
    v39 = stack[-1];
    if (v39 == nil) goto v97;
    v39 = stack[-1];
    v35 = qcar(v39);
    v39 = stack[0];
    fn = elt(env, 2); /* nonlnr */
    v39 = (*qfn2(fn))(qenv(fn), v35, v39);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    if (!(v39 == nil)) { popv(3); return onevalue(v39); }
    v39 = stack[-1];
    v35 = qcdr(v39);
    v39 = stack[0];
    stack[-1] = v35;
    stack[0] = v39;
    goto v57;

v97:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v39); }
/* error exit handlers */
v104:
    popv(3);
    return nil;
}



/* Code for crprcd */

static Lisp_Object CC_crprcd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprcd");
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
    v84 = stack[0];
    v84 = qcdr(v84);
    v84 = qcar(v84);
    if (!consp(v84)) goto v97;
    v85 = elt(env, 1); /* !:rd!: */
    v84 = stack[0];
    v84 = qcdr(v84);
    v84 = qcar(v84);
    v84 = cons(v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    goto v58;

v58:
    fn = elt(env, 2); /* convchk */
    stack[-1] = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v84 = stack[0];
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    if (!consp(v84)) goto v23;
    v85 = elt(env, 1); /* !:rd!: */
    v84 = stack[0];
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = cons(v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    goto v52;

v52:
    fn = elt(env, 2); /* convchk */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v151;
    v85 = stack[-1];
    popv(3);
    return cons(v85, v84);

v23:
    v84 = stack[0];
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    goto v52;

v97:
    v84 = stack[0];
    v84 = qcdr(v84);
    v84 = qcar(v84);
    goto v58;
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for gcref_select */

static Lisp_Object CC_gcref_select(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_select");
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
    v3 = v0;
/* end of prologue */
    stack[-3] = v3;
    goto v100;

v100:
    v3 = stack[-3];
    if (v3 == nil) goto v17;
    v3 = stack[-3];
    v3 = qcar(v3);
    v203 = v3;
    v4 = v203;
    v3 = elt(env, 2); /* defd */
    v3 = Lflagp(nil, v4, v3);
    env = stack[-4];
    if (v3 == nil) goto v62;
    v4 = v203;
    v3 = qvalue(elt(env, 3)); /* gcref_nolist!* */
    v3 = Lmemq(nil, v4, v3);
    v3 = (v3 == nil ? lisp_true : nil);
    goto v116;

v116:
    if (v3 == nil) goto v87;
    v3 = v203;
    v3 = ncons(v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    goto v30;

v30:
    stack[-2] = v3;
    v3 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    stack[-1] = v3;
    v3 = stack[-3];
    v3 = qcdr(v3);
    stack[-3] = v3;
    v3 = stack[-1];
    if (!consp(v3)) goto v100;
    else goto v50;

v50:
    v3 = stack[-3];
    if (v3 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v3 = stack[-3];
    v3 = qcar(v3);
    v203 = v3;
    v4 = v203;
    v3 = elt(env, 2); /* defd */
    v3 = Lflagp(nil, v4, v3);
    env = stack[-4];
    if (v3 == nil) goto v214;
    v4 = v203;
    v3 = qvalue(elt(env, 3)); /* gcref_nolist!* */
    v3 = Lmemq(nil, v4, v3);
    v3 = (v3 == nil ? lisp_true : nil);
    goto v177;

v177:
    if (v3 == nil) goto v82;
    v3 = v203;
    v3 = ncons(v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    goto v121;

v121:
    v3 = Lrplacd(nil, stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v3 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    stack[-1] = v3;
    v3 = stack[-3];
    v3 = qcdr(v3);
    stack[-3] = v3;
    goto v50;

v82:
    v3 = nil;
    goto v121;

v214:
    v3 = qvalue(elt(env, 1)); /* nil */
    goto v177;

v87:
    v3 = nil;
    goto v30;

v62:
    v3 = qvalue(elt(env, 1)); /* nil */
    goto v116;

v17:
    v3 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v3); }
/* error exit handlers */
v11:
    popv(5);
    return nil;
}



/* Code for polynommultiplybyvariable */

static Lisp_Object CC_polynommultiplybyvariable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynommultiplybyvariable");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v102;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v12 = stack[-2];
    stack[0] = v12;
    goto v1;

v1:
    v12 = stack[0];
    v12 = qcar(v12);
    if (v12 == nil) goto v20;
    v12 = stack[0];
    v11 = qcar(v12);
    v12 = stack[-1];
    fn = elt(env, 2); /* monomgetvariabledegree */
    v11 = (*qfn2(fn))(qenv(fn), v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    v12 = (Lisp_Object)1; /* 0 */
    v12 = Leqn(nil, v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    if (v12 == nil) goto v60;
    v12 = stack[0];
    v11 = qcar(v12);
    v12 = stack[-3];
    v12 = cons(v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    stack[-3] = v12;
    v11 = stack[0];
    v12 = stack[0];
    v12 = qcdr(v12);
    v12 = qcar(v12);
    v11 = Lrplaca(nil, v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    v12 = stack[0];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = Lrplacd(nil, v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    goto v1;

v60:
    v12 = stack[0];
    v12 = qcdr(v12);
    stack[0] = v12;
    goto v1;

v20:
    v11 = qvalue(elt(env, 1)); /* nil */
    v12 = stack[-3];
    v12 = cons(v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    stack[-3] = v12;
    v12 = stack[-3];
    v12 = Lreverse(nil, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    stack[-3] = v12;
    v12 = stack[-3];
    stack[0] = v12;
    goto v59;

v59:
    v12 = stack[0];
    v12 = qcar(v12);
    if (v12 == nil) goto v146;
    v12 = stack[0];
    v11 = qcar(v12);
    v12 = stack[-1];
    fn = elt(env, 3); /* monommultiplybyvariable */
    v12 = (*qfn2(fn))(qenv(fn), v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    v12 = stack[0];
    v12 = qcdr(v12);
    stack[0] = v12;
    goto v59;

v146:
    v11 = stack[-2];
    v12 = stack[-3];
    fn = elt(env, 4); /* polynomadd */
    v12 = (*qfn2(fn))(qenv(fn), v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v217;
    v12 = nil;
    { popv(5); return onevalue(v12); }
/* error exit handlers */
v217:
    popv(5);
    return nil;
}



/* Code for exptf */

static Lisp_Object CC_exptf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptf");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v20 = stack[0];
    v19 = (Lisp_Object)1; /* 0 */
    v19 = (Lisp_Object)lessp2(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v178;
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v114;
    v218 = elt(env, 1); /* "exptf" */
    v20 = stack[-1];
    v19 = stack[0];
    v19 = list3(v218, v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* errach */
        return (*qfn1(fn))(qenv(fn), v19);
    }

v114:
    v19 = stack[-1];
    if (!consp(v19)) goto v18;
    v19 = stack[-1];
    v19 = qcar(v19);
    v19 = (consp(v19) ? nil : lisp_true);
    goto v24;

v24:
    if (v19 == nil) goto v23;
    v20 = stack[-1];
    v19 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v20, v19);
    }

v23:
    v19 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v19 == nil)) goto v109;
    v19 = stack[-1];
    fn = elt(env, 6); /* kernlp */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-2];
    if (!(v19 == nil)) goto v109;
    v20 = stack[-1];
    v19 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* mksfpf */
        return (*qfn2(fn))(qenv(fn), v20, v19);
    }

v109:
    v20 = stack[-1];
    v19 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* exptf1 */
        return (*qfn2(fn))(qenv(fn), v20, v19);
    }

v18:
    v19 = qvalue(elt(env, 2)); /* t */
    goto v24;
/* error exit handlers */
v178:
    popv(3);
    return nil;
}



/* Code for cl_susiupdknowl */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, Lisp_Object v105, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v53, v63, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v105,v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v102,v111,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    v36 = v111;
    stack[-1] = v102;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v1;

v1:
    v53 = stack[-1];
    if (v53 == nil) goto v54;
    v53 = stack[-1];
    v53 = qcar(v53);
    stack[-3] = v53;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    v189 = stack[-2];
    v63 = stack[-3];
    v53 = v36;
    v36 = stack[0];
    fn = elt(env, 4); /* cl_susiupdknowl1 */
    v36 = (*qfnn(fn))(qenv(fn), 4, v189, v63, v53, v36);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v63 = v36;
    v53 = elt(env, 2); /* false */
    if (!(v63 == v53)) goto v1;
    v53 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v53;
    v53 = elt(env, 3); /* break */
    stack[-3] = v53;
    goto v1;

v54:
    v63 = stack[-3];
    v53 = elt(env, 3); /* break */
    if (!(v63 == v53)) { popv(5); return onevalue(v36); }
    v36 = elt(env, 2); /* false */
    { popv(5); return onevalue(v36); }
/* error exit handlers */
v167:
    popv(5);
    return nil;
}



/* Code for tobvarir */

static Lisp_Object CC_tobvarir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tobvarir");
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
    v24 = stack[-1];
    if (v24 == nil) goto v97;
    stack[-2] = elt(env, 1); /* bvar */
    v24 = stack[-1];
    v18 = qcar(v24);
    v24 = (Lisp_Object)17; /* 1 */
    stack[0] = list2(v18, v24);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-3];
    v24 = stack[-1];
    v24 = qcdr(v24);
    v24 = CC_tobvarir(env, v24);
    nil = C_nil;
    if (exception_pending()) goto v186;
    {
        Lisp_Object v104 = stack[-2];
        Lisp_Object v31 = stack[0];
        popv(4);
        return acons(v104, v31, v24);
    }

v97:
    v24 = nil;
    { popv(4); return onevalue(v24); }
/* error exit handlers */
v186:
    popv(4);
    return nil;
}



/* Code for bc2a */

static Lisp_Object CC_bc2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v23 = v0;
/* end of prologue */
    v52 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (!(v52 == nil)) return onevalue(v23);
    v52 = v23;
    v52 = qcar(v52);
    if (v52 == nil) goto v17;
    v52 = elt(env, 2); /* prepf */
    {
        fn = elt(env, 3); /* sqform */
        return (*qfn2(fn))(qenv(fn), v23, v52);
    }

v17:
    v52 = (Lisp_Object)1; /* 0 */
    return onevalue(v52);
}



/* Code for listdiff */

static Lisp_Object CC_listdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    v25 = v0;
/* end of prologue */

v97:
    v24 = stack[0];
    if (v24 == nil) { popv(2); return onevalue(v25); }
    v24 = v25;
    if (v24 == nil) goto v17;
    v24 = stack[0];
    v24 = qcar(v24);
    v25 = Ldelete(nil, v24, v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[0] = v24;
    goto v97;

v17:
    v25 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v25); }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec1");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v109 = stack[-1];
    v108 = (Lisp_Object)17; /* 1 */
    if (v109 == v108) goto v97;
    v108 = stack[-1];
    v109 = sub1(v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v108 = stack[0];
    v108 = qcdr(v108);
    fn = elt(env, 1); /* inttovec!-solve */
    v108 = (*qfn2(fn))(qenv(fn), v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    stack[-2] = v108;
    v108 = stack[0];
    v109 = qcar(v108);
    v108 = stack[-2];
    v108 = qcar(v108);
    stack[0] = difference2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v108 = stack[-1];
    v109 = sub1(v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v108 = stack[-2];
    v108 = CC_inttovec1(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v122;
    {
        Lisp_Object v110 = stack[0];
        popv(4);
        return cons(v110, v108);
    }

v97:
    v108 = stack[0];
    v108 = qcar(v108);
    popv(4);
    return ncons(v108);
/* error exit handlers */
v122:
    popv(4);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v110, v151, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cstimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v110 = v102;
    v151 = v0;
/* end of prologue */

v114:
    v122 = v151;
    if (v122 == nil) goto v101;
    v122 = v151;
    v36 = qcar(v122);
    v122 = (Lisp_Object)17; /* 1 */
    if (v36 == v122) goto v195;
    v122 = v151;
    v122 = qcdr(v122);
    stack[0] = v122;
    v122 = v151;
    v122 = qcar(v122);
    v122 = cons(v122, v110);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-1];
    v110 = v122;
    v122 = stack[0];
    v151 = v122;
    goto v114;

v195:
    v122 = v151;
    v122 = qcdr(v122);
    v151 = v122;
    goto v114;

v101:
    v122 = v110;
    if (v122 == nil) goto v2;
    v122 = v110;
    v122 = qcdr(v122);
    if (v122 == nil) goto v194;
    v122 = elt(env, 1); /* times */
    popv(2);
    return cons(v122, v110);

v194:
    v122 = v110;
    v122 = qcar(v122);
    { popv(2); return onevalue(v122); }

v2:
    v122 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v122); }
/* error exit handlers */
v63:
    popv(2);
    return nil;
}



/* Code for repasc */

static Lisp_Object MS_CDECL CC_repasc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v147, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "repasc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repasc");
#endif
    if (stack >= stacklimit)
    {
        push3(v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v102,v111);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v111;
    stack[-1] = v102;
    stack[-2] = v0;
/* end of prologue */
    v148 = nil;
    goto v100;

v100:
    v59 = stack[0];
    if (v59 == nil) goto v2;
    v147 = stack[-2];
    v59 = stack[0];
    v59 = qcar(v59);
    v59 = qcar(v59);
    if (equal(v147, v59)) goto v108;
    v59 = stack[0];
    v59 = qcar(v59);
    v147 = v148;
    v59 = cons(v59, v147);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v148 = v59;
    v59 = stack[0];
    v59 = qcdr(v59);
    stack[0] = v59;
    goto v100;

v108:
    stack[-3] = v148;
    v148 = stack[-2];
    v147 = stack[-1];
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = acons(v148, v147, v59);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    {
        Lisp_Object v210 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v210, v59);
    }

v2:
    stack[0] = v148;
    v148 = elt(env, 1); /* "key" */
    v147 = stack[-2];
    v59 = elt(env, 2); /* "not found" */
    v59 = list3(v148, v147, v59);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v147 = v59;
    v59 = v147;
    qvalue(elt(env, 3)) = v59; /* errmsg!* */
    v59 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v59 == nil)) goto v104;
    v59 = v147;
    fn = elt(env, 6); /* lprie */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    goto v104;

v104:
    v59 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v59 = nil;
    {
        Lisp_Object v149 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v149, v59);
    }
/* error exit handlers */
v77:
    popv(5);
    return nil;
}



/* Code for formsetq */

static Lisp_Object MS_CDECL CC_formsetq(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v59, v147, v148, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v147 = v111;
    v148 = v102;
    v209 = v0;
/* end of prologue */
    v59 = v147;
    v183 = elt(env, 1); /* symbolic */
    if (v59 == v183) goto v25;
    v183 = v209;
    v59 = v148;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v183, v59, v147);
    }

v25:
    v183 = v209;
    v183 = qcdr(v183);
    v59 = qcar(v183);
    v183 = elt(env, 2); /* list */
    if (!consp(v59)) goto v54;
    v59 = qcar(v59);
    if (!(v59 == v183)) goto v54;
    v183 = v209;
    v59 = v148;
    {
        fn = elt(env, 5); /* formsetq1 */
        return (*qfnn(fn))(qenv(fn), 3, v183, v59, v147);
    }

v54:
    v183 = v209;
    v183 = qcdr(v183);
    v59 = qcar(v183);
    v183 = elt(env, 3); /* cons */
    if (!consp(v59)) goto v218;
    v59 = qcar(v59);
    if (!(v59 == v183)) goto v218;
    v183 = v209;
    v59 = v148;
    {
        fn = elt(env, 6); /* formsetq2 */
        return (*qfnn(fn))(qenv(fn), 3, v183, v59, v147);
    }

v218:
    v183 = v209;
    v59 = v148;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v183, v59, v147);
    }
}



/* Code for th_match */

static Lisp_Object CC_th_match(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */
    v186 = stack[-1];
    v195 = stack[0];
    fn = elt(env, 2); /* th_match0 */
    v195 = (*qfn2(fn))(qenv(fn), v186, v195);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    if (v195 == nil) goto v97;
    v195 = stack[-1];
    v195 = qcdr(v195);
    v195 = qcar(v195);
    fn = elt(env, 3); /* dl_get */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    stack[-1] = Llength(nil, v195);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v195 = stack[0];
    v195 = qcdr(v195);
    v195 = qcar(v195);
    fn = elt(env, 3); /* dl_get */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v195 = Llength(nil, v195);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v195 = (equal(stack[-1], v195) ? lisp_true : nil);
    { popv(3); return onevalue(v195); }

v97:
    v195 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v195); }
/* error exit handlers */
v103:
    popv(3);
    return nil;
}



/* Code for general!-expt!-mod!-p */

static Lisp_Object CC_generalKexptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v178, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-expt-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v177 = v102;
    stack[0] = v0;
/* end of prologue */
    v178 = v177;
    v82 = (Lisp_Object)1; /* 0 */
    if (v178 == v82) goto v97;
    v178 = v177;
    v82 = (Lisp_Object)17; /* 1 */
    if (v178 == v82) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v178 = v177;
    v82 = (Lisp_Object)33; /* 2 */
    v82 = Ldivide(nil, v178, v82);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    stack[-1] = v82;
    v178 = stack[0];
    v82 = stack[-1];
    v82 = qcar(v82);
    v82 = CC_generalKexptKmodKp(env, v178, v82);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v177 = v82;
    v82 = v177;
    v178 = v177;
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v82 = (*qfn2(fn))(qenv(fn), v82, v178);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v177 = v82;
    v82 = stack[-1];
    v178 = qcdr(v82);
    v82 = (Lisp_Object)1; /* 0 */
    if (v178 == v82) { popv(3); return onevalue(v177); }
    v178 = v177;
    v82 = stack[0];
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v82 = (*qfn2(fn))(qenv(fn), v178, v82);
    nil = C_nil;
    if (exception_pending()) goto v38;
    v177 = v82;
    { popv(3); return onevalue(v177); }

v97:
    v82 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v82); }
/* error exit handlers */
v38:
    popv(3);
    return nil;
}



/* Code for simpqg */

static Lisp_Object CC_simpqg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpqg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v15 = v1;
    v1 = elt(env, 1); /* qg */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v15, v1);
    }
}



/* Code for revalx */

static Lisp_Object CC_revalx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalx");
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
    v89 = v0;
/* end of prologue */
    v116 = v89;
    if (!consp(v116)) goto v40;
    v116 = v89;
    v116 = qcar(v116);
    v116 = (consp(v116) ? nil : lisp_true);
    v116 = (v116 == nil ? lisp_true : nil);
    goto v50;

v50:
    if (v116 == nil) goto v166;
    v116 = v89;
    fn = elt(env, 2); /* prepf */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[0];
    goto v58;

v58:
    {
        popv(1);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v166:
    v116 = v89;
    goto v58;

v40:
    v116 = qvalue(elt(env, 1)); /* nil */
    goto v50;
/* error exit handlers */
v98:
    popv(1);
    return nil;
}



/* Code for setunion */

static Lisp_Object CC_setunion(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v61, v119;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setunion");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    v61 = v0;
/* end of prologue */

v97:
    v83 = stack[0];
    if (v83 == nil) { popv(3); return onevalue(v61); }
    v83 = stack[0];
    v119 = qcar(v83);
    v83 = v61;
    v83 = Lmember(nil, v119, v83);
    if (v83 == nil) goto v23;
    v83 = stack[0];
    v83 = qcdr(v83);
    stack[0] = v83;
    goto v97;

v23:
    stack[-1] = v61;
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = ncons(v83);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v83 = Lappend(nil, stack[-1], v83);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v61 = v83;
    v83 = stack[0];
    v83 = qcdr(v83);
    stack[0] = v83;
    goto v97;
/* error exit handlers */
v62:
    popv(3);
    return nil;
}



/* Code for vdp_zero!? */

static Lisp_Object CC_vdp_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_zero?");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v0;
/* end of prologue */
    fn = elt(env, 1); /* vdp_poly */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    errexit();
    v97 = (v97 == nil ? lisp_true : nil);
    return onevalue(v97);
}



/* Code for vdpred */

static Lisp_Object CC_vdpred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpred");
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
    v148 = stack[-3];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    stack[-4] = v148;
    v148 = stack[-4];
    if (v148 == nil) goto v56;
    stack[-2] = elt(env, 1); /* vdp */
    v148 = stack[-4];
    stack[-1] = qcar(v148);
    v148 = stack[-4];
    v148 = qcdr(v148);
    stack[0] = qcar(v148);
    v209 = stack[-4];
    v148 = qvalue(elt(env, 2)); /* nil */
    v148 = list2(v209, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v148 = list3star(stack[-2], stack[-1], stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-4] = v148;
    v148 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v148 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v209 = stack[-3];
    v148 = elt(env, 4); /* sugar */
    fn = elt(env, 5); /* vdpgetprop */
    v209 = (*qfn2(fn))(qenv(fn), v209, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v148 = v209;
    if (v209 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v209 = stack[-4];
    fn = elt(env, 6); /* gsetsugar */
    v148 = (*qfn2(fn))(qenv(fn), v209, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v56:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v148 = qvalue(elt(env, 2)); /* nil */
    stack[0] = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v209 = qvalue(elt(env, 2)); /* nil */
    v148 = qvalue(elt(env, 2)); /* nil */
    v148 = list2(v209, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    {
        Lisp_Object v150 = stack[-2];
        Lisp_Object v190 = stack[-1];
        Lisp_Object v41 = stack[0];
        popv(6);
        return list3star(v150, v190, v41, v148);
    }
/* error exit handlers */
v149:
    popv(6);
    return nil;
}



/* Code for freeoffl */

static Lisp_Object CC_freeoffl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeoffl");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v0;
/* end of prologue */

v57:
    v104 = stack[0];
    if (v104 == nil) goto v97;
    v31 = stack[-1];
    v104 = stack[0];
    v104 = qcar(v104);
    fn = elt(env, 3); /* freeoff */
    v104 = (*qfn2(fn))(qenv(fn), v31, v104);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    if (v104 == nil) goto v16;
    v31 = stack[-1];
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[-1] = v31;
    stack[0] = v104;
    goto v57;

v16:
    v104 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v104); }

v97:
    v104 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v104); }
/* error exit handlers */
v61:
    popv(3);
    return nil;
}



/* Code for triviallcm */

static Lisp_Object MS_CDECL CC_triviallcm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v102,
                         Lisp_Object v111, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "triviallcm");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triviallcm");
#endif
    if (stack >= stacklimit)
    {
        push3(v111,v102,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v102,v111);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v111;
    v30 = v102;
    v56 = v0;
/* end of prologue */
    fn = elt(env, 1); /* xdiv */
    v30 = (*qfn2(fn))(qenv(fn), v30, v56);
    nil = C_nil;
    if (exception_pending()) goto v87;
    v56 = stack[0];
    v56 = (equal(v30, v56) ? lisp_true : nil);
    { popv(1); return onevalue(v56); }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



setup_type const u14_setup[] =
{
    {"matsm*1",                 CC_matsmH1,     too_many_1,    wrong_no_1},
    {"chk",                     CC_chk,         too_many_1,    wrong_no_1},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"fctlength",               CC_fctlength,   too_many_1,    wrong_no_1},
    {"trwrite",                 CC_trwrite,     too_many_1,    wrong_no_1},
    {"endstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_endstat},
    {"evalequal",               too_few_2,      CC_evalequal,  wrong_no_2},
    {"listtest",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_listtest},
    {"ad_numsort",              CC_ad_numsort,  too_many_1,    wrong_no_1},
    {"lambda_lqlbvc_3",         too_few_2,      CC_lambda_lqlbvc_3,wrong_no_2},
    {"moduntag",                CC_moduntag,    too_many_1,    wrong_no_1},
    {"image-of-power",          too_few_2,      CC_imageKofKpower,wrong_no_2},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"polynomheadreduceby",     too_few_2,      CC_polynomheadreduceby,wrong_no_2},
    {"simpg3",                  CC_simpg3,      too_many_1,    wrong_no_1},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"cl_susiupdknowl1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl1},
    {"rl_simp1",                CC_rl_simp1,    too_many_1,    wrong_no_1},
    {"nary",                    too_few_2,      CC_nary,       wrong_no_2},
    {"opmtch",                  CC_opmtch,      too_many_1,    wrong_no_1},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"evaluate1",               too_few_2,      CC_evaluate1,  wrong_no_2},
    {"lispassignp",             CC_lispassignp, too_many_1,    wrong_no_1},
    {"assert_uninstall1",       CC_assert_uninstall1,too_many_1,wrong_no_1},
    {"dp_times_bcmo",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dp_times_bcmo},
    {"addgt",                   CC_addgt,       too_many_1,    wrong_no_1},
    {"wi_new",                  CC_wi_new,      too_many_1,    wrong_no_1},
    {"tensorp",                 CC_tensorp,     too_many_1,    wrong_no_1},
    {"dfprint",                 CC_dfprint,     too_many_1,    wrong_no_1},
    {"ofsf_entry2at",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at},
    {"squared+matrix+p",        CC_squaredLmatrixLp,too_many_1,wrong_no_1},
    {"mri_realvarp",            CC_mri_realvarp,too_many_1,    wrong_no_1},
    {"searchpl",                CC_searchpl,    too_many_1,    wrong_no_1},
    {"ibalp_var-satlist",       too_few_2,      CC_ibalp_varKsatlist,wrong_no_2},
    {"quotfail1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfail1},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"bcquot",                  too_few_2,      CC_bcquot,     wrong_no_2},
    {"bcneg",                   CC_bcneg,       too_many_1,    wrong_no_1},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"delete-dups",             CC_deleteKdups, too_many_1,    wrong_no_1},
    {"cut:mt",                  too_few_2,      CC_cutTmt,     wrong_no_2},
    {"mv-domainlist-*",         too_few_2,      CC_mvKdomainlistKH,wrong_no_2},
    {"groeb=better",            too_few_2,      CC_groebMbetter,wrong_no_2},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"next-random-number",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nextKrandomKnumber},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,too_many_1,wrong_no_1},
    {"nonlnrsys",               too_few_2,      CC_nonlnrsys,  wrong_no_2},
    {"crprcd",                  CC_crprcd,      too_many_1,    wrong_no_1},
    {"gcref_select",            CC_gcref_select,too_many_1,    wrong_no_1},
    {"polynommultiplybyvariable",too_few_2,     CC_polynommultiplybyvariable,wrong_no_2},
    {"exptf",                   too_few_2,      CC_exptf,      wrong_no_2},
    {"cl_susiupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
    {"bc2a",                    CC_bc2a,        too_many_1,    wrong_no_1},
    {"listdiff",                too_few_2,      CC_listdiff,   wrong_no_2},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"repasc",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_repasc},
    {"formsetq",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq},
    {"th_match",                too_few_2,      CC_th_match,   wrong_no_2},
    {"general-expt-mod-p",      too_few_2,      CC_generalKexptKmodKp,wrong_no_2},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"freeoffl",                too_few_2,      CC_freeoffl,   wrong_no_2},
    {"triviallcm",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_triviallcm},
    {NULL, (one_args *)"u14", (two_args *)"1455 4645105 2120687", 0}
};

/* end of generated code */