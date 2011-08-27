
/* $destdir\u49.c        Machine generated C code */

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


/* Code for physopsubs */

static Lisp_Object CC_physopsubs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsubs");
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
    stack[-2] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v27 = qvalue(elt(env, 2)); /* nil */
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    qvalue(elt(env, 1)) = v27; /* alglist!* */
    v27 = stack[-1];
    fn = elt(env, 12); /* physop2sq */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-1] = v27;
    v27 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v27;
    goto v31;

v31:
    v27 = stack[0];
    if (v27 == nil) goto v32;
    v27 = stack[0];
    v27 = qcar(v27);
    v29 = v27;
    v28 = v29;
    v27 = elt(env, 4); /* rtype */
    v27 = Lremprop(nil, v28, v27);
    env = stack[-3];
    v28 = elt(env, 5); /* simpfn */
    v27 = elt(env, 6); /* simpiden */
    v27 = Lputprop(nil, 3, v29, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v31;

v32:
    v28 = elt(env, 7); /* (dot) */
    v27 = elt(env, 8); /* physopfn */
    v27 = Lremflag(nil, v28, v27);
    env = stack[-3];
    v29 = elt(env, 9); /* dot */
    v28 = elt(env, 5); /* simpfn */
    v27 = elt(env, 6); /* simpiden */
    v27 = Lputprop(nil, 3, v29, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v27 = stack[-1];
    fn = elt(env, 13); /* subs2 */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-1] = v27;
    v27 = qvalue(elt(env, 10)); /* !*nosq */
    if (v27 == nil) goto v33;
    v27 = stack[-1];
    fn = elt(env, 14); /* prepsqxx */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    goto v34;

v34:
    stack[-1] = v27;
    v27 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v27;
    goto v35;

v35:
    v27 = stack[0];
    if (v27 == nil) goto v36;
    v27 = stack[0];
    v27 = qcar(v27);
    v29 = v27;
    v28 = v29;
    v27 = elt(env, 5); /* simpfn */
    v27 = Lremprop(nil, v28, v27);
    env = stack[-3];
    v28 = elt(env, 4); /* rtype */
    v27 = elt(env, 11); /* physop */
    v27 = Lputprop(nil, 3, v29, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v35;

v36:
    v28 = elt(env, 9); /* dot */
    v27 = elt(env, 5); /* simpfn */
    v27 = Lremprop(nil, v28, v27);
    env = stack[-3];
    v28 = elt(env, 7); /* (dot) */
    v27 = elt(env, 8); /* physopfn */
    v27 = Lflag(nil, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v27 = stack[-1];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    { popv(4); return onevalue(v27); }

v33:
    v27 = stack[-1];
    fn = elt(env, 15); /* mk!*sq */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    goto v34;
/* error exit handlers */
v30:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for coeff1_calc */

static Lisp_Object MS_CDECL CC_coeff1_calc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v37,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff1_calc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff1_calc");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v37,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v46;

v46:
    v44 = stack[0];
    if (v44 == nil) goto v31;
    v32 = stack[-2];
    v45 = stack[-1];
    v44 = stack[0];
    v44 = qcar(v44);
    fn = elt(env, 1); /* calc_coeffmap_ */
    v45 = (*qfnn(fn))(qenv(fn), 3, v32, v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v44 = stack[-3];
    v44 = cons(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    stack[-3] = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v46;

v31:
    stack[0] = stack[-3];
    v44 = (Lisp_Object)1; /* 0 */
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    {
        Lisp_Object v19 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v19, v44);
    }
/* error exit handlers */
v18:
    popv(5);
    return nil;
}



/* Code for red_extract */

static Lisp_Object CC_red_extract(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_extract");
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
    stack[0] = (Lisp_Object)1; /* 0 */
    v53 = stack[-2];
    fn = elt(env, 1); /* bas_rep */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    fn = elt(env, 2); /* dp_comp */
    v53 = (*qfn2(fn))(qenv(fn), stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-3] = v53;
    v53 = stack[-2];
    fn = elt(env, 3); /* bas_nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v53 = stack[-2];
    fn = elt(env, 4); /* bas_dpoly */
    stack[0] = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v53 = stack[-2];
    fn = elt(env, 1); /* bas_rep */
    v22 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v53 = stack[-3];
    fn = elt(env, 5); /* dp_diff */
    v53 = (*qfn2(fn))(qenv(fn), v22, v53);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    fn = elt(env, 6); /* bas_make1 */
    v22 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v53 = stack[-3];
    popv(5);
    return cons(v22, v53);
/* error exit handlers */
v45:
    popv(5);
    return nil;
}



/* Code for permp!: */

static Lisp_Object CC_permpT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v58, v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp:");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v19 = v37;
    v58 = v0;
/* end of prologue */

v1:
    v18 = v58;
    if (v18 == nil) goto v51;
    v18 = v58;
    v59 = qcar(v18);
    v18 = v19;
    v18 = qcar(v18);
    if (equal(v59, v18)) goto v60;
    v18 = v58;
    stack[0] = qcdr(v18);
    v18 = v19;
    v18 = qcar(v18);
    v58 = qcar(v58);
    v19 = qcdr(v19);
    v18 = Lsubst(nil, 3, v18, v58, v19);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v18 = CC_permpT(env, stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v18 = (v18 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v18); }

v60:
    v18 = v58;
    v18 = qcdr(v18);
    v58 = v18;
    v18 = v19;
    v18 = qcdr(v18);
    v19 = v18;
    goto v1;

v51:
    v18 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v18); }
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for merge_list1 */

static Lisp_Object MS_CDECL CC_merge_list1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v37,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v65, v66;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "merge_list1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge_list1");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v37,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    v33 = stack[-2];
    if (v33 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v33 = stack[-1];
    if (v33 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v66 = stack[0];
    v33 = stack[-2];
    v65 = qcar(v33);
    v33 = stack[-1];
    v33 = qcar(v33);
    v33 = Lapply2(nil, 3, v66, v65, v33);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-4];
    if (v33 == nil) goto v68;
    stack[-3] = stack[-2];
    v33 = stack[-2];
    v66 = qcdr(v33);
    v65 = stack[-1];
    v33 = stack[0];
    v33 = CC_merge_list1(env, 3, v66, v65, v33);
    nil = C_nil;
    if (exception_pending()) goto v67;
    {
        Lisp_Object v69 = stack[-3];
        popv(5);
        return Lrplacd(nil, v69, v33);
    }

v68:
    stack[-3] = stack[-1];
    v66 = stack[-2];
    v33 = stack[-1];
    v65 = qcdr(v33);
    v33 = stack[0];
    v33 = CC_merge_list1(env, 3, v66, v65, v33);
    nil = C_nil;
    if (exception_pending()) goto v67;
    {
        Lisp_Object v13 = stack[-3];
        popv(5);
        return Lrplacd(nil, v13, v33);
    }
/* error exit handlers */
v67:
    popv(5);
    return nil;
}



/* Code for constant_exprp */

static Lisp_Object CC_constant_exprp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81, v82;
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
    v81 = v0;
/* end of prologue */
    v80 = v81;
    if (!consp(v80)) goto v2;
    v80 = v81;
    v82 = qcar(v80);
    v80 = elt(env, 6); /* realvalued */
    v80 = Lflagp(nil, v82, v80);
    env = stack[0];
    if (v80 == nil) goto v67;
    v80 = qvalue(elt(env, 2)); /* t */
    goto v62;

v62:
    if (v80 == nil) goto v19;
    v80 = v81;
    v80 = qcdr(v80);
    if (!consp(v80)) goto v83;
    v80 = v81;
    v80 = qcdr(v80);
    {
        popv(1);
        fn = elt(env, 12); /* constant_expr_listp */
        return (*qfn1(fn))(qenv(fn), v80);
    }

v83:
    v80 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v80); }

v19:
    v80 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v80); }

v67:
    v80 = v81;
    v82 = qcar(v80);
    v80 = elt(env, 7); /* alwaysrealvalued */
    v80 = Lflagp(nil, v82, v80);
    env = stack[0];
    if (v80 == nil) goto v84;
    v80 = qvalue(elt(env, 2)); /* t */
    goto v62;

