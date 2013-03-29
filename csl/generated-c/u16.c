
/* $destdir\u16.c        Machine generated C code */

/* Signature: 00000000 26-Mar-2013 */

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
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space;
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


/* Code for listeval */

static Lisp_Object CC_listeval(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0038, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0037 = qvalue(elt(env, 1)); /* simpcount!* */
    v0038 = add1(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0038; /* simpcount!* */
    v0037 = qvalue(elt(env, 2)); /* simplimit!* */
    v0037 = (Lisp_Object)greaterp2(v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0037 = v0037 ? lisp_true : nil;
    env = stack[-5];
    if (v0037 == nil) goto v0041;
    v0037 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0037; /* simpcount!* */
    v0039 = elt(env, 3); /* rlisp */
    v0038 = (Lisp_Object)289; /* 18 */
    v0037 = elt(env, 4); /* "Simplification recursion too deep" */
    fn = elt(env, 9); /* rerror */
    v0037 = (*qfnn(fn))(qenv(fn), 3, v0039, v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    goto v0041;

v0041:
    v0037 = stack[0];
    if (!consp(v0037)) goto v0042;
    v0037 = stack[0];
    v0038 = qcar(v0037);
    v0037 = elt(env, 5); /* list */
    if (v0038 == v0037) goto v0043;
    v0037 = stack[0];
    v0038 = qcar(v0037);
    v0037 = elt(env, 7); /* listfn */
    v0037 = get(v0038, v0037);
    env = stack[-5];
    v0038 = v0037;
    v0037 = v0038;
    if (v0037 == nil) goto v0044;
    v0039 = v0038;
    v0037 = stack[0];
    v0038 = qcdr(v0037);
    v0037 = stack[-3];
    v0037 = Lapply2(nil, 3, v0039, v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    goto v0045;

v0045:
    stack[0] = v0037;
    v0037 = qvalue(elt(env, 1)); /* simpcount!* */
    v0037 = sub1(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0037; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0044:
    v0039 = elt(env, 3); /* rlisp */
    v0038 = (Lisp_Object)305; /* 19 */
    v0037 = elt(env, 8); /* "Illegal operation on lists" */
    fn = elt(env, 9); /* rerror */
    v0037 = (*qfnn(fn))(qenv(fn), 3, v0039, v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    goto v0045;

v0043:
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    stack[-4] = v0037;
    v0037 = stack[-4];
    if (v0037 == nil) goto v0046;
    v0037 = stack[-4];
    v0037 = qcar(v0037);
    v0038 = v0037;
    v0037 = stack[-3];
    fn = elt(env, 10); /* reval1 */
    v0037 = (*qfn2(fn))(qenv(fn), v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0037 = ncons(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    stack[-1] = v0037;
    stack[-2] = v0037;
    goto v0047;

v0047:
    v0037 = stack[-4];
    v0037 = qcdr(v0037);
    stack[-4] = v0037;
    v0037 = stack[-4];
    if (v0037 == nil) goto v0048;
    stack[0] = stack[-1];
    v0037 = stack[-4];
    v0037 = qcar(v0037);
    v0038 = v0037;
    v0037 = stack[-3];
    fn = elt(env, 10); /* reval1 */
    v0037 = (*qfn2(fn))(qenv(fn), v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0037 = ncons(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0037 = Lrplacd(nil, stack[0], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0037 = stack[-1];
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    goto v0047;

v0048:
    v0037 = stack[-2];
    goto v0049;

v0049:
    fn = elt(env, 11); /* makelist */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    goto v0045;

v0046:
    v0037 = qvalue(elt(env, 6)); /* nil */
    goto v0049;

v0042:
    v0037 = stack[0];
    if (!symbolp(v0037)) v0037 = nil;
    else { v0037 = qfastgets(v0037);
           if (v0037 != nil) { v0037 = elt(v0037, 4); /* avalue */
#ifdef RECORD_GET
             if (v0037 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0037 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0037 == SPID_NOPROP) v0037 = nil; }}
#endif
    v0038 = v0037;
    v0037 = stack[0];
    if (!symbolp(v0037)) v0037 = nil;
    else { v0037 = qfastgets(v0037);
           if (v0037 != nil) { v0037 = elt(v0037, 17); /* share */
#ifdef RECORD_GET
             if (v0037 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0037 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0037 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0037 == SPID_NOPROP) v0037 = nil; else v0037 = lisp_true; }}
#endif
    if (v0037 == nil) goto v0050;
    v0037 = stack[0];
    fn = elt(env, 12); /* eval */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0038 = v0037;
    goto v0051;

v0051:
    v0037 = stack[-3];
    v0037 = CC_listeval(env, v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    goto v0045;

v0050:
    v0037 = v0038;
    if (v0037 == nil) goto v0052;
    v0037 = v0038;
    v0037 = qcdr(v0037);
    v0037 = qcar(v0037);
    v0038 = v0037;
    goto v0051;

v0052:
    v0038 = stack[0];
    v0037 = elt(env, 5); /* list */
    fn = elt(env, 13); /* typerr */
    v0037 = (*qfn2(fn))(qenv(fn), v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0038 = v0037;
    goto v0051;
/* error exit handlers */
v0040:
    popv(6);
    return nil;
}



/* Code for my_freeof */

static Lisp_Object CC_my_freeof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0042, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_freeof");
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
    v0042 = stack[0];
    v0045 = stack[-1];
    fn = elt(env, 3); /* smember */
    v0045 = (*qfn2(fn))(qenv(fn), v0042, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    if (v0045 == nil) goto v0058;
    v0045 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0045); }

v0058:
    v0056 = qvalue(elt(env, 1)); /* depl!* */
    v0042 = stack[-1];
    v0045 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeofdepl */
        return (*qfnn(fn))(qenv(fn), 3, v0056, v0042, v0045);
    }
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for deleteall */

static Lisp_Object CC_deleteall(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0051, v0062, v0063;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteall");
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
    v0062 = nil;
    goto v0064;

v0064:
    v0061 = stack[0];
    if (v0061 == nil) { popv(4); return onevalue(v0062); }
    v0061 = stack[0];
    v0061 = qcar(v0061);
    v0063 = v0061;
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    stack[0] = v0061;
    v0051 = v0063;
    v0061 = stack[-1];
    if (equal(v0051, v0061)) goto v0064;
    stack[-2] = v0062;
    v0061 = v0063;
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0061 = Lnconc(nil, stack[-2], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0062 = v0061;
    goto v0064;
/* error exit handlers */
v0050:
    popv(4);
    return nil;
}



/* Code for command */

static Lisp_Object MS_CDECL CC_command(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0106, v0107, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command");
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
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-1] = qvalue(elt(env, 2)); /* loopdelimslist!* */
    qvalue(elt(env, 2)) = nil; /* loopdelimslist!* */
    v0105 = qvalue(elt(env, 3)); /* !*demo */
    if (v0105 == nil) goto v0055;
    v0105 = qvalue(elt(env, 4)); /* ifl!* */
    if (v0105 == nil) goto v0055;
    fn = elt(env, 29); /* commdemo */
    v0105 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0064;

v0064:
    qvalue(elt(env, 2)) = stack[-1]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-2]; /* errmsg!* */
    { popv(4); return onevalue(v0105); }

v0055:
    v0105 = qvalue(elt(env, 5)); /* !*slin */
    if (v0105 == nil) goto v0054;
    v0105 = qvalue(elt(env, 7)); /* !*reduce4 */
    goto v0053;

v0053:
    if (!(v0105 == nil)) goto v0110;
    fn = elt(env, 30); /* setcloc!* */
    v0105 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0105 = qvalue(elt(env, 8)); /* lreadfn!* */
    if (v0105 == nil) goto v0050;
    v0106 = qvalue(elt(env, 8)); /* lreadfn!* */
    v0105 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 31); /* lispapply */
    v0105 = (*qfn2(fn))(qenv(fn), v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0111;

v0111:
    stack[0] = v0105;
    goto v0112;

v0112:
    v0105 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v0105 == nil) goto v0029;
    v0105 = qvalue(elt(env, 25)); /* !*debug */
    if (v0105 == nil) goto v0113;
    v0105 = elt(env, 26); /* "Parse: " */
    v0105 = Lprinc(nil, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0105 = stack[0];
    fn = elt(env, 32); /* prettyprint */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0113;

v0113:
    v0106 = qvalue(elt(env, 18)); /* key!* */
    v0105 = elt(env, 27); /* !*semicol!* */
    if (v0106 == v0105) goto v0110;
    v0105 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v0105 == nil) goto v0114;
    v0105 = stack[0];
    fn = elt(env, 33); /* n_form */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    stack[0] = v0105;
    goto v0115;

v0115:
    v0105 = qvalue(elt(env, 25)); /* !*debug */
    if (v0105 == nil) goto v0116;
    v0105 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0105 = elt(env, 28); /* "Form: " */
    v0105 = Lprinc(nil, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0105 = stack[0];
    fn = elt(env, 32); /* prettyprint */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0116;

v0116:
    v0105 = stack[0];
    goto v0064;

v0114:
    v0105 = stack[0];
    fn = elt(env, 34); /* form */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    stack[0] = v0105;
    goto v0115;

v0110:
    fn = elt(env, 35); /* readch1 */
    v0105 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    qvalue(elt(env, 10)) = v0105; /* crchar!* */
    v0106 = qvalue(elt(env, 10)); /* crchar!* */
    v0105 = qvalue(elt(env, 11)); /* !$eol!$ */
    if (equal(v0106, v0105)) goto v0110;
    fn = elt(env, 36); /* command1 */
    v0105 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    stack[0] = v0105;
    goto v0112;

v0029:
    v0105 = qvalue(elt(env, 12)); /* !*struct */
    if (v0105 == nil) goto v0117;
    v0105 = stack[0];
    fn = elt(env, 37); /* structchk */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    stack[0] = v0105;
    goto v0117;

v0117:
    v0105 = qvalue(elt(env, 13)); /* !*pret */
    if (v0105 == nil) goto v0118;
    v0105 = stack[0];
    if (!consp(v0105)) goto v0020;
    v0105 = stack[0];
    v0106 = qcar(v0105);
    v0105 = elt(env, 14); /* (in out shut) */
    v0105 = Lmemq(nil, v0106, v0105);
    v0105 = (v0105 == nil ? lisp_true : nil);
    goto v0021;

v0021:
    if (v0105 == nil) goto v0118;
    v0105 = stack[0];
    if (v0105 == nil) goto v0119;
    v0105 = qvalue(elt(env, 9)); /* nil */
    goto v0120;

v0120:
    if (v0105 == nil) goto v0014;
    v0105 = elt(env, 16); /* end */
    fn = elt(env, 38); /* rprint */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0118;

v0118:
    v0105 = qvalue(elt(env, 5)); /* !*slin */
    if (v0105 == nil) goto v0121;
    v0106 = elt(env, 17); /* symbolic */
    v0105 = stack[0];
    v0105 = list2(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0064;

v0121:
    v0105 = stack[0];
    fn = elt(env, 34); /* form */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0106 = v0105;
    v0105 = qvalue(elt(env, 18)); /* key!* */
    if (!symbolp(v0105)) v0105 = nil;
    else { v0105 = qfastgets(v0105);
           if (v0105 != nil) { v0105 = elt(v0105, 48); /* modefn */
#ifdef RECORD_GET
             if (v0105 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0105 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0105 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0105 == SPID_NOPROP) v0105 = nil; else v0105 = lisp_true; }}
#endif
    if (v0105 == nil) goto v0122;
    v0105 = qvalue(elt(env, 18)); /* key!* */
    goto v0123;

v0123:
    stack[0] = v0105;
    v0108 = v0106;
    v0107 = qvalue(elt(env, 9)); /* nil */
    v0106 = elt(env, 17); /* symbolic */
    fn = elt(env, 39); /* convertmode1 */
    v0105 = (*qfnn(fn))(qenv(fn), 4, v0108, v0107, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0105 = list2(stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0064;

v0122:
    v0105 = v0106;
    if (!consp(v0105)) goto v0124;
    v0105 = v0106;
    v0107 = qcar(v0105);
    v0105 = elt(env, 19); /* quote */
    if (v0107 == v0105) goto v0125;
    v0105 = v0106;
    v0105 = qcar(v0105);
    if (!(symbolp(v0105))) goto v0126;
    v0105 = v0106;
    v0107 = qcar(v0105);
    v0105 = elt(env, 20); /* nochange */
    v0105 = Lflagp(nil, v0107, v0105);
    env = stack[-3];
    if (v0105 == nil) goto v0127;
    v0105 = qvalue(elt(env, 6)); /* t */
    goto v0004;

v0004:
    if (v0105 == nil) goto v0126;
    v0105 = v0106;
    v0107 = qcar(v0105);
    v0105 = elt(env, 23); /* (setq setel setf) */
    v0105 = Lmemq(nil, v0107, v0105);
    if (v0105 == nil) goto v0128;
    v0105 = v0106;
    v0105 = qcdr(v0105);
    v0105 = qcdr(v0105);
    v0107 = qcar(v0105);
    v0105 = elt(env, 19); /* quote */
    v0105 = Leqcar(nil, v0107, v0105);
    env = stack[-3];
    goto v0129;

v0129:
    if (v0105 == nil) goto v0130;
    v0105 = elt(env, 17); /* symbolic */
    goto v0123;

v0130:
    v0105 = qvalue(elt(env, 24)); /* !*mode */
    goto v0123;

v0128:
    v0105 = qvalue(elt(env, 9)); /* nil */
    goto v0129;

v0126:
    v0105 = qvalue(elt(env, 6)); /* t */
    goto v0129;

v0127:
    v0105 = v0106;
    v0107 = qcar(v0105);
    v0105 = elt(env, 21); /* intfn */
    v0105 = Lflagp(nil, v0107, v0105);
    env = stack[-3];
    if (v0105 == nil) goto v0131;
    v0105 = qvalue(elt(env, 6)); /* t */
    goto v0004;

v0131:
    v0105 = v0106;
    v0107 = qcar(v0105);
    v0105 = elt(env, 22); /* list */
    v0105 = (v0107 == v0105 ? lisp_true : nil);
    goto v0004;

v0125:
    v0105 = qvalue(elt(env, 9)); /* nil */
    goto v0129;

v0124:
    v0105 = qvalue(elt(env, 9)); /* nil */
    goto v0129;

v0014:
    v0105 = stack[0];
    fn = elt(env, 38); /* rprint */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0105 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0118;

v0119:
    v0106 = qvalue(elt(env, 15)); /* cursym!* */
    v0105 = elt(env, 16); /* end */
    v0105 = (v0106 == v0105 ? lisp_true : nil);
    goto v0120;

v0020:
    v0105 = qvalue(elt(env, 6)); /* t */
    goto v0021;

v0050:
    v0105 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    goto v0111;

v0054:
    v0105 = qvalue(elt(env, 6)); /* t */
    goto v0053;
/* error exit handlers */
v0109:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-2]; /* errmsg!* */
    popv(4);
    return nil;
}



/* Code for general!-reduce!-degree!-mod!-p */

static Lisp_Object CC_generalKreduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0142, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
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
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = qcdr(v0141);
    fn = elt(env, 1); /* general!-modular!-minus */
    v0142 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    v0141 = stack[0];
    v0141 = qcar(v0141);
    v0141 = qcdr(v0141);
    fn = elt(env, 2); /* general!-modular!-quotient */
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    stack[-2] = v0141;
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0142 = qcdr(v0141);
    v0141 = stack[0];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0141 = qcdr(v0141);
    v0141 = (Lisp_Object)(int32_t)((int32_t)v0142 - (int32_t)v0141 + TAG_FIXNUM);
    v0095 = v0141;
    v0142 = v0095;
    v0141 = (Lisp_Object)1; /* 0 */
    if (v0142 == v0141) goto v0144;
    v0141 = stack[-1];
    stack[-1] = qcdr(v0141);
    v0141 = stack[0];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0142 = v0095;
    fn = elt(env, 3); /* mksp */
    v0142 = (*qfn2(fn))(qenv(fn), v0141, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    v0141 = stack[-2];
    v0142 = cons(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    v0141 = stack[0];
    v0141 = qcdr(v0141);
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    {
        Lisp_Object v0119 = stack[-1];
        popv(4);
        fn = elt(env, 5); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0119, v0141);
    }

v0144:
    v0141 = stack[-1];
    stack[-1] = qcdr(v0141);
    v0141 = stack[0];
    v0142 = qcdr(v0141);
    v0141 = stack[-2];
    fn = elt(env, 6); /* general!-multiply!-by!-constant!-mod!-p */
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    {
        Lisp_Object v0145 = stack[-1];
        popv(4);
        fn = elt(env, 5); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0145, v0141);
    }
/* error exit handlers */
v0143:
    popv(4);
    return nil;
}



/* Code for polynomheadreduceby */

static Lisp_Object CC_polynomheadreduceby(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomheadreduceby");
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
    stack[-3] = nil;
    goto v0112;

v0112:
    v0043 = stack[-2];
    v0043 = qcar(v0043);
    if (v0043 == nil) goto v0110;
    v0043 = stack[-3];
    if (!(v0043 == nil)) goto v0110;
    v0043 = stack[-2];
    v0149 = qcar(v0043);
    v0043 = stack[-1];
    v0043 = qcar(v0043);
    fn = elt(env, 4); /* monomisdivisibleby */
    v0043 = (*qfn2(fn))(qenv(fn), v0149, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-4];
    if (v0043 == nil) goto v0138;
    v0043 = stack[-2];
    v0149 = qcar(v0043);
    v0043 = stack[-1];
    v0043 = qcar(v0043);
    fn = elt(env, 5); /* monomdivide */
    v0043 = (*qfn2(fn))(qenv(fn), v0149, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-4];
    stack[0] = stack[-2];
    v0149 = stack[-1];
    fn = elt(env, 6); /* polynommultiplybymonom */
    v0043 = (*qfn2(fn))(qenv(fn), v0149, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-4];
    fn = elt(env, 7); /* polynomadd */
    v0043 = (*qfn2(fn))(qenv(fn), stack[0], v0043);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-4];
    goto v0112;

v0138:
    v0043 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0043;
    goto v0112;

v0110:
    v0043 = qvalue(elt(env, 3)); /* fluidbibasisreductionsmade */
    v0043 = (Lisp_Object)((int32_t)(v0043) + 0x10);
    qvalue(elt(env, 3)) = v0043; /* fluidbibasisreductionsmade */
    v0043 = nil;
    { popv(5); return onevalue(v0043); }
/* error exit handlers */
v0150:
    popv(5);
    return nil;
}



/* Code for ofsf_subf */

static Lisp_Object MS_CDECL CC_ofsf_subf(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0162, v0163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_subf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_subf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0065,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0065);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0065;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0017 = stack[-2];
    if (!consp(v0017)) goto v0035;
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    v0017 = (consp(v0017) ? nil : lisp_true);
    goto v0164;

v0164:
    if (v0017 == nil) goto v0056;
    v0162 = stack[-2];
    v0017 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0162, v0017);

v0056:
    v0017 = stack[-2];
    v0163 = qcdr(v0017);
    v0162 = stack[-1];
    v0017 = stack[0];
    v0017 = CC_ofsf_subf(env, 3, v0163, v0162, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[-3] = v0017;
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    v0017 = qcar(v0017);
    v0162 = qcar(v0017);
    v0017 = stack[-1];
    if (v0162 == v0017) goto v0166;
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    v0163 = qcdr(v0017);
    v0162 = stack[-1];
    v0017 = stack[0];
    stack[0] = CC_ofsf_subf(env, 3, v0163, v0162, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    v0017 = qcar(v0017);
    v0162 = qcar(v0017);
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    v0017 = qcar(v0017);
    v0017 = qcdr(v0017);
    fn = elt(env, 2); /* ofsf_pow2q */
    v0017 = (*qfn2(fn))(qenv(fn), v0162, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    v0017 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0162, v0017);
    }

v0166:
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    v0162 = qcdr(v0017);
    v0017 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v0162, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    v0162 = stack[0];
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    v0017 = qcar(v0017);
    v0017 = qcdr(v0017);
    fn = elt(env, 5); /* exptsq */
    v0017 = (*qfn2(fn))(qenv(fn), v0162, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0162 = (*qfn2(fn))(qenv(fn), stack[-1], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    v0017 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0162, v0017);
    }

v0035:
    v0017 = qvalue(elt(env, 1)); /* t */
    goto v0164;
/* error exit handlers */
v0165:
    popv(5);
    return nil;
}



/* Code for cl_qb */

static Lisp_Object CC_cl_qb(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0166, v0167, v0132, v0118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_qb");
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
    v0118 = nil;
    v0149 = (Lisp_Object)1; /* 0 */
    v0132 = v0149;
    goto v0168;

v0168:
    v0149 = stack[0];
    if (!consp(v0149)) goto v0169;
    v0149 = stack[0];
    v0149 = qcar(v0149);
    goto v0058;

v0058:
    stack[-1] = v0149;
    v0167 = v0149;
    v0166 = v0167;
    v0149 = elt(env, 1); /* ex */
    if (v0166 == v0149) goto v0002;
    v0166 = v0167;
    v0149 = elt(env, 3); /* all */
    v0149 = (v0166 == v0149 ? lisp_true : nil);
    goto v0033;

v0033:
    if (v0149 == nil) { popv(3); return onevalue(v0132); }
    v0166 = stack[-1];
    v0149 = v0118;
    if (equal(v0166, v0149)) goto v0146;
    v0149 = v0132;
    v0149 = add1(v0149);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0132 = v0149;
    v0149 = stack[-1];
    v0118 = v0149;
    goto v0146;

v0146:
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0149 = qcdr(v0149);
    v0149 = qcar(v0149);
    stack[0] = v0149;
    goto v0168;

v0002:
    v0149 = qvalue(elt(env, 2)); /* t */
    goto v0033;

v0169:
    v0149 = stack[0];
    goto v0058;
/* error exit handlers */
v0025:
    popv(3);
    return nil;
}



/* Code for poly!-minusp */

static Lisp_Object CC_polyKminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0056 = v0000;
/* end of prologue */

v0041:
    v0101 = v0056;
    if (v0101 == nil) goto v0064;
    v0101 = v0056;
    if (!consp(v0101)) goto v0036;
    v0101 = v0056;
    v0101 = qcar(v0101);
    v0101 = (consp(v0101) ? nil : lisp_true);
    goto v0055;

v0055:
    if (v0101 == nil) goto v0032;
        return Lminusp(nil, v0056);

v0032:
    v0056 = qcar(v0056);
    v0056 = qcdr(v0056);
    goto v0041;

v0036:
    v0101 = qvalue(elt(env, 2)); /* t */
    goto v0055;

v0064:
    v0056 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0056);
}



/* Code for omsir */

static Lisp_Object MS_CDECL CC_omsir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0177, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omsir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omsir");
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
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* end of prologue */
    stack[-1] = nil;
    v0177 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0177;
    v0037 = qvalue(elt(env, 2)); /* atts */
    v0177 = elt(env, 3); /* name */
    fn = elt(env, 12); /* find */
    v0177 = (*qfn2(fn))(qenv(fn), v0037, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = Lintern(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    stack[-5] = v0177;
    v0037 = qvalue(elt(env, 2)); /* atts */
    v0177 = elt(env, 4); /* cd */
    fn = elt(env, 12); /* find */
    v0177 = (*qfn2(fn))(qenv(fn), v0037, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = Lintern(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    stack[-3] = v0177;
    v0177 = stack[-5];
    v0037 = Lexplode(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = elt(env, 5); /* (v e c t o r) */
    if (equal(v0037, v0177)) goto v0111;
    v0177 = stack[-5];
    v0037 = Lintern(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = qvalue(elt(env, 7)); /* mmleq!* */
    v0177 = Lmember(nil, v0037, v0177);
    stack[-4] = v0177;
    goto v0101;

v0101:
    v0177 = stack[-4];
    if (!(v0177 == nil)) goto v0179;
    v0037 = stack[-5];
    v0177 = qvalue(elt(env, 8)); /* special_cases!* */
    v0177 = Lassoc(nil, v0037, v0177);
    stack[-4] = v0177;
    if (v0177 == nil) goto v0095;
    v0177 = stack[-4];
    v0177 = Lreverse(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = qcar(v0177);
    stack[-2] = v0177;
    v0177 = stack[-2];
    if (v0177 == nil) goto v0047;
    v0177 = stack[-2];
    v0177 = ncons(v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    stack[-2] = v0177;
    goto v0047;

v0047:
    v0177 = stack[-4];
    v0177 = Lreverse(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = qcdr(v0177);
    stack[0] = qcar(v0177);
    v0177 = stack[-4];
    v0177 = qcdr(v0177);
    v0177 = Lreverse(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = qcdr(v0177);
    v0177 = qcdr(v0177);
    v0177 = Lreverse(nil, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0177 = cons(stack[0], v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    stack[-4] = v0177;
    goto v0179;

v0179:
    v0177 = stack[-4];
    if (v0177 == nil) goto v0018;
    v0177 = stack[-4];
    v0037 = qcar(v0177);
    v0177 = qvalue(elt(env, 10)); /* valid_om!* */
    v0177 = Lassoc(nil, v0037, v0177);
    stack[-1] = v0177;
    goto v0018;

v0018:
    v0177 = stack[-1];
    if (v0177 == nil) goto v0180;
    v0177 = stack[-1];
    v0177 = qcdr(v0177);
    v0177 = qcar(v0177);
    stack[-1] = v0177;
    goto v0180;

v0180:
    v0177 = stack[-4];
    if (v0177 == nil) goto v0181;
    v0037 = stack[-3];
    v0177 = stack[-1];
    v0177 = (v0177 == nil ? lisp_true : nil);
    v0177 = (equal(v0037, v0177) ? lisp_true : nil);
    goto v0129;

v0129:
    if (v0177 == nil) goto v0182;
    v0177 = stack[-5];
    {
        popv(7);
        fn = elt(env, 13); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v0177);
    }

v0182:
    v0177 = stack[-4];
    v0037 = qcar(v0177);
    v0177 = stack[-2];
    popv(7);
    return list2(v0037, v0177);

v0181:
    v0177 = qvalue(elt(env, 11)); /* t */
    goto v0129;

v0095:
    v0037 = stack[-5];
    v0177 = qvalue(elt(env, 9)); /* special_cases2!* */
    v0037 = Lassoc(nil, v0037, v0177);
    v0177 = v0037;
    if (v0037 == nil) goto v0179;
    v0037 = v0177;
    v0037 = qcdr(v0037);
    v0037 = qcar(v0037);
    v0177 = qcdr(v0177);
    v0177 = qcdr(v0177);
    {
        popv(7);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v0037, v0177);
    }

v0111:
    v0177 = elt(env, 6); /* (vectorml linalg1) */
    stack[-4] = v0177;
    goto v0101;
/* error exit handlers */
v0178:
    popv(7);
    return nil;
}



/* Code for take!-impart */

static Lisp_Object CC_takeKimpart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for take-impart");
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
    stack[0] = v0000;
/* end of prologue */
    v0035 = stack[0];
    v0035 = qcar(v0035);
    fn = elt(env, 1); /* impartf */
    v0055 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    popv(1);
    return cons(v0055, v0035);
/* error exit handlers */
v0058:
    popv(1);
    return nil;
}



/* Code for inshisto */

static Lisp_Object CC_inshisto(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0044, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inshisto");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0044 = qvalue(elt(env, 2)); /* maxvar */
    v0078 = stack[-3];
    v0078 = plus2(v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    v0044 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    v0078 = (Lisp_Object)1; /* 0 */
    v0078 = *(Lisp_Object *)((char *)v0044 + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    if (v0078 == nil) goto v0067;
    v0044 = stack[-3];
    v0078 = (Lisp_Object)1; /* 0 */
    v0078 = (Lisp_Object)geq2(v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-5];
    if (v0078 == nil) goto v0067;
    stack[0] = qvalue(elt(env, 3)); /* codhisto */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0044 = qvalue(elt(env, 2)); /* maxvar */
    v0078 = stack[-3];
    v0078 = plus2(v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    v0044 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    v0078 = (Lisp_Object)17; /* 1 */
    v0078 = *(Lisp_Object *)((char *)v0044 + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    v0044 = qcdr(v0078);
    v0078 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 6); /* min */
    v0078 = (*qfn2(fn))(qenv(fn), v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    stack[-2] = v0078;
    v0078 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    stack[-4] = v0078;
    if (v0078 == nil) goto v0152;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0044 = qvalue(elt(env, 2)); /* maxvar */
    v0078 = stack[-4];
    v0078 = plus2(v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    v0044 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    v0078 = (Lisp_Object)113; /* 7 */
    v0044 = *(Lisp_Object *)((char *)v0044 + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    v0078 = stack[-3];
    v0078 = Lrplaca(nil, v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    goto v0017;

v0017:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0044 = qvalue(elt(env, 2)); /* maxvar */
    v0078 = stack[-3];
    v0078 = plus2(v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    stack[0] = (Lisp_Object)113; /* 7 */
    v0044 = qvalue(elt(env, 5)); /* nil */
    v0078 = stack[-4];
    v0078 = cons(v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0078;
    v0126 = qvalue(elt(env, 3)); /* codhisto */
    v0044 = stack[-2];
    v0078 = stack[-3];
    *(Lisp_Object *)((char *)v0126 + (CELL-TAG_VECTOR) + ((int32_t)v0044/(16/CELL))) = v0078;
    v0078 = nil;
    { popv(6); return onevalue(v0078); }

v0152:
    v0044 = stack[-2];
    v0078 = qvalue(elt(env, 4)); /* headhisto */
    v0078 = (Lisp_Object)greaterp2(v0044, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-5];
    if (v0078 == nil) goto v0017;
    v0078 = stack[-2];
    qvalue(elt(env, 4)) = v0078; /* headhisto */
    goto v0017;

v0067:
    v0078 = nil;
    { popv(6); return onevalue(v0078); }
/* error exit handlers */
v0006:
    popv(6);
    return nil;
}



/* Code for dipprodin1 */

static Lisp_Object MS_CDECL CC_dipprodin1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipprodin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprodin1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0065,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0065);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0065;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0064;

v0064:
    v0052 = stack[0];
    if (v0052 == nil) goto v0055;
    v0138 = stack[-1];
    v0052 = stack[0];
    v0052 = qcar(v0052);
    fn = elt(env, 2); /* evsum */
    v0138 = (*qfn2(fn))(qenv(fn), v0138, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0052 = stack[-3];
    v0052 = cons(v0138, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    stack[-3] = v0052;
    v0138 = stack[-2];
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    fn = elt(env, 3); /* bcprod */
    v0138 = (*qfn2(fn))(qenv(fn), v0138, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0052 = stack[-3];
    v0052 = cons(v0138, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    stack[-3] = v0052;
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    goto v0064;

v0055:
    v0138 = stack[-3];
    v0052 = qvalue(elt(env, 1)); /* dipzero */
    {
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0138, v0052);
    }
/* error exit handlers */
v0030:
    popv(5);
    return nil;
}



/* Code for physop2sq */

static Lisp_Object CC_physop2sq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physop2sq");
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

v0193:
    v0092 = stack[0];
    fn = elt(env, 3); /* physopp */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    if (v0092 == nil) goto v0110;
    v0092 = stack[0];
    if (!symbolp(v0092)) v0092 = nil;
    else { v0092 = qfastgets(v0092);
           if (v0092 != nil) { v0092 = elt(v0092, 46); /* rvalue */
#ifdef RECORD_GET
             if (v0092 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v0092 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v0092 == SPID_NOPROP) v0092 = nil; }}
#endif
    stack[-1] = v0092;
    if (v0092 == nil) goto v0055;
    v0092 = stack[-1];
    stack[0] = v0092;
    goto v0193;

v0055:
    v0092 = stack[0];
    if (symbolp(v0092)) goto v0059;
    v0092 = stack[0];
    v0078 = qcar(v0092);
    v0092 = elt(env, 1); /* psimpfn */
    v0092 = get(v0078, v0092);
    env = stack[-2];
    stack[-1] = v0092;
    if (v0092 == nil) goto v0144;
    v0078 = stack[-1];
    v0092 = stack[0];
    v0092 = Lapply1(nil, v0078, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    stack[-1] = v0092;
    fn = elt(env, 3); /* physopp */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    if (v0092 == nil) goto v0098;
    v0078 = stack[-1];
    v0092 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    v0078 = (*qfn2(fn))(qenv(fn), v0078, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    v0092 = (Lisp_Object)17; /* 1 */
    v0092 = cons(v0078, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    v0078 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0092 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0078, v0092);

v0098:
    v0092 = stack[-1];
    fn = elt(env, 5); /* physopsm!* */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    { popv(3); return onevalue(v0092); }

v0144:
    v0092 = stack[0];
    v0092 = qcar(v0092);
    if (!symbolp(v0092)) v0092 = nil;
    else { v0092 = qfastgets(v0092);
           if (v0092 != nil) { v0092 = elt(v0092, 9); /* opmtch */
#ifdef RECORD_GET
             if (v0092 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0092 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0092 == SPID_NOPROP) v0092 = nil; }}
#endif
    if (v0092 == nil) goto v0195;
    v0092 = stack[0];
    fn = elt(env, 6); /* opmtch!* */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    stack[-1] = v0092;
    if (v0092 == nil) goto v0195;
    v0092 = stack[-1];
    stack[0] = v0092;
    goto v0193;

v0195:
    v0078 = stack[0];
    v0092 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    v0078 = (*qfn2(fn))(qenv(fn), v0078, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    v0092 = (Lisp_Object)17; /* 1 */
    v0092 = cons(v0078, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    v0078 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0092 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0078, v0092);

v0059:
    v0078 = stack[0];
    v0092 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    v0078 = (*qfn2(fn))(qenv(fn), v0078, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    v0092 = (Lisp_Object)17; /* 1 */
    v0092 = cons(v0078, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    v0078 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0092 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0078, v0092);

v0110:
    v0092 = stack[0];
    if (!consp(v0092)) goto v0093;
    v0092 = stack[0];
    v0078 = qcar(v0092);
    v0092 = elt(env, 2); /* !*sq */
    if (v0078 == v0092) goto v0196;
    v0092 = stack[0];
    fn = elt(env, 7); /* getphystype */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    if (v0092 == nil) goto v0077;
    v0092 = stack[0];
    fn = elt(env, 5); /* physopsm!* */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-2];
    stack[0] = v0092;
    goto v0193;

v0077:
    v0092 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v0092);
    }

v0196:
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    { popv(3); return onevalue(v0092); }

v0093:
    v0092 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v0092);
    }
/* error exit handlers */
v0194:
    popv(3);
    return nil;
}



/* Code for assert_format */

static Lisp_Object MS_CDECL CC_assert_format(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0184, v0204, v0205;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assert_format");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_format");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0065,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0065);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0184 = v0065;
    stack[-8] = v0001;
    stack[-9] = v0000;
/* end of prologue */
    v0184 = Lexplode(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    stack[-10] = v0184;
    stack[-7] = elt(env, 1); /* !! */
    stack[-6] = elt(env, 2); /* !) */
    stack[-5] = elt(env, 1); /* !! */
    stack[-4] = elt(env, 3); /* !  */
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 4); /* !- */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 5); /* !> */
    v0205 = elt(env, 1); /* !! */
    v0204 = elt(env, 3); /* !  */
    v0184 = stack[-10];
    v0184 = list2star(v0205, v0204, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-1], stack[0], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-3], stack[-2], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-5], stack[-4], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-7], stack[-6], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    stack[-10] = v0184;
    v0184 = stack[-8];
    v0184 = Lreverse(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    stack[-4] = v0184;
    goto v0206;

v0206:
    v0184 = stack[-4];
    if (v0184 == nil) goto v0117;
    v0184 = stack[-4];
    v0184 = qcar(v0184);
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 7); /* !, */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 3); /* !  */
    v0204 = Lexplode(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = stack[-10];
    v0184 = Lnconc(nil, v0204, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-1], stack[0], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-3], stack[-2], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    stack[-10] = v0184;
    v0184 = stack[-4];
    v0184 = qcdr(v0184);
    stack[-4] = v0184;
    goto v0206;

v0117:
    v0184 = stack[-10];
    v0184 = qcdr(v0184);
    v0184 = qcdr(v0184);
    v0184 = qcdr(v0184);
    v0184 = qcdr(v0184);
    stack[-10] = v0184;
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 8); /* !: */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 3); /* !  */
    v0205 = elt(env, 1); /* !! */
    v0204 = elt(env, 9); /* !( */
    v0184 = stack[-10];
    v0184 = list2star(v0205, v0204, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-1], stack[0], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = list2star(stack[-3], stack[-2], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    stack[-10] = v0184;
    v0184 = stack[-9];
    v0204 = Lexplode(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-11];
    v0184 = stack[-10];
    v0184 = Lnconc(nil, v0204, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    stack[-10] = v0184;
    v0184 = stack[-10];
        popv(12);
        return Lcompress(nil, v0184);
/* error exit handlers */
v0194:
    popv(12);
    return nil;
}



/* Code for mo_times_ei */

static Lisp_Object CC_mo_times_ei(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0102, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_times_ei");
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
    v0103 = v0001;
    v0102 = v0000;
/* end of prologue */
    v0027 = v0103;
    v0027 = qcar(v0027);
    if (v0027 == nil) goto v0067;
    v0027 = v0103;
    v0027 = qcar(v0027);
    v0027 = qcar(v0027);
    v0027 = (Lisp_Object)(int32_t)((int32_t)v0102 + (int32_t)v0027 - TAG_FIXNUM);
    v0102 = v0103;
    v0102 = qcar(v0102);
    v0102 = qcdr(v0102);
    v0027 = cons(v0027, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-1];
    goto v0057;

v0057:
    stack[0] = v0027;
    fn = elt(env, 1); /* mo!=deglist */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    {
        Lisp_Object v0203 = stack[0];
        popv(2);
        return cons(v0203, v0027);
    }

v0067:
    v0027 = v0102;
    v0027 = ncons(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-1];
    goto v0057;
/* error exit handlers */
v0144:
    popv(2);
    return nil;
}



/* Code for b_expand2 */

static Lisp_Object MS_CDECL CC_b_expand2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0175, v0176, v0104, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "b_expand2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b_expand2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0175 = v0065;
    v0176 = v0001;
    v0104 = v0000;
/* end of prologue */
    v0053 = v0104;
    v0053 = qcar(v0053);
    v0104 = qcdr(v0104);
    {
        fn = elt(env, 1); /* b_expand2b */
        return (*qfnn(fn))(qenv(fn), 4, v0053, v0104, v0176, v0175);
    }
}



/* Code for simpatom */

static Lisp_Object CC_simpatom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0223, v0224, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpatom");
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
    v0223 = stack[-1];
    if (v0223 == nil) goto v0110;
    v0223 = stack[-1];
    if (is_number(v0223)) goto v0104;
    v0223 = stack[-1];
    v0223 = Lstringp(nil, v0223);
    env = stack[-3];
    if (v0223 == nil) goto v0226;
    v0224 = elt(env, 6); /* "String" */
    v0223 = stack[-1];
    v0224 = list2(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    v0223 = elt(env, 7); /* "identifier" */
    {
        popv(4);
        fn = elt(env, 12); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0224, v0223);
    }

v0226:
    v0223 = stack[-1];
    if (!symbolp(v0223)) v0223 = nil;
    else { v0223 = qfastgets(v0223);
           if (v0223 != nil) { v0223 = elt(v0223, 17); /* share */
#ifdef RECORD_GET
             if (v0223 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0223 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0223 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0223 == SPID_NOPROP) v0223 = nil; else v0223 = lisp_true; }}
#endif
    if (v0223 == nil) goto v0005;
    v0223 = stack[-1];
    fn = elt(env, 13); /* lispeval */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    v0225 = v0223;
    v0224 = v0225;
    v0223 = stack[-1];
    if (v0224 == v0223) goto v0092;
    v0223 = v0225;
    {
        popv(4);
        fn = elt(env, 14); /* simp */
        return (*qfn1(fn))(qenv(fn), v0223);
    }

v0092:
    v0224 = stack[-1];
    v0223 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0224, v0223);
    }

v0005:
    v0223 = stack[-1];
    if (!symbolp(v0223)) v0223 = nil;
    else { v0223 = qfastgets(v0223);
           if (v0223 != nil) { v0223 = elt(v0223, 56); /* idvalfn */
#ifdef RECORD_GET
             if (v0223 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v0223 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v0223 == SPID_NOPROP) v0223 = nil; }}
#endif
    stack[-2] = v0223;
    if (v0223 == nil) goto v0228;
    v0224 = stack[-2];
    v0223 = stack[-1];
        popv(4);
        return Lapply1(nil, v0224, v0223);

v0228:
    v0223 = qvalue(elt(env, 8)); /* !*numval */
    if (v0223 == nil) goto v0229;
    v0223 = qvalue(elt(env, 3)); /* dmode!* */
    if (v0223 == nil) goto v0229;
    v0224 = stack[-1];
    v0223 = elt(env, 9); /* constant */
    v0223 = Lflagp(nil, v0224, v0223);
    env = stack[-3];
    if (v0223 == nil) goto v0230;
    v0224 = stack[-1];
    v0223 = qvalue(elt(env, 3)); /* dmode!* */
    v0223 = get(v0224, v0223);
    env = stack[-3];
    stack[-2] = v0223;
    if (v0223 == nil) goto v0231;
    stack[0] = elt(env, 10); /* lispapply */
    v0223 = stack[-2];
    v0224 = Lmkquote(nil, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    v0223 = qvalue(elt(env, 1)); /* nil */
    v0224 = list3(stack[0], v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    v0223 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 16); /* errorset!* */
    v0223 = (*qfn2(fn))(qenv(fn), v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    stack[-2] = v0223;
    fn = elt(env, 17); /* errorp */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    v0223 = (v0223 == nil ? lisp_true : nil);
    goto v0232;

v0232:
    if (v0223 == nil) goto v0229;
    v0223 = stack[-2];
    v0223 = qcar(v0223);
    {
        popv(4);
        fn = elt(env, 18); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0223);
    }

v0229:
    v0223 = stack[-1];
    fn = elt(env, 19); /* getrtype */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    if (v0223 == nil) goto v0074;
    v0224 = stack[-1];
    v0223 = elt(env, 11); /* scalar */
    fn = elt(env, 12); /* typerr */
    v0223 = (*qfn2(fn))(qenv(fn), v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    v0223 = nil;
    { popv(4); return onevalue(v0223); }

v0074:
    v0224 = stack[-1];
    v0223 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0224, v0223);
    }

v0231:
    v0223 = qvalue(elt(env, 1)); /* nil */
    goto v0232;

v0230:
    v0223 = qvalue(elt(env, 1)); /* nil */
    goto v0232;

v0104:
    v0224 = stack[-1];
    v0223 = (Lisp_Object)1; /* 0 */
    if (v0224 == v0223) goto v0042;
    v0223 = stack[-1];
    v0223 = integerp(v0223);
    if (v0223 == nil) goto v0027;
    v0224 = qvalue(elt(env, 3)); /* dmode!* */
    v0223 = elt(env, 4); /* !:mod!: */
    if (v0224 == v0223) goto v0043;
    v0223 = qvalue(elt(env, 1)); /* nil */
    goto v0148;

v0148:
    if (v0223 == nil) goto v0159;
    v0224 = qvalue(elt(env, 1)); /* nil */
    v0223 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0224, v0223);

v0159:
    v0223 = qvalue(elt(env, 3)); /* dmode!* */
    if (!symbolp(v0223)) v0223 = nil;
    else { v0223 = qfastgets(v0223);
           if (v0223 != nil) { v0223 = elt(v0223, 5); /* convert */
#ifdef RECORD_GET
             if (v0223 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0223 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0223 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0223 == SPID_NOPROP) v0223 = nil; else v0223 = lisp_true; }}
#endif
    if (v0223 == nil) goto v0022;
    v0224 = stack[-1];
    v0223 = (Lisp_Object)17; /* 1 */
    v0223 = Lneq(nil, v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    goto v0157;

v0157:
    if (v0223 == nil) goto v0014;
    v0223 = qvalue(elt(env, 3)); /* dmode!* */
    if (!symbolp(v0223)) v0224 = nil;
    else { v0224 = qfastgets(v0223);
           if (v0224 != nil) { v0224 = elt(v0224, 34); /* i2d */
#ifdef RECORD_GET
             if (v0224 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0224 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0224 == SPID_NOPROP) v0224 = nil; }}
#endif
    v0223 = stack[-1];
    v0223 = Lapply1(nil, v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 18); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0223);
    }

v0014:
    v0224 = stack[-1];
    v0223 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0224, v0223);

v0022:
    v0223 = qvalue(elt(env, 1)); /* nil */
    goto v0157;

v0043:
    v0224 = qvalue(elt(env, 5)); /* current!-modulus */
    v0223 = (Lisp_Object)17; /* 1 */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0148;

v0027:
    stack[0] = elt(env, 2); /* !:rd!: */
    v0223 = stack[-1];
    fn = elt(env, 20); /* fl2bf */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    v0224 = qcdr(v0223);
    v0223 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v0233 = stack[0];
        popv(4);
        return acons(v0233, v0224, v0223);
    }

v0042:
    v0224 = qvalue(elt(env, 1)); /* nil */
    v0223 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0224, v0223);

v0110:
    v0224 = qvalue(elt(env, 1)); /* nil */
    v0223 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0224, v0223);
/* error exit handlers */
v0227:
    popv(4);
    return nil;
}



/* Code for readprogn */

static Lisp_Object MS_CDECL CC_readprogn(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "readprogn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for readprogn");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    stack[0] = nil;
    goto v0110;

v0110:
    v0057 = elt(env, 1); /* group */
    fn = elt(env, 5); /* xread */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-1];
    fn = elt(env, 6); /* aconc!* */
    v0057 = (*qfn2(fn))(qenv(fn), stack[0], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-1];
    stack[0] = v0057;
    v0031 = qvalue(elt(env, 2)); /* cursym!* */
    v0057 = elt(env, 3); /* !*rsqbkt!* */
    if (!(v0031 == v0057)) goto v0110;
    fn = elt(env, 7); /* scan */
    v0057 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-1];
    v0031 = elt(env, 4); /* progn */
    v0057 = stack[0];
    popv(2);
    return cons(v0031, v0057);
/* error exit handlers */
v0189:
    popv(2);
    return nil;
}



/* Code for sfto_varp */

static Lisp_Object CC_sfto_varp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0028;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_varp");
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
    v0030 = stack[0];
    if (!consp(v0030)) goto v0164;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0030 = (consp(v0030) ? nil : lisp_true);
    goto v0161;

v0161:
    if (v0030 == nil) goto v0110;
    v0030 = qvalue(elt(env, 2)); /* nil */
    goto v0064;

v0064:
    if (v0030 == nil) goto v0067;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    { popv(2); return onevalue(v0030); }

v0067:
    v0030 = nil;
    { popv(2); return onevalue(v0030); }

v0110:
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    if (v0030 == nil) goto v0101;
    v0030 = qvalue(elt(env, 2)); /* nil */
    goto v0064;

v0101:
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0028 = qcdr(v0030);
    v0030 = (Lisp_Object)17; /* 1 */
    v0030 = Leqn(nil, v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-1];
    if (v0030 == nil) goto v0045;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    v0028 = qcdr(v0030);
    v0030 = (Lisp_Object)17; /* 1 */
    v0030 = Leqn(nil, v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    goto v0064;

v0045:
    v0030 = qvalue(elt(env, 2)); /* nil */
    goto v0064;

v0164:
    v0030 = qvalue(elt(env, 1)); /* t */
    goto v0161;
/* error exit handlers */
v0149:
    popv(2);
    return nil;
}



/* Code for polynommultiplybyvariable */

static Lisp_Object CC_polynommultiplybyvariable(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynommultiplybyvariable");
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
    stack[-3] = nil;
    v0155 = stack[-2];
    stack[0] = v0155;
    goto v0168;

v0168:
    v0155 = stack[0];
    v0155 = qcar(v0155);
    if (v0155 == nil) goto v0200;
    v0155 = stack[0];
    v0152 = qcar(v0155);
    v0155 = stack[-1];
    fn = elt(env, 2); /* monomgetvariabledegree */
    v0152 = (*qfn2(fn))(qenv(fn), v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    v0155 = (Lisp_Object)1; /* 0 */
    v0155 = Leqn(nil, v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    if (v0155 == nil) goto v0043;
    v0155 = stack[0];
    v0152 = qcar(v0155);
    v0155 = stack[-3];
    v0155 = cons(v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    stack[-3] = v0155;
    v0152 = stack[0];
    v0155 = stack[0];
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    v0152 = Lrplaca(nil, v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    v0155 = stack[0];
    v0155 = qcdr(v0155);
    v0155 = qcdr(v0155);
    v0155 = Lrplacd(nil, v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    goto v0168;

v0043:
    v0155 = stack[0];
    v0155 = qcdr(v0155);
    stack[0] = v0155;
    goto v0168;

v0200:
    v0152 = qvalue(elt(env, 1)); /* nil */
    v0155 = stack[-3];
    v0155 = cons(v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    stack[-3] = v0155;
    v0155 = stack[-3];
    v0155 = Lreverse(nil, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    stack[-3] = v0155;
    v0155 = stack[-3];
    stack[0] = v0155;
    goto v0234;

v0234:
    v0155 = stack[0];
    v0155 = qcar(v0155);
    if (v0155 == nil) goto v0188;
    v0155 = stack[0];
    v0152 = qcar(v0155);
    v0155 = stack[-1];
    fn = elt(env, 3); /* monommultiplybyvariable */
    v0155 = (*qfn2(fn))(qenv(fn), v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    v0155 = stack[0];
    v0155 = qcdr(v0155);
    stack[0] = v0155;
    goto v0234;

v0188:
    v0152 = stack[-2];
    v0155 = stack[-3];
    fn = elt(env, 4); /* polynomadd */
    v0155 = (*qfn2(fn))(qenv(fn), v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    v0155 = nil;
    { popv(5); return onevalue(v0155); }
/* error exit handlers */
v0185:
    popv(5);
    return nil;
}



/* Code for ofsf_pow2q */

static Lisp_Object CC_ofsf_pow2q(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0045, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_pow2q");
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
    v0045 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* to */
    v0045 = (*qfn2(fn))(qenv(fn), v0045, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[0];
    v0002 = (Lisp_Object)17; /* 1 */
    v0045 = cons(v0045, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[0];
    v0042 = qvalue(elt(env, 1)); /* nil */
    v0002 = (Lisp_Object)17; /* 1 */
    popv(1);
    return acons(v0045, v0042, v0002);
/* error exit handlers */
v0056:
    popv(1);
    return nil;
}



/* Code for simpqg */

static Lisp_Object CC_simpqg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpqg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0168 = v0000;
/* end of prologue */
    v0161 = v0168;
    v0168 = elt(env, 1); /* qg */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v0161, v0168);
    }
}



/* Code for ibalp_negatet */

static Lisp_Object CC_ibalp_negatet(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0031, v0059;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0059 = v0000;
/* end of prologue */
    v0031 = v0059;
    v0057 = (Lisp_Object)1; /* 0 */
    if (v0031 == v0057) goto v0041;
    v0031 = v0059;
    v0057 = (Lisp_Object)17; /* 1 */
    if (v0031 == v0057) goto v0055;
    v0057 = elt(env, 1); /* bnot */
    v0031 = v0059;
    return list2(v0057, v0031);

v0055:
    v0057 = (Lisp_Object)1; /* 0 */
    return onevalue(v0057);

v0041:
    v0057 = (Lisp_Object)17; /* 1 */
    return onevalue(v0057);
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0063, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapins");
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
    stack[-2] = nil;
    goto v0066;

v0066:
    v0062 = stack[0];
    if (v0062 == nil) goto v0112;
    v0063 = stack[-1];
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0027 = cons(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0063 = qcdr(v0062);
    v0062 = stack[-2];
    v0062 = acons(v0027, v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[-2] = v0062;
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    stack[0] = v0062;
    goto v0066;

v0112:
    v0062 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0062);
    }
/* error exit handlers */
v0144:
    popv(4);
    return nil;
}



/* Code for ir2mml */

static Lisp_Object CC_ir2mml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ir2mml");
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
    v0190 = elt(env, 1); /* (indent) */
    fn = elt(env, 8); /* fluid */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-1];
    v0190 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 2)) = v0190; /* ind */
    v0190 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0190; /* indent */
    v0190 = elt(env, 4); /* "<math>" */
    fn = elt(env, 9); /* printout */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-1];
    v0190 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 10); /* indent!* */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-1];
    v0190 = stack[0];
    fn = elt(env, 11); /* expression */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-1];
    v0190 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* indent!* */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-1];
    v0190 = elt(env, 7); /* "</math>" */
    fn = elt(env, 9); /* printout */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    v0190 = nil;
    { popv(2); return onevalue(v0190); }
/* error exit handlers */
v0175:
    popv(2);
    return nil;
}



/* Code for matsm!*1 */

static Lisp_Object CC_matsmH1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0196, v0198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm*1");
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
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0196 = v0000;
/* end of prologue */
    stack[-8] = elt(env, 1); /* mat */
    stack[-7] = v0196;
    v0196 = stack[-7];
    if (v0196 == nil) goto v0175;
    v0196 = stack[-7];
    v0196 = qcar(v0196);
    stack[-3] = v0196;
    v0196 = stack[-3];
    if (v0196 == nil) goto v0189;
    v0196 = stack[-3];
    v0196 = qcar(v0196);
    fn = elt(env, 4); /* subs2!* */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    stack[-1] = v0196;
    stack[-2] = v0196;
    goto v0111;

v0111:
    v0196 = stack[-3];
    v0196 = qcdr(v0196);
    stack[-3] = v0196;
    v0196 = stack[-3];
    if (v0196 == nil) goto v0136;
    stack[0] = stack[-1];
    v0196 = stack[-3];
    v0196 = qcar(v0196);
    fn = elt(env, 4); /* subs2!* */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = Lrplacd(nil, stack[0], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = stack[-1];
    v0196 = qcdr(v0196);
    stack[-1] = v0196;
    goto v0111;

v0136:
    v0196 = stack[-2];
    goto v0101;

v0101:
    v0196 = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    stack[-5] = v0196;
    stack[-6] = v0196;
    goto v0058;

v0058:
    v0196 = stack[-7];
    v0196 = qcdr(v0196);
    stack[-7] = v0196;
    v0196 = stack[-7];
    if (v0196 == nil) goto v0026;
    stack[-4] = stack[-5];
    v0196 = stack[-7];
    v0196 = qcar(v0196);
    stack[-3] = v0196;
    v0196 = stack[-3];
    if (v0196 == nil) goto v0095;
    v0196 = stack[-3];
    v0196 = qcar(v0196);
    fn = elt(env, 4); /* subs2!* */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    stack[-1] = v0196;
    stack[-2] = v0196;
    goto v0151;

v0151:
    v0196 = stack[-3];
    v0196 = qcdr(v0196);
    stack[-3] = v0196;
    v0196 = stack[-3];
    if (v0196 == nil) goto v0152;
    stack[0] = stack[-1];
    v0196 = stack[-3];
    v0196 = qcar(v0196);
    fn = elt(env, 4); /* subs2!* */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = Lrplacd(nil, stack[0], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = stack[-1];
    v0196 = qcdr(v0196);
    stack[-1] = v0196;
    goto v0151;

v0152:
    v0196 = stack[-2];
    goto v0024;

v0024:
    v0196 = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = Lrplacd(nil, stack[-4], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0196 = stack[-5];
    v0196 = qcdr(v0196);
    stack[-5] = v0196;
    goto v0058;

v0095:
    v0196 = qvalue(elt(env, 2)); /* nil */
    goto v0024;

v0026:
    v0196 = stack[-6];
    goto v0110;

v0110:
    v0196 = cons(stack[-8], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-9];
    v0198 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v0198; /* !*sub2 */
    { popv(10); return onevalue(v0196); }

v0189:
    v0196 = qvalue(elt(env, 2)); /* nil */
    goto v0101;

v0175:
    v0196 = qvalue(elt(env, 2)); /* nil */
    goto v0110;
/* error exit handlers */
v0197:
    popv(10);
    return nil;
}



/* Code for bcfd */

static Lisp_Object CC_bcfd(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0144, v0203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcfd");
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
    v0203 = v0000;
/* end of prologue */
    v0050 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0050 == nil) goto v0110;
    v0050 = v0203;
    v0050 = integerp(v0050);
    if (v0050 == nil) goto v0053;
    v0050 = v0203;
    {
        popv(1);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0050);
    }

v0053:
    v0050 = v0203;
    v0144 = qcar(v0050);
    v0050 = elt(env, 2); /* !:mod!: */
    if (v0144 == v0050) goto v0062;
    v0050 = elt(env, 3); /* "Invalid modular coefficient" */
    v0144 = v0203;
    v0050 = list2(v0050, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0050);
    }

v0062:
    v0050 = v0203;
    v0050 = qcdr(v0050);
    {
        popv(1);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0050);
    }

v0110:
    v0144 = v0203;
    v0050 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 6); /* mkbc */
        return (*qfn2(fn))(qenv(fn), v0144, v0050);
    }
