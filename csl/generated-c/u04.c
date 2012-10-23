
/* $destdir\u04.c        Machine generated C code */

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


/* Code for addsq */

static Lisp_Object CC_addsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addsq");
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
    v0053 = stack[-3];
    v0053 = qcar(v0053);
    if (v0053 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0053 = stack[-2];
    v0053 = qcar(v0053);
    if (v0053 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0053 = stack[-3];
    v0054 = qcdr(v0053);
    v0053 = (Lisp_Object)17; /* 1 */
    if (v0054 == v0053) goto v0055;
    v0053 = qvalue(elt(env, 1)); /* nil */
    goto v0056;

v0056:
    if (v0053 == nil) goto v0057;
    v0053 = stack[-3];
    v0054 = qcar(v0053);
    v0053 = stack[-2];
    v0053 = qcar(v0053);
    fn = elt(env, 5); /* addf */
    v0054 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0053 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0054, v0053);

v0057:
    v0053 = qvalue(elt(env, 2)); /* !*exp */
    if (!(v0053 == nil)) goto v0059;
    v0053 = stack[-3];
    stack[0] = qcar(v0053);
    v0053 = stack[-3];
    v0053 = qcdr(v0053);
    fn = elt(env, 6); /* mkprod */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0053 = cons(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-3] = v0053;
    v0053 = stack[-2];
    stack[0] = qcar(v0053);
    v0053 = stack[-2];
    v0053 = qcdr(v0053);
    fn = elt(env, 6); /* mkprod */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0053 = cons(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-2] = v0053;
    goto v0059;

v0059:
    v0053 = qvalue(elt(env, 3)); /* !*lcm */
    if (v0053 == nil) goto v0060;
    v0053 = stack[-3];
    v0054 = qcdr(v0053);
    v0053 = stack[-2];
    v0053 = qcdr(v0053);
    fn = elt(env, 7); /* gcdf!* */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-4] = v0053;
    goto v0061;

v0061:
    v0053 = stack[-3];
    v0054 = qcdr(v0053);
    v0053 = stack[-4];
    fn = elt(env, 8); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0053 = stack[-2];
    v0054 = qcdr(v0053);
    v0053 = stack[-4];
    fn = elt(env, 8); /* quotf */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0053 = cons(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    fn = elt(env, 9); /* canonsq */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0053;
    v0053 = stack[-1];
    v0054 = qcdr(v0053);
    v0053 = stack[-3];
    v0053 = qcar(v0053);
    fn = elt(env, 10); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0053 = stack[-1];
    v0054 = qcar(v0053);
    v0053 = stack[-2];
    v0053 = qcar(v0053);
    fn = elt(env, 10); /* multf */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    fn = elt(env, 5); /* addf */
    v0053 = (*qfn2(fn))(qenv(fn), stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[0] = v0053;
    v0053 = stack[0];
    if (v0053 == nil) goto v0062;
    v0053 = stack[-3];
    v0054 = qcdr(v0053);
    v0053 = stack[-1];
    v0053 = qcdr(v0053);
    fn = elt(env, 10); /* multf */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0053;
    v0054 = stack[-4];
    v0053 = (Lisp_Object)17; /* 1 */
    if (v0054 == v0053) goto v0063;
    v0054 = stack[0];
    v0053 = stack[-4];
    fn = elt(env, 11); /* gcdf */
    v0054 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-4] = v0054;
    v0053 = (Lisp_Object)17; /* 1 */
    v0053 = (v0054 == v0053 ? lisp_true : nil);
    goto v0064;

v0064:
    if (v0053 == nil) goto v0065;
    v0054 = stack[0];
    v0053 = stack[-1];
    popv(6);
    return cons(v0054, v0053);

v0065:
    v0054 = stack[0];
    v0053 = stack[-4];
    fn = elt(env, 8); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0054 = stack[-1];
    v0053 = stack[-4];
    fn = elt(env, 8); /* quotf */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0053 = cons(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 9); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v0053);
    }

v0063:
    v0053 = qvalue(elt(env, 4)); /* t */
    goto v0064;

v0062:
    v0054 = qvalue(elt(env, 1)); /* nil */
    v0053 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0054, v0053);

v0060:
    v0053 = stack[-3];
    v0054 = qcdr(v0053);
    v0053 = stack[-2];
    v0053 = qcdr(v0053);
    fn = elt(env, 11); /* gcdf */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-4] = v0053;
    goto v0061;

v0055:
    v0053 = stack[-2];
    v0054 = qcdr(v0053);
    v0053 = (Lisp_Object)17; /* 1 */
    v0053 = (v0054 == v0053 ? lisp_true : nil);
    goto v0056;
/* error exit handlers */
v0058:
    popv(6);
    return nil;
}



/* Code for pkp */

static Lisp_Object CC_pkp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0085, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pkp");
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
    stack[-3] = nil;
    v0024 = stack[0];
    if (!consp(v0024)) goto v0087;
    v0024 = qvalue(elt(env, 2)); /* !*ppacked */
    v0024 = (v0024 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (!(v0024 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0024 = stack[0];
    v0085 = Llength(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    v0024 = (Lisp_Object)161; /* 10 */
    v0024 = (Lisp_Object)geq2(v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0024 = v0024 ? lisp_true : nil;
    env = stack[-4];
    stack[-2] = v0024;
    v0024 = stack[0];
    stack[-1] = v0024;
    goto v0089;

v0089:
    v0024 = stack[-1];
    if (v0024 == nil) goto v0090;
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    stack[0] = v0024;
    v0024 = stack[-2];
    if (v0024 == nil) goto v0091;
    v0085 = stack[0];
    v0024 = (Lisp_Object)161; /* 10 */
    v0024 = (Lisp_Object)lessp2(v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0024 = v0024 ? lisp_true : nil;
    env = stack[-4];
    if (v0024 == nil) goto v0092;
    v0085 = stack[0];
    v0024 = qvalue(elt(env, 4)); /* diglist!* */
    fn = elt(env, 6); /* dssoc */
    v0024 = (*qfn2(fn))(qenv(fn), v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    v0086 = qcar(v0024);
    v0085 = elt(env, 5); /* !0 */
    v0024 = stack[-3];
    v0024 = list2star(v0086, v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    stack[-3] = v0024;
    goto v0093;

v0093:
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    stack[-1] = v0024;
    goto v0089;

v0092:
    v0085 = stack[0];
    v0024 = (Lisp_Object)161; /* 10 */
    v0024 = Ldivide(nil, v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    stack[0] = v0024;
    v0024 = stack[0];
    v0085 = qcar(v0024);
    v0024 = qvalue(elt(env, 4)); /* diglist!* */
    fn = elt(env, 6); /* dssoc */
    v0024 = (*qfn2(fn))(qenv(fn), v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    v0085 = qcar(v0024);
    v0024 = stack[-3];
    v0024 = cons(v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    stack[-3] = v0024;
    v0024 = stack[0];
    v0085 = qcdr(v0024);
    v0024 = qvalue(elt(env, 4)); /* diglist!* */
    fn = elt(env, 6); /* dssoc */
    v0024 = (*qfn2(fn))(qenv(fn), v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    v0085 = qcar(v0024);
    v0024 = stack[-3];
    v0024 = cons(v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    stack[-3] = v0024;
    goto v0093;

v0091:
    v0085 = stack[0];
    v0024 = qvalue(elt(env, 4)); /* diglist!* */
    fn = elt(env, 6); /* dssoc */
    v0024 = (*qfn2(fn))(qenv(fn), v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    v0085 = qcar(v0024);
    v0024 = stack[-3];
    v0024 = cons(v0085, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    stack[-3] = v0024;
    goto v0093;

v0090:
    v0024 = stack[-3];
    v0024 = Lnreverse(nil, v0024);
        popv(5);
        return Lcompress(nil, v0024);

v0087:
    v0024 = qvalue(elt(env, 1)); /* t */
    goto v0088;
/* error exit handlers */
v0028:
    popv(5);
    return nil;
}



/* Code for round!:last */

static Lisp_Object CC_roundTlast(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0105, v0106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round:last");
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
    v0105 = v0000;
/* end of prologue */
    v0104 = v0105;
    v0104 = qcdr(v0104);
    stack[0] = qcar(v0104);
    v0104 = v0105;
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    v0105 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    v0104 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = v0105;
    stack[0] = v0104;
    v0105 = stack[-2];
    v0104 = (Lisp_Object)1; /* 0 */
    v0104 = (Lisp_Object)lessp2(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    v0104 = v0104 ? lisp_true : nil;
    env = stack[-3];
    if (v0104 == nil) goto v0107;
    v0104 = stack[-2];
    v0104 = negate(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    stack[-2] = v0104;
    v0104 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0104;
    goto v0107;

v0107:
    v0104 = stack[-2];
    v0104 = Levenp(nil, v0104);
    env = stack[-3];
    if (v0104 == nil) goto v0050;
    v0105 = stack[-2];
    v0104 = (Lisp_Object)-15; /* -1 */
    v0104 = ash(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    goto v0055;

v0055:
    stack[-2] = v0104;
    v0104 = stack[0];
    if (v0104 == nil) goto v0010;
    v0104 = stack[-2];
    v0104 = negate(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    stack[-2] = v0104;
    goto v0010;

v0010:
    v0106 = elt(env, 3); /* !:rd!: */
    v0105 = stack[-2];
    v0104 = stack[-1];
    popv(4);
    return list2star(v0106, v0105, v0104);

v0050:
    v0105 = stack[-2];
    v0104 = (Lisp_Object)-15; /* -1 */
    v0104 = ash(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    goto v0055;
/* error exit handlers */
v0042:
    popv(4);
    return nil;
}



/* Code for remainder!-in!-vector */

static Lisp_Object MS_CDECL CC_remainderKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, Lisp_Object v0081, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0063, v0139, v0140, v0141, v0142, v0143, v0144, v0018, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "remainder-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remainder-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0081,v0066,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0066,v0081);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0081;
    stack[-1] = v0066;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0063 = stack[0];
    v0064 = (Lisp_Object)1; /* 0 */
    if (v0063 == v0064) goto v0087;
    v0063 = stack[0];
    v0064 = (Lisp_Object)-15; /* -1 */
    if (!(v0063 == v0064)) goto v0049;
    v0064 = elt(env, 1); /* "ATTEMPT TO DIVIDE BY ZERO" */
    fn = elt(env, 3); /* errorf */
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    goto v0049;

v0049:
    v0063 = stack[-1];
    v0064 = stack[0];
    v0064 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    v0064 = Lmodular_reciprocal(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0064);
        if (w != 0) w = current_modulus - w;
        v0064 = fixnum_of_int(w);
    }
    v0144 = v0064;
    v0064 = stack[0];
    v0064 = (Lisp_Object)((int32_t)(v0064) - 0x10);
    v0018 = v0064;
    goto v0057;

v0057:
    v0063 = stack[-2];
    v0064 = stack[0];
    v0063 = (Lisp_Object)(int32_t)((int32_t)v0063 - (int32_t)v0064 + TAG_FIXNUM);
    v0019 = v0063;
    v0064 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0063)) < ((int32_t)(v0064))) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0139 = v0144;
    v0063 = stack[-3];
    v0064 = stack[-2];
    v0064 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    v0064 = Lmodular_times(nil, v0139, v0064);
    env = stack[-4];
    v0143 = v0064;
    v0064 = (Lisp_Object)1; /* 0 */
    v0142 = v0064;
    goto v0146;

v0146:
    v0063 = v0018;
    v0064 = v0142;
    v0064 = (Lisp_Object)(int32_t)((int32_t)v0063 - (int32_t)v0064 + TAG_FIXNUM);
    v0064 = ((intptr_t)(v0064) < 0 ? lisp_true : nil);
    if (v0064 == nil) goto v0147;
    v0064 = stack[-2];
    v0064 = (Lisp_Object)((int32_t)(v0064) - 0x10);
    stack[-2] = v0064;
    goto v0027;

v0027:
    v0063 = stack[-2];
    v0064 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0063)) < ((int32_t)(v0064))) goto v0148;
    v0063 = stack[-3];
    v0064 = stack[-2];
    v0063 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    v0064 = (Lisp_Object)1; /* 0 */
    v0064 = (v0063 == v0064 ? lisp_true : nil);
    goto v0149;

v0149:
    if (v0064 == nil) goto v0057;
    v0064 = stack[-2];
    v0064 = (Lisp_Object)((int32_t)(v0064) - 0x10);
    stack[-2] = v0064;
    goto v0027;

v0148:
    v0064 = qvalue(elt(env, 2)); /* nil */
    goto v0149;

v0147:
    v0141 = stack[-3];
    v0063 = v0142;
    v0064 = v0019;
    v0140 = (Lisp_Object)(int32_t)((int32_t)v0063 + (int32_t)v0064 - TAG_FIXNUM);
    v0139 = stack[-3];
    v0063 = v0142;
    v0064 = v0019;
    v0064 = (Lisp_Object)(int32_t)((int32_t)v0063 + (int32_t)v0064 - TAG_FIXNUM);
    v0139 = *(Lisp_Object *)((char *)v0139 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    v0063 = stack[-1];
    v0064 = v0142;
    v0063 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    v0064 = v0143;
    v0064 = Lmodular_times(nil, v0063, v0064);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0139) + int_of_fixnum(v0064);
        if (w >= current_modulus) w -= current_modulus;
        v0064 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0141 + (CELL-TAG_VECTOR) + ((int32_t)v0140/(16/CELL))) = v0064;
    v0064 = v0142;
    v0064 = (Lisp_Object)((int32_t)(v0064) + 0x10);
    v0142 = v0064;
    goto v0146;

v0087:
    v0064 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0064); }
/* error exit handlers */
v0145:
    popv(5);
    return nil;
}



/* Code for !*!*s2a */

static Lisp_Object CC_HHs2a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object v0074, v0123;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **s2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0074 = v0001;
    v0123 = v0000;
/* end of prologue */
    return onevalue(v0123);
}



/* Code for gcdf */

static Lisp_Object CC_gcdf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf");
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
    stack[-4] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*rounded */
    qvalue(elt(env, 2)) = nil; /* !*rounded */
    v0076 = qvalue(elt(env, 3)); /* !*mcd */
    stack[0] = v0076;
    v0076 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 1)) = v0076; /* !*exp */
    v0076 = stack[-3];
    if (!consp(v0076)) goto v0137;
    v0076 = stack[-3];
    v0076 = qcar(v0076);
    v0076 = (consp(v0076) ? nil : lisp_true);
    goto v0154;

v0154:
    if (v0076 == nil) goto v0083;
    v0076 = qvalue(elt(env, 4)); /* t */
    goto v0155;

v0155:
    if (v0076 == nil) goto v0156;
    v0076 = qvalue(elt(env, 7)); /* !*combineexpt */
    if (v0076 == nil) goto v0080;
    v0076 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v0076; /* !*mcd */
    goto v0080;

v0080:
    v0039 = stack[-3];
    v0076 = stack[-2];
    fn = elt(env, 8); /* gcdf1 */
    v0076 = (*qfn2(fn))(qenv(fn), v0039, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    goto v0084;

v0084:
    stack[-3] = v0076;
    v0076 = stack[0];
    qvalue(elt(env, 3)) = v0076; /* !*mcd */
    v0076 = stack[-3];
    fn = elt(env, 9); /* minusf */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    if (v0076 == nil) goto v0147;
    v0076 = stack[-3];
    fn = elt(env, 10); /* negf */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    goto v0131;

v0131:
    qvalue(elt(env, 2)) = stack[-1]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-4]; /* !*exp */
    { popv(6); return onevalue(v0076); }

v0147:
    v0076 = stack[-3];
    goto v0131;

v0156:
    v0039 = stack[-3];
    v0076 = stack[-2];
    fn = elt(env, 11); /* ezgcdf */
    v0076 = (*qfn2(fn))(qenv(fn), v0039, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    goto v0084;

v0083:
    v0076 = stack[-2];
    if (!consp(v0076)) goto v0158;
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    v0076 = (consp(v0076) ? nil : lisp_true);
    goto v0159;

v0159:
    if (v0076 == nil) goto v0160;
    v0076 = qvalue(elt(env, 4)); /* t */
    goto v0155;

v0160:
    v0076 = qvalue(elt(env, 5)); /* !*ezgcd */
    if (v0076 == nil) goto v0099;
    v0076 = qvalue(elt(env, 6)); /* dmode!* */
    if (!(v0076 == nil)) goto v0155;
    v0076 = stack[-3];
    fn = elt(env, 12); /* free!-powerp */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    if (!(v0076 == nil)) goto v0155;
    v0076 = stack[-2];
    fn = elt(env, 12); /* free!-powerp */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    goto v0155;

v0099:
    v0076 = qvalue(elt(env, 4)); /* t */
    goto v0155;

v0158:
    v0076 = qvalue(elt(env, 4)); /* t */
    goto v0159;

v0137:
    v0076 = qvalue(elt(env, 4)); /* t */
    goto v0154;
/* error exit handlers */
v0157:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-4]; /* !*exp */
    popv(6);
    return nil;
}



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0154, v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-min2");
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
    v0137 = stack[-1];
    v0154 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v0154 = (*qfn2(fn))(qenv(fn), v0137, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    if (v0154 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v0102:
    popv(2);
    return nil;
}



/* Code for pasf_susitf */

static Lisp_Object CC_pasf_susitf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object v0074, v0123;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susitf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0074 = v0001;
    v0123 = v0000;
/* end of prologue */
    return onevalue(v0123);
}



/* Code for ibalp_csat */

static Lisp_Object CC_ibalp_csat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_csat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0000;
/* end of prologue */

v0161:
    v0052 = v0051;
    if (v0052 == nil) goto v0074;
    v0052 = v0051;
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    if (v0052 == nil) goto v0088;
    v0051 = qcdr(v0051);
    goto v0161;

v0088:
    v0051 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0051);

v0074:
    v0051 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0051);
}



/* Code for free!-powerp */

static Lisp_Object CC_freeKpowerp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for free-powerp");
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

v0161:
    v0101 = stack[0];
    if (!consp(v0101)) goto v0119;
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0101 = (consp(v0101) ? nil : lisp_true);
    goto v0131;

v0131:
    if (v0101 == nil) goto v0074;
    v0101 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0101); }

