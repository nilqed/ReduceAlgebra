
/* $destdir\u28.c        Machine generated C code */

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


/* Code for msolve!-polyn */

static Lisp_Object CC_msolveKpolyn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-polyn");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0001;
    stack[-9] = v0000;
/* end of prologue */
    v0053 = stack[-8];
    v0053 = qcar(v0053);
    stack[-10] = v0053;
    v0053 = stack[-8];
    v0053 = qcdr(v0053);
    if (v0053 == nil) goto v0056;
    v0053 = (Lisp_Object)1; /* 0 */
    stack[-7] = v0053;
    goto v0057;

v0057:
    v0053 = qvalue(elt(env, 1)); /* current!-modulus */
    v0054 = sub1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = stack[-7];
    v0053 = difference2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = Lminusp(nil, v0053);
    env = stack[-11];
    if (v0053 == nil) goto v0059;
    v0053 = qvalue(elt(env, 2)); /* nil */
    { popv(12); return onevalue(v0053); }

v0059:
    stack[0] = stack[-9];
    v0054 = stack[-10];
    v0053 = stack[-7];
    v0053 = cons(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v0053 = (*qfn2(fn))(qenv(fn), stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = qcar(v0053);
    v0053 = stack[-8];
    v0053 = qcdr(v0053);
    v0053 = CC_msolveKpolyn(env, v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-3] = v0053;
    v0053 = stack[-3];
    if (v0053 == nil) goto v0060;
    v0053 = stack[-3];
    v0053 = qcar(v0053);
    v0055 = stack[-10];
    v0054 = stack[-7];
    v0053 = acons(v0055, v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-1] = v0053;
    stack[-2] = v0053;
    goto v0061;

v0061:
    v0053 = stack[-3];
    v0053 = qcdr(v0053);
    stack[-3] = v0053;
    v0053 = stack[-3];
    if (v0053 == nil) goto v0062;
    stack[0] = stack[-1];
    v0053 = stack[-3];
    v0053 = qcar(v0053);
    v0055 = stack[-10];
    v0054 = stack[-7];
    v0053 = acons(v0055, v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = Lrplacd(nil, stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = stack[-1];
    v0053 = qcdr(v0053);
    stack[-1] = v0053;
    goto v0061;

v0062:
    v0053 = stack[-2];
    goto v0063;

v0063:
    stack[-6] = v0053;
    v0053 = stack[-6];
    fn = elt(env, 4); /* lastpair */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-5] = v0053;
    v0053 = stack[-7];
    v0053 = add1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-7] = v0053;
    v0053 = stack[-5];
    if (!consp(v0053)) goto v0057;
    else goto v0064;

v0064:
    v0053 = qvalue(elt(env, 1)); /* current!-modulus */
    v0054 = sub1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = stack[-7];
    v0053 = difference2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = Lminusp(nil, v0053);
    env = stack[-11];
    if (!(v0053 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    stack[0] = stack[-9];
    v0054 = stack[-10];
    v0053 = stack[-7];
    v0053 = cons(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v0053 = (*qfn2(fn))(qenv(fn), stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = qcar(v0053);
    v0053 = stack[-8];
    v0053 = qcdr(v0053);
    v0053 = CC_msolveKpolyn(env, v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-3] = v0053;
    v0053 = stack[-3];
    if (v0053 == nil) goto v0065;
    v0053 = stack[-3];
    v0053 = qcar(v0053);
    v0055 = stack[-10];
    v0054 = stack[-7];
    v0053 = acons(v0055, v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-1] = v0053;
    stack[-2] = v0053;
    goto v0066;

v0066:
    v0053 = stack[-3];
    v0053 = qcdr(v0053);
    stack[-3] = v0053;
    v0053 = stack[-3];
    if (v0053 == nil) goto v0067;
    stack[0] = stack[-1];
    v0053 = stack[-3];
    v0053 = qcar(v0053);
    v0055 = stack[-10];
    v0054 = stack[-7];
    v0053 = acons(v0055, v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = Lrplacd(nil, stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = stack[-1];
    v0053 = qcdr(v0053);
    stack[-1] = v0053;
    goto v0066;

v0067:
    v0053 = stack[-2];
    goto v0068;

v0068:
    v0053 = Lrplacd(nil, stack[-4], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0053 = stack[-5];
    fn = elt(env, 4); /* lastpair */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-5] = v0053;
    v0053 = stack[-7];
    v0053 = add1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-7] = v0053;
    goto v0064;

v0065:
    v0053 = qvalue(elt(env, 2)); /* nil */
    goto v0068;

v0060:
    v0053 = qvalue(elt(env, 2)); /* nil */
    goto v0063;

v0056:
    v0054 = stack[-9];
    v0053 = stack[-8];
    v0053 = qcar(v0053);
    {
        popv(12);
        fn = elt(env, 5); /* msolve!-poly1 */
        return (*qfn2(fn))(qenv(fn), v0054, v0053);
    }
/* error exit handlers */
v0058:
    popv(12);
    return nil;
}



/* Code for even_action_sf */

static Lisp_Object MS_CDECL CC_even_action_sf(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, Lisp_Object v0070, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0079, v0080, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "even_action_sf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for even_action_sf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0070,v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0069,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
    stack[-1] = v0069;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0079 = qvalue(elt(env, 1)); /* nil */
    v0078 = (Lisp_Object)17; /* 1 */
    v0078 = cons(v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0079 = v0078;
    goto v0051;

v0051:
    v0078 = stack[-2];
    if (!consp(v0078)) goto v0004;
    v0078 = stack[-2];
    v0078 = qcar(v0078);
    v0078 = (consp(v0078) ? nil : lisp_true);
    goto v0028;

v0028:
    if (!(v0078 == nil)) { popv(6); return onevalue(v0079); }
    stack[-4] = v0079;
    v0081 = stack[-3];
    v0078 = stack[-2];
    v0080 = qcar(v0078);
    v0079 = stack[-1];
    v0078 = stack[0];
    fn = elt(env, 3); /* even_action_term */
    v0078 = (*qfnn(fn))(qenv(fn), 4, v0081, v0080, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    fn = elt(env, 4); /* addsq */
    v0078 = (*qfn2(fn))(qenv(fn), stack[-4], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0079 = v0078;
    v0078 = stack[-2];
    v0078 = qcdr(v0078);
    stack[-2] = v0078;
    goto v0051;

v0004:
    v0078 = qvalue(elt(env, 2)); /* t */
    goto v0028;
/* error exit handlers */
v0082:
    popv(6);
    return nil;
}



/* Code for ofsf_smcpknowl */

static Lisp_Object CC_ofsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0090;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smcpknowl");
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
    v0043 = v0000;
/* end of prologue */
    stack[-4] = v0043;
    v0043 = stack[-4];
    if (v0043 == nil) goto v0091;
    v0043 = stack[-4];
    v0043 = qcar(v0043);
    v0090 = v0043;
    v0043 = v0090;
    stack[0] = qcar(v0043);
    v0043 = v0090;
    v0090 = qcdr(v0043);
    v0043 = qvalue(elt(env, 1)); /* nil */
    v0043 = Lappend(nil, v0090, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    v0043 = cons(stack[0], v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    v0043 = ncons(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    stack[-2] = v0043;
    stack[-3] = v0043;
    goto v0093;

v0093:
    v0043 = stack[-4];
    v0043 = qcdr(v0043);
    stack[-4] = v0043;
    v0043 = stack[-4];
    if (v0043 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0043 = stack[-4];
    v0043 = qcar(v0043);
    v0090 = v0043;
    v0043 = v0090;
    stack[0] = qcar(v0043);
    v0043 = v0090;
    v0090 = qcdr(v0043);
    v0043 = qvalue(elt(env, 1)); /* nil */
    v0043 = Lappend(nil, v0090, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    v0043 = cons(stack[0], v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    v0043 = ncons(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    v0043 = Lrplacd(nil, stack[-1], v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    v0043 = stack[-2];
    v0043 = qcdr(v0043);
    stack[-2] = v0043;
    goto v0093;

v0091:
    v0043 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0043); }
/* error exit handlers */
v0092:
    popv(6);
    return nil;
}



/* Code for bvarom */

static Lisp_Object CC_bvarom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarom");
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
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = Lconsp(nil, v0095);
    env = stack[-1];
    if (v0095 == nil) goto v0012;
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0096 = qcar(v0095);
    v0095 = elt(env, 1); /* bvar */
    if (!(v0096 == v0095)) goto v0012;
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = qcdr(v0095);
    v0095 = qcar(v0095);
    fn = elt(env, 2); /* objectom */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0095 = stack[0];
    v0095 = qcdr(v0095);
    v0095 = CC_bvarom(env, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    goto v0012;

v0012:
    v0095 = nil;
    { popv(2); return onevalue(v0095); }
/* error exit handlers */
v0089:
    popv(2);
    return nil;
}



/* Code for look_for_substitute */

static Lisp_Object MS_CDECL CC_look_for_substitute(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0103, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_substitute");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_substitute");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0069);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0069;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0105:
    v0102 = qvalue(elt(env, 1)); /* !*nointsubst */
    if (v0102 == nil) goto v0106;
    v0102 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0102); }

v0106:
    v0102 = stack[0];
    if (!consp(v0102)) goto v0107;
    v0104 = stack[-2];
    v0103 = stack[-1];
    v0102 = stack[0];
    fn = elt(env, 3); /* look_for_exponential */
    v0102 = (*qfnn(fn))(qenv(fn), 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0103 = v0102;
    if (!(v0102 == nil)) { popv(4); return onevalue(v0103); }
    v0104 = stack[-2];
    v0103 = stack[-1];
    v0102 = stack[0];
    fn = elt(env, 4); /* look_for_rational */
    v0102 = (*qfnn(fn))(qenv(fn), 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0103 = v0102;
    if (!(v0102 == nil)) { popv(4); return onevalue(v0103); }
    v0104 = stack[-2];
    v0103 = stack[-1];
    v0102 = stack[0];
    fn = elt(env, 5); /* look_for_quad */
    v0102 = (*qfnn(fn))(qenv(fn), 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0103 = v0102;
    if (!(v0102 == nil)) { popv(4); return onevalue(v0103); }
    v0104 = stack[-2];
    v0103 = stack[-1];
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0102 = CC_look_for_substitute(env, 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0103 = v0102;
    if (!(v0102 == nil)) { popv(4); return onevalue(v0103); }
    v0104 = stack[-2];
    v0103 = stack[-1];
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    stack[-2] = v0104;
    stack[-1] = v0103;
    stack[0] = v0102;
    goto v0105;

v0107:
    v0102 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0102); }
/* error exit handlers */
v0108:
    popv(4);
    return nil;
}



/* Code for fieldp */

static Lisp_Object CC_fieldp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0076;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fieldp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0076 = v0000;
/* end of prologue */
    v0056 = v0076;
    if (!consp(v0056)) goto v0106;
    v0056 = v0076;
    v0056 = qcar(v0056);
    if (!symbolp(v0056)) v0056 = nil;
    else { v0056 = qfastgets(v0056);
           if (v0056 != nil) { v0056 = elt(v0056, 3); /* field */
#ifdef RECORD_GET
             if (v0056 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0056 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0056 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0056 == SPID_NOPROP) v0056 = nil; else v0056 = lisp_true; }}
#endif
    return onevalue(v0056);

v0106:
    v0056 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0056);
}



/* Code for calc_den_tar */

static Lisp_Object CC_calc_den_tar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_den_tar");
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
    v0110 = v0001;
    v0111 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* denlist */
    v0110 = (*qfn2(fn))(qenv(fn), v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[0];
    v0111 = v0110;
    v0110 = v0111;
    if (v0110 == nil) goto v0076;
    v0110 = v0111;
    v0110 = qcdr(v0110);
    if (v0110 == nil) goto v0051;
    v0110 = v0111;
    {
        popv(1);
        fn = elt(env, 2); /* constimes */
        return (*qfn1(fn))(qenv(fn), v0110);
    }

v0051:
    v0110 = v0111;
    v0110 = qcar(v0110);
    { popv(1); return onevalue(v0110); }

v0076:
    v0110 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0110); }
/* error exit handlers */
v0112:
    popv(1);
    return nil;
}



/* Code for subcare */

static Lisp_Object MS_CDECL CC_subcare(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0118, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subcare");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subcare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0069);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0069;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0093;

v0093:
    v0117 = stack[0];
    if (v0117 == nil) goto v0106;
    v0118 = stack[-2];
    v0117 = stack[0];
    if (equal(v0118, v0117)) goto v0004;
    v0117 = stack[0];
    if (!consp(v0117)) goto v0120;
    v0117 = stack[0];
    v0118 = qcar(v0117);
    v0117 = elt(env, 2); /* subfunc */
    v0117 = get(v0118, v0117);
    env = stack[-4];
    goto v0089;

v0089:
    if (v0117 == nil) goto v0121;
    v0118 = stack[-3];
    v0117 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0118, v0117);
    }

v0121:
    v0119 = stack[-2];
    v0118 = stack[-1];
    v0117 = stack[0];
    v0117 = qcar(v0117);
    v0118 = CC_subcare(env, 3, v0119, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0117 = stack[-3];
    v0117 = cons(v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    stack[-3] = v0117;
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    stack[0] = v0117;
    goto v0093;

v0120:
    v0117 = qvalue(elt(env, 1)); /* t */
    goto v0089;

v0004:
    v0118 = stack[-3];
    v0117 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0118, v0117);
    }

v0106:
    v0117 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0117);
    }
/* error exit handlers */
v0099:
    popv(5);
    return nil;
}



/* Code for sqprint */

static Lisp_Object CC_sqprint(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0130, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqprint");
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
    stack[0] = qvalue(elt(env, 1)); /* !*prin!# */
    qvalue(elt(env, 1)) = nil; /* !*prin!# */
    v0129 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0129; /* !*prin!# */
    v0129 = qvalue(elt(env, 3)); /* orig!* */
    stack[-2] = v0129;
    v0129 = qvalue(elt(env, 4)); /* !*nat */
    if (v0129 == nil) goto v0106;
    v0130 = qvalue(elt(env, 5)); /* posn!* */
    v0129 = (Lisp_Object)321; /* 20 */
    v0129 = (Lisp_Object)lessp2(v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    v0129 = v0129 ? lisp_true : nil;
    env = stack[-3];
    if (v0129 == nil) goto v0106;
    v0129 = qvalue(elt(env, 5)); /* posn!* */
    qvalue(elt(env, 3)) = v0129; /* orig!* */
    goto v0106;

v0106:
    v0129 = qvalue(elt(env, 6)); /* !*pri */
    if (!(v0129 == nil)) goto v0087;
    v0129 = qvalue(elt(env, 7)); /* wtl!* */
    if (!(v0129 == nil)) goto v0087;
    v0129 = stack[-1];
    v0130 = qcdr(v0129);
    v0129 = (Lisp_Object)17; /* 1 */
    if (v0130 == v0129) goto v0133;
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    if (!consp(v0129)) goto v0074;
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    v0129 = qcar(v0129);
    v0129 = (consp(v0129) ? nil : lisp_true);
    goto v0134;

v0134:
    if (v0129 == nil) goto v0063;
    v0129 = qvalue(elt(env, 8)); /* nil */
    goto v0047;

v0047:
    v0130 = stack[-1];
    v0131 = qcar(v0130);
    v0130 = v0129;
    v0129 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 10); /* xprinf */
    v0129 = (*qfnn(fn))(qenv(fn), 3, v0131, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    v0129 = elt(env, 9); /* " / " */
    fn = elt(env, 11); /* prin2!* */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    if (!consp(v0129)) goto v0101;
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0129 = (consp(v0129) ? nil : lisp_true);
    goto v0135;

v0135:
    if (v0129 == nil) goto v0136;
    v0129 = qvalue(elt(env, 8)); /* nil */
    goto v0137;

v0137:
    v0130 = stack[-1];
    v0131 = qcdr(v0130);
    v0130 = v0129;
    v0129 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 10); /* xprinf */
    v0129 = (*qfnn(fn))(qenv(fn), 3, v0131, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    goto v0086;

v0086:
    v0129 = stack[-2];
    qvalue(elt(env, 3)) = v0129; /* orig!* */
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    { popv(4); return onevalue(v0129); }

v0136:
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
    if (!(v0129 == nil)) goto v0137;
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0130 = qcdr(v0129);
    v0129 = (Lisp_Object)17; /* 1 */
    v0129 = Lneq(nil, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    goto v0137;

v0101:
    v0129 = qvalue(elt(env, 2)); /* t */
    goto v0135;

v0063:
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    v0129 = qcdr(v0129);
    goto v0047;

v0074:
    v0129 = qvalue(elt(env, 2)); /* t */
    goto v0134;

v0133:
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    fn = elt(env, 12); /* xprinf2 */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    goto v0086;

v0087:
    v0129 = stack[-1];
    fn = elt(env, 13); /* sqhorner!* */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    fn = elt(env, 14); /* prepsq!* */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    fn = elt(env, 15); /* prepreform */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    fn = elt(env, 16); /* maprin */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-3];
    goto v0086;
/* error exit handlers */
v0132:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    popv(4);
    return nil;
}



/* Code for nf */

static Lisp_Object MS_CDECL CC_nf(Lisp_Object env, int nargs,
                         Lisp_Object v0001, Lisp_Object v0069,
                         Lisp_Object v0070, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0165, v0166, v0167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "nf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0070,v0069,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0001,v0069,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0070;
    v0165 = v0069;
    v0166 = v0001;
/* end of prologue */
    stack[-10] = qvalue(elt(env, 1)); /* gg!* */
    qvalue(elt(env, 1)) = nil; /* gg!* */
    qvalue(elt(env, 1)) = v0165; /* gg!* */
    v0165 = qvalue(elt(env, 1)); /* gg!* */
    if (v0165 == nil) goto v0091;
    stack[-3] = nil;
    v0165 = (Lisp_Object)1; /* 0 */
    stack[0] = v0165;
    v0165 = v0166;
    stack[-8] = v0165;
    v0165 = qvalue(elt(env, 1)); /* gg!* */
    stack[-2] = v0165;
    goto v0112;

v0112:
    v0165 = stack[-8];
    if (v0165 == nil) goto v0168;
    v0165 = stack[-8];
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    stack[-7] = v0165;
    goto v0097;

v0097:
    v0165 = stack[-2];
    if (v0165 == nil) goto v0046;
    v0166 = stack[-7];
    v0165 = stack[-2];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    fn = elt(env, 13); /* dless */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    goto v0061;

v0061:
    if (v0165 == nil) goto v0050;
    v0165 = stack[-2];
    v0165 = qcdr(v0165);
    stack[-2] = v0165;
    goto v0097;

v0050:
    v0165 = stack[-2];
    if (v0165 == nil) goto v0168;
    v0165 = stack[-2];
    stack[-1] = v0165;
    goto v0060;

v0060:
    v0165 = stack[-1];
    if (v0165 == nil) goto v0114;
    v0165 = stack[-1];
    v0165 = qcar(v0165);
    v0166 = qcdr(v0165);
    v0165 = stack[-7];
    fn = elt(env, 14); /* dd */
    stack[-4] = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    v0166 = stack[-9];
    v0165 = (Lisp_Object)33; /* 2 */
    v0165 = plus2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    if (!(((int32_t)(stack[-4])) < ((int32_t)(v0165)))) goto v0114;
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    stack[-1] = v0165;
    goto v0060;

v0114:
    v0165 = stack[-1];
    if (v0165 == nil) goto v0170;
    v0166 = qvalue(elt(env, 4)); /* gv!* */
    v0165 = stack[-1];
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    v0165 = *(Lisp_Object *)((char *)v0166 + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    stack[-6] = v0165;
    v0165 = stack[-8];
    v0165 = qcar(v0165);
    v0166 = qcdr(v0165);
    v0165 = stack[-6];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    fn = elt(env, 15); /* gcdf!* */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-4] = v0165;
    v0165 = stack[-8];
    v0165 = qcar(v0165);
    v0166 = qcdr(v0165);
    v0165 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-5] = v0165;
    v0165 = stack[-6];
    v0165 = qcar(v0165);
    v0166 = qcdr(v0165);
    v0165 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-4] = v0165;
    v0166 = stack[-8];
    v0165 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-8] = v0165;
    v0166 = stack[-3];
    v0165 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-3] = v0165;
    v0166 = stack[-6];
    v0165 = stack[-5];
    fn = elt(env, 17); /* pcmult */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-6] = v0165;
    v0165 = stack[-6];
    stack[-4] = qcdr(v0165);
    v0166 = stack[-7];
    v0165 = stack[-1];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    fn = elt(env, 18); /* dquot */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    fn = elt(env, 19); /* pdmult */
    v0165 = (*qfn2(fn))(qenv(fn), stack[-4], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-4] = v0165;
    v0165 = qvalue(elt(env, 5)); /* tred */
    if (v0165 == nil) goto v0006;
    v0165 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    v0165 = elt(env, 6); /* "r e d u c t i o n :  " */
    v0165 = Lprinc(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    v0165 = stack[-7];
    v0165 = Lprinc(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    v0165 = elt(env, 7); /* "/" */
    v0165 = Lprinc(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    v0165 = stack[-1];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    v0165 = Lprinc(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    v0165 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    goto v0006;

v0006:
    v0165 = qvalue(elt(env, 8)); /* stars */
    if (v0165 == nil) goto v0171;
    v0165 = elt(env, 9); /* "*" */
    v0165 = Lprinc(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    goto v0171;

v0171:
    v0165 = stack[0];
    v0165 = (Lisp_Object)((int32_t)(v0165) + 0x10);
    stack[0] = v0165;
    v0165 = stack[-8];
    v0166 = qcdr(v0165);
    v0165 = stack[-4];
    fn = elt(env, 20); /* pdif */
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-8] = v0165;
    goto v0112;

v0170:
    v0165 = qvalue(elt(env, 3)); /* redtails */
    if (v0165 == nil) goto v0168;
    v0167 = stack[-7];
    v0165 = stack[-8];
    v0165 = qcar(v0165);
    v0166 = qcdr(v0165);
    v0165 = stack[-3];
    v0165 = acons(v0167, v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-3] = v0165;
    v0165 = stack[-8];
    v0165 = qcdr(v0165);
    stack[-8] = v0165;
    goto v0112;

v0168:
    v0166 = qvalue(elt(env, 10)); /* reductions!* */
    v0165 = stack[0];
    v0165 = (Lisp_Object)(int32_t)((int32_t)v0166 + (int32_t)v0165 - TAG_FIXNUM);
    qvalue(elt(env, 10)) = v0165; /* reductions!* */
    v0165 = qvalue(elt(env, 11)); /* nforms!* */
    v0165 = (Lisp_Object)((int32_t)(v0165) + 0x10);
    qvalue(elt(env, 11)) = v0165; /* nforms!* */
    v0165 = stack[-3];
    v0166 = Lnreverse(nil, v0165);
    env = stack[-11];
    v0165 = stack[-8];
    v0165 = Lappend(nil, v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    fn = elt(env, 21); /* gcdout */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-11];
    stack[-4] = v0165;
    v0165 = stack[-4];
    if (!(v0165 == nil)) goto v0172;
    v0165 = qvalue(elt(env, 12)); /* zeros!* */
    v0165 = (Lisp_Object)((int32_t)(v0165) + 0x10);
    qvalue(elt(env, 12)) = v0165; /* zeros!* */
    goto v0172;

v0172:
    v0165 = stack[-4];
    goto v0093;

v0093:
    qvalue(elt(env, 1)) = stack[-10]; /* gg!* */
    { popv(12); return onevalue(v0165); }

v0046:
    v0165 = qvalue(elt(env, 2)); /* nil */
    goto v0061;

v0091:
    v0165 = v0166;
    goto v0093;
/* error exit handlers */
v0169:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-10]; /* gg!* */
    popv(12);
    return nil;
}



/* Code for ad_splitname */

static Lisp_Object CC_ad_splitname(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_splitname");
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
    v0046 = v0000;
/* end of prologue */
    v0045 = v0046;
    if (symbolp(v0045)) goto v0085;
    v0045 = nil;
    { popv(3); return onevalue(v0045); }

v0085:
    stack[0] = nil;
    v0045 = v0046;
    v0045 = Lexplode(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    v0045 = Lreverse(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[-1] = v0045;
    goto v0174;

v0174:
    v0045 = stack[-1];
    if (v0045 == nil) goto v0077;
    v0045 = stack[-1];
    v0045 = qcar(v0045);
    fn = elt(env, 2); /* charnump!: */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    if (v0045 == nil) goto v0077;
    v0045 = stack[-1];
    v0046 = qcar(v0045);
    v0045 = stack[0];
    v0045 = cons(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[0] = v0045;
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    goto v0174;

v0077:
    v0045 = stack[-1];
    if (v0045 == nil) goto v0071;
    v0045 = stack[-1];
    v0045 = Lreverse(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    v0045 = Lcompress(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    v0045 = Lintern(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[-1] = v0045;
    goto v0071;

v0071:
    v0045 = stack[0];
    if (v0045 == nil) goto v0115;
    v0045 = stack[0];
    v0045 = Lcompress(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    stack[0] = v0045;
    goto v0115;

v0115:
    v0046 = stack[-1];
    v0045 = stack[0];
    popv(3);
    return cons(v0046, v0045);
/* error exit handlers */
v0121:
    popv(3);
    return nil;
}



/* Code for !*multf */

static Lisp_Object CC_Hmultf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0255, v0256, v0257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *multf");
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
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0255 = stack[-3];
    if (v0255 == nil) goto v0077;
    v0255 = stack[-2];
    v0255 = (v0255 == nil ? lisp_true : nil);
    goto v0076;

v0076:
    if (v0255 == nil) goto v0086;
    v0255 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0255); }

v0086:
    v0256 = stack[-3];
    v0255 = (Lisp_Object)17; /* 1 */
    if (v0256 == v0255) goto v0028;
    v0256 = stack[-2];
    v0255 = (Lisp_Object)17; /* 1 */
    if (v0256 == v0255) goto v0089;
    v0255 = stack[-3];
    if (!consp(v0255)) goto v0063;
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = (consp(v0255) ? nil : lisp_true);
    goto v0029;

v0029:
    if (v0255 == nil) goto v0038;
    stack[0] = stack[-3];
    v0255 = stack[-2];
    fn = elt(env, 7); /* squashsqrt */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    {
        Lisp_Object v0259 = stack[0];
        popv(6);
        fn = elt(env, 8); /* multd */
        return (*qfn2(fn))(qenv(fn), v0259, v0255);
    }

v0038:
    v0255 = stack[-2];
    if (!consp(v0255)) goto v0047;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = (consp(v0255) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0255 == nil) goto v0082;
    stack[0] = stack[-2];
    v0255 = stack[-3];
    fn = elt(env, 7); /* squashsqrt */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    {
        Lisp_Object v0260 = stack[0];
        popv(6);
        fn = elt(env, 8); /* multd */
        return (*qfn2(fn))(qenv(fn), v0260, v0255);
    }

v0082:
    v0255 = qvalue(elt(env, 3)); /* !*noncomp */
    if (v0255 == nil) goto v0106;
    v0256 = stack[-3];
    v0255 = stack[-2];
    {
        popv(6);
        fn = elt(env, 9); /* multf */
        return (*qfn2(fn))(qenv(fn), v0256, v0255);
    }

v0106:
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    stack[0] = v0255;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    stack[-1] = v0255;
    v0256 = stack[0];
    v0255 = stack[-1];
    if (v0256 == v0255) goto v0261;
    v0256 = stack[0];
    v0255 = stack[-1];
    fn = elt(env, 10); /* ordop */
    v0255 = (*qfn2(fn))(qenv(fn), v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    if (v0255 == nil) goto v0124;
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[0] = v0255;
    v0255 = stack[-3];
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[-1] = v0255;
    v0255 = stack[0];
    if (v0255 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    if (!consp(v0255)) goto v0262;
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    v0255 = (consp(v0255) ? nil : lisp_true);
    goto v0263;

v0263:
    if (v0255 == nil) goto v0264;
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0265;

v0265:
    if (v0255 == nil) goto v0266;
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0256 = qcar(v0255);
    v0255 = (Lisp_Object)17; /* 1 */
    v0255 = cons(v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0256 = ncons(v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[0];
    v0256 = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0256, v0255);
    }

v0266:
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0257 = qcar(v0255);
    v0256 = stack[0];
    v0255 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v0257, v0256, v0255);
    }

v0264:
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0256 = qcar(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    if (v0256 == v0255) goto v0267;
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0265;

v0267:
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    if (!consp(v0255)) goto v0268;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0256 = qcar(v0255);
    v0255 = elt(env, 4); /* (expt sqrt) */
    v0255 = Lmemq(nil, v0256, v0255);
    goto v0265;

v0268:
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0265;

v0262:
    v0255 = qvalue(elt(env, 1)); /* t */
    goto v0263;

v0124:
    v0256 = stack[-3];
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[0] = v0255;
    v0256 = stack[-3];
    v0255 = stack[-2];
    v0255 = qcdr(v0255);
    v0255 = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[-1] = v0255;
    v0255 = stack[0];
    if (v0255 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    if (!consp(v0255)) goto v0014;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    v0255 = (consp(v0255) ? nil : lisp_true);
    goto v0015;

v0015:
    if (v0255 == nil) goto v0023;
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0068;

v0068:
    if (v0255 == nil) goto v0269;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0256 = qcar(v0255);
    v0255 = (Lisp_Object)17; /* 1 */
    v0255 = cons(v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = ncons(v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0256 = CC_Hmultf(env, stack[0], v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0256, v0255);
    }

v0269:
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0257 = qcar(v0255);
    v0256 = stack[0];
    v0255 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v0257, v0256, v0255);
    }

v0023:
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0256 = qcar(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    if (v0256 == v0255) goto v0270;
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0068;

v0270:
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    if (!consp(v0255)) goto v0144;
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0256 = qcar(v0255);
    v0255 = elt(env, 4); /* (expt sqrt) */
    v0255 = Lmemq(nil, v0256, v0255);
    goto v0068;

v0144:
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0068;

v0014:
    v0255 = qvalue(elt(env, 1)); /* t */
    goto v0015;

v0261:
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0256 = ncons(v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-2];
    v0255 = qcdr(v0255);
    stack[-1] = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-3];
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    fn = elt(env, 11); /* addf */
    v0255 = (*qfn2(fn))(qenv(fn), stack[-1], v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[-1] = v0255;
    v0256 = stack[0];
    v0255 = elt(env, 5); /* sqrt */
    if (!consp(v0256)) goto v0271;
    v0256 = qcar(v0256);
    if (!(v0256 == v0255)) goto v0271;
    v0255 = stack[-1];
    fn = elt(env, 7); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[-1] = stack[0];
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    stack[0] = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = plus2(v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    fn = elt(env, 13); /* !*multfsqrt */
    v0255 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    {
        Lisp_Object v0272 = stack[-4];
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0272, v0255);
    }

v0271:
    v0256 = stack[0];
    v0255 = elt(env, 6); /* expt */
    if (!consp(v0256)) goto v0273;
    v0256 = qcar(v0256);
    if (!(v0256 == v0255)) goto v0273;
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    fn = elt(env, 14); /* prefix!-rational!-numberp */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    goto v0274;

v0274:
    if (v0255 == nil) goto v0275;
    v0255 = stack[-1];
    fn = elt(env, 7); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[-1] = stack[0];
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    stack[0] = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = plus2(v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    fn = elt(env, 15); /* !*multfexpt */
    v0255 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    {
        Lisp_Object v0276 = stack[-4];
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0276, v0255);
    }

v0275:
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = plus2(v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    fn = elt(env, 16); /* mkspm */
    v0255 = (*qfn2(fn))(qenv(fn), stack[0], v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[0] = v0255;
    v0255 = stack[0];
    if (v0255 == nil) goto v0277;
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0256 = qcdr(v0255);
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    v0255 = CC_Hmultf(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    stack[-3] = v0255;
    v0255 = (v0255 == nil ? lisp_true : nil);
    goto v0278;

v0278:
    if (!(v0255 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0256 = stack[0];
    v0255 = (Lisp_Object)17; /* 1 */
    v0255 = cons(v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0256 = ncons(v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-3];
    fn = elt(env, 9); /* multf */
    v0256 = (*qfn2(fn))(qenv(fn), v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-5];
    v0255 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0256, v0255);
    }

v0277:
    v0255 = qvalue(elt(env, 1)); /* t */
    goto v0278;

v0273:
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0274;

v0047:
    v0255 = qvalue(elt(env, 1)); /* t */
    goto v0084;

v0063:
    v0255 = qvalue(elt(env, 1)); /* t */
    goto v0029;

v0089:
    v0255 = stack[-3];
    {
        popv(6);
        fn = elt(env, 7); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v0255);
    }

v0028:
    v0255 = stack[-2];
    {
        popv(6);
        fn = elt(env, 7); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v0255);
    }

v0077:
    v0255 = qvalue(elt(env, 1)); /* t */
    goto v0076;
/* error exit handlers */
v0258:
    popv(6);
    return nil;
}



/* Code for mconv1 */

static Lisp_Object CC_mconv1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mconv1");
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
    goto v0012;

v0012:
    v0063 = stack[-1];
    if (!consp(v0063)) goto v0279;
    v0063 = stack[-1];
    v0063 = qcar(v0063);
    v0063 = (consp(v0063) ? nil : lisp_true);
    goto v0091;

v0091:
    if (v0063 == nil) goto v0096;
    stack[0] = stack[-2];
    v0063 = stack[-1];
    fn = elt(env, 2); /* drnconv */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    {
        Lisp_Object v0073 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0073, v0063);
    }

v0096:
    v0063 = stack[-1];
    v0063 = qcar(v0063);
    stack[0] = qcar(v0063);
    v0063 = stack[-1];
    v0063 = qcar(v0063);
    v0063 = qcdr(v0063);
    v0061 = CC_mconv1(env, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0063 = stack[-2];
    v0063 = acons(stack[0], v0061, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    stack[-2] = v0063;
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0012;

v0279:
    v0063 = qvalue(elt(env, 1)); /* t */
    goto v0091;
/* error exit handlers */
v0072:
    popv(4);
    return nil;
}



/* Code for !*a2f */

static Lisp_Object CC_Ha2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *a2f");
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
    v0012 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*q2f */
        return (*qfn1(fn))(qenv(fn), v0012);
    }
/* error exit handlers */
v0138:
    popv(1);
    return nil;
}



/* Code for formboollis */

static Lisp_Object MS_CDECL CC_formboollis(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, Lisp_Object v0070, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "formboollis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formboollis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0070,v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0069,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0070;
    stack[-1] = v0069;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    goto v0173;

v0173:
    v0079 = stack[-3];
    if (v0079 == nil) goto v0091;
    v0079 = stack[0];
    if (v0079 == nil) goto v0038;
    v0079 = stack[-3];
    v0081 = qcar(v0079);
    v0080 = stack[-2];
    v0079 = stack[-1];
    fn = elt(env, 1); /* formbool */
    v0080 = (*qfnn(fn))(qenv(fn), 3, v0081, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0079 = stack[-4];
    v0079 = cons(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-4] = v0079;
    goto v0106;

v0106:
    v0079 = stack[-3];
    v0079 = qcdr(v0079);
    stack[-3] = v0079;
    goto v0173;

v0038:
    v0079 = stack[-3];
    v0081 = qcar(v0079);
    v0080 = stack[-2];
    v0079 = stack[-1];
    fn = elt(env, 2); /* formc!* */
    v0080 = (*qfnn(fn))(qenv(fn), 3, v0081, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0079 = stack[-4];
    v0079 = cons(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-4] = v0079;
    goto v0106;

v0091:
    v0079 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v0079);
    }
/* error exit handlers */
v0082:
    popv(6);
    return nil;
}



/* Code for valuecoefft */

static Lisp_Object MS_CDECL CC_valuecoefft(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0037, v0029, v0063, v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "valuecoefft");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for valuecoefft");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0029 = v0069;
    v0063 = v0001;
    v0061 = v0000;
/* end of prologue */

v0138:
    v0038 = v0029;
    if (v0038 == nil) goto v0109;
    v0037 = v0061;
    v0038 = v0029;
    v0038 = qcar(v0038);
    if (v0037 == v0038) goto v0110;
    v0038 = v0063;
    v0038 = qcdr(v0038);
    v0063 = v0038;
    v0038 = v0029;
    v0038 = qcdr(v0038);
    v0029 = v0038;
    goto v0138;

v0110:
    v0038 = v0063;
    v0037 = qcar(v0038);
    v0038 = (Lisp_Object)1; /* 0 */
    if (v0037 == v0038) goto v0086;
    v0038 = v0063;
    v0038 = qcar(v0038);
    return onevalue(v0038);

v0086:
    v0038 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0038);

v0109:
    v0038 = elt(env, 1); /* "Valuecoefft - no value" */
    {
        fn = elt(env, 3); /* interr */
        return (*qfn1(fn))(qenv(fn), v0038);
    }
}



/* Code for dvfsf_0mk2 */

static Lisp_Object CC_dvfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0077, v0174;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0076 = v0001;
    v0077 = v0000;
/* end of prologue */
    v0174 = qvalue(elt(env, 1)); /* nil */
    return list3(v0077, v0076, v0174);
}



/* Code for ciml */

static Lisp_Object MS_CDECL CC_ciml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0280, v0281;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ciml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ciml");
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
    v0281 = qvalue(elt(env, 2)); /* atts */
    v0280 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 5); /* search_att */
    v0280 = (*qfn2(fn))(qenv(fn), v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    fn = elt(env, 6); /* lex */
    v0280 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0280 = qvalue(elt(env, 4)); /* char */
    stack[0] = v0280;
    fn = elt(env, 6); /* lex */
    v0280 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0280 = stack[0];
    v0280 = Lcompress(nil, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    stack[0] = v0280;
    v0280 = stack[0];
    if (!(is_number(v0280))) goto v0028;
    v0281 = stack[0];
    v0280 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 7); /* errorml */
    v0280 = (*qfn2(fn))(qenv(fn), v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    goto v0028;

v0028:
    v0280 = stack[0];
        popv(2);
        return Lintern(nil, v0280);
/* error exit handlers */
v0049:
    popv(2);
    return nil;
}



/* Code for delyzz */

static Lisp_Object CC_delyzz(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0254, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delyzz");
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
    v0050 = nil;
    goto v0091;

v0091:
    v0254 = stack[-1];
    v0049 = stack[0];
    v0049 = qcar(v0049);
    v0049 = qcar(v0049);
    if (equal(v0254, v0049)) goto v0151;
    v0049 = stack[0];
    v0049 = qcar(v0049);
    v0254 = v0050;
    v0049 = cons(v0049, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0050 = v0049;
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    stack[0] = v0049;
    goto v0091;

v0151:
    v0254 = v0050;
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0254, v0049);
    }
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for unify */

static Lisp_Object MS_CDECL CC_unify(Lisp_Object env, int nargs,
                         Lisp_Object v0070, Lisp_Object v0085,
                         Lisp_Object v0012, Lisp_Object v0138,
                         Lisp_Object v0093, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0292, v0006, v0007, v0293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "unify");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unify");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0093,v0138,v0012,v0085,v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0070,v0085,v0012,v0138,v0093);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-13] = v0093;
    stack[-14] = v0138;
    v0292 = v0012;
    v0006 = v0085;
    v0147 = v0070;
/* end of prologue */
    stack[-15] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-12] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-11] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v0147; /* op */
    v0147 = v0006;
    qvalue(elt(env, 2)) = v0147; /* r */
    v0147 = v0292;
    qvalue(elt(env, 3)) = v0147; /* p */
    v0147 = qvalue(elt(env, 2)); /* r */
    if (v0147 == nil) goto v0005;
    v0147 = qvalue(elt(env, 4)); /* nil */
    goto v0094;

v0094:
    if (v0147 == nil) goto v0052;
    v0292 = stack[-14];
    v0147 = stack[-13];
    fn = elt(env, 14); /* resume */
    v0147 = (*qfn2(fn))(qenv(fn), v0292, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-16];
    goto v0056;

v0056:
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    { popv(17); return onevalue(v0147); }

v0052:
    v0147 = qvalue(elt(env, 2)); /* r */
    if (v0147 == nil) goto v0280;
    v0147 = qvalue(elt(env, 3)); /* p */
    if (v0147 == nil) goto v0061;
    v0147 = qvalue(elt(env, 4)); /* nil */
    goto v0063;

v0063:
    if (v0147 == nil) goto v0113;
    v0147 = qvalue(elt(env, 4)); /* nil */
    goto v0056;

v0113:
    stack[0] = nil;
    stack[-9] = nil;
    stack[-8] = qvalue(elt(env, 6)); /* symm */
    qvalue(elt(env, 6)) = nil; /* symm */
    stack[-7] = qvalue(elt(env, 7)); /* comb */
    qvalue(elt(env, 7)) = nil; /* comb */
    stack[-6] = qvalue(elt(env, 8)); /* identity */
    qvalue(elt(env, 8)) = nil; /* identity */
    stack[-5] = qvalue(elt(env, 9)); /* mcontract */
    qvalue(elt(env, 9)) = nil; /* mcontract */
    stack[-4] = qvalue(elt(env, 10)); /* acontract */
    qvalue(elt(env, 10)) = nil; /* acontract */
    stack[-3] = qvalue(elt(env, 11)); /* expand */
    qvalue(elt(env, 11)) = nil; /* expand */
    stack[-2] = qvalue(elt(env, 12)); /* i */
    qvalue(elt(env, 12)) = nil; /* i */
    stack[-1] = qvalue(elt(env, 13)); /* upb */
    qvalue(elt(env, 13)) = nil; /* upb */
    v0147 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v0147; /* i */
    v0147 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 13)) = v0147; /* upb */
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcar(v0147);
    fn = elt(env, 15); /* pm!:free */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    if (v0147 == nil) goto v0125;
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcar(v0147);
    fn = elt(env, 16); /* genp */
    v0292 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    v0147 = stack[-14];
    v0147 = cons(v0292, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    stack[-14] = v0147;
    goto v0125;

v0125:
    v0147 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 17); /* initarg */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    goto v0294;

v0294:
    v0147 = stack[0];
    if (v0147 == nil) goto v0030;
    v0147 = qvalue(elt(env, 4)); /* nil */
    goto v0295;

v0295:
    if (v0147 == nil) goto v0296;
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcar(v0147);
    if (!consp(v0147)) goto v0032;
    v0293 = qvalue(elt(env, 1)); /* op */
    v0007 = qvalue(elt(env, 2)); /* r */
    v0006 = stack[-9];
    v0292 = stack[-14];
    v0147 = stack[-13];
    fn = elt(env, 18); /* suspend */
    v0147 = (*qfnn(fn))(qenv(fn), 5, v0293, v0007, v0006, v0292, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    stack[0] = v0147;
    goto v0294;

v0032:
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcar(v0147);
    fn = elt(env, 15); /* pm!:free */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    if (v0147 == nil) goto v0244;
    v0147 = qvalue(elt(env, 2)); /* r */
    v0292 = qcar(v0147);
    v0147 = stack[-9];
    v0147 = qcar(v0147);
    fn = elt(env, 19); /* bind */
    v0147 = (*qfn2(fn))(qenv(fn), v0292, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    v0147 = stack[-14];
    fn = elt(env, 20); /* chk */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    stack[-10] = v0147;
    if (v0147 == nil) goto v0003;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcdr(v0147);
    fn = elt(env, 21); /* mval */
    v0007 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    v0147 = stack[-9];
    v0006 = qcdr(v0147);
    v0292 = stack[-10];
    v0147 = stack[-13];
    v0147 = CC_unify(env, 5, stack[0], v0007, v0006, v0292, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    stack[0] = v0147;
    goto v0003;

v0003:
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcar(v0147);
    fn = elt(env, 22); /* unbind */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    goto v0294;

v0244:
    v0147 = qvalue(elt(env, 2)); /* r */
    v0292 = qcar(v0147);
    v0147 = stack[-9];
    v0147 = qcar(v0147);
    fn = elt(env, 23); /* meq */
    v0147 = (*qfn2(fn))(qenv(fn), v0292, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    if (v0147 == nil) goto v0294;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcdr(v0147);
    fn = elt(env, 21); /* mval */
    v0007 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    v0147 = stack[-9];
    v0006 = qcdr(v0147);
    v0292 = stack[-14];
    v0147 = stack[-13];
    v0147 = CC_unify(env, 5, stack[0], v0007, v0006, v0292, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    stack[0] = v0147;
    goto v0294;

v0296:
    v0147 = stack[0];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    goto v0056;

v0030:
    v0147 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 24); /* nextarg */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-16];
    stack[-9] = v0147;
    goto v0295;

v0061:
    v0147 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 25); /* ident */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-16];
    if (!(v0147 == nil)) goto v0072;
    v0147 = qvalue(elt(env, 2)); /* r */
    v0147 = qcar(v0147);
    fn = elt(env, 26); /* mgenp */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-16];
    goto v0072;

v0072:
    v0147 = (v0147 == nil ? lisp_true : nil);
    goto v0063;

v0280:
    v0147 = elt(env, 5); /* "UNIFY:pattern over-run for function " */
    v0147 = Lprinc(nil, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-16];
    v0147 = qvalue(elt(env, 1)); /* op */
    v0147 = Lprint(nil, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-16];
    v0147 = qvalue(elt(env, 4)); /* nil */
    goto v0056;

v0005:
    v0147 = qvalue(elt(env, 3)); /* p */
    v0147 = (v0147 == nil ? lisp_true : nil);
    goto v0094;
/* error exit handlers */
v0241:
    env = stack[-16];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
v0171:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
}



/* Code for groedeletip */

static Lisp_Object CC_groedeletip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groedeletip");
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

v0173:
    v0047 = stack[0];
    if (v0047 == nil) goto v0093;
    v0048 = stack[-1];
    v0047 = stack[0];
    v0047 = qcar(v0047);
    if (!(equal(v0048, v0047))) goto v0093;
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0173;

v0093:
    v0047 = stack[0];
    if (v0047 == nil) goto v0111;
    v0047 = stack[0];
    stack[-2] = v0047;
    goto v0120;

v0120:
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    if (v0047 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0048 = stack[-1];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    v0047 = qcar(v0047);
    if (equal(v0048, v0047)) goto v0116;
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0120;

v0116:
    v0048 = stack[0];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    v0047 = qcdr(v0047);
    fn = elt(env, 2); /* setcdr */
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-3];
    goto v0120;

v0111:
    v0047 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0047); }