/* error exit handlers */
v0201:
    popv(1);
    return nil;
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegreecheck");
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
    v0175 = v0000;
/* end of prologue */
    v0140 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v0140 == nil) goto v0041;
    v0140 = v0175;
    fn = elt(env, 3); /* xdegree */
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[0];
    v0175 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v0140, v0175);

v0041:
    v0140 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0140); }
/* error exit handlers */
v0176:
    popv(1);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0139, v0117, v0206;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cstimes");
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
    v0139 = v0001;
    v0117 = v0000;
/* end of prologue */

v0066:
    v0138 = v0117;
    if (v0138 == nil) goto v0112;
    v0138 = v0117;
    v0206 = qcar(v0138);
    v0138 = (Lisp_Object)17; /* 1 */
    if (v0206 == v0138) goto v0057;
    v0138 = v0117;
    v0138 = qcdr(v0138);
    stack[0] = v0138;
    v0138 = v0117;
    v0138 = qcar(v0138);
    v0138 = cons(v0138, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0139 = v0138;
    v0138 = stack[0];
    v0117 = v0138;
    goto v0066;

v0057:
    v0138 = v0117;
    v0138 = qcdr(v0138);
    v0117 = v0138;
    goto v0066;

v0112:
    v0138 = v0139;
    if (v0138 == nil) goto v0055;
    v0138 = v0139;
    v0138 = qcdr(v0138);
    if (v0138 == nil) goto v0190;
    v0138 = elt(env, 1); /* times */
    popv(2);
    return cons(v0138, v0139);

v0190:
    v0138 = v0139;
    v0138 = qcar(v0138);
    { popv(2); return onevalue(v0138); }

v0055:
    v0138 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0138); }
