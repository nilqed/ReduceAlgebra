
/* $destdir\u05.c        Machine generated C code */

/* Signature: 00000000 23-Oct-2012 */

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


/* Code for fs!:plus */

static Lisp_Object CC_fsTplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0057, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:plus");
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

v0059:
    v0056 = stack[-1];
    if (v0056 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0056 = stack[-2];
    if (v0056 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0057 = stack[-2];
    v0056 = (Lisp_Object)17; /* 1 */
    v0058 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0057 = stack[-1];
    v0056 = (Lisp_Object)17; /* 1 */
    v0056 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    if (equal(v0058, v0056)) goto v0060;
    v0056 = qvalue(elt(env, 1)); /* nil */
    goto v0061;

v0061:
    if (v0056 == nil) goto v0062;
    v0057 = stack[-2];
    v0056 = (Lisp_Object)1; /* 0 */
    v0058 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0057 = stack[-1];
    v0056 = (Lisp_Object)1; /* 0 */
    v0056 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    fn = elt(env, 2); /* addsq */
    v0056 = (*qfn2(fn))(qenv(fn), v0058, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-4];
    v0057 = v0056;
    v0057 = qcar(v0057);
    if (v0057 == nil) goto v0064;
    v0058 = stack[-2];
    v0057 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0058 + (CELL-TAG_VECTOR) + ((int32_t)v0057/(16/CELL))) = v0056;
    stack[-3] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0057 = stack[-2];
    v0056 = (Lisp_Object)49; /* 3 */
    v0058 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0057 = stack[-1];
    v0056 = (Lisp_Object)49; /* 3 */
    v0056 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0056 = CC_fsTplus(env, v0058, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0056;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v0064:
    v0057 = stack[-2];
    v0056 = (Lisp_Object)49; /* 3 */
    v0058 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0057 = stack[-1];
    v0056 = (Lisp_Object)49; /* 3 */
    v0056 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    stack[-2] = v0058;
    stack[-1] = v0056;
    goto v0059;

v0062:
    v0057 = stack[-2];
    v0056 = stack[-1];
    fn = elt(env, 3); /* fs!:angle!-order */
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-4];
    if (v0056 == nil) goto v0065;
    stack[-3] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0057 = stack[-2];
    v0056 = (Lisp_Object)49; /* 3 */
    v0057 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0056 = stack[-1];
    v0056 = CC_fsTplus(env, v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0056;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v0065:
    stack[-3] = stack[-1];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0057 = stack[-1];
    v0056 = (Lisp_Object)49; /* 3 */
    v0057 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0056 = stack[-2];
    v0056 = CC_fsTplus(env, v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0056;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v0060:
    v0057 = stack[-2];
    v0056 = (Lisp_Object)33; /* 2 */
    v0058 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    v0057 = stack[-1];
    v0056 = (Lisp_Object)33; /* 2 */
    v0056 = *(Lisp_Object *)((char *)v0057 + (CELL-TAG_VECTOR) + ((int32_t)v0056/(16/CELL)));
    fn = elt(env, 4); /* angles!-equal */
    v0056 = (*qfn2(fn))(qenv(fn), v0058, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-4];
    goto v0061;
/* error exit handlers */
v0063:
    popv(5);
    return nil;
}



/* Code for mo!=shorten */

static Lisp_Object CC_moMshorten(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0069;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=shorten");
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
    v0044 = v0000;
/* end of prologue */
    v0044 = Lreverse(nil, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    stack[0] = v0044;
    goto v0071;

v0071:
    v0044 = stack[0];
    if (v0044 == nil) goto v0072;
    v0044 = stack[0];
    v0069 = qcar(v0044);
    v0044 = (Lisp_Object)1; /* 0 */
    v0044 = Leqn(nil, v0069, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    if (v0044 == nil) goto v0072;
    v0044 = stack[0];
    v0044 = qcdr(v0044);
    stack[0] = v0044;
    goto v0071;

v0072:
    v0044 = stack[0];
        popv(2);
        return Lnreverse(nil, v0044);
/* error exit handlers */
v0070:
    popv(2);
    return nil;
}



/* Code for unpkp */

static Lisp_Object CC_unpkp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0027, v0029;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unpkp");
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
    v0089 = stack[-1];
    if (!(!consp(v0089))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0089 = stack[-1];
    v0089 = Lexplode(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    stack[-1] = v0089;
    v0089 = stack[-1];
    v0027 = Llength(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0089 = (Lisp_Object)161; /* 10 */
    v0089 = (Lisp_Object)geq2(v0027, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0089 = v0089 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v0089;
    v0089 = stack[0];
    if (v0089 == nil) goto v0091;
    v0089 = stack[-1];
    v0089 = Llength(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0089 = Levenp(nil, v0089);
    env = stack[-3];
    if (!(v0089 == nil)) goto v0091;
    v0027 = elt(env, 1); /* !0 */
    v0089 = stack[-1];
    v0089 = cons(v0027, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    stack[-1] = v0089;
    goto v0091;

v0091:
    v0089 = stack[-1];
    if (v0089 == nil) goto v0092;
    v0089 = stack[0];
    if (v0089 == nil) goto v0055;
    v0089 = stack[-1];
    v0027 = qcar(v0089);
    v0089 = qvalue(elt(env, 3)); /* diglist!* */
    v0089 = Lassoc(nil, v0027, v0089);
    v0089 = qcdr(v0089);
    v0027 = v0089;
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    v0089 = (Lisp_Object)161; /* 10 */
    v0029 = times2(v0027, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0089 = stack[-1];
    v0027 = qcar(v0089);
    v0089 = qvalue(elt(env, 3)); /* diglist!* */
    v0089 = Lassoc(nil, v0027, v0089);
    v0089 = qcdr(v0089);
    v0027 = plus2(v0029, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0089 = stack[-2];
    v0089 = cons(v0027, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    stack[-2] = v0089;
    goto v0043;

v0043:
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    goto v0091;

v0055:
    v0089 = stack[-1];
    v0027 = qcar(v0089);
    v0089 = qvalue(elt(env, 3)); /* diglist!* */
    v0089 = Lassoc(nil, v0027, v0089);
    v0027 = qcdr(v0089);
    v0089 = stack[-2];
    v0089 = cons(v0027, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    stack[-2] = v0089;
    goto v0043;

v0092:
    v0089 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0089);
/* error exit handlers */
v0090:
    popv(4);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modplus:");
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
    v0095 = v0001;
    v0037 = v0000;
/* end of prologue */
    v0037 = qcdr(v0037);
    v0095 = qcdr(v0095);
    fn = elt(env, 1); /* general!-modular!-plus */
    v0095 = (*qfn2(fn))(qenv(fn), v0037, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0095);
    }
/* error exit handlers */
v0061:
    popv(1);
    return nil;
}



/* Code for gen!-mult!-by!-const!-mod!-p */

static Lisp_Object CC_genKmultKbyKconstKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen-mult-by-const-mod-p");
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
    v0101 = stack[-2];
    if (v0101 == nil) goto v0103;
    v0102 = stack[-1];
    v0101 = (Lisp_Object)17; /* 1 */
    if (v0102 == v0101) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0101 = stack[-2];
    if (!consp(v0101)) goto v0088;
    v0101 = stack[-2];
    v0101 = qcar(v0101);
    v0101 = (consp(v0101) ? nil : lisp_true);
    goto v0104;

v0104:
    if (v0101 == nil) goto v0105;
    v0102 = stack[-2];
    v0101 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0102 = v0101;
    v0101 = v0102;
    v0101 = (Lisp_Object)zerop(v0101);
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-4];
    if (v0101 == nil) { popv(5); return onevalue(v0102); }
    v0101 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0101); }

v0105:
    v0101 = stack[-2];
    v0101 = qcar(v0101);
    stack[-3] = qcar(v0101);
    v0101 = stack[-2];
    v0101 = qcar(v0101);
    v0102 = qcdr(v0101);
    v0101 = stack[-1];
    stack[0] = CC_genKmultKbyKconstKmodKp(env, v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0101 = stack[-2];
    v0102 = qcdr(v0101);
    v0101 = stack[-1];
    v0101 = CC_genKmultKbyKconstKmodKp(env, v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    {
        Lisp_Object v0106 = stack[-3];
        Lisp_Object v0107 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0106, v0107, v0101);
    }

v0088:
    v0101 = qvalue(elt(env, 2)); /* t */
    goto v0104;

v0103:
    v0101 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0101); }
/* error exit handlers */
v0032:
    popv(5);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0068, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0068,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0068;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = stack[-1];
    v0116 = stack[-2];
    v0116 = qcdr(v0116);
    v0116 = qcar(v0116);
    v0116 = Labsval(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0116 = add1(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0116 = plus2(stack[0], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v0116 = (*qfn2(fn))(qenv(fn), stack[-3], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    stack[-3] = v0116;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0116 = stack[-3];
    v0116 = qcdr(v0116);
    v0117 = qcar(v0116);
    v0116 = stack[-2];
    v0116 = qcdr(v0116);
    v0116 = qcar(v0116);
    stack[0] = quot2(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0116 = stack[-3];
    v0116 = qcdr(v0116);
    v0117 = qcdr(v0116);
    v0116 = stack[-2];
    v0116 = qcdr(v0116);
    v0116 = qcdr(v0116);
    v0116 = difference2(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0116 = list2star(stack[-4], stack[0], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    stack[-3] = v0116;
    v0117 = stack[-3];
    v0116 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0117, v0116);
    }
/* error exit handlers */
v0075:
    popv(6);
    return nil;
}



/* Code for procstat */

static Lisp_Object MS_CDECL CC_procstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "procstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for procstat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0084 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* procstat1 */
        return (*qfn1(fn))(qenv(fn), v0084);
    }
}



/* Code for qqe_id!-nyt!-branchb */

static Lisp_Object CC_qqe_idKnytKbranchb(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchb");
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
    v0118 = stack[0];
    if (!consp(v0118)) goto v0081;
    v0118 = stack[0];
    v0118 = qcar(v0118);
    fn = elt(env, 1); /* qqe_qopaddp */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-1];
    if (!(v0118 == nil)) goto v0100;
    v0118 = stack[0];
    v0118 = qcar(v0118);
    fn = elt(env, 2); /* qqe_qoptailp */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    goto v0100;

v0100:
    v0118 = (v0118 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0118); }

v0081:
    v0118 = stack[0];
    fn = elt(env, 3); /* qqe_btidp */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-1];
    if (!(v0118 == nil)) { popv(2); return onevalue(v0118); }
    v0118 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* qqe_nytidp */
        return (*qfn1(fn))(qenv(fn), v0118);
    }
/* error exit handlers */
v0119:
    popv(2);
    return nil;
}



/* Code for pasf_dec */

static Lisp_Object CC_pasf_dec(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dec");
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
    v0091 = v0000;
/* end of prologue */
    v0092 = v0091;
    stack[-1] = v0092;
    goto v0072;

v0072:
    v0092 = stack[-1];
    if (!consp(v0092)) goto v0037;
    v0092 = stack[-1];
    v0092 = qcar(v0092);
    v0092 = (consp(v0092) ? nil : lisp_true);
    goto v0095;

v0095:
    if (v0092 == nil) goto v0122;
    stack[0] = v0091;
    v0092 = stack[-1];
    fn = elt(env, 3); /* negf */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    fn = elt(env, 4); /* addf */
    v0091 = (*qfn2(fn))(qenv(fn), stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0092 = stack[-1];
    popv(3);
    return cons(v0091, v0092);

v0122:
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    stack[-1] = v0092;
    goto v0072;

v0037:
    v0092 = qvalue(elt(env, 1)); /* t */
    goto v0095;
/* error exit handlers */
v0110:
    popv(3);
    return nil;
}



/* Code for ibalp_getupl */

static Lisp_Object CC_ibalp_getupl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getupl");
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
    v0125 = v0000;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v0125;
    goto v0072;

v0072:
    v0125 = stack[-1];
    if (v0125 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0125 = stack[-1];
    v0125 = qcar(v0125);
    stack[0] = v0125;
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    v0125 = qcdr(v0125);
    v0125 = qcdr(v0125);
    v0125 = qcdr(v0125);
    v0125 = qcar(v0125);
    if (v0125 == nil) goto v0085;
    v0125 = qvalue(elt(env, 1)); /* nil */
    goto v0066;

v0066:
    if (v0125 == nil) goto v0115;
    v0126 = stack[0];
    v0125 = stack[-2];
    v0125 = cons(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-3];
    stack[-2] = v0125;
    goto v0115;

v0115:
    v0125 = stack[-1];
    v0125 = qcdr(v0125);
    stack[-1] = v0125;
    goto v0072;

v0085:
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    v0125 = qcdr(v0125);
    v0126 = qcar(v0125);
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    v0125 = qcdr(v0125);
    v0125 = qcdr(v0125);
    v0125 = qcar(v0125);
    v0126 = plus2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-3];
    v0125 = (Lisp_Object)17; /* 1 */
    v0125 = Leqn(nil, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-3];
    goto v0066;
/* error exit handlers */
v0075:
    popv(4);
    return nil;
}



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    v0123 = v0001;
    v0114 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v0123 = list2(v0114, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    {
        Lisp_Object v0104 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0104, v0123);
    }
/* error exit handlers */
v0087:
    popv(2);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0068)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0068,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0068;
    v0127 = v0001;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v0127; /* ps */
    v0112 = qvalue(elt(env, 1)); /* ps */
    v0127 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v0127 = (*qfn2(fn))(qenv(fn), v0112, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    stack[-1] = v0127;
    v0127 = stack[-1];
    if (v0127 == nil) goto v0115;
    v0127 = stack[-1];
    goto v0128;

v0128:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v0127); }

v0115:
    v0127 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v0127 = (*qfn1(fn))(qenv(fn), v0127);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    v0127 = add1(v0127);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    stack[0] = v0127;
    goto v0047;

v0047:
    v0112 = stack[-2];
    v0127 = stack[0];
    v0127 = difference2(v0112, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    v0127 = Lminusp(nil, v0127);
    env = stack[-4];
    if (v0127 == nil) goto v0110;
    v0127 = stack[-1];
    goto v0128;

v0110:
    v0112 = qvalue(elt(env, 1)); /* ps */
    v0127 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v0127 = (*qfn2(fn))(qenv(fn), v0112, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    stack[-1] = v0127;
    v0127 = stack[0];
    v0127 = add1(v0127);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    stack[0] = v0127;
    goto v0047;
/* error exit handlers */
v0083:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126, v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_timbf");
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
    v0125 = stack[-3];
    v0125 = qcdr(v0125);
    v0126 = qcar(v0125);
    v0125 = stack[-2];
    v0125 = qcdr(v0125);
    v0125 = qcar(v0125);
    v0125 = times2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    v0133 = v0125;
    v0126 = v0133;
    v0125 = (Lisp_Object)1; /* 0 */
    if (v0126 == v0125) goto v0115;
    v0126 = v0133;
    v0125 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v0125 = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    v0133 = v0125;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v0125 = v0133;
    stack[-1] = qcar(v0125);
    v0125 = v0133;
    stack[0] = qcdr(v0125);
    v0125 = stack[-3];
    v0125 = qcdr(v0125);
    v0126 = qcdr(v0125);
    v0125 = stack[-2];
    v0125 = qcdr(v0125);
    v0125 = qcdr(v0125);
    v0125 = plus2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    v0125 = plus2(stack[0], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    {
        Lisp_Object v0135 = stack[-4];
        Lisp_Object v0035 = stack[-1];
        popv(6);
        return list2star(v0135, v0035, v0125);
    }

v0115:
    v0125 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v0125); }
/* error exit handlers */
v0134:
    popv(6);
    return nil;
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0068, Lisp_Object v0084, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147, v0148, v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convertmode1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0084,v0068,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0068,v0084);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0147 = v0084;
    stack[0] = v0068;
    stack[-1] = v0001;
    v0148 = v0000;
/* end of prologue */

v0113:
    v0149 = v0147;
    v0146 = elt(env, 1); /* real */
    if (!(v0149 == v0146)) goto v0066;
    v0146 = elt(env, 2); /* algebraic */
    v0147 = v0146;
    goto v0066;

v0066:
    v0149 = stack[0];
    v0146 = elt(env, 1); /* real */
    if (!(v0149 == v0146)) goto v0131;
    v0146 = elt(env, 2); /* algebraic */
    stack[0] = v0146;
    goto v0131;

v0131:
    v0149 = stack[0];
    v0146 = v0147;
    if (v0149 == v0146) { popv(4); return onevalue(v0148); }
    v0146 = v0148;
    if (!(symbolp(v0146))) goto v0074;
    v0149 = v0148;
    v0146 = stack[-1];
    v0146 = Latsoc(nil, v0149, v0146);
    stack[-2] = v0146;
    if (v0146 == nil) goto v0074;
    v0146 = stack[-2];
    v0149 = qcdr(v0146);
    v0146 = elt(env, 3); /* (integer scalar real) */
    v0146 = Lmemq(nil, v0149, v0146);
    if (v0146 == nil) goto v0098;
    v0146 = qvalue(elt(env, 4)); /* nil */
    goto v0041;

v0041:
    if (v0146 == nil) goto v0074;
    v0147 = stack[-1];
    v0146 = stack[-2];
    v0146 = qcdr(v0146);
    fn = elt(env, 5); /* form1 */
    v0148 = (*qfnn(fn))(qenv(fn), 3, v0148, v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0149 = stack[-1];
    v0147 = stack[0];
    v0146 = stack[-2];
    v0146 = qcdr(v0146);
    stack[-1] = v0149;
    stack[0] = v0147;
    v0147 = v0146;
    goto v0113;

v0074:
    v0149 = v0147;
    v0146 = stack[0];
    v0146 = get(v0149, v0146);
    env = stack[-3];
    stack[-2] = v0146;
    if (v0146 == nil) goto v0089;
    v0147 = stack[-2];
    v0146 = stack[-1];
        popv(4);
        return Lapply2(nil, 3, v0147, v0148, v0146);

v0089:
    v0146 = stack[0];
    fn = elt(env, 6); /* typerr */
    v0146 = (*qfn2(fn))(qenv(fn), v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0146 = nil;
    { popv(4); return onevalue(v0146); }

v0098:
    v0146 = stack[-2];
    v0149 = qcdr(v0146);
    v0146 = v0147;
    v0146 = (v0149 == v0146 ? lisp_true : nil);
    v0146 = (v0146 == nil ? lisp_true : nil);
    goto v0041;
/* error exit handlers */
v0026:
    popv(4);
    return nil;
}



/* Code for simpminus */

static Lisp_Object CC_simpminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpminus");
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
    v0088 = v0000;
/* end of prologue */
    v0066 = v0088;
    v0088 = elt(env, 1); /* minus */
    fn = elt(env, 2); /* carx */
    v0088 = (*qfn2(fn))(qenv(fn), v0066, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    fn = elt(env, 3); /* simp */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    stack[0] = v0088;
    v0088 = stack[0];
    v0088 = qcar(v0088);
    fn = elt(env, 4); /* negf */
    v0066 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    popv(2);
    return cons(v0066, v0088);
/* error exit handlers */
v0118:
    popv(2);
    return nil;
}



/* Code for fs!:timestermterm */

static Lisp_Object CC_fsTtimestermterm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0208, v0209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:timestermterm");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0001;
    stack[-7] = v0000;
/* end of prologue */
    v0207 = (Lisp_Object)113; /* 7 */
    v0207 = Lmkvect(nil, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-8] = v0207;
    v0208 = stack[-7];
    v0207 = (Lisp_Object)33; /* 2 */
    v0207 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    stack[-4] = v0207;
    v0208 = stack[-6];
    v0207 = (Lisp_Object)33; /* 2 */
    v0207 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    stack[-3] = v0207;
    v0207 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0207;
    goto v0085;

v0085:
    v0208 = (Lisp_Object)113; /* 7 */
    v0207 = stack[-2];
    v0207 = difference2(v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0207 = Lminusp(nil, v0207);
    env = stack[-9];
    if (v0207 == nil) goto v0124;
    v0207 = (Lisp_Object)113; /* 7 */
    v0207 = Lmkvect(nil, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-5] = v0207;
    v0207 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0207;
    goto v0078;

v0078:
    v0208 = (Lisp_Object)113; /* 7 */
    v0207 = stack[-2];
    v0207 = difference2(v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0207 = Lminusp(nil, v0207);
    env = stack[-9];
    if (v0207 == nil) goto v0064;
    v0208 = stack[-7];
    v0207 = (Lisp_Object)1; /* 0 */
    v0209 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0208 = stack[-6];
    v0207 = (Lisp_Object)1; /* 0 */
    v0207 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    fn = elt(env, 5); /* multsq */
    v0207 = (*qfn2(fn))(qenv(fn), v0209, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[0] = v0207;
    v0208 = stack[0];
    v0207 = elt(env, 2); /* (1 . 2) */
    fn = elt(env, 5); /* multsq */
    v0207 = (*qfn2(fn))(qenv(fn), v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[0] = v0207;
    v0207 = stack[0];
    v0207 = qcar(v0207);
    if (v0207 == nil) goto v0211;
    v0208 = stack[-7];
    v0207 = (Lisp_Object)17; /* 1 */
    v0208 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0207 = elt(env, 3); /* sin */
    if (v0208 == v0207) goto v0212;
    v0208 = stack[-6];
    v0207 = (Lisp_Object)17; /* 1 */
    v0208 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0207 = elt(env, 3); /* sin */
    if (v0208 == v0207) goto v0213;
    v0209 = elt(env, 4); /* cos */
    v0208 = stack[-8];
    v0207 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0209, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0209 = elt(env, 4); /* cos */
    v0208 = stack[-5];
    v0207 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v0207 = (*qfnn(fn))(qenv(fn), 3, v0209, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    {
        Lisp_Object v0214 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0214, v0207);
    }

v0213:
    v0209 = elt(env, 3); /* sin */
    v0208 = stack[-8];
    v0207 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0209, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-1] = elt(env, 3); /* sin */
    stack[-3] = stack[-5];
    v0207 = stack[0];
    v0207 = qcar(v0207);
    fn = elt(env, 8); /* negf */
    v0208 = (*qfn1(fn))(qenv(fn), v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0207 = stack[0];
    v0207 = qcdr(v0207);
    v0207 = cons(v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    v0207 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-3], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    {
        Lisp_Object v0215 = stack[-2];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0215, v0207);
    }

v0212:
    v0208 = stack[-6];
    v0207 = (Lisp_Object)17; /* 1 */
    v0208 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0207 = elt(env, 3); /* sin */
    if (v0208 == v0207) goto v0216;
    v0209 = elt(env, 3); /* sin */
    v0208 = stack[-8];
    v0207 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0209, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0209 = elt(env, 3); /* sin */
    v0208 = stack[-5];
    v0207 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v0207 = (*qfnn(fn))(qenv(fn), 3, v0209, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    {
        Lisp_Object v0217 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0217, v0207);
    }

v0216:
    stack[-1] = elt(env, 4); /* cos */
    stack[-2] = stack[-8];
    v0207 = stack[0];
    v0207 = qcar(v0207);
    fn = elt(env, 8); /* negf */
    v0208 = (*qfn1(fn))(qenv(fn), v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0207 = stack[0];
    v0207 = qcdr(v0207);
    v0207 = cons(v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0209 = elt(env, 4); /* cos */
    v0208 = stack[-5];
    v0207 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v0207 = (*qfnn(fn))(qenv(fn), 3, v0209, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    {
        Lisp_Object v0218 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0218, v0207);
    }

v0211:
    v0207 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0207); }

v0064:
    stack[-1] = stack[-5];
    stack[0] = stack[-2];
    v0208 = stack[-4];
    v0207 = stack[-2];
    v0209 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0208 = stack[-3];
    v0207 = stack[-2];
    v0207 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0207 = difference2(v0209, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0207;
    v0207 = stack[-2];
    v0207 = add1(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-2] = v0207;
    goto v0078;

v0124:
    stack[-1] = stack[-8];
    stack[0] = stack[-2];
    v0208 = stack[-4];
    v0207 = stack[-2];
    v0209 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0208 = stack[-3];
    v0207 = stack[-2];
    v0207 = *(Lisp_Object *)((char *)v0208 + (CELL-TAG_VECTOR) + ((int32_t)v0207/(16/CELL)));
    v0207 = plus2(v0209, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0207;
    v0207 = stack[-2];
    v0207 = add1(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-2] = v0207;
    goto v0085;
/* error exit handlers */
v0210:
    popv(10);
    return nil;
}



/* Code for mo_sum */

static Lisp_Object CC_mo_sum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_sum");
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
    v0066 = v0001;
    v0067 = v0000;
/* end of prologue */
    v0067 = qcar(v0067);
    v0066 = qcar(v0066);
    fn = elt(env, 1); /* mo!=sum */
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    stack[-1] = v0066;
    v0066 = stack[-1];
    fn = elt(env, 2); /* mo!=shorten */
    stack[0] = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    v0066 = stack[-1];
    fn = elt(env, 3); /* mo!=deglist */
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    {
        Lisp_Object v0048 = stack[0];
        popv(3);
        return cons(v0048, v0066);
    }
/* error exit handlers */
v0119:
    popv(3);
    return nil;
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0061, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf*");
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
    v0061 = v0001;
    v0100 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v0037 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0037; /* !*gcd */
    v0037 = v0100;
    fn = elt(env, 3); /* gcdf */
    v0037 = (*qfn2(fn))(qenv(fn), v0037, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0037); }
/* error exit handlers */
v0114:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for prin2!* */

static Lisp_Object CC_prin2H(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0184, v0182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2*");
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
    v0229 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v0229 == nil) goto v0070;
    v0184 = qvalue(elt(env, 1)); /* outputhandler!* */
    v0182 = elt(env, 0); /* prin2!* */
    v0229 = stack[-2];
        popv(5);
        return Lapply2(nil, 3, v0184, v0182, v0229);

v0070:
    v0184 = stack[-2];
    v0229 = elt(env, 2); /* oldnam */
    v0229 = get(v0184, v0229);
    env = stack[-4];
    v0184 = v0229;
    if (v0229 == nil) goto v0049;
    v0229 = v0184;
    stack[-2] = v0229;
    goto v0049;

v0049:
    v0229 = qvalue(elt(env, 3)); /* overflowed!* */
    if (v0229 == nil) goto v0206;
    v0229 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v0229); }

v0206:
    v0229 = qvalue(elt(env, 5)); /* !*fort */
    if (v0229 == nil) goto v0129;
    v0229 = stack[-2];
    {
        popv(5);
        fn = elt(env, 18); /* fprin2!* */
        return (*qfn1(fn))(qenv(fn), v0229);
    }

v0129:
    v0229 = qvalue(elt(env, 6)); /* !*nat */
    if (v0229 == nil) goto v0092;
    v0184 = stack[-2];
    v0229 = elt(env, 7); /* pi */
    if (v0184 == v0229) goto v0112;
    v0184 = stack[-2];
    v0229 = elt(env, 9); /* infinity */
    if (!(v0184 == v0229)) goto v0092;
    v0229 = elt(env, 9); /* infinity */
    fn = elt(env, 19); /* symbol */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    stack[-2] = v0229;
    goto v0092;

v0092:
    v0229 = stack[-2];
    v0229 = Llengthc(nil, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    stack[-1] = v0229;
    v0229 = stack[-2];
    v0229 = integerp(v0229);
    if (v0229 == nil) goto v0026;
    v0184 = stack[-1];
    v0229 = (Lisp_Object)801; /* 50 */
    v0229 = (Lisp_Object)greaterp2(v0184, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0229 = v0229 ? lisp_true : nil;
    env = stack[-4];
    if (v0229 == nil) goto v0026;
    v0229 = qvalue(elt(env, 10)); /* !*rounded */
    if (v0229 == nil) goto v0026;
    v0229 = stack[-2];
    fn = elt(env, 20); /* chkint!* */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    v0184 = v0229;
    if (!(!consp(v0184))) goto v0231;
    v0184 = elt(env, 11); /* !:rd!: */
    v0229 = cons(v0184, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    goto v0231;

v0231:
    v0184 = v0229;
    v0229 = v0184;
    v0229 = qcdr(v0229);
    if (!consp(v0229)) goto v0199;
    v0229 = v0184;
    stack[0] = v0229;
    goto v0146;

v0146:
    v0184 = qvalue(elt(env, 12)); /* !:bprec!: */
    v0229 = (Lisp_Object)49; /* 3 */
    v0229 = difference2(v0184, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    fn = elt(env, 21); /* round!:mt */
    v0229 = (*qfn2(fn))(qenv(fn), stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    fn = elt(env, 22); /* csl_normbf */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 23); /* bfprin0 */
        return (*qfn1(fn))(qenv(fn), v0229);
    }

v0199:
    v0229 = v0184;
    v0229 = qcdr(v0229);
    fn = elt(env, 24); /* fl2bf */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    stack[0] = v0229;
    goto v0146;

v0026:
    v0184 = qvalue(elt(env, 13)); /* posn!* */
    v0229 = stack[-1];
    v0229 = (Lisp_Object)(int32_t)((int32_t)v0184 + (int32_t)v0229 - TAG_FIXNUM);
    stack[-3] = v0229;
    v0229 = qvalue(elt(env, 14)); /* nil */
    v0184 = Llinelength(nil, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    v0229 = qvalue(elt(env, 15)); /* spare!* */
    v0229 = difference2(v0184, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    stack[0] = v0229;
    v0184 = stack[-3];
    v0229 = stack[0];
    v0229 = (Lisp_Object)lesseq2(v0184, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0229 = v0229 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0229 == nil)) goto v0216;
    v0229 = qvalue(elt(env, 16)); /* testing!-width!* */
    if (v0229 == nil) goto v0232;
    v0229 = qvalue(elt(env, 14)); /* nil */
    goto v0233;

v0233:
    if (!(v0229 == nil)) goto v0216;
    v0229 = qvalue(elt(env, 16)); /* testing!-width!* */
    if (v0229 == nil) goto v0185;
    v0229 = qvalue(elt(env, 17)); /* t */
    qvalue(elt(env, 3)) = v0229; /* overflowed!* */
    v0229 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v0229); }

v0185:
    v0182 = stack[-2];
    v0229 = qvalue(elt(env, 13)); /* posn!* */
    v0184 = (Lisp_Object)((int32_t)(v0229) + 0x10);
    v0229 = stack[0];
    v0229 = (Lisp_Object)((int32_t)(v0229) - 0x10);
    {
        popv(5);
        fn = elt(env, 25); /* prin2lint */
        return (*qfnn(fn))(qenv(fn), 3, v0182, v0184, v0229);
    }

v0216:
    v0184 = stack[-2];
    v0229 = stack[-3];
    {
        popv(5);
        fn = elt(env, 26); /* add_prin_char */
        return (*qfn2(fn))(qenv(fn), v0184, v0229);
    }

v0232:
    v0229 = stack[-2];
    v0229 = integerp(v0229);
    if (!(v0229 == nil)) goto v0234;
    v0229 = qvalue(elt(env, 17)); /* t */
    fn = elt(env, 27); /* terpri!* */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    goto v0234;

v0234:
    v0184 = qvalue(elt(env, 13)); /* posn!* */
    v0229 = stack[-1];
    v0184 = (Lisp_Object)(int32_t)((int32_t)v0184 + (int32_t)v0229 - TAG_FIXNUM);
    stack[-3] = v0184;
    v0229 = stack[0];
    v0229 = (Lisp_Object)lesseq2(v0184, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0229 = v0229 ? lisp_true : nil;
    env = stack[-4];
    goto v0233;

v0112:
    v0229 = elt(env, 8); /* !.pi */
    fn = elt(env, 19); /* symbol */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    stack[-2] = v0229;
    goto v0092;
/* error exit handlers */
v0230:
    popv(5);
    return nil;
}



/* Code for insert_pv */

static Lisp_Object CC_insert_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0121, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv");
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
    v0069 = v0000;
/* end of prologue */
    v0121 = v0069;
    v0069 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v0069 = (*qfn2(fn))(qenv(fn), v0121, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0121 = v0069;
    v0069 = v0121;
    if (v0069 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0069 = v0121;
    fn = elt(env, 3); /* pv_renorm */
    v0070 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0121 = stack[0];
    v0069 = qvalue(elt(env, 1)); /* nil */
    {
        popv(2);
        fn = elt(env, 4); /* insert_pv1 */
        return (*qfnn(fn))(qenv(fn), 3, v0070, v0121, v0069);
    }
/* error exit handlers */
v0131:
    popv(2);
    return nil;
}



/* Code for rntimes!: */

static Lisp_Object CC_rntimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rntimes:");
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
    v0121 = qcdr(v0121);
    v0070 = qcar(v0121);
    v0121 = stack[0];
    v0121 = qcdr(v0121);
    v0121 = qcar(v0121);
    stack[-2] = times2(v0070, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    v0121 = stack[-1];
    v0121 = qcdr(v0121);
    v0070 = qcdr(v0121);
    v0121 = stack[0];
    v0121 = qcdr(v0121);
    v0121 = qcdr(v0121);
    v0121 = times2(v0070, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    {
        Lisp_Object v0045 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0045, v0121);
    }
/* error exit handlers */
v0047:
    popv(4);
    return nil;
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0085, v0086, v0120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0085 = v0001;
    v0086 = v0000;
/* end of prologue */

v0103:
    v0045 = v0086;
    if (v0045 == nil) goto v0072;
    v0045 = v0086;
    v0120 = qcar(v0045);
    v0045 = v0085;
    v0045 = qcar(v0045);
    if (equal(v0120, v0045)) goto v0113;
    v0045 = v0086;
    v0045 = qcar(v0045);
    v0085 = qcar(v0085);
    {
        fn = elt(env, 2); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v0045, v0085);
    }

v0113:
    v0045 = v0086;
    v0045 = qcdr(v0045);
    v0086 = v0045;
    v0045 = v0085;
    v0045 = qcdr(v0045);
    v0085 = v0045;
    goto v0103;

v0072:
    v0045 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0045);
}



/* Code for !*i2gi */

static Lisp_Object CC_Hi2gi(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0095, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2gi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0094 = v0000;
/* end of prologue */
    v0037 = elt(env, 1); /* !:gi!: */
    v0095 = v0094;
    v0094 = (Lisp_Object)1; /* 0 */
    return list2star(v0037, v0095, v0094);
}



/* Code for xread */

static Lisp_Object CC_xread(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xread");
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

v0081:
    fn = elt(env, 4); /* scan */
    v0104 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0104 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v0104 == nil) goto v0200;
    v0088 = qvalue(elt(env, 2)); /* cursym!* */
    v0104 = elt(env, 3); /* !*semicol!* */
    if (v0088 == v0104) goto v0081;
    else goto v0200;

v0200:
    v0104 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v0104);
    }
/* error exit handlers */
v0067:
    popv(2);
    return nil;
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raddf");
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
    goto v0128;

v0128:
    v0240 = stack[-2];
    if (v0240 == nil) goto v0094;
    v0240 = stack[-1];
    if (v0240 == nil) goto v0066;
    v0240 = stack[-2];
    if (!consp(v0240)) goto v0109;
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    v0240 = (consp(v0240) ? nil : lisp_true);
    goto v0070;

v0070:
    if (v0240 == nil) goto v0069;
    stack[0] = stack[-3];
    v0211 = stack[-2];
    v0240 = stack[-1];
    fn = elt(env, 2); /* addd */
    v0240 = (*qfn2(fn))(qenv(fn), v0211, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    {
        Lisp_Object v0242 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0242, v0240);
    }

v0069:
    v0240 = stack[-1];
    if (!consp(v0240)) goto v0083;
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = (consp(v0240) ? nil : lisp_true);
    goto v0082;

v0082:
    if (v0240 == nil) goto v0032;
    stack[0] = stack[-3];
    v0211 = stack[-1];
    v0240 = stack[-2];
    fn = elt(env, 2); /* addd */
    v0240 = (*qfn2(fn))(qenv(fn), v0211, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    {
        Lisp_Object v0243 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0243, v0240);
    }

v0032:
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    v0211 = qcar(v0240);
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcar(v0240);
    if (equal(v0211, v0240)) goto v0244;
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    v0211 = qcar(v0240);
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcar(v0240);
    fn = elt(env, 4); /* ordpp */
    v0240 = (*qfn2(fn))(qenv(fn), v0211, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    if (v0240 == nil) goto v0023;
    v0240 = stack[-2];
    v0211 = qcar(v0240);
    v0240 = stack[-3];
    v0240 = cons(v0211, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    stack[-3] = v0240;
    v0240 = stack[-2];
    v0240 = qcdr(v0240);
    stack[-2] = v0240;
    goto v0128;

v0023:
    v0240 = stack[-1];
    v0211 = qcar(v0240);
    v0240 = stack[-3];
    v0240 = cons(v0211, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    stack[-3] = v0240;
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    stack[-1] = v0240;
    goto v0128;

v0244:
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    stack[0] = qcar(v0240);
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    v0211 = qcdr(v0240);
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcdr(v0240);
    v0211 = CC_raddf(env, v0211, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    v0240 = stack[-3];
    v0240 = acons(stack[0], v0211, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    stack[-3] = v0240;
    v0240 = stack[-2];
    v0240 = qcdr(v0240);
    stack[-2] = v0240;
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    stack[-1] = v0240;
    goto v0128;

v0083:
    v0240 = qvalue(elt(env, 1)); /* t */
    goto v0082;

v0109:
    v0240 = qvalue(elt(env, 1)); /* t */
    goto v0070;

v0066:
    v0211 = stack[-3];
    v0240 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0211, v0240);
    }

v0094:
    v0211 = stack[-3];
    v0240 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0211, v0240);
    }
/* error exit handlers */
v0241:
    popv(5);
    return nil;
}



/* Code for sfto_davp */

static Lisp_Object CC_sfto_davp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0231;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_davp");
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

v0128:
    v0142 = stack[-1];
    if (!consp(v0142)) goto v0094;
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = (consp(v0142) ? nil : lisp_true);
    goto v0113;

v0113:
    if (v0142 == nil) goto v0118;
    v0142 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0142); }

v0118:
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0231 = qcdr(v0142);
    v0142 = (Lisp_Object)33; /* 2 */
    v0142 = (Lisp_Object)greaterp2(v0231, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    v0142 = v0142 ? lisp_true : nil;
    env = stack[-2];
    if (v0142 == nil) goto v0106;
    v0142 = stack[0];
    if (v0142 == nil) goto v0039;
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0231 = qcar(v0142);
    v0142 = stack[0];
    if (equal(v0231, v0142)) goto v0039;
    v0142 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0142); }

v0039:
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0231 = qcdr(v0142);
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0142 = CC_sfto_davp(env, v0231, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    if (v0142 == nil) goto v0036;
    v0142 = stack[-1];
    v0142 = qcdr(v0142);
    v0231 = v0142;
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    stack[0] = v0142;
    v0142 = v0231;
    stack[-1] = v0142;
    goto v0128;

v0036:
    v0142 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0142); }