/* error exit handlers */
v0283:
    popv(4);
    return nil;
}



/* Code for contposp */

static Lisp_Object CC_contposp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0094 = v0000;
/* end of prologue */

v0105:
    v0005 = v0094;
    if (v0005 == nil) goto v0085;
    v0005 = v0094;
    v0005 = qcar(v0005);
    if (!consp(v0005)) goto v0279;
    v0094 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0094);

v0279:
    v0094 = qcdr(v0094);
    goto v0105;

v0085:
    v0094 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0094);
}



/* Code for gfplus */

static Lisp_Object CC_gfplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0110, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0110 = v0001;
    v0111 = v0000;
/* end of prologue */
    v0087 = v0111;
    v0087 = qcar(v0087);
    if (!consp(v0087)) goto v0106;
    v0087 = v0111;
    {
        fn = elt(env, 1); /* gbfplus */
        return (*qfn2(fn))(qenv(fn), v0087, v0110);
    }

v0106:
    v0087 = v0111;
    {
        fn = elt(env, 2); /* gffplus */
        return (*qfn2(fn))(qenv(fn), v0087, v0110);
    }
}



/* Code for !:!:quotient */

static Lisp_Object CC_TTquotient(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ::quotient");
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
    v0094 = v0001;
    v0151 = v0000;
/* end of prologue */
    stack[0] = v0151;
    v0151 = v0094;
    v0151 = integerp(v0151);
    if (v0151 == nil) goto v0051;
    v0151 = v0094;
    fn = elt(env, 1); /* i2rd!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    goto v0093;

v0093:
    {
        Lisp_Object v0004 = stack[0];
        popv(2);
        fn = elt(env, 2); /* !:quotient */
        return (*qfn2(fn))(qenv(fn), v0004, v0151);
    }