/* error exit handlers */
v0030:
    popv(2);
    return nil;
}



/* Code for lesspcdr */

static Lisp_Object CC_lesspcdr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lesspcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0001;
    v0055 = v0000;
/* end of prologue */
    v0055 = qcdr(v0055);
    v0035 = qcdr(v0035);
        return Llessp(nil, v0055, v0035);
}



/* Code for endstat */

static Lisp_Object MS_CDECL CC_endstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endstat");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    v0112 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v0112;
    v0112 = elt(env, 2); /* end */
    fn = elt(env, 3); /* comm1 */
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    v0112 = stack[0];
    popv(1);
    return ncons(v0112);
/* error exit handlers */
v0161:
    popv(1);
    return nil;
}



/* Code for mv!-domainlist!-!* */

static Lisp_Object CC_mvKdomainlistKH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-*");
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
    stack[-2] = nil;
    goto v0066;

v0066:
    v0057 = stack[0];
    if (v0057 == nil) goto v0112;
    v0031 = stack[-1];
    v0057 = stack[0];
    v0057 = qcar(v0057);
    v0031 = times2(v0031, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-3];
    v0057 = stack[-2];
    v0057 = cons(v0031, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-3];
    stack[-2] = v0057;
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    stack[0] = v0057;
    goto v0066;