v84:
    v80 = v81;
    v82 = qcar(v80);
    v80 = elt(env, 8); /* (plus minus difference times quotient) */
    v80 = Lmemq(nil, v82, v80);
    if (!(v80 == nil)) goto v62;
    v80 = v81;
    v82 = qcar(v80);
    v80 = elt(env, 9); /* !:rd!: */
    v80 = get(v82, v80);
    env = stack[0];
    if (!(v80 == nil)) goto v62;
    v80 = qvalue(elt(env, 10)); /* !*complex */
    if (v80 == nil) goto v85;
    v80 = v81;
    v82 = qcar(v80);
    v80 = elt(env, 11); /* !:cr!: */
    v80 = get(v82, v80);
    env = stack[0];
    goto v62;

v85:
    v80 = qvalue(elt(env, 5)); /* nil */
    goto v62;

v2:
    v80 = v81;
    v80 = (is_number(v80) ? lisp_true : nil);
    if (!(v80 == nil)) { popv(1); return onevalue(v80); }
    v82 = v81;
    v80 = elt(env, 1); /* constant */
    v80 = Lflagp(nil, v82, v80);
    env = stack[0];
    if (v80 == nil) goto v86;
    v80 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v80); }

v86:
    v80 = elt(env, 3); /* i */
    if (v81 == v80) goto v40;
    v80 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v80); }

v40:
    v80 = elt(env, 3); /* i */
    v81 = elt(env, 4); /* idvalfn */
    popv(1);
    return get(v80, v81);
}



/* Code for cl_gaussintersection */

static Lisp_Object CC_cl_gaussintersection(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_gaussintersection");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v0;
/* end of prologue */
    v93 = stack[-1];
    v84 = qcar(v93);
    v93 = elt(env, 1); /* gignore */
    if (v84 == v93) goto v42;
    v93 = qvalue(elt(env, 2)); /* nil */
    goto v51;

v51:
    if (v93 == nil) goto v59;
    v93 = stack[-1];
    v93 = qcdr(v93);
    v93 = qcdr(v93);
    stack[-2] = Llength(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    v93 = stack[0];
    v93 = qcdr(v93);
    v93 = qcdr(v93);
    v93 = Llength(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    v93 = (Lisp_Object)lessp2(stack[-2], v93);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v93 = v93 ? lisp_true : nil;
    if (v93 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v59:
    v93 = stack[-1];
    v84 = qcar(v93);
    v93 = elt(env, 1); /* gignore */
    if (v84 == v93) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v93 = stack[0];
    v84 = qcar(v93);
    v93 = elt(env, 1); /* gignore */
    if (v84 == v93) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v84 = stack[-1];
    v93 = stack[0];
    fn = elt(env, 3); /* rl_bettergaussp */
    v93 = (*qfn2(fn))(qenv(fn), v84, v93);
    nil = C_nil;
    if (exception_pending()) goto v94;
    if (v93 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v42:
    v93 = stack[0];
    v84 = qcar(v93);
    v93 = elt(env, 1); /* gignore */
    v93 = (v84 == v93 ? lisp_true : nil);
    goto v51;
/* error exit handlers */
v94:
    popv(4);
    return nil;
}



/* Code for sfto_yun!-updecf */

static Lisp_Object CC_sfto_yunKupdecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_yun-updecf");
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
    stack[-7] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = nil;
    v109 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v109; /* !*gcd */
    v110 = (Lisp_Object)17; /* 1 */
    v109 = (Lisp_Object)17; /* 1 */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-2] = v109;
    v109 = stack[-6];
    v109 = qcar(v109);
    v109 = qcar(v109);
    v109 = qcar(v109);
    stack[-5] = v109;
    stack[-3] = stack[-6];
    v110 = stack[-6];
    v109 = stack[-5];
    fn = elt(env, 3); /* diff */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[0] = v109;
    fn = elt(env, 4); /* sfto_gcdf */
    v109 = (*qfn2(fn))(qenv(fn), stack[-3], v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-3] = v109;
    v110 = stack[-6];
    v109 = stack[-3];
    fn = elt(env, 5); /* quotf */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-4] = v109;
    v110 = stack[0];
    v109 = stack[-3];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    v110 = stack[-4];
    v109 = stack[-5];
    fn = elt(env, 3); /* diff */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v109 = (*qfn2(fn))(qenv(fn), stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-3] = v109;
    goto v89;

v89:
    v109 = stack[-1];
    v109 = (v109 == nil ? lisp_true : nil);
    stack[-1] = v109;
    v110 = stack[-4];
    v109 = stack[-3];
    fn = elt(env, 4); /* sfto_gcdf */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-6] = v109;
    v109 = stack[-1];
    if (v109 == nil) goto v9;
    stack[0] = stack[-2];
    v109 = stack[-2];
    v110 = qcar(v109);
    v109 = stack[-6];
    fn = elt(env, 8); /* multf */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    fn = elt(env, 9); /* setcar */
    v109 = (*qfn2(fn))(qenv(fn), stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    goto v112;

v112:
    v110 = stack[-4];
    v109 = stack[-6];
    fn = elt(env, 5); /* quotf */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-4] = v109;
    v110 = stack[-3];
    v109 = stack[-6];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    v110 = stack[-4];
    v109 = stack[-5];
    fn = elt(env, 3); /* diff */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v109 = (*qfn2(fn))(qenv(fn), stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-3] = v109;
    v109 = stack[-4];
    if (!consp(v109)) goto v113;
    v109 = stack[-4];
    v109 = qcar(v109);
    v109 = (consp(v109) ? nil : lisp_true);
    goto v114;

v114:
    if (v109 == nil) goto v89;
    v109 = stack[-2];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    { popv(9); return onevalue(v109); }

v113:
    v109 = qvalue(elt(env, 2)); /* t */
    goto v114;

v9:
    stack[0] = stack[-2];
    v109 = stack[-2];
    v110 = qcdr(v109);
    v109 = stack[-6];
    fn = elt(env, 8); /* multf */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    fn = elt(env, 10); /* setcdr */
    v109 = (*qfn2(fn))(qenv(fn), stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    goto v112;
/* error exit handlers */
v111:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    popv(9);
    return nil;
}



/* Code for get_mat */

static Lisp_Object CC_get_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    v117 = stack[-2];
    v116 = elt(env, 1); /* id */
    if (v117 == v116) goto v52;
    v116 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v116;
    goto v118;

v118:
    v116 = stack[-1];
    v117 = Llength(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-4];
    v116 = (Lisp_Object)1; /* 0 */
    v116 = (Lisp_Object)greaterp2(v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v10;
    v116 = v116 ? lisp_true : nil;
    env = stack[-4];
    if (v116 == nil) goto v49;
    v116 = stack[-3];
    if (!(v116 == nil)) goto v49;
    v117 = stack[-2];
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcar(v116);
    if (!(equal(v117, v116))) goto v45;
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = qcar(v116);
    stack[0] = v116;
    v116 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v116;
    goto v45;

v45:
    v116 = stack[-1];
    v116 = qcdr(v116);
    stack[-1] = v116;
    goto v118;

v49:
    v116 = stack[-3];
    if (!(v116 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v116 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v116 == nil)) goto v13;
    v116 = elt(env, 5); /* "error in get_mat" */
    fn = elt(env, 6); /* lprie */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-4];
    goto v13;

v13:
    v116 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v10;
    v116 = nil;
    { popv(5); return onevalue(v116); }

v52:
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = qcar(v116);
    fn = elt(env, 7); /* get!+row!+nr */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v116);
    }
/* error exit handlers */
v10:
    popv(5);
    return nil;
}



/* Code for cl_applysac1 */

static Lisp_Object MS_CDECL CC_cl_applysac1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v37,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_applysac1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac1");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v37,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    v106 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v106;
    goto v126;

v126:
    v125 = stack[-2];
    v107 = stack[-1];
    v106 = stack[0];
    fn = elt(env, 5); /* cl_applysac2 */
    v106 = (*qfnn(fn))(qenv(fn), 3, v125, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-4];
    v125 = v106;
    v107 = v125;
    v106 = elt(env, 2); /* break */
    if (!(v107 == v106)) goto v23;
    v106 = elt(env, 3); /* (nil) */
    v125 = v106;
    v106 = elt(env, 2); /* break */
    stack[-3] = v106;
    goto v23;

v23:
    v106 = v125;
    v106 = qcar(v106);
    if (v106 == nil) goto v54;
    v106 = v125;
    v106 = qcar(v106);
    v106 = qcar(v106);
    if (!(v106 == nil)) goto v54;
    v106 = qvalue(elt(env, 4)); /* nil */
    stack[-3] = v106;
    v106 = v125;
    v106 = qcar(v106);
    v106 = qcdr(v106);
    stack[-2] = v106;
    v106 = v125;
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v54;