v0074:
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = integerp(v0101);
    if (v0101 == nil) goto v0154;
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = CC_freeKpowerp(env, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    if (!(v0101 == nil)) { popv(2); return onevalue(v0101); }
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0161;

v0154:
    v0101 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0101); }

v0119:
    v0101 = qvalue(elt(env, 1)); /* t */
    goto v0131;
/* error exit handlers */
v0069:
    popv(2);
    return nil;
}



/* Code for isvalid */

static Lisp_Object CC_isvalid(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isvalid");
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
    v0163 = stack[0];
    v0163 = Lcompress(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0006 = Lsymbolp(nil, v0163);
    env = stack[-2];
    v0163 = qvalue(elt(env, 1)); /* t */
    if (equal(v0006, v0163)) goto v0102;
    v0163 = stack[0];
        popv(3);
        return Lcompress(nil, v0163);

v0102:
    v0163 = stack[0];
    fn = elt(env, 6); /* compress!* */
    v0006 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0163 = qvalue(elt(env, 2)); /* functions!* */
    v0163 = Lassoc(nil, v0006, v0163);
    if (v0163 == nil) goto v0049;
    v0163 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0163); }

v0049:
    stack[-1] = elt(env, 3); /* !/ */
    v0163 = stack[0];
    v0163 = Lreverse(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0163 = cons(stack[-1], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0163 = Lreverse(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    stack[0] = v0163;
    v0163 = stack[0];
    fn = elt(env, 6); /* compress!* */
    v0006 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0163 = qvalue(elt(env, 2)); /* functions!* */
    v0163 = Lassoc(nil, v0006, v0163);
    if (v0163 == nil) goto v0069;
    v0163 = stack[0];
    qvalue(elt(env, 4)) = v0163; /* char */
    v0163 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0163); }

v0069:
    v0163 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0163); }
/* error exit handlers */
v0133:
    popv(3);
    return nil;
}



/* Code for multi_elem */

static Lisp_Object CC_multi_elem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_elem");
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
    v0052 = stack[0];
    v0055 = Llength(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0052 = (Lisp_Object)17; /* 1 */
    if (v0055 == v0052) goto v0127;
    v0052 = stack[0];
    v0052 = qcar(v0052);
    fn = elt(env, 2); /* expression */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = CC_multi_elem(env, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    goto v0123;

v0123:
    v0052 = nil;
    { popv(2); return onevalue(v0052); }

v0127:
    v0052 = stack[0];
    v0052 = qcar(v0052);
    fn = elt(env, 2); /* expression */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    goto v0123;
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for findrow */

static Lisp_Object CC_findrow(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0165, v0135, v0100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findrow");
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
    v0158 = v0001;
    v0165 = v0000;
/* end of prologue */
    v0135 = v0165;
    v0135 = Lconsp(nil, v0135);
    env = stack[0];
    if (v0135 == nil) goto v0152;
    v0135 = v0165;
    v0135 = qcar(v0135);
    v0100 = elt(env, 1); /* sparsemat */
    if (!(v0135 == v0100)) goto v0152;
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    goto v0152;

v0152:
    v0158 = *(Lisp_Object *)((char *)v0165 + (CELL-TAG_VECTOR) + ((int32_t)v0158/(16/CELL)));
    { popv(1); return onevalue(v0158); }
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for downwght");
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
    v0155 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    v0162 = stack[-1];
    v0155 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v0155 = (*qfn2(fn))(qenv(fn), v0162, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    v0155 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v0155);
    }
/* error exit handlers */
v0154:
    popv(3);
    return nil;
}



/* Code for prepd */

static Lisp_Object CC_prepd(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0157, v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepd");
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
    v0171 = stack[0];
    if (!consp(v0171)) goto v0088;
    v0171 = stack[0];
    v0157 = qcar(v0171);
    v0171 = elt(env, 2); /* minusp */
    v0157 = get(v0157, v0171);
    env = stack[-2];
    v0171 = stack[0];
    v0171 = Lapply1(nil, v0157, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-2];
    if (v0171 == nil) goto v0147;
    v0171 = stack[0];
    fn = elt(env, 4); /* !:minus */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-2];
    v0172 = v0171;
    v0171 = v0172;
    if (!consp(v0171)) goto v0046;
    v0171 = v0172;
    v0157 = qcar(v0171);
    v0171 = elt(env, 3); /* prepfn */
    v0171 = get(v0157, v0171);
    env = stack[-2];
    v0157 = v0172;
    v0171 = Lapply1(nil, v0171, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-2];
    goto v0173;

v0173:
    v0157 = v0171;
    v0171 = v0157;
    if (v0171 == nil) goto v0078;
    v0171 = elt(env, 1); /* minus */
    popv(3);
    return list2(v0171, v0157);

v0078:
    v0171 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0171); }

v0046:
    v0171 = v0172;
    goto v0173;

v0147:
    v0171 = stack[0];
    v0157 = qcar(v0171);
    v0171 = elt(env, 3); /* prepfn */
    v0157 = get(v0157, v0171);
    v0171 = stack[0];
        popv(3);
        return Lapply1(nil, v0157, v0171);

v0088:
    v0157 = stack[0];
    v0171 = (Lisp_Object)1; /* 0 */
    v0171 = (Lisp_Object)lessp2(v0157, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    v0171 = v0171 ? lisp_true : nil;
    env = stack[-2];
    if (v0171 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* minus */
    v0171 = stack[0];
    v0171 = negate(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        Lisp_Object v0116 = stack[-1];
        popv(3);
        return list2(v0116, v0171);
    }
/* error exit handlers */
v0036:
    popv(3);
    return nil;
}



/* Code for bcint2op */

static Lisp_Object MS_CDECL CC_bcint2op(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0091, v0117, v0118, v0180;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bcint2op");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcint2op");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0066,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0066);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0180 = v0066;
    v0117 = v0001;
    v0118 = v0000;
/* end of prologue */
    v0031 = qvalue(elt(env, 1)); /* dmode!* */
    if (v0031 == nil) goto v0048;
    v0031 = qvalue(elt(env, 2)); /* nil */
    goto v0181;

v0181:
    if (v0031 == nil) goto v0131;
    v0091 = v0118;
    v0031 = (Lisp_Object)1; /* 0 */
    if (v0091 == v0031) goto v0072;
    v0031 = v0118;
    v0091 = v0031;
    goto v0036;

v0036:
    v0031 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v0091, v0031);

v0072:
    v0031 = qvalue(elt(env, 2)); /* nil */
    v0091 = v0031;
    goto v0036;

v0131:
    v0031 = nil;
    { popv(1); return onevalue(v0031); }

v0048:
    v0091 = (Lisp_Object)17; /* 1 */
    v0031 = v0118;
    v0031 = qcdr(v0031);
    if (v0091 == v0031) goto v0155;
    v0031 = qvalue(elt(env, 2)); /* nil */
    goto v0181;

v0155:
    v0031 = v0118;
    v0031 = qcar(v0031);
    v0118 = v0031;
    if (is_number(v0031)) goto v0158;
    v0031 = qvalue(elt(env, 2)); /* nil */
    goto v0181;

v0158:
    v0091 = (Lisp_Object)17; /* 1 */
    v0031 = v0117;
    v0031 = qcdr(v0031);
    if (v0091 == v0031) goto v0050;
    v0031 = qvalue(elt(env, 2)); /* nil */
    goto v0181;

v0050:
    v0031 = v0117;
    v0031 = qcar(v0031);
    v0117 = v0031;
    if (is_number(v0031)) goto v0163;
    v0031 = qvalue(elt(env, 2)); /* nil */
    goto v0181;