v0106:
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0231 = qcdr(v0142);
    v0142 = stack[0];
    v0142 = CC_sfto_davp(env, v0231, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    if (v0142 == nil) goto v0244;
    v0142 = stack[-1];
    v0142 = qcdr(v0142);
    stack[-1] = v0142;
    goto v0128;

v0244:
    v0142 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0142); }

v0094:
    v0142 = qvalue(elt(env, 1)); /* t */
    goto v0113;
/* error exit handlers */
v0055:
    popv(3);
    return nil;
}



/* Code for ibalp_minclnr */

static Lisp_Object CC_ibalp_minclnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075, v0245;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_minclnr");
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
    v0245 = v0000;
/* end of prologue */
    v0075 = (Lisp_Object)1600001; /* 100000 */
    stack[-2] = v0075;
    v0075 = v0245;
    stack[-1] = v0075;
    goto v0071;

v0071:
    v0075 = stack[-1];
    if (v0075 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0075 = stack[-1];
    v0075 = qcar(v0075);
    stack[0] = v0075;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcar(v0075);
    if (!(v0075 == nil)) goto v0087;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0245 = qcar(v0075);
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcar(v0075);
    v0245 = plus2(v0245, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0075 = stack[-2];
    v0075 = (Lisp_Object)lessp2(v0245, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    v0075 = v0075 ? lisp_true : nil;
    env = stack[-3];
    if (v0075 == nil) goto v0087;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0245 = qcar(v0075);
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcar(v0075);
    v0075 = plus2(v0245, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-2] = v0075;
    goto v0087;

v0087:
    v0075 = stack[-1];
    v0075 = qcdr(v0075);
    stack[-1] = v0075;
    goto v0071;
/* error exit handlers */
v0035:
    popv(4);
    return nil;
}



/* Code for omobj */

static Lisp_Object MS_CDECL CC_omobj(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobj");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobj");
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
    v0119 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 4); /* compress!* */
    v0048 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[0];
    v0119 = qvalue(elt(env, 2)); /* omfuncs!* */
    v0119 = Lassoc(nil, v0048, v0119);
    v0048 = v0119;
    if (v0119 == nil) goto v0128;
    v0119 = v0048;
    v0119 = qcdr(v0119);
    v0048 = qcar(v0119);
    v0119 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v0048, v0119);
    }