v0112:
    v0057 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0057);
    }
/* error exit handlers */
v0051:
    popv(4);
    return nil;
}



/* Code for di_insert */

static Lisp_Object MS_CDECL CC_di_insert(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0019, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "di_insert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for di_insert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0065,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0065);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0065;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0110:
    v0158 = stack[-2];
    if (v0158 == nil) goto v0161;
    v0019 = stack[-3];
    v0158 = stack[-2];
    v0158 = qcar(v0158);
    v0158 = qcar(v0158);
    fn = elt(env, 2); /* eqdummy */
    v0158 = (*qfn2(fn))(qenv(fn), v0019, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    if (v0158 == nil) goto v0206;
    v0158 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v0158;
    v0158 = stack[-2];
    v0158 = qcdr(v0158);
    stack[0] = v0158;
    v0158 = stack[-2];
    v0158 = qcar(v0158);
    v0021 = qcar(v0158);
    v0019 = stack[-3];
    v0158 = stack[-1];
    v0158 = acons(v0021, v0019, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-1] = v0158;
    v0158 = stack[0];
    stack[-2] = v0158;
    v0158 = stack[-4];
    stack[-3] = v0158;
    goto v0110;

v0206:
    v0158 = stack[-2];
    v0158 = qcdr(v0158);
    stack[-4] = v0158;
    v0158 = stack[-2];
    v0019 = qcar(v0158);
    v0158 = stack[-1];
    v0158 = cons(v0019, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-1] = v0158;
    v0158 = stack[-4];
    stack[-2] = v0158;
    goto v0110;

v0161:
    v0158 = stack[-3];
    if (v0158 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0019 = stack[-3];
    v0021 = qvalue(elt(env, 1)); /* nil */
    v0158 = stack[-1];
    popv(6);
    return acons(v0019, v0021, v0158);
/* error exit handlers */
v0199:
    popv(6);
    return nil;
}



/* Code for st_sorttree */

static Lisp_Object MS_CDECL CC_st_sorttree(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0169, v0190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0065,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0065);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0058 = v0065;
    v0169 = v0001;
    v0190 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* st_sorttree1 */
    v0058 = (*qfnn(fn))(qenv(fn), 3, v0190, v0169, v0058);
    errexit();
    v0058 = qcdr(v0058);
    return onevalue(v0058);
}



/* Code for arplus!: */

static Lisp_Object CC_arplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0032, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arplus:");
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
    v0032 = v0001;
    v0033 = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v0034 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v0034; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v0034 = v0033;
    v0034 = qcdr(v0034);
    v0032 = qcdr(v0032);
    fn = elt(env, 5); /* addf */
    v0034 = (*qfn2(fn))(qenv(fn), v0034, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    v0034 = cons(stack[0], v0034);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v0034); }