v0163:
    v0091 = v0180;
    v0031 = elt(env, 3); /* times */
    if (v0091 == v0031) goto v0182;
    v0091 = v0180;
    v0031 = elt(env, 4); /* plus */
    if (v0091 == v0031) goto v0092;
    v0031 = v0180;
    v0091 = v0118;
    v0031 = Lapply2(nil, 3, v0031, v0091, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[0];
    goto v0047;

v0047:
    v0118 = v0031;
    goto v0181;

v0092:
    v0031 = v0118;
    v0091 = v0117;
    v0031 = plus2(v0031, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[0];
    goto v0047;

v0182:
    v0031 = v0118;
    v0091 = v0117;
    v0031 = times2(v0031, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[0];
    goto v0047;
/* error exit handlers */
v0183:
    popv(1);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0006, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convchk");
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
    v0163 = v0000;
/* end of prologue */
    v0006 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v0006 == nil) goto v0123;
    v0006 = v0163;
    if (!(!consp(v0006))) { popv(1); return onevalue(v0163); }
    v0006 = v0163;
    v0006 = Lfloatp(nil, v0006);
    env = stack[0];
    if (v0006 == nil) goto v0137;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0163);
    }

v0137:
    v0006 = v0163;
    if (!(!consp(v0006))) goto v0103;
    v0006 = v0163;
    v0006 = integerp(v0006);
    if (v0006 == nil) goto v0069;
    v0010 = elt(env, 2); /* !:rd!: */
    v0006 = v0163;
    v0163 = (Lisp_Object)1; /* 0 */
    v0163 = list2star(v0010, v0006, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    goto v0103;

v0103:
    {
        popv(1);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v0163);
    }

v0069:
    fn = elt(env, 5); /* read!:num */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    goto v0103;

v0123:
    v0006 = v0163;
    if (!consp(v0006)) { popv(1); return onevalue(v0163); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v0163);
    }
/* error exit handlers */
v0007:
    popv(1);
    return nil;
}



/* Code for repeatsp */

static Lisp_Object CC_repeatsp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0051, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeatsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0000;
/* end of prologue */

v0161:
    v0169 = v0051;
    if (v0169 == nil) goto v0074;
    v0169 = v0051;
    v0052 = qcar(v0169);
    v0169 = v0051;
    v0169 = qcdr(v0169);
    v0169 = Lmember(nil, v0052, v0169);
    if (!(v0169 == nil)) return onevalue(v0169);
    v0169 = v0051;
    v0169 = qcdr(v0169);
    v0051 = v0169;
    goto v0161;

v0074:
    v0169 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0169);
}



/* Code for nonzero!-length */

static Lisp_Object CC_nonzeroKlength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0083, v0082;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonzero-length");
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
    v0083 = v0000;
/* end of prologue */

v0074:
    v0055 = v0083;
    if (v0055 == nil) goto v0131;
    v0055 = v0083;
    v0082 = qcar(v0055);
    v0055 = (Lisp_Object)1; /* 0 */
    if (v0082 == v0055) goto v0084;
    v0055 = v0083;
    v0055 = qcdr(v0055);
    v0055 = CC_nonzeroKlength(env, v0055);
    errexit();
    return add1(v0055);

v0084:
    v0055 = v0083;
    v0055 = qcdr(v0055);
    v0083 = v0055;
    goto v0074;

v0131:
    v0055 = (Lisp_Object)1; /* 0 */
    return onevalue(v0055);
}



/* Code for bas_rep */

static Lisp_Object CC_bas_rep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_rep");
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
    v0084 = v0000;
/* end of prologue */
    v0088 = v0084;
    v0084 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v0084 = (*qfn2(fn))(qenv(fn), v0088, v0084);
    errexit();
    v0084 = qcar(v0084);
    return onevalue(v0084);
}



/* Code for lcm */

static Lisp_Object CC_lcm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0133, v0134, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lcm");
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
    v0134 = v0001;
    v0132 = v0000;
/* end of prologue */
    v0007 = v0132;
    if (v0007 == nil) goto v0181;
    v0007 = v0134;
    v0007 = (v0007 == nil ? lisp_true : nil);
    goto v0119;

v0119:
    if (v0007 == nil) goto v0137;
    v0007 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0007); }

v0137:
    v0133 = v0132;
    v0007 = (Lisp_Object)17; /* 1 */
    if (v0133 == v0007) { popv(3); return onevalue(v0134); }
    v0133 = v0134;
    v0007 = (Lisp_Object)17; /* 1 */
    if (v0133 == v0007) { popv(3); return onevalue(v0132); }
    stack[-1] = v0132;
    stack[0] = v0134;
    v0007 = v0132;
    v0133 = v0134;
    fn = elt(env, 3); /* gcdf */
    v0007 = (*qfn2(fn))(qenv(fn), v0007, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    fn = elt(env, 4); /* quotf */
    v0007 = (*qfn2(fn))(qenv(fn), stack[0], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    {
        Lisp_Object v0094 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* multf */
        return (*qfn2(fn))(qenv(fn), v0094, v0007);
    }

v0181:
    v0007 = qvalue(elt(env, 1)); /* t */
    goto v0119;
/* error exit handlers */
v0095:
    popv(3);
    return nil;
}



/* Code for lispapply */

static Lisp_Object CC_lispapply(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0165, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispapply");
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
    v0165 = v0001;
    v0135 = v0000;
/* end of prologue */
    v0158 = v0135;
    if (!consp(v0158)) goto v0082;
    v0158 = elt(env, 1); /* "Apply called with non-id arg" */
    v0165 = v0135;
    v0158 = list2(v0158, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[0];
    v0165 = v0158;
    v0158 = v0165;
    qvalue(elt(env, 2)) = v0158; /* errmsg!* */
    v0158 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0158 == nil)) goto v0136;
    v0158 = v0165;
    fn = elt(env, 4); /* lprie */
    v0158 = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[0];
    goto v0136;

v0136:
    v0158 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0158 = nil;
    { popv(1); return onevalue(v0158); }

v0082:
    v0158 = v0135;
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v0158, v0165);
    }
/* error exit handlers */
v0100:
    popv(1);
    return nil;
}



/* Code for rl_varlat */

static Lisp_Object CC_rl_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_varlat");
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
    v0084 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_varlat!* */
    v0084 = ncons(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    {
        Lisp_Object v0107 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0107, v0084);
    }
/* error exit handlers */
v0087:
    popv(2);
    return nil;
}



/* Code for rl_smmkatl */

static Lisp_Object MS_CDECL CC_rl_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, Lisp_Object v0081, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0051, v0052, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0081,v0066,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0066,v0081);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0169 = v0081;
    v0051 = v0066;
    v0052 = v0001;
    v0055 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smmkatl!* */
    v0169 = list4(v0055, v0052, v0051, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    {
        Lisp_Object v0152 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0152, v0169);
    }
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for sfto_gcdf */

static Lisp_Object CC_sfto_gcdf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf");
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
    v0047 = qvalue(elt(env, 1)); /* !*rldavgcd */
    if (v0047 == nil) goto v0181;
    v0044 = stack[-1];
    v0047 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v0047 = (*qfn2(fn))(qenv(fn), v0044, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    if (!(v0047 == nil)) goto v0162;
    v0044 = stack[0];
    v0047 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v0047 = (*qfn2(fn))(qenv(fn), v0044, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    if (!(v0047 == nil)) goto v0162;
    v0044 = stack[-1];
    v0047 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ezgcdf */
        return (*qfn2(fn))(qenv(fn), v0044, v0047);
    }

v0162:
    v0047 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = v0047; /* !*ezgcd */
    v0044 = stack[-1];
    v0047 = stack[0];
    fn = elt(env, 6); /* gcdf */
    v0047 = (*qfn2(fn))(qenv(fn), v0044, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    { popv(4); return onevalue(v0047); }

v0181:
    v0044 = stack[-1];
    v0047 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); /* gcdf */
        return (*qfn2(fn))(qenv(fn), v0044, v0047);
    }
/* error exit handlers */
v0007:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    popv(4);
    return nil;
v0010:
    popv(4);
    return nil;
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp");
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
    v0131 = v0000;
/* end of prologue */
    v0127 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0127; /* varstack!* */
    v0127 = v0131;
    fn = elt(env, 3); /* resimp1 */
    v0127 = (*qfn1(fn))(qenv(fn), v0127);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0127); }
/* error exit handlers */
v0181:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for qqe_mk2 */

static Lisp_Object MS_CDECL CC_qqe_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0162, v0048;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "qqe_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0155 = v0066;
    v0162 = v0001;
    v0048 = v0000;
/* end of prologue */
    return list3(v0048, v0162, v0155);
}



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_evlmon");
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
    v0123 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v0123);
    }
/* error exit handlers */
v0127:
    popv(1);
    return nil;
}



/* Code for indent!* */

static Lisp_Object CC_indentH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0159;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indent*");
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
    v0159 = stack[0];
    v0050 = qvalue(elt(env, 1)); /* t */
    if (!(equal(v0159, v0050))) goto v0123;
    v0159 = qvalue(elt(env, 2)); /* indent */
    v0050 = qvalue(elt(env, 3)); /* ind */
    v0050 = plus2(v0159, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0050; /* indent */
    goto v0123;

v0123:
    v0050 = stack[0];
    if (!(v0050 == nil)) goto v0103;
    v0159 = qvalue(elt(env, 2)); /* indent */
    v0050 = qvalue(elt(env, 3)); /* ind */
    v0050 = difference2(v0159, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0050; /* indent */
    goto v0103;

v0103:
    v0050 = nil;
    { popv(2); return onevalue(v0050); }
/* error exit handlers */
v0165:
    popv(2);
    return nil;
}



/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0083, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_compl");
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
    v0083 = v0000;
/* end of prologue */
    v0055 = v0083;
    v0055 = Lconsp(nil, v0055);
    env = stack[0];
    if (v0055 == nil) goto v0123;
    v0055 = v0083;
    v0082 = qcar(v0055);
    v0055 = elt(env, 1); /* arbcomplex */
    if (v0082 == v0055) goto v0088;
    v0055 = v0083;
    v0055 = qcdr(v0055);
    fn = elt(env, 4); /* multi_isarb_compl */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    goto v0123;

v0123:
    v0055 = nil;
    { popv(1); return onevalue(v0055); }

v0088:
    v0055 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0055; /* found_compl */
    goto v0123;
/* error exit handlers */
v0152:
    popv(1);
    return nil;
}



/* Code for round!:mt */