v0128:
    v0119 = nil;
    { popv(1); return onevalue(v0119); }
/* error exit handlers */
v0049:
    popv(1);
    return nil;
}



/* Code for find */

static Lisp_Object CC_find(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0206, v0060, v0110, v0124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0060 = v0001;
    v0110 = v0000;
/* end of prologue */

v0071:
    v0124 = v0060;
    v0206 = nil;
    if (v0124 == v0206) goto v0200;
    v0206 = v0060;
    v0206 = qcar(v0206);
    v0110 = Lmember(nil, v0206, v0110);
    v0206 = v0060;
    v0206 = qcdr(v0206);
    v0060 = v0206;
    goto v0071;

v0200:
    v0206 = v0110;
    if (v0206 == nil) goto v0088;
    v0206 = v0110;
    v0206 = qcdr(v0206);
    return onevalue(v0206);

v0088:
    v0206 = elt(env, 1); /* (stop) */
    return onevalue(v0206);
}



/* Code for sortcolelem */

static Lisp_Object MS_CDECL CC_sortcolelem(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0068, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0237;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sortcolelem");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0068,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0068;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0079 = stack[-2];
    v0079 = qcdr(v0079);
    stack[-4] = v0079;
    goto v0113;

v0113:
    v0079 = stack[0];
    if (v0079 == nil) goto v0095;
    v0079 = nil;
    { popv(6); return onevalue(v0079); }

v0095:
    v0079 = stack[-4];
    if (v0079 == nil) goto v0067;
    v0237 = stack[-3];
    v0079 = stack[-4];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0079 = (Lisp_Object)lessp2(v0237, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0079 = v0079 ? lisp_true : nil;
    env = stack[-5];
    if (v0079 == nil) goto v0036;
    stack[0] = stack[-2];
    v0237 = stack[-3];
    v0079 = stack[-1];
    v0079 = cons(v0237, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0237 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0079 = stack[-4];
    v0079 = Lrplacd(nil, v0237, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0079 = Lrplacd(nil, stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0079 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0079;
    goto v0113;

v0036:
    v0237 = stack[-3];
    v0079 = stack[-4];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0079 = (Lisp_Object)greaterp2(v0237, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0079 = v0079 ? lisp_true : nil;
    env = stack[-5];
    if (v0079 == nil) goto v0113;
    v0079 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0079;
    v0079 = stack[-2];
    v0079 = qcdr(v0079);
    stack[-2] = v0079;
    v0079 = stack[-2];
    v0079 = qcdr(v0079);
    stack[-4] = v0079;
    goto v0113;

v0067:
    stack[0] = stack[-2];
    v0237 = stack[-3];
    v0079 = stack[-1];
    v0079 = cons(v0237, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0079 = Lrplacd(nil, stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0079 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0079;
    goto v0113;
/* error exit handlers */
v0064:
    popv(6);
    return nil;
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegree");
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
    v0095 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* deg!*form */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    errexit();
    v0037 = v0095;
    v0095 = v0037;
    if (!(v0095 == nil)) return onevalue(v0037);
    v0095 = (Lisp_Object)1; /* 0 */
    return onevalue(v0095);
}



/* Code for smemqlp */

static Lisp_Object CC_smemqlp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0096;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemqlp");
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

v0059:
    v0083 = stack[0];
    if (v0083 == nil) goto v0071;
    v0083 = stack[0];
    v0083 = (is_number(v0083) ? lisp_true : nil);
    goto v0072;

v0072:
    if (v0083 == nil) goto v0128;
    v0083 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0083); }

v0128:
    v0083 = stack[0];
    if (!consp(v0083)) goto v0087;
    v0083 = stack[0];
    v0096 = qcar(v0083);
    v0083 = elt(env, 3); /* quote */
    if (v0096 == v0083) goto v0048;
    v0096 = stack[-1];
    v0083 = stack[0];
    v0083 = qcar(v0083);
    v0083 = CC_smemqlp(env, v0096, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    if (!(v0083 == nil)) { popv(3); return onevalue(v0083); }
    v0096 = stack[-1];
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    stack[-1] = v0096;
    stack[0] = v0083;
    goto v0059;

v0048:
    v0083 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0083); }

v0087:
    v0096 = stack[0];
    v0083 = stack[-1];
    v0083 = Lmemq(nil, v0096, v0083);
    { popv(3); return onevalue(v0083); }

v0071:
    v0083 = qvalue(elt(env, 1)); /* t */
    goto v0072;
/* error exit handlers */
v0116:
    popv(3);
    return nil;
}



/* Code for optype */

static Lisp_Object CC_optype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0093;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for optype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0122 = v0000;
/* end of prologue */
    v0093 = elt(env, 1); /* !*optype!* */
    return get(v0122, v0093);
}



/* Code for delallasc */

static Lisp_Object CC_delallasc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0086, v0120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delallasc");
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
    v0120 = nil;
    goto v0128;

v0128:
    v0085 = stack[0];
    if (v0085 == nil) goto v0071;
    v0086 = stack[-1];
    v0085 = stack[0];
    v0085 = qcar(v0085);
    v0085 = qcar(v0085);
    if (v0086 == v0085) goto v0095;
    v0085 = stack[0];
    v0085 = qcar(v0085);
    v0086 = v0120;
    v0085 = cons(v0085, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-2];
    v0120 = v0085;
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    stack[0] = v0085;
    goto v0128;

v0095:
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    stack[0] = v0085;
    goto v0128;

v0071:
    v0085 = v0120;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0085);
    }