v54:
    v106 = v125;
    v106 = qcar(v106);
    if (v106 == nil) goto v108;
    v106 = v125;
    v106 = qcar(v106);
    v106 = qcar(v106);
    goto v127;

v127:
    if (v106 == nil) goto v126;
    v107 = stack[-3];
    v106 = elt(env, 2); /* break */
    if (v107 == v106) goto v88;
    v106 = v125;
    v106 = qcar(v106);
    if (v106 == nil) { popv(5); return onevalue(v125); }
    v107 = stack[-3];
    v106 = v125;
    v106 = qcar(v106);
    v106 = qcdr(v106);
    v125 = qcdr(v125);
    popv(5);
    return acons(v107, v106, v125);

v88:
    v106 = elt(env, 2); /* break */
    { popv(5); return onevalue(v106); }

v108:
    v106 = qvalue(elt(env, 1)); /* t */
    goto v127;
/* error exit handlers */
v8:
    popv(5);
    return nil;
}



/* Code for logrtn */

static Lisp_Object CC_logrtn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for logrtn");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    v127 = stack[-2];
    v127 = qcdr(v127);
    v127 = qcar(v127);
    stack[0] = v127;
    v127 = stack[0];
    fn = elt(env, 3); /* msd */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    v127 = sub1(v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    stack[-3] = v127;
    v108 = elt(env, 1); /* 2.0 */
    v127 = stack[-3];
    v127 = Lexpt(nil, v108, v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    v127 = quot2(stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    fn = elt(env, 4); /* log */
    stack[0] = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    v108 = stack[-3];
    v127 = stack[-2];
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v108 = plus2(v108, v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    v127 = qvalue(elt(env, 2)); /* log2 */
    v127 = times2(v108, v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    v127 = plus2(stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v108 = v127;
    v127 = stack[-1];
    popv(5);
    return quot2(v108, v127);
/* error exit handlers */
v63:
    popv(5);
    return nil;
}



/* Code for physopplus */

static Lisp_Object CC_physopplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopplus");
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
    v66 = stack[0];
    v66 = qcar(v66);
    fn = elt(env, 3); /* physopsim!* */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-3] = v66;
    v66 = stack[0];
    v66 = qcdr(v66);
    stack[0] = v66;
    goto v31;

v31:
    v66 = stack[0];
    if (v66 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v66 = stack[0];
    v66 = qcar(v66);
    fn = elt(env, 3); /* physopsim!* */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-2] = v66;
    v66 = stack[-3];
    fn = elt(env, 4); /* getphystype */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v66;
    v66 = stack[-2];
    fn = elt(env, 4); /* getphystype */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v88 = v66;
    if (v88 == nil) goto v127;
    v88 = stack[-1];
    if (v88 == nil) goto v127;
    v88 = stack[-1];
    if (v88 == v66) goto v127;
    v88 = elt(env, 0); /* physopplus */
    v66 = elt(env, 2); /* "type mismatch in plus " */
    fn = elt(env, 5); /* rederr2 */
    v66 = (*qfn2(fn))(qenv(fn), v88, v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v127;

v127:
    v66 = stack[-3];
    fn = elt(env, 6); /* physop2sq */
    stack[-1] = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v66 = stack[-2];
    fn = elt(env, 6); /* physop2sq */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    fn = elt(env, 7); /* addsq */
    v66 = (*qfn2(fn))(qenv(fn), stack[-1], v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    fn = elt(env, 8); /* mk!*sq */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-3] = v66;
    v66 = stack[0];
    v66 = qcdr(v66);
    stack[0] = v66;
    goto v31;
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for coeff_ordn1 */

static Lisp_Object CC_coeff_ordn1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v123, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_ordn1");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v0;
/* end of prologue */

v129:
    v61 = stack[-1];
    if (v61 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v61 = stack[-1];
    v127 = qcar(v61);
    v61 = stack[-1];
    v123 = qcdr(v61);
    v61 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* p_subsatlaslist */
    v61 = (*qfnn(fn))(qenv(fn), 3, v127, v123, v61);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    v123 = v61;
    v61 = v123;
    if (v61 == nil) goto v22;
    v61 = stack[0];
    stack[-1] = v123;
    stack[0] = v61;
    goto v129;

v22:
    v61 = stack[-1];
    stack[-2] = qcdr(v61);
    v61 = stack[-1];
    v123 = qcar(v61);
    v61 = stack[0];
    v61 = cons(v123, v61);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v61;
    goto v129;
/* error exit handlers */
v15:
    popv(4);
    return nil;
}



/* Code for frlp */

static Lisp_Object CC_frlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v39, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v0;
/* end of prologue */

v129:
    v130 = v39;
    if (v130 == nil) goto v2;
    v130 = v39;
    v24 = qcar(v130);
    v130 = qvalue(elt(env, 2)); /* frlis!* */
    v130 = Lmemq(nil, v24, v130);
    if (v130 == nil) goto v60;
    v130 = v39;
    v130 = qcdr(v130);
    v39 = v130;
    goto v129;

v60:
    v130 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v130);

v2:
    v130 = qvalue(elt(env, 1)); /* t */
    return onevalue(v130);
}



/* Code for inormmat */

static Lisp_Object CC_inormmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inormmat");
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
    v27 = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-5] = v27;
    goto v95;

v95:
    v27 = stack[-5];
    if (v27 == nil) goto v52;
    v27 = stack[-5];
    v27 = qcar(v27);
    stack[-1] = v27;
    v27 = (Lisp_Object)17; /* 1 */
    stack[-7] = v27;
    v27 = stack[-1];
    stack[0] = v27;
    goto v91;

v91:
    v27 = stack[0];
    if (v27 == nil) goto v55;
    v27 = stack[0];
    v27 = qcar(v27);
    v28 = stack[-7];
    v27 = qcdr(v27);
    fn = elt(env, 2); /* ilcm */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    stack[-7] = v27;
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v91;

v55:
    v27 = stack[-1];
    stack[-4] = v27;
    v27 = stack[-4];
    if (v27 == nil) goto v17;
    v27 = stack[-4];
    v27 = qcar(v27);
    v28 = v27;
    stack[0] = qcar(v28);
    v28 = stack[-7];
    v27 = qcdr(v27);
    v27 = quot2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    v27 = times2(stack[0], v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    stack[-2] = v27;
    stack[-3] = v27;
    goto v123;

v123:
    v27 = stack[-4];
    v27 = qcdr(v27);
    stack[-4] = v27;
    v27 = stack[-4];
    if (v27 == nil) goto v10;
    stack[-1] = stack[-2];
    v27 = stack[-4];
    v27 = qcar(v27);
    v28 = v27;
    stack[0] = qcar(v28);
    v28 = stack[-7];
    v27 = qcdr(v27);
    v27 = quot2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    v27 = times2(stack[0], v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    v27 = Lrplacd(nil, stack[-1], v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    v27 = stack[-2];
    v27 = qcdr(v27);
    stack[-2] = v27;
    goto v123;

v10:
    v27 = stack[-3];
    v28 = v27;
    goto v56;

v56:
    v27 = stack[-6];
    v27 = cons(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-8];
    stack[-6] = v27;
    v27 = stack[-5];
    v27 = qcdr(v27);
    stack[-5] = v27;
    goto v95;

v17:
    v27 = qvalue(elt(env, 1)); /* nil */
    v28 = v27;
    goto v56;

v52:
    v27 = stack[-6];
        popv(9);
        return Lreverse(nil, v27);
/* error exit handlers */
v83:
    popv(9);
    return nil;
}



/* Code for validrule1 */

static Lisp_Object CC_validrule1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v125, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for validrule1");
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
    v133 = v0;
/* end of prologue */
    v107 = v133;
    if (!consp(v107)) goto v2;
    v107 = v133;
    v125 = qcar(v107);
    v107 = elt(env, 2); /* list */
    if (v125 == v107) goto v51;
    v107 = v133;
    v125 = qcar(v107);
    v107 = elt(env, 3); /* replaceby */
    if (v125 == v107) { popv(5); return onevalue(v133); }
    v107 = v133;
    v125 = qcar(v107);
    v107 = elt(env, 4); /* equal */
    if (v125 == v107) goto v134;
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v107); }

v134:
    v107 = elt(env, 3); /* replaceby */
    v125 = v133;
    v125 = qcdr(v125);
    popv(5);
    return cons(v107, v125);

v51:
    v107 = v133;
    v107 = qcdr(v107);
    if (v107 == nil) goto v43;
    v107 = v133;
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v41;
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_validrule1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-1] = v107;
    stack[-2] = v107;
    goto v86;

v86:
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_validrule1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v86;

v41:
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v107); }