static Lisp_Object CC_roundTmt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round:mt");
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
    v0117 = stack[-2];
    v0091 = elt(env, 1); /* !:rd!: */
    if (!consp(v0117)) goto v0051;
    v0117 = qcar(v0117);
    if (!(v0117 == v0091)) goto v0051;
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    v0091 = (consp(v0091) ? nil : lisp_true);
    v0091 = (v0091 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0091 == nil) goto v0045;
    v0091 = stack[-1];
    v0091 = integerp(v0091);
    if (v0091 == nil) goto v0152;
    v0117 = stack[-1];
    v0091 = (Lisp_Object)1; /* 0 */
    v0091 = (Lisp_Object)greaterp2(v0117, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0091 = v0091 ? lisp_true : nil;
    env = stack[-4];
    goto v0119;

v0119:
    if (v0091 == nil) goto v0073;
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    v0091 = qcar(v0091);
    v0091 = Labsval(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    fn = elt(env, 4); /* msd */
    v0117 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0091 = stack[-1];
    v0091 = difference2(v0117, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0117 = sub1(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    stack[-1] = v0117;
    v0091 = (Lisp_Object)1; /* 0 */
    v0091 = (Lisp_Object)lessp2(v0117, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0091 = v0091 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0091 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0117 = stack[-1];
    v0091 = (Lisp_Object)1; /* 0 */
    if (v0117 == v0091) goto v0168;
    stack[-3] = elt(env, 1); /* !:rd!: */
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    stack[0] = qcar(v0091);
    v0091 = stack[-1];
    v0091 = negate(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    v0117 = qcdr(v0091);
    v0091 = stack[-1];
    v0091 = plus2(v0117, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0091 = list2star(stack[-3], stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v0091);
    }

v0168:
    v0091 = stack[-2];
    {
        popv(5);
        fn = elt(env, 5); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v0091);
    }

v0073:
    stack[0] = (Lisp_Object)1; /* 0 */
    v0117 = elt(env, 3); /* "Invalid argument to" */
    v0091 = elt(env, 0); /* round!:mt */
    v0091 = list2(v0117, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    {
        Lisp_Object v0033 = stack[0];
        popv(5);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v0033, v0091);
    }

v0152:
    v0091 = qvalue(elt(env, 2)); /* nil */
    goto v0119;

v0045:
    v0091 = qvalue(elt(env, 2)); /* nil */
    goto v0119;

v0051:
    v0091 = qvalue(elt(env, 2)); /* nil */
    goto v0088;
/* error exit handlers */
v0032:
    popv(5);
    return nil;
}



/* Code for revlis */

static Lisp_Object CC_revlis(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revlis");
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
    v0069 = v0000;
/* end of prologue */
    stack[-3] = v0069;
    v0069 = stack[-3];
    if (v0069 == nil) goto v0084;
    v0069 = stack[-3];
    v0069 = qcar(v0069);
    fn = elt(env, 2); /* reval */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0069 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    stack[-1] = v0069;
    stack[-2] = v0069;
    goto v0131;

v0131:
    v0069 = stack[-3];
    v0069 = qcdr(v0069);
    stack[-3] = v0069;
    v0069 = stack[-3];
    if (v0069 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0069 = stack[-3];
    v0069 = qcar(v0069);
    fn = elt(env, 2); /* reval */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0069 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0069 = Lrplacd(nil, stack[0], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0069 = stack[-1];
    v0069 = qcdr(v0069);
    stack[-1] = v0069;
    goto v0131;

v0084:
    v0069 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0069); }
/* error exit handlers */
v0184:
    popv(5);
    return nil;
}



/* Code for subscriptedvarp */

static Lisp_Object CC_subscriptedvarp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subscriptedvarp");
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
    v0083 = qvalue(elt(env, 1)); /* nil */
    v0055 = stack[0];
    fn = elt(env, 3); /* symtabget */
    v0055 = (*qfn2(fn))(qenv(fn), v0083, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    v0083 = Llength(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    v0055 = (Lisp_Object)33; /* 2 */
    v0055 = (Lisp_Object)greaterp2(v0083, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0055 == nil)) { popv(2); return onevalue(v0055); }
    v0055 = stack[0];
    v0083 = elt(env, 2); /* subscripted */
        popv(2);
        return Lflagp(nil, v0055, v0083);
/* error exit handlers */
v0152:
    popv(2);
    return nil;
}



/* Code for ordad */

static Lisp_Object CC_ordad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordad");
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
    goto v0119;

v0119:
    v0182 = stack[0];
    if (v0182 == nil) goto v0158;
    v0095 = stack[-1];
    v0182 = stack[0];
    v0182 = qcar(v0182);
    fn = elt(env, 2); /* ordp */
    v0182 = (*qfn2(fn))(qenv(fn), v0095, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    if (!(v0182 == nil)) goto v0158;
    v0182 = stack[0];
    v0095 = qcar(v0182);
    v0182 = stack[-2];
    v0182 = cons(v0095, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    stack[-2] = v0182;
    v0182 = stack[0];
    v0182 = qcdr(v0182);
    stack[0] = v0182;
    goto v0119;

v0158:
    v0095 = stack[-1];
    v0182 = stack[0];
    v0182 = cons(v0095, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    stack[0] = v0182;
    goto v0045;

v0045:
    v0182 = stack[-2];
    if (v0182 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0182 = stack[-2];
    v0182 = qcdr(v0182);
    stack[-1] = v0182;
    v0095 = stack[-2];
    v0182 = stack[0];
    v0182 = Lrplacd(nil, v0095, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    v0182 = stack[-2];
    stack[0] = v0182;
    v0182 = stack[-1];
    stack[-2] = v0182;
    goto v0045;
/* error exit handlers */
v0105:
    popv(4);
    return nil;
}



/* Code for xdiv */

static Lisp_Object CC_xdiv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdiv");
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
    stack[-2] = stack[-1];
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    if (equal(stack[-2], v0178)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0069 = stack[-1];
    v0178 = stack[0];
    fn = elt(env, 1); /* sublistp */
    v0178 = (*qfn2(fn))(qenv(fn), v0069, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    if (v0178 == nil) goto v0048;
    v0069 = stack[0];
    v0178 = stack[-1];
    fn = elt(env, 2); /* listdiff */
    v0178 = (*qfn2(fn))(qenv(fn), v0069, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    stack[0] = v0178;
    if (!(v0178 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0178 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v0178);

v0048:
    v0178 = nil;
    { popv(4); return onevalue(v0178); }
/* error exit handlers */
v0160:
    popv(4);
    return nil;
}



/* Code for scprint */

static Lisp_Object CC_scprint(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0095;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scprint");
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
    v0095 = v0000;
/* end of prologue */
    v0182 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0182; /* posn!* */
    v0182 = v0095;
    stack[-1] = v0182;
    goto v0097;

v0097:
    v0182 = stack[-1];
    if (v0182 == nil) goto v0181;
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    stack[0] = v0182;
    v0182 = stack[0];
    v0182 = qcar(v0182);
    v0095 = qcdr(v0182);
    v0182 = stack[-2];
    if (!(equal(v0095, v0182))) goto v0164;
    v0182 = stack[0];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0095 = qcar(v0182);
    v0182 = qvalue(elt(env, 1)); /* posn!* */
    v0095 = difference2(v0095, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-4];
    stack[-3] = v0095;
    v0182 = (Lisp_Object)1; /* 0 */
    v0182 = (Lisp_Object)lessp2(v0095, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0182 = v0182 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0182 == nil)) goto v0049;
    v0182 = stack[-3];
    v0182 = Lxtab(nil, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-4];
    goto v0049;

v0049:
    v0182 = stack[0];
    v0182 = qcdr(v0182);
    v0182 = Lprinc(nil, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-4];
    v0182 = stack[0];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0182 = qcdr(v0182);
    qvalue(elt(env, 1)) = v0182; /* posn!* */
    goto v0164;

v0164:
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    stack[-1] = v0182;
    goto v0097;

v0181:
    v0182 = nil;
    { popv(5); return onevalue(v0182); }
/* error exit handlers */
v0106:
    popv(5);
    return nil;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0057, v0163, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0163 = v0001;
    v0006 = v0000;
/* end of prologue */
    v0044 = v0006;
    if (v0044 == nil) goto v0123;
    v0044 = v0163;
    if (v0044 == nil) return onevalue(v0006);
    v0057 = v0006;
    v0044 = v0163;
    if (equal(v0057, v0044)) goto v0107;
    v0044 = v0006;
    if (!consp(v0044)) goto v0052;
    v0044 = qvalue(elt(env, 1)); /* nil */
    goto v0051;

v0051:
    if (v0044 == nil) goto v0045;
    v0044 = v0006;
    v0057 = v0163;
    return difference2(v0044, v0057);

v0045:
    v0057 = v0006;
    v0044 = elt(env, 2); /* difference */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0057, v0163, v0044);
    }

v0052:
    v0044 = v0163;
    v0044 = (consp(v0044) ? nil : lisp_true);
    goto v0051;

v0107:
    v0044 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0044);

v0123:
    v0044 = v0163;
    {
        fn = elt(env, 4); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v0044);
    }
}



/* Code for prin2!-downcase */

static Lisp_Object CC_prin2Kdowncase(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0184, v0153, v0098;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2-downcase");
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
    v0184 = v0000;
/* end of prologue */
    v0184 = Lexplodec(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    stack[0] = v0184;
    goto v0123;

v0123:
    v0184 = stack[0];
    if (v0184 == nil) goto v0097;
    v0184 = stack[0];
    v0184 = qcar(v0184);
    v0098 = v0184;
    v0184 = v0098;
    v0184 = Lalpha_char_p(nil, v0184);
    env = stack[-1];
    if (v0184 == nil) goto v0178;
    v0153 = v0098;
    v0184 = qvalue(elt(env, 2)); /* charassoc!* */
    v0184 = Latsoc(nil, v0153, v0184);
    v0153 = v0184;
    v0184 = v0153;
    if (v0184 == nil) goto v0135;
    v0184 = v0153;
    v0184 = qcdr(v0184);
    goto v0089;

v0089:
    v0184 = Lprinc(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    goto v0056;

v0056:
    v0184 = stack[0];
    v0184 = qcdr(v0184);
    stack[0] = v0184;
    goto v0123;

v0135:
    v0184 = v0098;
    goto v0089;

v0178:
    v0184 = v0098;
    v0184 = Lprinc(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    goto v0056;

v0097:
    v0184 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0184); }
/* error exit handlers */
v0173:
    popv(2);
    return nil;
}



/* Code for tensopp */

static Lisp_Object CC_tensopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0134, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensopp");
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
    v0134 = v0000;
/* end of prologue */
    v0133 = v0134;
    if (symbolp(v0133)) goto v0154;
    v0133 = qvalue(elt(env, 1)); /* nil */
    goto v0127;

v0127:
    if (!(v0133 == nil)) { popv(1); return onevalue(v0133); }
    v0133 = v0134;
    if (!consp(v0133)) goto v0006;
    v0133 = v0134;
    v0132 = qcar(v0133);
    v0133 = elt(env, 2); /* phystype */
    v0132 = get(v0132, v0133);
    env = stack[0];
    v0133 = elt(env, 3); /* tensor */
    if (v0132 == v0133) goto v0049;
    v0133 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0133); }

v0049:
    v0133 = v0134;
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    fn = elt(env, 4); /* isanindex */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0133 = (v0133 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0133); }

v0006:
    v0133 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0133); }

v0154:
    v0132 = v0134;
    v0133 = elt(env, 2); /* phystype */
    v0132 = get(v0132, v0133);
    env = stack[0];
    v0133 = elt(env, 3); /* tensor */
    v0133 = (v0132 == v0133 ? lisp_true : nil);
    goto v0127;
/* error exit handlers */
v0059:
    popv(1);
    return nil;
}



/* Code for negf */

static Lisp_Object CC_negf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negf");
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
    goto v0123;

v0123:
    v0146 = stack[-1];
    if (v0146 == nil) goto v0119;
    v0146 = stack[-1];
    if (!consp(v0146)) goto v0048;
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    v0146 = (consp(v0146) ? nil : lisp_true);
    goto v0162;

v0162:
    if (v0146 == nil) goto v0168;
    stack[0] = stack[-2];
    v0146 = stack[-1];
    if (!consp(v0146)) goto v0069;
    v0146 = qvalue(elt(env, 4)); /* nil */
    goto v0165;

v0165:
    if (v0146 == nil) goto v0094;
    v0186 = qvalue(elt(env, 2)); /* dmode!* */
    v0146 = elt(env, 5); /* i2d */
    v0186 = get(v0186, v0146);
    env = stack[-3];
    v0146 = stack[-1];
    v0146 = Lapply1(nil, v0186, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-3];
    goto v0049;

v0049:
    fn = elt(env, 6); /* !:minus */
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-3];
    {
        Lisp_Object v0126 = stack[0];
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0126, v0146);
    }

v0094:
    v0146 = stack[-1];
    goto v0049;

v0069:
    v0186 = qvalue(elt(env, 2)); /* dmode!* */
    v0146 = elt(env, 3); /* convert */
    v0146 = Lflagp(nil, v0186, v0146);
    env = stack[-3];
    goto v0165;

v0168:
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    stack[0] = qcar(v0146);
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    v0186 = CC_negf(env, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-3];
    v0146 = stack[-2];
    v0146 = acons(stack[0], v0186, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-3];
    stack[-2] = v0146;
    v0146 = stack[-1];
    v0146 = qcdr(v0146);
    stack[-1] = v0146;
    goto v0123;

v0048:
    v0146 = qvalue(elt(env, 1)); /* t */
    goto v0162;

v0119:
    v0146 = stack[-2];
    {
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0146);
    }
/* error exit handlers */
v0125:
    popv(4);
    return nil;
}



/* Code for add2inputbuf */

static Lisp_Object CC_add2inputbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0100, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2inputbuf");
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
    v0100 = v0001;
    v0135 = v0000;
/* end of prologue */
    v0101 = qvalue(elt(env, 1)); /* !*int */
    if (v0101 == nil) goto v0084;
    v0101 = qvalue(elt(env, 2)); /* ifl!* */
    if (!(v0101 == nil)) goto v0084;
    v0101 = qvalue(elt(env, 4)); /* !*nosave!* */
    goto v0097;

v0097:
    if (v0101 == nil) goto v0055;
    v0135 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0135); }

v0055:
    v0101 = qvalue(elt(env, 6)); /* statcounter */
    v0100 = list3(v0101, v0100, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[0];
    v0135 = qvalue(elt(env, 7)); /* inputbuflis!* */
    v0135 = cons(v0100, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[0];
    qvalue(elt(env, 7)) = v0135; /* inputbuflis!* */
    v0135 = nil;
    { popv(1); return onevalue(v0135); }

v0084:
    v0101 = qvalue(elt(env, 3)); /* t */
    goto v0097;
/* error exit handlers */
v0178:
    popv(1);
    return nil;
}



/* Code for fs!:angle!-order */

static Lisp_Object CC_fsTangleKorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0175, v0189;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:angle-order");
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
    v0122 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0122;
    v0175 = stack[-3];
    v0122 = (Lisp_Object)33; /* 2 */
    v0122 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    stack[-1] = v0122;
    v0175 = stack[-2];
    v0122 = (Lisp_Object)33; /* 2 */
    v0122 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    stack[0] = v0122;
    goto v0090;

v0090:
    v0175 = stack[-1];
    v0122 = stack[-4];
    v0189 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    v0175 = stack[0];
    v0122 = stack[-4];
    v0122 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    v0122 = difference2(v0189, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-5];
    v0189 = v0122;
    v0175 = v0189;
    v0122 = (Lisp_Object)1; /* 0 */
    if (v0175 == v0122) goto v0153;
    v0175 = v0189;
    v0122 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v0175, v0122);