v0051:
    v0151 = v0094;
    goto v0093;
/* error exit handlers */
v0028:
    popv(2);
    return nil;
}



/* Code for toolongexpp */

static Lisp_Object CC_toolongexpp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongexpp");
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
    v0091 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* numprintlen */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[0];
    v0279 = qvalue(elt(env, 1)); /* maxexpprintlen!* */
        popv(1);
        return Lgreaterp(nil, v0091, v0279);
/* error exit handlers */
v0056:
    popv(1);
    return nil;
}



/* Code for collectphysops_reversed */

static Lisp_Object CC_collectphysops_reversed(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectphysops_reversed");
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
    v0121 = stack[-1];
    if (!consp(v0121)) goto v0093;
    v0121 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    if (v0121 == nil) goto v0029;
    stack[-2] = stack[-1];
    v0121 = stack[-1];
    fn = elt(env, 3); /* collectindices */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    fn = elt(env, 4); /* removeindices */
    v0082 = (*qfn2(fn))(qenv(fn), stack[-2], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0121 = stack[0];
    popv(4);
    return cons(v0082, v0121);

v0029:
    v0121 = stack[-1];
    if (!consp(v0121)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0121 = stack[-1];
    v0082 = qcar(v0121);
    v0121 = stack[0];
    v0121 = CC_collectphysops_reversed(env, v0082, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[0] = v0121;
    v0121 = stack[-1];
    v0121 = qcdr(v0121);
    stack[-1] = v0121;
    goto v0029;

v0093:
    v0121 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    if (v0121 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0082 = stack[-1];
    v0121 = stack[0];
    popv(4);
    return cons(v0082, v0121);
/* error exit handlers */
v0048:
    popv(4);
    return nil;
}



/* Code for mk!-numr */

static Lisp_Object MS_CDECL CC_mkKnumr(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0116, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-numr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-numr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0069);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0069;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0279;

v0279:
    v0116 = stack[-1];
    v0115 = stack[0];
    if (equal(v0116, v0115)) goto v0106;
    v0116 = stack[-1];
    v0115 = (Lisp_Object)1; /* 0 */
    if (v0116 == v0115) goto v0098;
    v0059 = elt(env, 1); /* difference */
    v0116 = stack[-2];
    v0115 = stack[-1];
    v0115 = list3(v0059, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    v0116 = v0115;
    goto v0086;

v0086:
    v0115 = stack[-3];
    v0115 = cons(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    stack[-3] = v0115;
    v0115 = stack[-1];
    v0115 = add1(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    stack[-1] = v0115;
    goto v0279;

v0098:
    v0115 = stack[-2];
    v0116 = v0115;
    goto v0086;

v0106:
    v0115 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0115);
    }
/* error exit handlers */
v0045:
    popv(5);
    return nil;
}



/* Code for quotodd */

static Lisp_Object CC_quotodd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0057, v0282;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotodd");
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
    v0057 = v0001;
    v0282 = v0000;
/* end of prologue */
    v0120 = v0282;
    if (!consp(v0120)) goto v0109;
    v0120 = qvalue(elt(env, 1)); /* nil */
    goto v0173;

v0173:
    if (v0120 == nil) goto v0111;
    v0120 = v0282;
    fn = elt(env, 2); /* mkrn */
    v0120 = (*qfn2(fn))(qenv(fn), v0120, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v0120);
    }

v0111:
    v0120 = v0282;
    {
        popv(1);
        fn = elt(env, 4); /* lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v0120, v0057);
    }

v0109:
    v0120 = v0057;
    v0120 = (consp(v0120) ? nil : lisp_true);
    goto v0173;
/* error exit handlers */
v0280:
    popv(1);
    return nil;
}



/* Code for red_tailreddriver */

static Lisp_Object MS_CDECL CC_red_tailreddriver(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_tailreddriver");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_tailreddriver");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0069);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0069;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0116 = stack[-2];
    fn = elt(env, 3); /* bas_dpoly */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    if (v0116 == nil) goto v0106;
    v0116 = stack[-2];
    fn = elt(env, 3); /* bas_dpoly */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0116 = qcdr(v0116);
    if (v0116 == nil) goto v0148;
    v0116 = stack[-3];
    v0116 = (v0116 == nil ? lisp_true : nil);
    goto v0109;

v0109:
    if (!(v0116 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v0120:
    v0116 = stack[-2];
    fn = elt(env, 3); /* bas_dpoly */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    if (v0116 == nil) goto v0089;
    stack[-4] = stack[-1];
    stack[0] = stack[-3];
    v0116 = stack[-2];
    fn = elt(env, 4); /* red!=hidelt */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0116 = Lapply2(nil, 3, stack[-4], stack[0], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-2] = v0116;
    goto v0120;

v0089:
    v0116 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* red!=recover */
        return (*qfn1(fn))(qenv(fn), v0116);
    }

v0148:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0109;

v0106:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0109;
/* error exit handlers */
v0045:
    popv(6);
    return nil;
}



/* Code for simp!-prop2 */

static Lisp_Object CC_simpKprop2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0301, v0026, v0302;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop2");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    v0301 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-1] = v0301;
    goto v0076;

v0076:
    v0301 = stack[-1];
    if (v0301 == nil) goto v0056;
    v0301 = stack[-1];
    v0301 = qcar(v0301);
    stack[0] = v0301;
    v0301 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v0301;
    goto v0110;

v0110:
    v0301 = stack[-5];
    if (v0301 == nil) goto v0087;
    v0301 = stack[-5];
    v0301 = qcar(v0301);
    stack[-3] = v0301;
    v0301 = stack[-5];
    v0301 = qcdr(v0301);
    stack[-5] = v0301;
    v0026 = elt(env, 3); /* prop!* */
    v0301 = stack[0];
    v0301 = list2(v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    stack[-4] = v0301;
    v0026 = elt(env, 4); /* not_prop!* */
    v0301 = stack[0];
    v0301 = list2(v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    v0302 = v0301;
    v0026 = stack[-4];
    v0301 = stack[-3];
    v0301 = Lmember(nil, v0026, v0301);
    if (!(v0301 == nil)) goto v0048;
    v0301 = v0302;
    v0026 = stack[-4];
    v0302 = v0026;
    stack[-4] = v0301;
    goto v0048;

v0048:
    v0026 = stack[-4];
    v0301 = stack[-3];
    v0301 = Lsubst(nil, 3, v0302, v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    stack[-6] = v0301;
    v0026 = stack[-3];
    v0301 = stack[-2];
    v0301 = cons(v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    stack[-2] = v0301;
    v0026 = stack[-6];
    v0301 = stack[-5];
    v0301 = Lmember(nil, v0026, v0301);
    stack[-6] = v0301;
    if (v0301 == nil) goto v0110;
    v0301 = stack[-6];
    if (v0301 == nil) goto v0034;
    v0301 = stack[-6];
    v0026 = qcar(v0301);
    v0301 = stack[-5];
    v0301 = Ldelete(nil, v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    stack[-5] = v0301;
    v0301 = stack[-6];
    v0026 = qcar(v0301);
    v0301 = stack[-2];
    v0301 = cons(v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    stack[-2] = v0301;
    goto v0034;

v0034:
    v0026 = stack[-4];
    v0301 = stack[-3];
    v0301 = Ldelete(nil, v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    stack[-3] = v0301;
    v0301 = stack[-3];
    v0026 = ncons(v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    v0301 = stack[-2];
    fn = elt(env, 5); /* union */
    v0301 = (*qfn2(fn))(qenv(fn), v0026, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-7];
    stack[-2] = v0301;
    goto v0110;

v0087:
    v0301 = stack[-2];
    stack[-5] = v0301;
    v0301 = stack[-1];
    v0301 = qcdr(v0301);
    stack[-1] = v0301;
    goto v0076;

v0056:
    v0301 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* simp!-prop!-condense */
        return (*qfn1(fn))(qenv(fn), v0301);
    }
/* error exit handlers */
v0303:
    popv(8);
    return nil;
}



/* Code for getavalue */

static Lisp_Object CC_getavalue(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0174, v0107;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getavalue");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0174 = v0000;
/* end of prologue */
    if (!symbolp(v0174)) v0174 = nil;
    else { v0174 = qfastgets(v0174);
           if (v0174 != nil) { v0174 = elt(v0174, 4); /* avalue */
#ifdef RECORD_GET
             if (v0174 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0174 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0174 == SPID_NOPROP) v0174 = nil; }}
#endif
    v0107 = v0174;
    v0174 = v0107;
    if (v0174 == nil) goto v0056;
    v0174 = v0107;
    v0174 = qcdr(v0174);
    v0174 = qcar(v0174);
    return onevalue(v0174);

v0056:
    v0174 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0174);
}



/* Code for solvealgdepends */

static Lisp_Object CC_solvealgdepends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0125;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgdepends");
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

v0091:
    v0125 = stack[-1];
    v0119 = stack[0];
    if (equal(v0125, v0119)) goto v0109;
    v0119 = stack[-1];
    if (!consp(v0119)) goto v0148;
    v0125 = stack[-1];
    v0119 = elt(env, 3); /* root_of */
    if (!consp(v0125)) goto v0078;
    v0125 = qcar(v0125);
    if (!(v0125 == v0119)) goto v0078;
    v0125 = stack[0];
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    if (equal(v0125, v0119)) goto v0089;
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    stack[-1] = v0119;
    goto v0091;

v0089:
    v0119 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0119); }

v0078:
    v0119 = stack[-1];
    v0125 = qcar(v0119);
    v0119 = stack[0];
    v0119 = CC_solvealgdepends(env, v0125, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0125 = v0119;
    if (!(v0119 == nil)) { popv(3); return onevalue(v0125); }
    v0119 = stack[-1];
    v0125 = qcdr(v0119);
    v0119 = stack[0];
    v0119 = CC_solvealgdepends(env, v0125, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0125 = v0119;
    if (!(v0119 == nil)) { popv(3); return onevalue(v0125); }
    v0119 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0119); }

v0148:
    v0119 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0119); }

v0109:
    v0119 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0119); }
/* error exit handlers */
v0100:
    popv(3);
    return nil;
}