/* error exit handlers */
v0206:
    popv(3);
    return nil;
}



/* Code for lpri */

static Lisp_Object CC_lpri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpri");
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

v0081:
    v0123 = stack[0];
    if (v0123 == nil) goto v0200;
    v0123 = stack[0];
    v0123 = qcar(v0123);
    v0123 = Lprinc(nil, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0123 = elt(env, 2); /* " " */
    v0123 = Lprinc(nil, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    stack[0] = v0123;
    goto v0081;

v0200:
    v0123 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0123); }
/* error exit handlers */
v0115:
    popv(2);
    return nil;
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    v0060 = stack[0];
    v0110 = Llength(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-2];
    v0060 = (Lisp_Object)33; /* 2 */
    if (!(v0110 == v0060)) goto v0087;
    v0060 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-2];
    goto v0087;

v0087:
    v0110 = qvalue(elt(env, 1)); /* nil */
    v0060 = (Lisp_Object)17; /* 1 */
    v0060 = cons(v0110, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-2];
    stack[-1] = v0060;
    goto v0103;

v0103:
    v0060 = stack[0];
    if (v0060 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0060 = stack[0];
    v0060 = qcar(v0060);
    fn = elt(env, 3); /* simp */
    v0110 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-2];
    v0060 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v0060 = (*qfn2(fn))(qenv(fn), v0110, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-2];
    stack[-1] = v0060;
    v0060 = stack[0];
    v0060 = qcdr(v0060);
    stack[0] = v0060;
    goto v0103;