v0153:
    v0122 = stack[-4];
    v0122 = add1(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-5];
    stack[-4] = v0122;
    v0175 = stack[-4];
    v0122 = (Lisp_Object)129; /* 8 */
    v0122 = (Lisp_Object)lessp2(v0175, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0122 = v0122 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0122 == nil)) goto v0090;
    v0175 = stack[-3];
    v0122 = (Lisp_Object)17; /* 1 */
    v0189 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    v0175 = stack[-2];
    v0122 = (Lisp_Object)17; /* 1 */
    v0122 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    if (equal(v0189, v0122)) goto v0092;
    v0175 = stack[-3];
    v0122 = (Lisp_Object)17; /* 1 */
    v0175 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    v0122 = elt(env, 2); /* sin */
    if (v0175 == v0122) goto v0167;
    v0122 = qvalue(elt(env, 3)); /* t */
    { popv(6); return onevalue(v0122); }

v0167:
    v0122 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0122); }

v0092:
    v0122 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0122); }
/* error exit handlers */
v0091:
    popv(6);
    return nil;
}



/* Code for mo!=sum */

static Lisp_Object CC_moMsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0044, v0057;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=sum");
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
    v0057 = nil;
    goto v0119;

v0119:
    v0047 = stack[-1];
    if (v0047 == nil) goto v0135;
    v0047 = stack[0];
    if (v0047 == nil) goto v0135;
    v0047 = stack[-1];
    v0044 = qcar(v0047);
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0047 = (Lisp_Object)(int32_t)((int32_t)v0044 + (int32_t)v0047 - TAG_FIXNUM);
    v0044 = v0057;
    v0047 = cons(v0047, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0057 = v0047;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    stack[-1] = v0047;
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0119;

v0135:
    v0047 = v0057;
    v0044 = Lnreverse(nil, v0047);
    v0047 = stack[-1];
    if (v0047 == nil) goto v0173;
    v0047 = stack[-1];
    goto v0178;

v0178:
        popv(3);
        return Lappend(nil, v0044, v0047);

v0173:
    v0047 = stack[0];
    goto v0178;
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for rev */

static Lisp_Object CC_rev(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0052, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rev");
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
    v0051 = v0001;
    v0052 = v0000;
/* end of prologue */

v0127:
    v0055 = v0052;
    if (v0055 == nil) { popv(2); return onevalue(v0051); }
    v0055 = v0052;
    v0055 = qcdr(v0055);
    stack[0] = v0055;
    v0052 = qcar(v0052);
    v0051 = cons(v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0052 = stack[0];
    goto v0127;
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for mod!# */

static Lisp_Object CC_modC(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod#");
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
    v0089 = v0000;
/* end of prologue */
    v0049 = v0089;
    v0089 = qvalue(elt(env, 1)); /* current!-modulus */
    v0089 = Cremainder(v0049, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-1];
    stack[0] = v0089;
    v0049 = stack[0];
    v0089 = (Lisp_Object)1; /* 0 */
    v0089 = (Lisp_Object)lessp2(v0049, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    v0089 = v0089 ? lisp_true : nil;
    env = stack[-1];
    if (v0089 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0089 = stack[0];
    v0049 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return plus2(v0089, v0049);
/* error exit handlers */
v0159:
    popv(2);
    return nil;
}



/* Code for times!-term!-mod!-p */

static Lisp_Object CC_timesKtermKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0113, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-term-mod-p");
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
    v0112 = stack[-1];
    if (v0112 == nil) goto v0123;
    v0112 = stack[-1];
    if (!consp(v0112)) goto v0087;
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    v0112 = (consp(v0112) ? nil : lisp_true);
    goto v0088;

v0088:
    if (v0112 == nil) goto v0069;
    v0112 = stack[-2];
    stack[0] = qcar(v0112);
    v0112 = stack[-2];
    v0113 = qcdr(v0112);
    v0112 = stack[-1];
    fn = elt(env, 3); /* multiply!-by!-constant!-mod!-p */
    v0113 = (*qfn2(fn))(qenv(fn), v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0112 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0022 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0022, v0113, v0112);
    }

v0069:
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0113 = qcar(v0112);
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    if (equal(v0113, v0112)) goto v0132;
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0113 = qcar(v0112);
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    fn = elt(env, 5); /* ordop */
    v0112 = (*qfn2(fn))(qenv(fn), v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    if (v0112 == nil) goto v0199;
    v0112 = stack[-2];
    stack[0] = qcar(v0112);
    v0112 = stack[-2];
    v0113 = qcdr(v0112);
    v0112 = stack[-1];
    fn = elt(env, 6); /* times!-mod!-p */
    v0113 = (*qfn2(fn))(qenv(fn), v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0112 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0200 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0200, v0113, v0112);
    }

v0199:
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    stack[-3] = qcar(v0112);
    v0113 = stack[-2];
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    stack[0] = CC_timesKtermKmodKp(env, v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0113 = stack[-2];
    v0112 = stack[-1];
    v0112 = qcdr(v0112);
    v0112 = CC_timesKtermKmodKp(env, v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    {
        Lisp_Object v0201 = stack[-3];
        Lisp_Object v0202 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0201, v0202, v0112);
    }

v0132:
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    fn = elt(env, 7); /* fkern */
    v0062 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0113 = qcdr(v0112);
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    v0112 = (Lisp_Object)(int32_t)((int32_t)v0113 + (int32_t)v0112 - TAG_FIXNUM);
    fn = elt(env, 8); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0062, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0112 = stack[-2];
    v0113 = qcdr(v0112);
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    fn = elt(env, 6); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0113 = stack[-2];
    v0112 = stack[-1];
    v0112 = qcdr(v0112);
    v0112 = CC_timesKtermKmodKp(env, v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    {
        Lisp_Object v0111 = stack[-3];
        Lisp_Object v0110 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0111, v0110, v0112);
    }

v0087:
    v0112 = qvalue(elt(env, 2)); /* t */
    goto v0088;

v0123:
    v0112 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0112); }
/* error exit handlers */
v0023:
    popv(5);
    return nil;
}



/* Code for anforml */

static Lisp_Object CC_anforml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anforml");
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

v0127:
    v0186 = stack[0];
    if (!consp(v0186)) goto v0123;
    v0186 = stack[0];
    v0186 = qcar(v0186);
    fn = elt(env, 6); /* anform */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    stack[0] = v0186;
    goto v0127;

v0123:
    v0186 = stack[0];
    if (v0186 == nil) goto v0154;
    v0186 = qvalue(elt(env, 2)); /* !*globals */
    if (v0186 == nil) goto v0154;
    v0186 = stack[0];
    if (v0186 == nil) goto v0154;
    v0150 = stack[0];
    v0186 = lisp_true;
    if (v0150 == v0186) goto v0010;
    v0186 = stack[0];
    if (symbolp(v0186)) goto v0099;
    v0186 = qvalue(elt(env, 1)); /* nil */
    goto v0089;

v0089:
    if (v0186 == nil) goto v0154;
    v0150 = stack[0];
    v0186 = elt(env, 4); /* glb2rf */
    v0186 = Lflagp(nil, v0150, v0186);
    env = stack[-1];
    if (!(v0186 == nil)) goto v0154;
    v0186 = stack[0];
    v0150 = ncons(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0186 = elt(env, 4); /* glb2rf */
    v0186 = Lflag(nil, v0150, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0150 = stack[0];
    v0186 = qvalue(elt(env, 5)); /* globs!* */
    v0186 = cons(v0150, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0186; /* globs!* */
    goto v0154;

v0154:
    v0186 = nil;
    { popv(2); return onevalue(v0186); }

v0099:
    v0150 = stack[0];
    v0186 = qvalue(elt(env, 3)); /* locls!* */
    v0186 = Lassoc(nil, v0150, v0186);
    v0186 = (v0186 == nil ? lisp_true : nil);
    goto v0089;

v0010:
    v0186 = qvalue(elt(env, 1)); /* nil */
    goto v0089;
/* error exit handlers */
v0188:
    popv(2);
    return nil;
}



/* Code for cl_cflip */

static Lisp_Object CC_cl_cflip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_cflip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0001;
    v0107 = v0000;
/* end of prologue */
    if (!(v0087 == nil)) return onevalue(v0107);
    v0087 = v0107;
    {
        fn = elt(env, 1); /* cl_flip */
        return (*qfn1(fn))(qenv(fn), v0087);
    }
}



/* Code for get!+col!+nr */

static Lisp_Object CC_getLcolLnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+col+nr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0131 = v0000;
/* end of prologue */
    v0131 = qcar(v0131);
        return Llength(nil, v0131);
}



/* Code for mri_0mk2 */

static Lisp_Object MS_CDECL CC_mri_0mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0154, v0137, v0136;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mri_0mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0137 = v0066;
    v0056 = v0001;
    v0154 = v0000;
/* end of prologue */
    v0136 = qvalue(elt(env, 1)); /* nil */
    return list4(v0154, v0056, v0136, v0137);
}



/* Code for pasf_smwupdknowl */

static Lisp_Object MS_CDECL CC_pasf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, Lisp_Object v0081, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0100, v0101, v0178, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0100 = v0081;
    v0101 = v0066;
    v0178 = v0001;
    v0069 = v0000;
/* end of prologue */
    v0135 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0135 == nil) goto v0051;
    v0135 = v0069;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0135, v0178, v0101, v0100);
    }

v0051:
    v0135 = v0069;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0135, v0178, v0101, v0100);
    }
}



/* Code for list2string */

static Lisp_Object CC_list2string(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list2string");
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
    v0155 = stack[0];
    if (v0155 == nil) goto v0123;
    v0155 = stack[0];
    v0155 = qcar(v0155);
    v0155 = Lprinc(nil, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    v0155 = stack[0];
    v0155 = qcdr(v0155);
    v0155 = CC_list2string(env, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    goto v0123;

v0123:
    v0155 = nil;
    { popv(2); return onevalue(v0155); }
/* error exit handlers */
v0048:
    popv(2);
    return nil;
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0083, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_int");
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
    v0083 = v0000;
/* end of prologue */
    v0055 = v0083;
    v0055 = Lconsp(nil, v0055);
    env = stack[0];
    if (v0055 == nil) goto v0123;
    v0055 = v0083;
    v0082 = qcar(v0055);
    v0055 = elt(env, 1); /* arbint */
    if (v0082 == v0055) goto v0088;
    v0055 = v0083;
    v0055 = qcdr(v0055);
    fn = elt(env, 4); /* multi_isarb_int */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    goto v0123;

v0123:
    v0055 = nil;
    { popv(1); return onevalue(v0055); }

v0088:
    v0055 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0055; /* found_int */
    goto v0123;
/* error exit handlers */
v0152:
    popv(1);
    return nil;
}



/* Code for rd!:minus */

static Lisp_Object CC_rdTminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0159;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:minus");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    if (!consp(v0050)) goto v0181;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    v0050 = qcar(v0050);
    v0159 = negate(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    {
        Lisp_Object v0100 = stack[-1];
        popv(2);
        return list2star(v0100, v0159, v0050);
    }

v0181:
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    v0050 = negate(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    {
        Lisp_Object v0101 = stack[-1];
        popv(2);
        return cons(v0101, v0050);
    }
/* error exit handlers */
v0135:
    popv(2);
    return nil;
}



/* Code for bound */

static Lisp_Object CC_bound(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bound");
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
    v0136 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* binding */
    v0136 = (*qfn1(fn))(qenv(fn), v0136);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[0];
    v0164 = v0136;
    v0136 = v0164;
    if (v0136 == nil) goto v0131;
    v0136 = v0164;
    v0164 = elt(env, 2); /* unbound */
        popv(1);
        return Lneq(nil, v0136, v0164);

v0131:
    v0136 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0136); }
/* error exit handlers */
v0102:
    popv(1);
    return nil;
}



/* Code for vevcompless!? */

static Lisp_Object CC_vevcomplessW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevcompless?");
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
    v0154 = v0001;
    v0056 = v0000;
/* end of prologue */
    stack[0] = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* evcomp */
    v0056 = (*qfn2(fn))(qenv(fn), v0154, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    v0056 = (stack[0] == v0056 ? lisp_true : nil);
    { popv(1); return onevalue(v0056); }
/* error exit handlers */
v0136:
    popv(1);
    return nil;
}



/* Code for fast_unchecked_getmatelem */

static Lisp_Object CC_fast_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fast_unchecked_getmatelem");
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
    v0169 = stack[0];
    v0169 = qcar(v0169);
    v0051 = qcdr(v0169);
    v0169 = stack[0];
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    fn = elt(env, 1); /* pnth */
    v0169 = (*qfn2(fn))(qenv(fn), v0051, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    v0051 = qcar(v0169);
    v0169 = stack[0];
    v0169 = qcdr(v0169);
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    fn = elt(env, 1); /* pnth */
    v0169 = (*qfn2(fn))(qenv(fn), v0051, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    v0169 = qcar(v0169);
    { popv(2); return onevalue(v0169); }
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for mkwedge */

static Lisp_Object CC_mkwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0155, v0162;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkwedge");
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
    v0107 = v0000;
/* end of prologue */
    v0162 = v0107;
    v0155 = (Lisp_Object)17; /* 1 */
    v0107 = (Lisp_Object)17; /* 1 */
    v0107 = list2star(v0162, v0155, v0107);
    errexit();
    return ncons(v0107);
}



/* Code for physopp!* */

static Lisp_Object CC_physoppH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp*");
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
    v0105 = stack[0];
    fn = elt(env, 6); /* physopp */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-1];
    if (!(v0105 == nil)) { popv(2); return onevalue(v0105); }
    v0105 = stack[0];
    if (!consp(v0105)) goto v0094;
    v0105 = stack[0];
    v0106 = qcar(v0105);
    v0105 = elt(env, 1); /* physopfn */
    v0105 = Lflagp(nil, v0106, v0105);
    env = stack[-1];
    if (v0105 == nil) goto v0050;
    v0105 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0105); }