/* Code for reduce!-eival!-powers */

static Lisp_Object CC_reduceKeivalKpowers(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046, v0253, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-eival-powers");
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
    v0253 = v0001;
    v0113 = v0000;
/* end of prologue */
    v0045 = v0253;
    if (!consp(v0045)) goto v0056;
    v0045 = v0253;
    v0045 = qcar(v0045);
    v0045 = (consp(v0045) ? nil : lisp_true);
    goto v0279;

v0279:
    if (v0045 == nil) goto v0004;
    v0045 = qvalue(elt(env, 1)); /* t */
    goto v0173;

v0173:
    if (v0045 == nil) goto v0063;
    v0046 = v0253;
    v0045 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0046, v0045);

v0063:
    stack[0] = v0113;
    v0046 = v0253;
    v0045 = (Lisp_Object)17; /* 1 */
    v0045 = cons(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    {
        Lisp_Object v0083 = stack[0];
        popv(2);
        fn = elt(env, 2); /* reduce!-eival!-powers1 */
        return (*qfn2(fn))(qenv(fn), v0083, v0045);
    }

v0004:
    v0045 = v0253;
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0046 = qcar(v0045);
    v0045 = v0113;
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0045 = (v0046 == v0045 ? lisp_true : nil);
    v0045 = (v0045 == nil ? lisp_true : nil);
    goto v0173;

v0056:
    v0045 = qvalue(elt(env, 1)); /* t */
    goto v0279;
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0076;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+outer+list");
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
    v0056 = elt(env, 1); /* list */
    v0076 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    v0056 = stack[0];
        popv(1);
        return Lappend(nil, v0076, v0056);
/* error exit handlers */
v0174:
    popv(1);
    return nil;
}