v43:
    v107 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return ncons(v107);

v2:
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v107); }
/* error exit handlers */
v71:
    popv(5);
    return nil;
}



/* Code for qqe_qadd!-inside */

static Lisp_Object CC_qqe_qaddKinside(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qadd-inside");
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
    stack[0] = v0;
/* end of prologue */
    v104 = stack[0];
    if (v104 == nil) goto v137;
    v104 = stack[0];
    v104 = (consp(v104) ? nil : lisp_true);
    goto v31;

v31:
    if (v104 == nil) goto v95;
    v104 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v104); }

v95:
    v104 = stack[0];
    fn = elt(env, 6); /* qqe_op */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    stack[-1] = v104;
    v136 = elt(env, 3); /* a */
    v104 = qvalue(elt(env, 4)); /* qqe_qadd!-location!* */
    v104 = cons(v136, v104);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    qvalue(elt(env, 4)) = v104; /* qqe_qadd!-location!* */
    v104 = stack[0];
    v104 = Lconsp(nil, v104);
    env = stack[-3];
    if (v104 == nil) goto v54;
    v104 = stack[-1];
    fn = elt(env, 7); /* qqe_qopaddp */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    if (!(v104 == nil)) goto v54;
    v104 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v104;
    v104 = stack[-1];
    v136 = v104;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[-1] = v104;
    v104 = qvalue(elt(env, 4)); /* qqe_qadd!-location!* */
    stack[0] = v104;
    goto v68;

v68:
    v104 = stack[-1];
    if (v104 == nil) goto v56;
    v104 = stack[-2];
    if (v104 == nil) goto v56;
    v136 = elt(env, 5); /* d */
    v104 = stack[0];
    v104 = cons(v136, v104);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    qvalue(elt(env, 4)) = v104; /* qqe_qadd!-location!* */
    v104 = qvalue(elt(env, 4)); /* qqe_qadd!-location!* */
    stack[0] = v104;
    v104 = stack[-1];
    if (!consp(v104)) goto v138;
    v104 = stack[-1];
    v104 = qcar(v104);
    v104 = Lconsp(nil, v104);
    env = stack[-3];
    if (v104 == nil) goto v35;
    v104 = stack[-1];
    v104 = qcar(v104);
    v104 = CC_qqe_qaddKinside(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    goto v139;

v139:
    if (v104 == nil) goto v66;
    v104 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v104;
    goto v66;

v66:
    v104 = stack[-1];
    v136 = v104;
    v104 = stack[-1];
    v104 = qcdr(v104);
    stack[-1] = v104;
    goto v68;

v35:
    v104 = qvalue(elt(env, 2)); /* nil */
    goto v139;

v138:
    v104 = qvalue(elt(env, 2)); /* nil */
    goto v139;

v56:
    v104 = stack[-2];
    if (v104 == nil) { popv(4); return onevalue(v136); }
    v104 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v104); }

v54:
    v104 = stack[0];
    v104 = Lconsp(nil, v104);
    env = stack[-3];
    if (v104 == nil) goto v5;
    v104 = stack[-1];
    fn = elt(env, 7); /* qqe_qopaddp */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    if (v104 == nil) goto v5;
    v104 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v104); }

v5:
    v104 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v104); }

v137:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v31;
/* error exit handlers */
v3:
    popv(4);
    return nil;
}



/* Code for iv_new */

static Lisp_Object CC_iv_new(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v130, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_new");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v37;
    v39 = v0;
/* end of prologue */
    v48 = v39;
    if (v48 == nil) goto v115;
    v48 = v39;
    v39 = v48;
    goto v46;

v46:
    v48 = v130;
    if (v48 == nil) goto v91;
    v48 = v130;
    goto v51;

v51:
    v48 = cons(v39, v48);
    errexit();
    return ncons(v48);

v91:
    v48 = (Lisp_Object)1; /* 0 */
    goto v51;

v115:
    v48 = (Lisp_Object)1; /* 0 */
    v39 = v48;
    goto v46;
}



/* Code for lengthf */