v0050:
    v0105 = stack[0];
    v0106 = qcar(v0105);
    v0105 = elt(env, 3); /* physoparith */
    v0105 = Lflagp(nil, v0106, v0105);
    env = stack[-1];
    if (v0105 == nil) goto v0045;
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    fn = elt(env, 7); /* hasonephysop */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-1];
    goto v0152;

v0152:
    if (!(v0105 == nil)) { popv(2); return onevalue(v0105); }
    v0105 = stack[0];
    v0106 = qcar(v0105);
    v0105 = elt(env, 5); /* physopmapping */
    v0105 = Lflagp(nil, v0106, v0105);
    env = stack[-1];
    if (v0105 == nil) goto v0059;
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    {
        popv(2);
        fn = elt(env, 7); /* hasonephysop */
        return (*qfn1(fn))(qenv(fn), v0105);
    }

v0059:
    v0105 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v0105); }

v0045:
    v0105 = qvalue(elt(env, 4)); /* nil */
    goto v0152;

v0094:
    v0105 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v0105); }
/* error exit handlers */
v0168:
    popv(2);
    return nil;
}



/* Code for getroad */

static Lisp_Object CC_getroad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0100, v0101, v0178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getroad");
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
    v0101 = v0001;
    v0178 = v0000;
/* end of prologue */

v0123:
    v0135 = v0101;
    if (v0135 == nil) goto v0119;
    v0135 = v0178;
    v0100 = qcdr(v0135);
    v0135 = v0101;
    v0135 = qcar(v0135);
    v0135 = qcdr(v0135);
    if (equal(v0100, v0135)) goto v0170;
    v0135 = v0101;
    v0135 = qcdr(v0135);
    v0101 = v0135;
    goto v0123;

v0170:
    v0135 = v0178;
    v0135 = qcar(v0135);
    v0100 = v0101;
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    fn = elt(env, 1); /* qassoc */
    v0135 = (*qfn2(fn))(qenv(fn), v0135, v0100);
    errexit();
    v0135 = qcdr(v0135);
    return onevalue(v0135);

v0119:
    v0135 = (Lisp_Object)17; /* 1 */
    return onevalue(v0135);
}



/* Code for command1 */

static Lisp_Object MS_CDECL CC_command1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0052, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command1");
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
    fn = elt(env, 7); /* scan */
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[0];
    v0051 = qvalue(elt(env, 1)); /* ifl!* */
    if (v0051 == nil) goto v0127;
    v0051 = qvalue(elt(env, 1)); /* ifl!* */
    v0055 = qcar(v0051);
    v0052 = (Lisp_Object)17; /* 1 */
    v0051 = qvalue(elt(env, 3)); /* curline!* */
    v0051 = list2star(v0055, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[0];
    goto v0123;

v0123:
    qvalue(elt(env, 4)) = v0051; /* cloc!* */
    v0051 = qvalue(elt(env, 5)); /* cursym!* */
    qvalue(elt(env, 6)) = v0051; /* key!* */
    v0051 = qvalue(elt(env, 2)); /* nil */
    {
        popv(1);
        fn = elt(env, 8); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v0051);
    }

v0127:
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0123;
/* error exit handlers */
v0083:
    popv(1);
    return nil;
}



/* Code for mo!=degcomp */

static Lisp_Object CC_moMdegcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0178, v0069, v0179;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=degcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0178 = v0001;
    v0069 = v0000;
/* end of prologue */

v0123:
    v0101 = v0069;
    if (v0101 == nil) goto v0119;
    v0101 = v0069;
    v0179 = qcar(v0101);
    v0101 = v0178;
    v0101 = qcar(v0101);
    if (equal(v0179, v0101)) goto v0088;
    v0101 = v0069;
    v0101 = qcar(v0101);
    v0178 = qcar(v0178);
    if (((int32_t)(v0101)) < ((int32_t)(v0178))) goto v0051;
    v0101 = (Lisp_Object)17; /* 1 */
    return onevalue(v0101);

v0051:
    v0101 = (Lisp_Object)-15; /* -1 */
    return onevalue(v0101);

v0088:
    v0101 = v0069;
    v0101 = qcdr(v0101);
    v0069 = v0101;
    v0101 = v0178;
    v0101 = qcdr(v0101);
    v0178 = v0101;
    goto v0123;

v0119:
    v0101 = (Lisp_Object)1; /* 0 */
    return onevalue(v0101);
}



/* Code for vecp */

static Lisp_Object CC_vecp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0071, v0203, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecp");
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
    v0070 = v0203;
    if (v0070 == nil) goto v0084;
    v0070 = v0203;
    v0070 = (is_number(v0070) ? lisp_true : nil);
    goto v0097;

v0097:
    if (v0070 == nil) goto v0119;
    v0070 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0070); }

v0119:
    v0070 = v0203;
    if (!consp(v0070)) goto v0090;
    v0070 = v0203;
    v0070 = Lthreevectorp(nil, v0070);
    env = stack[0];
    if (v0070 == nil) goto v0045;
    v0070 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0070); }

v0045:
    v0070 = v0203;
    v0070 = qcar(v0070);
    v0030 = v0070;
    if (!consp(v0070)) goto v0132;
    v0070 = qvalue(elt(env, 2)); /* nil */
    goto v0046;

v0046:
    if (v0070 == nil) goto v0092;
    v0070 = v0203;
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    {
        popv(1);
        fn = elt(env, 8); /* isvectorindex */
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0092:
    v0071 = v0030;
    v0070 = elt(env, 5); /* vectorfn */
    v0070 = Lflagp(nil, v0071, v0070);
    env = stack[0];
    if (v0070 == nil) goto v0204;
    v0070 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0070); }

v0204:
    v0071 = v0030;
    v0070 = elt(env, 6); /* varithop */
    v0070 = Lflagp(nil, v0071, v0070);
    env = stack[0];
    if (v0070 == nil) goto v0060;
    v0070 = qvalue(elt(env, 1)); /* t */
    goto v0205;

v0205:
    if (v0070 == nil) goto v0187;
    v0070 = v0203;
    v0070 = qcdr(v0070);
    {
        popv(1);
        fn = elt(env, 9); /* hasonevector */
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0187:
    v0070 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0070); }

v0060:
    v0071 = v0030;
    v0070 = elt(env, 7); /* vectormapping */
    v0070 = Lflagp(nil, v0071, v0070);
    env = stack[0];
    goto v0205;

v0132:
    v0071 = v0030;
    v0070 = elt(env, 3); /* rtype */
    v0071 = get(v0071, v0070);
    env = stack[0];
    v0070 = elt(env, 4); /* !3vector */
    v0070 = (v0071 == v0070 ? lisp_true : nil);
    goto v0046;

v0090:
    v0071 = v0203;
    v0070 = elt(env, 3); /* rtype */
    v0071 = get(v0071, v0070);
    env = stack[0];
    v0070 = elt(env, 4); /* !3vector */
    if (v0071 == v0070) goto v0170;
    v0070 = v0203;
        popv(1);
        return Lthreevectorp(nil, v0070);

v0170:
    v0070 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0070); }

v0084:
    v0070 = qvalue(elt(env, 1)); /* t */
    goto v0097;
}



/* Code for pv_sort */

static Lisp_Object CC_pv_sort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort");
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
    v0164 = v0000;
/* end of prologue */
    v0136 = v0164;
    if (v0136 == nil) goto v0074;
    v0136 = v0164;
    stack[0] = qcdr(v0136);
    v0136 = v0164;
    v0136 = qcar(v0136);
    v0136 = ncons(v0136);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-1];
    {
        Lisp_Object v0170 = stack[0];
        popv(2);
        fn = elt(env, 2); /* pv_sort1 */
        return (*qfn2(fn))(qenv(fn), v0170, v0136);
    }

v0074:
    v0136 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0136); }
/* error exit handlers */
v0103:
    popv(2);
    return nil;
}



/* Code for !*modular2f */

static Lisp_Object CC_Hmodular2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0206, v0166;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *modular2f");
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

v0181:
    v0166 = stack[0];
    v0206 = (Lisp_Object)1; /* 0 */
    if (v0166 == v0206) goto v0131;
    v0206 = qvalue(elt(env, 2)); /* !*balanced_mod */
    if (v0206 == nil) goto v0186;
    v0166 = stack[0];
    v0206 = stack[0];
    v0166 = plus2(v0166, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0206 = qvalue(elt(env, 3)); /* current!-modulus */
    v0206 = (Lisp_Object)greaterp2(v0166, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    v0206 = v0206 ? lisp_true : nil;
    env = stack[-2];
    if (v0206 == nil) goto v0133;
    stack[-1] = elt(env, 4); /* !:mod!: */
    v0166 = stack[0];
    v0206 = qvalue(elt(env, 3)); /* current!-modulus */
    v0206 = difference2(v0166, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    {
        Lisp_Object v0076 = stack[-1];
        popv(3);
        return cons(v0076, v0206);
    }

v0133:
    v0166 = stack[0];
    v0206 = stack[0];
    stack[-1] = plus2(v0166, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0206 = qvalue(elt(env, 3)); /* current!-modulus */
    v0206 = negate(v0206);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0206 = (Lisp_Object)lesseq2(stack[-1], v0206);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    v0206 = v0206 ? lisp_true : nil;
    env = stack[-2];
    if (v0206 == nil) goto v0121;
    v0166 = stack[0];
    v0206 = qvalue(elt(env, 3)); /* current!-modulus */
    v0206 = plus2(v0166, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    stack[0] = v0206;
    goto v0181;

v0121:
    v0166 = elt(env, 4); /* !:mod!: */
    v0206 = stack[0];
    popv(3);
    return cons(v0166, v0206);

v0186:
    v0166 = elt(env, 4); /* !:mod!: */
    v0206 = stack[0];
    popv(3);
    return cons(v0166, v0206);

v0131:
    v0206 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0206); }
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for outdefr */

static Lisp_Object CC_outdefr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0103, v0170, v0169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for outdefr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0102 = v0001;
    v0103 = v0000;
/* end of prologue */
    v0170 = v0103;
    v0169 = qcar(v0170);
    v0170 = v0103;
    v0170 = qcdr(v0170);
    v0170 = qcar(v0170);
    v0103 = qcdr(v0103);
    v0103 = qcdr(v0103);
    v0103 = qcar(v0103);
    {
        fn = elt(env, 1); /* outref */
        return (*qfnn(fn))(qenv(fn), 4, v0169, v0170, v0103, v0102);
    }
}



/* Code for sfto_reorder */

static Lisp_Object CC_sfto_reorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_reorder");
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
    v0107 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0107 = ncons(v0107);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    fn = elt(env, 1); /* setkorder */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    stack[-1] = v0107;
    v0107 = stack[0];
    fn = elt(env, 2); /* reorder */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    stack[0] = v0107;
    v0107 = stack[-1];
    fn = elt(env, 1); /* setkorder */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0048:
    popv(3);
    return nil;
}



/* Code for sfto_gcdf!* */

static Lisp_Object CC_sfto_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0107, v0155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf*");
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
    v0107 = v0001;
    v0155 = v0000;
/* end of prologue */
    v0087 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*gcd */
    qvalue(elt(env, 2)) = v0087; /* !*gcd */
    v0087 = v0155;
    fn = elt(env, 3); /* sfto_gcdf */
    v0087 = (*qfn2(fn))(qenv(fn), v0087, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0087); }