/* error exit handlers */
v0239:
    popv(3);
    return nil;
}



/* Code for mo_compare */

static Lisp_Object CC_mo_compare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0083, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_compare");
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
    v0082 = stack[-1];
    v0083 = qcdr(v0082);
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    fn = elt(env, 3); /* mo!=degcomp */
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    v0096 = v0082;
    v0083 = v0096;
    v0082 = (Lisp_Object)1; /* 0 */
    if (!(v0083 == v0082)) { popv(3); return onevalue(v0096); }
    v0082 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_tag */
    v0083 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    v0082 = elt(env, 2); /* revlex */
    if (v0083 == v0082) goto v0085;
    v0082 = stack[-1];
    v0083 = qcar(v0082);
    v0082 = stack[0];
    v0082 = qcar(v0082);
    fn = elt(env, 5); /* mo!=lexcomp */
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    goto v0119;

v0119:
    v0096 = v0082;
    { popv(3); return onevalue(v0096); }

v0085:
    v0082 = stack[-1];
    v0083 = qcar(v0082);
    v0082 = stack[0];
    v0082 = qcar(v0082);
    fn = elt(env, 6); /* mo!=revlexcomp */
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    goto v0119;
/* error exit handlers */
v0116:
    popv(3);
    return nil;
}



/* Code for pv_renorm */

static Lisp_Object CC_pv_renorm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_renorm");
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
    stack[0] = v0000;
/* end of prologue */
    v0062 = stack[0];
    if (!(v0062 == nil)) goto v0061;
    v0062 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0062); }

v0061:
    v0062 = stack[0];
    if (v0062 == nil) goto v0037;
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0192 = qcar(v0062);
    v0062 = (Lisp_Object)1; /* 0 */
    if (!(v0192 == v0062)) goto v0037;
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    stack[0] = v0062;
    goto v0061;

v0037:
    v0062 = stack[0];
    if (v0062 == nil) goto v0047;
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0192 = qcar(v0062);
    v0062 = (Lisp_Object)1; /* 0 */
    v0062 = (Lisp_Object)lessp2(v0192, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    v0062 = v0062 ? lisp_true : nil;
    env = stack[-4];
    if (v0062 == nil) goto v0092;
    v0062 = stack[0];
    fn = elt(env, 2); /* pv_neg */
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[0] = v0062;
    goto v0092;

v0092:
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    stack[-2] = v0062;
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    stack[-3] = v0062;
    goto v0030;

v0030:
    v0062 = stack[-3];
    if (v0062 == nil) goto v0096;
    v0192 = stack[-2];
    v0062 = (Lisp_Object)17; /* 1 */
    if (v0192 == v0062) goto v0096;
    v0192 = stack[-2];
    v0062 = stack[-3];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    fn = elt(env, 3); /* gcdf!* */
    v0062 = (*qfn2(fn))(qenv(fn), v0192, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-2] = v0062;
    v0062 = stack[-3];
    v0062 = qcdr(v0062);
    stack[-3] = v0062;
    goto v0030;

v0096:
    v0062 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0062;
    v0062 = stack[0];
    stack[-1] = v0062;
    goto v0076;

v0076:
    v0062 = stack[-1];
    if (v0062 == nil) goto v0077;
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    stack[0] = v0062;
    v0062 = stack[0];
    v0192 = qcar(v0062);
    v0062 = (Lisp_Object)1; /* 0 */
    if (v0192 == v0062) goto v0145;
    v0192 = stack[-2];
    v0062 = (Lisp_Object)17; /* 1 */
    if (v0192 == v0062) goto v0228;
    v0062 = stack[0];
    v0192 = qcar(v0062);
    v0062 = stack[-2];
    v0192 = quot2(v0192, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    v0062 = cons(v0192, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0192 = v0062;
    goto v0089;

v0089:
    v0062 = stack[-3];
    v0062 = cons(v0192, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-3] = v0062;
    goto v0145;

v0145:
    v0062 = stack[-1];
    v0062 = qcdr(v0062);
    stack[-1] = v0062;
    goto v0076;

v0228:
    v0062 = stack[0];
    v0192 = v0062;
    goto v0089;

v0077:
    v0062 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0062);

v0047:
    v0062 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0062); }
/* error exit handlers */
v0017:
    popv(5);
    return nil;
}



/* Code for dv_skelhead */

static Lisp_Object CC_dv_skelhead(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelhead");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0103 = v0000;
/* end of prologue */
    v0103 = qcar(v0103);
    {
        fn = elt(env, 1); /* dv_cambhead */
        return (*qfn1(fn))(qenv(fn), v0103);
    }
}



/* Code for mkrn */

static Lisp_Object CC_mkrn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrn");
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

v0093:
    v0040 = stack[-1];
    v0112 = (Lisp_Object)1; /* 0 */
    v0112 = (Lisp_Object)lessp2(v0040, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0112 = v0112 ? lisp_true : nil;
    env = stack[-4];
    if (v0112 == nil) goto v0067;
    v0112 = stack[-2];
    v0112 = negate(v0112);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    stack[-2] = v0112;
    v0112 = stack[-1];
    v0112 = negate(v0112);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    stack[-1] = v0112;
    goto v0093;

v0067:
    v0040 = stack[-2];
    v0112 = stack[-1];
    v0112 = Lgcd(nil, v0040, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    stack[-3] = v0112;
    stack[0] = elt(env, 1); /* !:rn!: */
    v0040 = stack[-2];
    v0112 = stack[-3];
    stack[-2] = quot2(v0040, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0040 = stack[-1];
    v0112 = stack[-3];
    v0112 = quot2(v0040, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    {
        Lisp_Object v0030 = stack[0];
        Lisp_Object v0108 = stack[-2];
        popv(5);
        return list2star(v0030, v0108, v0112);
    }
/* error exit handlers */
v0096:
    popv(5);
    return nil;
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0038, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    v0043 = v0001;
    v0105 = v0000;
/* end of prologue */
    v0038 = v0105;
    v0038 = qcar(v0038);
    if (v0038 == v0043) goto v0123;
    v0043 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0043); }

v0123:
    v0043 = v0105;
    v0038 = qcdr(v0043);
    v0043 = (Lisp_Object)17; /* 1 */
    if (v0038 == v0043) goto v0061;
    v0043 = v0105;
    stack[-1] = qcdr(v0043);
    v0043 = v0105;
    stack[0] = qcar(v0043);
    v0043 = v0105;
    v0043 = qcdr(v0043);
    v0038 = sub1(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-2];
    v0043 = (Lisp_Object)17; /* 1 */
    v0043 = acons(stack[0], v0038, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-2];
    v0043 = ncons(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-2];
    {
        Lisp_Object v0112 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* multd */
        return (*qfn2(fn))(qenv(fn), v0112, v0043);
    }

v0061:
    v0043 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0043); }
/* error exit handlers */
v0127:
    popv(3);
    return nil;
}



/* Code for removev */

static Lisp_Object CC_removev(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0129, v0239, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removev");
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
    v0042 = v0001;
    v0239 = v0000;
/* end of prologue */

v0103:
    v0124 = v0239;
    if (v0124 == nil) goto v0094;
    v0124 = v0239;
    v0124 = qcdr(v0124);
    v0129 = qcar(v0124);
    v0124 = v0042;
    if (v0129 == v0124) goto v0109;
    v0124 = v0239;
    v0124 = qcdr(v0124);
    v0239 = v0124;
    goto v0103;

v0109:
    v0124 = v0239;
    v0129 = v0239;
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
        popv(1);
        return Lrplacd(nil, v0124, v0129);

v0094:
    v0129 = elt(env, 1); /* "Vertex" */
    v0239 = v0042;
    v0124 = elt(env, 2); /* "is absent." */
    v0124 = list3(v0129, v0239, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cerror */
        return (*qfn1(fn))(qenv(fn), v0124);
    }
/* error exit handlers */
v0043:
    popv(1);
    return nil;
}