static Lisp_Object CC_lengthf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthf");
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
    v169 = stack[-1];
    if (v169 == nil) goto v2;
    v169 = stack[-1];
    if (!consp(v169)) goto v51;
    v170 = stack[-1];
    v169 = elt(env, 1); /* plus */
    if (!consp(v170)) goto v56;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v56;
    stack[0] = (Lisp_Object)49; /* 3 */
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = Llength(nil, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = sub1(v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    stack[0] = times2(stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = CC_lengthf(env, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v172 = stack[0];
        popv(4);
        return plus2(v172, v169);
    }

v56:
    v170 = stack[-1];
    v169 = elt(env, 2); /* times */
    if (!consp(v170)) goto v90;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v90;
    v169 = qvalue(elt(env, 3)); /* t */
    goto v45;

v45:
    if (v169 == nil) goto v87;
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = Llength(nil, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    stack[0] = sub1(v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = CC_lengthf(env, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v173 = stack[0];
        popv(4);
        return plus2(v173, v169);
    }

v87:
    v170 = stack[-1];
    v169 = elt(env, 5); /* quotient */
    if (!consp(v170)) goto v174;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v174;
    v169 = qvalue(elt(env, 6)); /* !*rational */
    if (v169 == nil) goto v175;
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcar(v169);
    fn = elt(env, 16); /* flatsizec */
    stack[0] = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcdr(v169);
    v169 = qcar(v169);
    fn = elt(env, 16); /* flatsizec */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    fn = elt(env, 17); /* max */
    v169 = (*qfn2(fn))(qenv(fn), stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = add1(v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    popv(4);
    return add1(v169);

v175:
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcar(v169);
    fn = elt(env, 16); /* flatsizec */
    stack[0] = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcdr(v169);
    v169 = qcar(v169);
    fn = elt(env, 16); /* flatsizec */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = plus2(stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    popv(4);
    return add1(v169);

v174:
    v170 = stack[-1];
    v169 = elt(env, 7); /* expt */
    if (!consp(v170)) goto v99;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v99;
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcar(v169);
    fn = elt(env, 16); /* flatsizec */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    popv(4);
    return add1(v169);

v99:
    v170 = stack[-1];
    v169 = elt(env, 8); /* dx */
    if (!consp(v170)) goto v176;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v176;
    v169 = qvalue(elt(env, 3)); /* t */
    goto v177;

v177:
    if (v169 == nil) goto v178;
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcar(v169);
    fn = elt(env, 16); /* flatsizec */
    v170 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v169 = (Lisp_Object)65; /* 4 */
    popv(4);
    return plus2(v170, v169);

v178:
    v170 = stack[-1];
    v169 = elt(env, 10); /* xi */
    if (!consp(v170)) goto v179;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v179;
    v169 = qvalue(elt(env, 3)); /* t */
    goto v180;

v180:
    if (v169 == nil) goto v181;
    stack[0] = (Lisp_Object)33; /* 2 */
    v169 = stack[-1];
    v169 = Llength(nil, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v182 = stack[0];
        popv(4);
        return times2(v182, v169);
    }

v181:
    v170 = stack[-1];
    v169 = elt(env, 15); /* df */
    if (!consp(v170)) goto v183;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v183;
    stack[-2] = (Lisp_Object)65; /* 4 */
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcar(v169);
    stack[0] = CC_lengthf(env, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = qcdr(v169);
    v169 = CC_lengthf(env, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = plus2(stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v184 = stack[-2];
        popv(4);
        return plus2(v184, v169);
    }

v183:
    v169 = stack[-1];
    v169 = qcar(v169);
    stack[0] = CC_lengthf(env, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v169 = stack[-1];
    v169 = qcdr(v169);
    v169 = CC_lengthf(env, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v185 = stack[0];
        popv(4);
        return plus2(v185, v169);
    }

v179:
    v170 = stack[-1];
    v169 = elt(env, 11); /* eta */
    if (!consp(v170)) goto v186;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v186;
    v169 = qvalue(elt(env, 3)); /* t */
    goto v180;

v186:
    v170 = stack[-1];
    v169 = elt(env, 12); /* c */
    if (!consp(v170)) goto v187;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v187;
    v169 = qvalue(elt(env, 3)); /* t */
    goto v180;

v187:
    v170 = stack[-1];
    v169 = elt(env, 13); /* x */
    if (!consp(v170)) goto v188;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v188;
    v169 = qvalue(elt(env, 3)); /* t */
    goto v180;

v188:
    v170 = stack[-1];
    v169 = elt(env, 14); /* u */
    v169 = Leqcar(nil, v170, v169);
    env = stack[-3];
    goto v180;

v176:
    v170 = stack[-1];
    v169 = elt(env, 9); /* du */
    v169 = Leqcar(nil, v170, v169);
    env = stack[-3];
    goto v177;

v90:
    v170 = stack[-1];
    v169 = elt(env, 4); /* minus */
    v169 = Leqcar(nil, v170, v169);
    env = stack[-3];
    goto v45;

v51:
    v169 = stack[-1];
    {
        popv(4);
        fn = elt(env, 16); /* flatsizec */
        return (*qfn1(fn))(qenv(fn), v169);
    }

v2:
    v169 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v169); }
/* error exit handlers */
v171:
    popv(4);
    return nil;
}



/* Code for xreduce1 */

static Lisp_Object MS_CDECL CC_xreduce1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v37,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v40, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xreduce1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xreduce1");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v37,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v126;

v126:
    v53 = stack[-2];
    v40 = stack[-1];
    v41 = stack[0];
    fn = elt(env, 1); /* weak_xreduce1 */
    v41 = (*qfnn(fn))(qenv(fn), 3, v53, v40, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[-2] = v41;
    if (v41 == nil) goto v118;
    v41 = stack[-2];
    v40 = qcar(v41);
    v41 = stack[-3];
    v41 = cons(v40, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[-3] = v41;
    v41 = stack[-2];
    v41 = qcdr(v41);
    stack[-2] = v41;
    goto v126;

v118:
    v41 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v41);
    }
/* error exit handlers */
v44:
    popv(5);
    return nil;
}



/* Code for subsetneqp */

static Lisp_Object CC_subsetneqp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsetneqp");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v0;
/* end of prologue */
    v48 = stack[-1];
    v189 = stack[0];
    fn = elt(env, 2); /* subsetp */
    v189 = (*qfn2(fn))(qenv(fn), v48, v189);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    if (v189 == nil) goto v1;
    v48 = stack[0];
    v189 = stack[-1];
    fn = elt(env, 2); /* subsetp */
    v189 = (*qfn2(fn))(qenv(fn), v48, v189);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v189 = (v189 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v189); }

v1:
    v189 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v189); }
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for exp!: */

static Lisp_Object CC_expT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v261, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exp:");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v37;
    stack[-11] = v0;
/* end of prologue */
    v260 = stack[-10];
    v260 = integerp(v260);
    if (v260 == nil) goto v52;
    v261 = stack[-10];
    v260 = (Lisp_Object)1; /* 0 */
    v260 = (Lisp_Object)lesseq2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    v260 = v260 ? lisp_true : nil;
    env = stack[-14];
    goto v51;

v51:
    if (v260 == nil) goto v22;
    stack[0] = (Lisp_Object)1; /* 0 */
    v261 = elt(env, 2); /* "Invalid argument to" */
    v260 = elt(env, 0); /* exp!: */
    v260 = list2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    {
        Lisp_Object v264 = stack[0];
        popv(15);
        fn = elt(env, 7); /* error */
        return (*qfn2(fn))(qenv(fn), v264, v260);
    }

v22:
    v260 = stack[-11];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = (Lisp_Object)1; /* 0 */
    if (v261 == v260) goto v40;
    stack[0] = elt(env, 4); /* !:rd!: */
    v260 = stack[-11];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = (Lisp_Object)1; /* 0 */
    v260 = (Lisp_Object)greaterp2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    v260 = v260 ? lisp_true : nil;
    env = stack[-14];
    if (v260 == nil) goto v10;
    v260 = stack[-11];
    goto v135;

v135:
    stack[-1] = v260;
    v261 = v260;
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v261 = Lash1(nil, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-9] = v261;
    v260 = (Lisp_Object)1; /* 0 */
    v260 = list2star(stack[0], v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[0] = v260;
    v261 = stack[-1];
    v260 = stack[0];
    fn = elt(env, 8); /* difference!: */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-2] = stack[-10];
    v260 = stack[-9];
    fn = elt(env, 9); /* msd */
    v261 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = (Lisp_Object)113; /* 7 */
    v260 = plus2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = plus2(stack[-2], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-12] = v260;
    v261 = stack[-1];
    v260 = stack[0];
    fn = elt(env, 8); /* difference!: */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-8] = v260;
    v260 = stack[0];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = (Lisp_Object)1; /* 0 */
    if (v261 == v260) goto v265;
    v260 = stack[-12];
    stack[0] = qvalue(elt(env, 5)); /* !:bprec!: */
    qvalue(elt(env, 5)) = v260; /* !:bprec!: */
    v260 = stack[-12];
    fn = elt(env, 10); /* !:e */
    v261 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-14];
    v260 = stack[-9];
    fn = elt(env, 11); /* texpt!: */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-14];
    stack[-7] = v260;
    qvalue(elt(env, 5)) = stack[0]; /* !:bprec!: */
    goto v267;

v267:
    v260 = stack[-8];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = (Lisp_Object)1; /* 0 */
    if (v261 == v260) goto v164;
    stack[-1] = elt(env, 4); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v260 = stack[-12];
    v260 = negate(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = list2star(stack[-1], stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-4] = v260;
    v260 = qvalue(elt(env, 3)); /* bfone!* */
    stack[0] = v260;
    stack[-2] = v260;
    stack[-6] = v260;
    v260 = (Lisp_Object)17; /* 1 */
    stack[-9] = v260;
    v260 = (Lisp_Object)1; /* 0 */
    stack[-5] = v260;
    goto v268;

v268:
    v261 = stack[0];
    v260 = stack[-4];
    fn = elt(env, 12); /* greaterp!: */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    if (v260 == nil) goto v269;
    stack[0] = elt(env, 4); /* !:rd!: */
    stack[-1] = stack[-9];
    v260 = stack[-5];
    v260 = add1(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-5] = v260;
    v261 = times2(stack[-1], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-9] = v261;
    v260 = (Lisp_Object)1; /* 0 */
    v260 = list2star(stack[0], v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-3] = v260;
    stack[-1] = elt(env, 4); /* !:rd!: */
    v260 = stack[-2];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = stack[-8];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    stack[0] = times2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-2];
    v260 = qcdr(v260);
    v261 = qcdr(v260);
    v260 = stack[-8];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = plus2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[0] = list2star(stack[-1], stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-12];
    v260 = negate(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    fn = elt(env, 13); /* cut!:ep */
    v260 = (*qfn2(fn))(qenv(fn), stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-2] = v260;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[-13] = stack[-12];
    v260 = stack[-3];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = (Lisp_Object)1; /* 0 */
    if (v261 == v260) goto v270;
    v260 = stack[-3];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    v260 = Labsval(nil, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-3];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = sub1(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = plus2(stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    goto v173;

v173:
    stack[-13] = difference2(stack[-13], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-2];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = (Lisp_Object)1; /* 0 */
    if (v261 == v260) goto v271;
    v260 = stack[-2];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    v260 = Labsval(nil, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-2];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = sub1(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = plus2(stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    goto v170;

v170:
    v260 = plus2(stack[-13], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    fn = elt(env, 14); /* max */
    v260 = (*qfn2(fn))(qenv(fn), stack[-1], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v262 = stack[-2];
    v261 = stack[-3];
    fn = elt(env, 15); /* divide!: */
    v260 = (*qfnn(fn))(qenv(fn), 3, v262, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[0] = v260;
    v261 = stack[-6];
    v260 = stack[0];
    fn = elt(env, 16); /* plus!: */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-6] = v260;
    v261 = stack[-5];
    v260 = (Lisp_Object)161; /* 10 */
    v261 = Cremainder(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = (Lisp_Object)1; /* 0 */
    if (!(v261 == v260)) goto v268;
    stack[-1] = stack[-6];
    v260 = stack[-12];
    v260 = negate(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    fn = elt(env, 13); /* cut!:ep */
    v260 = (*qfn2(fn))(qenv(fn), stack[-1], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-6] = v260;
    goto v268;

v271:
    v260 = (Lisp_Object)1; /* 0 */
    goto v170;

v270:
    v260 = (Lisp_Object)1; /* 0 */
    goto v173;

v269:
    stack[-1] = elt(env, 4); /* !:rd!: */
    v260 = stack[-7];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = stack[-6];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    stack[0] = times2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-7];
    v260 = qcdr(v260);
    v261 = qcdr(v260);
    v260 = stack[-6];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = plus2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[0] = list2star(stack[-1], stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-10];
    v260 = add1(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    fn = elt(env, 17); /* cut!:mt */
    v260 = (*qfn2(fn))(qenv(fn), stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    stack[-1] = v260;
    v261 = stack[-11];
    v260 = elt(env, 4); /* !:rd!: */
    if (!consp(v261)) goto v272;
    v261 = qcar(v261);
    if (!(v261 == v260)) goto v272;
    v260 = stack[-11];
    v260 = qcdr(v260);
    v260 = (consp(v260) ? nil : lisp_true);
    v260 = (v260 == nil ? lisp_true : nil);
    goto v273;

v273:
    if (v260 == nil) goto v274;
    v260 = stack[-11];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = (Lisp_Object)1; /* 0 */
    v260 = (Lisp_Object)lessp2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    v260 = v260 ? lisp_true : nil;
    env = stack[-14];
    goto v275;

v275:
    if (v260 == nil) goto v276;
    v262 = qvalue(elt(env, 3)); /* bfone!* */
    v261 = stack[-1];
    v260 = stack[-10];
    {
        popv(15);
        fn = elt(env, 15); /* divide!: */
        return (*qfnn(fn))(qenv(fn), 3, v262, v261, v260);
    }

v276:
    v261 = stack[-1];
    v260 = stack[-10];
    {
        popv(15);
        fn = elt(env, 18); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v261, v260);
    }

v274:
    v260 = qvalue(elt(env, 6)); /* nil */
    goto v275;

v272:
    v260 = qvalue(elt(env, 6)); /* nil */
    goto v273;

v164:
    v260 = qvalue(elt(env, 3)); /* bfone!* */
    stack[-6] = v260;
    goto v269;

v265:
    v260 = qvalue(elt(env, 3)); /* bfone!* */
    stack[-7] = v260;
    goto v267;

v10:
    stack[-1] = elt(env, 4); /* !:rd!: */
    v260 = stack[-11];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    v261 = negate(v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    v260 = stack[-11];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = list2star(stack[-1], v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-14];
    goto v135;

v40:
    v260 = qvalue(elt(env, 3)); /* bfone!* */
    { popv(15); return onevalue(v260); }

v52:
    v260 = qvalue(elt(env, 1)); /* t */
    goto v51;
/* error exit handlers */
v266:
    env = stack[-14];
    qvalue(elt(env, 5)) = stack[0]; /* !:bprec!: */
    popv(15);
    return nil;
v263:
    popv(15);
    return nil;
}



/* Code for simpinnerprod */

static Lisp_Object CC_simpinnerprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpinnerprod");
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
    v1 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitinnerprod */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v101:
    popv(1);
    return nil;
}



/* Code for new_edge */

static Lisp_Object CC_new_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v0;
/* end of prologue */
    v68 = stack[-1];
    v18 = qcar(v68);
    v68 = stack[0];
    v68 = qcar(v68);
    fn = elt(env, 3); /* mk_edge_name */
    stack[-2] = (*qfn2(fn))(qenv(fn), v18, v68);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v68 = stack[-1];
    v18 = qcar(v68);
    v68 = stack[0];
    v68 = qcar(v68);
    v18 = cons(v18, v68);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v68 = qvalue(elt(env, 1)); /* nil */
    v68 = list3(stack[-2], v18, v68);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    stack[0] = v68;
    v18 = stack[0];
    v68 = qvalue(elt(env, 2)); /* new_edge_list */
    v68 = cons(v18, v68);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    qvalue(elt(env, 2)) = v68; /* new_edge_list */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for generic!-sub */

static Lisp_Object CC_genericKsub(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for generic-sub");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v57 = v37;
    v79 = v0;
/* end of prologue */
    stack[-2] = v79;
    stack[-1] = elt(env, 1); /* dfp */
    stack[0] = v57;
    v57 = elt(env, 2); /* list */
    v57 = ncons(v57);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    v57 = list3(stack[-1], stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    {
        Lisp_Object v48 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* dfp!-sub */
        return (*qfn2(fn))(qenv(fn), v48, v57);
    }
/* error exit handlers */
v189:
    popv(4);
    return nil;
}



/* Code for fs!:intequiv!: */

static Lisp_Object CC_fsTintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:intequiv:");
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
    v76 = v0;
/* end of prologue */
    v76 = qcdr(v76);
    stack[0] = v76;
    v87 = stack[0];
    v76 = (Lisp_Object)49; /* 3 */
    v76 = *(Lisp_Object *)((char *)v87 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL)));
    if (v76 == nil) goto v46;
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v76); }

v46:
    v76 = stack[0];
    fn = elt(env, 3); /* fs!:null!-angle */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-1];
    if (v76 == nil) goto v42;
    v87 = stack[0];
    v76 = (Lisp_Object)17; /* 1 */
    v87 = *(Lisp_Object *)((char *)v87 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL)));
    v76 = elt(env, 2); /* cos */
    if (v87 == v76) goto v55;
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v76); }

v55:
    v87 = stack[0];
    v76 = (Lisp_Object)1; /* 0 */
    v76 = *(Lisp_Object *)((char *)v87 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL)));
    v76 = qcar(v76);
    v76 = integerp(v76);
    if (v76 == nil) goto v45;
    v87 = stack[0];
    v76 = (Lisp_Object)1; /* 0 */
    v76 = *(Lisp_Object *)((char *)v87 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL)));
    v87 = qcdr(v76);
    v76 = (Lisp_Object)17; /* 1 */
    v76 = (v87 == v76 ? lisp_true : nil);
    { popv(2); return onevalue(v76); }

