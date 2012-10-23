
/* $destdir\u18.c        Machine generated C code */

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


/* Code for rnprep!: */

static Lisp_Object CC_rnprepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0008, v0009;
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
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    fn = elt(env, 2); /* prepf */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    v0009 = v0007;
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0008 = qcdr(v0007);
    v0007 = (Lisp_Object)17; /* 1 */
    if (v0008 == v0007) { popv(4); return onevalue(v0009); }
    stack[-2] = elt(env, 1); /* quotient */
    stack[0] = v0009;
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    fn = elt(env, 2); /* prepf */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    {
        Lisp_Object v0011 = stack[-2];
        Lisp_Object v0012 = stack[0];
        popv(4);
        return list3(v0011, v0012, v0007);
    }
/* error exit handlers */
v0010:
    popv(4);
    return nil;
}



/* Code for di_insert */

static Lisp_Object MS_CDECL CC_di_insert(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0027, v0028;
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
        push3(v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0013,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0013;
    stack[-3] = v0000;
/* end of prologue */

v0029:
    v0026 = stack[-2];
    if (v0026 == nil) goto v0030;
    v0027 = stack[-3];
    v0026 = stack[-2];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    fn = elt(env, 2); /* eqdummy */
    v0026 = (*qfn2(fn))(qenv(fn), v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    if (v0026 == nil) goto v0032;
    v0026 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v0026;
    v0026 = stack[-2];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    v0026 = stack[-2];
    v0026 = qcar(v0026);
    v0028 = qcar(v0026);
    v0027 = stack[-3];
    v0026 = stack[-1];
    v0026 = acons(v0028, v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[-1] = v0026;
    v0026 = stack[0];
    stack[-2] = v0026;
    v0026 = stack[-4];
    stack[-3] = v0026;
    goto v0029;

v0032:
    v0026 = stack[-2];
    v0026 = qcdr(v0026);
    stack[-4] = v0026;
    v0026 = stack[-2];
    v0027 = qcar(v0026);
    v0026 = stack[-1];
    v0026 = cons(v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[-1] = v0026;
    v0026 = stack[-4];
    stack[-2] = v0026;
    goto v0029;

v0030:
    v0026 = stack[-3];
    if (v0026 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0027 = stack[-3];
    v0028 = qvalue(elt(env, 1)); /* nil */
    v0026 = stack[-1];
    popv(6);
    return acons(v0027, v0028, v0026);
/* error exit handlers */
v0031:
    popv(6);
    return nil;
}



/* Code for reducepowers */

static Lisp_Object CC_reducepowers(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reducepowers");
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

v0024:
    v0053 = stack[0];
    if (!consp(v0053)) goto v0055;
    v0053 = stack[0];
    v0053 = qcar(v0053);
    v0053 = (consp(v0053) ? nil : lisp_true);
    goto v0056;

v0056:
    if (v0053 == nil) goto v0021;
    v0053 = qvalue(elt(env, 1)); /* t */
    goto v0057;

v0057:
    if (!(v0053 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0053 = stack[0];
    v0053 = qcar(v0053);
    v0053 = qcar(v0053);
    v0054 = qcdr(v0053);
    v0053 = qvalue(elt(env, 2)); /* repowl!* */
    v0053 = qcar(v0053);
    v0053 = qcdr(v0053);
    if (equal(v0054, v0053)) goto v0058;
    v0053 = stack[0];
    v0053 = qcar(v0053);
    v0053 = qcar(v0053);
    stack[-1] = qcar(v0053);
    v0053 = stack[0];
    v0053 = qcar(v0053);
    v0053 = qcar(v0053);
    v0054 = qcdr(v0053);
    v0053 = qvalue(elt(env, 2)); /* repowl!* */
    v0053 = qcar(v0053);
    v0053 = qcdr(v0053);
    v0054 = difference2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0053 = (Lisp_Object)17; /* 1 */
    v0053 = acons(stack[-1], v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0054 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0053 = stack[0];
    v0053 = qcar(v0053);
    v0053 = qcdr(v0053);
    fn = elt(env, 3); /* multf */
    v0054 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0053 = qvalue(elt(env, 2)); /* repowl!* */
    v0053 = qcdr(v0053);
    fn = elt(env, 3); /* multf */
    v0054 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    fn = elt(env, 4); /* addf */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    stack[0] = v0053;
    goto v0024;

v0058:
    v0053 = qvalue(elt(env, 2)); /* repowl!* */
    v0054 = qcdr(v0053);
    v0053 = stack[0];
    v0053 = qcar(v0053);
    v0053 = qcdr(v0053);
    fn = elt(env, 3); /* multf */
    v0054 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    {
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v0054, v0053);
    }

v0021:
    v0053 = stack[0];
    v0053 = qcar(v0053);
    v0053 = qcar(v0053);
    v0054 = qcdr(v0053);
    v0053 = qvalue(elt(env, 2)); /* repowl!* */
    v0053 = qcar(v0053);
    v0053 = qcdr(v0053);
    v0053 = (Lisp_Object)lessp2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0053 = v0053 ? lisp_true : nil;
    env = stack[-2];
    goto v0057;

v0055:
    v0053 = qvalue(elt(env, 1)); /* t */
    goto v0056;
/* error exit handlers */
v0059:
    popv(3);
    return nil;
}



/* Code for general!-evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKevaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0075, v0076, v0077, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0013,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0013;
    stack[-3] = v0000;
/* end of prologue */

v0004:
    v0074 = stack[-3];
    if (!consp(v0074)) goto v0052;
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = (consp(v0074) ? nil : lisp_true);
    goto v0079;

v0079:
    if (!(v0074 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0075 = stack[-1];
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0080;
    v0074 = stack[-2];
    if (v0074 == nil) goto v0003;
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = qcar(v0074);
    v0075 = qcar(v0074);
    v0074 = stack[-2];
    if (equal(v0075, v0074)) goto v0049;
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    stack[-4] = qcar(v0074);
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0076 = qcdr(v0074);
    v0075 = stack[-2];
    v0074 = stack[-1];
    stack[0] = CC_generalKevaluateKmodKp(env, 3, v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    v0074 = stack[-3];
    v0076 = qcdr(v0074);
    v0075 = stack[-2];
    v0074 = stack[-1];
    v0074 = CC_generalKevaluateKmodKp(env, 3, v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    {
        Lisp_Object v0082 = stack[-4];
        Lisp_Object v0038 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0082, v0038, v0074);
    }

v0049:
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0078 = qcdr(v0074);
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = qcar(v0074);
    v0077 = qcdr(v0074);
    v0074 = stack[-3];
    v0076 = qcdr(v0074);
    v0075 = stack[-1];
    v0074 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* general!-horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v0078, v0077, v0076, v0075, v0074);
    }

v0003:
    v0074 = elt(env, 3); /* "Variable=NIL in GENERAL-EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0074);
    }

v0080:
    v0074 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0074;
    goto v0004;

v0052:
    v0074 = qvalue(elt(env, 1)); /* t */
    goto v0079;
/* error exit handlers */
v0081:
    popv(6);
    return nil;
}



/* Code for outref */

static Lisp_Object MS_CDECL CC_outref(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, Lisp_Object v0083, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0040, v0081, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "outref");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for outref");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0083,v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0013,v0014,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0083;
    stack[-6] = v0014;
    stack[-7] = v0013;
    stack[-8] = v0000;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* curfun!* */
    qvalue(elt(env, 1)) = nil; /* curfun!* */
    stack[-4] = qvalue(elt(env, 2)); /* calls!* */
    qvalue(elt(env, 2)) = nil; /* calls!* */
    stack[-3] = qvalue(elt(env, 3)); /* globs!* */
    qvalue(elt(env, 3)) = nil; /* globs!* */
    stack[-2] = qvalue(elt(env, 4)); /* locls!* */
    qvalue(elt(env, 4)) = nil; /* locls!* */
    stack[-1] = qvalue(elt(env, 5)); /* toplv!* */
    qvalue(elt(env, 5)) = nil; /* toplv!* */
    v0040 = stack[-7];
    v0043 = elt(env, 6); /* (anp!!atom anp!!idb anp!!eq anp!!unknown) */
    v0043 = Lmemq(nil, v0040, v0043);
    if (v0043 == nil) goto v0091;
    v0043 = qvalue(elt(env, 7)); /* nil */
    goto v0056;

v0056:
    stack[0] = v0043;
    v0082 = stack[-8];
    v0081 = stack[-5];
    v0043 = stack[0];
    if (v0043 == nil) goto v0072;
    v0043 = stack[0];
    goto v0051;

v0051:
    fn = elt(env, 13); /* outrdefun */
    v0043 = (*qfnn(fn))(qenv(fn), 3, v0082, v0081, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    stack[-8] = v0043;
    v0043 = stack[0];
    if (v0043 == nil) goto v0017;
    v0043 = stack[-7];
    fn = elt(env, 14); /* add2locs */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    v0043 = stack[-6];
    fn = elt(env, 15); /* anform */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    v0043 = stack[-7];
    fn = elt(env, 16); /* remlocs */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    goto v0093;

v0093:
    v0043 = stack[-8];
    fn = elt(env, 17); /* outrefend */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    v0043 = nil;
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    { popv(11); return onevalue(v0043); }

v0017:
    v0043 = stack[-6];
    if (v0043 == nil) goto v0047;
    v0043 = stack[-6];
    v0043 = Lsymbolp(nil, v0043);
    env = stack[-10];
    v0043 = (v0043 == nil ? lisp_true : nil);
    goto v0069;

v0069:
    if (!(v0043 == nil)) goto v0093;
    v0040 = stack[-7];
    v0043 = elt(env, 10); /* anp!!eq */
    if (v0040 == v0043) goto v0094;
    v0043 = stack[-6];
    fn = elt(env, 18); /* add2calls */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    goto v0093;

v0094:
    stack[-5] = stack[-8];
    stack[0] = elt(env, 11); /* sameas */
    v0043 = stack[-6];
    v0043 = ncons(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    v0043 = Lputprop(nil, 3, stack[-5], stack[0], v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    v0081 = stack[-6];
    v0040 = elt(env, 12); /* alsois */
    v0043 = stack[-8];
    fn = elt(env, 19); /* traput */
    v0043 = (*qfnn(fn))(qenv(fn), 3, v0081, v0040, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    goto v0093;

v0047:
    v0043 = qvalue(elt(env, 9)); /* t */
    goto v0069;

v0072:
    v0040 = stack[-6];
    v0043 = elt(env, 8); /* number!-of!-args */
    v0043 = get(v0040, v0043);
    env = stack[-10];
    goto v0051;

v0091:
    v0043 = stack[-7];
    v0043 = Llength(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-10];
    goto v0056;
/* error exit handlers */
v0092:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    popv(11);
    return nil;
}



/* Code for prepsq!* */

static Lisp_Object CC_prepsqH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0132, v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0000;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* !*combinelogs */
    qvalue(elt(env, 1)) = nil; /* !*combinelogs */
    v0131 = stack[-9];
    v0131 = qcar(v0131);
    if (v0131 == nil) goto v0050;
    v0131 = qvalue(elt(env, 2)); /* ordl!* */
    fn = elt(env, 16); /* setkorder */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-10] = v0131;
    v0131 = qvalue(elt(env, 3)); /* factors!* */
    stack[-7] = v0131;
    goto v0135;

v0135:
    v0131 = stack[-7];
    if (v0131 == nil) goto v0009;
    v0131 = stack[-7];
    v0131 = qcar(v0131);
    v0132 = v0131;
    v0131 = v0132;
    if (symbolp(v0131)) goto v0089;
    v0131 = qvalue(elt(env, 4)); /* nil */
    goto v0136;

v0136:
    stack[-6] = v0131;
    v0131 = stack[-6];
    fn = elt(env, 17); /* lastpair */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-5] = v0131;
    v0131 = stack[-7];
    v0131 = qcdr(v0131);
    stack[-7] = v0131;
    v0131 = stack[-5];
    if (!consp(v0131)) goto v0135;
    else goto v0137;

v0137:
    v0131 = stack[-7];
    if (v0131 == nil) goto v0138;
    stack[-4] = stack[-5];
    v0131 = stack[-7];
    v0131 = qcar(v0131);
    v0132 = v0131;
    if (symbolp(v0132)) goto v0139;
    v0131 = qvalue(elt(env, 4)); /* nil */
    goto v0140;

v0140:
    v0131 = Lrplacd(nil, stack[-4], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = stack[-5];
    fn = elt(env, 17); /* lastpair */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-5] = v0131;
    v0131 = stack[-7];
    v0131 = qcdr(v0131);
    stack[-7] = v0131;
    goto v0137;

v0139:
    v0133 = v0131;
    v0132 = elt(env, 5); /* prepsq!*fn */
    v0132 = get(v0133, v0132);
    env = stack[-11];
    v0133 = v0132;
    if (v0132 == nil) goto v0141;
    v0132 = stack[-9];
    v0131 = Lapply2(nil, 3, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    goto v0140;

v0141:
    v0132 = v0131;
    v0131 = elt(env, 6); /* klist */
    v0131 = get(v0132, v0131);
    env = stack[-11];
    stack[-3] = v0131;
    v0131 = stack[-3];
    if (v0131 == nil) goto v0142;
    v0131 = stack[-3];
    v0131 = qcar(v0131);
    v0131 = qcar(v0131);
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-1] = v0131;
    stack[-2] = v0131;
    goto v0143;

v0143:
    v0131 = stack[-3];
    v0131 = qcdr(v0131);
    stack[-3] = v0131;
    v0131 = stack[-3];
    if (v0131 == nil) goto v0144;
    stack[0] = stack[-1];
    v0131 = stack[-3];
    v0131 = qcar(v0131);
    v0131 = qcar(v0131);
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = Lrplacd(nil, stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    stack[-1] = v0131;
    goto v0143;

v0144:
    v0131 = stack[-2];
    goto v0140;

v0142:
    v0131 = qvalue(elt(env, 4)); /* nil */
    goto v0140;

v0138:
    v0131 = stack[-6];
    v0132 = v0131;
    goto v0091;

v0091:
    v0131 = elt(env, 7); /* ordop */
    fn = elt(env, 18); /* sort */
    stack[0] = (*qfn2(fn))(qenv(fn), v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0132 = qvalue(elt(env, 3)); /* factors!* */
    v0131 = elt(env, 7); /* ordop */
    fn = elt(env, 18); /* sort */
    v0132 = (*qfn2(fn))(qenv(fn), v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = qvalue(elt(env, 2)); /* ordl!* */
    v0131 = Lappend(nil, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = Lappend(nil, stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    fn = elt(env, 16); /* setkorder */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0132 = qvalue(elt(env, 8)); /* kord!* */
    v0131 = stack[-10];
    if (equal(v0132, v0131)) goto v0145;
    v0131 = qvalue(elt(env, 9)); /* t */
    goto v0146;

v0146:
    if (v0131 == nil) goto v0147;
    v0131 = stack[-9];
    v0131 = qcar(v0131);
    fn = elt(env, 19); /* formop */
    stack[0] = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = stack[-9];
    v0131 = qcdr(v0131);
    fn = elt(env, 19); /* formop */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = cons(stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-9] = v0131;
    goto v0147;

v0147:
    v0131 = qvalue(elt(env, 11)); /* !*rat */
    if (!(v0131 == nil)) goto v0148;
    v0131 = qvalue(elt(env, 12)); /* !*div */
    if (!(v0131 == nil)) goto v0148;
    v0131 = qvalue(elt(env, 13)); /* upl!* */
    if (!(v0131 == nil)) goto v0148;
    v0131 = qvalue(elt(env, 14)); /* dnl!* */
    if (!(v0131 == nil)) goto v0148;
    v0132 = stack[-9];
    v0131 = elt(env, 15); /* prepsq!*2 */
    fn = elt(env, 20); /* sqform */
    v0131 = (*qfn2(fn))(qenv(fn), v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    goto v0149;

v0149:
    stack[-9] = v0131;
    v0131 = stack[-10];
    fn = elt(env, 16); /* setkorder */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = stack[-9];
    goto v0004;

v0004:
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    { popv(12); return onevalue(v0131); }

v0148:
    v0131 = stack[-9];
    v0133 = qcar(v0131);
    v0131 = stack[-9];
    v0132 = qcdr(v0131);
    v0131 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 21); /* prepsq!*1 */
    v0131 = (*qfnn(fn))(qenv(fn), 3, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    fn = elt(env, 22); /* replus */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    goto v0149;

v0145:
    v0131 = qvalue(elt(env, 10)); /* wtl!* */
    goto v0146;

v0089:
    v0133 = v0132;
    v0131 = elt(env, 5); /* prepsq!*fn */
    v0131 = get(v0133, v0131);
    env = stack[-11];
    v0133 = v0131;
    if (v0131 == nil) goto v0150;
    v0131 = stack[-9];
    v0131 = Lapply2(nil, 3, v0133, v0131, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    goto v0136;

v0150:
    v0131 = elt(env, 6); /* klist */
    v0131 = get(v0132, v0131);
    env = stack[-11];
    stack[-3] = v0131;
    v0131 = stack[-3];
    if (v0131 == nil) goto v0094;
    v0131 = stack[-3];
    v0131 = qcar(v0131);
    v0131 = qcar(v0131);
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-1] = v0131;
    stack[-2] = v0131;
    goto v0151;

v0151:
    v0131 = stack[-3];
    v0131 = qcdr(v0131);
    stack[-3] = v0131;
    v0131 = stack[-3];
    if (v0131 == nil) goto v0152;
    stack[0] = stack[-1];
    v0131 = stack[-3];
    v0131 = qcar(v0131);
    v0131 = qcar(v0131);
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = Lrplacd(nil, stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    stack[-1] = v0131;
    goto v0151;

v0152:
    v0131 = stack[-2];
    goto v0136;

v0094:
    v0131 = qvalue(elt(env, 4)); /* nil */
    goto v0136;

v0009:
    v0131 = qvalue(elt(env, 4)); /* nil */
    v0132 = v0131;
    goto v0091;

v0050:
    v0131 = (Lisp_Object)1; /* 0 */
    goto v0004;
/* error exit handlers */
v0134:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    popv(12);
    return nil;
}



/* Code for sf2ss */

static Lisp_Object CC_sf2ss(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0048;
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
    v0155 = stack[-1];
    if (!consp(v0155)) goto v0079;
    v0155 = stack[-1];
    v0155 = qcar(v0155);
    v0155 = (consp(v0155) ? nil : lisp_true);
    goto v0030;

v0030:
    if (!(v0155 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0155 = stack[-1];
    fn = elt(env, 2); /* searchpl */
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    stack[-2] = v0155;
    v0155 = stack[-2];
    fn = elt(env, 3); /* qsort */
    stack[0] = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    v0155 = stack[-2];
    v0155 = Llength(nil, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    v0155 = cons(stack[0], v0155);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    stack[0] = v0155;
    v0048 = stack[-1];
    fn = elt(env, 4); /* sq2sspl */
    v0048 = (*qfn2(fn))(qenv(fn), v0048, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    v0155 = (Lisp_Object)17; /* 1 */
    v0155 = list2star(stack[0], v0048, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* lx2xx */
        return (*qfn1(fn))(qenv(fn), v0155);
    }

v0079:
    v0155 = qvalue(elt(env, 1)); /* t */
    goto v0030;
/* error exit handlers */
v0019:
    popv(4);
    return nil;
}



/* Code for ibalp_recalcv */

static Lisp_Object CC_ibalp_recalcv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_recalcv");
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
    v0035 = v0000;
/* end of prologue */
    stack[-2] = v0035;
    goto v0025;

v0025:
    v0035 = stack[-2];
    if (v0035 == nil) goto v0050;
    v0035 = stack[-2];
    v0035 = qcar(v0035);
    stack[-1] = v0035;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    stack[0] = qcdr(v0035);
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0086 = qcar(v0035);
    v0035 = elt(env, 2); /* 0.05 */
    v0035 = difference2(v0086, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v0035 = (*qfn2(fn))(qenv(fn), stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    stack[0] = qcdr(v0035);
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0086 = qcar(v0035);
    v0035 = elt(env, 2); /* 0.05 */
    v0035 = difference2(v0086, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v0035 = (*qfn2(fn))(qenv(fn), stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    v0035 = stack[-2];
    v0035 = qcdr(v0035);
    stack[-2] = v0035;
    goto v0025;

v0050:
    v0035 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0035); }
/* error exit handlers */
v0158:
    popv(4);
    return nil;
}



/* Code for aex_ids */

static Lisp_Object CC_aex_ids(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_ids");
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
    v0025 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_idl */
        return (*qfn1(fn))(qenv(fn), v0025);
    }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0163;
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
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0037 = v0013;
    stack[-3] = v0000;
/* end of prologue */
    v0037 = stack[-3];
    if (v0037 == nil) goto v0025;
    v0163 = stack[-3];
    v0037 = elt(env, 3); /* nochange */
    v0037 = Lflagpcar(nil, v0163, v0037);
    env = stack[-5];
    if (v0037 == nil) goto v0164;
    v0037 = stack[-3];
    v0163 = qcar(v0037);
    v0037 = elt(env, 4); /* getel */
    if (!(v0163 == v0037)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0164:
    v0163 = elt(env, 5); /* random */
    v0037 = stack[-3];
    fn = elt(env, 12); /* smember */
    v0037 = (*qfn2(fn))(qenv(fn), v0163, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    if (v0037 == nil) goto v0130;
    stack[-4] = elt(env, 6); /* lambda */
    stack[-2] = elt(env, 7); /* (!*uncached) */
    stack[-1] = elt(env, 8); /* progn */
    stack[0] = elt(env, 9); /* (declare (special !*uncached)) */
    v0163 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v0037 = stack[-3];
    v0037 = list2(v0163, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    v0037 = list3(stack[-1], stack[0], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    v0037 = list3(stack[-4], stack[-2], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    v0163 = qvalue(elt(env, 11)); /* t */
    popv(6);
    return list2(v0037, v0163);

v0130:
    v0163 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v0037 = stack[-3];
    popv(6);
    return list2(v0163, v0037);

v0025:
    v0037 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0037 == nil)) goto v0030;
    v0037 = elt(env, 2); /* "tell Hearn!!" */
    fn = elt(env, 13); /* lprie */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    goto v0030;

v0030:
    v0037 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    v0037 = nil;
    { popv(6); return onevalue(v0037); }
/* error exit handlers */
v0165:
    popv(6);
    return nil;
}



/* Code for crprimp */

static Lisp_Object CC_crprimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0012, v0128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprimp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0128 = v0000;
/* end of prologue */
    v0012 = v0128;
    v0011 = (Lisp_Object)17; /* 1 */
    if (v0012 == v0011) goto v0024;
    v0012 = v0128;
    v0011 = (Lisp_Object)-15; /* -1 */
    if (v0012 == v0011) goto v0167;
    v0011 = elt(env, 3); /* times */
    v0012 = v0128;
    v0128 = elt(env, 1); /* i */
    return list3(v0011, v0012, v0128);

v0167:
    v0011 = elt(env, 2); /* minus */
    v0012 = elt(env, 1); /* i */
    return list2(v0011, v0012);

v0024:
    v0011 = elt(env, 1); /* i */
    return onevalue(v0011);
}



/* Code for getdec */

static Lisp_Object CC_getdec(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getdec");
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
    v0090 = qvalue(elt(env, 1)); /* nil */
    v0166 = stack[0];
    fn = elt(env, 2); /* symtabget */
    v0166 = (*qfn2(fn))(qenv(fn), v0090, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    v0090 = v0166;
    v0166 = v0090;
    if (!(v0166 == nil)) { popv(2); return onevalue(v0090); }
    v0166 = stack[0];
    fn = elt(env, 3); /* implicitdec */
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    v0090 = v0166;
    { popv(2); return onevalue(v0090); }
/* error exit handlers */
v0167:
    popv(2);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0001, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for meq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    v0002 = stack[-1];
    fn = elt(env, 2); /* binding */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-2];
    v0001 = v0002;
    v0002 = v0001;
    if (v0002 == nil) goto v0091;
    v0002 = v0001;
    v0003 = elt(env, 1); /* unbound */
    if (v0002 == v0003) goto v0091;
    v0002 = v0001;
    v0001 = v0002;
    goto v0029;

v0029:
    v0002 = stack[0];
    v0002 = (equal(v0001, v0002) ? lisp_true : nil);
    { popv(3); return onevalue(v0002); }

v0091:
    v0002 = stack[-1];
    v0001 = v0002;
    goto v0029;
/* error exit handlers */
v0051:
    popv(3);
    return nil;
}



/* Code for r2findindex */

static Lisp_Object CC_r2findindex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0055, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0056 = v0013;
    v0055 = v0000;
/* end of prologue */
    v0168 = v0055;
    v0055 = v0056;
    v0056 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* r2findindex1 */
        return (*qfnn(fn))(qenv(fn), 3, v0168, v0055, v0056);
    }
}



/* Code for inttovec!-solve */

static Lisp_Object CC_inttovecKsolve(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec-solve");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0013;
    stack[-3] = v0000;
/* end of prologue */
    v0171 = stack[-2];
    v0170 = (Lisp_Object)1; /* 0 */
    if (v0171 == v0170) goto v0050;
    v0171 = stack[-3];
    v0170 = (Lisp_Object)17; /* 1 */
    v0170 = (v0171 == v0170 ? lisp_true : nil);
    goto v0029;

v0029:
    if (v0170 == nil) goto v0007;
    v0171 = stack[-2];
    v0170 = (Lisp_Object)1; /* 0 */
    popv(6);
    return cons(v0171, v0170);

v0007:
    v0170 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0170;
    v0170 = (Lisp_Object)17; /* 1 */
    stack[0] = v0170;
    goto v0071;

v0071:
    v0170 = stack[0];
    stack[-1] = v0170;
    v0170 = stack[-4];
    v0170 = add1(v0170);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    stack[-4] = v0170;
    v0171 = stack[-3];
    v0170 = stack[-4];
    v0171 = plus2(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    v0170 = stack[-1];
    v0171 = times2(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    v0170 = stack[-4];
    v0170 = quot2(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    stack[0] = v0170;
    v0171 = stack[0];
    v0170 = stack[-2];
    v0170 = (Lisp_Object)greaterp2(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    v0170 = v0170 ? lisp_true : nil;
    env = stack[-5];
    if (v0170 == nil) goto v0071;
    stack[0] = stack[-4];
    v0171 = stack[-2];
    v0170 = stack[-1];
    v0170 = difference2(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    {
        Lisp_Object v0063 = stack[0];
        popv(6);
        return cons(v0063, v0170);
    }

v0050:
    v0170 = qvalue(elt(env, 1)); /* t */
    goto v0029;
/* error exit handlers */
v0062:
    popv(6);
    return nil;
}



/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0128, v0136, v0071, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0071 = v0013;
    v0072 = v0000;
/* end of prologue */
    v0012 = qvalue(elt(env, 1)); /* kord!* */
    v0136 = v0012;
    goto v0004;

v0004:
    v0012 = v0136;
    if (v0012 == nil) goto v0056;
    v0128 = v0072;
    v0012 = v0136;
    v0012 = qcar(v0012);
    if (v0128 == v0012) goto v0166;
    v0128 = v0071;
    v0012 = v0136;
    v0012 = qcar(v0012);
    if (v0128 == v0012) goto v0001;
    v0012 = v0136;
    v0012 = qcdr(v0012);
    v0136 = v0012;
    goto v0004;

v0001:
    v0012 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0012);

v0166:
    v0012 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0012);

v0056:
    v0012 = v0072;
    v0128 = v0071;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0012, v0128);
    }
}



/* Code for contr */

static Lisp_Object CC_contr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0004;

v0004:
    v0135 = stack[0];
    if (v0135 == nil) goto v0050;
    v0137 = stack[-1];
    v0135 = stack[0];
    v0135 = qcar(v0135);
    fn = elt(env, 1); /* split!-road */
    v0137 = (*qfn2(fn))(qenv(fn), v0137, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    v0135 = stack[-2];
    v0135 = cons(v0137, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    stack[-2] = v0135;
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0004;

v0050:
    v0135 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0135);
    }
/* error exit handlers */
v0009:
    popv(4);
    return nil;
}



/* Code for assert_error */

static Lisp_Object MS_CDECL CC_assert_error(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, Lisp_Object v0083,
                         Lisp_Object v0024, Lisp_Object v0025, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0174, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "assert_error");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_error");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0025,v0024,v0083,v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0013,v0014,v0083,v0024,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0025;
    v0113 = v0024;
    stack[-2] = v0083;
    stack[-3] = v0014;
    stack[-4] = v0013;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v0113 = qvalue(elt(env, 2)); /* !*assertstatistics */
    if (v0113 == nil) goto v0012;
    v0174 = stack[-5];
    v0113 = qvalue(elt(env, 3)); /* assertstatistics!* */
    v0113 = Latsoc(nil, v0174, v0113);
    v0113 = qcdr(v0113);
    v0174 = v0113;
    v0113 = v0174;
    v0113 = qcdr(v0113);
    stack[0] = qcdr(v0113);
    v0113 = v0174;
    v0113 = qcdr(v0113);
    v0113 = qcdr(v0113);
    v0113 = qcar(v0113);
    v0113 = add1(v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    fn = elt(env, 13); /* setcar */
    v0113 = (*qfn2(fn))(qenv(fn), stack[0], v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    goto v0012;

v0012:
    v0174 = stack[-2];
    v0113 = (Lisp_Object)1; /* 0 */
    v0113 = Leqn(nil, v0174, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    if (v0113 == nil) goto v0028;
    stack[0] = elt(env, 4); /* "declaration" */
    v0175 = stack[-5];
    v0174 = stack[-4];
    v0113 = stack[-3];
    fn = elt(env, 14); /* assert_format */
    v0175 = (*qfnn(fn))(qenv(fn), 3, v0175, v0174, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    v0174 = elt(env, 5); /* "violated by result" */
    v0113 = stack[-1];
    v0113 = list4(stack[0], v0175, v0174, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    goto v0020;

v0020:
    v0174 = qvalue(elt(env, 8)); /* !*assertbreak */
    if (v0174 == nil) goto v0177;
    v0174 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v0174 == nil)) goto v0178;
    fn = elt(env, 15); /* lprie */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    goto v0178;

v0178:
    v0113 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    goto v0179;

v0179:
    v0113 = nil;
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    { popv(8); return onevalue(v0113); }

v0177:
    v0174 = qvalue(elt(env, 10)); /* !*msg */
    if (v0174 == nil) goto v0179;
    v0174 = elt(env, 12); /* "***" */
    fn = elt(env, 16); /* lpriw */
    v0113 = (*qfn2(fn))(qenv(fn), v0174, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    goto v0179;

v0028:
    stack[0] = elt(env, 4); /* "declaration" */
    v0175 = stack[-5];
    v0174 = stack[-4];
    v0113 = stack[-3];
    fn = elt(env, 14); /* assert_format */
    stack[-4] = (*qfnn(fn))(qenv(fn), 3, v0175, v0174, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    stack[-3] = elt(env, 6); /* "violated by" */
    v0174 = elt(env, 7); /* arg */
    v0113 = stack[-2];
    fn = elt(env, 17); /* mkid */
    v0174 = (*qfn2(fn))(qenv(fn), v0174, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    v0113 = stack[-1];
    v0113 = list2(v0174, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    v0113 = list3star(stack[0], stack[-4], stack[-3], v0113);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-7];
    goto v0020;
/* error exit handlers */
v0176:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    popv(8);
    return nil;
}



/* Code for setelv */

static Lisp_Object CC_setelv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setelv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0013;
    v0058 = v0000;
/* end of prologue */
    v0044 = v0058;
    stack[-5] = qcar(v0044);
    v0044 = v0058;
    v0044 = qcdr(v0044);
    stack[-3] = v0044;
    v0044 = stack[-3];
    if (v0044 == nil) goto v0022;
    v0044 = stack[-3];
    v0044 = qcar(v0044);
    fn = elt(env, 2); /* reval_without_mod */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-6];
    v0044 = ncons(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-6];
    stack[-1] = v0044;
    stack[-2] = v0044;
    goto v0090;

v0090:
    v0044 = stack[-3];
    v0044 = qcdr(v0044);
    stack[-3] = v0044;
    v0044 = stack[-3];
    if (v0044 == nil) goto v0020;
    stack[0] = stack[-1];
    v0044 = stack[-3];
    v0044 = qcar(v0044);
    fn = elt(env, 2); /* reval_without_mod */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-6];
    v0044 = ncons(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-6];
    v0044 = Lrplacd(nil, stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-6];
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    stack[-1] = v0044;
    goto v0090;

v0020:
    v0044 = stack[-2];
    goto v0052;

v0052:
    v0058 = cons(stack[-5], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-6];
    v0044 = stack[-4];
    {
        popv(7);
        fn = elt(env, 3); /* setel */
        return (*qfn2(fn))(qenv(fn), v0058, v0044);
    }

v0022:
    v0044 = qvalue(elt(env, 1)); /* nil */
    goto v0052;
/* error exit handlers */
v0087:
    popv(7);
    return nil;
}



/* Code for fs!:times */

static Lisp_Object CC_fsTtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    v0071 = stack[-1];
    if (v0071 == nil) goto v0025;
    v0071 = stack[0];
    if (v0071 == nil) goto v0050;
    v0072 = stack[-1];
    v0071 = stack[0];
    fn = elt(env, 2); /* fs!:timesterm */
    v0071 = (*qfn2(fn))(qenv(fn), v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    stack[-2] = v0071;
    v0072 = stack[-1];
    v0071 = (Lisp_Object)49; /* 3 */
    v0072 = *(Lisp_Object *)((char *)v0072 + (CELL-TAG_VECTOR) + ((int32_t)v0071/(16/CELL)));
    v0071 = stack[0];
    v0071 = CC_fsTtimes(env, v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    {
        Lisp_Object v0048 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0048, v0071);
    }

v0050:
    v0071 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0071); }

v0025:
    v0071 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0071); }
/* error exit handlers */
v0155:
    popv(4);
    return nil;
}



/* Code for dpmat_coldegs */

static Lisp_Object CC_dpmat_coldegs(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpmat_coldegs");
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
    v0030 = v0000;
/* end of prologue */
    v0079 = v0030;
    v0030 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v0030 = (*qfn2(fn))(qenv(fn), v0079, v0030);
    errexit();
    v0030 = qcar(v0030);
    return onevalue(v0030);
}



/* Code for evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_evaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0075, v0076, v0077, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0013,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0013;
    stack[-3] = v0000;
/* end of prologue */

v0004:
    v0074 = stack[-3];
    if (!consp(v0074)) goto v0052;
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = (consp(v0074) ? nil : lisp_true);
    goto v0079;

v0079:
    if (!(v0074 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0075 = stack[-1];
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0080;
    v0074 = stack[-2];
    if (v0074 == nil) goto v0003;
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = qcar(v0074);
    v0075 = qcar(v0074);
    v0074 = stack[-2];
    if (equal(v0075, v0074)) goto v0049;
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    stack[-4] = qcar(v0074);
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0076 = qcdr(v0074);
    v0075 = stack[-2];
    v0074 = stack[-1];
    stack[0] = CC_evaluateKmodKp(env, 3, v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    v0074 = stack[-3];
    v0076 = qcdr(v0074);
    v0075 = stack[-2];
    v0074 = stack[-1];
    v0074 = CC_evaluateKmodKp(env, 3, v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    {
        Lisp_Object v0082 = stack[-4];
        Lisp_Object v0038 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0082, v0038, v0074);
    }

v0049:
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0078 = qcdr(v0074);
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = qcar(v0074);
    v0077 = qcdr(v0074);
    v0074 = stack[-3];
    v0076 = qcdr(v0074);
    v0075 = stack[-1];
    v0074 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v0078, v0077, v0076, v0075, v0074);
    }

v0003:
    v0074 = elt(env, 3); /* "Variable=NIL in EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0074);
    }

v0080:
    v0074 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0074;
    goto v0004;

v0052:
    v0074 = qvalue(elt(env, 1)); /* t */
    goto v0079;
/* error exit handlers */
v0081:
    popv(6);
    return nil;
}



/* Code for mkfil!* */

static Lisp_Object CC_mkfilH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0068, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfil*");
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
    v0161 = nil;
    v0032 = stack[0];
    v0032 = Lstringp(nil, v0032);
    env = stack[-2];
    if (!(v0032 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0032 = stack[0];
    if (symbolp(v0032)) goto v0073;
    v0068 = stack[0];
    v0032 = elt(env, 1); /* "file name" */
    {
        popv(3);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0068, v0032);
    }

v0073:
    v0068 = stack[0];
    v0032 = elt(env, 2); /* share */
    v0032 = Lflagp(nil, v0068, v0032);
    env = stack[-2];
    if (v0032 == nil) goto v0088;
    v0032 = stack[0];
    fn = elt(env, 7); /* eval */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0161 = v0032;
    v0032 = Lstringp(nil, v0032);
    env = stack[-2];
    goto v0091;

v0091:
    if (!(v0032 == nil)) { popv(3); return onevalue(v0161); }
    stack[-1] = elt(env, 4); /* !" */
    v0032 = stack[0];
    fn = elt(env, 8); /* explode2lc */
    v0068 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0032 = elt(env, 5); /* (!") */
    v0032 = Lappend(nil, v0068, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0032 = cons(stack[-1], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0046;
        popv(3);
        return Lcompress(nil, v0032);

v0088:
    v0032 = qvalue(elt(env, 3)); /* nil */
    goto v0091;
/* error exit handlers */
v0046:
    popv(3);
    return nil;
}



/* Code for sq2sstm */

static Lisp_Object CC_sq2sstm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0063, v0074;
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
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0013;
    v0074 = v0000;
/* end of prologue */
    v0062 = v0074;
    v0062 = qcar(v0062);
    v0063 = qcar(v0062);
    v0062 = stack[-2];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    if (equal(v0063, v0062)) goto v0057;
    v0062 = v0074;
    stack[-1] = ncons(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0062 = stack[-2];
    v0062 = qcar(v0062);
    stack[0] = qcdr(v0062);
    v0062 = stack[-2];
    v0062 = qcdr(v0062);
    v0062 = sub1(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0062 = cons(stack[0], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v0062 = (*qfn2(fn))(qenv(fn), stack[-1], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0063 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0063;
    goto v0170;

v0170:
    v0063 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* mapins */
        return (*qfn2(fn))(qenv(fn), v0063, v0062);
    }

v0057:
    v0062 = v0074;
    v0062 = qcdr(v0062);
    stack[0] = v0062;
    v0062 = v0074;
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    stack[-3] = v0062;
    v0062 = stack[0];
    if (!consp(v0062)) goto v0135;
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = (consp(v0062) ? nil : lisp_true);
    goto v0003;

v0003:
    if (v0062 == nil) goto v0018;
    stack[-1] = stack[-3];
    v0062 = stack[-2];
    v0062 = qcdr(v0062);
    fn = elt(env, 4); /* mkzl */
    v0063 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0062 = stack[0];
    v0062 = acons(stack[-1], v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    popv(5);
    return ncons(v0062);

v0018:
    stack[-1] = stack[0];
    v0062 = stack[-2];
    v0062 = qcar(v0062);
    stack[0] = qcdr(v0062);
    v0062 = stack[-2];
    v0062 = qcdr(v0062);
    v0062 = sub1(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0062 = cons(stack[0], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v0062 = (*qfn2(fn))(qenv(fn), stack[-1], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    goto v0170;

v0135:
    v0062 = qvalue(elt(env, 1)); /* t */
    goto v0003;
/* error exit handlers */
v0042:
    popv(5);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, Lisp_Object v0083,
                         Lisp_Object v0024, Lisp_Object v0025, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0183, v0177;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0025,v0024,v0083,v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0013,v0014,v0083,v0024,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0025;
    stack[-4] = v0024;
    stack[-5] = v0083;
    stack[-6] = v0014;
    stack[-7] = v0013;
    stack[-8] = v0000;
/* end of prologue */

v0005:
    v0054 = stack[-7];
    v0053 = (Lisp_Object)17; /* 1 */
    if (v0054 == v0053) goto v0073;
    v0054 = stack[-6];
    v0053 = stack[-5];
    v0053 = (Lisp_Object)greaterp2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0053 = v0053 ? lisp_true : nil;
    env = stack[-10];
    if (!(v0053 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0054 = stack[-8];
    v0053 = stack[-6];
    v0053 = difference2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    stack[-9] = v0053;
    v0053 = stack[-7];
    v0053 = sub1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    stack[-2] = v0053;
    v0054 = stack[-8];
    v0053 = stack[-6];
    stack[0] = difference2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    v0053 = stack[-7];
    v0053 = sub1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    v0053 = quot2(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    stack[-1] = v0053;
    v0054 = stack[-6];
    v0053 = stack[-4];
    v0053 = cons(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    stack[0] = v0053;
    v0053 = stack[-6];
    v0177 = add1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    v0183 = stack[-5];
    v0054 = stack[-4];
    v0053 = stack[-3];
    v0053 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v0177, v0183, v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    stack[-3] = v0053;
    v0053 = stack[0];
    stack[-4] = v0053;
    v0053 = stack[-1];
    stack[-5] = v0053;
    v0053 = stack[-2];
    stack[-7] = v0053;
    v0053 = stack[-9];
    stack[-8] = v0053;
    goto v0005;

v0073:
    v0054 = stack[-8];
    v0053 = stack[-6];
    v0053 = (Lisp_Object)geq2(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0053 = v0053 ? lisp_true : nil;
    env = stack[-10];
    if (v0053 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0054 = stack[-8];
    v0053 = stack[-4];
    v0053 = cons(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-10];
    v0054 = Lreverse(nil, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0053 = stack[-3];
    popv(11);
    return cons(v0054, v0053);
/* error exit handlers */
v0184:
    popv(11);
    return nil;
}



/* Code for sfto_sqfpartf */

static Lisp_Object CC_sfto_sqfpartf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_sqfpartf");
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
    v0161 = stack[-3];
    if (!consp(v0161)) goto v0079;
    v0161 = stack[-3];
    v0161 = qcar(v0161);
    v0161 = (consp(v0161) ? nil : lisp_true);
    goto v0030;

v0030:
    if (v0161 == nil) goto v0084;
    v0161 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v0161); }

v0084:
    v0161 = stack[-3];
    fn = elt(env, 2); /* sfto_ucontentf */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-5];
    stack[0] = v0161;
    v0156 = stack[-3];
    v0161 = stack[0];
    fn = elt(env, 3); /* quotf */
    v0161 = (*qfn2(fn))(qenv(fn), v0156, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-5];
    stack[-4] = v0161;
    v0161 = stack[0];
    stack[-2] = CC_sfto_sqfpartf(env, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-4];
    v0156 = stack[-4];
    v0161 = stack[-3];
    v0161 = qcar(v0161);
    v0161 = qcar(v0161);
    v0161 = qcar(v0161);
    fn = elt(env, 4); /* diff */
    v0161 = (*qfn2(fn))(qenv(fn), v0156, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-5];
    fn = elt(env, 5); /* sfto_gcdf!* */
    v0161 = (*qfn2(fn))(qenv(fn), stack[0], v0161);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-5];
    fn = elt(env, 3); /* quotf */
    v0161 = (*qfn2(fn))(qenv(fn), stack[-1], v0161);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-5];
    {
        Lisp_Object v0045 = stack[-2];
        popv(6);
        fn = elt(env, 6); /* multf */
        return (*qfn2(fn))(qenv(fn), v0045, v0161);
    }

v0079:
    v0161 = qvalue(elt(env, 1)); /* t */
    goto v0030;
/* error exit handlers */
v0070:
    popv(6);
    return nil;
}



/* Code for simpexpt */

static Lisp_Object CC_simpexpt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0011, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt");
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
    v0010 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v0010; /* kord!* */
    v0010 = stack[0];
    v0011 = qcdr(v0010);
    v0010 = elt(env, 3); /* expt */
    fn = elt(env, 6); /* carx */
    v0011 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    v0010 = elt(env, 4); /* simp!* */
    fn = elt(env, 7); /* simpexpon1 */
    v0010 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    v0011 = v0010;
    v0010 = elt(env, 5); /* resimp */
    fn = elt(env, 7); /* simpexpon1 */
    v0010 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    v0011 = stack[0];
    v0012 = qcar(v0011);
    v0011 = v0010;
    v0010 = qvalue(elt(env, 1)); /* nil */
    {
        popv(3);
        fn = elt(env, 8); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v0012, v0011, v0010);
    }
/* error exit handlers */
v0072:
    popv(3);
    return nil;
v0071:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    popv(3);
    return nil;
}



/* Code for tayexp!-times2 */

static Lisp_Object CC_tayexpKtimes2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0188, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-times2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    v0187 = stack[-1];
    if (!consp(v0187)) goto v0050;
    v0187 = qvalue(elt(env, 1)); /* nil */
    goto v0029;

v0029:
    if (v0187 == nil) goto v0180;
    v0188 = stack[-1];
    v0187 = stack[0];
    popv(4);
    return times2(v0188, v0187);

v0180:
    v0187 = stack[-1];
    if (!consp(v0187)) goto v0003;
    v0187 = stack[0];
    if (!consp(v0187)) goto v0027;
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0188 = qcar(v0187);
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    stack[-2] = times2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0188 = qcdr(v0187);
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0187 = times2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v0187 = (*qfn2(fn))(qenv(fn), stack[-2], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    goto v0021;

v0021:
    v0125 = v0187;
    v0187 = v0125;
    v0187 = qcdr(v0187);
    v0188 = qcdr(v0187);
    v0187 = (Lisp_Object)17; /* 1 */
    if (!(v0188 == v0187)) { popv(4); return onevalue(v0125); }
    v0187 = v0125;
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    { popv(4); return onevalue(v0187); }

v0027:
    v0125 = elt(env, 2); /* !:rn!: */
    v0188 = stack[0];
    v0187 = (Lisp_Object)17; /* 1 */
    v0187 = list2star(v0125, v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    stack[-2] = v0187;
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0188 = qcar(v0187);
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    stack[0] = times2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0188 = qcdr(v0187);
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0187 = times2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v0187 = (*qfn2(fn))(qenv(fn), stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    goto v0021;

v0003:
    v0125 = elt(env, 2); /* !:rn!: */
    v0188 = stack[-1];
    v0187 = (Lisp_Object)17; /* 1 */
    v0187 = list2star(v0125, v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    stack[-2] = v0187;
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0188 = qcar(v0187);
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    stack[-1] = times2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0188 = qcdr(v0187);
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0187 = times2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v0187 = (*qfn2(fn))(qenv(fn), stack[-1], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    goto v0021;

v0050:
    v0187 = stack[0];
    v0187 = (consp(v0187) ? nil : lisp_true);
    goto v0029;
/* error exit handlers */
v0189:
    popv(4);
    return nil;
}



/* Code for mk!+unit!+mat */

static Lisp_Object CC_mkLunitLmat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* gen!+can!+bas */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
}



/* Code for ibalp_negateat */

static Lisp_Object CC_ibalp_negateat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negateat");
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
    v0169 = stack[-1];
    fn = elt(env, 1); /* ibalp_op */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    v0169 = stack[-1];
    fn = elt(env, 2); /* ibalp_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    v0169 = stack[-1];
    fn = elt(env, 3); /* ibalp_arg2r */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    fn = elt(env, 4); /* ibalp_negatet */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    {
        Lisp_Object v0090 = stack[-2];
        Lisp_Object v0080 = stack[0];
        popv(4);
        fn = elt(env, 5); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0090, v0080, v0169);
    }
/* error exit handlers */
v0166:
    popv(4);
    return nil;
}



/* Code for cgp_number */

static Lisp_Object CC_cgp_number(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_number");
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
    v0030 = v0000;
/* end of prologue */
    v0079 = v0030;
    v0030 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v0030 = (*qfn2(fn))(qenv(fn), v0079, v0030);
    errexit();
    v0030 = qcar(v0030);
    return onevalue(v0030);
}



/* Code for reln */

static Lisp_Object CC_reln(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reln");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    v0003 = elt(env, 1); /* "<reln>" */
    fn = elt(env, 6); /* printout */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    v0003 = elt(env, 2); /* "<" */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    v0003 = stack[0];
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    v0003 = elt(env, 3); /* "/>" */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    v0135 = qvalue(elt(env, 4)); /* indent */
    v0003 = (Lisp_Object)49; /* 3 */
    v0003 = plus2(v0135, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0003; /* indent */
    v0003 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    v0135 = qvalue(elt(env, 4)); /* indent */
    v0003 = (Lisp_Object)49; /* 3 */
    v0003 = difference2(v0135, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0003; /* indent */
    v0003 = elt(env, 5); /* "</reln>" */
    fn = elt(env, 6); /* printout */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    v0003 = nil;
    { popv(3); return onevalue(v0003); }
/* error exit handlers */
v0007:
    popv(3);
    return nil;
}



/* Code for dipprodin1 */

static Lisp_Object MS_CDECL CC_dipprodin1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0018;
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
        push3(v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0013,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0013;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0084;

v0084:
    v0017 = stack[0];
    if (v0017 == nil) goto v0056;
    v0018 = stack[-1];
    v0017 = stack[0];
    v0017 = qcar(v0017);
    fn = elt(env, 2); /* evsum */
    v0018 = (*qfn2(fn))(qenv(fn), v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    v0017 = stack[-3];
    v0017 = cons(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    stack[-3] = v0017;
    v0018 = stack[-2];
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = qcar(v0017);
    fn = elt(env, 3); /* bcprod */
    v0018 = (*qfn2(fn))(qenv(fn), v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    v0017 = stack[-3];
    v0017 = cons(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    stack[-3] = v0017;
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = qcdr(v0017);
    stack[0] = v0017;
    goto v0084;

v0056:
    v0018 = stack[-3];
    v0017 = qvalue(elt(env, 1)); /* dipzero */
    {
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0018, v0017);
    }
/* error exit handlers */
v0161:
    popv(5);
    return nil;
}



/* Code for expvec2a */

static Lisp_Object CC_expvec2a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expvec2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0057 = v0000;
/* end of prologue */
    v0030 = v0057;
    v0057 = qvalue(elt(env, 1)); /* dipvars!* */
    {
        fn = elt(env, 2); /* expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v0030, v0057);
    }
}



/* Code for pfordp */

static Lisp_Object CC_pfordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0181, v0093, v0019, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pfordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0093 = v0013;
    v0019 = v0000;
/* end of prologue */

v0025:
    v0181 = v0019;
    if (v0181 == nil) goto v0029;
    v0181 = v0093;
    if (v0181 == nil) goto v0168;
    v0181 = v0019;
    v0181 = qcar(v0181);
    v0017 = qcar(v0181);
    v0181 = v0093;
    v0181 = qcar(v0181);
    v0181 = qcar(v0181);
    if (v0017 == v0181) goto v0154;
    v0181 = v0019;
    v0181 = qcar(v0181);
    v0181 = qcar(v0181);
    v0093 = qcar(v0093);
    v0093 = qcar(v0093);
    {
        fn = elt(env, 2); /* termordp */
        return (*qfn2(fn))(qenv(fn), v0181, v0093);
    }

v0154:
    v0181 = v0019;
    v0181 = qcdr(v0181);
    v0019 = v0181;
    v0181 = v0093;
    v0181 = qcdr(v0181);
    v0093 = v0181;
    goto v0025;

v0168:
    v0181 = v0019;
    v0181 = qcar(v0181);
    v0093 = qcar(v0181);
    v0181 = (Lisp_Object)17; /* 1 */
        return Lneq(nil, v0093, v0181);

v0029:
    v0181 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0181);
}



/* Code for rd!:times */

static Lisp_Object CC_rdTtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0198, v0199, v0200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    v0198 = qvalue(elt(env, 1)); /* nil */
    v0199 = v0198;
    v0198 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v0198 == nil) goto v0030;
    v0198 = qvalue(elt(env, 1)); /* nil */
    goto v0057;

v0057:
    if (v0198 == nil) goto v0018;
    v0198 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v0198, v0199);

v0018:
    v0199 = stack[-1];
    v0198 = stack[0];
    fn = elt(env, 8); /* convprc2 */
    v0198 = (*qfn2(fn))(qenv(fn), v0199, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[-3] = v0198;
    v0198 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v0198;
    v0198 = stack[-3];
    if (!consp(v0198)) goto v0159;
    v0199 = stack[-3];
    v0198 = stack[-2];
    fn = elt(env, 9); /* csl_timbf */
    v0198 = (*qfn2(fn))(qenv(fn), v0199, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0087;

v0087:
    v0199 = v0198;
    v0198 = v0199;
    if (!(!consp(v0198))) { popv(5); return onevalue(v0199); }
    v0198 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v0198, v0199);

v0159:
    stack[-1] = elt(env, 5); /* times2 */
    v0198 = stack[-3];
    stack[0] = Lmkquote(nil, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0198 = stack[-2];
    v0198 = Lmkquote(nil, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0200 = list3(stack[-1], stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0199 = qvalue(elt(env, 1)); /* nil */
    v0198 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 10); /* errorset */
    v0198 = (*qfnn(fn))(qenv(fn), 3, v0200, v0199, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0199 = v0198;
    v0198 = v0199;
    if (!consp(v0198)) goto v0075;
    v0198 = v0199;
    v0198 = qcdr(v0198);
    goto v0074;

v0074:
    if (v0198 == nil) goto v0202;
    fn = elt(env, 11); /* rndbfon */
    v0198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0198 = stack[-3];
    v0198 = Lfloatp(nil, v0198);
    env = stack[-4];
    if (v0198 == nil) goto v0138;
    v0198 = stack[-3];
    fn = elt(env, 12); /* fl2bf */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0198;
    goto v0178;

v0178:
    v0198 = stack[-2];
    v0198 = Lfloatp(nil, v0198);
    env = stack[-4];
    if (v0198 == nil) goto v0187;
    v0198 = stack[-2];
    fn = elt(env, 12); /* fl2bf */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0036;

v0036:
    fn = elt(env, 9); /* csl_timbf */
    v0198 = (*qfn2(fn))(qenv(fn), stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0087;

v0187:
    v0198 = stack[-2];
    if (!consp(v0198)) goto v0189;
    v0198 = stack[-2];
    goto v0124;

v0124:
    fn = elt(env, 13); /* csl_normbf */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0036;

v0189:
    v0198 = stack[-2];
    v0198 = integerp(v0198);
    if (v0198 == nil) goto v0203;
    v0200 = elt(env, 3); /* !:rd!: */
    v0199 = stack[-2];
    v0198 = (Lisp_Object)1; /* 0 */
    v0198 = list2star(v0200, v0199, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0124;

v0203:
    v0198 = stack[-2];
    fn = elt(env, 14); /* read!:num */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0124;

v0138:
    v0198 = stack[-3];
    if (!consp(v0198)) goto v0204;
    v0198 = stack[-3];
    goto v0185;

v0185:
    fn = elt(env, 13); /* csl_normbf */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0198;
    goto v0178;

v0204:
    v0198 = stack[-3];
    v0198 = integerp(v0198);
    if (v0198 == nil) goto v0176;
    v0200 = elt(env, 3); /* !:rd!: */
    v0199 = stack[-3];
    v0198 = (Lisp_Object)1; /* 0 */
    v0198 = list2star(v0200, v0199, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0185;

v0176:
    v0198 = stack[-3];
    fn = elt(env, 14); /* read!:num */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0185;

v0202:
    v0198 = v0199;
    v0198 = qcar(v0198);
    goto v0087;

v0075:
    v0198 = qvalue(elt(env, 7)); /* t */
    goto v0074;

v0030:
    v0198 = stack[-1];
    v0198 = qcdr(v0198);
    if (!consp(v0198)) goto v0168;
    v0198 = qvalue(elt(env, 1)); /* nil */
    goto v0057;

v0168:
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    if (!consp(v0198)) goto v0022;
    v0198 = qvalue(elt(env, 1)); /* nil */
    goto v0057;

v0022:
    v0198 = stack[-1];
    v0199 = qcdr(v0198);
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    fn = elt(env, 15); /* safe!-fp!-times */
    v0198 = (*qfn2(fn))(qenv(fn), v0199, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0199 = v0198;
    goto v0057;
/* error exit handlers */
v0201:
    popv(5);
    return nil;
}



/* Code for factorial */

static Lisp_Object CC_factorial(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorial");
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
    v0136 = stack[0];
    v0136 = integerp(v0136);
    if (v0136 == nil) goto v0029;
    v0071 = stack[0];
    v0136 = (Lisp_Object)1; /* 0 */
    v0136 = (Lisp_Object)lessp2(v0071, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0136 = v0136 ? lisp_true : nil;
    env = stack[-1];
    goto v0084;

v0084:
    if (v0136 == nil) goto v0010;
    v0071 = stack[0];
    v0136 = elt(env, 2); /* "invalid factorial argument" */
    v0136 = list2(v0071, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-1];
    v0071 = v0136;
    v0136 = v0071;
    qvalue(elt(env, 3)) = v0136; /* errmsg!* */
    v0136 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0136 == nil)) goto v0051;
    v0136 = v0071;
    fn = elt(env, 5); /* lprie */
    v0136 = (*qfn1(fn))(qenv(fn), v0136);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-1];
    goto v0051;

v0051:
    v0136 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0136 = nil;
    { popv(2); return onevalue(v0136); }

v0010:
    v0136 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* nfactorial */
        return (*qfn1(fn))(qenv(fn), v0136);
    }

v0029:
    v0136 = qvalue(elt(env, 1)); /* t */
    goto v0084;
/* error exit handlers */
v0154:
    popv(2);
    return nil;
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0013,
                         Lisp_Object v0014, Lisp_Object v0083, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0205, v0094, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0083,v0014,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0013,v0014,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0083;
    stack[-1] = v0014;
    stack[-2] = v0013;
    stack[-3] = v0000;
/* end of prologue */

v0084:
    v0205 = stack[-2];
    v0205 = qcar(v0205);
    v0205 = integerp(v0205);
    if (v0205 == nil) goto v0168;
    v0205 = stack[-2];
    v0094 = qcar(v0205);
    v0205 = stack[0];
    v0205 = qcar(v0205);
    v0205 = (Lisp_Object)geq2(v0094, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0205 = v0205 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0205 == nil)) goto v0167;
    v0205 = stack[-2];
    v0094 = qcar(v0205);
    v0205 = (Lisp_Object)1; /* 0 */
    v0205 = (Lisp_Object)lessp2(v0094, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0205 = v0205 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0205 == nil)) goto v0167;
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    if (v0205 == nil) goto v0068;
    v0094 = stack[-3];
    v0205 = stack[-2];
    v0205 = qcar(v0205);
    v0205 = *(Lisp_Object *)((char *)v0094 + (CELL-TAG_VECTOR) + ((int32_t)v0205/(16/CELL)));
    stack[-3] = v0205;
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    stack[-2] = v0205;
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    stack[0] = v0205;
    goto v0084;

v0068:
    v0159 = stack[-3];
    v0205 = stack[-2];
    v0094 = qcar(v0205);
    v0205 = stack[-1];
    *(Lisp_Object *)((char *)v0159 + (CELL-TAG_VECTOR) + ((int32_t)v0094/(16/CELL))) = v0205;
    { popv(5); return onevalue(v0205); }

v0167:
    v0205 = elt(env, 2); /* "Array out of bounds" */
    v0094 = v0205;
    v0205 = v0094;
    qvalue(elt(env, 3)) = v0205; /* errmsg!* */
    v0205 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0205 == nil)) goto v0155;
    v0205 = v0094;
    fn = elt(env, 5); /* lprie */
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-4];
    goto v0155;

v0155:
    v0205 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0205 = nil;
    { popv(5); return onevalue(v0205); }

v0168:
    v0205 = stack[-2];
    v0094 = qcar(v0205);
    v0205 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0094, v0205);
    }
/* error exit handlers */
v0065:
    popv(5);
    return nil;
}



/* Code for reduce!-degree!-mod!-p */

static Lisp_Object CC_reduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-degree-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0013;
    stack[-2] = v0000;
/* end of prologue */
    v0061 = stack[-2];
    v0061 = qcar(v0061);
    v0061 = qcdr(v0061);
    {   int32_t w = int_of_fixnum(v0061);
        if (w != 0) w = current_modulus - w;
        v0085 = fixnum_of_int(w);
    }
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0061 = qcdr(v0061);
    v0061 = Lmodular_quotient(nil, v0085, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    stack[-3] = v0061;
    v0061 = stack[-2];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0085 = qcdr(v0061);
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = qcdr(v0061);
    v0061 = (Lisp_Object)(int32_t)((int32_t)v0085 - (int32_t)v0061 + TAG_FIXNUM);
    stack[0] = v0061;
    v0085 = stack[0];
    v0061 = (Lisp_Object)1; /* 0 */
    if (v0085 == v0061) goto v0128;
    v0061 = stack[-2];
    stack[-2] = qcdr(v0061);
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    fn = elt(env, 1); /* fkern */
    v0085 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    v0061 = stack[0];
    fn = elt(env, 2); /* getpower */
    v0085 = (*qfn2(fn))(qenv(fn), v0085, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    v0061 = stack[-3];
    v0085 = cons(v0085, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    fn = elt(env, 3); /* times!-term!-mod!-p */
    v0061 = (*qfn2(fn))(qenv(fn), v0085, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    {
        Lisp_Object v0041 = stack[-2];
        popv(5);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0041, v0061);
    }

v0128:
    v0061 = stack[-2];
    stack[0] = qcdr(v0061);
    v0061 = stack[-1];
    v0085 = qcdr(v0061);
    v0061 = stack[-3];
    fn = elt(env, 5); /* multiply!-by!-constant!-mod!-p */
    v0061 = (*qfn2(fn))(qenv(fn), v0085, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    {
        Lisp_Object v0039 = stack[0];
        popv(5);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0039, v0061);
    }
/* error exit handlers */
v0152:
    popv(5);
    return nil;
}



/* Code for powers4 */

static Lisp_Object CC_powers4(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0236, v0237, v0238;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0004;

v0004:
    v0236 = stack[-1];
    if (v0236 == nil) goto v0052;
    v0236 = stack[0];
    if (v0236 == nil) goto v0086;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[0];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    if (equal(v0237, v0236)) goto v0189;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[0];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    fn = elt(env, 2); /* ordop */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    if (v0236 == nil) goto v0098;
    v0236 = stack[0];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = (Lisp_Object)1; /* 0 */
    v0236 = Lrplacd(nil, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    stack[-2] = stack[0];
    v0237 = stack[-1];
    v0236 = stack[0];
    v0236 = qcdr(v0236);
    v0236 = CC_powers4(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = Lrplacd(nil, stack[-2], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    {
        Lisp_Object v0240 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0240, v0236);
    }

v0098:
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    stack[-2] = qcar(v0236);
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = (Lisp_Object)1; /* 0 */
    v0237 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = stack[-3];
    v0236 = acons(stack[-2], v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    stack[-3] = v0236;
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[-1] = v0236;
    goto v0004;

v0189:
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = stack[0];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    v0236 = (Lisp_Object)greaterp2(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    v0236 = v0236 ? lisp_true : nil;
    env = stack[-5];
    if (v0236 == nil) goto v0241;
    v0236 = stack[0];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = Lrplaca(nil, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    goto v0241;

v0241:
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = stack[0];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = (Lisp_Object)lessp2(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    v0236 = v0236 ? lisp_true : nil;
    env = stack[-5];
    if (v0236 == nil) goto v0107;
    v0236 = stack[0];
    v0236 = qcar(v0236);
    v0237 = qcdr(v0236);
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = Lrplacd(nil, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    goto v0107;

v0107:
    stack[-2] = stack[0];
    v0236 = stack[-1];
    v0237 = qcdr(v0236);
    v0236 = stack[0];
    v0236 = qcdr(v0236);
    v0236 = CC_powers4(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = Lrplacd(nil, stack[-2], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    {
        Lisp_Object v0242 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0242, v0236);
    }

v0086:
    stack[-4] = stack[-3];
    v0236 = stack[-1];
    stack[-3] = v0236;
    v0236 = stack[-3];
    if (v0236 == nil) goto v0197;
    v0236 = stack[-3];
    v0236 = qcar(v0236);
    v0237 = v0236;
    v0238 = qcar(v0237);
    v0237 = qcdr(v0236);
    v0236 = (Lisp_Object)1; /* 0 */
    v0236 = list2star(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    stack[-1] = v0236;
    stack[-2] = v0236;
    goto v0085;

v0085:
    v0236 = stack[-3];
    v0236 = qcdr(v0236);
    stack[-3] = v0236;
    v0236 = stack[-3];
    if (v0236 == nil) goto v0054;
    stack[0] = stack[-1];
    v0236 = stack[-3];
    v0236 = qcar(v0236);
    v0237 = v0236;
    v0238 = qcar(v0237);
    v0237 = qcdr(v0236);
    v0236 = (Lisp_Object)1; /* 0 */
    v0236 = list2star(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = Lrplacd(nil, stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[-1] = v0236;
    goto v0085;

v0054:
    v0236 = stack[-2];
    goto v0159;

v0159:
    {
        Lisp_Object v0243 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0243, v0236);
    }

v0197:
    v0236 = qvalue(elt(env, 1)); /* nil */
    goto v0159;

v0052:
    stack[-4] = stack[-3];
    v0236 = stack[0];
    stack[-3] = v0236;
    v0236 = stack[-3];
    if (v0236 == nil) goto v0021;
    v0236 = stack[-3];
    v0236 = qcar(v0236);
    v0237 = v0236;
    v0238 = qcar(v0237);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = (Lisp_Object)1; /* 0 */
    v0236 = list2star(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    stack[-1] = v0236;
    stack[-2] = v0236;
    goto v0167;

v0167:
    v0236 = stack[-3];
    v0236 = qcdr(v0236);
    stack[-3] = v0236;
    v0236 = stack[-3];
    if (v0236 == nil) goto v0048;
    stack[0] = stack[-1];
    v0236 = stack[-3];
    v0236 = qcar(v0236);
    v0237 = v0236;
    v0238 = qcar(v0237);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = (Lisp_Object)1; /* 0 */
    v0236 = list2star(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = Lrplacd(nil, stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-5];
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[-1] = v0236;
    goto v0167;

v0048:
    v0236 = stack[-2];
    goto v0168;

v0168:
    {
        Lisp_Object v0244 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0244, v0236);
    }

v0021:
    v0236 = qvalue(elt(env, 1)); /* nil */
    goto v0168;
/* error exit handlers */
v0239:
    popv(6);
    return nil;
}



/* Code for comm1 */

static Lisp_Object CC_comm1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm1");
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
    v0065 = stack[0];
    v0067 = elt(env, 1); /* end */
    if (!(v0065 == v0067)) goto v0091;

v0004:
    fn = elt(env, 10); /* scan */
    v0067 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    goto v0091;

v0091:
    v0065 = qvalue(elt(env, 2)); /* cursym!* */
    v0067 = elt(env, 3); /* !*semicol!* */
    if (v0065 == v0067) goto v0167;
    v0065 = stack[0];
    v0067 = elt(env, 1); /* end */
    if (v0065 == v0067) goto v0136;
    v0067 = qvalue(elt(env, 6)); /* nil */
    goto v0080;

v0080:
    if (v0067 == nil) goto v0161;
    v0067 = qvalue(elt(env, 6)); /* nil */
    { popv(3); return onevalue(v0067); }

v0161:
    v0065 = stack[0];
    v0067 = elt(env, 1); /* end */
    if (v0065 == v0067) goto v0032;
    v0067 = qvalue(elt(env, 6)); /* nil */
    goto v0058;

v0058:
    if (v0067 == nil) goto v0004;
    v0067 = qvalue(elt(env, 7)); /* !*msg */
    if (v0067 == nil) goto v0027;
    stack[-1] = elt(env, 8); /* "***" */
    v0067 = elt(env, 9); /* "END-COMMENT NO LONGER SUPPORTED" */
    v0067 = ncons(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    fn = elt(env, 11); /* lpriw */
    v0067 = (*qfn2(fn))(qenv(fn), stack[-1], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    goto v0027;

v0027:
    v0067 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v0067;
    goto v0004;

v0032:
    v0067 = stack[-1];
    v0067 = (v0067 == nil ? lisp_true : nil);
    goto v0058;

v0136:
    v0065 = qvalue(elt(env, 2)); /* cursym!* */
    v0067 = elt(env, 5); /* (end else then until !*rpar!* !*rsqbkt!*) */
    v0067 = Lmemq(nil, v0065, v0067);
    goto v0080;

v0167:
    v0067 = qvalue(elt(env, 4)); /* t */
    goto v0080;
/* error exit handlers */
v0085:
    popv(3);
    return nil;
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0261, v0262, v0263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0013;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0261 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0261 == nil) goto v0050;
    v0262 = stack[-4];
    v0261 = qvalue(elt(env, 2)); /* wtl!* */
    v0261 = Lassoc(nil, v0262, v0261);
    stack[-2] = v0261;
    if (v0261 == nil) goto v0005;
    stack[0] = elt(env, 3); /* k!* */
    v0262 = stack[-3];
    v0261 = stack[-2];
    v0261 = qcdr(v0261);
    v0261 = times2(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    v0261 = CC_mksq(env, stack[0], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    stack[-2] = v0261;
    v0261 = qcar(v0261);
    if (v0261 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    else goto v0005;

v0005:
    v0261 = stack[-4];
    if (!consp(v0261)) goto v0071;
    v0261 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v0261 == nil) goto v0222;
    v0261 = qvalue(elt(env, 6)); /* nil */
    goto v0265;

v0265:
    if (!(v0261 == nil)) goto v0030;
    stack[0] = elt(env, 7); /* used!* */
    v0261 = stack[-4];
    fn = elt(env, 16); /* fkern */
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    stack[-5] = v0261;
    v0261 = qcdr(v0261);
    v0261 = qcdr(v0261);
    v0261 = Lmemq(nil, stack[0], v0261);
    if (!(v0261 == nil)) goto v0029;
    stack[0] = stack[-5];
    v0261 = elt(env, 7); /* used!* */
    v0261 = ncons(v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    v0261 = Lnconc(nil, stack[0], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    goto v0029;

v0029:
    v0261 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v0261 == nil)) goto v0050;
    v0262 = stack[-3];
    v0261 = (Lisp_Object)17; /* 1 */
    if (v0262 == v0261) goto v0050;
    v0262 = stack[-4];
    v0261 = qvalue(elt(env, 8)); /* asymplis!* */
    v0261 = Lassoc(nil, v0262, v0261);
    stack[-1] = v0261;
    if (v0261 == nil) goto v0054;
    v0261 = stack[-1];
    v0262 = qcdr(v0261);
    v0261 = stack[-3];
    v0261 = (Lisp_Object)lesseq2(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    v0261 = v0261 ? lisp_true : nil;
    env = stack[-6];
    if (v0261 == nil) goto v0054;
    v0262 = qvalue(elt(env, 6)); /* nil */
    v0261 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v0262, v0261);

v0054:
    v0262 = stack[-4];
    v0261 = qvalue(elt(env, 9)); /* powlis!* */
    v0261 = Lassoc(nil, v0262, v0261);
    stack[-1] = v0261;
    if (!(v0261 == nil)) goto v0118;
    v0261 = stack[-4];
    if (!consp(v0261)) goto v0266;
    v0261 = stack[-4];
    v0262 = qcar(v0261);
    v0261 = elt(env, 10); /* (expt sqrt) */
    v0261 = Lmemq(nil, v0262, v0261);
    if (v0261 == nil) goto v0112;
    v0261 = stack[-4];
    v0261 = qcdr(v0261);
    v0262 = qcar(v0261);
    v0261 = qvalue(elt(env, 9)); /* powlis!* */
    v0261 = Lassoc(nil, v0262, v0261);
    stack[-1] = v0261;
    goto v0185;

v0185:
    if (!(v0261 == nil)) goto v0118;

v0050:
    v0261 = stack[-5];
    if (!(v0261 == nil)) goto v0267;
    v0261 = stack[-4];
    fn = elt(env, 16); /* fkern */
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    stack[-5] = v0261;
    goto v0267;

v0267:
    v0262 = stack[-5];
    v0261 = stack[-3];
    fn = elt(env, 17); /* getpower */
    v0262 = (*qfn2(fn))(qenv(fn), v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    v0261 = (Lisp_Object)17; /* 1 */
    v0261 = cons(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    v0262 = ncons(v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    v0261 = (Lisp_Object)17; /* 1 */
    v0261 = cons(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    stack[-5] = v0261;
    v0261 = stack[-2];
    if (v0261 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v0262 = stack[-2];
    v0261 = stack[-5];
    {
        popv(7);
        fn = elt(env, 18); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0262, v0261);
    }

v0118:
    v0262 = stack[-3];
    v0261 = stack[-1];
    v0261 = qcdr(v0261);
    v0261 = qcar(v0261);
    v0262 = times2(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    v0261 = (Lisp_Object)1; /* 0 */
    v0261 = (Lisp_Object)lessp2(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    v0261 = v0261 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0261 == nil)) goto v0050;
    v0261 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 12)) = v0261; /* !*sub2 */
    goto v0050;

v0112:
    v0261 = qvalue(elt(env, 6)); /* nil */
    goto v0185;

v0266:
    v0261 = qvalue(elt(env, 6)); /* nil */
    goto v0185;

v0030:
    v0261 = stack[-1];
    v0261 = qcdr(v0261);
    stack[-1] = v0261;
    v0261 = qvalue(elt(env, 15)); /* !*resubs */
    if (!(v0261 == nil)) goto v0268;
    v0261 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 4)) = v0261; /* !*nosubs */
    goto v0268;

v0268:
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    fn = elt(env, 19); /* simp */
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    stack[-5] = v0261;
    v0261 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 4)) = v0261; /* !*nosubs */
    v0262 = stack[-5];
    v0261 = stack[-3];
    {
        popv(7);
        fn = elt(env, 20); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v0262, v0261);
    }

v0222:
    v0261 = stack[-4];
    v0261 = qcar(v0261);
    if (!consp(v0261)) goto v0104;
    v0261 = qvalue(elt(env, 6)); /* nil */
    goto v0265;

v0104:
    v0261 = stack[-4];
    v0262 = qcar(v0261);
    v0261 = elt(env, 13); /* mksqsubfn */
    v0261 = get(v0262, v0261);
    env = stack[-6];
    stack[-1] = v0261;
    if (v0261 == nil) goto v0269;
    v0262 = stack[-1];
    v0261 = stack[-4];
    v0261 = Lapply1(nil, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    stack[-1] = v0261;
    goto v0270;

v0270:
    if (!(v0261 == nil)) goto v0265;
    v0263 = stack[-4];
    v0261 = stack[-4];
    v0262 = qcar(v0261);
    v0261 = elt(env, 14); /* kvalue */
    v0261 = get(v0262, v0261);
    env = stack[-6];
    v0261 = Lassoc(nil, v0263, v0261);
    stack[-1] = v0261;
    goto v0265;

v0269:
    v0261 = qvalue(elt(env, 6)); /* nil */
    goto v0270;

v0071:
    v0261 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v0261 == nil) goto v0019;
    v0261 = qvalue(elt(env, 6)); /* nil */
    goto v0155;

v0155:
    if (!(v0261 == nil)) goto v0030;
    v0261 = stack[-4];
    if (!(symbolp(v0261))) goto v0029;
    v0261 = stack[-4];
    v0262 = ncons(v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    v0261 = elt(env, 7); /* used!* */
    v0261 = Lflag(nil, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-6];
    goto v0029;

v0019:
    v0262 = stack[-4];
    v0261 = elt(env, 5); /* avalue */
    v0261 = get(v0262, v0261);
    env = stack[-6];
    stack[-1] = v0261;
    goto v0155;
/* error exit handlers */
v0264:
    popv(7);
    return nil;
}



/* Code for !*tayexp2q */

static Lisp_Object CC_Htayexp2q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *tayexp2q");
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
    v0021 = v0000;
/* end of prologue */
    v0023 = v0021;
    if (!consp(v0023)) goto v0029;
    v0021 = qcdr(v0021);
    { popv(1); return onevalue(v0021); }

v0029:
    v0023 = v0021;
    v0023 = (Lisp_Object)zerop(v0023);
    v0023 = v0023 ? lisp_true : nil;
    env = stack[0];
    if (v0023 == nil) goto v0172;
    v0021 = qvalue(elt(env, 1)); /* nil */
    v0023 = v0021;
    goto v0057;

v0057:
    v0021 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v0023, v0021);

v0172:
    v0023 = v0021;
    goto v0057;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0282;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-4] = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v0101 = stack[-4];
    if (v0101 == nil) goto v0168;
    v0101 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    goto v0055;

v0055:
    if (v0101 == nil) goto v0030;
    v0101 = stack[-4];
    goto v0050;

v0050:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v0101); }

v0030:
    v0101 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v0101; /* !*sub2 */
    v0282 = stack[-4];
    v0101 = (Lisp_Object)17; /* 1 */
    v0101 = cons(v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[0] = v0101;
    v0101 = stack[0];
    v0282 = qcdr(v0101);
    v0101 = (Lisp_Object)17; /* 1 */
    if (v0282 == v0101) goto v0154;
    v0101 = stack[-4];
    goto v0050;

v0154:
    v0101 = stack[0];
    v0282 = qcar(v0101);
    v0101 = stack[-4];
    if (equal(v0282, v0101)) goto v0051;
    v0101 = stack[0];
    v0101 = qcar(v0101);
    stack[-4] = v0101;
    v0101 = stack[-4];
    if (v0101 == nil) goto v0156;
    v0101 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    goto v0161;

v0161:
    if (v0101 == nil) goto v0051;
    v0101 = stack[-4];
    goto v0050;

v0051:
    v0101 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v0101; /* !*exp */
    v0101 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[-5] = v0101;
    v0282 = stack[-4];
    v0101 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v0101 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[-4] = v0101;
    v0101 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[0] = v0101;
    v0101 = stack[0];
    if (v0101 == nil) goto v0037;
    v0101 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    goto v0158;

v0158:
    if (v0101 == nil) goto v0086;
    v0282 = stack[-5];
    v0101 = stack[0];
    fn = elt(env, 15); /* multf */
    v0101 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    goto v0050;

v0086:
    v0101 = qvalue(elt(env, 4)); /* !*mcd */
    if (v0101 == nil) goto v0284;
    v0101 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v0101 == nil)) goto v0075;
    v0101 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v0101 == nil)) goto v0075;
    v0101 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v0101 == nil)) goto v0075;

v0284:
    v0101 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[-3] = v0101;
    v0282 = stack[0];
    v0101 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v0101 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[0] = v0101;
    v0282 = stack[0];
    v0101 = (Lisp_Object)17; /* 1 */
    v0101 = cons(v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    v0101 = list2(stack[-3], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[-3] = v0101;
    goto v0176;

v0176:
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0282 = qcdr(v0101);
    v0101 = (Lisp_Object)17; /* 1 */
    v0101 = (Lisp_Object)greaterp2(v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0101 == nil)) goto v0234;
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    if (!(v0101 == nil)) goto v0234;
    v0101 = qvalue(elt(env, 9)); /* !*group */
    if (v0101 == nil) goto v0227;
    v0101 = qvalue(elt(env, 8)); /* nil */
    goto v0267;

v0267:
    if (v0101 == nil) goto v0269;
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0282 = qcar(v0101);
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    fn = elt(env, 16); /* mksp!* */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    v0101 = stack[-3];
    v0101 = qcar(v0101);
    fn = elt(env, 15); /* multf */
    v0101 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[0] = v0101;
    goto v0285;

v0285:
    v0282 = stack[-5];
    v0101 = stack[0];
    fn = elt(env, 15); /* multf */
    v0101 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    goto v0050;

v0269:
    v0282 = stack[-4];
    v0101 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v0101 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[0] = v0101;
    goto v0285;

v0227:
    v0101 = stack[-4];
    fn = elt(env, 17); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 17); /* tmsf */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    v0101 = (Lisp_Object)greaterp2(stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-6];
    goto v0267;

v0234:
    v0101 = stack[-3];
    v0101 = qcar(v0101);
    stack[0] = v0101;
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    stack[-3] = v0101;
    goto v0117;

v0117:
    v0101 = stack[-3];
    if (v0101 == nil) goto v0285;
    v0101 = stack[-3];
    v0101 = qcar(v0101);
    v0282 = v0101;
    v0282 = qcar(v0282);
    v0101 = qcdr(v0101);
    fn = elt(env, 16); /* mksp!* */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    v0101 = stack[0];
    fn = elt(env, 15); /* multf */
    v0101 = (*qfn2(fn))(qenv(fn), v0282, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[0] = v0101;
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    stack[-3] = v0101;
    goto v0117;

v0075:
    v0101 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-6];
    stack[-3] = v0101;
    goto v0176;

v0037:
    v0101 = qvalue(elt(env, 3)); /* t */
    goto v0158;

v0156:
    v0101 = qvalue(elt(env, 3)); /* t */
    goto v0161;

v0168:
    v0101 = qvalue(elt(env, 3)); /* t */
    goto v0055;
/* error exit handlers */
v0283:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    popv(7);
    return nil;
}



/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check");
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
    v0035 = stack[0];
    v0035 = qcar(v0035);
    stack[-1] = v0035;
    v0035 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (v0035 == nil) goto v0029;
    v0035 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    goto v0004;

v0004:
    v0035 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0035); }

v0029:
    v0035 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (v0035 == nil) goto v0056;
    v0035 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    goto v0004;

v0056:
    v0035 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (!(v0035 == nil)) goto v0006;
    v0035 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (!(v0035 == nil)) goto v0006;
    v0035 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (v0035 == nil) goto v0153;
    v0035 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    goto v0004;

v0153:
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0093;

v0093:
    v0035 = stack[-1];
    if (v0035 == nil) goto v0004;
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (!(v0035 == nil)) goto v0069;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0035 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    v0086 = stack[0];
    v0035 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v0035 = (*qfn2(fn))(qenv(fn), v0086, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    goto v0069;

v0069:
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0093;

v0006:
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (!(v0035 == nil)) goto v0004;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0035 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    v0086 = stack[0];
    v0035 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v0035 = (*qfn2(fn))(qenv(fn), v0086, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    goto v0004;
/* error exit handlers */
v0159:
    popv(3);
    return nil;
}



/* Code for pasf_varlat */

static Lisp_Object CC_pasf_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_varlat");
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
    v0048 = stack[0];
    v0048 = qcdr(v0048);
    v0089 = qcar(v0048);
    v0048 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0089, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    v0048 = stack[0];
    v0048 = Lconsp(nil, v0048);
    env = stack[-2];
    if (v0048 == nil) goto v0049;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0048 = Lconsp(nil, v0048);
    env = stack[-2];
    if (v0048 == nil) goto v0049;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0089 = qcar(v0048);
    v0048 = elt(env, 2); /* (cong ncong) */
    v0048 = Lmemq(nil, v0089, v0048);
    if (v0048 == nil) goto v0049;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0089 = qcdr(v0048);
    v0048 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v0048 = (*qfn2(fn))(qenv(fn), v0089, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    goto v0004;

v0004:
    {
        Lisp_Object v0017 = stack[-1];
        popv(3);
        return Lappend(nil, v0017, v0048);
    }

v0049:
    v0048 = qvalue(elt(env, 1)); /* nil */
    goto v0004;
/* error exit handlers */
v0019:
    popv(3);
    return nil;
}



/* Code for cl_qb */

static Lisp_Object CC_cl_qb(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0087, v0069, v0047, v0070;
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
    v0070 = nil;
    v0046 = (Lisp_Object)1; /* 0 */
    v0047 = v0046;
    goto v0057;

v0057:
    v0046 = stack[0];
    if (!consp(v0046)) goto v0169;
    v0046 = stack[0];
    v0046 = qcar(v0046);
    goto v0168;

v0168:
    stack[-1] = v0046;
    v0069 = v0046;
    v0087 = v0069;
    v0046 = elt(env, 1); /* ex */
    if (v0087 == v0046) goto v0021;
    v0087 = v0069;
    v0046 = elt(env, 3); /* all */
    v0046 = (v0087 == v0046 ? lisp_true : nil);
    goto v0022;

v0022:
    if (v0046 == nil) { popv(3); return onevalue(v0047); }
    v0087 = stack[-1];
    v0046 = v0070;
    if (equal(v0087, v0046)) goto v0154;
    v0046 = v0047;
    v0046 = add1(v0046);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0047 = v0046;
    v0046 = stack[-1];
    v0070 = v0046;
    goto v0154;

v0154:
    v0046 = stack[0];
    v0046 = qcdr(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    stack[0] = v0046;
    goto v0057;

v0021:
    v0046 = qvalue(elt(env, 2)); /* t */
    goto v0022;

v0169:
    v0046 = stack[0];
    goto v0168;
/* error exit handlers */
v0016:
    popv(3);
    return nil;
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0154, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expansion-point");
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
    v0154 = v0000;
/* end of prologue */
    v0072 = v0154;
    if (!consp(v0072)) goto v0029;
    v0072 = v0154;
    v0049 = qcar(v0072);
    v0072 = elt(env, 2); /* !:ps!: */
    if (v0049 == v0072) goto v0137;
    v0072 = v0154;
    v0049 = qcar(v0072);
    v0072 = elt(env, 3); /* dname */
    v0072 = get(v0049, v0072);
    env = stack[0];
    goto v0084;

v0084:
    if (v0072 == nil) goto v0011;
    v0072 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v0072); }

v0011:
    v0072 = (Lisp_Object)49; /* 3 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0154, v0072);
    }

v0137:
    v0072 = qvalue(elt(env, 4)); /* nil */
    goto v0084;

v0029:
    v0072 = qvalue(elt(env, 1)); /* t */
    goto v0084;
}



/* Code for makeset */

static Lisp_Object CC_makeset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0020, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeset");
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
    v0164 = nil;
    goto v0025;

v0025:
    v0088 = stack[0];
    if (v0088 == nil) goto v0029;
    v0088 = stack[0];
    v0020 = qcar(v0088);
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0088 = Lmember(nil, v0020, v0088);
    if (v0088 == nil) goto v0073;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    goto v0025;

v0073:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0020 = v0164;
    v0088 = cons(v0088, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    v0164 = v0088;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    goto v0025;

v0029:
    v0088 = v0164;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0088);
    }
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for dm!-min */

static Lisp_Object CC_dmKmin(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0013)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-min");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0013;
    stack[-1] = v0000;
/* end of prologue */
    v0172 = stack[-1];
    v0006 = stack[0];
    fn = elt(env, 1); /* dm!-gt */
    v0006 = (*qfn2(fn))(qenv(fn), v0172, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    if (v0006 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0080:
    popv(2);
    return nil;
}



setup_type const u18_setup[] =
{
    {"rnprep:",                 CC_rnprepT,     too_many_1,    wrong_no_1},
    {"di_insert",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_di_insert},
    {"reducepowers",            CC_reducepowers,too_many_1,    wrong_no_1},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"outref",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_outref},
    {"prepsq*",                 CC_prepsqH,     too_many_1,    wrong_no_1},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ibalp_recalcv",           CC_ibalp_recalcv,too_many_1,   wrong_no_1},
    {"aex_ids",                 CC_aex_ids,     too_many_1,    wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"crprimp",                 CC_crprimp,     too_many_1,    wrong_no_1},
    {"getdec",                  CC_getdec,      too_many_1,    wrong_no_1},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"r2findindex",             too_few_2,      CC_r2findindex,wrong_no_2},
    {"inttovec-solve",          too_few_2,      CC_inttovecKsolve,wrong_no_2},
    {"ordop2",                  too_few_2,      CC_ordop2,     wrong_no_2},
    {"contr",                   too_few_2,      CC_contr,      wrong_no_2},
    {"assert_error",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_error},
    {"setelv",                  too_few_2,      CC_setelv,     wrong_no_2},
    {"fs:times",                too_few_2,      CC_fsTtimes,   wrong_no_2},
    {"dpmat_coldegs",           CC_dpmat_coldegs,too_many_1,   wrong_no_1},
    {"evaluate-mod-p",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKmodKp},
    {"mkfil*",                  CC_mkfilH,      too_many_1,    wrong_no_1},
    {"sq2sstm",                 too_few_2,      CC_sq2sstm,    wrong_no_2},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"sfto_sqfpartf",           CC_sfto_sqfpartf,too_many_1,   wrong_no_1},
    {"simpexpt",                CC_simpexpt,    too_many_1,    wrong_no_1},
    {"tayexp-times2",           too_few_2,      CC_tayexpKtimes2,wrong_no_2},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {"ibalp_negateat",          CC_ibalp_negateat,too_many_1,  wrong_no_1},
    {"cgp_number",              CC_cgp_number,  too_many_1,    wrong_no_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"dipprodin1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipprodin1},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {"pfordp",                  too_few_2,      CC_pfordp,     wrong_no_2},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"reduce-degree-mod-p",     too_few_2,      CC_reduceKdegreeKmodKp,wrong_no_2},
    {"powers4",                 too_few_2,      CC_powers4,    wrong_no_2},
    {"comm1",                   CC_comm1,       too_many_1,    wrong_no_1},
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"*tayexp2q",               CC_Htayexp2q,   too_many_1,    wrong_no_1},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"pasf_varlat",             CC_pasf_varlat, too_many_1,    wrong_no_1},
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"ps:expansion-point",      CC_psTexpansionKpoint,too_many_1,wrong_no_1},
    {"makeset",                 CC_makeset,     too_many_1,    wrong_no_1},
    {"dm-min",                  too_few_2,      CC_dmKmin,     wrong_no_2},
    {NULL, (one_args *)"u18", (two_args *)"632 7800965 7530741", 0}
};

/* end of generated code */