/* Code for subs2f1 */

static Lisp_Object CC_subs2f1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0307, v0308, v0309, v0310, v0311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f1");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0000;
/* end of prologue */
    v0307 = stack[-8];
    if (!consp(v0307)) goto v0072;
    v0307 = stack[-8];
    v0307 = qcar(v0307);
    v0307 = (consp(v0307) ? nil : lisp_true);
    goto v0200;

v0200:
    if (v0307 == nil) goto v0114;
    v0307 = stack[-8];
    {
        popv(11);
        fn = elt(env, 12); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0307);
    }

v0114:
    stack[-2] = nil;
    goto v0049;

v0049:
    v0307 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0307;
    v0307 = stack[-8];
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    stack[-9] = v0307;
    v0308 = qvalue(elt(env, 2)); /* nil */
    v0307 = (Lisp_Object)17; /* 1 */
    v0307 = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-3] = v0307;
    goto v0044;

v0044:
    v0307 = stack[-8];
    if (v0307 == nil) goto v0039;
    v0308 = stack[-8];
    v0307 = stack[-9];
    fn = elt(env, 13); /* degr */
    v0308 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = (Lisp_Object)1; /* 0 */
    v0307 = (v0308 == v0307 ? lisp_true : nil);
    goto v0041;

v0041:
    if (!(v0307 == nil)) goto v0069;
    v0307 = stack[-8];
    v0308 = qcar(v0307);
    v0307 = stack[-4];
    v0307 = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-4] = v0307;
    v0307 = stack[-8];
    v0307 = qcdr(v0307);
    stack[-8] = v0307;
    goto v0044;

v0069:
    v0307 = qvalue(elt(env, 3)); /* powlis!* */
    stack[-5] = v0307;
    goto v0121;

v0121:
    v0307 = stack[-5];
    if (v0307 == nil) goto v0070;
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    v0308 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    if (equal(v0308, v0307)) goto v0074;
    v0308 = stack[-9];
    v0307 = elt(env, 4); /* expt */
    if (!consp(v0308)) goto v0313;
    v0308 = qcar(v0308);
    if (!(v0308 == v0307)) goto v0313;
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    if (equal(v0308, v0307)) goto v0016;
    v0307 = qvalue(elt(env, 2)); /* nil */
    goto v0020;

v0020:
    if (v0307 == nil) goto v0079;
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    v0308 = qcdr(v0307);
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = Ldivide(nil, v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-7] = v0307;
    v0307 = stack[-7];
    v0308 = qcar(v0307);
    v0307 = (Lisp_Object)1; /* 0 */
    if (v0308 == v0307) goto v0314;
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    fn = elt(env, 14); /* simp */
    v0308 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-7];
    v0307 = qcar(v0307);
    fn = elt(env, 15); /* exptsq */
    v0307 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-6] = v0307;
    goto v0315;

v0315:
    v0307 = stack[-7];
    v0308 = qcdr(v0307);
    v0307 = (Lisp_Object)1; /* 0 */
    if (v0308 == v0307) goto v0316;
    stack[-1] = qvalue(elt(env, 6)); /* alglist!* */
    qvalue(elt(env, 6)) = nil; /* alglist!* */
    stack[0] = qvalue(elt(env, 7)); /* dmode!* */
    qvalue(elt(env, 7)) = nil; /* dmode!* */
    v0307 = qvalue(elt(env, 2)); /* nil */
    v0307 = ncons(v0307);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-10];
    qvalue(elt(env, 6)) = v0307; /* alglist!* */
    v0307 = stack[-7];
    v0308 = qcdr(v0307);
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-10];
    fn = elt(env, 16); /* cancel */
    v0307 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-10];
    stack[-7] = v0307;
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = stack[-7];
    v0307 = qcar(v0307);
    v0309 = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    fn = elt(env, 17); /* subs2p */
    v0307 = (*qfnn(fn))(qenv(fn), 3, v0309, v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    fn = elt(env, 18); /* mk!*sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0309 = elt(env, 5); /* quotient */
    v0308 = (Lisp_Object)17; /* 1 */
    v0307 = stack[-7];
    v0307 = qcdr(v0307);
    v0307 = list3(v0309, v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = list2(stack[0], v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    fn = elt(env, 19); /* simpexpt */
    v0308 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-6];
    fn = elt(env, 20); /* multsq */
    v0307 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-6] = v0307;
    goto v0316;

v0316:
    stack[0] = stack[-6];
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = CC_subs2f1(env, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    fn = elt(env, 20); /* multsq */
    v0308 = (*qfn2(fn))(qenv(fn), stack[0], v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-3];
    fn = elt(env, 21); /* addsq */
    v0307 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-3] = v0307;
    goto v0046;

v0046:
    v0307 = stack[-4];
    v0307 = qcdr(v0307);
    stack[-4] = v0307;
    v0307 = stack[-4];
    if (!(v0307 == nil)) goto v0069;

v0047:
    v0307 = stack[-8];
    if (!consp(v0307)) goto v0318;
    v0307 = stack[-8];
    v0307 = qcar(v0307);
    v0307 = (consp(v0307) ? nil : lisp_true);
    goto v0319;

v0319:
    if (v0307 == nil) goto v0320;
    v0307 = stack[-8];
    fn = elt(env, 12); /* !*d2q */
    v0307 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-4] = v0307;
    goto v0045;

v0045:
    v0307 = qvalue(elt(env, 10)); /* !*exp */
    if (!(v0307 == nil)) goto v0321;
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    fn = elt(env, 22); /* mkprod */
    stack[0] = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-4];
    v0307 = qcdr(v0307);
    fn = elt(env, 22); /* mkprod */
    v0307 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = cons(stack[0], v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-4] = v0307;
    goto v0321;

v0321:
    v0308 = stack[-3];
    v0307 = stack[-4];
    fn = elt(env, 21); /* addsq */
    v0307 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-4] = v0307;
    v0307 = stack[-2];
    if (v0307 == nil) { Lisp_Object res = stack[-4]; popv(11); return onevalue(res); }
    v0307 = stack[-2];
    v0307 = qcar(v0307);
    stack[-3] = v0307;
    v0307 = stack[-2];
    v0307 = qcdr(v0307);
    stack[-2] = v0307;
    goto v0045;

v0320:
    v0308 = stack[-3];
    v0307 = stack[-2];
    v0307 = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-2] = v0307;
    goto v0049;

v0318:
    v0307 = qvalue(elt(env, 1)); /* t */
    goto v0319;

v0314:
    v0308 = (Lisp_Object)17; /* 1 */
    v0307 = (Lisp_Object)17; /* 1 */
    v0307 = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-6] = v0307;
    goto v0315;

v0079:
    v0307 = stack[-5];
    v0307 = qcdr(v0307);
    stack[-5] = v0307;
    goto v0121;

v0016:
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = elt(env, 5); /* quotient */
    if (!consp(v0308)) goto v0003;
    v0308 = qcar(v0308);
    if (!(v0308 == v0307)) goto v0003;
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = (Lisp_Object)17; /* 1 */
    if (v0308 == v0307) goto v0223;
    v0307 = qvalue(elt(env, 2)); /* nil */
    goto v0020;

v0223:
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = (is_number(v0307) ? lisp_true : nil);
    goto v0020;

v0003:
    v0307 = qvalue(elt(env, 2)); /* nil */
    goto v0020;

v0313:
    v0307 = qvalue(elt(env, 2)); /* nil */
    goto v0020;

v0074:
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0309 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    fn = elt(env, 17); /* subs2p */
    v0307 = (*qfnn(fn))(qenv(fn), 3, v0309, v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-6] = v0307;
    goto v0316;

v0070:
    v0307 = qvalue(elt(env, 8)); /* powlis1!* */
    stack[-5] = v0307;
    goto v0109;

v0109:
    v0307 = stack[-5];
    if (v0307 == nil) goto v0322;
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0311 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0310 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0309 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0308 = qcar(v0307);
    v0307 = stack[-5];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    fn = elt(env, 23); /* mtchp */
    v0307 = (*qfnn(fn))(qenv(fn), 5, v0311, v0310, v0309, v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-6] = v0307;
    if (!(v0307 == nil)) goto v0316;
    v0307 = stack[-5];
    v0307 = qcdr(v0307);
    stack[-5] = v0307;
    goto v0109;

v0322:
    v0308 = stack[-9];
    v0307 = elt(env, 4); /* expt */
    if (!consp(v0308)) goto v0323;
    v0308 = qcar(v0308);
    if (!(v0308 == v0307)) goto v0323;
    v0307 = qvalue(elt(env, 9)); /* !*structure */
    v0307 = (v0307 == nil ? lisp_true : nil);
    goto v0324;

v0324:
    if (!(v0307 == nil)) goto v0325;
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0308 = qcar(v0307);
    v0307 = (Lisp_Object)17; /* 1 */
    v0307 = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0308 = ncons(v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = CC_subs2f1(env, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    fn = elt(env, 20); /* multsq */
    v0308 = (*qfn2(fn))(qenv(fn), stack[0], v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-3];
    fn = elt(env, 21); /* addsq */
    v0307 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-3] = v0307;
    goto v0046;

v0325:
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    v0308 = qcdr(v0307);
    v0307 = (Lisp_Object)17; /* 1 */
    if (v0308 == v0307) goto v0326;
    v0307 = qvalue(elt(env, 2)); /* nil */
    goto v0327;

v0327:
    if (v0307 == nil) goto v0328;
    v0308 = stack[-9];
    v0307 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 24); /* mksq */
    v0307 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-6] = v0307;
    goto v0329;