/* error exit handlers */
v0056:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for gcref_select */

static Lisp_Object CC_gcref_select(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0187, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_select");
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
    v0048 = v0000;
/* end of prologue */
    stack[-3] = v0048;
    goto v0064;

v0064:
    v0048 = stack[-3];
    if (v0048 == nil) goto v0164;
    v0048 = stack[-3];
    v0048 = qcar(v0048);
    v0096 = v0048;
    v0187 = v0096;
    v0048 = elt(env, 2); /* defd */
    v0048 = Lflagp(nil, v0187, v0048);
    env = stack[-4];
    if (v0048 == nil) goto v0103;
    v0187 = v0096;
    v0048 = qvalue(elt(env, 3)); /* gcref_nolist!* */
    v0048 = Lmemq(nil, v0187, v0048);
    v0048 = (v0048 == nil ? lisp_true : nil);
    goto v0054;

v0054:
    if (v0048 == nil) goto v0104;
    v0048 = v0096;
    v0048 = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    goto v0175;

v0175:
    stack[-2] = v0048;
    v0048 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    stack[-1] = v0048;
    v0048 = stack[-3];
    v0048 = qcdr(v0048);
    stack[-3] = v0048;
    v0048 = stack[-1];
    if (!consp(v0048)) goto v0064;
    else goto v0110;

v0110:
    v0048 = stack[-3];
    if (v0048 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0048 = stack[-3];
    v0048 = qcar(v0048);
    v0096 = v0048;
    v0187 = v0096;
    v0048 = elt(env, 2); /* defd */
    v0048 = Lflagp(nil, v0187, v0048);
    env = stack[-4];
    if (v0048 == nil) goto v0142;
    v0187 = v0096;
    v0048 = qvalue(elt(env, 3)); /* gcref_nolist!* */
    v0048 = Lmemq(nil, v0187, v0048);
    v0048 = (v0048 == nil ? lisp_true : nil);
    goto v0021;

v0021:
    if (v0048 == nil) goto v0158;
    v0048 = v0096;
    v0048 = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    goto v0149;

v0149:
    v0048 = Lrplacd(nil, stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    v0048 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    stack[-1] = v0048;
    v0048 = stack[-3];
    v0048 = qcdr(v0048);
    stack[-3] = v0048;
    goto v0110;

v0158:
    v0048 = nil;
    goto v0149;

v0142:
    v0048 = qvalue(elt(env, 1)); /* nil */
    goto v0021;

v0104:
    v0048 = nil;
    goto v0175;

v0103:
    v0048 = qvalue(elt(env, 1)); /* nil */
    goto v0054;

v0164:
    v0048 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0048); }
/* error exit handlers */
v0152:
    popv(5);
    return nil;
}