v45:
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v76); }

v42:
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v76); }
/* error exit handlers */
v117:
    popv(2);
    return nil;
}



/* Code for all_index_lst */

static Lisp_Object CC_all_index_lst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_index_lst");
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
    goto v101;

v101:
    v34 = stack[-1];
    if (v34 == nil) goto v46;
    v34 = stack[-1];
    v34 = qcar(v34);
    v34 = qcdr(v34);
    stack[0] = v34;
    v34 = stack[0];
    v34 = qcar(v34);
    fn = elt(env, 3); /* listp */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    if (v34 == nil) goto v78;
    v34 = stack[0];
    v34 = qcar(v34);
    v33 = qcar(v34);
    v34 = elt(env, 1); /* list */
    if (!(v33 == v34)) goto v78;
    v34 = stack[0];
    v34 = qcdr(v34);
    v33 = v34;
    goto v92;

v92:
    v34 = stack[-2];
    v34 = cons(v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    stack[-2] = v34;
    v34 = stack[-1];
    v34 = qcdr(v34);
    stack[-1] = v34;
    goto v101;

v78:
    v34 = stack[0];
    v33 = v34;
    goto v92;

v46:
    v34 = qvalue(elt(env, 2)); /* nil */
    v33 = v34;
    goto v51;

v51:
    v34 = stack[-2];
    if (v34 == nil) { popv(4); return onevalue(v33); }
    v34 = stack[-2];
    v34 = qcar(v34);
    v34 = Lappend(nil, v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    v33 = v34;
    v34 = stack[-2];
    v34 = qcdr(v34);
    stack[-2] = v34;
    goto v51;
/* error exit handlers */
v89:
    popv(4);
    return nil;
}



/* Code for eval_uni_poly */

static Lisp_Object CC_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v106, v107;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eval_uni_poly");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    v120 = stack[-2];
    if (!consp(v120)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v120 = stack[-2];
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v107 = v120;
    v120 = stack[-2];
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v106 = v120;
    v120 = stack[-2];
    v120 = qcdr(v120);
    stack[-2] = v120;
    goto v49;

v49:
    v120 = stack[-2];
    if (!consp(v120)) goto v135;
    stack[-3] = v107;
    stack[0] = stack[-1];
    v120 = stack[-2];
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v120 = difference2(v106, v120);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v120 = Lexpt(nil, stack[0], v120);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v106 = times2(stack[-3], v120);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v120 = stack[-2];
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v120 = plus2(v106, v120);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v107 = v120;
    v120 = stack[-2];
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v106 = v120;
    v120 = stack[-2];
    v120 = qcdr(v120);
    stack[-2] = v120;
    goto v49;

v135:
    stack[0] = v107;
    v120 = stack[-1];
    v120 = Lexpt(nil, v120, v106);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v120 = times2(stack[0], v120);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v107 = v120;
    v120 = stack[-2];
    if (v120 == nil) { popv(5); return onevalue(v107); }
    v106 = v107;
    v120 = stack[-2];
    v120 = plus2(v106, v120);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v107 = v120;
    { popv(5); return onevalue(v107); }
/* error exit handlers */
v7:
    popv(5);
    return nil;
}



/* Code for liqsimp1!-check */

static Lisp_Object MS_CDECL CC_liqsimp1Kcheck(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v37,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "liqsimp1-check");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for liqsimp1-check");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v37,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v21 = v38;
    stack[0] = v37;
    stack[-1] = v0;
/* end of prologue */
    v78 = v21;
    v21 = elt(env, 1); /* min */
    if (v78 == v21) goto v57;
    v78 = stack[-1];
    v21 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* liqsimp1!-check1 */
        return (*qfn2(fn))(qenv(fn), v78, v21);
    }