/* Code for pasf_sisub!-gand */

static Lisp_Object MS_CDECL CC_pasf_sisubKgand(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, Lisp_Object v0070,
                         Lisp_Object v0085, Lisp_Object v0012, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0251, v0304, v0305;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "pasf_sisub-gand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_sisub-gand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0012,v0085,v0070,v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0069,v0070,v0085,v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0012;
    stack[-2] = v0085;
    stack[-3] = v0070;
    stack[-4] = v0069;
    stack[-5] = v0001;
    stack[-6] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0251 = qvalue(elt(env, 1)); /* t */
    stack[-7] = v0251;
    goto v0174;

v0174:
    v0251 = stack[-7];
    if (v0251 == nil) goto v0077;
    v0251 = stack[-5];
    if (v0251 == nil) goto v0077;
    v0251 = stack[-5];
    v0251 = qcar(v0251);
    v0304 = v0251;
    v0251 = stack[-5];
    v0251 = qcdr(v0251);
    stack[-5] = v0251;
    v0251 = v0304;
    v0305 = v0251;
    v0304 = stack[-4];
    v0251 = stack[-3];
    fn = elt(env, 6); /* pasf_sisub */
    v0251 = (*qfnn(fn))(qenv(fn), 3, v0305, v0304, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-8];
    v0305 = v0251;
    v0304 = v0305;
    v0251 = stack[-1];
    if (v0304 == v0251) goto v0038;
    v0304 = v0305;
    v0251 = stack[-2];
    if (equal(v0304, v0251)) goto v0174;
    v0304 = v0305;
    v0251 = stack[0];
    v0251 = cons(v0304, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-8];
    stack[0] = v0251;
    goto v0174;

v0038:
    v0251 = qvalue(elt(env, 2)); /* nil */
    stack[-7] = v0251;
    goto v0174;

v0077:
    v0251 = stack[-7];
    if (v0251 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v0251 = stack[0];
    if (v0251 == nil) goto v0118;
    v0251 = stack[0];
    v0251 = qcdr(v0251);
    if (v0251 == nil) goto v0118;
    v0304 = stack[-6];
    v0251 = stack[0];
    popv(9);
    return cons(v0304, v0251);

v0118:
    v0251 = stack[0];
    if (v0251 == nil) goto v0296;
    v0251 = stack[0];
    v0251 = qcar(v0251);
    { popv(9); return onevalue(v0251); }

v0296:
    v0304 = stack[-6];
    v0251 = elt(env, 3); /* and */
    if (v0304 == v0251) goto v0062;
    v0251 = elt(env, 5); /* false */
    { popv(9); return onevalue(v0251); }

v0062:
    v0251 = elt(env, 4); /* true */
    { popv(9); return onevalue(v0251); }
/* error exit handlers */
v0298:
    popv(9);
    return nil;
}



/* Code for dip_fmon */

static Lisp_Object CC_dip_fmon(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0077, v0174;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_fmon");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0077 = v0001;
    v0076 = v0000;
/* end of prologue */
    v0174 = qvalue(elt(env, 1)); /* nil */
    return list2star(v0077, v0076, v0174);
}



/* Code for setfuncsnaryrd */

static Lisp_Object MS_CDECL CC_setfuncsnaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0134, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setfuncsnaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setfuncsnaryrd");
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
    fn = elt(env, 4); /* mathml */
    v0134 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-1];
    stack[0] = v0134;
    v0134 = stack[0];
    v0134 = Lconsp(nil, v0134);
    env = stack[-1];
    if (v0134 == nil) goto v0138;
    v0134 = stack[0];
    v0134 = qcdr(v0134);
    v0134 = qcar(v0134);
    if (v0134 == nil) goto v0138;
    v0134 = stack[0];
    v0134 = qcdr(v0134);
    v0134 = qcar(v0134);
    v0134 = qcar(v0134);
    v0134 = qcdr(v0134);
    v0134 = qcar(v0134);
    v0074 = Lintern(nil, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-1];
    v0134 = elt(env, 1); /* multiset */
    if (!(v0074 == v0134)) goto v0138;
    v0134 = elt(env, 1); /* multiset */
    qvalue(elt(env, 2)) = v0134; /* mmlatts */
    goto v0138;