/* error exit handlers */
v0048:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for mcharg */

static Lisp_Object MS_CDECL CC_mcharg(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0068, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mcharg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0066,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0066);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0066;
    stack[0] = v0001;
    v0032 = v0000;
/* end of prologue */
    v0068 = elt(env, 1); /* minus */
    v0183 = stack[0];
    v0183 = Latsoc(nil, v0068, v0183);
    if (v0183 == nil) goto v0131;
    v0068 = v0032;
    v0183 = stack[0];
    fn = elt(env, 4); /* reform!-minus */
    v0032 = (*qfn2(fn))(qenv(fn), v0068, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-5];
    v0068 = stack[0];
    v0183 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v0032, v0068, v0183);
    }

v0131:
    v0183 = stack[0];
    if (v0183 == nil) goto v0197;
    v0183 = stack[0];
    v0068 = qcar(v0183);
    v0183 = elt(env, 2); /* slash */
    if (!consp(v0068)) goto v0197;
    v0068 = qcar(v0068);
    if (!(v0068 == v0183)) goto v0197;
    v0068 = v0032;
    v0183 = stack[0];
    fn = elt(env, 6); /* reform!-minus2 */
    v0183 = (*qfn2(fn))(qenv(fn), v0068, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-5];
    stack[-4] = v0183;
    goto v0173;

v0173:
    v0183 = stack[-4];
    if (v0183 == nil) goto v0132;
    v0183 = stack[-4];
    v0183 = qcar(v0183);
    v0068 = v0183;
    v0032 = qcar(v0068);
    v0068 = qcdr(v0183);
    v0183 = stack[-3];
    fn = elt(env, 5); /* mcharg1 */
    v0183 = (*qfnn(fn))(qenv(fn), 3, v0032, v0068, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-5];
    stack[-2] = v0183;
    v0183 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-5];
    stack[-1] = v0183;
    v0183 = stack[-4];
    v0183 = qcdr(v0183);
    stack[-4] = v0183;
    v0183 = stack[-1];
    if (!consp(v0183)) goto v0173;
    else goto v0046;

v0046:
    v0183 = stack[-4];
    if (v0183 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0183 = stack[-4];
    v0183 = qcar(v0183);
    v0068 = v0183;
    v0032 = qcar(v0068);
    v0068 = qcdr(v0183);
    v0183 = stack[-3];
    fn = elt(env, 5); /* mcharg1 */
    v0183 = (*qfnn(fn))(qenv(fn), 3, v0032, v0068, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-5];
    v0183 = Lrplacd(nil, stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-5];
    v0183 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-5];
    stack[-1] = v0183;
    v0183 = stack[-4];
    v0183 = qcdr(v0183);
    stack[-4] = v0183;
    goto v0046;

v0132:
    v0183 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v0183); }

v0197:
    v0068 = stack[0];
    v0183 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v0032, v0068, v0183);
    }
/* error exit handlers */
v0207:
    popv(6);
    return nil;
}



/* Code for subs2 */

static Lisp_Object CC_subs2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2");
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
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0039 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0039 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0039 = qvalue(elt(env, 2)); /* !*sub2 */
    if (!(v0039 == nil)) goto v0107;
    v0039 = qvalue(elt(env, 3)); /* powlis1!* */
    if (!(v0039 == nil)) goto v0107;

v0181:
    v0039 = qvalue(elt(env, 4)); /* !*combineexpt */
    if (v0039 == nil) goto v0103;
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    fn = elt(env, 11); /* exptchk */
    stack[0] = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-5];
    v0039 = stack[-3];
    v0039 = qcdr(v0039);
    fn = elt(env, 11); /* exptchk */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-5];
    fn = elt(env, 12); /* invsq */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-5];
    fn = elt(env, 13); /* multsq */
    v0039 = (*qfn2(fn))(qenv(fn), stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-5];
    goto v0102;

v0102:
    stack[-3] = v0039;
    v0075 = elt(env, 5); /* slash */
    v0039 = elt(env, 6); /* opmtch */
    v0039 = get(v0075, v0039);
    env = stack[-5];
    stack[0] = v0039;
    v0039 = qvalue(elt(env, 7)); /* !*match */
    if (!(v0039 == nil)) goto v0134;
    v0039 = stack[0];
    if (!(v0039 == nil)) goto v0134;
    v0039 = qvalue(elt(env, 8)); /* t */
    goto v0047;

v0047:
    if (!(v0039 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0039 = qvalue(elt(env, 9)); /* !*exp */
    if (!(v0039 == nil)) goto v0099;
    v0039 = qvalue(elt(env, 8)); /* t */
    stack[-4] = v0039;
    v0039 = qvalue(elt(env, 8)); /* t */
    qvalue(elt(env, 9)) = v0039; /* !*exp */
    v0039 = stack[-3];
    stack[-2] = v0039;
    v0039 = stack[-3];
    fn = elt(env, 14); /* resimp */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-5];
    stack[-3] = v0039;
    stack[-1] = v0039;
    goto v0099;

v0099:
    v0039 = stack[-3];
    fn = elt(env, 15); /* subs3q */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-5];
    stack[-3] = v0039;
    v0039 = stack[-4];
    if (v0039 == nil) goto v0130;
    v0039 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 9)) = v0039; /* !*exp */
    v0075 = stack[-3];
    v0039 = stack[-1];
    if (!(equal(v0075, v0039))) goto v0130;
    v0039 = stack[-2];
    stack[-3] = v0039;
    goto v0130;

v0130:
    v0039 = stack[0];
    if (v0039 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0039 = stack[-3];
    fn = elt(env, 16); /* subs4q */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    stack[-3] = v0039;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0134:
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    v0039 = (v0039 == nil ? lisp_true : nil);
    goto v0047;

v0103:
    v0039 = stack[-3];
    goto v0102;

v0107:
    v0039 = stack[-3];
    fn = elt(env, 17); /* subs2q */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-5];
    stack[-3] = v0039;
    goto v0181;
/* error exit handlers */
v0172:
    popv(6);
    return nil;
}



/* Code for aex_mk */

static Lisp_Object MS_CDECL CC_aex_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0066, Lisp_Object v0081, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0051, v0052, v0055;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "aex_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0081,v0066,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0066,v0081);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0169 = v0081;
    v0051 = v0066;
    v0052 = v0001;
    v0055 = v0000;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v0055;
    stack[0] = v0052;
    v0169 = list2(v0051, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        Lisp_Object v0089 = stack[-2];
        Lisp_Object v0049 = stack[-1];
        Lisp_Object v0050 = stack[0];
        popv(3);
        return list3star(v0089, v0049, v0050, v0169);
    }
/* error exit handlers */
v0090:
    popv(3);
    return nil;
}



/* Code for lex */

static Lisp_Object MS_CDECL CC_lex(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lex");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lex");
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
    v0156 = qvalue(elt(env, 2)); /* atts */
    if (v0156 == nil) goto v0127;
    v0156 = qvalue(elt(env, 2)); /* atts */
    qvalue(elt(env, 3)) = v0156; /* safe_atts */
    goto v0127;

v0127:
    v0156 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0156; /* atts */
    v0198 = qvalue(elt(env, 4)); /* ch */
    v0156 = qvalue(elt(env, 5)); /* !$eof!$ */
    if (equal(v0198, v0156)) goto v0087;
    v0198 = qvalue(elt(env, 4)); /* ch */
    v0156 = qvalue(elt(env, 6)); /* space */
    if (equal(v0198, v0156)) goto v0101;
    v0198 = qvalue(elt(env, 4)); /* ch */
    v0156 = elt(env, 7); /* !< */
    if (v0198 == v0156) goto v0153;
    fn = elt(env, 10); /* get_content */
    v0156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0156; /* char */
    goto v0103;

v0103:
    v0156 = qvalue(elt(env, 8)); /* char */
    if (v0156 == nil) goto v0129;
    v0156 = qvalue(elt(env, 9)); /* count */
    v0156 = add1(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    qvalue(elt(env, 9)) = v0156; /* count */
    v0156 = qvalue(elt(env, 8)); /* char */
    v0156 = Lreverse(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    stack[0] = v0156;
    v0156 = stack[0];
    fn = elt(env, 11); /* butes */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0156; /* char */
    v0198 = qvalue(elt(env, 8)); /* char */
    v0156 = stack[0];
    fn = elt(env, 12); /* attributes */
    v0156 = (*qfn2(fn))(qenv(fn), v0198, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    goto v0087;

v0087:
    v0156 = nil;
    { popv(2); return onevalue(v0156); }

v0129:
    v0156 = CC_lex(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    goto v0087;

v0153:
    fn = elt(env, 13); /* get_token */
    v0156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0156; /* char */
    goto v0103;

v0101:
    v0198 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0198; /* ch */
    v0156 = qvalue(elt(env, 6)); /* space */
    if (equal(v0198, v0156)) goto v0101;
    else goto v0103;
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for depends */

static Lisp_Object CC_depends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0142, v0143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depends");
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
    v0141 = stack[-1];
    if (v0141 == nil) goto v0181;
    v0141 = stack[-1];
    v0141 = (is_number(v0141) ? lisp_true : nil);
    if (!(v0141 == nil)) goto v0119;
    v0141 = stack[0];
    v0141 = (is_number(v0141) ? lisp_true : nil);
    goto v0119;

v0119:
    if (v0141 == nil) goto v0170;
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0170:
    v0142 = stack[-1];
    v0141 = stack[0];
    if (equal(v0142, v0141)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0135;
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0050;

v0050:
    if (v0141 == nil) goto v0046;
    v0141 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0141); }

v0046:
    v0142 = stack[-1];
    v0141 = qvalue(elt(env, 4)); /* depl!* */
    v0141 = Lassoc(nil, v0142, v0141);
    v0142 = v0141;
    v0141 = v0142;
    if (v0141 == nil) goto v0132;
    v0141 = v0142;
    v0142 = qcdr(v0141);
    v0141 = stack[0];
    fn = elt(env, 7); /* ldepends */
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    goto v0134;

v0134:
    if (v0141 == nil) goto v0173;
    v0141 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0141); }

v0173:
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0039;
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    if (symbolp(v0141)) goto v0126;
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0092;

v0092:
    if (v0141 == nil) goto v0129;
    v0141 = stack[-1];
    v0142 = qcar(v0141);
    v0141 = elt(env, 6); /* domain!-depends!-fn */
    v0141 = get(v0142, v0141);
    env = stack[-2];
    v0142 = v0141;
    v0141 = v0142;
    if (v0141 == nil) goto v0031;
    v0143 = v0142;
    v0142 = stack[-1];
    v0141 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v0143, v0142, v0141);

v0031:
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0129:
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0149;
    v0141 = stack[-1];
    v0142 = qcdr(v0141);
    v0141 = stack[0];
    fn = elt(env, 7); /* ldepends */
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    if (!(v0141 == nil)) goto v0068;
    v0141 = stack[-1];
    v0142 = qcar(v0141);
    v0141 = stack[0];
    v0141 = CC_depends(env, v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    goto v0068;

v0068:
    if (v0141 == nil) goto v0180;
    v0141 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0141); }

v0180:
    v0141 = stack[0];
    if (!consp(v0141)) goto v0112;
    v0141 = stack[0];
    v0141 = qcar(v0141);
    if (symbolp(v0141)) goto v0020;
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0193;

v0193:
    if (v0141 == nil) goto v0063;
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0063:
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0020:
    v0141 = stack[0];
    v0142 = qcar(v0141);
    v0141 = elt(env, 5); /* dname */
    v0141 = get(v0142, v0141);
    env = stack[-2];
    goto v0193;

v0112:
    v0141 = qvalue(elt(env, 1)); /* t */
    goto v0193;

v0149:
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0068;

v0126:
    v0141 = stack[-1];
    v0142 = qcar(v0141);
    v0141 = elt(env, 5); /* dname */
    v0141 = get(v0142, v0141);
    env = stack[-2];
    goto v0092;

v0039:
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0092;

v0132:
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0134;

v0135:
    v0142 = stack[-1];
    v0141 = qvalue(elt(env, 3)); /* frlis!* */
    v0141 = Lmemq(nil, v0142, v0141);
    goto v0050;

v0181:
    v0141 = qvalue(elt(env, 1)); /* t */
    goto v0119;
/* error exit handlers */
v0019:
    popv(3);
    return nil;
}



/* Code for mk!*sq */

static Lisp_Object CC_mkHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0198, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk*sq");
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
    v0040 = v0000;
/* end of prologue */
    v0198 = qvalue(elt(env, 1)); /* !*exp */
    if (v0198 == nil) goto v0119;
    v0198 = v0040;
    goto v0081;

v0081:
    stack[0] = v0198;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    if (v0198 == nil) goto v0155;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    if (!consp(v0198)) goto v0052;
    v0198 = qvalue(elt(env, 2)); /* nil */
    goto v0102;