v0329:
    stack[0] = stack[-6];
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = CC_subs2f1(env, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    fn = elt(env, 20); /* multsq */
    v0308 = (*qfn2(fn))(qenv(fn), stack[0], v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = stack[-3];
    fn = elt(env, 21); /* addsq */
    v0307 = (*qfn2(fn))(qenv(fn), v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-3] = v0307;
    v0307 = stack[-4];
    v0307 = qcdr(v0307);
    stack[-4] = v0307;
    v0307 = stack[-4];
    if (v0307 == nil) goto v0047;
    else goto v0325;

v0328:
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    stack[0] = qcar(v0307);
    v0309 = elt(env, 11); /* times */
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = stack[-4];
    v0307 = qcar(v0307);
    v0307 = qcar(v0307);
    v0307 = qcdr(v0307);
    v0307 = list3(v0309, v0308, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    v0307 = list2(stack[0], v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    fn = elt(env, 19); /* simpexpt */
    v0307 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-10];
    stack[-6] = v0307;
    goto v0329;

v0326:
    v0307 = stack[-9];
    v0307 = qcdr(v0307);
    v0308 = qcar(v0307);
    v0307 = elt(env, 4); /* expt */
    v0307 = Leqcar(nil, v0308, v0307);
    env = stack[-10];
    v0307 = (v0307 == nil ? lisp_true : nil);
    goto v0327;

v0323:
    v0307 = qvalue(elt(env, 2)); /* nil */
    goto v0324;

v0039:
    v0307 = qvalue(elt(env, 1)); /* t */
    goto v0041;

v0072:
    v0307 = qvalue(elt(env, 1)); /* t */
    goto v0200;
/* error exit handlers */
v0317:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    popv(11);
    return nil;
v0312:
    popv(11);
    return nil;
}



/* Code for cl_simplat */

static Lisp_Object CC_cl_simplat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0070, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    v0070 = v0001;
    v0109 = v0000;
/* end of prologue */
    v0121 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v0121 == nil) goto v0071;
    v0121 = v0109;
    fn = elt(env, 3); /* rl_simplat1 */
    v0070 = (*qfn2(fn))(qenv(fn), v0121, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[0];
    v0121 = elt(env, 2); /* cl_identifyat */
    {
        popv(1);
        fn = elt(env, 4); /* cl_apply2ats */
        return (*qfn2(fn))(qenv(fn), v0070, v0121);
    }

v0071:
    v0121 = v0109;
    {
        popv(1);
        fn = elt(env, 3); /* rl_simplat1 */
        return (*qfn2(fn))(qenv(fn), v0121, v0070);
    }
/* error exit handlers */
v0131:
    popv(1);
    return nil;
}



/* Code for ibalp_commonlenisone */

static Lisp_Object CC_ibalp_commonlenisone(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
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
    v0118 = stack[-1];
    if (v0118 == nil) goto v0072;
    v0118 = qvalue(elt(env, 1)); /* nil */
    goto v0200;

v0200:
    if (!(v0118 == nil)) { popv(3); return onevalue(v0118); }
    v0118 = stack[0];
    if (v0118 == nil) goto v0123;
    v0118 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0118); }

v0123:
    v0118 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* ibalp_lenisone */
        return (*qfn1(fn))(qenv(fn), v0118);
    }

v0072:
    v0118 = stack[0];
    fn = elt(env, 2); /* ibalp_lenisone */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    goto v0200;
/* error exit handlers */
v0048:
    popv(3);
    return nil;
}



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml");
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
    fn = elt(env, 2); /* lex */
    v0200 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0072:
    popv(1);
    return nil;
}



/* Code for off_mod_reval */

static Lisp_Object CC_off_mod_reval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    v0088 = qvalue(elt(env, 1)); /* !*modular */
    if (v0088 == nil) goto v0123;
    v0088 = elt(env, 2); /* modular */
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    fn = elt(env, 4); /* off */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0088 = stack[0];
    fn = elt(env, 5); /* reval */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    stack[0] = v0088;
    v0088 = elt(env, 2); /* modular */
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    fn = elt(env, 6); /* on */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0123:
    v0088 = stack[0];
    fn = elt(env, 5); /* reval */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    stack[0] = v0088;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0067:
    popv(2);
    return nil;
}



/* Code for mknwedge */

static Lisp_Object CC_mknwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0087;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mknwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0115 = v0087;
    v0115 = qcdr(v0115);
    if (v0115 == nil) goto v0061;
    v0115 = elt(env, 1); /* wedge */
    return cons(v0115, v0087);

v0061:
    v0115 = v0087;
    v0115 = qcar(v0115);
    return onevalue(v0115);
}



/* Code for boundindp */

static Lisp_Object CC_boundindp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0121, v0070, v0109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boundindp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0109 = v0001;
    v0070 = v0000;
/* end of prologue */

v0103:
    v0069 = v0070;
    if (v0069 == nil) goto v0072;
    v0069 = v0070;
    v0121 = qcar(v0069);
    v0069 = v0109;
    v0069 = Lmember(nil, v0121, v0069);
    if (v0069 == nil) goto v0048;
    v0069 = v0070;
    v0069 = qcdr(v0069);
    v0070 = v0069;
    goto v0103;

v0048:
    v0069 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0069);

v0072:
    v0069 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0069);
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0100 = v0000;
/* end of prologue */
    stack[0] = elt(env, 1); /* list */
    v0123 = v0100;
    v0100 = elt(env, 2); /* set!-ordp */
    fn = elt(env, 3); /* sort */
    v0100 = (*qfn2(fn))(qenv(fn), v0123, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    {
        Lisp_Object v0087 = stack[0];
        popv(1);
        return cons(v0087, v0100);
    }
/* error exit handlers */
v0115:
    popv(1);
    return nil;
}



/* Code for maxdeg */

static Lisp_Object CC_maxdeg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0131;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxdeg");
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

v0128:
    v0109 = stack[-1];
    if (v0109 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    v0131 = qcdr(v0109);
    v0109 = stack[0];
    v0109 = qcdr(v0109);
    v0109 = (Lisp_Object)greaterp2(v0131, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0109 = v0109 ? lisp_true : nil;
    env = stack[-2];
    if (v0109 == nil) goto v0044;
    v0109 = stack[-1];
    v0109 = qcdr(v0109);
    v0131 = v0109;
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    stack[0] = v0109;
    v0109 = v0131;
    stack[-1] = v0109;
    goto v0128;

v0044:
    v0109 = stack[-1];
    v0109 = qcdr(v0109);
    stack[-1] = v0109;
    goto v0128;
/* error exit handlers */
v0045:
    popv(3);
    return nil;
}



/* Code for areallindices */

static Lisp_Object CC_areallindices(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for areallindices");
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

v0059:
    v0066 = stack[0];
    v0066 = qcar(v0066);
    fn = elt(env, 3); /* isanindex */
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    if (v0066 == nil) goto v0081;
    v0066 = stack[0];
    v0066 = qcdr(v0066);
    if (v0066 == nil) goto v0095;
    v0066 = stack[0];
    v0066 = qcdr(v0066);
    stack[0] = v0066;
    goto v0059;

v0095:
    v0066 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0066); }

v0081:
    v0066 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0066); }
/* error exit handlers */
v0118:
    popv(2);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0068, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0397, v0398, v0399, v0400;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0068,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0068);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0068;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0059:
    v0397 = stack[-3];
    if (!consp(v0397)) goto v0122;
    v0397 = stack[-3];
    v0397 = qcar(v0397);
    if (!consp(v0397)) goto v0116;
    v0399 = stack[-3];
    v0398 = stack[-2];
    v0397 = stack[-1];
    {
        popv(6);
        fn = elt(env, 33); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v0399, v0398, v0397);
    }

v0116:
    v0397 = stack[-3];
    v0397 = qcar(v0397);
    if (symbolp(v0397)) goto v0237;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 4); /* "operator" */
    fn = elt(env, 34); /* typerr */
    v0397 = (*qfn2(fn))(qenv(fn), v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0402;

v0402:
    v0398 = stack[-1];
    v0397 = elt(env, 9); /* symbolic */
    if (v0398 == v0397) goto v0403;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 24); /* opfn */
    v0397 = Lflagp(nil, v0398, v0397);
    env = stack[-5];
    goto v0277;

v0277:
    if (v0397 == nil) goto v0404;
    v0397 = stack[-3];
    fn = elt(env, 35); /* argnochk */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0404;

v0404:
    v0397 = stack[-3];
    v0399 = qcdr(v0397);
    v0398 = stack[-2];
    v0397 = stack[-1];
    fn = elt(env, 36); /* formlis */
    v0397 = (*qfnn(fn))(qenv(fn), 3, v0399, v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-4] = v0397;
    v0398 = stack[-4];
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    if (equal(v0398, v0397)) goto v0405;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = stack[-4];
    v0397 = cons(v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0406;

v0406:
    stack[0] = v0397;
    v0398 = stack[-1];
    v0397 = elt(env, 9); /* symbolic */
    if (v0398 == v0397) goto v0407;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 16); /* stat */
    v0397 = get(v0398, v0397);
    env = stack[-5];
    if (!(v0397 == nil)) goto v0408;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    if (v0397 == nil) goto v0409;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0398 = qcar(v0397);
    v0397 = elt(env, 25); /* quote */
    if (!consp(v0398)) goto v0410;
    v0398 = qcar(v0398);
    if (!(v0398 == v0397)) goto v0410;
    v0397 = qvalue(elt(env, 26)); /* !*micro!-version */
    if (v0397 == nil) goto v0260;
    v0397 = qvalue(elt(env, 27)); /* !*defn */
    v0397 = (v0397 == nil ? lisp_true : nil);
    goto v0411;

v0411:
    v0397 = (v0397 == nil ? lisp_true : nil);
    goto v0412;

v0412:
    if (!(v0397 == nil)) goto v0408;
    v0398 = stack[0];
    v0397 = stack[-2];
    fn = elt(env, 37); /* intexprnp */
    v0397 = (*qfn2(fn))(qenv(fn), v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    if (v0397 == nil) goto v0413;
    v0397 = qvalue(elt(env, 28)); /* !*composites */
    if (v0397 == nil) goto v0414;
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0408;

v0408:
    if (v0397 == nil) goto v0415;
    v0398 = stack[0];
    v0397 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0398, v0397);
    }

v0415:
    v0398 = stack[-1];
    v0397 = elt(env, 30); /* algebraic */
    if (v0398 == v0397) goto v0416;
    v0399 = stack[0];
    v0398 = stack[-2];
    v0397 = elt(env, 30); /* algebraic */
    v0400 = CC_form1(env, 3, v0399, v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0399 = stack[-2];
    v0398 = stack[-1];
    v0397 = elt(env, 30); /* algebraic */
    {
        popv(6);
        fn = elt(env, 39); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v0400, v0399, v0398, v0397);
    }

v0416:
    stack[0] = elt(env, 31); /* list */
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = stack[-2];
    v0397 = Latsoc(nil, v0398, v0397);
    if (!(v0397 == nil)) goto v0417;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 32); /* share */
    v0397 = Lflagp(nil, v0398, v0397);
    env = stack[-5];
    if (!(v0397 == nil)) goto v0417;
    v0397 = stack[-3];
    v0397 = qcar(v0397);
    v0397 = Lmkquote(nil, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0398 = v0397;
    goto v0418;

v0418:
    v0397 = stack[-4];
    {
        Lisp_Object v0419 = stack[0];
        popv(6);
        return list2star(v0419, v0398, v0397);
    }

v0417:
    v0397 = stack[-3];
    v0397 = qcar(v0397);
    v0398 = v0397;
    goto v0418;

v0414:
    v0398 = qvalue(elt(env, 29)); /* current!-modulus */
    v0397 = (Lisp_Object)17; /* 1 */
    v0397 = (v0398 == v0397 ? lisp_true : nil);
    goto v0408;

v0413:
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0408;

v0260:
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0411;

v0410:
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0412;

v0409:
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0412;

v0407:
    v0397 = qvalue(elt(env, 13)); /* t */
    goto v0408;

v0405:
    v0397 = stack[-3];
    goto v0406;

v0403:
    v0397 = qvalue(elt(env, 13)); /* t */
    goto v0277;

v0237:
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 5); /* comment */
    if (v0398 == v0397) goto v0231;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 6); /* noform */
    v0397 = Lflagp(nil, v0398, v0397);
    env = stack[-5];
    if (!(v0397 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 7); /* rtype */
    v0398 = get(v0398, v0397);
    env = stack[-5];
    v0397 = elt(env, 8); /* array */
    if (v0398 == v0397) goto v0021;
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0198;

v0198:
    if (v0397 == nil) goto v0090;
    stack[0] = elt(env, 11); /* getel */
    v0399 = stack[-3];
    v0398 = stack[-2];
    v0397 = stack[-1];
    fn = elt(env, 40); /* intargfn */
    v0397 = (*qfnn(fn))(qenv(fn), 3, v0399, v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    {
        Lisp_Object v0420 = stack[0];
        popv(6);
        return list2(v0420, v0397);
    }

v0090:
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    if (v0397 == nil) goto v0421;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 7); /* rtype */
    v0398 = get(v0398, v0397);
    env = stack[-5];
    v0397 = elt(env, 12); /* vector */
    if (v0398 == v0397) goto v0191;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    v0397 = Lsimple_vectorp(nil, v0397);
    env = stack[-5];
    if (!(v0397 == nil)) goto v0190;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0398 = qcar(v0397);
    v0397 = elt(env, 14); /* vecfn */
    v0397 = Lflagpcar(nil, v0398, v0397);
    env = stack[-5];
    goto v0190;

v0190:
    if (v0397 == nil) goto v0421;
    v0399 = stack[-3];
    v0398 = stack[-2];
    v0397 = stack[-1];
    {
        popv(6);
        fn = elt(env, 41); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v0399, v0398, v0397);
    }