/* Code for ofsf_surep */

static Lisp_Object CC_ofsf_surep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0176, v0104, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_surep");
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
    v0176 = v0001;
    v0104 = v0000;
/* end of prologue */
    v0053 = v0104;
    v0104 = v0176;
    v0176 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* cl_simpl */
    v0176 = (*qfnn(fn))(qenv(fn), 3, v0053, v0104, v0176);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[0];
    v0104 = elt(env, 1); /* true */
    v0176 = (v0176 == v0104 ? lisp_true : nil);
    { popv(1); return onevalue(v0176); }
/* error exit handlers */
v0054:
    popv(1);
    return nil;
}



/* Code for sf2ss */

static Lisp_Object CC_sf2ss(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2ss");
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
    v0137 = stack[-1];
    if (!consp(v0137)) goto v0164;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = (consp(v0137) ? nil : lisp_true);
    goto v0161;

v0161:
    if (!(v0137 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0137 = stack[-1];
    fn = elt(env, 2); /* searchpl */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    stack[-2] = v0137;
    v0137 = stack[-2];
    fn = elt(env, 3); /* qsort */
    stack[0] = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    v0137 = stack[-2];
    v0137 = Llength(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    v0137 = cons(stack[0], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    stack[0] = v0137;
    v0160 = stack[-1];
    fn = elt(env, 4); /* sq2sspl */
    v0160 = (*qfn2(fn))(qenv(fn), v0160, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    v0137 = (Lisp_Object)17; /* 1 */
    v0137 = list2star(stack[0], v0160, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* lx2xx */
        return (*qfn1(fn))(qenv(fn), v0137);
    }

v0164:
    v0137 = qvalue(elt(env, 1)); /* t */
    goto v0161;
/* error exit handlers */
v0100:
    popv(4);
    return nil;
}



/* Code for ibalp_renewwl */

static Lisp_Object CC_ibalp_renewwl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0246, v0247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_renewwl");
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
    v0246 = v0000;
/* end of prologue */
    stack[-2] = v0246;
    goto v0110;

v0110:
    v0246 = stack[-2];
    if (v0246 == nil) goto v0064;
    v0246 = stack[-2];
    v0246 = qcar(v0246);
    stack[-1] = v0246;
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    if (!(v0246 == nil)) goto v0175;
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0247 = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = (Lisp_Object)17; /* 1 */
    v0246 = Leqn(nil, v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    if (v0246 == nil) goto v0101;
    v0246 = stack[-1];
    v0246 = qcar(v0246);
    stack[0] = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0247 = plus2(stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = (Lisp_Object)17; /* 1 */
    v0246 = (Lisp_Object)greaterp2(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    v0246 = v0246 ? lisp_true : nil;
    env = stack[-4];
    if (v0246 == nil) goto v0101;
    v0246 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    stack[-3] = v0246;
    v0246 = stack[-3];
    if (v0246 == nil) goto v0175;
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    stack[0] = qcdr(v0246);
    v0247 = stack[-3];
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = cons(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v0246 = (*qfn2(fn))(qenv(fn), stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    stack[0] = qcdr(v0246);
    v0247 = stack[-1];
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = cons(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v0246 = (*qfn2(fn))(qenv(fn), stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    goto v0175;

v0175:
    v0246 = stack[-2];
    v0246 = qcdr(v0246);
    stack[-2] = v0246;
    goto v0110;

v0101:
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    if (v0246 == nil) goto v0078;
    v0246 = qvalue(elt(env, 1)); /* nil */
    goto v0183;

v0183:
    if (v0246 == nil) goto v0175;
    v0246 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    stack[-3] = v0246;
    v0246 = stack[-3];
    if (v0246 == nil) goto v0089;
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    stack[0] = qcdr(v0246);
    v0247 = stack[-3];
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = cons(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v0246 = (*qfn2(fn))(qenv(fn), stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    stack[0] = qcdr(v0246);
    v0247 = stack[-1];
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = cons(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v0246 = (*qfn2(fn))(qenv(fn), stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    goto v0089;

v0089:
    v0246 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    stack[-3] = v0246;
    v0246 = stack[-3];
    if (v0246 == nil) goto v0175;
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    stack[0] = qcdr(v0246);
    v0247 = stack[-3];
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = cons(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v0246 = (*qfn2(fn))(qenv(fn), stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    stack[0] = qcdr(v0246);
    v0247 = stack[-1];
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = cons(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v0246 = (*qfn2(fn))(qenv(fn), stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    goto v0175;

v0078:
    v0246 = stack[-1];
    v0246 = qcar(v0246);
    stack[0] = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    v0246 = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0247 = plus2(stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-4];
    v0246 = (Lisp_Object)17; /* 1 */
    v0246 = (Lisp_Object)greaterp2(v0247, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    v0246 = v0246 ? lisp_true : nil;
    env = stack[-4];
    goto v0183;

v0064:
    v0246 = nil;
    { popv(5); return onevalue(v0246); }
/* error exit handlers */
v0248:
    popv(5);
    return nil;
}



/* Code for cgp_number */

static Lisp_Object CC_cgp_number(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_number");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0168 = v0000;
/* end of prologue */
    v0161 = v0168;
    v0168 = (Lisp_Object)81; /* 5 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0161, v0168);
    }
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0234, v0235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2s");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0234 = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0234 = stack[-3];
    if (v0234 == nil) goto v0067;
    v0235 = stack[-3];
    v0234 = elt(env, 2); /* nochange */
    v0234 = Lflagpcar(nil, v0235, v0234);
    env = stack[-5];
    if (v0234 == nil) goto v0057;
    v0234 = stack[-3];
    v0235 = qcar(v0234);
    v0234 = elt(env, 3); /* getel */
    if (!(v0235 == v0234)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0057:
    v0235 = elt(env, 4); /* random */
    v0234 = stack[-3];
    fn = elt(env, 11); /* smember */
    v0234 = (*qfn2(fn))(qenv(fn), v0235, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-5];
    if (v0234 == nil) goto v0021;
    stack[-4] = elt(env, 5); /* lambda */
    stack[-2] = elt(env, 6); /* (!*uncached) */
    stack[-1] = elt(env, 7); /* progn */
    stack[0] = elt(env, 8); /* (declare (special !*uncached)) */
    v0235 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v0234 = stack[-3];
    v0234 = list2(v0235, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-5];
    v0234 = list3(stack[-1], stack[0], v0234);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-5];
    v0234 = list3(stack[-4], stack[-2], v0234);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-5];
    v0235 = qvalue(elt(env, 10)); /* t */
    popv(6);
    return list2(v0234, v0235);

v0021:
    v0235 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v0234 = stack[-3];
    popv(6);
    return list2(v0235, v0234);

v0067:
    v0234 = elt(env, 1); /* "tell Hearn!!" */
    {
        popv(6);
        fn = elt(env, 12); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0234);
    }
/* error exit handlers */
v0099:
    popv(6);
    return nil;
}



/* Code for merge!-ind!-vars */

static Lisp_Object CC_mergeKindKvars(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge-ind-vars");
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
    v0052 = qvalue(elt(env, 1)); /* !*nocommutedf */
    if (!(v0052 == nil)) goto v0061;
    v0052 = qvalue(elt(env, 2)); /* !*commutedf */
    if (v0052 == nil) goto v0036;
    v0052 = qvalue(elt(env, 3)); /* nil */
    goto v0161;

v0161:
    if (!(v0052 == nil)) goto v0061;
    v0138 = stack[0];
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    {
        popv(4);
        fn = elt(env, 4); /* derad */
        return (*qfn2(fn))(qenv(fn), v0138, v0052);
    }

v0061:
    v0138 = stack[0];
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    {
        popv(4);
        fn = elt(env, 5); /* derad!* */
        return (*qfn2(fn))(qenv(fn), v0138, v0052);
    }

v0036:
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    stack[-2] = qcar(v0052);
    v0138 = stack[0];
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    v0052 = cons(v0138, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0052 = Lmemq(nil, stack[-2], v0052);
    goto v0161;
/* error exit handlers */
v0029:
    popv(4);
    return nil;
}



/* Code for vdpsave */

static Lisp_Object CC_vdpsave(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0060;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsave");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0060 = v0000;
/* end of prologue */
    return onevalue(v0060);
}



/* Code for vdpputprop */

static Lisp_Object MS_CDECL CC_vdpputprop(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0222, v0121, v0195, v0226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpputprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpputprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0065,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0065);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0065;
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = nil;
    v0222 = stack[-4];
    v0222 = Lconsp(nil, v0222);
    env = stack[-6];
    if (v0222 == nil) goto v0055;
    v0222 = stack[-4];
    v0222 = qcdr(v0222);
    stack[-5] = v0222;
    v0222 = Lconsp(nil, v0222);
    env = stack[-6];
    if (v0222 == nil) goto v0053;
    v0222 = stack[-5];
    v0222 = qcdr(v0222);
    stack[-5] = v0222;
    v0222 = Lconsp(nil, v0222);
    env = stack[-6];
    if (v0222 == nil) goto v0111;
    v0222 = stack[-5];
    v0222 = qcdr(v0222);
    stack[-5] = v0222;
    v0222 = Lconsp(nil, v0222);
    env = stack[-6];
    if (v0222 == nil) goto v0102;
    v0222 = stack[-5];
    v0222 = qcdr(v0222);
    stack[-5] = v0222;
    v0222 = Lconsp(nil, v0222);
    env = stack[-6];
    v0222 = (v0222 == nil ? lisp_true : nil);
    goto v0035;

v0035:
    if (v0222 == nil) goto v0021;
    stack[-1] = elt(env, 2); /* dipoly */
    stack[0] = (Lisp_Object)97; /* 6 */
    v0226 = elt(env, 3); /* "vdpputprop given a non-vdp as 1st parameter" 
*/
    v0195 = stack[-4];
    v0121 = stack[-3];
    v0222 = stack[-2];
    v0222 = list4(v0226, v0195, v0121, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    fn = elt(env, 4); /* rerror */
    v0222 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0222);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    goto v0021;

v0021:
    v0121 = stack[-3];
    v0222 = stack[-5];
    v0222 = qcar(v0222);
    v0222 = Lassoc(nil, v0121, v0222);
    v0121 = v0222;
    v0222 = v0121;
    if (v0222 == nil) goto v0143;
    v0222 = stack[-2];
    v0222 = Lrplacd(nil, v0121, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v0143:
    stack[0] = stack[-5];
    v0195 = stack[-3];
    v0121 = stack[-2];
    v0222 = stack[-5];
    v0222 = qcar(v0222);
    v0222 = acons(v0195, v0121, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0222 = Lrplaca(nil, stack[0], v0222);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v0102:
    v0222 = qvalue(elt(env, 1)); /* t */
    goto v0035;

v0111:
    v0222 = qvalue(elt(env, 1)); /* t */
    goto v0035;

v0053:
    v0222 = qvalue(elt(env, 1)); /* t */
    goto v0035;

v0055:
    v0222 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0172:
    popv(7);
    return nil;
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec1");
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
    v0179 = stack[-1];
    v0159 = (Lisp_Object)17; /* 1 */
    if (v0179 == v0159) goto v0067;
    v0159 = stack[-1];
    v0179 = sub1(v0159);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0159 = stack[0];
    v0159 = qcdr(v0159);
    fn = elt(env, 1); /* inttovec!-solve */
    v0159 = (*qfn2(fn))(qenv(fn), v0179, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    stack[-2] = v0159;
    v0159 = stack[0];
    v0179 = qcar(v0159);
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    stack[0] = difference2(v0179, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0159 = stack[-1];
    v0179 = sub1(v0159);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0159 = stack[-2];
    v0159 = CC_inttovec1(env, v0179, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    {
        Lisp_Object v0139 = stack[0];
        popv(4);
        return cons(v0139, v0159);
    }

v0067:
    v0159 = stack[0];
    v0159 = qcar(v0159);
    popv(4);
    return ncons(v0159);
/* error exit handlers */
v0138:
    popv(4);
    return nil;
}



/* Code for evaluate1 */

static Lisp_Object CC_evaluate1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0094, v0180, v0165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate1");
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
    v0094 = v0001;
    v0180 = v0000;
/* end of prologue */
    v0093 = v0180;
    if (is_number(v0093)) goto v0067;
    v0093 = v0180;
    if (v0093 == nil) goto v0067;
    v0093 = v0180;
    v0093 = Lconsp(nil, v0093);
    env = stack[0];
    if (v0093 == nil) goto v0034;
    v0093 = v0180;
    v0093 = qcar(v0093);
    if (!symbolp(v0093)) v0093 = nil;
    else { v0093 = qfastgets(v0093);
           if (v0093 != nil) { v0093 = elt(v0093, 8); /* dname */
#ifdef RECORD_GET
             if (v0093 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0093 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0093 == SPID_NOPROP) v0093 = nil; }}
#endif
    if (!(v0093 == nil)) { popv(1); return onevalue(v0180); }

v0034:
    v0165 = v0180;
    v0093 = v0094;
    v0093 = Lassoc(nil, v0165, v0093);
    v0165 = v0093;
    v0093 = v0165;
    if (v0093 == nil) goto v0189;
    v0093 = v0165;
    v0093 = qcdr(v0093);
    { popv(1); return onevalue(v0093); }

v0189:
    v0093 = v0180;
    if (!consp(v0093)) goto v0201;
    v0093 = v0180;
    v0093 = qcar(v0093);
    v0180 = qcdr(v0180);
    {
        popv(1);
        fn = elt(env, 11); /* evaluate2 */
        return (*qfnn(fn))(qenv(fn), 3, v0093, v0180, v0094);
    }

v0201:
    v0094 = v0180;
    v0093 = elt(env, 1); /* i */
    if (v0094 == v0093) goto v0138;
    v0094 = v0180;
    v0093 = elt(env, 6); /* e */
    if (v0094 == v0093) goto v0134;
    v0094 = v0180;
    v0093 = elt(env, 8); /* pi */
    v0093 = (v0094 == v0093 ? lisp_true : nil);
    goto v0047;

v0047:
    if (v0093 == nil) goto v0048;
    v0093 = v0180;
    fn = elt(env, 12); /* simp */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[0];
    v0093 = qcar(v0093);
    {
        popv(1);
        fn = elt(env, 13); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0048:
    v0093 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 9)) = v0093; /* !*evaluateerror */
    v0094 = v0180;
    v0093 = elt(env, 10); /* "number" */
    {
        popv(1);
        fn = elt(env, 14); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0094, v0093);
    }

v0134:
    v0093 = qvalue(elt(env, 7)); /* t */
    goto v0047;

v0138:
    v0094 = qvalue(elt(env, 2)); /* dmode!* */
    v0093 = elt(env, 3); /* ivalue */
    v0093 = get(v0094, v0093);
    env = stack[0];
    v0180 = v0093;
    if (v0093 == nil) goto v0026;
    v0094 = v0180;
    v0093 = elt(env, 4); /* (nil) */
    fn = elt(env, 15); /* apply */
    v0093 = (*qfn2(fn))(qenv(fn), v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    v0093 = qcar(v0093);
    { popv(1); return onevalue(v0093); }

v0026:
    v0093 = elt(env, 5); /* "i used as indeterminate value" */
    {
        popv(1);
        fn = elt(env, 16); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0067:
    v0093 = v0180;
    {
        popv(1);
        fn = elt(env, 13); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v0093);
    }
/* error exit handlers */
v0249:
    popv(1);
    return nil;
}



/* Code for coposp */

static Lisp_Object CC_coposp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0032 = v0000;
/* end of prologue */
    v0034 = v0032;
    v0034 = qcdr(v0034);
    if (v0034 == nil) goto v0041;
    v0034 = v0032;
    v0034 = qcar(v0034);
    if (!consp(v0034)) goto v0035;
    v0034 = v0032;
    v0034 = qcdr(v0034);
    {
        fn = elt(env, 2); /* covposp */
        return (*qfn1(fn))(qenv(fn), v0034);
    }

v0035:
    v0034 = v0032;
    v0034 = qcdr(v0034);
    {
        fn = elt(env, 3); /* contposp */
        return (*qfn1(fn))(qenv(fn), v0034);
    }

v0041:
    v0034 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0034);
}



/* Code for map__edges */

static Lisp_Object CC_map__edges(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for map__edges");
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
    goto v0066;

v0066:
    v0102 = stack[0];
    if (v0102 == nil) goto v0064;
    v0102 = stack[0];
    v0103 = qcar(v0102);
    v0102 = stack[-1];
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    stack[-1] = v0102;
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    stack[0] = v0102;
    goto v0066;

v0064:
    v0102 = qvalue(elt(env, 1)); /* nil */
    v0103 = v0102;
    goto v0110;

v0110:
    v0102 = stack[-1];
    if (v0102 == nil) { popv(3); return onevalue(v0103); }
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    fn = elt(env, 2); /* union_edges */
    v0102 = (*qfn2(fn))(qenv(fn), v0102, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    v0103 = v0102;
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0110;
/* error exit handlers */
v0203:
    popv(3);
    return nil;
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-global-mode");
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
    v0032 = qvalue(elt(env, 1)); /* nil */
    v0032 = ncons(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0032; /* alglist!* */
    v0032 = stack[-2];
    qvalue(elt(env, 3)) = v0032; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v0032 = stack[-2];
    v0032 = Lmkquote(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-4];
    v0032 = list3(stack[-1], stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    {
        Lisp_Object v0101 = stack[-3];
        popv(5);
        return list2(v0101, v0032);
    }
/* error exit handlers */
v0056:
    popv(5);
    return nil;
}



/* Code for rnprep!: */

static Lisp_Object CC_rnprepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0189, v0061, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnprep:");
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
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    v0189 = qcar(v0189);
    fn = elt(env, 2); /* prepf */
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-3];
    v0051 = v0189;
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    v0061 = qcdr(v0189);
    v0189 = (Lisp_Object)17; /* 1 */
    if (v0061 == v0189) { popv(4); return onevalue(v0051); }
    stack[-2] = elt(env, 1); /* quotient */
    stack[0] = v0051;
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    v0189 = qcdr(v0189);
    fn = elt(env, 2); /* prepf */
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    {
        Lisp_Object v0103 = stack[-2];
        Lisp_Object v0050 = stack[0];
        popv(4);
        return list3(v0103, v0050, v0189);
    }
/* error exit handlers */
v0102:
    popv(4);
    return nil;
}



/* Code for decprec2internal */

static Lisp_Object CC_decprec2internal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0190, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for decprec2internal");
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
    v0190 = v0000;
/* end of prologue */
    v0140 = v0190;
    v0190 = qvalue(elt(env, 1)); /* log2of10 */
    v0190 = times2(v0140, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[0];
    fn = elt(env, 2); /* ceiling */
    v0140 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    v0190 = (Lisp_Object)49; /* 3 */
    popv(1);
    return plus2(v0140, v0190);
/* error exit handlers */
v0175:
    popv(1);
    return nil;
}



/* Code for symbvarlst */

static Lisp_Object MS_CDECL CC_symbvarlst(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0065, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0145, v0188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "symbvarlst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbvarlst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0065,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0065);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0119 = v0065;
    stack[-3] = v0001;
    v0188 = v0000;
/* end of prologue */
    v0145 = v0119;
    v0119 = elt(env, 1); /* symbolic */
    if (v0145 == v0119) goto v0168;
    v0119 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0119); }

v0168:
    v0119 = v0188;
    stack[-4] = v0119;
    goto v0110;

v0110:
    v0119 = stack[-4];
    if (v0119 == nil) goto v0054;
    v0119 = stack[-4];
    v0119 = qcar(v0119);
    v0119 = Lconsp(nil, v0119);
    env = stack[-5];
    if (v0119 == nil) goto v0061;
    v0119 = stack[-4];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    goto v0045;

v0045:
    stack[0] = v0119;
    v0119 = stack[0];
    v0119 = Lsymbol_specialp(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    if (v0119 == nil) goto v0201;
    v0119 = qvalue(elt(env, 2)); /* nil */
    goto v0203;

v0203:
    if (v0119 == nil) goto v0102;
    stack[-2] = elt(env, 4); /* "local variable" */
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* "in procedure" */
    v0145 = qvalue(elt(env, 6)); /* fname!* */
    v0119 = elt(env, 7); /* "not used" */
    v0119 = list2(v0145, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0119 = list3star(stack[-2], stack[-1], stack[0], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    fn = elt(env, 8); /* lprim */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    goto v0102;

v0102:
    v0119 = stack[-4];
    v0119 = qcdr(v0119);
    stack[-4] = v0119;
    goto v0110;

v0201:
    v0119 = stack[0];
    v0119 = Lsymbol_globalp(nil, v0119);
    env = stack[-5];
    if (v0119 == nil) goto v0206;
    v0119 = qvalue(elt(env, 2)); /* nil */
    goto v0203;

v0206:
    v0145 = stack[0];
    v0119 = stack[-3];
    v0119 = Lsmemq(nil, v0145, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    if (v0119 == nil) goto v0138;
    v0119 = qvalue(elt(env, 2)); /* nil */
    goto v0203;

v0138:
    v0119 = qvalue(elt(env, 3)); /* !*novarmsg */
    v0119 = (v0119 == nil ? lisp_true : nil);
    goto v0203;

v0061:
    v0119 = stack[-4];
    v0119 = qcar(v0119);
    goto v0045;

v0054:
    v0119 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0119); }
/* error exit handlers */
v0154:
    popv(6);
    return nil;
}



/* Code for sq2sstm */

static Lisp_Object CC_sq2sstm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0096, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sstm");
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
    stack[-2] = v0001;
    v0097 = v0000;
/* end of prologue */
    v0187 = v0097;
    v0187 = qcar(v0187);
    v0096 = qcar(v0187);
    v0187 = stack[-2];
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    if (equal(v0096, v0187)) goto v0168;
    v0187 = v0097;
    stack[-1] = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0187 = stack[-2];
    v0187 = qcar(v0187);
    stack[0] = qcdr(v0187);
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0187 = sub1(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0187 = cons(stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v0187 = (*qfn2(fn))(qenv(fn), stack[-1], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0096 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0096;
    goto v0022;

v0022:
    v0096 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* mapins */
        return (*qfn2(fn))(qenv(fn), v0096, v0187);
    }

v0168:
    v0187 = v0097;
    v0187 = qcdr(v0187);
    stack[0] = v0187;
    v0187 = v0097;
    v0187 = qcar(v0187);
    v0187 = qcdr(v0187);
    stack[-3] = v0187;
    v0187 = stack[0];
    if (!consp(v0187)) goto v0057;
    v0187 = stack[0];
    v0187 = qcar(v0187);
    v0187 = (consp(v0187) ? nil : lisp_true);
    goto v0111;

v0111:
    if (v0187 == nil) goto v0138;
    stack[-1] = stack[-3];
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    fn = elt(env, 4); /* mkzl */
    v0096 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0187 = stack[0];
    v0187 = acons(stack[-1], v0096, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    popv(5);
    return ncons(v0187);

v0138:
    stack[-1] = stack[0];
    v0187 = stack[-2];
    v0187 = qcar(v0187);
    stack[0] = qcdr(v0187);
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0187 = sub1(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0187 = cons(stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v0187 = (*qfn2(fn))(qenv(fn), stack[-1], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    goto v0022;

v0057:
    v0187 = qvalue(elt(env, 1)); /* t */
    goto v0111;
/* error exit handlers */
v0173:
    popv(5);
    return nil;
}



/* Code for ibalp_tvb */

static Lisp_Object CC_ibalp_tvb(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_tvb");
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
    stack[-1] = v0001;
    v0147 = v0000;
/* end of prologue */
    stack[-2] = v0147;
    goto v0066;

v0066:
    v0147 = stack[-2];
    if (v0147 == nil) goto v0168;
    v0147 = stack[-2];
    v0147 = qcar(v0147);
    stack[0] = v0147;
    v0147 = stack[0];
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0136 = qcar(v0147);
    v0147 = stack[-1];
    v0147 = (Lisp_Object)geq2(v0136, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0147 = v0147 ? lisp_true : nil;
    env = stack[-3];
    if (v0147 == nil) goto v0190;
    v0147 = stack[0];
    v0136 = qcdr(v0147);
    v0147 = stack[0];
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcar(v0147);
    fn = elt(env, 2); /* ibalp_var!-unset */
    v0147 = (*qfn2(fn))(qenv(fn), v0136, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-3];
    goto v0190;

v0190:
    v0147 = stack[-2];
    v0147 = qcdr(v0147);
    stack[-2] = v0147;
    goto v0066;

v0168:
    v0147 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0147); }
/* error exit handlers */
v0179:
    popv(4);
    return nil;
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initwght");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    v0163 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0163;
    stack[0] = v0163;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0172 = qvalue(elt(env, 2)); /* maxvar */
    v0163 = stack[-3];
    v0163 = plus2(v0172, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0172 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0163/(16/CELL)));
    v0163 = (Lisp_Object)65; /* 4 */
    v0163 = *(Lisp_Object *)((char *)v0172 + (CELL-TAG_VECTOR) + ((int32_t)v0163/(16/CELL)));
    stack[-4] = v0163;
    goto v0168;

v0168:
    v0163 = stack[-4];
    if (v0163 == nil) goto v0174;
    v0163 = stack[-4];
    v0163 = qcar(v0163);
    stack[-2] = v0163;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0172 = qvalue(elt(env, 2)); /* maxvar */
    v0163 = stack[-2];
    v0163 = qcar(v0163);
    v0163 = plus2(v0172, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0172 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0163/(16/CELL)));
    v0163 = (Lisp_Object)1; /* 0 */
    v0163 = *(Lisp_Object *)((char *)v0172 + (CELL-TAG_VECTOR) + ((int32_t)v0163/(16/CELL)));
    if (v0163 == nil) goto v0102;
    v0163 = stack[-2];
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    fn = elt(env, 4); /* dm!-abs */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    fn = elt(env, 5); /* !:onep */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    if (!(v0163 == nil)) goto v0167;
    v0163 = stack[-5];
    v0163 = add1(v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    stack[-5] = v0163;
    goto v0167;

v0167:
    v0163 = stack[0];
    v0163 = add1(v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    stack[0] = v0163;
    goto v0102;

v0102:
    v0163 = stack[-4];
    v0163 = qcdr(v0163);
    stack[-4] = v0163;
    goto v0168;

v0174:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0172 = qvalue(elt(env, 2)); /* maxvar */
    v0163 = stack[-3];
    v0163 = plus2(v0172, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0163/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v0172 = (Lisp_Object)49; /* 3 */
    v0163 = stack[-5];
    v0163 = times2(v0172, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0163 = plus2(stack[0], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0163 = acons(stack[-2], stack[-1], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v0163;
    v0163 = nil;
    { popv(7); return onevalue(v0163); }
/* error exit handlers */
v0198:
    popv(7);
    return nil;
}



/* Code for equalreplaceby */

static Lisp_Object CC_equalreplaceby(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0161;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreplaceby");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0168 = v0000;
/* end of prologue */
    v0161 = elt(env, 1); /* replaceby */
    return cons(v0161, v0168);
}



setup_type const u16_setup[] =
{
    {"listeval",                too_few_2,      CC_listeval,   wrong_no_2},
    {"my_freeof",               too_few_2,      CC_my_freeof,  wrong_no_2},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"polynomheadreduceby",     too_few_2,      CC_polynomheadreduceby,wrong_no_2},
    {"ofsf_subf",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_subf},
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"poly-minusp",             CC_polyKminusp, too_many_1,    wrong_no_1},
    {"omsir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omsir},
    {"take-impart",             CC_takeKimpart, too_many_1,    wrong_no_1},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"dipprodin1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipprodin1},
    {"physop2sq",               CC_physop2sq,   too_many_1,    wrong_no_1},
    {"assert_format",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_format},
    {"mo_times_ei",             too_few_2,      CC_mo_times_ei,wrong_no_2},
    {"b_expand2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_b_expand2},
    {"simpatom",                CC_simpatom,    too_many_1,    wrong_no_1},
    {"readprogn",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_readprogn},
    {"sfto_varp",               CC_sfto_varp,   too_many_1,    wrong_no_1},
    {"polynommultiplybyvariable",too_few_2,     CC_polynommultiplybyvariable,wrong_no_2},
    {"ofsf_pow2q",              too_few_2,      CC_ofsf_pow2q, wrong_no_2},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"ibalp_negatet",           CC_ibalp_negatet,too_many_1,   wrong_no_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"ir2mml",                  CC_ir2mml,      too_many_1,    wrong_no_1},
    {"matsm*1",                 CC_matsmH1,     too_many_1,    wrong_no_1},
    {"bcfd",                    CC_bcfd,        too_many_1,    wrong_no_1},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"lesspcdr",                too_few_2,      CC_lesspcdr,   wrong_no_2},
    {"endstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_endstat},
    {"mv-domainlist-*",         too_few_2,      CC_mvKdomainlistKH,wrong_no_2},
    {"di_insert",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_di_insert},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"arplus:",                 too_few_2,      CC_arplusT,    wrong_no_2},
    {"gcref_select",            CC_gcref_select,too_many_1,    wrong_no_1},
    {"ofsf_surep",              too_few_2,      CC_ofsf_surep, wrong_no_2},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ibalp_renewwl",           CC_ibalp_renewwl,too_many_1,   wrong_no_1},
    {"cgp_number",              CC_cgp_number,  too_many_1,    wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"merge-ind-vars",          too_few_2,      CC_mergeKindKvars,wrong_no_2},
    {"vdpsave",                 CC_vdpsave,     too_many_1,    wrong_no_1},
    {"vdpputprop",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpputprop},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"evaluate1",               too_few_2,      CC_evaluate1,  wrong_no_2},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"map__edges",              CC_map__edges,  too_many_1,    wrong_no_1},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"rnprep:",                 CC_rnprepT,     too_many_1,    wrong_no_1},
    {"decprec2internal",        CC_decprec2internal,too_many_1,wrong_no_1},
    {"symbvarlst",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbvarlst},
    {"sq2sstm",                 too_few_2,      CC_sq2sstm,    wrong_no_2},
    {"ibalp_tvb",               too_few_2,      CC_ibalp_tvb,  wrong_no_2},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"equalreplaceby",          CC_equalreplaceby,too_many_1,  wrong_no_1},
    {NULL, (one_args *)"u16", (two_args *)"8765 2269577 6802746", 0}
};

/* end of generated code */