v0102:
    if (v0198 == nil) goto v0136;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    { popv(3); return onevalue(v0198); }

v0136:
    v0198 = stack[0];
    fn = elt(env, 7); /* kernp */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-2];
    if (v0198 == nil) goto v0095;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0198 = qcar(v0198);
    v0198 = qcar(v0198);
    v0040 = qcar(v0198);
    v0198 = elt(env, 3); /* list */
    if (!consp(v0040)) goto v0095;
    v0040 = qcar(v0040);
    if (!(v0040 == v0198)) goto v0095;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0198 = qcar(v0198);
    v0198 = qcar(v0198);
    v0198 = qcar(v0198);
    { popv(3); return onevalue(v0198); }

v0095:
    stack[-1] = elt(env, 4); /* !*sq */
    v0198 = qvalue(elt(env, 5)); /* !*resubs */
    if (v0198 == nil) goto v0121;
    v0198 = qvalue(elt(env, 6)); /* !*sqvar!* */
    goto v0106;

v0106:
    {
        Lisp_Object v0146 = stack[-1];
        Lisp_Object v0186 = stack[0];
        popv(3);
        return list2star(v0146, v0186, v0198);
    }

v0121:
    v0198 = qvalue(elt(env, 2)); /* nil */
    v0198 = ncons(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    goto v0106;

v0052:
    v0198 = stack[0];
    v0040 = qcdr(v0198);
    v0198 = (Lisp_Object)17; /* 1 */
    v0198 = (v0040 == v0198 ? lisp_true : nil);
    goto v0102;

v0155:
    v0198 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0198); }

v0119:
    v0198 = v0040;
    fn = elt(env, 8); /* offexpchk */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-2];
    goto v0081;
/* error exit handlers */
v0151:
    popv(3);
    return nil;
}



/* Code for pnthxzz */

static Lisp_Object CC_pnthxzz(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0089, v0049, v0050;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnthxzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0001;
    v0050 = v0000;
/* end of prologue */

v0123:
    v0090 = v0049;
    if (v0090 == nil) goto v0088;
    v0090 = v0049;
    v0090 = qcar(v0090);
    v0089 = qcar(v0090);
    v0090 = v0050;
    v0090 = (equal(v0089, v0090) ? lisp_true : nil);
    goto v0084;

v0084:
    if (!(v0090 == nil)) return onevalue(v0049);
    v0090 = v0049;
    v0090 = qcdr(v0090);
    v0049 = v0090;
    goto v0123;

v0088:
    v0090 = qvalue(elt(env, 1)); /* t */
    goto v0084;
}



/* Code for genp */

static Lisp_Object CC_genp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0103, v0170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genp");
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
    v0103 = v0000;
/* end of prologue */
    v0102 = v0103;
    if (!consp(v0102)) goto v0084;
    v0102 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0102); }

v0084:
    v0170 = v0103;
    v0102 = elt(env, 1); /* gen */
    v0102 = get(v0170, v0102);
    env = stack[0];
    if (!(v0102 == nil)) { popv(1); return onevalue(v0102); }
    v0102 = v0103;
    {
        popv(1);
        fn = elt(env, 3); /* mgenp */
        return (*qfn1(fn))(qenv(fn), v0102);
    }
}



/* Code for evsum */

static Lisp_Object CC_evsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0094, v0096;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evsum");
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
    v0096 = nil;
    goto v0119;

v0119:
    v0095 = stack[-1];
    if (v0095 == nil) goto v0131;
    v0095 = stack[0];
    if (v0095 == nil) goto v0131;
    v0095 = stack[-1];
    v0094 = qcar(v0095);
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = (Lisp_Object)(int32_t)((int32_t)v0094 + (int32_t)v0095 - TAG_FIXNUM);
    v0094 = v0096;
    v0095 = cons(v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0096 = v0095;
    v0095 = stack[-1];
    v0095 = qcdr(v0095);
    stack[-1] = v0095;
    v0095 = stack[0];
    v0095 = qcdr(v0095);
    stack[0] = v0095;
    goto v0119;

v0131:
    v0095 = v0096;
    v0095 = Lnreverse(nil, v0095);
    v0096 = v0095;
    v0095 = stack[-1];
    if (v0095 == nil) goto v0069;
    v0094 = v0096;
    v0095 = stack[-1];
        popv(3);
        return Lnconc(nil, v0094, v0095);

v0069:
    v0095 = stack[0];
    if (v0095 == nil) { popv(3); return onevalue(v0096); }
    v0094 = v0096;
    v0095 = stack[0];
        popv(3);
        return Lnconc(nil, v0094, v0095);
/* error exit handlers */
v0106:
    popv(3);
    return nil;
}



/* Code for find_item */

static Lisp_Object CC_find_item(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0099;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_item");
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

v0161:
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    if (v0098 == nil) goto v0123;
    v0099 = stack[-1];
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    v0098 = CC_find_item(env, v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-2];
    if (!(v0098 == nil)) { popv(3); return onevalue(v0098); }
    v0098 = stack[0];
    v0099 = qcar(v0098);
    v0098 = stack[-1];
    if (equal(v0099, v0098)) goto v0083;
    v0098 = nil;
    goto v0055;

v0055:
    if (!(v0098 == nil)) { popv(3); return onevalue(v0098); }
    v0099 = stack[-1];
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    v0098 = qcdr(v0098);
    stack[-1] = v0099;
    stack[0] = v0098;
    goto v0161;

v0083:
    v0098 = stack[0];
    goto v0055;

v0123:
    v0098 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0098); }
/* error exit handlers */
v0176:
    popv(3);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
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
    v0088 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v0087 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-1];
    v0088 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v0087, v0088);
    }
/* error exit handlers */
v0155:
    popv(2);
    return nil;
}



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0127 = v0000;
/* end of prologue */
    v0127 = qcar(v0127);
    v0127 = qcar(v0127);
    {
        fn = elt(env, 1); /* getphystypesf */
        return (*qfn1(fn))(qenv(fn), v0127);
    }
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0056, v0154, v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0001;
    v0056 = v0000;
/* end of prologue */
    v0137 = v0056;
    v0154 = v0048;
    v0056 = qvalue(elt(env, 1)); /* nil */
    v0048 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v0137, v0154, v0056, v0048);
    }
}



/* Code for reval2 */

static Lisp_Object CC_reval2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval2");
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
    v0099 = v0000;
/* end of prologue */
    v0098 = stack[0];
    if (!(v0098 == nil)) goto v0123;
    v0098 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v0098 == nil) goto v0088;
    v0098 = qvalue(elt(env, 3)); /* dmode!* */
    goto v0084;

v0084:
    if (!(v0098 == nil)) goto v0123;
    v0098 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = qvalue(elt(env, 5)); /* !*mcd */
    qvalue(elt(env, 5)) = v0098; /* !*mcd */
    v0098 = v0099;
    fn = elt(env, 6); /* simp!* */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-2];
    qvalue(elt(env, 5)) = stack[-1]; /* !*mcd */
    v0099 = v0098;
    v0098 = stack[0];
    if (v0098 == nil) goto v0101;
    v0098 = v0099;
    {
        popv(3);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0098);
    }

v0101:
    v0098 = v0099;
    {
        popv(3);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0098);
    }

v0123:
    v0098 = v0099;
    fn = elt(env, 6); /* simp!* */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    v0099 = v0098;
    v0098 = stack[0];
    if (v0098 == nil) goto v0103;
    v0098 = v0099;
    {
        popv(3);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0098);
    }

v0103:
    v0098 = v0099;
    {
        popv(3);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0098);
    }

v0088:
    v0098 = qvalue(elt(env, 2)); /* t */
    goto v0084;
/* error exit handlers */
v0047:
    popv(3);
    return nil;
v0176:
    env = stack[-2];
    qvalue(elt(env, 5)) = stack[-1]; /* !*mcd */
    popv(3);
    return nil;
}



setup_type const u04_setup[] =
{
    {"addsq",                   too_few_2,      CC_addsq,      wrong_no_2},
    {"pkp",                     CC_pkp,         too_many_1,    wrong_no_1},
    {"round:last",              CC_roundTlast,  too_many_1,    wrong_no_1},
    {"remainder-in-vector",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_remainderKinKvector},
    {"**s2a",                   too_few_2,      CC_HHs2a,      wrong_no_2},
    {"gcdf",                    too_few_2,      CC_gcdf,       wrong_no_2},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"pasf_susitf",             too_few_2,      CC_pasf_susitf,wrong_no_2},
    {"ibalp_csat",              CC_ibalp_csat,  too_many_1,    wrong_no_1},
    {"free-powerp",             CC_freeKpowerp, too_many_1,    wrong_no_1},
    {"isvalid",                 CC_isvalid,     too_many_1,    wrong_no_1},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {"findrow",                 too_few_2,      CC_findrow,    wrong_no_2},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"prepd",                   CC_prepd,       too_many_1,    wrong_no_1},
    {"bcint2op",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_bcint2op},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"repeatsp",                CC_repeatsp,    too_many_1,    wrong_no_1},
    {"nonzero-length",          CC_nonzeroKlength,too_many_1,  wrong_no_1},
    {"bas_rep",                 CC_bas_rep,     too_many_1,    wrong_no_1},
    {"lcm",                     too_few_2,      CC_lcm,        wrong_no_2},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"rl_varlat",               CC_rl_varlat,   too_many_1,    wrong_no_1},
    {"rl_smmkatl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smmkatl},
    {"sfto_gcdf",               too_few_2,      CC_sfto_gcdf,  wrong_no_2},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"qqe_mk2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_qqe_mk2},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"indent*",                 CC_indentH,     too_many_1,    wrong_no_1},
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"round:mt",                too_few_2,      CC_roundTmt,   wrong_no_2},
    {"revlis",                  CC_revlis,      too_many_1,    wrong_no_1},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"ordad",                   too_few_2,      CC_ordad,      wrong_no_2},
    {"xdiv",                    too_few_2,      CC_xdiv,       wrong_no_2},
    {"scprint",                 too_few_2,      CC_scprint,    wrong_no_2},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"prin2-downcase",          CC_prin2Kdowncase,too_many_1,  wrong_no_1},
    {"tensopp",                 CC_tensopp,     too_many_1,    wrong_no_1},
    {"negf",                    CC_negf,        too_many_1,    wrong_no_1},
    {"add2inputbuf",            too_few_2,      CC_add2inputbuf,wrong_no_2},
    {"fs:angle-order",          too_few_2,      CC_fsTangleKorder,wrong_no_2},
    {"mo=sum",                  too_few_2,      CC_moMsum,     wrong_no_2},
    {"rev",                     too_few_2,      CC_rev,        wrong_no_2},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"times-term-mod-p",        too_few_2,      CC_timesKtermKmodKp,wrong_no_2},
    {"anforml",                 CC_anforml,     too_many_1,    wrong_no_1},
    {"cl_cflip",                too_few_2,      CC_cl_cflip,   wrong_no_2},
    {"get+col+nr",              CC_getLcolLnr,  too_many_1,    wrong_no_1},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"pasf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwupdknowl},
    {"list2string",             CC_list2string, too_many_1,    wrong_no_1},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"bound",                   CC_bound,       too_many_1,    wrong_no_1},
    {"vevcompless?",            too_few_2,      CC_vevcomplessW,wrong_no_2},
    {"fast_unchecked_getmatelem",CC_fast_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"mkwedge",                 CC_mkwedge,     too_many_1,    wrong_no_1},
    {"physopp*",                CC_physoppH,    too_many_1,    wrong_no_1},
    {"getroad",                 too_few_2,      CC_getroad,    wrong_no_2},
    {"command1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_command1},
    {"mo=degcomp",              too_few_2,      CC_moMdegcomp, wrong_no_2},
    {"vecp",                    CC_vecp,        too_many_1,    wrong_no_1},
    {"pv_sort",                 CC_pv_sort,     too_many_1,    wrong_no_1},
    {"*modular2f",              CC_Hmodular2f,  too_many_1,    wrong_no_1},
    {"outdefr",                 too_few_2,      CC_outdefr,    wrong_no_2},
    {"sfto_reorder",            too_few_2,      CC_sfto_reorder,wrong_no_2},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"mcharg",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg},
    {"subs2",                   CC_subs2,       too_many_1,    wrong_no_1},
    {"aex_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_mk},
    {"lex",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_lex},
    {"depends",                 too_few_2,      CC_depends,    wrong_no_2},
    {"mk*sq",                   CC_mkHsq,       too_many_1,    wrong_no_1},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"genp",                    CC_genp,        too_many_1,    wrong_no_1},
    {"evsum",                   too_few_2,      CC_evsum,      wrong_no_2},
    {"find_item",               too_few_2,      CC_find_item,  wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"reval2",                  too_few_2,      CC_reval2,     wrong_no_2},
    {NULL, (one_args *)"u04", (two_args *)"13227 8272667 1773926", 0}
};

/* end of generated code */