v0421:
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 2); /* modefn */
    v0397 = Lflagp(nil, v0398, v0397);
    env = stack[-5];
    if (v0397 == nil) goto v0300;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0399 = qcar(v0397);
    v0398 = stack[-2];
    v0397 = stack[-3];
    v0397 = qcar(v0397);
    v0400 = CC_form1(env, 3, v0399, v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0399 = stack[-2];
    v0398 = stack[-1];
    v0397 = stack[-3];
    v0397 = qcar(v0397);
    {
        popv(6);
        fn = elt(env, 39); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v0400, v0399, v0398, v0397);
    }

v0300:
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 15); /* formfn */
    v0397 = get(v0398, v0397);
    env = stack[-5];
    stack[-4] = v0397;
    if (v0397 == nil) goto v0422;
    v0400 = stack[-4];
    v0399 = stack[-3];
    v0398 = stack[-2];
    v0397 = stack[-1];
    v0398 = Lapply3(nil, 4, v0400, v0399, v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0397 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0398, v0397);
    }

v0422:
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 16); /* stat */
    v0398 = get(v0398, v0397);
    env = stack[-5];
    v0397 = elt(env, 17); /* rlis */
    if (v0398 == v0397) goto v0423;
    v0397 = stack[-3];
    v0398 = qcar(v0397);
    v0397 = elt(env, 18); /* !*comma!* */
    if (!(v0398 == v0397)) goto v0402;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    if (!consp(v0397)) goto v0424;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    if (!consp(v0397)) goto v0425;
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0426;

v0426:
    if (v0397 == nil) goto v0427;
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    v0398 = qcar(v0397);
    v0397 = elt(env, 20); /* "invalid except at head of block" */
    v0397 = list2(v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0398 = v0397;
    v0397 = v0398;
    qvalue(elt(env, 21)) = v0397; /* errmsg!* */
    v0397 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v0397 == nil)) goto v0428;
    v0397 = v0398;
    fn = elt(env, 42); /* lprie */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0428;

v0428:
    v0397 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0402;

v0427:
    v0398 = elt(env, 23); /* "Syntax error: , invalid after" */
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    v0397 = list2(v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0398 = v0397;
    v0397 = v0398;
    qvalue(elt(env, 21)) = v0397; /* errmsg!* */
    v0397 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v0397 == nil)) goto v0273;
    v0397 = v0398;
    fn = elt(env, 42); /* lprie */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0273;

v0273:
    v0397 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0402;

v0425:
    v0397 = stack[-3];
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    v0398 = qcar(v0397);
    v0397 = elt(env, 19); /* type */
    v0397 = Lflagp(nil, v0398, v0397);
    env = stack[-5];
    goto v0426;

v0424:
    v0397 = qvalue(elt(env, 10)); /* nil */
    goto v0426;

v0423:
    v0399 = stack[-3];
    v0398 = stack[-2];
    v0397 = stack[-1];
    fn = elt(env, 43); /* formrlis */
    v0398 = (*qfnn(fn))(qenv(fn), 3, v0399, v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0397 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0398, v0397);
    }

v0191:
    v0397 = qvalue(elt(env, 13)); /* t */
    goto v0190;

v0021:
    v0398 = stack[-1];
    v0397 = elt(env, 9); /* symbolic */
    v0397 = (v0398 == v0397 ? lisp_true : nil);
    goto v0198;

v0231:
    v0397 = stack[-3];
    fn = elt(env, 44); /* lastpair */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0399 = qcar(v0397);
    v0398 = stack[-2];
    v0397 = stack[-1];
    stack[-3] = v0399;
    stack[-2] = v0398;
    stack[-1] = v0397;
    goto v0059;

v0122:
    v0397 = stack[-3];
    if (!(symbolp(v0397))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0398 = stack[-3];
    v0397 = elt(env, 1); /* ed */
    if (v0398 == v0397) goto v0114;
    v0398 = stack[-3];
    v0397 = elt(env, 2); /* modefn */
    v0397 = Lflagp(nil, v0398, v0397);
    env = stack[-5];
    if (v0397 == nil) goto v0206;
    v0397 = stack[-3];
    {
        popv(6);
        fn = elt(env, 45); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v0397);
    }

v0206:
    v0398 = stack[-1];
    v0397 = elt(env, 3); /* idfn */
    v0397 = get(v0398, v0397);
    stack[-4] = v0397;
    if (v0397 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0399 = stack[-4];
    v0398 = stack[-3];
    v0397 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v0399, v0398, v0397);

v0114:
    v0397 = stack[-3];
    popv(6);
    return ncons(v0397);
/* error exit handlers */
v0401:
    popv(6);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    v0061 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    v0061 = stack[0];
    v0061 = qcar(v0061);
    fn = elt(env, 2); /* simp */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    fn = elt(env, 3); /* simpminus */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    {
        Lisp_Object v0115 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0115, v0061);
    }
/* error exit handlers */
v0114:
    popv(3);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight");
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
    v0114 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    v0115 = stack[-1];
    v0114 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v0114 = (*qfn2(fn))(qenv(fn), v0115, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    {
        Lisp_Object v0067 = stack[-2];
        popv(4);
        return cons(v0067, v0114);
    }
/* error exit handlers */
v0066:
    popv(4);
    return nil;
}



/* Code for bc!=simp */

static Lisp_Object CC_bcMsimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc=simp");
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
    v0053 = elt(env, 1); /* cali */
    v0052 = elt(env, 2); /* rules */
    v0052 = get(v0053, v0052);
    env = stack[-5];
    stack[-4] = v0052;
    v0052 = stack[-4];
    if (v0052 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0052 = (Lisp_Object)1; /* 0 */
    stack[0] = v0052;
    v0052 = stack[-4];
    stack[-2] = v0052;
    goto v0118;

v0118:
    v0052 = stack[-2];
    if (v0052 == nil) goto v0395;
    v0053 = stack[0];
    v0052 = (Lisp_Object)16001; /* 1000 */
    v0052 = (Lisp_Object)lessp2(v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    v0052 = v0052 ? lisp_true : nil;
    env = stack[-5];
    if (v0052 == nil) goto v0395;
    v0053 = stack[-3];
    v0052 = stack[-2];
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    fn = elt(env, 6); /* qremf */
    v0052 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    stack[-1] = v0052;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    if (v0052 == nil) goto v0111;
    v0052 = stack[-1];
    v0053 = qcar(v0052);
    v0052 = stack[-2];
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    fn = elt(env, 7); /* multf */
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    fn = elt(env, 8); /* addf */
    v0052 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    stack[-3] = v0052;
    v0052 = stack[0];
    v0052 = add1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    stack[0] = v0052;
    v0052 = stack[-4];
    stack[-2] = v0052;
    goto v0118;

v0111:
    v0052 = stack[-2];
    v0052 = qcdr(v0052);
    stack[-2] = v0052;
    goto v0118;

v0395:
    v0053 = stack[0];
    v0052 = (Lisp_Object)16001; /* 1000 */
    v0052 = (Lisp_Object)lessp2(v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    v0052 = v0052 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0052 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0052 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0052 == nil)) goto v0231;
    v0052 = elt(env, 5); /* "recursion depth of bc!=simp too high" */
    fn = elt(env, 9); /* lprie */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    goto v0231;

v0231:
    v0052 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    v0052 = nil;
    { popv(6); return onevalue(v0052); }
/* error exit handlers */
v0201:
    popv(6);
    return nil;
}



setup_type const u05_setup[] =
{
    {"fs:plus",                 too_few_2,      CC_fsTplus,    wrong_no_2},
    {"mo=shorten",              CC_moMshorten,  too_many_1,    wrong_no_1},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"gen-mult-by-const-mod-p", too_few_2,      CC_genKmultKbyKconstKmodKp,wrong_no_2},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"procstat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_procstat},
    {"qqe_id-nyt-branchb",      CC_qqe_idKnytKbranchb,too_many_1,wrong_no_1},
    {"pasf_dec",                CC_pasf_dec,    too_many_1,    wrong_no_1},
    {"ibalp_getupl",            CC_ibalp_getupl,too_many_1,    wrong_no_1},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"simpminus",               CC_simpminus,   too_many_1,    wrong_no_1},
    {"fs:timestermterm",        too_few_2,      CC_fsTtimestermterm,wrong_no_2},
    {"mo_sum",                  too_few_2,      CC_mo_sum,     wrong_no_2},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"prin2*",                  CC_prin2H,      too_many_1,    wrong_no_1},
    {"insert_pv",               too_few_2,      CC_insert_pv,  wrong_no_2},
    {"rntimes:",                too_few_2,      CC_rntimesT,   wrong_no_2},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"*i2gi",                   CC_Hi2gi,       too_many_1,    wrong_no_1},
    {"xread",                   CC_xread,       too_many_1,    wrong_no_1},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"sfto_davp",               too_few_2,      CC_sfto_davp,  wrong_no_2},
    {"ibalp_minclnr",           CC_ibalp_minclnr,too_many_1,   wrong_no_1},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"delallasc",               too_few_2,      CC_delallasc,  wrong_no_2},
    {"lpri",                    CC_lpri,        too_many_1,    wrong_no_1},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"mo_compare",              too_few_2,      CC_mo_compare, wrong_no_2},
    {"pv_renorm",               CC_pv_renorm,   too_many_1,    wrong_no_1},
    {"dv_skelhead",             CC_dv_skelhead, too_many_1,    wrong_no_1},
    {"mkrn",                    too_few_2,      CC_mkrn,       wrong_no_2},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"subs2f1",                 CC_subs2f1,     too_many_1,    wrong_no_1},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"maxdeg",                  too_few_2,      CC_maxdeg,     wrong_no_2},
    {"areallindices",           CC_areallindices,too_many_1,   wrong_no_1},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"bc=simp",                 CC_bcMsimp,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u05", (two_args *)"4933 8528349 1623259", 0}
};

/* end of generated code */