v0138:
    v0134 = stack[0];
    if (v0134 == nil) goto v0280;
    v0134 = CC_setfuncsnaryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    {
        Lisp_Object v0115 = stack[0];
        popv(2);
        return cons(v0115, v0134);
    }

v0280:
    v0134 = nil;
    { popv(2); return onevalue(v0134); }
/* error exit handlers */
v0073:
    popv(2);
    return nil;
}



/* Code for amatch */

static Lisp_Object MS_CDECL CC_amatch(Lisp_Object env, int nargs,
                         Lisp_Object v0069, Lisp_Object v0070,
                         Lisp_Object v0085, Lisp_Object v0012, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0133, v0160, v0247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "amatch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for amatch");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0012,v0085,v0070,v0069);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0069,v0070,v0085,v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0012;
    stack[-4] = v0085;
    v0133 = v0070;
    v0123 = v0069;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* r */
    qvalue(elt(env, 1)) = nil; /* r */
    stack[-2] = qvalue(elt(env, 2)); /* p */
    qvalue(elt(env, 2)) = nil; /* p */
    qvalue(elt(env, 1)) = v0123; /* r */
    v0123 = v0133;
    qvalue(elt(env, 2)) = v0123; /* p */
    goto v0174;

v0174:
    v0123 = qvalue(elt(env, 1)); /* r */
    if (!consp(v0123)) goto v0005;
    v0123 = qvalue(elt(env, 2)); /* p */
    if (!consp(v0123)) goto v0036;
    v0123 = qvalue(elt(env, 1)); /* r */
    v0133 = qcar(v0123);
    v0123 = qvalue(elt(env, 2)); /* p */
    v0123 = qcar(v0123);
    v0123 = Lneq(nil, v0133, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    goto v0097;

v0097:
    if (v0123 == nil) goto v0081;
    v0123 = qvalue(elt(env, 1)); /* r */
    fn = elt(env, 7); /* suchp */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    if (v0123 == nil) goto v0119;
    v0123 = qvalue(elt(env, 1)); /* r */
    v0123 = qcdr(v0123);
    v0123 = qcar(v0123);
    stack[0] = v0123;
    v0123 = qvalue(elt(env, 1)); /* r */
    v0123 = qcdr(v0123);
    v0123 = qcdr(v0123);
    v0133 = qcar(v0123);
    v0123 = stack[-4];
    v0123 = cons(v0133, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    stack[-4] = v0123;
    v0123 = stack[0];
    qvalue(elt(env, 1)) = v0123; /* r */
    goto v0174;

v0119:
    v0123 = qvalue(elt(env, 5)); /* !*semantic */
    if (v0123 == nil) goto v0298;
    v0160 = elt(env, 6); /* equal */
    v0133 = qvalue(elt(env, 1)); /* r */
    v0123 = qvalue(elt(env, 2)); /* p */
    v0133 = list3(v0160, v0133, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0123 = stack[-4];
    v0133 = cons(v0133, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0123 = stack[-3];
    fn = elt(env, 8); /* resume */
    v0123 = (*qfn2(fn))(qenv(fn), v0133, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    goto v0106;

v0106:
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    { popv(7); return onevalue(v0123); }

v0298:
    v0123 = qvalue(elt(env, 3)); /* nil */
    goto v0106;

v0081:
    v0123 = qvalue(elt(env, 1)); /* r */
    stack[0] = qcar(v0123);
    v0123 = qvalue(elt(env, 1)); /* r */
    v0123 = qcdr(v0123);
    fn = elt(env, 9); /* mval */
    v0247 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0123 = qvalue(elt(env, 2)); /* p */
    v0160 = qcdr(v0123);
    v0133 = stack[-4];
    v0123 = stack[-3];
    fn = elt(env, 10); /* unify */
    v0123 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0247, v0160, v0133, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    goto v0106;

v0036:
    v0123 = qvalue(elt(env, 4)); /* t */
    goto v0097;

v0005:
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v0123 = qvalue(elt(env, 1)); /* r */
    v0123 = ncons(v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    fn = elt(env, 9); /* mval */
    stack[0] = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0123 = qvalue(elt(env, 2)); /* p */
    v0160 = ncons(v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0133 = stack[-4];
    v0123 = stack[-3];
    fn = elt(env, 10); /* unify */
    v0123 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], v0160, v0133, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    goto v0106;
/* error exit handlers */
v0290:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    popv(7);
    return nil;
}



/* Code for vdp2a */

static Lisp_Object CC_vdp2a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0173 = v0000;
/* end of prologue */
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0173 = qcar(v0173);
    {
        fn = elt(env, 1); /* dip2a */
        return (*qfn1(fn))(qenv(fn), v0173);
    }
}



/* Code for inprinla */

static Lisp_Object MS_CDECL CC_inprinla(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprinla");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inprinla");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0069);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0069;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0118 = stack[-2];
    if (!symbolp(v0118)) v0118 = nil;
    else { v0118 = qfastgets(v0118);
           if (v0118 != nil) { v0118 = elt(v0118, 49); /* alt */
#ifdef RECORD_GET
             if (v0118 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0118 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0118 == SPID_NOPROP) v0118 = nil; }}
#endif
    if (!(v0118 == nil)) goto v0093;
    v0118 = stack[0];
    v0119 = qcar(v0118);
    v0118 = stack[-1];
    fn = elt(env, 4); /* maprintla */
    v0118 = (*qfn2(fn))(qenv(fn), v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    goto v0138;

v0138:
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    stack[0] = v0118;
    goto v0093;

v0093:
    v0118 = stack[0];
    if (v0118 == nil) goto v0087;
    v0118 = stack[0];
    v0118 = qcar(v0118);
    if (!consp(v0118)) goto v0089;
    stack[-3] = stack[-2];
    v0118 = stack[0];
    v0118 = qcar(v0118);
    v0119 = qcar(v0118);
    v0118 = elt(env, 3); /* alt */
    v0118 = Lget(nil, v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0118 = (stack[-3] == v0118 ? lisp_true : nil);
    v0118 = (v0118 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0118 == nil) goto v0090;
    v0118 = stack[-2];
    fn = elt(env, 5); /* oprinla */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0118 = stack[0];
    v0118 = qcar(v0118);
    fn = elt(env, 6); /* negnumberchk */
    v0119 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0118 = stack[-1];
    fn = elt(env, 4); /* maprintla */
    v0118 = (*qfn2(fn))(qenv(fn), v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    goto v0138;

v0090:
    v0118 = stack[0];
    v0119 = qcar(v0118);
    v0118 = stack[-1];
    fn = elt(env, 4); /* maprintla */
    v0118 = (*qfn2(fn))(qenv(fn), v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    goto v0138;

v0089:
    v0118 = qvalue(elt(env, 2)); /* t */
    goto v0088;

v0087:
    v0118 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0118); }
/* error exit handlers */
v0099:
    popv(5);
    return nil;
}



/* Code for simp!-prop!-condense */

static Lisp_Object CC_simpKpropKcondense(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-condense");
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
    stack[-2] = nil;
    v0090 = stack[-3];
    v0043 = elt(env, 1); /* lambda_mka0p5_6 */
    fn = elt(env, 3); /* sort */
    v0043 = (*qfn2(fn))(qenv(fn), v0090, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    stack[-3] = v0043;
    goto v0174;

v0174:
    v0043 = stack[-3];
    if (v0043 == nil) goto v0077;
    v0043 = stack[-3];
    v0043 = qcar(v0043);
    stack[-4] = v0043;
    v0043 = stack[-3];
    v0043 = qcdr(v0043);
    stack[-3] = v0043;
    v0090 = stack[-4];
    v0043 = stack[-2];
    v0043 = cons(v0090, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    stack[-2] = v0043;
    v0043 = stack[-3];
    stack[-1] = v0043;
    goto v0282;

v0282:
    v0043 = stack[-1];
    if (v0043 == nil) goto v0174;
    v0043 = stack[-1];
    v0043 = qcar(v0043);
    stack[0] = v0043;
    v0090 = stack[-4];
    v0043 = stack[0];
    fn = elt(env, 4); /* subsetp */
    v0043 = (*qfn2(fn))(qenv(fn), v0090, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    if (v0043 == nil) goto v0063;
    v0090 = stack[0];
    v0043 = stack[-3];
    v0043 = Ldelete(nil, v0090, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-5];
    stack[-3] = v0043;
    goto v0063;

v0063:
    v0043 = stack[-1];
    v0043 = qcdr(v0043);
    stack[-1] = v0043;
    goto v0282;

v0077:
    v0043 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* ordn */
        return (*qfn1(fn))(qenv(fn), v0043);
    }
/* error exit handlers */
v0092:
    popv(6);
    return nil;
}



/* Code for lambda_mka0p5_6 */

static Lisp_Object CC_lambda_mka0p5_6(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_mka0p5_6");
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
    v0056 = v0000;
/* end of prologue */
    stack[-1] = Llength(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0056 = stack[0];
    v0056 = Llength(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    {
        Lisp_Object v0107 = stack[-1];
        popv(3);
        return Llessp(nil, v0107, v0056);
    }
/* error exit handlers */
v0174:
    popv(3);
    return nil;
}



/* Code for cl_sitheo */

static Lisp_Object CC_cl_sitheo(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0060, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sitheo");
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
    stack[-1] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*rlsiexpla */
    qvalue(elt(env, 1)) = nil; /* !*rlsiexpla */
    v0114 = qvalue(elt(env, 2)); /* !*rlsithok */
    if (v0114 == nil) goto v0174;
    v0114 = stack[-2];
    goto v0093;

v0093:
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    { popv(5); return onevalue(v0114); }

v0174:
    v0114 = stack[-2];
    if (v0114 == nil) goto v0082;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    stack[-3] = v0114;
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    stack[-2] = v0114;
    v0060 = stack[-3];
    v0114 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* cl_simplat */
    v0114 = (*qfn2(fn))(qenv(fn), v0060, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0128 = v0114;
    v0060 = v0128;
    v0114 = elt(env, 4); /* false */
    if (v0060 == v0114) goto v0057;
    v0060 = v0128;
    v0114 = elt(env, 6); /* true */
    if (v0060 == v0114) goto v0174;
    v0060 = v0128;
    v0114 = stack[-1];
    v0114 = cons(v0060, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    stack[-1] = v0114;
    goto v0174;

v0057:
    v0114 = elt(env, 5); /* inctheo */
    stack[-3] = v0114;
    v0114 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v0114;
    goto v0174;

v0082:
    v0060 = stack[-3];
    v0114 = elt(env, 5); /* inctheo */
    if (v0060 == v0114) goto v0113;
    v0114 = stack[-1];
    goto v0093;

v0113:
    v0114 = elt(env, 5); /* inctheo */
    goto v0093;
/* error exit handlers */
v0125:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    popv(5);
    return nil;
}



/* Code for listeval0 */

static Lisp_Object CC_listeval0(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0253, v0113, v0121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval0");
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
    v0253 = qvalue(elt(env, 1)); /* simpcount!* */
    v0113 = add1(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    qvalue(elt(env, 1)) = v0113; /* simpcount!* */
    v0253 = qvalue(elt(env, 2)); /* simplimit!* */
    v0253 = (Lisp_Object)greaterp2(v0113, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    v0253 = v0253 ? lisp_true : nil;
    env = stack[-1];
    if (v0253 == nil) goto v0138;
    v0253 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0253; /* simpcount!* */
    v0121 = elt(env, 3); /* rlisp */
    v0113 = (Lisp_Object)321; /* 20 */
    v0253 = elt(env, 4); /* "Simplification recursion too deep" */
    fn = elt(env, 5); /* rerror */
    v0253 = (*qfnn(fn))(qenv(fn), 3, v0121, v0113, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    goto v0138;

v0138:
    v0253 = stack[0];
    if (!(symbolp(v0253))) goto v0098;
    v0253 = stack[0];
    if (!symbolp(v0253)) v0253 = nil;
    else { v0253 = qfastgets(v0253);
           if (v0253 != nil) { v0253 = elt(v0253, 17); /* share */
#ifdef RECORD_GET
             if (v0253 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0253 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0253 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0253 == SPID_NOPROP) v0253 = nil; else v0253 = lisp_true; }}
#endif
    if (v0253 == nil) goto v0282;
    v0253 = stack[0];
    fn = elt(env, 6); /* eval */
    v0253 = (*qfn1(fn))(qenv(fn), v0253);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0253 = CC_listeval0(env, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    stack[0] = v0253;
    goto v0098;

v0098:
    v0253 = qvalue(elt(env, 1)); /* simpcount!* */
    v0253 = sub1(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    qvalue(elt(env, 1)) = v0253; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0282:
    v0253 = stack[0];
    if (!symbolp(v0253)) v0253 = nil;
    else { v0253 = qfastgets(v0253);
           if (v0253 != nil) { v0253 = elt(v0253, 4); /* avalue */
#ifdef RECORD_GET
             if (v0253 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0253 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0253 == SPID_NOPROP) v0253 = nil; }}
#endif
    v0121 = v0253;
    if (v0253 == nil) goto v0098;
    v0253 = v0121;
    v0253 = qcdr(v0253);
    v0113 = qcar(v0253);
    v0253 = stack[0];
    if (equal(v0113, v0253)) goto v0098;
    v0253 = v0121;
    v0253 = qcdr(v0253);
    v0253 = qcar(v0253);
    v0253 = CC_listeval0(env, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    stack[0] = v0253;
    goto v0098;
/* error exit handlers */
v0083:
    popv(2);
    return nil;
}



/* Code for tayexp!-max2 */

static Lisp_Object CC_tayexpKmax2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-max2");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0052 = stack[-1];
    v0148 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v0148 = (*qfn2(fn))(qenv(fn), v0052, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    if (v0148 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0005:
    popv(2);
    return nil;
}



/* Code for my!+nullsq!+p */

static Lisp_Object CC_myLnullsqLp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my+nullsq+p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0091 = v0000;
/* end of prologue */
    v0091 = qcar(v0091);
    if (v0091 == nil) goto v0138;
    v0091 = nil;
    return onevalue(v0091);

v0138:
    v0091 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0091);
}



/* Code for cl_susicpknowl */

static Lisp_Object CC_cl_susicpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0079;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susicpknowl");
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
    v0078 = v0000;
/* end of prologue */
    stack[-3] = v0078;
    v0078 = stack[-3];
    if (v0078 == nil) goto v0091;
    v0078 = stack[-3];
    v0078 = qcar(v0078);
    v0079 = v0078;
    v0079 = qcar(v0079);
    v0078 = qcdr(v0078);
    v0078 = cons(v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-4];
    v0078 = ncons(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-4];
    stack[-1] = v0078;
    stack[-2] = v0078;
    goto v0093;

v0093:
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    stack[-3] = v0078;
    v0078 = stack[-3];
    if (v0078 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0078 = stack[-3];
    v0078 = qcar(v0078);
    v0079 = v0078;
    v0079 = qcar(v0079);
    v0078 = qcdr(v0078);
    v0078 = cons(v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-4];
    v0078 = ncons(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-4];
    v0078 = Lrplacd(nil, stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-4];
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    stack[-1] = v0078;
    goto v0093;

v0091:
    v0078 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0078); }
/* error exit handlers */
v0253:
    popv(5);
    return nil;
}



/* Code for aex_subrp */

static Lisp_Object MS_CDECL CC_aex_subrp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0098, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_subrp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0069);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0069;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0112 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v0095 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0098 = stack[-1];
    v0112 = stack[0];
    fn = elt(env, 3); /* ratpoly_sub */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0095, v0098, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0112 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v0095 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0098 = qvalue(elt(env, 1)); /* nil */
    v0112 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0057 = stack[0];
        popv(4);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0057, v0095, v0098, v0112);
    }
/* error exit handlers */
v0120:
    popv(4);
    return nil;
}



/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setrd");
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
    v0004 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v0004; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v0004 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-1];
    v0004 = cons(stack[0], v0004);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-1];
    v0086 = v0004;
    v0004 = v0086;
    stack[0] = qcar(v0004);
    v0004 = v0086;
    v0004 = qcdr(v0004);
    fn = elt(env, 5); /* norepeat */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    {
        Lisp_Object v0111 = stack[0];
        popv(2);
        return cons(v0111, v0004);
    }
/* error exit handlers */
v0110:
    popv(2);
    return nil;
}



/* Code for prlist */

static Lisp_Object CC_prlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prlist");
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
    v0088 = nil;
    goto v0012;

v0012:
    v0096 = stack[0];
    if (v0096 == nil) goto v0173;
    v0096 = stack[0];
    v0096 = qcar(v0096);
    v0096 = Lconsp(nil, v0096);
    env = stack[-1];
    if (v0096 == nil) goto v0111;
    v0096 = stack[0];
    v0096 = qcar(v0096);
    v0096 = cons(v0096, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-1];
    v0088 = v0096;
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    stack[0] = v0096;
    goto v0012;

v0111:
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    stack[0] = v0096;
    goto v0012;

v0173:
    v0096 = v0088;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0096);
    }
/* error exit handlers */
v0120:
    popv(2);
    return nil;
}



/* Code for mkmatrix */

static Lisp_Object CC_mkmatrix(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0303;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkmatrix");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0001;
    stack[-9] = v0000;
/* end of prologue */
    stack[-10] = elt(env, 1); /* mat */
    v0068 = (Lisp_Object)17; /* 1 */
    stack[-7] = v0068;
    v0303 = stack[-9];
    v0068 = stack[-7];
    v0068 = difference2(v0303, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lminusp(nil, v0068);
    env = stack[-11];
    if (v0068 == nil) goto v0051;
    v0068 = qvalue(elt(env, 2)); /* nil */
    goto v0093;

v0093:
    {
        Lisp_Object v0157 = stack[-10];
        popv(12);
        return cons(v0157, v0068);
    }

v0051:
    v0068 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0068;
    v0303 = stack[-8];
    v0068 = stack[-3];
    v0068 = difference2(v0303, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lminusp(nil, v0068);
    env = stack[-11];
    if (v0068 == nil) goto v0281;
    v0068 = qvalue(elt(env, 2)); /* nil */
    goto v0120;

v0120:
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    stack[-5] = v0068;
    stack[-6] = v0068;
    goto v0077;

v0077:
    v0068 = stack[-7];
    v0068 = add1(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    stack[-7] = v0068;
    v0303 = stack[-9];
    v0068 = stack[-7];
    v0068 = difference2(v0303, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lminusp(nil, v0068);
    env = stack[-11];
    if (v0068 == nil) goto v0252;
    v0068 = stack[-6];
    goto v0093;

v0252:
    stack[-4] = stack[-5];
    v0068 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0068;
    v0303 = stack[-8];
    v0068 = stack[-3];
    v0068 = difference2(v0303, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lminusp(nil, v0068);
    env = stack[-11];
    if (v0068 == nil) goto v0300;
    v0068 = qvalue(elt(env, 2)); /* nil */
    goto v0291;

v0291:
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lrplacd(nil, stack[-4], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = stack[-5];
    v0068 = qcdr(v0068);
    stack[-5] = v0068;
    goto v0077;

v0300:
    v0068 = (Lisp_Object)1; /* 0 */
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    stack[-1] = v0068;
    stack[-2] = v0068;
    goto v0295;

v0295:
    v0068 = stack[-3];
    v0068 = add1(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    stack[-3] = v0068;
    v0303 = stack[-8];
    v0068 = stack[-3];
    v0068 = difference2(v0303, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lminusp(nil, v0068);
    env = stack[-11];
    if (v0068 == nil) goto v0132;
    v0068 = stack[-2];
    goto v0291;

v0132:
    stack[0] = stack[-1];
    v0068 = (Lisp_Object)1; /* 0 */
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lrplacd(nil, stack[0], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    stack[-1] = v0068;
    goto v0295;

v0281:
    v0068 = (Lisp_Object)1; /* 0 */
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    stack[-1] = v0068;
    stack[-2] = v0068;
    goto v0057;

v0057:
    v0068 = stack[-3];
    v0068 = add1(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    stack[-3] = v0068;
    v0303 = stack[-8];
    v0068 = stack[-3];
    v0068 = difference2(v0303, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lminusp(nil, v0068);
    env = stack[-11];
    if (v0068 == nil) goto v0047;
    v0068 = stack[-2];
    goto v0120;

v0047:
    stack[0] = stack[-1];
    v0068 = (Lisp_Object)1; /* 0 */
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = Lrplacd(nil, stack[0], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-11];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    stack[-1] = v0068;
    goto v0057;
/* error exit handlers */
v0309:
    popv(12);
    return nil;
}



/* Code for contr2 */

static Lisp_Object MS_CDECL CC_contr2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0069, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0253, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contr2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0069,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0069);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0069;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0093;

v0093:
    v0253 = stack[-1];
    if (v0253 == nil) goto v0076;
    v0253 = stack[0];
    if (v0253 == nil) goto v0095;
    v0113 = stack[-2];
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    fn = elt(env, 1); /* split!-road */
    v0113 = (*qfn2(fn))(qenv(fn), v0113, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    v0253 = stack[-3];
    v0253 = cons(v0113, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    stack[-3] = v0253;
    v0253 = stack[-1];
    v0253 = qcdr(v0253);
    stack[-1] = v0253;
    goto v0093;

v0095:
    stack[0] = stack[-3];
    v0113 = stack[-2];
    v0253 = stack[-1];
    fn = elt(env, 2); /* contr */
    v0253 = (*qfn2(fn))(qenv(fn), v0113, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    {
        Lisp_Object v0048 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0048, v0253);
    }

v0076:
    stack[-1] = stack[-3];
    v0113 = stack[-2];
    v0253 = stack[0];
    fn = elt(env, 2); /* contr */
    v0253 = (*qfn2(fn))(qenv(fn), v0113, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    {
        Lisp_Object v0043 = stack[-1];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0043, v0253);
    }
/* error exit handlers */
v0047:
    popv(5);
    return nil;
}



/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0283;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hide");
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
    v0044 = v0000;
/* end of prologue */
    stack[-5] = v0044;
    v0044 = stack[-5];
    if (v0044 == nil) goto v0091;
    v0044 = stack[-5];
    v0044 = qcar(v0044);
    stack[-1] = v0044;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v0044 = stack[-1];
    v0044 = qcar(v0044);
    fn = elt(env, 2); /* mo_neg */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v0283 = (*qfn2(fn))(qenv(fn), stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    v0044 = cons(v0283, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0044 = ncons(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    stack[-3] = v0044;
    stack[-4] = v0044;
    goto v0093;

v0093:
    v0044 = stack[-5];
    v0044 = qcdr(v0044);
    stack[-5] = v0044;
    v0044 = stack[-5];
    if (v0044 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v0044 = stack[-5];
    v0044 = qcar(v0044);
    stack[-1] = v0044;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v0044 = stack[-1];
    v0044 = qcar(v0044);
    fn = elt(env, 2); /* mo_neg */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v0283 = (*qfn2(fn))(qenv(fn), stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    v0044 = cons(v0283, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0044 = ncons(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0044 = Lrplacd(nil, stack[-2], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0044 = stack[-3];
    v0044 = qcdr(v0044);
    stack[-3] = v0044;
    goto v0093;

v0091:
    v0044 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0044); }
/* error exit handlers */
v0119:
    popv(7);
    return nil;
}



setup_type const u28_setup[] =
{
    {"msolve-polyn",            too_few_2,      CC_msolveKpolyn,wrong_no_2},
    {"even_action_sf",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_sf},
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,too_many_1,  wrong_no_1},
    {"bvarom",                  CC_bvarom,      too_many_1,    wrong_no_1},
    {"look_for_substitute",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_substitute},
    {"fieldp",                  CC_fieldp,      too_many_1,    wrong_no_1},
    {"calc_den_tar",            too_few_2,      CC_calc_den_tar,wrong_no_2},
    {"subcare",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subcare},
    {"sqprint",                 CC_sqprint,     too_many_1,    wrong_no_1},
    {"nf",                      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nf},
    {"ad_splitname",            CC_ad_splitname,too_many_1,    wrong_no_1},
    {"*multf",                  too_few_2,      CC_Hmultf,     wrong_no_2},
    {"mconv1",                  CC_mconv1,      too_many_1,    wrong_no_1},
    {"*a2f",                    CC_Ha2f,        too_many_1,    wrong_no_1},
    {"formboollis",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_formboollis},
    {"valuecoefft",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_valuecoefft},
    {"dvfsf_0mk2",              too_few_2,      CC_dvfsf_0mk2, wrong_no_2},
    {"ciml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_ciml},
    {"delyzz",                  too_few_2,      CC_delyzz,     wrong_no_2},
    {"unify",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_unify},
    {"groedeletip",             too_few_2,      CC_groedeletip,wrong_no_2},
    {"contposp",                CC_contposp,    too_many_1,    wrong_no_1},
    {"gfplus",                  too_few_2,      CC_gfplus,     wrong_no_2},
    {"::quotient",              too_few_2,      CC_TTquotient, wrong_no_2},
    {"toolongexpp",             CC_toolongexpp, too_many_1,    wrong_no_1},
    {"collectphysops_reversed", too_few_2,      CC_collectphysops_reversed,wrong_no_2},
    {"mk-numr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKnumr},
    {"quotodd",                 too_few_2,      CC_quotodd,    wrong_no_2},
    {"red_tailreddriver",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_tailreddriver},
    {"simp-prop2",              CC_simpKprop2,  too_many_1,    wrong_no_1},
    {"getavalue",               CC_getavalue,   too_many_1,    wrong_no_1},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"reduce-eival-powers",     too_few_2,      CC_reduceKeivalKpowers,wrong_no_2},
    {"mk+outer+list",           CC_mkLouterLlist,too_many_1,   wrong_no_1},
    {"pasf_sisub-gand",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sisubKgand},
    {"dip_fmon",                too_few_2,      CC_dip_fmon,   wrong_no_2},
    {"setfuncsnaryrd",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_setfuncsnaryrd},
    {"amatch",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_amatch},
    {"vdp2a",                   CC_vdp2a,       too_many_1,    wrong_no_1},
    {"inprinla",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprinla},
    {"simp-prop-condense",      CC_simpKpropKcondense,too_many_1,wrong_no_1},
    {"lambda_mka0p5_6",         too_few_2,      CC_lambda_mka0p5_6,wrong_no_2},
    {"cl_sitheo",               CC_cl_sitheo,   too_many_1,    wrong_no_1},
    {"listeval0",               CC_listeval0,   too_many_1,    wrong_no_1},
    {"tayexp-max2",             too_few_2,      CC_tayexpKmax2,wrong_no_2},
    {"my+nullsq+p",             CC_myLnullsqLp, too_many_1,    wrong_no_1},
    {"cl_susicpknowl",          CC_cl_susicpknowl,too_many_1,  wrong_no_1},
    {"aex_subrp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrp},
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"prlist",                  CC_prlist,      too_many_1,    wrong_no_1},
    {"mkmatrix",                too_few_2,      CC_mkmatrix,   wrong_no_2},
    {"contr2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_contr2},
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u28", (two_args *)"19160 5952640 7206395", 0}
};

/* end of generated code */