v57:
    v21 = stack[-1];
    v21 = qcar(v21);
    fn = elt(env, 3); /* negf */
    v78 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v21 = stack[-1];
    v21 = qcdr(v21);
    v78 = cons(v78, v21);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v21 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* liqsimp1!-check1 */
        return (*qfn2(fn))(qenv(fn), v78, v21);
    }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for rule!-list */

static Lisp_Object CC_ruleKlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v283, v284, v285, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule-list");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */

v52:
    v282 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v282; /* frasc!* */
    v282 = stack[-2];
    if (v282 == nil) goto v92;
    stack[0] = stack[-2];
    v282 = qvalue(elt(env, 1)); /* nil */
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v282 = (equal(stack[0], v282) ? lisp_true : nil);
    goto v115;

v115:
    if (v282 == nil) goto v60;
    v282 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 4)) = v282; /* mcond!* */
    { popv(5); return onevalue(v282); }

v60:
    v282 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 4)) = v282; /* mcond!* */
    v282 = stack[-2];
    v282 = qcar(v282);
    stack[-3] = v282;
    v282 = stack[-3];
    if (symbolp(v282)) goto v32;
    v282 = stack[-3];
    v283 = qcar(v282);
    v282 = elt(env, 6); /* list */
    if (v283 == v282) goto v74;
    v282 = stack[-3];
    v283 = qcar(v282);
    v282 = elt(env, 8); /* equal */
    if (v283 == v282) goto v133;
    v282 = stack[-3];
    v283 = qcar(v282);
    v282 = elt(env, 12); /* replaceby */
    if (v283 == v282) goto v54;
    v283 = stack[-3];
    v282 = elt(env, 13); /* "rule" */
    fn = elt(env, 16); /* typerr */
    v282 = (*qfn2(fn))(qenv(fn), v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v54;

v54:
    v282 = stack[-3];
    v282 = qcdr(v282);
    v282 = qcar(v282);
    fn = elt(env, 17); /* remove!-free!-vars */
    v282 = (*qfn1(fn))(qenv(fn), v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[0] = v282;
    v282 = stack[-3];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    v283 = qcar(v282);
    v282 = elt(env, 14); /* when */
    if (!consp(v283)) goto v163;
    v283 = qcar(v283);
    if (!(v283 == v282)) goto v163;
    v282 = stack[-3];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    v282 = qcar(v282);
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    v282 = qcar(v282);
    fn = elt(env, 18); /* remove!-free!-vars!* */
    v284 = (*qfn1(fn))(qenv(fn), v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v283 = qvalue(elt(env, 1)); /* nil */
    v282 = elt(env, 15); /* algebraic */
    fn = elt(env, 19); /* formbool */
    v282 = (*qfnn(fn))(qenv(fn), 3, v284, v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    qvalue(elt(env, 4)) = v282; /* mcond!* */
    v282 = stack[-3];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    v282 = qcar(v282);
    v282 = qcdr(v282);
    v282 = qcar(v282);
    fn = elt(env, 18); /* remove!-free!-vars!* */
    v282 = (*qfn1(fn))(qenv(fn), v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v286;

v286:
    v159 = stack[0];
    v285 = v282;
    v284 = qvalue(elt(env, 2)); /* frasc!* */
    v283 = qvalue(elt(env, 4)); /* mcond!* */
    v282 = stack[-1];
    fn = elt(env, 20); /* rule!* */
    v282 = (*qfnn(fn))(qenv(fn), 5, v159, v285, v284, v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v282 = stack[-2];
    v282 = qcdr(v282);
    stack[-2] = v282;
    goto v52;

v163:
    v282 = stack[-3];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    v282 = qcar(v282);
    fn = elt(env, 18); /* remove!-free!-vars!* */
    v282 = (*qfn1(fn))(qenv(fn), v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v286;

v133:
    v282 = qvalue(elt(env, 9)); /* !*msg */
    if (v282 == nil) goto v54;
    v283 = elt(env, 10); /* "***" */
    v282 = elt(env, 11); /* "Please use => instead of = in rules" */
    fn = elt(env, 21); /* lpriw */
    v282 = (*qfn2(fn))(qenv(fn), v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v54;

v74:
    v282 = stack[-3];
    v283 = qcdr(v282);
    v282 = stack[-2];
    v282 = qcdr(v282);
    v282 = Lappend(nil, v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-2] = v282;
    goto v52;

v32:
    v283 = stack[-3];
    v282 = elt(env, 5); /* avalue */
    v282 = get(v283, v282);
    env = stack[-4];
    v284 = v282;
    if (v282 == nil) goto v121;
    v282 = v284;
    v283 = qcar(v282);
    v282 = elt(env, 6); /* list */
    if (!(v283 == v282)) goto v121;
    v282 = v284;
    v282 = qcdr(v282);
    v282 = qcar(v282);
    v282 = qcdr(v282);
    v283 = Lreverse(nil, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v282 = stack[-2];
    v282 = qcdr(v282);
    v282 = Lappend(nil, v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-2] = v282;
    goto v52;

v121:
    v283 = stack[-3];
    v282 = elt(env, 7); /* "rule list" */
    fn = elt(env, 16); /* typerr */
    v282 = (*qfn2(fn))(qenv(fn), v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v54;

v92:
    v282 = qvalue(elt(env, 3)); /* t */
    goto v115;
/* error exit handlers */
v153:
    popv(5);
    return nil;
}



/* Code for qqe_prefix!-length */

static Lisp_Object CC_qqe_prefixKlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v56, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_prefix-length");
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
    v56 = v0;
/* end of prologue */
    v128 = (Lisp_Object)1; /* 0 */
    v68 = v128;
    v128 = v56;
    if (v128 == nil) goto v52;
    v128 = v56;
    stack[0] = v128;
    goto v42;

v42:
    v128 = stack[0];
    if (v128 == nil) { popv(2); return onevalue(v68); }
    v128 = stack[0];
    if (!consp(v128)) { popv(2); return onevalue(v68); }
    v128 = stack[0];
    v56 = qcar(v128);
    v128 = elt(env, 2); /* (rtail ltail rhead lhead) */
    v128 = Lmemq(nil, v56, v128);
    if (v128 == nil) goto v39;
    v128 = v68;
    v128 = add1(v128);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v68 = v128;
    goto v39;

v39:
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    stack[0] = v128;
    goto v42;

v52:
    v128 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v128;
    goto v42;
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for cpr_buchcrit4t */

static Lisp_Object CC_cpr_buchcrit4t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cpr_buchcrit4t");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v37;
    v126 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ev_disjointp */
    v60 = (*qfn2(fn))(qenv(fn), v126, v60);
    errexit();
    v60 = (v60 == nil ? lisp_true : nil);
    return onevalue(v60);
}



/* Code for rewrite2 */

static Lisp_Object CC_rewrite2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rewrite2");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v37;
    v62 = v0;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v62;
    goto v60;

v60:
    v62 = stack[0];
    if (v62 == nil) goto v26;
    v62 = stack[0];
    v62 = qcar(v62);
    v61 = v62;
    v62 = v61;
    v62 = qcdr(v62);
    stack[-3] = v62;
    v62 = v61;
    v62 = qcar(v62);
    v61 = v62;
    v62 = stack[-2];
    v62 = plus2(v61, v62);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v61 = v62;
    v62 = stack[-3];
    v62 = cons(v61, v62);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v61 = v62;
    v62 = stack[-1];
    v62 = cons(v61, v62);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    stack[-1] = v62;
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[0] = v62;
    goto v60;

v26:
    v62 = stack[-1];
        popv(5);
        return Lreverse(nil, v62);
/* error exit handlers */
v17:
    popv(5);
    return nil;
}



/* Code for tchscheme2 */

static Lisp_Object MS_CDECL CC_tchscheme2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tchscheme2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tchscheme2");
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
    v48 = (Lisp_Object)1; /* 0 */
    stack[0] = v48;
    goto v31;

v31:
    v130 = qvalue(elt(env, 1)); /* rowmax */
    v48 = stack[0];
    v48 = difference2(v130, v48);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    v48 = Lminusp(nil, v48);
    env = stack[-1];
    if (v48 == nil) goto v52;
    v48 = nil;
    { popv(2); return onevalue(v48); }

v52:
    v48 = stack[0];
    fn = elt(env, 3); /* removechild */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    v48 = stack[0];
    fn = elt(env, 4); /* to!*scheme */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    v48 = stack[0];
    v48 = add1(v48);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    stack[0] = v48;
    goto v31;
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for num */

static Lisp_Object CC_num(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num");
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
    v126 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[0];
    v31 = qcar(v126);
    v126 = (Lisp_Object)17; /* 1 */
    v126 = cons(v31, v126);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v126);
    }
/* error exit handlers */
v137:
    popv(1);
    return nil;
}



/* Code for updkorder */

static Lisp_Object CC_updkorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v40, v53;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for updkorder");
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
    v40 = v0;
/* end of prologue */
    v41 = qvalue(elt(env, 1)); /* kord!* */
    stack[-1] = v41;
    stack[0] = v40;
    v41 = stack[-1];
    v41 = Ldelete(nil, v40, v41);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    v41 = cons(stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    v53 = v41;
    v40 = stack[-1];
    v41 = v53;
    if (equal(v40, v41)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v41 = v53;
    qvalue(elt(env, 1)) = v41; /* kord!* */
    v41 = qvalue(elt(env, 2)); /* nil */
    v41 = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    qvalue(elt(env, 3)) = v41; /* alglist!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v21:
    popv(3);
    return nil;
}



/* Code for xadd */

static Lisp_Object MS_CDECL CC_xadd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v37,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xadd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xadd");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v37,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v37,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v37;
    stack[-2] = v0;
/* end of prologue */
    v251 = stack[-2];
    v290 = qcar(v251);
    v251 = stack[-1];
    v251 = Lassoc(nil, v290, v251);
    stack[-3] = v251;
    v251 = stack[-3];
    if (v251 == nil) goto v47;
    v251 = stack[0];
    if (v251 == nil) goto v32;
    v290 = stack[-3];
    v251 = stack[-1];
    v251 = Ldelete(nil, v290, v251);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-4];
    stack[-1] = v251;
    v251 = stack[-3];
    v251 = qcdr(v251);
    if (!consp(v251)) goto v67;
    v251 = stack[-3];
    v290 = Llength(nil, v251);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-4];
    v251 = (Lisp_Object)81; /* 5 */
    v251 = (v290 == v251 ? lisp_true : nil);
    goto v17;

v17:
    if (v251 == nil) goto v123;
    v251 = stack[-3];
    v251 = qcdr(v251);
    stack[-3] = v251;
    goto v123;

v123:
    v251 = stack[-3];
    v251 = qcdr(v251);
    if (!consp(v251)) goto v125;
    v251 = stack[-3];
    v251 = qcdr(v251);
    v251 = qcdr(v251);
    v290 = qcar(v251);
    v251 = stack[-3];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = qcdr(v251);
    fn = elt(env, 4); /* updoldrules */
    v251 = (*qfn2(fn))(qenv(fn), v290, v251);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-4];
    goto v125;

v125:
    v290 = stack[0];
    v251 = elt(env, 1); /* replace */
    if (v290 == v251) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v290 = stack[-2];
    v251 = stack[-1];
    v251 = cons(v290, v251);
    nil = C_nil;
    if (exception_pending()) goto v150;
    stack[-1] = v251;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v67:
    v251 = qvalue(elt(env, 2)); /* nil */
    goto v17;

v32:
    v251 = stack[-3];
    v251 = qcdr(v251);
    if (!consp(v251)) goto v29;
    v251 = qvalue(elt(env, 2)); /* nil */
    goto v3;

v3:
    if (v251 == nil) goto v291;
    v251 = qvalue(elt(env, 3)); /* t */
    goto v136;

v136:
    if (v251 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v290 = stack[-3];
    v251 = stack[-1];
    v251 = Ldelete(nil, v290, v251);
    nil = C_nil;
    if (exception_pending()) goto v150;
    stack[-1] = v251;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v291:
    v251 = stack[-3];
    v251 = qcdr(v251);
    if (!consp(v251)) goto v292;
    v251 = stack[-3];
    v251 = qcdr(v251);
    v290 = qcar(v251);
    v251 = stack[-2];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = (equal(v290, v251) ? lisp_true : nil);
    goto v136;

v292:
    v251 = qvalue(elt(env, 2)); /* nil */
    goto v136;

v29:
    v251 = stack[-3];
    v290 = qcdr(v251);
    v251 = stack[-2];
    v251 = qcdr(v251);
    v251 = (equal(v290, v251) ? lisp_true : nil);
    goto v3;

v47:
    v251 = stack[0];
    if (v251 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v290 = stack[0];
    v251 = elt(env, 1); /* replace */
    if (v290 == v251) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v290 = stack[-2];
    v251 = stack[-1];
    v251 = cons(v290, v251);
    nil = C_nil;
    if (exception_pending()) goto v150;
    stack[-1] = v251;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
/* error exit handlers */
v150:
    popv(5);
    return nil;
}



setup_type const u49_setup[] =
{
    {"physopsubs",              CC_physopsubs,  too_many_1,    wrong_no_1},
    {"coeff1_calc",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff1_calc},
    {"red_extract",             CC_red_extract, too_many_1,    wrong_no_1},
    {"permp:",                  too_few_2,      CC_permpT,     wrong_no_2},
    {"merge_list1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_merge_list1},
    {"constant_exprp",          CC_constant_exprp,too_many_1,  wrong_no_1},
    {"cl_gaussintersection",    too_few_2,      CC_cl_gaussintersection,wrong_no_2},
    {"sfto_yun-updecf",         CC_sfto_yunKupdecf,too_many_1, wrong_no_1},
    {"get_mat",                 too_few_2,      CC_get_mat,    wrong_no_2},
    {"cl_applysac1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_applysac1},
    {"logrtn",                  too_few_2,      CC_logrtn,     wrong_no_2},
    {"physopplus",              CC_physopplus,  too_many_1,    wrong_no_1},
    {"coeff_ordn1",             too_few_2,      CC_coeff_ordn1,wrong_no_2},
    {"frlp",                    CC_frlp,        too_many_1,    wrong_no_1},
    {"inormmat",                CC_inormmat,    too_many_1,    wrong_no_1},
    {"validrule1",              CC_validrule1,  too_many_1,    wrong_no_1},
    {"qqe_qadd-inside",         CC_qqe_qaddKinside,too_many_1, wrong_no_1},
    {"iv_new",                  too_few_2,      CC_iv_new,     wrong_no_2},
    {"lengthf",                 CC_lengthf,     too_many_1,    wrong_no_1},
    {"xreduce1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreduce1},
    {"subsetneqp",              too_few_2,      CC_subsetneqp, wrong_no_2},
    {"exp:",                    too_few_2,      CC_expT,       wrong_no_2},
    {"simpinnerprod",           CC_simpinnerprod,too_many_1,   wrong_no_1},
    {"new_edge",                too_few_2,      CC_new_edge,   wrong_no_2},
    {"generic-sub",             too_few_2,      CC_genericKsub,wrong_no_2},
    {"fs:intequiv:",            CC_fsTintequivT,too_many_1,    wrong_no_1},
    {"all_index_lst",           CC_all_index_lst,too_many_1,   wrong_no_1},
    {"eval_uni_poly",           too_few_2,      CC_eval_uni_poly,wrong_no_2},
    {"liqsimp1-check",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_liqsimp1Kcheck},
    {"rule-list",               too_few_2,      CC_ruleKlist,  wrong_no_2},
    {"qqe_prefix-length",       CC_qqe_prefixKlength,too_many_1,wrong_no_1},
    {"cpr_buchcrit4t",          too_few_2,      CC_cpr_buchcrit4t,wrong_no_2},
    {"rewrite2",                too_few_2,      CC_rewrite2,   wrong_no_2},
    {"tchscheme2",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_tchscheme2},
    {"num",                     CC_num,         too_many_1,    wrong_no_1},
    {"updkorder",               CC_updkorder,   too_many_1,    wrong_no_1},
    {"xadd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_xadd},
    {NULL, (one_args *)"u49", (two_args *)"13086 4785852 9079597", 0}
};

/* end of generated code */
