
// $destdir/u43.c        Machine generated C code

// $Id: u43.cpp 5210 2019-12-08 17:45:20Z arthurcnorman $

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdarg>
#include <ctime>
#include <csetjmp>
#include <exception>
#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG 1
#endif
#endif
#if defined HAVE_COMPLEX_H && \
 defined HAVE_COMPLEX_DOUBLE && \
 defined HAVE_CSQRT
#define HAVE_COMPLEX 1
#endif
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif
#ifdef __cpp_inline_variables
#define INLINE_VAR inline
#else
#define INLINE_VAR static
#endif
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#ifndef __has_cpp_attribute
#define __has_cpp_attribute(name) 0
#endif
#ifndef MAYBE_UNUSED
#if __has_cpp_attribute(maybe_unused)
#define MAYBE_UNUSED [[maybe_unused]]
#elif defined __GNUC__
#define MAYBE_UNUSED [[gnu::unused]]
#else
#define MAYBE_UNUSED
#endif
#endif
#ifdef WIN32
#define __USE_MINGW_ANSI_STDIO 1
#include <winsock.h>
#include <windows.h>
#else 
#define unix_posix 1 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>
#define WSAGetLastError() errno 
#define WSACleanup() 
#define closesocket(a) close(a)
#define SOCKET int
#define SOCKET_ERROR (-1)
#ifndef INADDR_NONE
# define INADDR_NONE 0xffffffff
#endif
#endif 
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cfloat>
#include <cstdint>
#include <cinttypes>
#include <climits>
#include <cstring>
#include <cctype>
#include <cwctype>
#include <ctime>
#include <cstdarg>
#include <csetjmp>
#include <csignal>
#include <cerrno>
#include <iostream>
#include <exception>
#include <cassert>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL
#include <ffi.h>
#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL
#ifndef EMBEDDED
extern "C"
{
#include "softfloat.h"
}
#endif
#if !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS 1
#endif
#endif
#ifdef WIN32
# if defined WIN64 || defined __WIN64__
# define OPSYS "win64"
# define IMPNAME "win64"
# else
# define OPSYS "win32"
# define IMPNAME "win32"
# endif
#else
# ifdef HOST_OS
# define OPSYS HOST_OS
# ifdef HOST_CPU
# define IMPNAME HOST_OS ":" HOST_CPU
# else
# define IMPNAME HOST_OS
# endif
# else
# define OPSYS "Unknown"
# define IMPNAME "Generic"
# endif
#endif
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
inline std::int32_t ASR(std::int32_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int32_t)) n=0;
 return a >> n;
}
inline std::int64_t ASR(std::int64_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int64_t)) n=0;
 return a >> n;
}
#else 
inline std::int32_t ASR(std::int32_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int32_t)) n=0;
 std::uint32_t r = ((std::uint32_t)a) >> n;
 std::uint32_t std::signbit = ((std::uint32_t)a) >> (8*sizeof(std::uint32_t)-1);
 if (n != 0) r |= ((-std::signbit) << (8*sizeof(std::uint32_t) - n));
 return (std::int32_t)r;
}
inline std::int64_t ASR(std::int64_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int64_t)) n=0;
 std::uint64_t r = ((std::uint64_t)a) >> n;
 std::uint64_t std::signbit = ((std::uint64_t)a) >> (8*sizeof(std::uint64_t)-1);
 if (n != 0) r |= ((-std::signbit) << (8*sizeof(std::uint64_t) - n));
 return (std::int64_t)r;
}
#endif 
inline std::int32_t ASL(std::int32_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(std::uint32_t)) n = 0;
 return (std::int32_t)(((std::uint32_t)a) << n);
}
inline std::int64_t ASL(std::int64_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(std::uint64_t)) n = 0;
 return (std::int64_t)(((std::uint64_t)a) << n);
}
inline std::uint64_t ASL(std::uint64_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(std::uint64_t)) n = 0;
 return a << n;
}
#ifdef HAVE_UINT128_T
#define HAVE_NATIVE_UINT128 1
#elif defined HAVE_UNSIGNED___INT128
typedef unsigned __int128 uint128_t;
#define HAVE_NATIVE_UINT128
#else
#include "uint128_t.h" 
#endif
#ifdef HAVE_INT128_T
#define HAVE_NATIVE_INT128 1
#elif defined HAVE___INT128
typedef __int128 int128_t;
#define HAVE_NATIVE_INT128
#elif defined HAVE_UINT128_T || defined HAVE_UNSIGNED___INT128
#error Seem to have unsigned 128-bit type but not a signed one!
#endif
#ifdef MAXALING4
inline void *aligned_malloc(std::size_t n)
{ void *p = (void *)std::malloc(n + 32);
 if (p == NULL) return p;
 void *r = (void *)((((std::uintptr_t)p + 15) & -(std::uint64_t)16) + 16);
 (void *)((std::uintptr_t)r - 16) = p;
 return r;
}
inline void aligned_free(void *p)
{ if (p == NULL) return;
 std::free(*(void *)((std::uintptr_t)p - 16));
}
#else 
inline void *aligned_malloc(std::size_t n)
{ return (void *)std::malloc(n);
}
inline void aligned_free(void *p)
{ std::free(p);
}
#endif 
#endif 
#ifndef header_fwin_h
#define header_fwin_h 1
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <csignal>
#ifdef DEBUG
extern void fwin_write_log(const char *s, ...);
#define FWIN_LOG(...) fwin_write_log(__VA_ARGS__)
#else
#define FWIN_LOG(...) ((void)0)
#endif
typedef int fwin_entrypoint(int argc, const char *argv[]);
extern int fwin_startup(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern const char *fullProgramName;
extern const char *programName;
extern const char *programDir;
#define FWIN_WITH_TERMED 1
#define FWIN_IN_WINDOW 2
extern int fwin_windowmode();
extern void fwin_exit(int return_code);
extern bool fwin_pause_at_end;
extern void fwin_minimize(void);
extern void fwin_restore(void);
extern void fwin_putchar(int c);
extern void fwin_puts(const char *s);
extern void fwin_showmath(const char *s);
extern void fwin_printf(const char *fmt, ...);
extern void fwin_vfprintf(const char *fmt, std::va_list a);
extern int fwin_linelength;
extern void fwin_ensure_screen(void);
extern int fwin_getchar(void);
#define MAX_PROMPT_LENGTH 80
extern void fwin_set_prompt(const char *s);
extern void fwin_clear_screen();
extern int fwin_screen_size();
typedef char *lookup_function(char *s, int ch);
extern void fwin_set_lookup(lookup_function *f);
typedef void delay_callback_t(int);
extern void fwin_callback_on_delay(delay_callback_t *f);
#define QUERY_INTERRUPT 0
#define QUIET_INTERRUPT 1
#define NOISY_INTERRUPT 2
#define BREAK_LOOP 3
#define QUIT_PROGRAM 4
typedef void review_switch_settings_function();
extern void fwin_menus(char **modules, char **switches,
 review_switch_settings_function *f);
extern void fwin_refresh_switches(char **switches, char **packages);
extern void fwin_report_left(const char *msg);
extern void fwin_report_mid(const char *msg);
extern void fwin_report_right(const char *msg);
extern char about_box_title[40]; 
extern char about_box_description[40]; 
extern char about_box_rights_1[40]; 
extern char about_box_rights_2[40]; 
extern char about_box_rights_3[40]; 
extern char about_box_rights_4[40]; 
extern void fwin_set_help_file(const char *key, const char *path);
extern int plain_worker(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern delay_callback_t *delay_callback;
extern void fwin_putchar_overwrite(int c);
extern void fwin_move_cursor_vertically(int n);
extern void fwin_move_to_column(int column);
#define INPUT_HISTORY_SIZE 100
extern wchar_t *input_history[INPUT_HISTORY_SIZE];
extern int input_history_next;
extern void input_history_init();
extern void input_history_end();
extern void input_history_add(const wchar_t *s);
extern const wchar_t *input_history_get(int n);
#ifndef INT_VERSION
#define INT_VERSION(a,b,c) (((a*1000) + b)*1000 + c)
#endif
extern int find_program_directory(const char *argv0);
typedef struct date_and_type_
{ unsigned long int date;
 unsigned long int type;
} date_and_type;
extern void set_filedate(const char *name, unsigned long int datestamp,
 unsigned long int ftype);
extern void put_fileinfo(date_and_type *p, const char *name);
extern int windowed;
extern int windowed_worker(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern bool fwin_use_xft;
extern bool directoryp(char *f, const char *o, std::size_t n);
extern bool using_termed;
extern int fwin_plain_getchar();
extern bool texmacs_mode;
#ifdef HAVE_SIGACTION
extern void sigint_handler(int signo, siginfo_t *t, void *v);
#else 
extern void sigint_handler(int signo);
#endif 
extern int plain_worker(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern char fwin_prompt_string[MAX_PROMPT_LENGTH];
extern int get_current_directory(char *s, std::size_t n);
extern bool file_readable(char *filename, const char *old, std::size_t n);
extern bool file_writeable(char *filename, const char *old, std::size_t n);
extern bool file_executable(char *filename, const char *old, std::size_t n);
extern int rename_file(char *from_name, const char *from_old, std::size_t from_size,
 char *to_name, const char *to_old, std::size_t to_size);
extern int get_home_directory(char *b, std::size_t len);
extern int get_users_home_directory(char *b, std::size_t len);
extern int my_system(const char *s);
extern int truncate_file(std::FILE *f, long int where);
#endif 
#ifndef header_int128_t_h
#define header_int128_t_h 1
#ifdef HAVE_NATIVE_INT128
inline uint128_t uint128(int128_t v)
{ return (uint128_t)v;
}
inline uint128_t uint128(std::uint64_t v)
{ return (uint128_t)v;
}
inline uint128_t uint128(std::int64_t v)
{ return (uint128_t)v;
}
inline int128_t int128(std::int64_t v)
{ return (int128_t)v;
}
inline bool greaterp128(int128_t a, int128_t b)
{ return a > b;
}
inline bool lessp128(int128_t a, int128_t b)
{ return a < b;
}
inline bool geq128(int128_t a, int128_t b)
{ return a >= b;
}
inline bool leq128(int128_t a, int128_t b)
{ return a <= b;
}
inline int128_t ASL128(int128_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int128_t)) n = 0;
 return(int128_t) ((uint128_t)a) << n;
}
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
inline int128_t ASR128(int128_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int128_t)) n = 0;
 return a >> n;
}
#else 
inline int128_t ASR128(int128_t a, int n)
{ if (n<0 || n>=(int)sizeof(uint128_t)) n = 0;
 uint128_t r = ((uint128_t)a) >> n;
 uint128_t std::signbit = ((uint128_t)a) >> (8*sizeof(uint128_t)-1);
 if (n != 0) r |= ((-std::signbit) << (8*sizeof(uint128_t) - n));
 return (int128_t)r;
}
#endif 
inline std::int64_t NARROW128(int128_t a)
{ return (std::int64_t)a;
}
inline void divrem128(int128_t a, int128_t b,
 int128_t &q, int128_t &r)
{ uint128_t qq = a/b;
 q = qq;
 r = a - qq*b;
}
#else 
typedef uint128_t int128_t;
inline uint128_t uint128(int128_t v)
{ uint128_t r = v;
 return r;
}
inline uint128_t uint128(std::int64_t v)
{ uint128_t r = (std::uint64_t)v;
 return r;
}
inline uint128_t uint128(std::uint64_t v)
{ uint128_t r = v;
 return r;
}
inline int128_t int128(std::int64_t v)
{ int128_t r = (std::uint64_t)v;
 if (v < 0)
 { int128_t w = -(std::uint64_t)1;
 w = w <<64;
 r = r | w;
 }
 return r;
}
inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa > bb;
}
inline bool lessp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa < bb;
}
inline bool geq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa >= bb;
}
inline bool leq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa <= bb;
}
inline int128_t ASL128(const int128_t & a, int n)
{ if (n >= 128) return 0;
 if (n < 64) return
 int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
 a.lower()<<n);
 else if (n == 64) return int128_t(a.lower(), 0);
 else return int128_t(a.lower()<<(n-64), 0);
}
inline int128_t ASR128(const int128_t & a, int n)
{ if (n >= 128) return (a < 0 ? -1 : 0);
 if (n < 64) return int128_t(ASR((std::int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else if (n == 64) return int128_t(-(std::int64_t)(a.upper()<0),
 a.upper());
 else if (n < 64) return int128_t(ASR((std::int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else return int128_t(-(std::int64_t)(a.upper()<0),
 ASR(((std::int64_t)a.upper()), n-64));
}
inline std::int64_t NARROW128(const int128_t & a)
{ return (std::int64_t)a.lower();
}
inline void divrem128(const int128_t & a, const int128_t & b,
 int128_t & q, int128_t & r)
{ if ((std::int64_t)a.upper() < 0)
 { if ((std::int64_t)b.upper() < 0) q = (-a)/(-b);
 else q = -((-a)/b);
 }
 else
 { if ((std::int64_t)b.upper() < 0) q = -(a/(-b));
 else q = a/b;
 }
 r = a - q*b;
}
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
typedef std::intptr_t LispObject;
extern LispObject nil;
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
inline void CSL_IGNORE(LispObject x)
{ (void)x;
}
#ifndef PAGE_BITS
# define PAGE_BITS 23
#endif 
#define PAGE_POWER_OF_TWO (((size_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO)
#ifndef MAX_HEAPSIZE
#define MAX_HEAPBITS (SIXTY_FOUR_BIT ? 41 : 31)
#define MAX_HEAPSIZE (((size_t)1) << (MAX_HEAPBITS-20))
#endif 
#define MEGABYTE ((size_t)0x100000)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif
#define LONGEST_LEGAL_FILENAME 1024
#define CELL ((size_t)sizeof(LispObject))
static const int TAG_BITS = 0x7;
static const int XTAG_BITS = 0xf;
static const int TAG_CONS = 0; 
static const int TAG_VECTOR = 1; 
static const int TAG_HDR_IMMED = 2; 
static const int TAG_FORWARD = 3; 
static const int TAG_SYMBOL = 4; 
static const int TAG_NUMBERS = 5; 
static const int TAG_BOXFLOAT = 6; 
static const int TAG_FIXNUM = 7; 
static const int TAG_XBIT = 8; 
static const int XTAG_SFLOAT = 15; 
static const int XTAG_FLOAT32 = 16;
inline bool is_forward(LispObject p)
{ return (p & TAG_BITS) == TAG_FORWARD;
}
inline bool is_number(LispObject p)
{ return (p & TAG_BITS) >= TAG_NUMBERS;
}
inline bool is_float(LispObject p)
{ return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}
inline bool is_immed_or_cons(LispObject p)
{ return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}
inline bool is_immed_cons_sym(LispObject p)
{ return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}
inline bool need_more_than_eq(LispObject p)
{ return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}
inline constexpr LispObject fixnum_of_int(std::intptr_t x)
{ return (LispObject)((((std::uintptr_t)x)<<4) + TAG_FIXNUM);
}
#define FIXNUM_OF_INT(n) (16*(n)+TAG_FIXNUM)
inline constexpr std::intptr_t int_of_fixnum(LispObject x)
{ return ((std::intptr_t)x & ~(std::intptr_t)15)/16;
}
inline bool valid_as_fixnum(std::int32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(std::int64_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(int128_t x)
{ return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}
inline bool intptr_valid_as_fixnum(std::intptr_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(std::uint32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return x < (((std::uintptr_t)1) << 28);
}
inline bool valid_as_fixnum(std::uint64_t x)
{ return x < (((std::uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
inline bool uint128_valid_as_fixnum(uint128_t x)
{ return x < (((std::uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))
#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)
inline bool is_cons(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_CONS);
}
inline bool is_fixnum(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM);
}
inline bool is_odds(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED); 
}
inline bool is_sfloat(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT);
}
inline bool is_symbol(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_SYMBOL);
}
inline bool is_numbers(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_NUMBERS);
}
inline bool is_vector(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_VECTOR);
}
inline bool is_bfloat(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT);
}
inline bool consp(LispObject p)
{ return is_cons(p);
}
inline bool symbolp(LispObject p)
{ return is_symbol(p);
}
inline bool car_legal(LispObject p)
{ return is_cons(p);
}
typedef struct Cons_Cell_
{ std::atomic<LispObject> car;
 std::atomic<LispObject> cdr;
} Cons_Cell;
extern bool valid_address(void *pointer);
[[noreturn]] extern void my_abort();
inline LispObject car(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ 
 return ((Cons_Cell *)p)->car.load(mo);
}
inline LispObject cdr(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ 
 return ((Cons_Cell *)p)->cdr.load(mo);
}
inline void setcar(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ 
 ((Cons_Cell *)p)->car.store(q, mo);
}
inline void setcdr(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ 
 ((Cons_Cell *)p)->cdr.store(q, mo);
}
inline std::atomic<LispObject> *caraddr(LispObject p)
{ 
 return &(((Cons_Cell *)p)->car);
}
inline std::atomic<LispObject> *cdraddr(LispObject p)
{ 
 return &(((Cons_Cell *)p)->cdr);
}
inline LispObject *vcaraddr(LispObject p)
{ 
 return (LispObject *)&(((Cons_Cell *)p)->car);
}
inline LispObject *vcdraddr(LispObject p)
{ 
 return (LispObject *)&(((Cons_Cell *)p)->cdr);
}
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject no_args(LispObject);
typedef LispObject one_arg(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject fourup_args(LispObject, LispObject, LispObject,
 LispObject, LispObject);
typedef std::uintptr_t Header;
#define Tw (3)
#define header_mask (0x7f<<Tw)
#define TYPE_BITVEC_1 ( 0x02 <<Tw) 
#define TYPE_BITVEC_2 ( 0x06 <<Tw) 
#define TYPE_BITVEC_3 ( 0x0a <<Tw) 
#define TYPE_BITVEC_4 ( 0x0c <<Tw) 
#define TYPE_BITVEC_5 ( 0x12 <<Tw) 
#define TYPE_BITVEC_6 ( 0x16 <<Tw) 
#define TYPE_BITVEC_7 ( 0x1a <<Tw) 
#define TYPE_BITVEC_8 ( 0x1c <<Tw) 
#define TYPE_BITVEC_9 ( 0x22 <<Tw) 
#define TYPE_BITVEC_10 ( 0x26 <<Tw) 
#define TYPE_BITVEC_11 ( 0x2a <<Tw) 
#define TYPE_BITVEC_12 ( 0x2c <<Tw) 
#define TYPE_BITVEC_13 ( 0x32 <<Tw) 
#define TYPE_BITVEC_14 ( 0x36 <<Tw) 
#define TYPE_BITVEC_15 ( 0x3a <<Tw) 
#define TYPE_BITVEC_16 ( 0x3c <<Tw) 
#define TYPE_BITVEC_17 ( 0x42 <<Tw) 
#define TYPE_BITVEC_18 ( 0x46 <<Tw) 
#define TYPE_BITVEC_19 ( 0x4a <<Tw) 
#define TYPE_BITVEC_20 ( 0x4c <<Tw) 
#define TYPE_BITVEC_21 ( 0x52 <<Tw) 
#define TYPE_BITVEC_22 ( 0x56 <<Tw) 
#define TYPE_BITVEC_23 ( 0x5a <<Tw) 
#define TYPE_BITVEC_24 ( 0x5c <<Tw) 
#define TYPE_BITVEC_25 ( 0x62 <<Tw) 
#define TYPE_BITVEC_26 ( 0x66 <<Tw) 
#define TYPE_BITVEC_27 ( 0x6a <<Tw) 
#define TYPE_BITVEC_28 ( 0x6c <<Tw) 
#define TYPE_BITVEC_29 ( 0x72 <<Tw) 
#define TYPE_BITVEC_30 ( 0x76 <<Tw) 
#define TYPE_BITVEC_31 ( 0x7a <<Tw) 
#define TYPE_BITVEC_32 ( 0x7c <<Tw) 
#define TYPE_STRING_1 ( 0x07 <<Tw) 
#define TYPE_STRING_2 ( 0x27 <<Tw) 
#define TYPE_STRING_3 ( 0x47 <<Tw) 
#define TYPE_STRING_4 ( 0x67 <<Tw) 
#define TYPE_VEC8_1 ( 0x03 <<Tw) 
#define TYPE_VEC8_2 ( 0x23 <<Tw) 
#define TYPE_VEC8_3 ( 0x43 <<Tw) 
#define TYPE_VEC8_4 ( 0x63 <<Tw) 
#define TYPE_BPS_1 ( 0x0b <<Tw) 
#define TYPE_BPS_2 ( 0x2b <<Tw) 
#define TYPE_BPS_3 ( 0x4b <<Tw) 
#define TYPE_BPS_4 ( 0x6b <<Tw) 
#define TYPE_VEC16_1 ( 0x0f <<Tw) 
#define TYPE_VEC16_2 ( 0x4f <<Tw) 
#if 0
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#endif
#define TYPE_FOREIGN ( 0x33 <<Tw) 
#define TYPE_SP ( 0x37 <<Tw) 
#define TYPE_ENCAPSULATE ( 0x3b <<Tw) 
#define TYPE_PADDER ( 0x7b <<Tw) 
inline bool vector_holds_binary(Header h)
{ return ((h) & (0x2<<Tw)) != 0;
}
#define TYPE_SIMPLE_VEC ( 0x01 <<Tw) 
#define TYPE_INDEXVEC ( 0x11 <<Tw) 
#define TYPE_HASH ( 0x15 <<Tw) 
#define TYPE_HASHX ( 0x19 <<Tw) 
#define TYPE_ARRAY ( 0x05 <<Tw) 
#define TYPE_STRUCTURE ( 0x09 <<Tw) 
#define TYPE_OBJECT ( 0x0d <<Tw) 
#define TYPE_VEC32 ( 0x13 <<Tw) 
#define TYPE_VEC64 ( 0x17 <<Tw) 
#define TYPE_VEC128 ( 0x1b <<Tw) 
#define TYPE_VECFLOAT32 ( 0x53 <<Tw) 
#define TYPE_VECFLOAT64 ( 0x57 <<Tw) 
#define TYPE_VECFLOAT128 ( 0x5b <<Tw) 
#define is_mixed_header(h) (((h) & (0x73<<Tw)) == TYPE_MIXED1)
#define TYPE_MIXED1 ( 0x41 <<Tw) 
#define TYPE_MIXED2 ( 0x45 <<Tw) 
#define TYPE_MIXED3 ( 0x49 <<Tw) 
#define TYPE_STREAM ( 0x4d <<Tw) 
#define VIRTUAL_TYPE_CONS ( 0x7d <<Tw) 
#define VIRTUAL_TYPE_REF ( 0x17d <<Tw)
#define VIRTUAL_TYPE_NIL ( 0x27d <<Tw)
#define HDR_IMMED_MASK (( 0xf <<Tw) | TAG_BITS)
#define TAG_CHAR (( 0x4 <<Tw) | TAG_HDR_IMMED) 
#define TAG_SPID (( 0xc <<Tw) | TAG_HDR_IMMED) 
#define SPID_NIL (TAG_SPID+(0x00<<(Tw+4))) 
#define SPID_FBIND (TAG_SPID+(0x01<<(Tw+4))) 
#define SPID_CATCH (TAG_SPID+(0x02<<(Tw+4))) 
#define SPID_PROTECT (TAG_SPID+(0x03<<(Tw+4))) 
#define SPID_HASHEMPTY (TAG_SPID+(0x04<<(Tw+4))) 
#define SPID_HASHTOMB (TAG_SPID+(0x05<<(Tw+4))) 
#define SPID_GCMARK (TAG_SPID+(0x06<<(Tw+4))) 
#define SPID_NOINPUT (TAG_SPID+(0x07<<(Tw+4))) 
#define SPID_ERROR (TAG_SPID+(0x08<<(Tw+4))) 
#define SPID_PVBIND (TAG_SPID+(0x09<<(Tw+4))) 
#define SPID_NOARG (TAG_SPID+(0x0a<<(Tw+4))) 
#define SPID_NOPROP (TAG_SPID+(0x0b<<(Tw+4))) 
#define SPID_LIBRARY (TAG_SPID+(0x0c<<(Tw+4))) 
inline Header vechdr(LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)v - TAG_VECTOR))->load(mo);
}
inline void setvechdr(LispObject v, Header h, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)v - TAG_VECTOR))->store(h, mo);
}
inline unsigned int type_of_header(Header h)
{ return ((unsigned int)h) & header_mask;
}
inline std::size_t length_of_header(Header h)
{ return (((std::size_t)h) >> (Tw+7)) << 2;
}
inline std::size_t length_of_bitheader(Header h)
{ return (((std::size_t)h) >> (Tw+2)) - 31;
}
inline std::size_t length_of_byteheader(Header h)
{ return (((std::size_t)h) >> (Tw+5)) - 3;
}
inline std::size_t length_of_hwordheader(Header h)
{ return (((std::size_t)h) >> (Tw+6)) - 1;
}
inline Header bitvechdr_(std::size_t n)
{ return TYPE_BITVEC_1 + (((n+31)&31)<<(Tw+2));
}
#define TYPE_SYMBOL 0x00000000 
#define SYM_SPECIAL_VAR 0x00000080 
#define SYM_FLUID_VAR 0x00000080 
#define SYM_GLOBAL_VAR 0x00000100 
#define SYM_KEYWORD_VAR 0x00000180 
#define SYM_SPECIAL_FORM 0x00000200 
#define SYM_MACRO 0x00000400 
#define SYM_C_DEF 0x00000800 
#define SYM_CODEPTR 0x00001000 
#define SYM_ANY_GENSYM 0x00002000 
#define SYM_TRACED 0x00004000 
#define SYM_TRACESET 0x00008000 
#define SYM_TAGGED 0x00010000 
#define SYM_FASTGET_MASK 0x007e0000 
#define SYM_FASTGET_SHIFT 17
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00800000 
#define SYM_IN_PACKAGE 0xff000000U 
#define SYM_IN_PKG_SHIFT 24
#define SYM_IN_PKG_COUNT 8
#else 
#define SYM_UNPRINTED_GENSYM 0x00800000 
#endif 
#define symhdr_length (doubleword_align_up(sizeof(Symbol_Head)))
inline bool is_symbol_header(Header h)
{ return ((int)h & (0xf<<Tw)) == TYPE_SYMBOL;
}
inline bool is_symbol_header_full_test(Header h)
{ return ((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED);
}
inline int header_fastget(Header h)
{ return (h >> SYM_FASTGET_SHIFT) & 0x3f;
}
inline bool is_number_header_full_test(Header h)
{ return ((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED);
}
inline bool is_vector_header_full_test(Header h)
{ return is_odds(h) && (((int)h & (0x3<<Tw)) != 0);
}
inline bool is_array_header(Header h)
{ return type_of_header(h) == TYPE_ARRAY;
}
inline bool is_basic_vector(LispObject v)
{ return type_of_header(vechdr(v)) != TYPE_INDEXVEC;
}
inline bool vector_i8(Header h)
{ return ((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i16(Header h)
{ return ((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i32(Header h)
{ return ((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i64(Header h)
{ return ((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i128(Header h)
{ return ((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_f32(Header h)
{ return ((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_f64(Header h)
{ return ((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_f128(Header h)
{ return ((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline std::atomic<LispObject>& basic_elt(LispObject v, std::size_t n)
{ return *(std::atomic<LispObject> *)((char *)v +
 (CELL-TAG_VECTOR) +
 (n*sizeof(LispObject)));
}
inline bool vector_i8(LispObject n)
{ if (is_basic_vector(n)) return vector_i8(vechdr(n));
 else return vector_i8(vechdr(basic_elt(n, 0)));
}
inline bool vector_i16(LispObject n)
{ if (is_basic_vector(n)) return vector_i16(vechdr(n));
 else return vector_i16(vechdr(basic_elt(n, 0)));
}
inline bool vector_i32(LispObject n)
{ if (is_basic_vector(n)) return vector_i32(vechdr(n));
 else return vector_i32(vechdr(basic_elt(n, 0)));
}
inline bool vector_i64(LispObject n)
{ if (is_basic_vector(n)) return vector_i64(vechdr(n));
 else return vector_i64(vechdr(basic_elt(n, 0)));
}
inline bool vector_i128(LispObject n)
{ if (is_basic_vector(n)) return vector_i128(vechdr(n));
 else return vector_i128(vechdr(basic_elt(n, 0)));
}
inline bool vector_f32(LispObject n)
{ if (is_basic_vector(n)) return vector_f32(vechdr(n));
 else return vector_f32(vechdr(basic_elt(n, 0)));
}
inline bool vector_f64(LispObject n)
{ if (is_basic_vector(n)) return vector_f64(vechdr(n));
 else return vector_f64(vechdr(basic_elt(n, 0)));
}
inline bool vector_f128(LispObject n)
{ if (is_basic_vector(n)) return vector_f128(vechdr(n));
 else return vector_f128(vechdr(basic_elt(n, 0)));
}
#define TYPE_BIGNUMINDEX ( 0x1d <<Tw)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_COMPLEX_NUM ( 0x5d <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_NEW_BIGNUM ( 0x7d <<Tw) 
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
inline Header numhdr(LispObject v, std::memory_order mo = std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)(v) - TAG_NUMBERS))->load(mo);
}
inline Header flthdr(LispObject v, std::memory_order mo = std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)(v) - TAG_BOXFLOAT))->load(mo);
}
inline void setnumhdr(LispObject v, Header h, std::memory_order mo = std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)(v) - TAG_NUMBERS))->store(h, mo);
}
inline void setflthdr(LispObject v, Header h, std::memory_order mo = std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)(v) - TAG_BOXFLOAT))->store(h, mo);
}
inline bool is_short_float(LispObject v)
{ if (!is_sfloat(v)) return false;
 if (SIXTY_FOUR_BIT && (v & XTAG_FLOAT32) != 0) return false;
 return true;
}
inline bool is_single_float(LispObject v)
{ if (SIXTY_FOUR_BIT && is_sfloat(v) && (v & XTAG_FLOAT32) != 0) return true;
 return is_bfloat(v) && type_of_header(flthdr(v)) == TYPE_SINGLE_FLOAT;
}
inline bool is_double_float(LispObject v)
{ return is_bfloat(v) && type_of_header(flthdr(v)) == TYPE_DOUBLE_FLOAT;
}
inline bool is_long_float(LispObject v)
{ return is_bfloat(v) && type_of_header(flthdr(v)) == TYPE_LONG_FLOAT;
}
inline bool is_ratio(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_RATNUM;
}
inline bool is_complex(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM;
}
inline bool is_bignum_header(Header h)
{ return type_of_header(h) == TYPE_BIGNUM;
}
inline bool is_bignum(LispObject n)
{ return is_bignum_header(numhdr(n));
 
}
inline bool is_new_bignum_header(Header h)
{ return type_of_header(h) == TYPE_NEW_BIGNUM;
}
inline bool is_new_bignum(LispObject n)
{ return is_new_bignum_header(numhdr(n));
 
}
inline bool is_string_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1;
}
inline bool is_string(LispObject n)
{ if (is_basic_vector(n)) return is_string_header(vechdr(n));
 else return is_string_header(vechdr(basic_elt(n, 0)));
}
inline bool is_vec8_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1;
}
inline bool is_vec8(LispObject n)
{ if (is_basic_vector(n)) return is_vec8_header(vechdr(n));
 else return is_vec8_header(vechdr(basic_elt(n, 0)));
}
inline bool is_bps_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1;
}
inline bool is_bps(LispObject n)
{ return is_bps_header(vechdr(n));
}
inline bool is_vec16_header(Header h)
{ return (type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1;
}
inline bool is_vec16(LispObject n)
{ if (is_basic_vector(n)) return is_vec16_header(vechdr(n));
 else return is_vec16_header(vechdr(basic_elt(n, 0)));
}
inline bool is_bitvec_header(Header h)
{ return (type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1;
}
inline bool is_bitvec(LispObject n)
{ if (is_basic_vector(n)) return is_bitvec_header(vechdr(n));
 else return is_bitvec_header(vechdr(basic_elt(n, 0)));
}
inline char& basic_celt(LispObject v, std::size_t n)
{ return *((char *)(v) + (CELL-TAG_VECTOR) + n);
}
inline unsigned char& basic_ucelt(LispObject v, std::size_t n)
{ return *((unsigned char *)v + (CELL-TAG_VECTOR) + n);
}
inline signed char& basic_scelt(LispObject v, std::size_t n)
{ return *((signed char *)v + (CELL-TAG_VECTOR) + n);
}
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
inline unsigned char* data_of_bps(LispObject v)
{ return (unsigned char *)v + BPS_DATA_OFFSET;
}
inline LispObject& vselt(LispObject v, std::size_t n)
{ return *(LispObject *)(((std::intptr_t)v & ~((std::intptr_t)TAG_BITS)) +
 ((1 + n)*sizeof(LispObject)));
}
inline std::int16_t& basic_helt(LispObject v, std::size_t n)
{ return *(std::int16_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(std::int16_t));
}
inline std::intptr_t& basic_ielt(LispObject v, std::size_t n)
{ return *(std::intptr_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(std::intptr_t));
}
inline std::int32_t& basic_ielt32(LispObject v, std::size_t n)
{ return *(std::int32_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(std::int32_t));
}
inline float& basic_felt(LispObject v, std::size_t n)
{ return *(float *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(float));
}
inline double& basic_delt(LispObject v, std::size_t n)
{ return *(double *)((char *)v +
 (8-TAG_VECTOR) +
 n*sizeof(double));
}
#define LOG2_VECTOR_CHUNK_BYTES (PAGE_BITS-2)
#define VECTOR_CHUNK_BYTES ((size_t)(((size_t)1)<<LOG2_VECTOR_CHUNK_BYTES))
inline bool is_power_of_two(std::uint64_t n)
{ return (n == (n & (-n)));
}
inline int intlog2(std::uint64_t n)
{
 static const unsigned char intlog2_table[] =
 {
 0, 0, 1, 39, 2, 15, 40, 23,
 3, 12, 16, 59, 41, 19, 24, 54,
 4,0, 13, 10, 17, 62, 60, 28,
 42, 30, 20, 51, 25, 44, 55, 47,
 5,32, 0, 38, 14, 22, 11, 58,
 18, 53, 63, 9, 61, 27, 29, 50,
 43, 46, 31, 37, 21, 57, 52, 8,
 26, 49, 45, 36, 56, 7, 48, 35,
 6,34, 33
 };
 return intlog2_table[n % (sizeof(intlog2_table)/sizeof(intlog2_table[0]))];
}
inline int type_of_vector(LispObject v)
{ if (is_basic_vector(v)) return type_of_header(vechdr(v));
 else return type_of_header(vechdr(basic_elt(v, 0)));
}
inline std::size_t bytes_in_bytevector(LispObject v)
{ if (is_basic_vector(v)) return length_of_byteheader(vechdr(v)) - CELL;
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_byteheader(vechdr(basic_elt(v, n-1))) - CELL;
}
inline std::size_t hwords_in_hwordvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_hwordheader(vechdr(v)) - (CELL/2);
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (VECTOR_CHUNK_BYTES/2)*(n-1) +
 length_of_hwordheader(vechdr(basic_elt(v, n-1))) - (CELL/2);
}
inline std::size_t bits_in_bitvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_bitheader(vechdr(v)) - 8*CELL;
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (8*VECTOR_CHUNK_BYTES)*(n-1) +
 length_of_bitheader(vechdr(basic_elt(v, n-1))) - 8*CELL;
}
inline std::size_t bytes_in_vector(LispObject v)
{ if (is_basic_vector(v)) return length_of_header(vechdr(v)) - CELL;
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_header(vechdr(basic_elt(v, n-1))) - CELL;
}
inline std::size_t cells_in_vector(LispObject v)
{ return bytes_in_vector(v)/CELL;
}
inline bool vector_holds_binary(LispObject v)
{ if (is_basic_vector(v)) return vector_holds_binary(vechdr(v));
 else return vector_holds_binary(vechdr(basic_elt(v, 0)));
}
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1];
inline void discard_basic_vector(LispObject v)
{ std::size_t size = length_of_header(vechdr(v));
 std::size_t n = size/CELL - 1;
 if (is_power_of_two(n)) 
 { int i = intlog2(n); 
 if (i <= LOG2_VECTOR_CHUNK_BYTES)
 { basic_elt(v, 0) = free_vectors[i];
 setvechdr(v,TYPE_SIMPLE_VEC +
 (size << (Tw+5)) +
 TAG_HDR_IMMED);
 v = (v & ~(std::uintptr_t)TAG_BITS) | TAG_VECTOR;
 free_vectors[i] = v;
 }
 }
}
inline void discard_vector(LispObject v)
{ if (is_basic_vector(v)) discard_basic_vector(v);
 else
 { std::size_t n1 = length_of_header(vechdr(v))/CELL - 1;
 for (std::size_t i=0; i<n1; i++)
 discard_basic_vector(basic_elt(v, i));
 discard_basic_vector(v);
 }
}
inline std::atomic<LispObject>& elt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_elt(v, n);
 return basic_elt(basic_elt(v, n/(VECTOR_CHUNK_BYTES/CELL)),
 n%(VECTOR_CHUNK_BYTES/CELL));
}
inline char& celt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_celt(v, n);
 return basic_celt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline unsigned char& ucelt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_ucelt(v, n);
 return basic_ucelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline signed char& scelt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_scelt(v, n);
 return basic_scelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline std::int16_t& helt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_helt(v, n);
 return basic_helt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(std::int16_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(std::int16_t)));
}
inline std::intptr_t& ielt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_ielt(v, n);
 return basic_ielt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(std::intptr_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(std::intptr_t)));
}
inline std::int32_t& ielt32(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_ielt32(v, n);
 return basic_ielt32(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(std::int32_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(std::int32_t)));
}
inline float& felt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_felt(v, n);
 return basic_felt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(float))),
 n%(VECTOR_CHUNK_BYTES/sizeof(float)));
}
inline double& delt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_delt(v, n);
 return basic_delt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(double))),
 n%(VECTOR_CHUNK_BYTES/sizeof(double)));
}
inline bool is_header(LispObject x)
{ return ((int)x & (0x3<<Tw)) != 0; 
}
inline bool is_char(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_CHAR;
}
inline bool is_spid(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_SPID;
}
inline bool is_library(LispObject x)
{ return ((int)x & 0xfffff) == SPID_LIBRARY;
}
inline unsigned int library_number(LispObject x)
{ return (x >> 20) & 0xfff;
}
inline int font_of_char(LispObject n)
{ return ((std::int32_t)n >> (21+4+Tw)) & 0xf;
}
inline int bits_of_char(LispObject n)
{ return 0;
}
inline unsigned int code_of_char(LispObject n)
{ return ((std::uint32_t)(n) >> (4+Tw)) & 0x001fffff;
}
inline LispObject pack_char(int font, unsigned int code)
{ return (LispObject)((((std::uint32_t)(font)) << (21+4+Tw)) |
 (((std::uint32_t)(code)) << (4+Tw)) | TAG_CHAR);
}
#define CHAR_EOF pack_char(0, 0x0010ffff)
typedef std::int32_t junk; 
typedef std::intptr_t junkxx; 
typedef struct Symbol_Head_
{
 Header header; 
 LispObject value; 
 LispObject env; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject package; 
 LispObject pname; 
 std::intptr_t function0; 
 std::intptr_t function1; 
 std::intptr_t function2; 
 std::intptr_t function3; 
 std::intptr_t function4up;
 std::uint64_t count; 
} Symbol_Head;
#ifdef FUTURE_IDEA
typedef struct Symbol_Head_
{ Header header; 
 LispObject value; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject pname; 
 LispObject package; 
 LispObject function; 
 std::uintptr_t count; 
} Symbol_Head;
typedef struct Function_Object_
{ Header header; 
 LispObject env; 
 std::intptr_t function0; 
 std::intptr_t function1; 
 std::intptr_t function2; 
 std::intptr_t function3; 
 std::intptr_t function4up;
 std::uintptr_t count; 
} Function_Object;
typedef struct Bytecoded_Function_Object_
{ Header header; 
 LispObject env; 
 std::intptr_t function0; 
 std::intptr_t function1; 
 std::intptr_t function2; 
 std::intptr_t function3; 
 std::intptr_t function4up;
 std::uintptr_t count; 
 unsigned char bytecodes[]; 
} Bytecoded_Function_Object;
#endif 
#define MAX_FASTGET_SIZE 63
inline Header qheader(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)p + (0*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qvalue(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (1*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qenv(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (2*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qplist(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (3*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qfastgets(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (4*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qpackage(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (5*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qpname(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (6*CELL-TAG_SYMBOL)))->load(mo);
}
inline std::atomic<LispObject> *valueaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (1*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *envaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (2*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *plistaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (3*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *fastgetsaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (4*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *packageaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (5*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *pnameaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (6*CELL-TAG_SYMBOL));
}
inline void setheader(LispObject p, Header h, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)p + (0*CELL-TAG_SYMBOL)))->store(h, mo);
}
inline void setvalue(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (1*CELL-TAG_SYMBOL)))->store(q, mo); 
}
inline void setenv(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (2*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setplist(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (3*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setfastgets(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (4*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setpackage(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (5*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setpname(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (6*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline std::intptr_t& ifn0(LispObject p)
{ return *(std::intptr_t *)((char *)p + (7*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn1(LispObject p)
{ return *(std::intptr_t *)((char *)p + (8*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn2(LispObject p)
{ return *(std::intptr_t *)((char *)p + (9*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn3(LispObject p)
{ return *(std::intptr_t *)((char *)p + (10*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn4up(LispObject p)
{ return *(std::intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifnunused(LispObject p)
{ return *(std::intptr_t *)((char *)p + (12*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifnn(LispObject p)
{ return *(std::intptr_t *)((char *)p + (13*CELL-TAG_SYMBOL));
}
inline no_args*& qfn0(LispObject p)
{ return *((no_args **)((char *)p + (7*CELL-TAG_SYMBOL)));
}
inline one_arg*& qfn1(LispObject p)
{ return *(one_arg **)((char *)p + (8*CELL-TAG_SYMBOL));
}
inline two_args*& qfn2(LispObject p)
{ return *(two_args **)((char *)p + (9*CELL-TAG_SYMBOL));
}
inline three_args*& qfn3(LispObject p)
{ return *(three_args **)((char *)p + (10*CELL-TAG_SYMBOL));
}
inline fourup_args*& qfn4up(LispObject p)
{ return *(fourup_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}
[[noreturn]] extern void aerror1(const char *s, LispObject a);
inline LispObject arg4(const char *name, LispObject a4up)
{ if (cdr(a4up) != nil) aerror1(name, a4up); 
 return car(a4up);
}
inline void a4a5(const char *name, LispObject a4up,
 LispObject& a4, LispObject& a5)
{ a4 = car(a4up);
 a4up = cdr(a4up);
 if (a4up==nil || cdr(a4up) != nil) aerror1(name, a4up); 
 a5 = car(a4up);
}
inline void a4a5a6(const char *name, LispObject a4up,
 LispObject& a4, LispObject& a5, LispObject& a6)
{ a4 = car(a4up);
 a4up = cdr(a4up);
 if (a4up == nil) aerror1(name, a4up); 
 a5 = car(a4up);
 a4up = cdr(a4up);
 if (a4up==nil || cdr(a4up) != nil) aerror1(name, a4up); 
 a6 = car(a4up);
}
inline std::atomic<std::uint64_t>& qcount(LispObject p)
{ return *(std::atomic<std::uint64_t> *)((char *)p + (12*CELL-TAG_SYMBOL));
}
#ifndef HAVE_SOFTFLOAT
typedef struct _float32_t
{ std::uint32_t v;
} float32_t;
typedef struct _float64_t
{ std::uint64_t v;
} float64_t;
#endif
typedef union _Float_union
{ float f;
 std::uint32_t i;
 float32_t f32;
} Float_union;
inline LispObject low32(LispObject a)
{ return (LispObject)(std::uint32_t)a;
}
typedef struct Big_Number_
{
 Header h;
 std::uint32_t d[1]; 
} Big_Number;
inline std::size_t bignum_length(LispObject b)
{ return length_of_header(numhdr(b));
}
inline std::uint32_t* bignum_digits(LispObject b)
{ return (std::uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
inline std::uint32_t* vbignum_digits(LispObject b)
{ return (std::uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
inline std::int64_t bignum_digits64(LispObject b, std::size_t n)
{ return (std::int64_t)((std::int32_t *)((char *)b+(CELL-TAG_NUMBERS)))[n];
}
inline Header make_bighdr(std::size_t n)
{ return TAG_HDR_IMMED+TYPE_BIGNUM+(n<<(Tw+7));
}
inline Header make_new_bighdr(std::size_t n)
{ return TAG_HDR_IMMED+TYPE_NEW_BIGNUM+(n<<(Tw+8));
}
inline std::uint64_t* new_bignum_digits(LispObject b)
{ return (std::uint64_t *)((char *)b + (8-TAG_NUMBERS));
}
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
typedef struct Rational_Number_
{ std::atomic<Header> header;
 std::atomic<LispObject> num;
 std::atomic<LispObject> den;
} Rational_Number;
inline LispObject numerator(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->num.load(mo);
}
inline LispObject denominator(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->den.load(mo);
}
inline void setnumerator(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ ((Rational_Number *)((char *)r-TAG_NUMBERS))->num.store(v, mo);
}
inline void setdenominator(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->den.store(v, mo);
}
typedef struct Complex_Number_
{ std::atomic<Header> header;
 std::atomic<LispObject> real;
 std::atomic<LispObject> imag;
} Complex_Number;
inline LispObject real_part(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->real.load(mo);
}
inline LispObject imag_part(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->imag.load(mo);
}
inline void setreal_part(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->real.store(v, mo);
}
inline void setimag_part(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->imag.store(v, mo);
}
typedef struct Single_Float_
{ std::atomic<Header> header;
 union float_or_int
 { float f;
 float32_t f32;
 std::int32_t i;
 } f;
} Single_Float;
inline float& single_float_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f;
}
inline float32_t& float32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f32;
}
inline std::int32_t& intfloat32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.i;
}
typedef union _Double_union
{ double f;
 std::uint32_t i[2];
 std::uint64_t i64;
 float64_t f64;
} Double_union;
#define SIZEOF_DOUBLE_FLOAT 16
inline double *double_float_addr(LispObject v)
{ return (double *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& double_float_pad(LispObject v)
{ return *(std::int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
inline double& double_float_val(LispObject v)
{ return *(double *)((char *)v + (8-TAG_BOXFLOAT));
}
inline float64_t& float64_t_val(LispObject v)
{ return *(float64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int64_t& intfloat64_t_val(LispObject v)
{ return *(std::int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat64_t_val_hi(LispObject v)
{ return *(std::int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat64_t_val_lo(LispObject v)
{ return *(std::int32_t *)((char *)v + (12-TAG_BOXFLOAT));
}
#ifdef HAVE_SOFTFLOAT
#define SIZEOF_LONG_FLOAT 24
inline float128_t *long_float_addr(LispObject v)
{ return (float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& long_float_pad(LispObject v)
{ return *(std::int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
inline float128_t& long_float_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline float128_t& float128_t_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int64_t& intfloat128_t_val0(LispObject v)
{ return *(std::int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int64_t& intfloat128_t_val1(LispObject v)
{ return *(std::int64_t *)((char *)v + (16-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_0(LispObject v)
{ return *(std::int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_1(LispObject v)
{ return *(std::int32_t *)((char *)v + (12-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_2(LispObject v)
{ return *(std::int32_t *)((char *)v + (16-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_3(LispObject v)
{ return *(std::int32_t *)((char *)v + (20-TAG_BOXFLOAT));
}
#endif 
inline std::uintptr_t word_align_up(std::uintptr_t n)
{ return (LispObject)((n + 3) & (-(std::uintptr_t)4U));
}
inline std::uintptr_t doubleword_align_up(std::uintptr_t n)
{ return (std::uintptr_t)((n + 7) & (-(std::uintptr_t)8U));
}
inline LispObject doubleword_align_up(LispObject n)
{ return (LispObject)(((std::uintptr_t)n + 7) & (-(std::uintptr_t)8U));
}
inline std::uintptr_t doubleword_align_down(std::uintptr_t n)
{ return (std::uintptr_t)((std::intptr_t)n & (-(std::uintptr_t)8U));
}
inline std::uintptr_t object_align_up(std::uintptr_t n)
{ return (std::uintptr_t)((n + sizeof(LispObject) - 1) &
 (-(std::uintptr_t)sizeof(LispObject)));
}
inline std::uintptr_t object_2_align_up(std::uintptr_t n)
{ return (std::uintptr_t)((n + 2*sizeof(LispObject) - 1) &
 (-(std::uintptr_t)2*sizeof(LispObject)));
}
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_SIGNAL 0x6 
#define UNWIND_SIGINT 0x7 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#define HASH_AS_EQ 0
#define HASH_AS_EQL 1
#define HASH_AS_CL_EQUAL 2
#define HASH_AS_EQUAL 3
#define HASH_AS_EQUALP 4
#define HASH_AS_SYMBOL 5
#define HASH_AS_SXHASH 6
#endif 
#ifndef header_thread_local_h
#define header_thread_local_h 1
#if defined __cpp_inline_variables && \
 (defined __CYGWIN__ || defined __MINGW32__)
extern "C"
{
#ifdef __LP64__
typedef unsigned int tls_handle;
#else
typedef unsigned long tls_handle;
#endif
extern __declspec(dllimport) tls_handle TlsAlloc(void);
extern __declspec(dllimport) int TlsFree(tls_handle);
extern __declspec(dllimport) void *TlsGetValue(tls_handle);
extern __declspec(dllimport) int TlsSetValue(tls_handle, void *);
};
#ifdef CAUTIOUS
inline void *tls_load(tls_handle teb_slot)
{ return TlsGetValue(teb_slot);
}
inline void tls_store(tls_handle teb_slot, void *v)
{ TlsSetValue(teb_slot, v);
}
#else 
#if __SIZEOF_POINTER__ == 4
#define MOVE_INSTRUCTION "movl"
#define SEGMENT_REGISTER "%%fs"
#define basic_TLS_offset 0xe10
#define extended_TLS_offset 0xf94
#else 
#define MOVE_INSTRUCTION "movq"
#define SEGMENT_REGISTER "%%gs"
#define basic_TLS_offset 0x1480
#define extended_TLS_offset 0x1780
#endif 
inline void *read_via_segment_register(tls_handle n)
{ void *r;
 asm volatile
 ( MOVE_INSTRUCTION "  " SEGMENT_REGISTER ":(%1), %0"
 : "=r" (r)
 : "r" (n)
 :
 );
 return r;
}
inline void write_via_segment_register(tls_handle n, void *v)
{ asm volatile
 ( MOVE_INSTRUCTION " %0, " SEGMENT_REGISTER ":(%1)"
 :
 : "r" (v), "r" (n)
 :
 );
}
inline void *extended_tls_load(tls_handle teb_slot)
{ void **a = (void **)read_via_segment_register(extended_TLS_offset);
 return a[teb_slot - 64];
}
inline void extended_tls_store(tls_handle teb_slot, void *v)
{ void **a = (void **)read_via_segment_register(extended_TLS_offset);
 a[teb_slot - 64] = v;
}
inline void *tls_load(tls_handle teb_slot)
{ if (teb_slot >= 64) return extended_tls_load(teb_slot);
 else return (void *)read_via_segment_register(
 basic_TLS_offset + sizeof(void *)*teb_slot);
}
inline void tls_store(tls_handle teb_slot, void *v)
{ if (teb_slot >= 64) return extended_tls_store(teb_slot, v);
 else write_via_segment_register(
 basic_TLS_offset + sizeof(void *)*teb_slot, v);
}
#endif 
class TlsHandle
{
public:
 tls_handle h;
 TlsHandle()
 { h = TlsAlloc();
 }
 ~TlsHandle()
 { TlsFree(h);
 }
};
#ifdef DEBUG
#define declare_thread_local(name, Type) \
class name \
{ \
 static inline TlsHandle H; \
 static inline thread_local Type val; \
public: \
 static Type get() \
 { return (Type)tls_load(H.h); \
 } \
 static void set(Type v) \
 { tls_store(H.h, (void *)v); \
 val = v; \
 } \
};
#else 
#define declare_thread_local(name, Type) \
class name \
{ \
 static inline TlsHandle H; \
public: \
 static Type get() \
 { return (Type)tls_load(H.h); \
 } \
 static void set(Type v) \
 { tls_store(H.h, (void *)v); \
 } \
};
#endif 
#define declare_thread_local_ref(name, Type) \
class name ## _Ref \
{ \
 static Type* get() \
 { static thread_local Type val; \
 return &val; \
 } \
public: \
 static inline TlsHandle H; \
 name ## _Ref() \
 { tls_store(H.h, (void *)get()); \
 } \
}; \
class name \
{ \
public: \
 static Type &get() \
 { static thread_local name ## _Ref val; \
 return *(Type *)tls_load(val.H.h); \
 } \
};
#elif defined __cpp_inline_variables
#define declare_thread_local(name, Type) \
class name \
{ \
 static inline thread_local Type val; \
public: \
 static Type& get() \
 { return val; \
 } \
 static void set(Type v) \
 { val = v; \
 } \
};
#define declare_thread_local_ref(name, Type) \
class name \
{ \
 static inline thread_local Type val; \
public: \
 static Type& get() \
 { return val; \
 } \
};
#else 
#define declare_thread_local(name, Type) \
class name \
{ \
 static Type& val() \
 { static thread_local Type Val; \
 return Val; \
 } \
public: \
 static Type& get() \
 { return val(); \
 } \
 static void set(Type v) \
 { val() = v; \
 } \
};
#define declare_thread_local_ref(name, Type) \
class name \
{ \
public: \
 static Type& get() \
 { static thread_local Type val; \
 return val; \
 } \
};
#endif 
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern void interrupted(bool noisy);
[[noreturn]] extern void error(int nargs, int code, ...);
[[noreturn]] extern void cerror(int nargs, int code1, int code2, ...);
[[noreturn]] extern void got_0_wanted_1(LispObject env);
[[noreturn]] extern void got_0_wanted_2(LispObject env);
[[noreturn]] extern void got_0_wanted_3(LispObject env);
[[noreturn]] extern void got_0_wanted_4up(LispObject env);
[[noreturn]] extern void got_0_wanted_other(LispObject env);
[[noreturn]] extern void got_1_wanted_0(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_2(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_3(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_4up(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_other(LispObject env, LispObject a1);
[[noreturn]] extern void got_2_wanted_0(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_1(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_3(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_4up(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_other(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_3_wanted_0(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_1(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_2(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_4up(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_other(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_4up_wanted_0(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_1(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_2(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_3(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_other(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void bad_specialfn_0(LispObject env);
[[noreturn]] extern void bad_specialfn_2(LispObject env, LispObject, LispObject);
[[noreturn]] extern void bad_specialfn_3(LispObject env, LispObject, LispObject, LispObject);
[[noreturn]] extern void bad_specialfn_4up(LispObject env, LispObject, LispObject, LispObject, LispObject);
#define G0W1 ((no_args *)got_0_wanted_1)
#define G0W2 ((no_args *)got_0_wanted_2)
#define G0W3 ((no_args *)got_0_wanted_3)
#define G0W4up ((no_args *)got_0_wanted_4up)
#define G0Wother ((no_args *)got_0_wanted_other)
#define G1W0 ((one_arg *)got_1_wanted_0)
#define G1W2 ((one_arg *)got_1_wanted_2)
#define G1W3 ((one_arg *)got_1_wanted_3)
#define G1W4up ((one_arg *)got_1_wanted_4up)
#define G1Wother ((one_arg *)got_1_wanted_other)
#define G2W0 ((two_args *)got_2_wanted_0)
#define G2W1 ((two_args *)got_2_wanted_1)
#define G2W3 ((two_args *)got_2_wanted_3)
#define G2W4up ((two_args *)got_2_wanted_4up)
#define G2Wother ((two_args *)got_2_wanted_other)
#define G3W0 ((three_args *)got_3_wanted_0)
#define G3W1 ((three_args *)got_3_wanted_1)
#define G3W2 ((three_args *)got_3_wanted_2)
#define G3W4up ((three_args *)got_3_wanted_4up)
#define G3Wother ((three_args *)got_3_wanted_other)
#define G4W0 ((fourup_args *)got_4up_wanted_0)
#define G4W1 ((fourup_args *)got_4up_wanted_1)
#define G4W2 ((fourup_args *)got_4up_wanted_2)
#define G4W3 ((fourup_args *)got_4up_wanted_3)
#define G4Wother ((fourup_args *)got_4up_wanted_other)
#define BAD_SPECIAL_0 ((no_args *)bad_specialfn_0)
#define BAD_SPECIAL_2 ((two_args *)bad_specialfn_2)
#define BAD_SPECIAL_3 ((three_args *)bad_specialfn_3)
#define BAD_SPECIAL_4up ((fourup_args *)bad_specialfn_4up)
[[noreturn]] extern void aerror(const char *s); 
[[noreturn]] extern void aerror0(const char *s);
[[noreturn]] extern void aerror1(const char *s, LispObject a);
[[noreturn]] extern void aerror2(const char *s, LispObject a, LispObject b);
[[noreturn]] extern void aerror2(const char *s, const char *a, LispObject b);
[[noreturn]] extern void aerror3(const char *s, LispObject a, LispObject b, LispObject c);
[[noreturn]] extern void fatal_error(int code, ...);
extern LispObject carerror(LispObject a);
extern LispObject cdrerror(LispObject a);
[[noreturn]] extern void car_fails(LispObject a);
[[noreturn]] extern void cdr_fails(LispObject a);
[[noreturn]] extern void rplaca_fails(LispObject a);
[[noreturn]] extern void rplacd_fails(LispObject a);
#define GC_MESSAGES 0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS 0x04
#define GC_MSG_BITS 0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG 0x10
#define ARGS_FLAG 0x20
#define BACKTRACE_MSG_BITS 0x38
#define err_bad_car 0 
#define err_bad_cdr 1 
#define err_no_store 2 
#define err_undefined_function_0 3 
#define err_undefined_function_1 4 
#define err_undefined_function_2 5 
#define err_undefined_function_3 6 
#define err_undefined_function_4up 7 
#define err_wrong_no_args 8 
#define err_unbound_lexical 9 
#define err_bad_rplac 10 
#define err_bad_arith 11 
#define err_redef_special 12 
#define err_bad_arg 13 
#define err_bad_declare 14 
#define err_bad_fn 15 
#define err_unset_var 16 
#define err_too_many_args0 17 
#define err_too_many_args1 18 
#define err_too_many_args2 19 
#define err_too_many_args3 20 
#define err_bad_apply 21 
#define err_macroex_hook 22 
#define err_block_tag 23 
#define err_go_tag 24 
#define err_excess_args 25
#define err_insufficient_args 26
#define err_bad_bvl 27 
#define err_bad_keyargs 28
#define err_write_err 29
#define err_bad_endp 30 
#define err_no_fasldir 31
#define err_no_fasl 32 
#define err_open_failed 33 
#define err_pipe_failed 34 
#define err_stack_overflow 35
#define err_top_bit 36
#define err_mem_spans_zero 37
#define err_no_longer_used 38 
#define err_no_tempdir 39
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (0 args)",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function (3 args)",
 "undefined function (4 or more args)",
 "wrong number of arguments",
 "unbound lexical variable",
 "bad rplaca/rplacd",
 "bad argument for an arithmetic function",
 "attempt to redefine a special form",
 "not a variable",
 "bad use of declare",
 "attempt to apply non-function",
 "unset variable",
 "too many arguments for 0-arg function",
 "too many arguments for 1-arg function",
 "too many arguments for 2-arg function",
 "too many arguments for 3-arg function",
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
#ifdef USE_MPI
#include "mpi.h"
extern std::int32_t mpi_rank,mpi_size;
#endif
extern void **pages, **heap_pages, **vheap_pages;
extern void **new_heap_pages, **new_vheap_pages;
extern void *allocate_page(const char *why);
extern std::size_t pages_count, heap_pages_count, vheap_pages_count;
extern std::size_t new_heap_pages_count, new_vheap_pages_count;
extern LispObject *list_bases[];
extern LispObject *nilsegment, *stacksegment;
extern LispObject *nilsegmentbase, *stacksegmentbase;
extern LispObject *stackBase;
extern std::int32_t stack_segsize; 
extern double max_store_size;
extern bool restartp;
#define IMAGE_FORMAT_VERSION '5'
#define DIRECTORY_SIZE 8 
typedef struct _directory_header
{ char C, S, L, version; 
 unsigned char dirext, 
 
 
 dirsize, 
 dirused, 
 updated; 
 char eof[4]; 
 
} directory_header;
typedef struct _directory_entry
{ char data[44];
} directory_entry;
#define D_newline data[0]
#define D_name data[1]
#define D_space data[12]
#define D_date data[13]
#define D_position data[37]
#define D_size data[41]
#define name_size 12
#define date_size 24
#define DIRNAME_LENGTH 256
#define NEWLINE_CHAR 0x0a
typedef struct directory
{ directory_header h;
 std::FILE *f;
 const char *full_filename; 
 char filename[DIRNAME_LENGTH];
 directory_entry d[1]; 
} directory;
#ifdef COMMON
# define MIDDLE_INITIAL 'C'
#else
# define MIDDLE_INITIAL 'S'
#endif
inline int get_dirused(directory &d)
{ return d.h.dirused + ((d.h.dirext & 0x0f)<<8);
}
inline int get_dirsize(directory &d)
{ return d.h.dirsize + ((d.h.dirext & 0xf0)<<4);
}
#define D_WRITE_OK 1
#define D_UPDATED 2
#define D_COMPACT 4
#define D_PENDING 8
class stringBool
{
public:
 std::string key;
 bool flag;
 stringBool(std::string k, bool f)
 { key = k;
 flag = f;
 }
};
class stringBoolString
{
public:
 std::string key;
 bool flag;
 std::string data;
 stringBoolString(std::string k, bool f, std::string d)
 { key = k;
 flag = f;
 data = d;
 }
};
class faslFileRecord
{
public:
 bool inUse;
 std::string name;
 directory *dir;
 bool isOutput;
 faslFileRecord(std::string n, bool o)
 { inUse = true;
 name = n;
 dir = NULL;
 isOutput = o;
 }
};
extern std::vector<stringBoolString> symbolsToDefine;
extern std::vector<stringBoolString> stringsToDefine;
extern std::vector<std::string> stringsToEvaluate;
extern std::vector<faslFileRecord> fasl_files; 
extern char *big_chunk_start, *big_chunk_end;
extern std::uintptr_t *C_stackbase, C_stacklimit;
extern LispObject multiplication_buffer;
#ifdef CONSERVATIVE
extern void write_barrier(std::atomic<LispObject> *p);
extern void write_barrier(LispObject *p);
#else 
inline void write_barrier(std::atomic<LispObject> *p)
{}
inline void write_barrier(LispObject *p)
{}
#endif 
extern std::mutex debug_lock;
extern const char *debug_file;
extern int debug_line;
extern void DebugTrace();
extern void DebugTrace(int i);
extern void DebugTrace(const char *msg);
extern void DebugTrace(const char *fmt, int i);
#define Tr(...) \
 { std::lock_guard<std::mutex> lk(debug_lock); \
 debug_file = __FILE__; \
 debug_line = __LINE__; \
 DebugTrace(__VA_ARGS__); \
 }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
inline void if_check_stack()
{ if (check_stack("@" __FILE__,__LINE__))
 { show_stack();
 aerror("stack overflow");
 }
}
#else
inline void if_check_stack()
{ const char *_p_ = (const char *)&_p_; \
 if ((std::uintptr_t)_p_ < C_stacklimit) aerror("stack overflow"); \
}
#endif
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
#define debug_record_string(s) debug_record((const char *)&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
 if (!(x)) { debug_show_trail("Assertion failed"); std::exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
#define first_nil_offset 50 
#define work_0_offset 250
#define last_nil_offset 301
#define NIL_SEGMENT_SIZE (((1 + last_nil_offset) & ~1) * \
 sizeof(LispObject) + 32)
#define SPARE 512
#ifdef CONSERVATIVE
extern std::uintptr_t heapstart;
extern std::uintptr_t len;
extern std::uintptr_t xor_chain;
extern std::uintptr_t vheapstart;
extern std::uintptr_t vlen;
extern std::uintptr_t vxor_chain;
extern LispObject *stackLimit;
#else 
extern LispObject *stackLimit;
#endif 
extern volatile std::atomic<std::uintptr_t> event_flag;
extern std::intptr_t nwork;
extern unsigned int exit_count;
extern std::uint64_t gensym_ser;
extern std::intptr_t print_precision, miscflags;
extern std::intptr_t current_modulus, fastget_size, package_bits;
extern std::intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject list_symbol, liststar_symbol, eq_symbol, eql_symbol;
extern LispObject cl_equal_symbol, equal_symbol, equalp_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table, progn_symbol, gcknt_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject big_divisor, big_dividend, big_quotient;
extern LispObject big_fake1, big_fake2, active_stream, current_module;
extern LispObject mv_call_symbol, features_symbol, lisp_package;
extern LispObject sys_hash_table, sxhash_hash_table;
extern LispObject help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject startup_symbol, mv_call_symbol, traceprint_symbol;
extern LispObject load_source_symbol, load_selected_source_symbol;
extern LispObject bytecoded_symbol, funcall_symbol, autoload_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, current_function, keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol, expand_def_symbol, allow_key_key;
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
extern LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol;
extern LispObject not_symbol, reader_workspace, named_character;
extern LispObject read_float_format, short_float, single_float, double_float;
extern LispObject long_float, bit_symbol, pathname_symbol, print_array_sym;
extern LispObject read_base, initial_element;
extern LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
extern LispObject builtin3_symbol, builtin4_symbol; 
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, int nargs, ...);
extern LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject env, LispObject ldev);
extern LispObject om_putEndApp(LispObject env, LispObject ldev);
extern LispObject om_putAtp(LispObject env, LispObject ldev);
extern LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern LispObject om_putAttr(LispObject env, LispObject ldev);
extern LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern LispObject om_putBind(LispObject env, LispObject ldev);
extern LispObject om_putEndBind(LispObject env, LispObject ldev);
extern LispObject om_putBVar(LispObject env, LispObject ldev);
extern LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern LispObject om_putError(LispObject env, LispObject ldev);
extern LispObject om_putEndError(LispObject env, LispObject ldev);
extern LispObject om_putObject(LispObject env, LispObject ldev);
extern LispObject om_putEndObject(LispObject env, LispObject ldev);
extern LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern LispObject om_getApp(LispObject env, LispObject ldev);
extern LispObject om_getEndApp(LispObject env, LispObject ldev);
extern LispObject om_getAtp(LispObject env, LispObject ldev);
extern LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern LispObject om_getAttr(LispObject env, LispObject ldev);
extern LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern LispObject om_getBind(LispObject env, LispObject ldev);
extern LispObject om_getEndBind(LispObject env, LispObject ldev);
extern LispObject om_getBVar(LispObject env, LispObject ldev);
extern LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern LispObject om_getError(LispObject env, LispObject ldev);
extern LispObject om_getEndError(LispObject env, LispObject ldev);
extern LispObject om_getObject(LispObject env, LispObject ldev);
extern LispObject om_getEndObject(LispObject env, LispObject ldev);
extern LispObject om_getInt(LispObject env, LispObject ldev);
extern LispObject om_getFloat(LispObject env, LispObject ldev);
extern LispObject om_getByteArray(LispObject env, LispObject ldev);
extern LispObject om_getVar(LispObject env, LispObject ldev);
extern LispObject om_getString(LispObject env, LispObject ldev);
extern LispObject om_getSymbol(LispObject env, LispObject ldev);
extern LispObject om_getType(LispObject env, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern LispObject om_read(LispObject env, LispObject dev);
extern LispObject om_supportsCD(LispObject env, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject env, int nargs, ...);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern LispObject workbase[51];
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 workbase[0]
#define work_1 workbase[1]
#define mv_1 workbase[1]
#define mv_2 workbase[2]
#define mv_3 workbase[3]
#define mv_4 workbase[4]
#define work_50 workbase[50]
extern void copy_into_nilseg();
extern void copy_out_of_nilseg();
extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern std::uint64_t hash_equal(LispObject key);
extern char *exit_charvec;
extern std::intptr_t exit_reason;
extern int procstackp;
extern bool garbage_collection_permitted;
extern int csl_argc;
extern const char **csl_argv;
extern bool fasl_output_file;
extern std::size_t output_directory;
extern LispObject *repeat_heap;
extern std::size_t repeat_count;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern std::FILE *binary_read_file;
#endif
extern std::FILE *binary_write_file;
extern std::size_t boffop;
extern void packcharacter(int c);
extern void packbyte(int c);
#define boffo_char(i) ucelt(boffo, i)
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#ifdef SOCKETS
extern bool sockets_ready;
extern void flush_socket();
#endif
extern void report_file(const char *s);
extern int errorset_min, errorset_max;
extern bool force_verbos, force_echo, force_backtrace;
extern bool stop_on_error;
extern std::uint64_t force_cons, force_vec;
extern int init_flags;
extern const char *standard_directory;
extern std::int64_t gc_number;
extern std::int64_t reclaim_trap_count;
extern std::uintptr_t reclaim_stack_limit;
extern std::uint64_t reclaim_trigger_count, reclaim_trigger_target;
#ifdef CONSERVATIVE
extern void reclaim(const char *why);
#else
extern LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, std::size_t size);
#endif
extern void use_gchook(LispObject arg);
extern std::uint64_t force_cons, force_vec;
extern bool next_gc_is_hard;
inline bool cons_forced(std::size_t n)
{
#ifdef DEBUG
 if (force_cons == 0) return false;
 if (force_cons <= n)
 { force_cons = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_cons -= n;
#endif
 return false;
}
inline bool vec_forced(std::size_t n)
{
#ifdef DEBUG
 if (force_vec == 0) return false;
 if (force_vec <= n)
 { force_vec = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_vec -= n;
#endif
 return false;
}
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern std::FILE *spool_file;
extern char spool_file_name[128];
#define CODESIZE 0x1000
typedef struct _entry_point0
{ no_args *p;
 const char *s;
} entry_point0;
typedef struct _entry_point1
{ one_arg *p;
 const char *s;
} entry_point1;
typedef struct _entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct _entry_point3
{ three_args *p;
 const char *s;
} entry_point3;
typedef struct _entry_point4up
{ fourup_args *p;
 const char *s;
} entry_point4up;
extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4up entries_table4up[];
extern entry_point1 entries_tableio[];
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject env, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
extern void Iinit();
extern void IreInit();
extern void Ilist();
extern bool open_output(const char *s, std::size_t len);
#define IMAGE_CODE ((size_t)(-1000))
#define HELP_CODE ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))
#define IOPEN_OUT 0
#define IOPEN_IN 1
extern bool Iopen(const char *name, std::size_t len, int dirn, char *expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char *expanded_name, std::size_t hard, int sixtyfour);
extern bool Iwriterootp(char *expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep1(int i, const char *name, std::size_t len, char *datestamp,
 std::size_t *size, char *expanded_name);
extern bool Imodulep(const char *name, std::size_t len, char *datestamp,
 std::size_t *size, char *expanded_name);
extern char *trim_module_name(char *name, std::size_t *lenp);
extern bool Icopy(const char *name, std::size_t len);
extern bool Idelete(const char *name, std::size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int Igetc();
extern bool Iread(void *buff, std::size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void *buff, std::size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int Zgetc();
extern bool Zread(void *buff, std::size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void *buff, std::size_t size);
extern long int Ioutsize();
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, std::size_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, std::size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern void ensure_screen();
extern int window_heading;
[[noreturn]] extern void my_exit(int n);
extern std::uint64_t base_time;
extern std::chrono::high_resolution_clock::time_point base_walltime;
extern std::uint64_t gc_time;
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
void set_up_signal_handlers();
extern int async_interrupt(int a);
extern void record_get(LispObject tag, bool found);
extern bool isprime(std::uint64_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern LispObject acons(LispObject a, LispObject b, LispObject c);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(std::size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, std::size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject acons_no_gc(LispObject a, LispObject b, LispObject c);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern std::uint32_t Crand();
extern LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(std::uint32_t a);
extern void discard(LispObject a);
extern bool eql_fn(LispObject a, LispObject b);
extern bool cl_equal_fn(LispObject a, LispObject b);
extern bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, LispObject args, LispObject env,
 LispObject from);
extern LispObject apply_lambda(LispObject def, LispObject args,
 LispObject env, LispObject name);
extern void deallocate_pages();
extern void drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject get_basic_vector(int tag, int type, std::size_t length);
extern LispObject get_basic_vector_init(std::size_t n, LispObject v);
extern LispObject reduce_basic_vector_size(LispObject v, std::size_t len);
extern LispObject get_vector(int tag, int type, std::size_t length);
extern LispObject get_vector_init(std::size_t n, LispObject v);
extern LispObject reduce_vector_size(LispObject n, std::size_t length);
extern void prepare_for_borrowing();
inline void zero_out(void *p)
{ char *p1 = (char *)doubleword_align_up((std::uintptr_t)p);
 std::memset(p1, 0, CSL_PAGE_SIZE);
}
extern LispObject borrow_basic_vector(int tag, int type, std::size_t length);
extern LispObject borrow_vector(int tag, int type, std::size_t length);
extern void finished_borrowing();
extern std::uint64_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern bool geq2(LispObject a, LispObject b);
extern bool greaterp2(LispObject a, LispObject b);
extern bool lesseq2(LispObject a, LispObject b);
extern bool lessp2(LispObject a, LispObject b);
extern LispObject list2(LispObject a, LispObject b);
extern LispObject list2star(LispObject a, LispObject b, LispObject c);
extern LispObject list2starrev(LispObject a, LispObject b, LispObject c);
extern LispObject list3(LispObject a, LispObject b, LispObject c);
extern LispObject list3rev(LispObject a, LispObject b, LispObject c);
extern LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, std::size_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 no_args *f0, one_arg *f1, two_args *f2,
 three_args *f3, fourup_args *f4up);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern LispObject nreverse2(LispObject a, LispObject b);
extern std::FILE *open_file(char *filename, const char *original_name,
 std::size_t n, const char *dirn, std::FILE *old_file);
extern LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, std::size_t len);
extern LispObject prin(LispObject u);
extern void debugprint(LispObject a, int depth=10);
extern void debugprint(const char *s, LispObject a);
extern void debugprint(const char *s);
extern const char *get_string_data(LispObject a, const char *why, std::size_t &len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prinhex_to_trace(const char *msg, LispObject value);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void print_bignum(LispObject u, bool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, bool blankp, int nobreak);
extern void print_newbignum(LispObject u, bool blankp, int nobreak);
extern void print_newbighexoctbin(LispObject u,
 int radix, int width, bool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject quotrem2(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern void set_fns(LispObject sym, no_args *f0, one_arg *f1,
 two_args *f2, three_args *f3, fourup_args *f4up);
extern void init_heap_segments(double size);
extern void grab_more_memory(std::size_t npages);
extern bool allocate_more_memory();
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern LispObject times2(LispObject a, LispObject b);
extern std::int32_t thirty_two_bits(LispObject a);
extern std::uint32_t thirty_two_bits_unsigned(LispObject a);
extern std::int64_t sixty_four_bits(LispObject a);
extern std::uint64_t sixty_four_bits_unsigned(LispObject a);
extern std::uint64_t crc64(std::uint64_t crc, const void *buf, std::size_t size);
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
inline LispObject onevalue(LispObject r)
{ exit_count = 1;
 return r;
}
inline LispObject nvalues(LispObject r, int n)
{ exit_count = n;
 return r;
}
inline bool equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return equal_fn(a, b);
 else return false;
}
inline bool cl_equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return cl_equal_fn(a, b);
 else return false;
}
inline bool eql(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return eql_fn(a, b);
 else return false;
}
extern no_args *no_arg_functions[];
extern one_arg *one_arg_functions[];
extern two_args *two_arg_functions[];
extern three_args *three_arg_functions[];
extern fourup_args *fourup_arg_functions[];
extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool three_arg_traceflags[];
extern bool fourup_arg_traceflags[];
extern const char *no_arg_names[];
extern const char *one_arg_names[];
extern const char *two_arg_names[];
extern const char *three_arg_names[];
extern const char *fourup_arg_names[];
typedef struct setup_type
{ const char *name;
 no_args *zero;
 one_arg *one;
 two_args *two;
 three_args *three;
 fourup_args *fourup;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 no_args *zero;
 one_arg *one;
 two_args *two;
 three_args *three;
 fourup_args *fourup;
 std::uint32_t c1;
 std::uint32_t c2;
} setup_type_1;
extern setup_type const
 arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 lisphash_setup[], print_setup[], read_setup[],
 restart_setup[], mpi_setup[];
#ifdef ARITHLIB
extern setup_type const arith_setup[];
#endif
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
extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
 LispObject env, int compilerp);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
[[noreturn]] extern void resource_exceeded();
extern std::int64_t time_base, space_base, io_base, errors_base;
extern std::int64_t time_now, space_now, io_now, errors_now;
extern std::int64_t time_limit, space_limit, io_limit, errors_limit;
extern bool symbol_protect_flag, warn_about_protected_symbols;
#ifdef HASH_STATISTICS
extern std::uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2, Nhputtmp;
extern std::uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define _pi ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr 0
#define boole_and 1
#define boole_andc2 2
#define boole_1 3
#define boole_andc1 4
#define boole_2 5
#define boole_xor 6
#define boole_ior 7
#define boole_nor 8
#define boole_eqv 9
#define boole_c2 10
#define boole_orc2 11
#define boole_c1 12
#define boole_orc1 13
#define boole_nand 14
#define boole_set 15
extern unsigned char msd_table[256], lsd_table[256];
#define top_bit_set(n) (((int32_t)(n)) < 0)
#define top_bit(n) ((int32_t)(((uint32_t)(n)) >> 31))
#define set_top_bit(n) ((int32_t)((uint32_t)(n) | (uint32_t)0x80000000U))
#define clear_top_bit(n) ((int32_t)((uint32_t)(n) & 0x7fffffff))
#define signed_overflow(n) \
 top_bit_set((std::uint32_t)(n) ^ ((std::uint32_t)(n) << 1))
#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))
#define signed29_in_64(n) \
 (((std::int64_t)(((std::uint64_t)(n) & 0x1fffffffU) << 35) / ((std::int64_t)1 << 35)) == \
 (std::int64_t)(n))
#define signed31_in_64(n) \
 (((std::int64_t)(((std::uint64_t)(n) & 0x7fffffffU) << 33) / ((std::int64_t)1 << 33)) == \
 (std::int64_t)(n))
#define signed31_in_ptr(n) \
 (((std::intptr_t)(((std::uintptr_t)(n)&0x7fffffffU) << (8*sizeof(std::intptr_t) - 31)) / \
 ((std::intptr_t)1 << (8*sizeof(std::intptr_t) - 31))) == (std::intptr_t)(n))
#ifdef HAVE_SOFTFLOAT
#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND softfloat_round_near_even
#define FIX_FLOOR softfloat_round_min
#define FIX_CEILING softfloat_round_max
#else
#define FIX_TRUNCATE 1
#define FIX_ROUND 0
#define FIX_FLOOR 2
#define FIX_CEILING 3
#endif 
extern LispObject lisp_fix(LispObject a, int roundmode);
extern LispObject lisp_ifix(LispObject a, LispObject b, int roundmode);
inline bool floating_edge_case(double r)
{ return (1.0/r == 0.0 || r != r);
}
inline void floating_clear_flags()
{}
#define Dmultiply(hi, lo, a, b, c) \
 do { std::uint64_t r64 = (std::uint64_t)(a) * (std::uint64_t)(b) + \
 (std::uint32_t)(c); \
 (lo) = 0x7fffffffu & (std::uint32_t)r64; \
 (hi) = (std::uint32_t)(r64 >> 31); } while (0)
#define Ddivide(r, q, a, b, c) \
 do { std::uint64_t r64 = (((std::uint64_t)(a)) << 31) | (std::uint64_t)(b); \
 std::uint64_t c64 = (std::uint64_t)(std::uint32_t)(c); \
 q = (std::uint32_t)(r64 / c64); \
 r = (std::uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { std::uint64_t r64 = (((std::uint64_t)(a)) << 31) | (std::uint64_t)(b); \
 std::uint64_t c64 = (std::uint64_t)(std::uint32_t)(c); \
 q = (std::uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { std::uint64_t r64 = (((std::uint64_t)(a)) << 31) | (std::uint64_t)(b); \
 std::uint64_t c64 = (std::uint64_t)(std::uint32_t)(c); \
 r = (std::uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#define fixnum_minusp(a) ((intptr_t)(a) < 0)
#define bignum_minusp(a) \
 ((std::int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
inline double value_of_immediate_float(LispObject a)
{ Float_union aa;
 if (SIXTY_FOUR_BIT) aa.i = (std::int32_t)((std::uint64_t)a>>32);
 else aa.i = (std::int32_t)(a - XTAG_SFLOAT);
 return aa.f;
}
extern LispObject make_boxfloat(double a, int type=TYPE_DOUBLE_FLOAT);
#ifdef HAVE_SOFTFLOAT
extern LispObject make_boxfloat128(float128_t a);
#endif 
inline LispObject pack_short_float(double d)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with short float");
 }
 aa.i &= ~0xf;
 if (SIXTY_FOUR_BIT)
 return (LispObject)(((std::uint64_t)aa.i) << 32) + XTAG_SFLOAT;
 else return aa.i + XTAG_SFLOAT;
}
inline LispObject pack_single_float(double d)
{ if (SIXTY_FOUR_BIT)
 { Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return (LispObject)((std::uint64_t)aa.i << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
 }
 else
 { LispObject r = get_basic_vector(TAG_BOXFLOAT,
 TYPE_SINGLE_FLOAT, sizeof(Single_Float));
 single_float_val(r) = (float)d;
 if (trap_floating_overflow &&
 floating_edge_case(single_float_val(r)))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return r;
 }
}
inline LispObject pack_immediate_float(double d,
 LispObject l1, LispObject l2=0)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 if (((l1 | l2) & XTAG_FLOAT32) != 0)
 aerror("exception with single float");
 else aerror("exception with short float");
 }
 if (SIXTY_FOUR_BIT)
 { if (((l1 | l2) & XTAG_FLOAT32) == 0) aa.i &= ~0xf;
 return (LispObject)(((std::uint64_t)aa.i) << 32) + XTAG_SFLOAT +
 ((l1 | l2) & XTAG_FLOAT32);
 }
 aa.i &= ~0xf;
 return aa.i + XTAG_SFLOAT;
}
inline bool eq_i64d(std::int64_t a, double b)
{
 if (b != (double)a) return false;
 if (b == (double)((std::uint64_t)1<<63)) return false;
 return a == (std::int64_t)b;
}
inline bool lessp_i64d(std::int64_t a, double b)
{
 if (a <= ((std::int64_t)1<<53) &&
 a >= -((std::int64_t)1<<53)) return (double)a < b;
 if (!(b >= -(double)((std::uint64_t)1<<63))) return false;
 if (!(b < (double)((std::uint64_t)1<<63))) return true;
 return a < (std::int64_t)b;
}
inline bool lessp_di64(double a, std::int64_t b)
{
 if (b <= ((std::int64_t)1<<53) &&
 b >= -((std::int64_t)1<<53)) return a < (double)b;
 if (!(a < (double)((std::uint64_t)1<<63))) return false;
 if (!(a >= -(double)((std::uint64_t)1<<63))) return true;
 return (std::int64_t)a < b;
}
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, std::int32_t n);
extern LispObject quotbn1(LispObject a, std::int32_t n);
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
extern LispObject quotbb(LispObject a, LispObject b, int needs);
extern LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, std::size_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, std::int32_t msd);
extern bool numeq2(LispObject a, LispObject b);
extern bool SL_numeq2(LispObject a, LispObject b);
extern bool zerop(LispObject a);
extern bool onep(LispObject a);
extern bool minusp(LispObject a);
extern bool plusp(LispObject a);
extern LispObject integer_decode_long_float(LispObject a);
extern LispObject Linteger_decode_float(LispObject env, LispObject a);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(std::intptr_t n);
extern LispObject make_one_word_bignum(std::int32_t n);
extern LispObject make_two_word_bignum(std::int32_t a, std::uint32_t b);
extern LispObject make_three_word_bignum(std::int32_t a, std::uint32_t b, std::uint32_t c);
extern LispObject make_four_word_bignum(std::int32_t a, std::uint32_t b,
 std::uint32_t c, std::uint32_t d);
extern LispObject make_five_word_bignum(std::int32_t a, std::uint32_t b,
 std::uint32_t c, std::uint32_t d, std::uint32_t e);
extern LispObject make_n_word_bignum(std::int32_t a2, std::uint32_t a1,
 std::uint32_t a0, std::size_t n);
extern LispObject make_n4_word_bignum(std::int32_t a3, std::uint32_t a2,
 std::uint32_t a1, std::uint32_t a0, std::size_t n);
extern LispObject make_n5_word_bignum(std::int32_t a4, std::uint32_t a3,
 std::uint32_t a2, std::uint32_t a1,
 std::uint32_t a0, std::size_t n);
extern LispObject make_power_of_two(std::size_t n);
extern LispObject make_lisp_integer32_fn(std::int32_t n);
inline LispObject make_lisp_integer32(std::int32_t n)
{ if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((std::intptr_t)n);
 else return make_lisp_integer32_fn(n);
}
extern LispObject make_lisp_integer64_fn(std::int64_t n);
inline LispObject make_lisp_integer64(std::int64_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((std::intptr_t)n);
 else return make_lisp_integer64_fn(n);
}
extern LispObject make_lisp_unsigned64_fn(std::uint64_t n);
inline LispObject make_lisp_unsigned64(std::uint64_t n)
{ if (n < ((std::uint64_t)1)<<(8*sizeof(std::intptr_t)-5))
 return fixnum_of_int((std::intptr_t)n);
 else return make_lisp_unsigned64_fn(n);
}
extern LispObject make_lisp_integerptr_fn(std::intptr_t n);
inline LispObject make_lisp_integerptr(std::intptr_t n)
{ if (intptr_valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(std::uintptr_t n);
inline LispObject make_lisp_unsignedptr(std::uintptr_t n)
{ if (n < ((std::uintptr_t)1)<<(8*sizeof(std::intptr_t)-5))
 return fixnum_of_int((std::intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
extern LispObject make_lisp_integer128_fn(int128_t n);
inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(NARROW128(n));
 else return make_lisp_integer128_fn(n);
}
extern LispObject make_lisp_unsigned128_fn(uint128_t n);
inline LispObject make_lisp_unsigned128(uint128_t n)
{ if (uint128_valid_as_fixnum(n))
 return fixnum_of_int((std::uint64_t)NARROW128(n));
 else return make_lisp_unsigned128_fn(n);
}
inline void validate_number(LispObject n)
{
}
extern double float_of_integer(LispObject a);
extern LispObject add1(LispObject p);
extern LispObject sub1(LispObject p);
extern LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
#ifdef HAVE_SOFTFLOAT
extern float128_t float128_of_number(LispObject a);
#endif 
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q, int bits);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
#ifdef HAVE_SOFTFLOAT
extern LispObject rationalf128(float128_t *d);
#endif 
extern int _reduced_exp(double, double *);
extern bool lesspbi(LispObject a, LispObject b);
extern bool lesspib(LispObject a, LispObject b);
typedef struct Complex
{ double real;
 double imag;
} Complex;
extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);
#ifndef HAVE_CILK
extern std::thread kara_thread[2];
#define KARA_0 (1<<0)
#define KARA_1 (1<<1)
#define KARA_QUIT (1<<2)
extern void kara_worker(int id);
extern std::mutex kara_mutex;
extern std::condition_variable cv_kara_ready,
 cv_kara_done;
extern unsigned int kara_ready;
extern int kara_done;
#endif
extern std::size_t kparallel, karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#ifdef HAVE_SOFTFLOAT
static int f128M_exponent(const float128_t *p);
static void f128M_set_exponent(float128_t *p, int n);
extern void f128M_ldexp(float128_t *p, int n);
extern void f128M_frexp(float128_t *p, float128_t *r, int *x);
static bool f128M_infinite(const float128_t *p);
static bool f128M_finite(const float128_t *p);
static bool f128M_nan(const float128_t *x);
static bool f128M_subnorm(const float128_t *x);
static bool f128M_negative(const float128_t *x);
static void f128M_negate(float128_t *x);
extern void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
#ifdef LITTLEENDIAN
#define HIPART 1
#define LOPART 0
#else
#define HIPART 0
#define LOPART 1
#endif
inline bool f128M_zero(const float128_t *p)
{ return ((p->v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
inline bool f128M_infinite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 ((p->v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
inline bool f128M_finite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}
inline void f128M_make_infinite(float128_t *p)
{ p->v[HIPART] |= UINT64_C(0x7fff000000000000);
 p->v[HIPART] &= UINT64_C(0xffff000000000000);
 p->v[LOPART] = 0;
}
inline void f128M_make_zero(float128_t *p)
{ p->v[HIPART] &= UINT64_C(0x8000000000000000);
 p->v[LOPART] = 0;
}
inline bool f128M_subnorm(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
inline bool f128M_nan(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
inline bool f128M_negative(const float128_t *x)
{ if (f128M_nan(x)) return false;
 return ((std::int64_t)x->v[HIPART]) < 0;
}
inline int f128M_exponent(const float128_t *p)
{ return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}
inline void f128M_set_exponent(float128_t *p, int n)
{ p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
 (((std::uint64_t)n + 0x3fff) << 48);
}
inline void f128M_negate(float128_t *x)
{ x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}
inline bool floating_edge_case128(float128_t *r)
{ return f128M_infinite(r) || f128M_nan(r);
}
#endif 
extern int double_to_binary(double d, std::int64_t &m);
#ifdef HAVE_SOFTFLOAT
extern int float128_to_binary(const float128_t *d,
 std::int64_t &mhi, std::uint64_t &mlo);
#endif 
extern std::intptr_t double_to_3_digits(double d,
 std::int32_t &a2, std::uint32_t &a1, std::uint32_t &a0);
#ifdef HAVE_SOFTFLOAT
extern std::intptr_t float128_to_5_digits(float128_t *d,
 std::int32_t &a4, std::uint32_t &a3, std::uint32_t &a2, std::uint32_t &a1, std::uint32_t &a0);
extern float128_t f128_0, 
 f128_half, 
 f128_mhalf, 
 f128_1, 
 f128_10, 
 f128_10_17, 
 f128_10_18, 
 f128_r10, 
 f128_N1; 
typedef struct _float256_t
{
#ifdef LITTLEENDIAN
 float128_t lo;
 float128_t hi;
#else
 float128_t hi;
 float128_t lo;
#endif
} float256_t;
inline void f128M_to_f256M(const float128_t *a, float256_t *b)
{ b->hi = *a;
 b->lo = f128_0;
} 
extern void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern int f128M_print_E(int width, int precision, float128_t *p);
extern int f128M_print_F(int width, int precision, float128_t *p);
extern int f128M_print_G(int width, int precision, float128_t *p);
extern float128_t atof128(const char *s);
#endif 
#ifdef HAVE_SOFTFLOAT
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1); \
 case TYPE_RATNUM: \
 return name##_r(a1); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 default: \
 aerror1("bad arg for " #name, a1); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0) \
 return name##_f(a1); \
 else return name##_s(a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a2))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a2))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a2 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(inline, type, name##_i, name) \
 \
arith_dispatch_1a(inline, type, name##_b, name) \
 \
arith_dispatch_1a(inline, type, name##_r, name) \
 \
arith_dispatch_1a(inline, type, name##_c, name) \
 \
arith_dispatch_1a(inline, type, name##_s, name) \
 \
arith_dispatch_1a(inline, type, name##_f, name) \
 \
arith_dispatch_1a(inline, type, name##_d, name) \
 \
arith_dispatch_1a(inline, type, name##_l, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#else 
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1); \
 case TYPE_RATNUM: \
 return name##_r(a1); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 default: \
 aerror1("bad arg for " #name, a1); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1); \
 else return name##_s(a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a2))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a2))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a2 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(inline, type, name##_i, name) \
 \
arith_dispatch_1a(inline, type, name##_b, name) \
 \
arith_dispatch_1a(inline, type, name##_r, name) \
 \
arith_dispatch_1a(inline, type, name##_c, name) \
 \
arith_dispatch_1a(inline, type, name##_s, name) \
 \
arith_dispatch_1a(inline, type, name##_f, name) \
 \
arith_dispatch_1a(inline, type, name##_d, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#endif 
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef CONSERVATIVE
extern void poll();
#endif
extern LispObject Lbatchp(LispObject env);
extern LispObject Ldate(LispObject env);
extern LispObject Ldatestamp(LispObject env);
extern LispObject Leject(LispObject env);
[[noreturn]] extern void Lerror_0(LispObject env);
extern LispObject Lall_symbols0(LispObject env);
extern LispObject Lflush(LispObject env);
extern LispObject Lgc0(LispObject env);
extern LispObject Lgctime(LispObject env);
extern LispObject Lgensym(LispObject env);
extern LispObject Llist_modules(LispObject env);
extern LispObject Llibrary_members0(LispObject env);
extern LispObject Lload_source0(LispObject env);
extern LispObject Lload_selected_source0(LispObject env);
extern LispObject Lload_spid(LispObject);
extern LispObject Llposn(LispObject env);
extern LispObject Lmapstore0(LispObject env);
extern LispObject Lnext_random(LispObject env);
extern LispObject Lnilfn(LispObject env);
extern LispObject Lposn(LispObject env);
extern LispObject Lread(LispObject env);
extern LispObject Lreadch(LispObject env);
extern LispObject Lrtell(LispObject env);
extern LispObject Lterpri(LispObject env);
extern LispObject Ltime(LispObject env);
extern LispObject Ltmpnam(LispObject env);
extern LispObject Ltyi(LispObject env);
extern LispObject Lunserialize(LispObject env);
extern LispObject autoload_0(LispObject env);
extern LispObject bytecoded_0(LispObject env);
extern LispObject Lbytecounts_0(LispObject env);
extern LispObject byteopt_0(LispObject def);
extern LispObject byteoptrest_0(LispObject def);
extern LispObject funarged_0(LispObject env);
extern LispObject tracefunarged_0(LispObject env);
extern LispObject hardopt_0(LispObject def);
extern LispObject hardoptrest_0(LispObject def);
extern LispObject interpreted_0(LispObject env);
extern LispObject tracebytecoded_0(LispObject env);
extern LispObject tracebyteopt_0(LispObject def);
extern LispObject tracebyteoptrest_0(LispObject def);
extern LispObject tracebytecoded_0(LispObject env);
extern LispObject traceinterpreted_0(LispObject env);
extern LispObject tracehardopt_0(LispObject def);
extern LispObject tracehardoptrest_0(LispObject def);
extern LispObject undefined_0(LispObject env);
extern LispObject f0_as_0(LispObject env);
extern LispObject autoload_1(LispObject env, LispObject a);
extern LispObject bytecoded_1(LispObject env, LispObject a);
extern LispObject Lbytecounts_1(LispObject env, LispObject a);
extern LispObject byteopt_1(LispObject def, LispObject a);
extern LispObject byteoptrest_1(LispObject def, LispObject a);
extern LispObject funarged_1(LispObject env, LispObject a1);
extern LispObject tracefunarged_1(LispObject env, LispObject a1);
extern LispObject hardopt_1(LispObject def, LispObject a);
extern LispObject hardoptrest_1(LispObject def, LispObject a);
extern LispObject interpreted_1(LispObject env, LispObject a1);
extern LispObject tracebytecoded_1(LispObject env, LispObject a);
extern LispObject tracebyteopt_1(LispObject def, LispObject a);
extern LispObject tracebyteoptrest_1(LispObject def, LispObject a);
extern LispObject tracebytecoded_1(LispObject env, LispObject a);
extern LispObject traceinterpreted_1(LispObject env, LispObject a1);
extern LispObject tracehardopt_1(LispObject def, LispObject a);
extern LispObject tracehardoptrest_1(LispObject def, LispObject a);
extern LispObject undefined_1(LispObject env, LispObject a1);
extern LispObject f1_as_0(LispObject env, LispObject a);
extern LispObject f1_as_1(LispObject env, LispObject a);
extern LispObject Labsval(LispObject env, LispObject a);
extern LispObject Ladd1(LispObject env, LispObject a);
extern LispObject Lalpha_char_p(LispObject env, LispObject a);
extern LispObject Lall_symbols(LispObject env, LispObject a1);
extern LispObject Lapply0(LispObject env, LispObject a);
extern LispObject Lapply_1(LispObject env, LispObject fn);
extern LispObject Latan(LispObject env, LispObject a);
extern LispObject Latom(LispObject env, LispObject a);
extern LispObject Lbanner(LispObject env, LispObject a);
extern LispObject Lboundp(LispObject env, LispObject a);
extern LispObject Lbpsp(LispObject env, LispObject a);
extern LispObject Lbpsupbv(LispObject env, LispObject v);
extern LispObject Lcaaaar(LispObject env, LispObject a);
extern LispObject Lcaaadr(LispObject env, LispObject a);
extern LispObject Lcaaar(LispObject env, LispObject a);
extern LispObject Lcaadar(LispObject env, LispObject a);
extern LispObject Lcaaddr(LispObject env, LispObject a);
extern LispObject Lcaadr(LispObject env, LispObject a);
extern LispObject Lcaar(LispObject env, LispObject a);
extern LispObject Lcaar(LispObject env, LispObject a);
extern LispObject Lcadaar(LispObject env, LispObject a);
extern LispObject Lcadadr(LispObject env, LispObject a);
extern LispObject Lcadar(LispObject env, LispObject a);
extern LispObject Lcaddar(LispObject env, LispObject a);
extern LispObject Lcadddr(LispObject env, LispObject a);
extern LispObject Lcaddr(LispObject env, LispObject a);
extern LispObject Lcadr(LispObject env, LispObject a);
extern LispObject Lcadr(LispObject env, LispObject a);
extern LispObject Lcar(LispObject env, LispObject a);
extern LispObject Lcar(LispObject env, LispObject a);
extern LispObject Lcdaaar(LispObject env, LispObject a);
extern LispObject Lcdaadr(LispObject env, LispObject a);
extern LispObject Lcdaar(LispObject env, LispObject a);
extern LispObject Lcdadar(LispObject env, LispObject a);
extern LispObject Lcdaddr(LispObject env, LispObject a);
extern LispObject Lcdadr(LispObject env, LispObject a);
extern LispObject Lcdar(LispObject env, LispObject a);
extern LispObject Lcdar(LispObject env, LispObject a);
extern LispObject Lcddaar(LispObject env, LispObject a);
extern LispObject Lcddadr(LispObject env, LispObject a);
extern LispObject Lcddar(LispObject env, LispObject a);
extern LispObject Lcdddar(LispObject env, LispObject a);
extern LispObject Lcddddr(LispObject env, LispObject a);
extern LispObject Lcdddr(LispObject env, LispObject a);
extern LispObject Lcddr(LispObject env, LispObject a);
extern LispObject Lcddr(LispObject env, LispObject a);
extern LispObject Lcdr(LispObject env, LispObject a);
extern LispObject Lcdr(LispObject env, LispObject a);
extern LispObject Lchar_code(LispObject env, LispObject a);
extern LispObject Lclose(LispObject env, LispObject a);
extern LispObject Lcodep(LispObject env, LispObject a);
extern LispObject Lcompress(LispObject env, LispObject a);
extern LispObject Lconsp(LispObject env, LispObject a);
extern LispObject Lconstantp(LispObject env, LispObject a);
extern LispObject Lcopy_module(LispObject env, LispObject a);
extern LispObject Ldefine_in_module(LispObject env, LispObject a);
extern LispObject Ldelete_module(LispObject env, LispObject a);
extern LispObject Ldigitp(LispObject env, LispObject a);
extern LispObject Lendp(LispObject env, LispObject a);
[[noreturn]] extern void Lerror_1(LispObject env, LispObject a1);
extern LispObject Lerrorset_1(LispObject env, LispObject form);
extern LispObject Leval(LispObject env, LispObject a);
extern LispObject Levenp(LispObject env, LispObject a);
extern LispObject Levlis(LispObject env, LispObject a);
extern LispObject Lexplode(LispObject env, LispObject a);
extern LispObject Lexplode2lc(LispObject env, LispObject a);
extern LispObject Lexplode2lcn(LispObject env, LispObject a);
extern LispObject Lexplode2n(LispObject env, LispObject a);
extern LispObject Lexplodec(LispObject env, LispObject a);
extern LispObject Lexplodecn(LispObject env, LispObject a);
extern LispObject Lexplodehex(LispObject env, LispObject a);
extern LispObject Lexploden(LispObject env, LispObject a);
extern LispObject Lexplodeoctal(LispObject env, LispObject a);
extern LispObject Lfixp(LispObject env, LispObject a);
extern LispObject Lfloat(LispObject env, LispObject a);
extern LispObject Lfloatp(LispObject env, LispObject a);
extern LispObject Lfrexp(LispObject env, LispObject a);
extern LispObject Lfuncall_1(LispObject env, LispObject fn);
extern LispObject Lgc(LispObject env, LispObject a);
extern LispObject Lgc_forcer1(LispObject env, LispObject a);
extern LispObject Lgensym0(LispObject env, LispObject a, const char *s);
extern LispObject Lgensym1(LispObject env, LispObject a);
extern LispObject Lgensym2(LispObject env, LispObject a);
extern LispObject Lgetd(LispObject env, LispObject a);
extern LispObject Lgetenv(LispObject env, LispObject a);
extern LispObject Lget_bps(LispObject env, LispObject a);
extern LispObject Liadd1(LispObject env, LispObject a);
extern LispObject Lidentity(LispObject env, LispObject a);
extern LispObject Liminus(LispObject env, LispObject a);
extern LispObject Liminusp(LispObject env, LispObject a);
extern LispObject Lindirect(LispObject env, LispObject a);
extern LispObject Lintegerp(LispObject env, LispObject a);
extern LispObject Lintern(LispObject env, LispObject a);
extern LispObject Lionep(LispObject env, LispObject a);
extern LispObject Lis_spid(LispObject env, LispObject a);
extern LispObject Lisub1(LispObject env, LispObject a);
extern LispObject Lizerop(LispObject env, LispObject a);
extern LispObject Llength(LispObject env, LispObject a);
extern LispObject Llengthc(LispObject env, LispObject a);
extern LispObject Llibrary_members(LispObject env, LispObject a);
extern LispObject Llinelength(LispObject env, LispObject a);
extern LispObject Llist_to_string(LispObject env, LispObject a);
extern LispObject Llist_to_vector(LispObject env, LispObject a);
extern LispObject Lload_module(LispObject env, LispObject a);
extern LispObject Lload_source(LispObject env, LispObject a);
extern LispObject Lload_selected_source(LispObject env, LispObject a);
extern LispObject Llognot(LispObject env, LispObject a);
extern LispObject Llog_1(LispObject env, LispObject a);
extern LispObject Llsd(LispObject env, LispObject a);
extern LispObject Lmacroexpand(LispObject env, LispObject a);
extern LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern LispObject Lmacro_function(LispObject env, LispObject a);
extern LispObject Lmake_global(LispObject env, LispObject a);
extern LispObject Lmake_keyword(LispObject env, LispObject a);
extern LispObject Lmake_special(LispObject env, LispObject a);
extern LispObject Lmapstore(LispObject env, LispObject a);
extern LispObject Lmd5(LispObject env, LispObject a1);
extern LispObject Lmd60(LispObject env, LispObject a1);
extern LispObject Lminus(LispObject env, LispObject a);
extern LispObject Lminusp(LispObject env, LispObject a);
extern LispObject Lmkevect(LispObject env, LispObject n);
extern LispObject Lmkhash_1(LispObject env, LispObject a);
extern LispObject Lmkhashset(LispObject env, LispObject a);
extern LispObject Lmkquote(LispObject env, LispObject a);
extern LispObject Lmkvect(LispObject env, LispObject a);
extern LispObject Lmodular_minus(LispObject env, LispObject a);
extern LispObject Lmodular_number(LispObject env, LispObject a);
extern LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern LispObject Lmodule_exists(LispObject env, LispObject a);
extern LispObject Lmsd(LispObject env, LispObject a);
extern LispObject Lmv_list(LispObject env, LispObject a);
extern LispObject Lncons(LispObject env, LispObject a);
extern LispObject Lnreverse(LispObject env, LispObject a);
extern LispObject Lnull(LispObject env, LispObject a);
extern LispObject Lnumberp(LispObject env, LispObject a);
extern LispObject Loddp(LispObject env, LispObject a);
extern LispObject Lonep(LispObject env, LispObject a);
extern LispObject Lpagelength(LispObject env, LispObject a);
extern LispObject Lplist(LispObject env, LispObject a);
extern LispObject Lplusp(LispObject env, LispObject a);
extern LispObject Lprin(LispObject env, LispObject a);
extern LispObject Lprin(LispObject env, LispObject a);
extern LispObject Lprin2a(LispObject env, LispObject a);
extern LispObject Lprinc(LispObject env, LispObject a);
extern LispObject Lprinc(LispObject env, LispObject a);
extern LispObject Lprint(LispObject env, LispObject a);
extern LispObject Lprintc(LispObject env, LispObject a);
extern LispObject Lrandom_1(LispObject env, LispObject a);
extern LispObject Lrational(LispObject env, LispObject a);
extern LispObject Lrdf1(LispObject env, LispObject a);
extern LispObject Lrds(LispObject env, LispObject a);
extern LispObject Lremd(LispObject env, LispObject a);
extern LispObject Lrepresentation1(LispObject env, LispObject a);
extern LispObject Lreverse(LispObject env, LispObject a);
extern LispObject Lserialize(LispObject env, LispObject a);
extern LispObject Lserialize1(LispObject env, LispObject a);
extern LispObject Lsetpchar(LispObject env, LispObject a);
extern LispObject Lset_small_modulus(LispObject env, LispObject a);
extern LispObject Lsmkvect(LispObject env, LispObject a);
extern LispObject Lspecial_char(LispObject env, LispObject a);
extern LispObject Lspecial_form_p(LispObject env, LispObject a);
extern LispObject Lspid_to_nil(LispObject env, LispObject a);
extern LispObject Lspool(LispObject env, LispObject a);
extern LispObject Lstart_module(LispObject env, LispObject a);
[[noreturn]] extern void Lstop1(LispObject env, LispObject a);
extern LispObject Lstringp(LispObject env, LispObject a);
extern LispObject Lsub1(LispObject env, LispObject a);
extern LispObject Lsymbolp(LispObject env, LispObject a);
extern LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern LispObject Lsymbol_env(LispObject env, LispObject a);
extern LispObject Lsymbol_function(LispObject env, LispObject a);
extern LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern LispObject Lsymbol_name(LispObject env, LispObject a);
extern LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern LispObject Lsymbol_value(LispObject env, LispObject a);
extern LispObject Lsystem(LispObject env, LispObject a);
extern LispObject Lthreevectorp(LispObject env, LispObject a);
extern LispObject Lthrow_nil(LispObject env, LispObject a);
extern LispObject Ltrace(LispObject env, LispObject a);
extern LispObject Ltruncate(LispObject env, LispObject a);
extern LispObject Lttab(LispObject env, LispObject a);
extern LispObject Ltyo(LispObject env, LispObject a);
extern LispObject Lunintern(LispObject env, LispObject a);
extern LispObject Lunmake_global(LispObject env, LispObject a);
extern LispObject Lunmake_keyword(LispObject env, LispObject a);
extern LispObject Lunmake_special(LispObject env, LispObject a);
extern LispObject Luntrace(LispObject env, LispObject a);
extern LispObject Lupbv(LispObject env, LispObject a);
extern LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern LispObject Lvectorp(LispObject env, LispObject a);
extern LispObject Lverbos(LispObject env, LispObject a);
extern LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern LispObject Lwrs(LispObject env, LispObject a);
extern LispObject Lxtab(LispObject env, LispObject a);
extern LispObject Lxtab(LispObject env, LispObject a);
extern LispObject Lzerop(LispObject env, LispObject a);
extern LispObject Lfind_symbol_1(LispObject env, LispObject str);
extern LispObject Llistp(LispObject env, LispObject a);
extern LispObject autoload_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject bytecoded_2(LispObject env, LispObject a, LispObject b);
extern LispObject byteopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject byteoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject funarged_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracefunarged_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject hardopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject hardoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject interpreted_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracebyteopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracebyteoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracebytecoded_2(LispObject env, LispObject a, LispObject b);
extern LispObject traceinterpreted_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracehardopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracehardoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject undefined_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lappend_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern LispObject Lash(LispObject env, LispObject a, LispObject b);
extern LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern LispObject Lbpsgetv(LispObject env, LispObject v, LispObject n);
extern LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern LispObject Ldifference_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ldivide_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern LispObject Leq(LispObject env, LispObject a, LispObject b);
extern LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern LispObject Leql(LispObject env, LispObject a, LispObject b);
extern LispObject Leqn_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern LispObject Lequal(LispObject env, LispObject a, LispObject b);
[[noreturn]] extern void Lerror_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject Lerrorset_2(LispObject env, LispObject form, LispObject ffg1);
extern LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern LispObject Lfuncall_2(LispObject env, LispObject fn, LispObject a1);
extern LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b);
extern LispObject Lgcd_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lgeq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lget(LispObject env, LispObject a, LispObject b);
extern LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern LispObject Lgreaterp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lidifference_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ligeq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ligreaterp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lileq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lilessp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Limax_2(LispObject env, LispObject a, LispObject b);
extern LispObject Limin_2(LispObject env, LispObject a, LispObject b);
extern LispObject Linorm(LispObject env, LispObject a, LispObject k);
extern LispObject Lintersect(LispObject env, LispObject a, LispObject b);
extern LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b);
extern LispObject Liplus_2(LispObject env, LispObject a, LispObject b);
extern LispObject Liquotient_2(LispObject env, LispObject a, LispObject b);
extern LispObject Liremainder_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern LispObject Litimes_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llcm_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lleq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llessp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llist_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llog(LispObject env, LispObject a, LispObject b);
extern LispObject Llog_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern LispObject Lmax_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern LispObject Lmin_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmkhash_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmod_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern LispObject Lneq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern LispObject Lpair(LispObject env, LispObject a, LispObject b);
extern LispObject Lplus_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lquotient_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrem_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b);
extern LispObject Lresource_limit_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern LispObject Lrseek(LispObject env, LispObject a);
extern LispObject Lset(LispObject env, LispObject a, LispObject b);
extern LispObject Lset_help_file(LispObject env, LispObject a, LispObject b);
extern LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
[[noreturn]] extern void Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern LispObject Ltimes_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lunion(LispObject env, LispObject a, LispObject b);
extern LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b);
extern LispObject Lwrite_module(LispObject env, LispObject a, LispObject b);
extern LispObject Lxcons(LispObject env, LispObject a, LispObject b);
extern LispObject Laref_2(LispObject env, LispObject a, LispObject b);
extern LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern LispObject Lfloat_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrandom_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
extern LispObject f3_as_0(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_1(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_2(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lapply_3(LispObject env, LispObject fn, LispObject a1, LispObject a2);
extern LispObject Lapply2(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lacons(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Laref_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Laset_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Lbpsputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
[[noreturn]] extern void Lerror_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lerrorset_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Lfuncall_3(LispObject env, LispObject fn, LispObject a1, LispObject a2);
extern LispObject Llist_2star(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Llist_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lput_hash(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lputprop(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lresource_limit_3(LispObject env, LispObject a, LispObject b, LispObject c);
extern LispObject Lsputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lsubst(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lget_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lmkhash_3(LispObject env, LispObject a, LispObject b, LispObject c);
extern LispObject autoload_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject bytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject byteopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject byteoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject funarged_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracefunarged_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject hardopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject hardoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject interpreted_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracebytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracebyteopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracebyteoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracebytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject traceinterpreted_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracehardopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracehardoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject undefined_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject autoload_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject bytecoded_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject byteopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject byteoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject funarged_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracefunarged_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject hardopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject hardoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject interpreted_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebyteopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebyteoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebytecoded0(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebytecoded_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject traceinterpreted_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracehardopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracehardoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject undefined_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lapply_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lapply3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
[[noreturn]] extern void Lerror_34up(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4up);
extern LispObject Lerrorset_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lfuncall_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llist_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lliststar_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogand_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogeqv_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogor_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogxor_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lmax_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lmin_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lresource_limit_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lvalues_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lappend_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Laref_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Laset_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Leqn_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgcd_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgeq_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgreaterp_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llcm_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lleq_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llessp_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lquotient_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject env, LispObject ldev);
extern LispObject om_putEndApp(LispObject env, LispObject ldev);
extern LispObject om_putAtp(LispObject env, LispObject ldev);
extern LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern LispObject om_putAttr(LispObject env, LispObject ldev);
extern LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern LispObject om_putBind(LispObject env, LispObject ldev);
extern LispObject om_putEndBind(LispObject env, LispObject ldev);
extern LispObject om_putBVar(LispObject env, LispObject ldev);
extern LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern LispObject om_putError(LispObject env, LispObject ldev);
extern LispObject om_putEndError(LispObject env, LispObject ldev);
extern LispObject om_putObject(LispObject env, LispObject ldev);
extern LispObject om_putEndObject(LispObject env, LispObject ldev);
extern LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_getApp(LispObject env, LispObject ldev);
extern LispObject om_getEndApp(LispObject env, LispObject ldev);
extern LispObject om_getAtp(LispObject env, LispObject ldev);
extern LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern LispObject om_getAttr(LispObject env, LispObject ldev);
extern LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern LispObject om_getBind(LispObject env, LispObject ldev);
extern LispObject om_getEndBind(LispObject env, LispObject ldev);
extern LispObject om_getBVar(LispObject env, LispObject ldev);
extern LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern LispObject om_getError(LispObject env, LispObject ldev);
extern LispObject om_getEndError(LispObject env, LispObject ldev);
extern LispObject om_getObject(LispObject env, LispObject ldev);
extern LispObject om_getEndObject(LispObject env, LispObject ldev);
extern LispObject om_getInt(LispObject env, LispObject ldev);
extern LispObject om_getFloat(LispObject env, LispObject ldev);
extern LispObject om_getByteArray(LispObject env, LispObject ldev);
extern LispObject om_getVar(LispObject env, LispObject ldev);
extern LispObject om_getString(LispObject env, LispObject ldev);
extern LispObject om_getSymbol(LispObject env, LispObject ldev);
extern LispObject om_getType(LispObject env, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern LispObject om_read(LispObject env, LispObject dev);
extern LispObject om_supportsCD(LispObject env, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern LispObject undefined_4up(LispObject env,
 LispObject a1, LispObject a2, LispObject a3, LispObject a4);
#endif 
#ifndef __lispthrow_h
#define __lispthrow_h 1
extern LispObject *stack;
extern std::jmp_buf *global_jb;
inline void push(LispObject a)
{ *++stack = a;
}
inline void push2(LispObject a, LispObject b)
{ *++stack = a;
 *++stack = b;
}
inline void push3(LispObject a, LispObject b, LispObject c)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
}
inline void push4(LispObject a, LispObject b, LispObject c,
 LispObject d)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
}
inline void push5(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
}
inline void push6(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e, LispObject f)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
 *++stack = f;
}
inline void push(LispObject a, LispObject b)
{ *++stack = a;
 *++stack = b;
}
inline void push(LispObject a, LispObject b, LispObject c)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
}
inline void push(LispObject a, LispObject b, LispObject c, LispObject d)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
}
inline void push(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
}
inline void push(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e, LispObject f)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
 *++stack = f;
}
inline void pop(LispObject& a)
{ a = *stack--;
}
inline void pop(volatile LispObject& a)
{ a = *stack--;
}
inline void pop2(LispObject& a, LispObject& b)
{ a = *stack--;
 b = *stack--;
}
inline void pop3(LispObject& a, LispObject& b, LispObject& c)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
}
inline void pop4(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
}
inline void pop5(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
}
inline void pop6(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e, LispObject& f)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
 f = *stack--;
}
inline void pop(LispObject& a, LispObject& b)
{ a = *stack--;
 b = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c, LispObject& d)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e, LispObject& f)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
 f = *stack--;
}
inline void popv(int n)
{ stack -= n;
}
extern volatile bool tick_pending;
extern volatile int unwind_pending;
extern void respond_to_stack_event();
inline void stackcheck0()
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit) respond_to_stack_event();
}
inline void stackcheck1(LispObject& a1) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1);
 respond_to_stack_event();
 pop(a1);
 }
}
inline void stackcheck2(LispObject& a1, LispObject& a2) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1, a2);
 respond_to_stack_event();
 pop(a2, a1);
 }
}
inline void stackcheck3(LispObject& a1, LispObject& a2, LispObject& a3) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1, a2, a3);
 respond_to_stack_event();
 pop(a3, a2, a1);
 }
}
inline void stackcheck4(LispObject& a1, LispObject& a2, LispObject& a3, LispObject& a4) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1, a2, a3, a4);
 respond_to_stack_event();
 pop(a4, a3, a2, a1);
 }
}
inline void stackcheck()
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit) respond_to_stack_event();
}
inline void stackcheck(LispObject& a1) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1);
 respond_to_stack_event();
 pop(a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1, a2);
 respond_to_stack_event();
 pop(a2, a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2, LispObject& a3) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1, a2, a3);
 respond_to_stack_event();
 pop(a3, a2, a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2,
 LispObject& a3, LispObject& a4) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stackLimit)
 { push(a1, a2, a3, a4);
 respond_to_stack_event();
 pop(a4, a3, a2, a1);
 }
}
inline void respond_to_fringe_event(LispObject &r, const char *msg)
{
#ifdef BOOTSTRAP
 if (msg == NULL)
 {
#ifdef CONSERVATIVE
 reclaim("gc-forcer");
#else
 r = reclaim(r, "gc-forcer", GC_USER_HARD, 0);
#endif
 return;
 }
#endif 
 std::uintptr_t f = event_flag.load();
 while (!event_flag.compare_exchange_weak(f, 0)) {}
 if (f == 0)
 {
#ifdef CONSERVATIVE
 reclaim(msg);
#else
 r = reclaim(r, "gc-forcer", GC_USER_HARD, 0);
#endif
 return;
 }
}
class stack_popper
{ int n;
public:
 stack_popper(int nn)
 { n = nn;
 }
 ~stack_popper()
 { popv(n);
 }
};
class stack_restorer
{ LispObject *stackSave;
public:
 stack_restorer()
 { stackSave = stack;
 }
 ~stack_restorer()
 { stack = stackSave;
 }
};
class save_current_function
{ LispObject *savestack;
public:
 save_current_function(LispObject newfn)
 { push(current_function);
 savestack = stack;
 current_function = newfn;
 }
 ~save_current_function()
 { stack = savestack;
 pop(current_function);
 }
};
class bind_fluid_stack
{ LispObject *savestack;
 int env_loc;
 int name_loc;
 int val_loc;
public:
 bind_fluid_stack(int e, int name, int val)
 { savestack = stack;
 env_loc = e;
 name_loc = name;
 val_loc = val;
#ifdef TRACE_FLUID
 debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val, stack);
 debug_printf("name="); prin_to_debug(elt(savestack[e], name));
 debug_printf(" old-val="); prin_to_debug(qvalue(elt(savestack[e], name)));
 debug_printf("\n");
#endif
 savestack[val] = qvalue(elt(savestack[e], name));
 }
 ~bind_fluid_stack()
 {
#ifdef TRACE_FLUID
 debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc, savestack);
 debug_printf("name="); prin_to_debug(elt(savestack[env_loc], name_loc));
 debug_printf(" local-val="); prin_to_debug(qvalue(elt(savestack[env_loc], name_loc)));
 debug_printf(" restored-val="); prin_to_debug(savestack[val_loc]);
 debug_printf("\n");
#endif
 setvalue(elt(savestack[env_loc], name_loc), savestack[val_loc]);
 }
};
#ifndef LISPEXCEPTION_DEFINED
struct LispException : public std::exception
{ virtual const char *what() const throw()
 { return "Generic Lisp Exception";
 }
};
 struct LispError : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Error";
 }
 };
 struct LispSignal : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Signal";
 }
 };
#endif 
 struct LispResource : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Resouce Limiter";
 }
 };
 struct LispGo : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Go";
 }
 };
 struct LispReturnFrom : public LispException
 { virtual const char *what() const throw()
 { return "Lisp ReturnFrom";
 }
 };
 struct LispThrow : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Throw";
 }
 };
 struct LispRestart : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Restart";
 }
 };
class RAIIstack_sanity
{ LispObject *saveStack;
 const char *fname;
 const char *file;
 int line;
 LispObject w;
public:
 RAIIstack_sanity(const char *fn, const char *fi, int li)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = nil;
 }
 RAIIstack_sanity(const char *fn, const char *fi, int li, LispObject ww)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = ww;
 }
 ~RAIIstack_sanity()
 {
#ifdef __cpp_lib_uncaught_exceptions
 if (saveStack != stack && !std::uncaught_exceptions() != 0)
#else
 if (saveStack != stack && !std::uncaught_exception())
#endif
 { err_printf("[Stack Sanity Oddity] %p => %p in %s : %s:%d\n",
 saveStack, stack, fname, file, line);
 err_printf("Data: ");
 prin_to_error(w);
 err_printf("\n");
 err_printf("exit_count = %d, exit_reason = %d\n",
 exit_count, exit_reason);
 }
 }
};
inline const char *tidy_filename(const char *a)
{ const char *b = std::strrchr(a, '/');
 return (b == NULL ? a : b+1);
}
#ifdef DEBUG
#define STACK_SANITY \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__);
#define STACK_SANITY1(w) \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__, w);
#else
#define STACK_SANITY ;
#define STACK_SANITY1(w) ;
#endif
class RAIIsave_codevec
{ LispObject *saveStack;
public:
 RAIIsave_codevec()
 { push(litvec, codevec);
 saveStack = stack;
 }
 ~RAIIsave_codevec()
 { stack = saveStack;
 pop(codevec, litvec);
 }
};
#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;
[[noreturn]] extern void global_longjmp();
#ifndef SAVE_STACK_AND_JB_DEFINED
class RAIIsave_stack_and_jb
{ LispObject *saveStack;
 std::jmp_buf *jbsave;
public:
 RAIIsave_stack_and_jb()
 { jbsave = global_jb; 
 saveStack = stack; 
 }
 ~RAIIsave_stack_and_jb()
 { global_jb = jbsave; 
 stack = saveStack; 
 }
};
#endif
class RAIIsave_stack
{ LispObject *saveStack;
public:
 RAIIsave_stack()
 { saveStack = stack; 
 }
 ~RAIIsave_stack()
 { stack = saveStack; 
 }
};
#define START_SETJMP_BLOCK \
 std::jmp_buf jb; \
 RAIIsave_stack_and_jb save_stack_Object; \
 switch (setjmp(jb)) \
 { default: \
 case 1: exit_reason = UNWIND_SIGNAL; \
 if (miscflags & HEADLINE_FLAG) \
 err_printf("\n+++ Error %s: ", errorset_msg); \
 throw LispSignal(); \
 case 0: break; \
 } \
 global_jb = &jb;
#define START_TRY_BLOCK \
 RAIIsave_stack save_stack_Object;
#define on_backtrace(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError &e) \
 { int _reason = exit_reason; \
 b; \
 exit_reason = _reason; \
 throw; \
 }
#define if_error(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError &e) \
 { b; \
 }
#define ignore_error(a) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError &e) \
 { \
 }
#define ignore_exception(a) \
 try \
 { START_SETJMP_BLOCK; \
 a; \
 } \
 catch (LispError &e) \
 { \
 }
#endif 
#ifdef CONSERVATIVE
#ifndef header_newallocate_h
#define header_newallocate_h 1
#include <csetjmp>
extern void set_up_signal_handlers();
extern void allocateSegment(std::size_t);
static const std::size_t pageSize = 8*1024*1024; 
static const std::size_t bytesForMap = pageSize/64;
static const std::size_t qwordsForMap = bytesForMap/8;
static const std::size_t spareBytes = 2*bytesForMap;
enum PageClass
{
 reservedPageTag = 0x00, 
 freePageTag = 0x01, 
 mostlyFreePageTag = 0x11, 
 
 busyPageTag = 0x02, 
 currentPageTag = 0x12, 
 previousPageTag = 0x22 
};
union alignas(pageSize) Page
{ struct PageHeader
 {
 union Page *chain;
 PageClass pageClass;
 std::uintptr_t fringe;
 std::uintptr_t heaplimit;
 std::atomic<bool> dirtypage;
 bool onstarts_present;
 bool somePins;
 double endOfHeader;
 } pageHeader;
 struct PageBody
 { union PageBitmaps
 {
 std::atomic<std::uint8_t> dirty[2*bytesForMap];
 std::uint64_t qwordsDirty[2*qwordsForMap];
 struct Maps
 { std::uint64_t objstart[qwordsForMap];
 std::uint64_t pinned[qwordsForMap];
 } maps;
 } pageBitmaps;
 LispObject data[(pageSize - spareBytes)/sizeof(LispObject)];
 } pageBody;
};
inline bool pageIsBusy(Page *p)
{ return (p->pageHeader.pageClass & 0x0f) == busyPageTag;
}
inline void write_barrier(LispObject *p)
{ std::uintptr_t a = reinterpret_cast<std::uintptr_t>(p);
 
 Page *x = reinterpret_cast<Page *>(a & -UINT64_C(0x800000));
 x->pageHeader.dirtypage.store(true);
 std::uintptr_t offset = a & 0x7fffffU;
 x->pageBody.pageBitmaps.dirty[offset/32].store(1);
}
inline void write_barrier(std::atomic<LispObject> *p)
{ write_barrier((LispObject *)p);
}
extern std::uint64_t threadMap;
class ThreadStartup
{
public:
 ThreadStartup();
 ~ThreadStartup();
};
extern Page *currentPage; 
extern Page *previousPage; 
extern Page *busyPages; 
extern Page *mostlyFreePages; 
extern Page *freePages; 
extern Page *doomedPages; 
extern std::size_t busyPagesCount;
extern std::size_t mostlyFreePagesCount;
extern std::size_t freePagesCount;
extern std::uintptr_t pinsA, pinsC;
extern void *heapSegment[32];
extern void *heapSegmentBase[32];
extern std::size_t heapSegmentSize[32];
extern std::size_t heapSegmentCount;
void initHeapSegments(double n);
inline int find_segment2(std::uintptr_t p, int n)
{ if (p < reinterpret_cast<std::uintptr_t>(heapSegment[n+1])) return n;
 else return n+1;
}
inline int find_segment4(std::uintptr_t p, int n)
{ if (p < reinterpret_cast<std::uintptr_t>(heapSegment[n+2]))
 return find_segment2(p, n);
 else return find_segment2(p, n+2);
}
inline int find_segment8(std::uintptr_t p, int n)
{ if (p < reinterpret_cast<std::uintptr_t>(heapSegment[n+4]))
 return find_segment4(p, n);
 else return find_segment4(p, n+4);
}
inline int find_segment16(std::uintptr_t p, int n)
{ if (p < reinterpret_cast<std::uintptr_t>(heapSegment[n+8]))
 return find_segment8(p, n);
 else return find_segment8(p, n+8);
}
inline int find_segment32(std::uintptr_t p, int n)
{ if (p < reinterpret_cast<std::uintptr_t>(heapSegment[n+16]))
 return find_segment8(p, n);
 else return find_segment16(p, n+16);
}
inline int find_heapSegment(std::uintptr_t p)
{ int n = find_segment32(p, 0);
 if (p < reinterpret_cast<std::uintptr_t>(heapSegment[n]) ||
 p >= reinterpret_cast<std::uintptr_t>(heapSegment[n]) +
 heapSegmentSize[n]) return -1;
 return n;
}
inline Page *findPage(std::uintptr_t p)
{ int n = find_heapSegment(p);
 if (n < 0) return NULL;
 return reinterpret_cast<Page *>(p & -pageSize);
}
inline bool inCurrentPage(std::uintptr_t p)
{ std::uintptr_t n = reinterpret_cast<std::uintptr_t>(currentPage);
 return (p >= n &&
 p < (n + pageSize));
}
inline bool inPreviousPage(std::uintptr_t p)
{ std::uintptr_t n = reinterpret_cast<std::uintptr_t>(previousPage);
 return (p >= n &&
 p < (n + pageSize));
}
#ifdef __GNUC__
inline int nlz(std::uint64_t x)
{ return __builtin_clzll(x); 
}
#else 
inline int nlz(std::uint64_t x)
{ int n = 0;
 if (x <= 0x00000000FFFFFFFFU) {n = n +32; x = x <<32;}
 if (x <= 0x0000FFFFFFFFFFFFU) {n = n +16; x = x <<16;}
 if (x <= 0x00FFFFFFFFFFFFFFU) {n = n + 8; x = x << 8;}
 if (x <= 0x0FFFFFFFFFFFFFFFU) {n = n + 4; x = x << 4;}
 if (x <= 0x3FFFFFFFFFFFFFFFU) {n = n + 2; x = x << 2;}
 if (x <= 0x7FFFFFFFFFFFFFFFU) {n = n + 1;}
 return n;
}
#endif 
#define NLZ_DEFINED 1
static const unsigned int maxThreads = 2; 
declare_thread_local(threadId, uintptr_t);
declare_thread_local(fringe, uintptr_t);
extern std::atomic<std::uintptr_t> limit[maxThreads];
extern std::uintptr_t limitBis[maxThreads];
extern std::uintptr_t fringeBis[maxThreads];
extern std::size_t request[maxThreads];
extern LispObject result[maxThreads];
extern std::size_t gIncrement[maxThreads];
extern std::atomic<std::uintptr_t> gFringe;
extern std::uintptr_t gLimit;
extern std::uintptr_t gNext;
extern std::uintptr_t difficult_n_bytes();
inline Header makePaddingHeader(std::size_t n) 
{ return TAG_HDR_IMMED + (n << (Tw+5)) + TYPE_PADDER;
}
inline Header makeVectorHeader(std::size_t n) 
{ return TAG_HDR_IMMED + (n << (Tw+5)) + TYPE_VEC32;
}
inline std::atomic<std::uintptr_t>& firstWord(std::uintptr_t a)
{ return ((std::atomic<std::uintptr_t> *)a)[0];
}
static const std::size_t CHUNK=16384;
extern std::uintptr_t nFringe, nLimit, nNext;
extern std::uintptr_t get_n_bytes_new(std::size_t n); 
inline LispObject get_n_bytes(std::size_t n)
{
 std::uintptr_t r = fringe::get();
 std::uintptr_t w = limit[threadId::get()].load();
 fringe::set(fringe::get() + n);
 if (fringe::get() <= w) return static_cast<LispObject>(r);
 if (w != 0)
 { std::size_t gap = w - r;
 if (gap != 0) firstWord(r).store(makePaddingHeader(gap));
 r = gFringe.fetch_add(CHUNK+n);
 std::uintptr_t oldFringe = fringe::get() - n;
 fringe::set(r + n);
 std::uint64_t newLimit = fringe::get() + CHUNK;
 if (newLimit <= gLimit)
 {
 limitBis[threadId::get()] = newLimit;
 bool ok = limit[threadId::get()].compare_exchange_strong(w, newLimit);
 if (ok) return static_cast<LispObject>(r);
 }
 gIncrement[threadId::get()] = CHUNK+n;
 fringe::set(oldFringe);
 }
 else
 {
 std::size_t gap = limitBis[threadId::get()] - r;
 if (gap != 0) firstWord(r).store(makePaddingHeader(gap));
 gIncrement[threadId::get()] = 0;
 fringe::set(r);
 }
 fringeBis[threadId::get()] = fringe::get();
 request[threadId::get()] = n;
 return static_cast<LispObject>(difficult_n_bytes());
}
inline void poll()
{ std::uintptr_t w;
 if (fringe::get() > (w = limit[threadId::get()].load()))
 {
 std::size_t gap = w - fringe::get();
 if (gap != 0) firstWord(fringe::get()).store(makePaddingHeader(gap));
 fringeBis[threadId::get()] = fringe::get();
 request[threadId::get()] = 0;
 gIncrement[threadId::get()] = 0;
 (void)difficult_n_bytes();
 }
}
extern std::jmp_buf *buffer_pointer;
extern std::uintptr_t stackBases[maxThreads];
extern std::uintptr_t stackFringes[maxThreads];
template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif 
inline void may_block(F &&action)
{ std::jmp_buf buffer;
 buffer_pointer = &buffer;
 if (setjmp(buffer) == 0)
 { stackFringes[threadId::get()] = reinterpret_cast<std::uintptr_t>(buffer);
 action();
 std::longjmp(buffer, 1);
 }
};
template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif 
inline void withRecordedStack(F &&action)
{ std::jmp_buf buffer;
 buffer_pointer = &buffer;
 if (setjmp(buffer) == 0)
 { stackFringes[threadId::get()] = reinterpret_cast<std::uintptr_t>(buffer);
 action();
 std::longjmp(buffer, 1);
 }
};
extern std::mutex mutexForGc;
extern std::mutex mutexForFreePages;
extern bool gc_started;
extern std::condition_variable cv_for_gc_idling;
extern std::condition_variable cv_for_gc_busy;
extern bool gc_complete;
extern std::condition_variable cv_for_gc_complete;
extern std::atomic<std::uint32_t> activeThreads;
extern bool generationalGarbageCollection;
extern void generationalGarbageCollect();
extern void fullGarbageCollect();
extern void setUpEmptyPage(Page *p);
extern void setVariablesFromPage(Page *p);
extern void saveVariablesToPage(Page *p);
inline void garbageCollectOnBehalfOfAll()
{
 { std::lock_guard<std::mutex> guard(mutexForGc);
 gc_complete = false;
 gc_started = true;
 }
 cv_for_gc_idling.notify_all();
 std::size_t inc = 0;
 for (unsigned int i=0; i<maxThreads; i++)
 { result[i] = nil;
 inc += gIncrement[i];
 gIncrement[i] = 0;
 }
 gFringe = gFringe - inc;
 for (;;)
 { unsigned int pendingCount = 0;
 for (unsigned int i=0; i<maxThreads; i++)
 { size_t n = request[i];
 if (n != 0)
 { uintptr_t f = fringeBis[i];
 uintptr_t l = limitBis[i];
 size_t gap = l - f;
 if (n <= gap)
 { result[i] = fringeBis[i] + TAG_VECTOR;
 request[i] = 0;
 firstWord(result[i]).store(makeVectorHeader(n));
 fringeBis[i] += n;
 gap -= n;
 if (gap != 0)
 firstWord(fringeBis[i]).store(makePaddingHeader(gap));
 }
 else
 { size_t gap1 = gLimit - gFringe;
 if (n+CHUNK < gap1)
 { firstWord(fringeBis[i]).store(makePaddingHeader(gap));
 result[i] = gFringe + TAG_VECTOR;
 request[i] = 0;
 firstWord(result[i]).store(makeVectorHeader(n));
 fringeBis[i] = gFringe + n;
 gFringe = limitBis[i] = limit[i] = fringeBis[i] + CHUNK;
 }
 else
 { while (gNext != 0)
 { gFringe = gNext;
 gLimit = ((std::uintptr_t *)gFringe.load())[0];
 gNext = ((std::uintptr_t *)gFringe.load())[1];
 gap1 = gLimit - gFringe;
 if (n+CHUNK < gap1)
 { firstWord(fringeBis[i]).store(makePaddingHeader(gap));
 result[i] = gFringe + TAG_VECTOR;
 request[i] = 0;
 firstWord(result[i]).store(makeVectorHeader(n));
 fringeBis[i] = gFringe + n;
 gFringe = limitBis[i] = limit[i] = fringeBis[i] + CHUNK;
 break;
 }
 }
 if (gNext == 0) pendingCount++;
 }
 }
 }
 }
 if (pendingCount == 0) break;
 for (unsigned int i=0; i<maxThreads; i++)
 { size_t gap = limitBis[i] - fringeBis[i];
 if (gap != 0)
 firstWord(fringeBis[i]).store(makePaddingHeader(gap));
 }
 size_t gap = gLimit - gFringe;
 if (gap != 0) firstWord(gFringe).store(makePaddingHeader(gap));
 if (!generationalGarbageCollection ||
 !garbage_collection_permitted ||
 previousPage == NULL)
 { if (busyPagesCount >= freePagesCount+mostlyFreePagesCount)
 { std::cout << "@@ full GC needed\n";
 fullGarbageCollect();
 }
 else
 {
 if (previousPage == NULL) busyPages++;
 previousPage = currentPage;
 previousPage->pageHeader.pageClass = previousPageTag; 
 { std::lock_guard<std::mutex> guard(mutexForFreePages);
 if (mostlyFreePages != NULL)
 { currentPage = mostlyFreePages;
 mostlyFreePages = mostlyFreePages->pageHeader.chain;
 mostlyFreePagesCount--;
 }
 else
 { currentPage = freePages;
 freePages = freePages->pageHeader.chain;
 freePagesCount--;
 }
 }
 currentPage->pageHeader.pageClass = currentPageTag;
 currentPage->pageHeader.chain = busyPages;
 busyPages = currentPage;
 busyPagesCount++;
 uintptr_t pFringe = currentPage->pageHeader.fringe;
 uintptr_t pLimit = currentPage->pageHeader.heaplimit;
 gFringe = pFringe;
 gLimit = pLimit;
 for (unsigned int k=0; k<maxThreads; k++)
 limit[k] = fringeBis[k] = limitBis[k] = gFringe;
 gNext = 0;
 }
 }
 else
 { std::cout << "@@ minor GC needed\n";
 generationalGarbageCollect();
 }
 }
 { std::unique_lock<std::mutex> lock(mutexForGc);
 cv_for_gc_busy.wait(lock,
 []{ std::uint32_t n = activeThreads.load();
 return (n & 0xff) == ((n>>8) & 0xff) - 1;
 });
 }
 { std::lock_guard<std::mutex> guard(mutexForGc);
 gc_started = false;
 activeThreads.fetch_add(0x0000001);
 gc_complete = true;
 }
 cv_for_gc_complete.notify_all();
}
inline void waitWhileAnotherThreadGarbageCollects()
{
 { std::unique_lock<std::mutex> lock(mutexForGc);
 cv_for_gc_idling.wait(lock, []{ return gc_started; });
 }
 bool inform = false;
 { std::lock_guard<std::mutex> guard(mutexForGc);
 std::uint32_t n = activeThreads.fetch_add(0x000001);
 if ((n & 0xff) == ((n>>8) & 0xff) - 2) inform = true;
 }
 if (inform) cv_for_gc_busy.notify_one();
 { std::unique_lock<std::mutex> lock(mutexForGc);
 cv_for_gc_complete.wait(lock, []{ return gc_complete; });
 }
 fringe::set(fringeBis[threadId::get()]);
}
inline std::uintptr_t difficult_n_bytes()
{
 withRecordedStack([&]
 {
 std::int32_t a = activeThreads.fetch_sub(0x000001);
 if ((a & 0xff) > 1) waitWhileAnotherThreadGarbageCollects();
 else garbageCollectOnBehalfOfAll();
 });
 fringe::set(fringeBis[threadId::get()]);
 return result[threadId::get()] - TAG_VECTOR;
}
extern LispObject Lgctest_0(LispObject);
extern LispObject Lgctest_1(LispObject, LispObject);
extern LispObject Lgctest_2(LispObject, LispObject, LispObject);
inline LispObject cons(LispObject a, LispObject b)
{ LispObject r = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
 setcar(r, a);
 setcdr(r, b);
 return r;
}
inline LispObject cons_no_gc(LispObject a, LispObject b)
{ return cons(a, b);
}
inline LispObject cons_gc_test(LispObject p)
{ return p;
}
inline LispObject ncons(LispObject a)
{ LispObject r = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
 setcar(r, a);
 setcdr(r, nil);
 return r;
}
inline LispObject list2(LispObject a, LispObject b)
{ LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 setcar(r1, a);
 setcar(r2, b);
 setcdr(r1, r2);
 setcdr(r2, nil);
 return r1;
}
inline LispObject list2star(LispObject a, LispObject b, LispObject c)
{ LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 setcar(r1, a);
 setcar(r2, b);
 setcdr(r1, r2);
 setcdr(r2, c);
 return r1;
}
inline LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{ LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 setcar(r1, a);
 setcar(r2, b);
 setcdr(r1, r2);
 setcdr(r2, c);
 return r1;
}
inline LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{ LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 LispObject r3 = r1 + 4*sizeof(LispObject);
 setcar(r1, a);
 setcar(r2, b);
 setcar(r3, c);
 setcdr(r1, r2);
 setcdr(r2, r3);
 setcdr(r3, d);
 return r1;
}
inline LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{ LispObject r1 = get_n_bytes(8*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 LispObject r3 = r1 + 4*sizeof(LispObject);
 LispObject r4 = r1 + 6*sizeof(LispObject);
 setcar(r1, a);
 setcar(r2, b);
 setcar(r3, c);
 setcar(r4, d);
 setcdr(r1, r2);
 setcdr(r2, r3);
 setcdr(r3, r4);
 setcdr(r4, nil);
 return r1;
}
inline LispObject acons(LispObject a, LispObject b, LispObject c)
{ LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 setcar(r1, r2);
 setcar(r2, a);
 setcdr(r1, c);
 setcdr(r2, b);
 return r1;
}
inline LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{ return acons(a, b, c);
}
inline LispObject list3(LispObject a, LispObject b, LispObject c)
{ LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 LispObject r3 = r1 + 4*sizeof(LispObject);
 setcar(r1, a);
 setcar(r2, b);
 setcar(r3, c);
 setcdr(r1, r2);
 setcdr(r2, r3);
 setcdr(r3, nil);
 return r1;
}
inline LispObject list3rev(LispObject c, LispObject b, LispObject a)
{ LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
 LispObject r2 = r1 + 2*sizeof(LispObject);
 LispObject r3 = r1 + 4*sizeof(LispObject);
 setcar(r1, a);
 setcar(r2, b);
 setcar(r3, c);
 setcdr(r1, r2);
 setcdr(r2, r3);
 setcdr(r3, nil);
 return r1;
}
inline LispObject Lcons(LispObject, LispObject a, LispObject b)
{ LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
 setcar(r1, a);
 setcdr(r1, b);
 return onevalue(r1);
}
inline LispObject Lxcons(LispObject, LispObject a, LispObject b)
{ LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
 setcar(r1, b);
 setcdr(r1, a);
 return onevalue(r1);
}
inline LispObject Lnilfn(LispObject)
{ return onevalue(nil);
}
inline LispObject Lncons(LispObject env, LispObject a)
{ LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
 setcar(r1, a);
 setcdr(r1, nil);
 return onevalue(r1);
}
extern void garbageCollect();
void allocate_segment(std::size_t n);
extern void clearPinnedMap(Page *x);
extern std::uint64_t threadBit(unsigned int n);
extern void setPinnedMajor(std::uintptr_t p);
declare_thread_local(borrowPages, Page *);
declare_thread_local(borrowFringe, std::uintptr_t);
declare_thread_local(borrowLimit, std::uintptr_t);
declare_thread_local(borrowNext, std::uintptr_t);
class Borrowing
{
public:
 Borrowing()
 { borrowPages::set(NULL);
 borrowFringe::set(0);
 borrowLimit::set(0);
 borrowNext::set(0);
 }
 ~Borrowing()
 { std::lock_guard<std::mutex> lock(mutexForFreePages);
 while (borrowPages::get() != NULL)
 { if (borrowPages::get()->pageHeader.pageClass == mostlyFreePageTag)
 { Page *w = borrowPages::get()->pageHeader.chain;
 borrowPages::get()->pageHeader.chain = mostlyFreePages;
 mostlyFreePages = borrowPages::get();
 borrowPages::set(w);
 }
 else
 { Page *w = borrowPages::get()->pageHeader.chain;
 borrowPages::get()->pageHeader.chain = freePages;
 freePages = borrowPages::get();
 borrowPages::set(w);
 }
 }
 }
};
#endif 
#else // CONSERVATIVE
#ifndef header_allocate_h
#define header_allocate_h 1
#if defined THREAD_LOCAL
inline thread_local std::uintptr_t fringe;
inline thread_local std::uintptr_t heaplimit;
inline thread_local std::uintptr_t vfringe;
inline thread_local std::uintptr_t vheaplimit;
#elif defined WINDOWS_THREADS && defined WIN32
const inline int fringe_slot = TlsAlloc();
const inline int heaplimit_slot = TlsAlloc();
const inline int vfringe_slot = TlsAlloc();
const inline int vheaplimit_slot = TlsAlloc();
inline thread_local std::atomic<std::uintptr_t> real_heaplimit;
inline thread_local std::atomic<std::uintptr_t> real_vheaplimit;
class ForFringe
{
public:
 operator std::uintptr_t()
 { return (std::uintptr_t)TlsGetValue(fringe_slot);
 };
 ForFringe& operator= (const std::uintptr_t a)
 { TlsSetValue(fringe_slot, (void *)a);
 return *this;
 };
 ForFringe& operator+= (const std::size_t a)
 { std::uintptr_t v = (std::uintptr_t)TlsGetValue(fringe_slot) + a;
 TlsSetValue(fringe_slot, (void *)v);
 return *this;
 };
};
inline ForFringe fringe;
class ForHeapLimit
{
public:
 operator std::uintptr_t()
 { return *(std::atomic<std::uintptr_t> *)TlsGetValue(heaplimit_slot);
 };
 ForHeapLimit& operator= (const std::uintptr_t a)
 { TlsSetValue(heaplimit_slot, (void *)a);
 return *this;
 };
 ForHeapLimit()
 { TlsSetValue(heaplimit_slot, (void *)&real_heaplimit);
 };
};
inline ForHeapLimit heaplimit;
class ForVFringe
{
public:
 operator std::uintptr_t()
 { return (std::uintptr_t)TlsGetValue(vfringe_slot);
 };
 ForVFringe& operator= (const std::uintptr_t a)
 { TlsSetValue(vfringe_slot, (void *)a);
 return *this;
 };
 ForVFringe& operator+= (const std::size_t a)
 { std::uintptr_t v = (std::uintptr_t)TlsGetValue(vfringe_slot) + a;
 TlsSetValue(vfringe_slot, (void *)v);
 return *this;
 };
};
inline ForVFringe vfringe;
class ForVHeapLimit
{
public:
 operator std::uintptr_t()
 { return *(std::atomic<std::uintptr_t> *)TlsGetValue(vheaplimit_slot);
 };
 ForVHeapLimit& operator= (const std::uintptr_t a)
 { TlsSetValue(vheaplimit_slot, (void *)a);
 return *this;
 };
 ForVHeapLimit()
 { TlsSetValue(vheaplimit_slot, (void *)&real_heaplimit);
 };
};
inline ForVHeapLimit vheaplimit;
#elif defined ATOMIC
inline std::atomic<std::uintptr_t> fringe;
inline std::atomic<std::uintptr_t> heaplimit;
inline std::atomic<std::uintptr_t> vfringe;
inline std::atomic<std::uintptr_t> vheaplimit;
#else
extern std::uintptr_t fringe;
extern std::uintptr_t heaplimit;
extern std::uintptr_t vfringe;
extern std::uintptr_t vheaplimit;
#endif
#define MIN_PAGE_SIZE 0x01000
#define MAX_PAGE_SIZE 0x10000
extern void get_page_size();
extern std::size_t page_size;
extern void set_up_signal_handlers();
extern void *allocate_segment(std::size_t);
extern std::size_t heap_segment_count;
extern void *heap_segment[32];
extern std::size_t heap_segment_size[32];
extern std::uint64_t *heap_dirty_pages_bitmap_1[32];
extern std::uint64_t *heap_dirty_pages_bitmap_2[32];
extern std::size_t free_pages_count, active_pages_count;
#define SMALL_BITMAP_SIZE (MAX_PAGE_SIZE/sizeof(uint64_t)/2)
extern std::uint64_t heap_small_bitmaps_1[SMALL_BITMAP_SIZE+1];
extern std::uint64_t *heap_small_bitmaps_1_ptr;
extern std::uint64_t heap_small_bitmaps_2[SMALL_BITMAP_SIZE+1];
extern std::uint64_t *heap_small_bitmaps_2_ptr;
int find_heap_segment(std::uintptr_t p);
extern bool clear_bitmap(std::size_t h);
extern bool refresh_bitmap(std::size_t h);
extern void garbage_collect();
extern std::size_t borrowed_pages_count;
extern void get_borrowed_page();
class Borrowing
{
public:
 Borrowing()
 { borrowed_pages_count = pages_count;
 get_borrowed_page();
 }
};
#endif 
#endif // CONSERVATIVE


// Code for xquotient!-mod!-p

static LispObject CC_xquotientKmodKp(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_134, v_135, v_136;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_134 = stack[-2];
    if (v_134 == nil) goto v_8;
    else goto v_9;
v_8:
    v_134 = nil;
    goto v_7;
v_9:
    v_134 = stack[-2];
    if (!consp(v_134)) goto v_20;
    else goto v_21;
v_20:
    v_134 = lisp_true;
    goto v_19;
v_21:
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    v_134 = (consp(v_134) ? nil : lisp_true);
    goto v_19;
    v_134 = nil;
v_19:
    if (v_134 == nil) goto v_17;
    v_134 = lisp_true;
    goto v_15;
v_17:
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_135 = carerror(v_134); else
    v_135 = car(v_134);
    v_134 = stack[0];
    if (equal(v_135, v_134)) goto v_35;
    v_134 = lisp_true;
    goto v_33;
v_35:
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_135 = cdrerror(v_134); else
    v_135 = cdr(v_134);
    v_134 = stack[-1];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = cdrerror(v_134); else
    v_134 = cdr(v_134);
    v_134 = ((std::intptr_t)v_135 < (std::intptr_t)v_134) ? lisp_true : nil;
    goto v_33;
    v_134 = nil;
v_33:
    goto v_15;
    v_134 = nil;
v_15:
    if (v_134 == nil) goto v_13;
    v_134 = nil;
    setvalue(basic_elt(env, 1), v_134); // exact!-quotient!-flag
    goto v_7;
v_13:
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_135 = cdrerror(v_134); else
    v_135 = cdr(v_134);
    v_134 = stack[-1];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = cdrerror(v_134); else
    v_134 = cdr(v_134);
    if (equal(v_135, v_134)) goto v_54;
    else goto v_55;
v_54:
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_135 = cdrerror(v_134); else
    v_135 = cdr(v_134);
    v_134 = stack[-1];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = cdrerror(v_134); else
    v_134 = cdr(v_134);
    {   LispObject fn = basic_elt(env, 2); // quotient!-mod!-p
    v_134 = (*qfn2(fn))(fn, v_135, v_134);
    }
    env = stack[-4];
    stack[0] = v_134;
    v_134 = stack[0];
    if (v_134 == nil) goto v_80;
    else goto v_81;
v_80:
    v_134 = lisp_true;
    goto v_79;
v_81:
    v_135 = stack[0];
    v_134 = stack[-1];
    {   LispObject fn = basic_elt(env, 3); // times!-mod!-p
    v_134 = (*qfn2(fn))(fn, v_135, v_134);
    }
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 4); // difference!-mod!-p
    v_134 = (*qfn2(fn))(fn, stack[-2], v_134);
    }
    env = stack[-4];
    goto v_79;
    v_134 = nil;
v_79:
    if (v_134 == nil) goto v_77;
    v_134 = nil;
    setvalue(basic_elt(env, 1), v_134); // exact!-quotient!-flag
    goto v_75;
v_77:
v_75:
    v_134 = stack[0];
    goto v_7;
v_55:
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_136 = carerror(v_134); else
    v_136 = car(v_134);
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_135 = cdrerror(v_134); else
    v_135 = cdr(v_134);
    v_134 = stack[-1];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = cdrerror(v_134); else
    v_134 = cdr(v_134);
    v_134 = (LispObject)(std::intptr_t)((std::intptr_t)v_135 - (std::intptr_t)v_134 + TAG_FIXNUM);
    {   LispObject fn = basic_elt(env, 5); // mksp
    stack[-3] = (*qfn2(fn))(fn, v_136, v_134);
    }
    env = stack[-4];
    v_134 = stack[-2];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_135 = cdrerror(v_134); else
    v_135 = cdr(v_134);
    v_134 = stack[-1];
    if (!car_legal(v_134)) v_134 = carerror(v_134); else
    v_134 = car(v_134);
    if (!car_legal(v_134)) v_134 = cdrerror(v_134); else
    v_134 = cdr(v_134);
    {   LispObject fn = basic_elt(env, 2); // quotient!-mod!-p
    v_134 = (*qfn2(fn))(fn, v_135, v_134);
    }
    env = stack[-4];
    v_134 = cons(stack[-3], v_134);
    env = stack[-4];
    stack[-3] = v_134;
    v_134 = stack[-2];
    if (!car_legal(v_134)) stack[-2] = cdrerror(v_134); else
    stack[-2] = cdr(v_134);
    v_134 = stack[-3];
    {   LispObject fn = basic_elt(env, 6); // negate!-term
    v_135 = (*qfn1(fn))(fn, v_134);
    }
    env = stack[-4];
    v_134 = stack[-1];
    if (!car_legal(v_134)) v_134 = cdrerror(v_134); else
    v_134 = cdr(v_134);
    {   LispObject fn = basic_elt(env, 7); // times!-term!-mod!-p
    v_134 = (*qfn2(fn))(fn, v_135, v_134);
    }
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // plus!-mod!-p
    v_134 = (*qfn2(fn))(fn, stack[-2], v_134);
    }
    env = stack[-4];
    stack[-2] = v_134;
    v_136 = stack[-2];
    v_135 = stack[-1];
    v_134 = stack[0];
    {   LispObject fn = basic_elt(env, 0); // xquotient!-mod!-p
    v_134 = (*qfn3(fn))(fn, v_136, v_135, v_134);
    }
    {
        LispObject v_141 = stack[-3];
        return cons(v_141, v_134);
    }
    goto v_7;
    v_134 = nil;
v_7:
    return onevalue(v_134);
}



// Code for mkcrn

static LispObject CC_mkcrn(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_3;
    v_10 = v_2;
// end of prologue
    v_11 = basic_elt(env, 1); // !:crn!:
    return list2star(v_11, v_10, v_9);
}



// Code for extadd

static LispObject CC_extadd(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_113, v_114;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
    v_113 = stack[-3];
    if (v_113 == nil) goto v_7;
    else goto v_8;
v_7:
    v_113 = stack[-2];
    goto v_6;
v_8:
    v_113 = stack[-2];
    if (v_113 == nil) goto v_11;
    else goto v_12;
v_11:
    v_113 = stack[-3];
    goto v_6;
v_12:
    v_113 = nil;
    v_113 = ncons(v_113);
    env = stack[-5];
    stack[-1] = v_113;
    stack[-4] = v_113;
v_26:
    v_113 = stack[-3];
    if (v_113 == nil) goto v_29;
    v_113 = stack[-2];
    if (v_113 == nil) goto v_29;
    goto v_30;
v_29:
    goto v_25;
v_30:
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    if (!car_legal(v_113)) v_114 = carerror(v_113); else
    v_114 = car(v_113);
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    if (equal(v_114, v_113)) goto v_38;
    else goto v_39;
v_38:
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    if (!car_legal(v_113)) v_114 = cdrerror(v_113); else
    v_114 = cdr(v_113);
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    {   LispObject fn = basic_elt(env, 1); // addf
    v_114 = (*qfn2(fn))(fn, v_114, v_113);
    }
    env = stack[-5];
    v_113 = v_114;
    if (v_114 == nil) goto v_49;
    stack[0] = stack[-1];
    v_114 = stack[-3];
    if (!car_legal(v_114)) v_114 = carerror(v_114); else
    v_114 = car(v_114);
    if (!car_legal(v_114)) v_114 = carerror(v_114); else
    v_114 = car(v_114);
    v_113 = cons(v_114, v_113);
    env = stack[-5];
    v_113 = ncons(v_113);
    env = stack[-5];
    {   LispObject fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, stack[0], v_113);
    }
    env = stack[-5];
    v_113 = stack[-1];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    stack[-1] = v_113;
    goto v_47;
v_49:
v_47:
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    stack[-3] = v_113;
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    stack[-2] = v_113;
    goto v_37;
v_39:
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    if (!car_legal(v_113)) v_114 = carerror(v_113); else
    v_114 = car(v_113);
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    {   LispObject fn = basic_elt(env, 3); // ordexp
    v_113 = (*qfn2(fn))(fn, v_114, v_113);
    }
    env = stack[-5];
    if (v_113 == nil) goto v_72;
    stack[0] = stack[-1];
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    v_113 = ncons(v_113);
    env = stack[-5];
    {   LispObject fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, stack[0], v_113);
    }
    env = stack[-5];
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    stack[-2] = v_113;
    v_113 = stack[-1];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    stack[-1] = v_113;
    goto v_37;
v_72:
    stack[0] = stack[-1];
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = car(v_113);
    v_113 = ncons(v_113);
    env = stack[-5];
    {   LispObject fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, stack[0], v_113);
    }
    env = stack[-5];
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    stack[-3] = v_113;
    v_113 = stack[-1];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    stack[-1] = v_113;
    goto v_37;
v_37:
    goto v_26;
v_25:
    v_114 = stack[-1];
    v_113 = stack[-3];
    if (v_113 == nil) goto v_105;
    v_113 = stack[-3];
    goto v_103;
v_105:
    v_113 = stack[-2];
    goto v_103;
    v_113 = nil;
v_103:
    {   LispObject fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, v_114, v_113);
    }
    v_113 = stack[-4];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = cdr(v_113);
    goto v_6;
    v_113 = nil;
v_6:
    return onevalue(v_113);
}



// Code for read!-comment1

static LispObject CC_readKcomment1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_48, v_49;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_48 = v_2;
// end of prologue
// Binding !*lower
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    setvalue(basic_elt(env, 1), nil); // !*lower
// Binding !*raise
// FLUIDBIND: reloadenv=2 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-2, 2, 0);
    setvalue(basic_elt(env, 2), nil); // !*raise
    v_48 = nil;
    setvalue(basic_elt(env, 3), v_48); // named!-character!*
v_10:
    v_48 = qvalue(basic_elt(env, 3)); // named!-character!*
    if (v_48 == nil) goto v_16;
    else goto v_14;
v_16:
    v_48 = qvalue(basic_elt(env, 4)); // crchar!*
    {   LispObject fn = basic_elt(env, 7); // id2string
    v_48 = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 8); // string!-length
    v_49 = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-2];
    v_48 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_49 == v_48) goto v_22;
    v_48 = lisp_true;
    goto v_20;
v_22:
    v_48 = qvalue(basic_elt(env, 4)); // crchar!*
    {   LispObject fn = basic_elt(env, 9); // delcp
    v_48 = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-2];
    if (v_48 == nil) goto v_32;
    else goto v_33;
v_32:
    v_48 = lisp_true;
    goto v_31;
v_33:
    v_49 = qvalue(basic_elt(env, 4)); // crchar!*
    v_48 = qvalue(basic_elt(env, 5)); // !$eol!$
    v_48 = (v_49 == v_48 ? lisp_true : nil);
    goto v_31;
    v_48 = nil;
v_31:
    goto v_20;
    v_48 = nil;
v_20:
    if (v_48 == nil) goto v_18;
    else goto v_14;
v_18:
    goto v_15;
v_14:
    v_48 = nil;
    setvalue(basic_elt(env, 3), v_48); // named!-character!*
    {   LispObject fn = basic_elt(env, 10); // readch1
    v_48 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    setvalue(basic_elt(env, 4), v_48); // crchar!*
    goto v_10;
v_15:
    v_48 = basic_elt(env, 6); // ! 
    setvalue(basic_elt(env, 4), v_48); // crchar!*
    {   LispObject fn = basic_elt(env, 11); // condterpri
    v_48 = (*qfn0(fn))(fn);
    }
    v_48 = nil;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_48);
}



// Code for sfto_yun!-updecf

static LispObject CC_sfto_yunKupdecf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_94, v_95;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_2;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    setvalue(basic_elt(env, 1), nil); // !*gcd
    stack[-1] = nil;
    v_94 = lisp_true;
    setvalue(basic_elt(env, 1), v_94); // !*gcd
    v_95 = (LispObject)16+TAG_FIXNUM; // 1
    v_94 = (LispObject)16+TAG_FIXNUM; // 1
    v_94 = cons(v_95, v_94);
    env = stack[-8];
    stack[-2] = v_94;
    v_94 = stack[-6];
    if (!car_legal(v_94)) v_94 = carerror(v_94); else
    v_94 = car(v_94);
    if (!car_legal(v_94)) v_94 = carerror(v_94); else
    v_94 = car(v_94);
    if (!car_legal(v_94)) v_94 = carerror(v_94); else
    v_94 = car(v_94);
    stack[-5] = v_94;
    stack[-3] = stack[-6];
    v_95 = stack[-6];
    v_94 = stack[-5];
    {   LispObject fn = basic_elt(env, 2); // diff
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    stack[0] = v_94;
    {   LispObject fn = basic_elt(env, 3); // sfto_gcdf
    v_94 = (*qfn2(fn))(fn, stack[-3], v_94);
    }
    env = stack[-8];
    stack[-3] = v_94;
    v_95 = stack[-6];
    v_94 = stack[-3];
    {   LispObject fn = basic_elt(env, 4); // quotf
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    stack[-4] = v_94;
    v_95 = stack[0];
    v_94 = stack[-3];
    {   LispObject fn = basic_elt(env, 4); // quotf
    stack[0] = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    v_95 = stack[-4];
    v_94 = stack[-5];
    {   LispObject fn = basic_elt(env, 2); // diff
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 5); // negf
    v_94 = (*qfn1(fn))(fn, v_94);
    }
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 6); // addf
    v_94 = (*qfn2(fn))(fn, stack[0], v_94);
    }
    env = stack[-8];
    stack[-3] = v_94;
v_41:
    v_94 = stack[-1];
    v_94 = (v_94 == nil ? lisp_true : nil);
    stack[-1] = v_94;
    v_95 = stack[-4];
    v_94 = stack[-3];
    {   LispObject fn = basic_elt(env, 3); // sfto_gcdf
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    stack[-6] = v_94;
    v_94 = stack[-1];
    if (v_94 == nil) goto v_50;
    stack[0] = stack[-2];
    v_94 = stack[-2];
    if (!car_legal(v_94)) v_95 = carerror(v_94); else
    v_95 = car(v_94);
    v_94 = stack[-6];
    {   LispObject fn = basic_elt(env, 7); // multf
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 8); // setcar
    v_94 = (*qfn2(fn))(fn, stack[0], v_94);
    }
    env = stack[-8];
    goto v_48;
v_50:
    stack[0] = stack[-2];
    v_94 = stack[-2];
    if (!car_legal(v_94)) v_95 = cdrerror(v_94); else
    v_95 = cdr(v_94);
    v_94 = stack[-6];
    {   LispObject fn = basic_elt(env, 7); // multf
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 9); // setcdr
    v_94 = (*qfn2(fn))(fn, stack[0], v_94);
    }
    env = stack[-8];
    goto v_48;
v_48:
    v_95 = stack[-4];
    v_94 = stack[-6];
    {   LispObject fn = basic_elt(env, 4); // quotf
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    stack[-4] = v_94;
    v_95 = stack[-3];
    v_94 = stack[-6];
    {   LispObject fn = basic_elt(env, 4); // quotf
    stack[0] = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    v_95 = stack[-4];
    v_94 = stack[-5];
    {   LispObject fn = basic_elt(env, 2); // diff
    v_94 = (*qfn2(fn))(fn, v_95, v_94);
    }
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 5); // negf
    v_94 = (*qfn1(fn))(fn, v_94);
    }
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 6); // addf
    v_94 = (*qfn2(fn))(fn, stack[0], v_94);
    }
    env = stack[-8];
    stack[-3] = v_94;
    v_94 = stack[-4];
    if (!consp(v_94)) goto v_83;
    else goto v_84;
v_83:
    v_94 = lisp_true;
    goto v_82;
v_84:
    v_94 = stack[-4];
    if (!car_legal(v_94)) v_94 = carerror(v_94); else
    v_94 = car(v_94);
    v_94 = (consp(v_94) ? nil : lisp_true);
    goto v_82;
    v_94 = nil;
v_82:
    if (v_94 == nil) goto v_79;
    else goto v_80;
v_79:
    goto v_41;
v_80:
    v_94 = stack[-2];
    ;}  // end of a binding scope
    return onevalue(v_94);
}



// Code for rl_identity1

static LispObject CC_rl_identity1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    return onevalue(v_5);
}



// Code for pasf_anegateat

static LispObject CC_pasf_anegateat(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_125, v_126;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2;
// end of prologue
    v_126 = stack[-1];
    v_125 = basic_elt(env, 1); // true
    if (v_126 == v_125) goto v_14;
    else goto v_15;
v_14:
    v_125 = lisp_true;
    goto v_13;
v_15:
    v_126 = stack[-1];
    v_125 = basic_elt(env, 2); // false
    v_125 = (v_126 == v_125 ? lisp_true : nil);
    goto v_13;
    v_125 = nil;
v_13:
    if (v_125 == nil) goto v_11;
    v_125 = stack[-1];
    v_126 = v_125;
    goto v_9;
v_11:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    v_125 = Lconsp(nil, v_125);
    env = stack[-3];
    if (v_125 == nil) goto v_26;
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    v_126 = v_125;
    goto v_9;
v_26:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    v_126 = v_125;
    goto v_9;
    v_126 = nil;
v_9:
    v_125 = basic_elt(env, 3); // (cong ncong)
    v_125 = Lmemq(nil, v_126, v_125);
    if (v_125 == nil) goto v_7;
    v_126 = stack[-1];
    v_125 = basic_elt(env, 1); // true
    if (v_126 == v_125) goto v_48;
    else goto v_49;
v_48:
    v_125 = lisp_true;
    goto v_47;
v_49:
    v_126 = stack[-1];
    v_125 = basic_elt(env, 2); // false
    v_125 = (v_126 == v_125 ? lisp_true : nil);
    goto v_47;
    v_125 = nil;
v_47:
    if (v_125 == nil) goto v_45;
    v_125 = stack[-1];
    goto v_43;
v_45:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    v_125 = Lconsp(nil, v_125);
    env = stack[-3];
    if (v_125 == nil) goto v_60;
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    goto v_43;
v_60:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    goto v_43;
    v_125 = nil;
v_43:
    {   LispObject fn = basic_elt(env, 4); // pasf_anegrel
    v_126 = (*qfn1(fn))(fn, v_125);
    }
    env = stack[-3];
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    {   LispObject fn = basic_elt(env, 5); // pasf_mkop
    stack[-2] = (*qfn2(fn))(fn, v_126, v_125);
    }
    env = stack[-3];
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    {   LispObject fn = basic_elt(env, 6); // negf
    stack[0] = (*qfn1(fn))(fn, v_125);
    }
    env = stack[-3];
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    {   LispObject fn = basic_elt(env, 6); // negf
    v_125 = (*qfn1(fn))(fn, v_125);
    }
    {
        LispObject v_130 = stack[-2];
        LispObject v_131 = stack[0];
        return list3(v_130, v_131, v_125);
    }
v_7:
    v_126 = stack[-1];
    v_125 = basic_elt(env, 1); // true
    if (v_126 == v_125) goto v_93;
    else goto v_94;
v_93:
    v_125 = lisp_true;
    goto v_92;
v_94:
    v_126 = stack[-1];
    v_125 = basic_elt(env, 2); // false
    v_125 = (v_126 == v_125 ? lisp_true : nil);
    goto v_92;
    v_125 = nil;
v_92:
    if (v_125 == nil) goto v_90;
    v_125 = stack[-1];
    goto v_88;
v_90:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    v_125 = Lconsp(nil, v_125);
    env = stack[-3];
    if (v_125 == nil) goto v_105;
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    goto v_88;
v_105:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    goto v_88;
    v_125 = nil;
v_88:
    {   LispObject fn = basic_elt(env, 4); // pasf_anegrel
    stack[-2] = (*qfn1(fn))(fn, v_125);
    }
    env = stack[-3];
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    {   LispObject fn = basic_elt(env, 6); // negf
    stack[0] = (*qfn1(fn))(fn, v_125);
    }
    env = stack[-3];
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    {   LispObject fn = basic_elt(env, 6); // negf
    v_125 = (*qfn1(fn))(fn, v_125);
    }
    {
        LispObject v_132 = stack[-2];
        LispObject v_133 = stack[0];
        return list3(v_132, v_133, v_125);
    }
    v_125 = nil;
    return onevalue(v_125);
}



// Code for bc_sum

static LispObject CC_bc_sum(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_64, v_65, v_66, v_67;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_66 = v_3;
    v_67 = v_2;
// end of prologue
    v_64 = v_67;
    if (!car_legal(v_64)) v_65 = cdrerror(v_64); else
    v_65 = cdr(v_64);
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_65 == v_64) goto v_11;
    else goto v_12;
v_11:
    v_64 = v_67;
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    if (is_number(v_64)) goto v_19;
    v_64 = nil;
    goto v_17;
v_19:
    v_64 = v_66;
    if (!car_legal(v_64)) v_65 = cdrerror(v_64); else
    v_65 = cdr(v_64);
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_65 == v_64) goto v_27;
    else goto v_28;
v_27:
    v_64 = v_66;
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    v_64 = (is_number(v_64) ? lisp_true : nil);
    goto v_26;
v_28:
    v_64 = nil;
    goto v_26;
    v_64 = nil;
v_26:
    goto v_17;
    v_64 = nil;
v_17:
    goto v_10;
v_12:
    v_64 = nil;
    goto v_10;
    v_64 = nil;
v_10:
    if (v_64 == nil) goto v_8;
    v_64 = v_67;
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    v_65 = v_66;
    if (!car_legal(v_65)) v_65 = carerror(v_65); else
    v_65 = car(v_65);
    v_65 = plus2(v_64, v_65);
    v_67 = v_65;
    v_64 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_65 == v_64) goto v_43;
    else goto v_44;
v_43:
    v_65 = nil;
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_65, v_64);
v_44:
    v_65 = v_67;
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_65, v_64);
    v_64 = nil;
    goto v_6;
v_8:
    v_64 = v_67;
    v_65 = v_66;
    {
        LispObject fn = basic_elt(env, 1); // addsq
        return (*qfn2(fn))(fn, v_64, v_65);
    }
    v_64 = nil;
v_6:
    return onevalue(v_64);
}



// Code for ciom

static LispObject CC_ciom(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_55, v_56;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_55 = basic_elt(env, 1); // "<OMATTR>"
    {   LispObject fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = lisp_true;
    {   LispObject fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = basic_elt(env, 2); // "<OMATP>"
    {   LispObject fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = lisp_true;
    {   LispObject fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = basic_elt(env, 3); // "<OMS cd=""typmml"" name=""type"">"
    {   LispObject fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = basic_elt(env, 4); // "<OMS cd=""typmml"" name="""
    {   LispObject fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = stack[0];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    v_56 = Lintern(nil, v_55);
    env = stack[-1];
    v_55 = qvalue(basic_elt(env, 5)); // mmltypes!*
    v_55 = Lassoc(nil, v_56, v_55);
    v_55 = Lprinc(nil, v_55);
    env = stack[-1];
    v_55 = stack[0];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    v_56 = Lintern(nil, v_55);
    env = stack[-1];
    v_55 = qvalue(basic_elt(env, 5)); // mmltypes!*
    v_55 = Lassoc(nil, v_56, v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    v_55 = Lprinc(nil, v_55);
    env = stack[-1];
    v_55 = basic_elt(env, 6); // """>"
    v_55 = Lprinc(nil, v_55);
    env = stack[-1];
    v_55 = nil;
    {   LispObject fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = basic_elt(env, 7); // "</OMATP>"
    {   LispObject fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = stack[0];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    {   LispObject fn = basic_elt(env, 11); // objectom
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = nil;
    {   LispObject fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    env = stack[-1];
    v_55 = basic_elt(env, 8); // "</OMATTR>"
    {   LispObject fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    }
    v_55 = nil;
    return onevalue(v_55);
}



// Code for f4

static LispObject CC_f4(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_200, v_201;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_201 = stack[0];
    v_200 = basic_elt(env, 1); // pi
    if (v_201 == v_200) goto v_8;
    else goto v_9;
v_8:
    v_200 = basic_elt(env, 2); // "<pi/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_9:
    v_201 = stack[0];
    v_200 = basic_elt(env, 3); // euler_gamma
    if (v_201 == v_200) goto v_14;
    else goto v_15;
v_14:
    v_200 = basic_elt(env, 4); // "<eulergamma/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_15:
    v_201 = stack[0];
    v_200 = basic_elt(env, 5); // true
    if (v_201 == v_200) goto v_20;
    else goto v_21;
v_20:
    v_200 = basic_elt(env, 6); // "<true/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_21:
    v_201 = stack[0];
    v_200 = basic_elt(env, 7); // false
    if (v_201 == v_200) goto v_26;
    else goto v_27;
v_26:
    v_200 = basic_elt(env, 8); // "<false/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_27:
    v_201 = stack[0];
    v_200 = basic_elt(env, 9); // !Na!N
    if (v_201 == v_200) goto v_32;
    else goto v_33;
v_32:
    v_200 = basic_elt(env, 10); // "<notanumber/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_33:
    v_201 = stack[0];
    v_200 = basic_elt(env, 11); // infinity
    if (v_201 == v_200) goto v_38;
    else goto v_39;
v_38:
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_44;
    else goto v_45;
v_44:
    v_200 = basic_elt(env, 13); // "<cn type=""constant"">"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    goto v_43;
v_45:
    v_200 = basic_elt(env, 14); // "<cn type=&quot;constant&quot;>"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    goto v_43;
v_43:
    v_200 = basic_elt(env, 15); // "&infin;"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_39:
    v_201 = stack[0];
    v_200 = basic_elt(env, 17); // e
    if (v_201 == v_200) goto v_61;
    else goto v_62;
v_61:
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_67;
    else goto v_68;
v_67:
    v_200 = basic_elt(env, 13); // "<cn type=""constant"">"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    goto v_66;
v_68:
    v_200 = basic_elt(env, 14); // "<cn type=&quot;constant&quot;>"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    goto v_66;
v_66:
    v_200 = basic_elt(env, 18); // "&ExponentialE;"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    goto v_60;
v_62:
    v_201 = stack[0];
    v_200 = basic_elt(env, 19); // i
    if (v_201 == v_200) goto v_84;
    else goto v_85;
v_84:
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_90;
    else goto v_91;
v_90:
    v_200 = basic_elt(env, 13); // "<cn type=""constant"">"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    goto v_89;
v_91:
    v_200 = basic_elt(env, 14); // "<cn type=&quot;constant&quot;>"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    goto v_89;
v_89:
    v_200 = basic_elt(env, 20); // "&ImaginaryI;"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    goto v_83;
v_85:
    v_200 = stack[0];
    if (is_number(v_200)) goto v_107;
    else goto v_108;
v_107:
    v_200 = basic_elt(env, 21); // "<cn"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    v_200 = stack[0];
    v_200 = Lfloatp(nil, v_200);
    env = stack[-1];
    if (v_200 == nil) goto v_115;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_120;
    else goto v_121;
v_120:
    v_200 = basic_elt(env, 22); // " type=""real"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_119;
v_121:
    v_200 = basic_elt(env, 23); // " type=&quot;real&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_119;
v_119:
    goto v_113;
v_115:
    v_200 = stack[0];
    v_200 = integerp(v_200);
    if (v_200 == nil) goto v_130;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_135;
    else goto v_136;
v_135:
    v_200 = basic_elt(env, 24); // " type=""integer"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_134;
v_136:
    v_200 = basic_elt(env, 25); // " type=&quot;integer&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_134;
v_134:
    goto v_113;
v_130:
    v_200 = basic_elt(env, 26); // ">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_113;
v_113:
    v_200 = stack[0];
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_106;
v_108:
v_106:
    v_200 = stack[0];
    if (symbolp(v_200)) goto v_154;
    else goto v_155;
v_154:
    v_200 = basic_elt(env, 27); // "<ci"
    {   LispObject fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    v_200 = stack[0];
    {   LispObject fn = basic_elt(env, 34); // listp
    v_200 = (*qfn1(fn))(fn, v_200);
    }
    env = stack[-1];
    if (v_200 == nil) goto v_162;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_167;
    else goto v_168;
v_167:
    v_200 = basic_elt(env, 28); // " type=""list"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_166;
v_168:
    v_200 = basic_elt(env, 29); // " type=&quot;list&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_166;
v_166:
    goto v_160;
v_162:
    v_200 = stack[0];
    v_200 = Lsimple_vectorp(nil, v_200);
    env = stack[-1];
    if (v_200 == nil) goto v_177;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_182;
    else goto v_183;
v_182:
    v_200 = basic_elt(env, 30); // " type=""vector"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_181;
v_183:
    v_200 = basic_elt(env, 31); // " type=&quot;vector&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_181;
v_181:
    goto v_160;
v_177:
    v_200 = basic_elt(env, 26); // ">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_160;
v_160:
    v_200 = stack[0];
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 32); // "</ci>"
    v_200 = Lprinc(nil, v_200);
    goto v_153;
v_155:
v_153:
    goto v_83;
v_83:
    goto v_60;
v_60:
    goto v_7;
v_7:
    v_200 = nil;
    return onevalue(v_200);
}



// Code for evzero

static LispObject CC_evzero(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_27, v_28;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    stack[-1] = nil;
    v_27 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_27;
v_9:
    v_27 = qvalue(basic_elt(env, 1)); // dipvars!*
    v_28 = Llength(nil, v_27);
    env = stack[-2];
    v_27 = stack[0];
    v_27 = difference2(v_28, v_27);
    env = stack[-2];
    v_27 = Lminusp(nil, v_27);
    env = stack[-2];
    if (v_27 == nil) goto v_14;
    goto v_8;
v_14:
    v_28 = (LispObject)0+TAG_FIXNUM; // 0
    v_27 = stack[-1];
    v_27 = cons(v_28, v_27);
    env = stack[-2];
    stack[-1] = v_27;
    v_27 = stack[0];
    v_27 = add1(v_27);
    env = stack[-2];
    stack[0] = v_27;
    goto v_9;
v_8:
    v_27 = stack[-1];
    return onevalue(v_27);
}



// Code for chksymmetries!&sub1

static LispObject CC_chksymmetriesGsub1(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_31, v_32, v_33;
    LispObject v_5;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4,v_5);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5,v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5;
    v_31 = v_4;
    v_32 = v_3;
    v_33 = v_2;
// end of prologue
    v_31 = Lsubst(nil, v_33, v_32, v_31);
    env = stack[-2];
    stack[-1] = v_31;
    v_31 = stack[0];
    if (v_31 == nil) goto v_18;
    else goto v_19;
v_18:
    v_31 = lisp_true;
    goto v_17;
v_19:
    v_32 = stack[-1];
    v_31 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // indxsymp
    v_31 = (*qfn2(fn))(fn, v_32, v_31);
    }
    goto v_17;
    v_31 = nil;
v_17:
    if (v_31 == nil) goto v_15;
    v_31 = stack[-1];
    goto v_13;
v_15:
    v_31 = nil;
    goto v_13;
    v_31 = nil;
v_13:
    return onevalue(v_31);
}



// Code for strand!-alg!-top

static LispObject CC_strandKalgKtop(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_23, v_24, v_25;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_24 = stack[-2];
    v_23 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // deletez1
    v_23 = (*qfn2(fn))(fn, v_24, v_23);
    }
    env = stack[-3];
    stack[-2] = v_23;
    v_25 = stack[0];
    v_24 = stack[-1];
    v_23 = (LispObject)16+TAG_FIXNUM; // 1
    {   LispObject fn = basic_elt(env, 2); // color!-strand
    v_23 = (*qfn3(fn))(fn, v_25, v_24, v_23);
    }
    env = stack[-3];
    stack[0] = v_23;
    v_24 = stack[-2];
    v_23 = stack[0];
    {   LispObject fn = basic_elt(env, 3); // contract!-strand
    v_23 = (*qfn2(fn))(fn, v_24, v_23);
    }
    env = stack[-3];
    stack[-2] = v_23;
    v_25 = stack[-2];
    v_24 = stack[0];
    v_23 = nil;
    {
        LispObject fn = basic_elt(env, 4); // dstr!-to!-alg
        return (*qfn3(fn))(fn, v_25, v_24, v_23);
    }
    return onevalue(v_23);
}



// Code for cali!=min

static LispObject CC_caliMmin(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_40, v_41, v_42;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
v_8:
    v_40 = stack[-1];
    if (v_40 == nil) goto v_11;
    else goto v_12;
v_11:
    v_40 = stack[-2];
    goto v_7;
v_12:
    v_42 = stack[-2];
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_41 = carerror(v_40); else
    v_41 = car(v_40);
    v_40 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // listtest
    v_40 = (*qfn3(fn))(fn, v_42, v_41, v_40);
    }
    env = stack[-3];
    if (v_40 == nil) goto v_17;
    else goto v_15;
v_17:
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_42 = cdrerror(v_40); else
    v_42 = cdr(v_40);
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_41 = carerror(v_40); else
    v_41 = car(v_40);
    v_40 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // listtest
    v_40 = (*qfn3(fn))(fn, v_42, v_41, v_40);
    }
    env = stack[-3];
    if (v_40 == nil) goto v_23;
    else goto v_15;
v_23:
    goto v_16;
v_15:
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = cdr(v_40);
    stack[-1] = v_40;
    goto v_8;
v_16:
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_41 = carerror(v_40); else
    v_41 = car(v_40);
    v_40 = stack[-2];
    v_40 = cons(v_41, v_40);
    env = stack[-3];
    stack[-2] = v_40;
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = cdr(v_40);
    stack[-1] = v_40;
    goto v_8;
    v_40 = nil;
v_7:
    return onevalue(v_40);
}



// Code for appr

static LispObject CC_appr(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_24, v_25, v_26;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24 = v_3;
    v_25 = v_2;
// end of prologue
v_8:
    v_26 = v_25;
    if (v_26 == nil) goto v_11;
    else goto v_12;
v_11:
    goto v_7;
v_12:
    v_26 = v_25;
    if (!car_legal(v_26)) v_26 = cdrerror(v_26); else
    v_26 = cdr(v_26);
    stack[0] = v_26;
    if (!car_legal(v_25)) v_25 = carerror(v_25); else
    v_25 = car(v_25);
    v_24 = cons(v_25, v_24);
    env = stack[-1];
    v_25 = stack[0];
    goto v_8;
    v_24 = nil;
v_7:
    return onevalue(v_24);
}



// Code for sfto_psrem

static LispObject CC_sfto_psrem(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_91, v_92;
    LispObject v_5;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4,v_5);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5,v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-6] = v_5;
    stack[-7] = v_4;
    v_92 = v_3;
    stack[-8] = v_2;
// end of prologue
    goto v_22;
    goto v_20;
v_22:
v_20:
    goto v_27;
    goto v_25;
v_27:
v_25:
    v_91 = v_92;
    if (!car_legal(v_91)) v_91 = carerror(v_91); else
    v_91 = car(v_91);
    if (!car_legal(v_91)) v_91 = cdrerror(v_91); else
    v_91 = cdr(v_91);
    stack[-9] = v_91;
    v_91 = v_92;
    if (!car_legal(v_91)) v_91 = cdrerror(v_91); else
    v_91 = cdr(v_91);
    stack[-5] = v_91;
    v_91 = stack[-8];
    if (!car_legal(v_91)) v_91 = carerror(v_91); else
    v_91 = car(v_91);
    if (!car_legal(v_91)) v_91 = carerror(v_91); else
    v_91 = car(v_91);
    if (!car_legal(v_91)) v_91 = cdrerror(v_91); else
    v_91 = cdr(v_91);
    stack[-4] = v_91;
    v_91 = v_92;
    if (!car_legal(v_91)) v_91 = carerror(v_91); else
    v_91 = car(v_91);
    if (!car_legal(v_91)) v_91 = carerror(v_91); else
    v_91 = car(v_91);
    if (!car_legal(v_91)) v_91 = cdrerror(v_91); else
    v_91 = cdr(v_91);
    stack[-3] = v_91;
v_44:
    v_92 = stack[-4];
    v_91 = stack[-3];
    v_91 = (LispObject)geq2(v_92, v_91);
    v_91 = v_91 ? lisp_true : nil;
    env = stack[-10];
    if (v_91 == nil) goto v_47;
    else goto v_48;
v_47:
    goto v_43;
v_48:
    v_91 = stack[-8];
    {   LispObject fn = basic_elt(env, 1); // sfto_lcx
    v_91 = (*qfn1(fn))(fn, v_91);
    }
    env = stack[-10];
    stack[0] = v_91;
    v_92 = stack[0];
    v_91 = stack[-9];
    {   LispObject fn = basic_elt(env, 2); // sfto_dgcd
    v_91 = (*qfn2(fn))(fn, v_92, v_91);
    }
    env = stack[-10];
    stack[-2] = v_91;
    v_92 = stack[0];
    v_91 = stack[-2];
    {   LispObject fn = basic_elt(env, 3); // quotfx
    stack[-1] = (*qfn2(fn))(fn, v_92, v_91);
    }
    env = stack[-10];
    stack[0] = stack[-7];
    v_92 = stack[-4];
    v_91 = stack[-3];
    v_91 = difference2(v_92, v_91);
    env = stack[-10];
    {   LispObject fn = basic_elt(env, 4); // sfto_kexp
    v_91 = (*qfn2(fn))(fn, stack[0], v_91);
    }
    env = stack[-10];
    {   LispObject fn = basic_elt(env, 5); // multf
    v_91 = (*qfn2(fn))(fn, stack[-1], v_91);
    }
    env = stack[-10];
    stack[0] = v_91;
    v_92 = stack[-9];
    v_91 = stack[-2];
    {   LispObject fn = basic_elt(env, 3); // quotfx
    v_92 = (*qfn2(fn))(fn, v_92, v_91);
    }
    env = stack[-10];
    v_91 = stack[-8];
    if (!car_legal(v_91)) v_91 = cdrerror(v_91); else
    v_91 = cdr(v_91);
    {   LispObject fn = basic_elt(env, 5); // multf
    stack[-1] = (*qfn2(fn))(fn, v_92, v_91);
    }
    env = stack[-10];
    v_92 = stack[0];
    v_91 = stack[-5];
    {   LispObject fn = basic_elt(env, 5); // multf
    v_91 = (*qfn2(fn))(fn, v_92, v_91);
    }
    env = stack[-10];
    {   LispObject fn = basic_elt(env, 6); // negf
    v_91 = (*qfn1(fn))(fn, v_91);
    }
    env = stack[-10];
    {   LispObject fn = basic_elt(env, 7); // addf
    v_91 = (*qfn2(fn))(fn, stack[-1], v_91);
    }
    env = stack[-10];
    stack[-8] = v_91;
    v_92 = stack[-6];
    v_91 = (LispObject)-16+TAG_FIXNUM; // -1
    v_91 = Leqn_2(nil, v_92, v_91);
    env = stack[-10];
    if (v_91 == nil) goto v_81;
    v_91 = stack[-8];
    {   LispObject fn = basic_elt(env, 6); // negf
    v_91 = (*qfn1(fn))(fn, v_91);
    }
    env = stack[-10];
    stack[-8] = v_91;
    goto v_79;
v_81:
v_79:
    v_92 = stack[-8];
    v_91 = stack[-7];
    {   LispObject fn = basic_elt(env, 8); // sfto_vardeg
    v_91 = (*qfn2(fn))(fn, v_92, v_91);
    }
    env = stack[-10];
    stack[-4] = v_91;
    goto v_44;
v_43:
    v_91 = stack[-8];
    return onevalue(v_91);
}



// Code for co_hfn

static LispObject CC_co_hfn(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_11 = stack[0];
    if (!car_legal(v_11)) v_11 = cdrerror(v_11); else
    v_11 = cdr(v_11);
    {   LispObject fn = basic_elt(env, 1); // cl_fvarl1
    stack[-1] = (*qfn1(fn))(fn, v_11);
    }
    env = stack[-2];
    v_11 = stack[0];
    if (!car_legal(v_11)) v_11 = cdrerror(v_11); else
    v_11 = cdr(v_11);
    {   LispObject fn = basic_elt(env, 2); // rl_atnum
    v_11 = (*qfn1(fn))(fn, v_11);
    }
    {
        LispObject v_14 = stack[-1];
        return list2(v_14, v_11);
    }
}



// Code for ofsf_updsigndom

static LispObject CC_ofsf_updsigndom(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_28, v_29;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_28 = stack[0];
    if (v_28 == nil) goto v_6;
    else goto v_7;
v_6:
    v_28 = basic_elt(env, 1); // equal
    goto v_5;
v_7:
    v_29 = stack[0];
    v_28 = (LispObject)0+TAG_FIXNUM; // 0
    v_28 = (LispObject)greaterp2(v_29, v_28);
    v_28 = v_28 ? lisp_true : nil;
    env = stack[-1];
    if (v_28 == nil) goto v_11;
    v_28 = basic_elt(env, 2); // greaterp
    goto v_5;
v_11:
    v_29 = stack[0];
    v_28 = (LispObject)0+TAG_FIXNUM; // 0
    v_28 = (LispObject)lessp2(v_29, v_28);
    v_28 = v_28 ? lisp_true : nil;
    env = stack[-1];
    if (v_28 == nil) goto v_17;
    v_28 = basic_elt(env, 3); // lessp
    goto v_5;
v_17:
    v_29 = basic_elt(env, 4); // "something wrong in ofsf_updSignDom:"
    v_28 = stack[0];
    v_28 = list2(v_29, v_28);
    env = stack[-1];
    {
        LispObject fn = basic_elt(env, 5); // rederr
        return (*qfn1(fn))(fn, v_28);
    }
    v_28 = nil;
v_5:
    return onevalue(v_28);
}



// Code for change!+int!+to!+sq

static LispObject CC_changeLintLtoLsq(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_2;
// end of prologue
    v_10 = v_9;
    v_9 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_10, v_9);
    return onevalue(v_9);
}



// Code for cl_subfof

static LispObject CC_cl_subfof(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_59, v_60, v_61;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_3;
    stack[-5] = v_2;
// end of prologue
    stack[-6] = nil;
    stack[-2] = nil;
    v_59 = stack[-5];
    {   LispObject fn = basic_elt(env, 1); // rl_subalchk
    v_59 = (*qfn1(fn))(fn, v_59);
    }
    env = stack[-7];
    v_59 = stack[-5];
    stack[-1] = v_59;
v_15:
    v_59 = stack[-1];
    if (v_59 == nil) goto v_19;
    else goto v_20;
v_19:
    goto v_14;
v_20:
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    stack[0] = v_59;
    v_59 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // rl_eqnrhskernels
    v_59 = (*qfn1(fn))(fn, v_59);
    }
    env = stack[-7];
    stack[-3] = v_59;
    v_59 = stack[0];
    if (!car_legal(v_59)) v_60 = carerror(v_59); else
    v_60 = car(v_59);
    v_59 = stack[-3];
    v_59 = cons(v_60, v_59);
    env = stack[-7];
    v_60 = ncons(v_59);
    env = stack[-7];
    v_59 = stack[-6];
    v_59 = list2(v_60, v_59);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 3); // lto_alunion
    v_59 = (*qfn1(fn))(fn, v_59);
    }
    env = stack[-7];
    stack[-6] = v_59;
    v_59 = stack[0];
    if (!car_legal(v_59)) stack[0] = carerror(v_59); else
    stack[0] = car(v_59);
    v_60 = stack[-3];
    v_59 = stack[-2];
    v_59 = Lappend_2(nil, v_60, v_59);
    env = stack[-7];
    v_59 = cons(stack[0], v_59);
    env = stack[-7];
    stack[-2] = v_59;
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = cdr(v_59);
    stack[-1] = v_59;
    goto v_15;
v_14:
    v_59 = stack[-4];
    {   LispObject fn = basic_elt(env, 4); // cl_varl1
    v_59 = (*qfn1(fn))(fn, v_59);
    }
    env = stack[-7];
    stack[-3] = v_59;
    v_61 = stack[-2];
    v_59 = stack[-3];
    if (!car_legal(v_59)) v_60 = carerror(v_59); else
    v_60 = car(v_59);
    v_59 = stack[-3];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = cdr(v_59);
    v_59 = list3(v_61, v_60, v_59);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 5); // lto_nconcn
    v_59 = (*qfn1(fn))(fn, v_59);
    }
    env = stack[-7];
    stack[-2] = v_59;
    stack[0] = stack[-5];
    stack[-1] = stack[-4];
    stack[-3] = stack[-6];
    v_59 = stack[-2];
    v_59 = ncons(v_59);
    env = stack[-7];
    {
        LispObject v_69 = stack[0];
        LispObject v_70 = stack[-1];
        LispObject v_71 = stack[-3];
        LispObject fn = basic_elt(env, 6); // cl_subfof1
        return (*qfn4up(fn))(fn, v_69, v_70, v_71, v_59);
    }
    return onevalue(v_59);
}



// Code for rl_sacatlp

static LispObject CC_rl_sacatlp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    stack[0] = qvalue(basic_elt(env, 1)); // rl_sacatlp!*
    v_10 = list2(v_11, v_10);
    env = stack[-1];
    {
        LispObject v_13 = stack[0];
        LispObject fn = basic_elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13, v_10);
    }
}



// Code for conditionml

static LispObject CC_conditionml(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_17;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_17 = basic_elt(env, 1); // "<condition>"
    {   LispObject fn = basic_elt(env, 3); // printout
    v_17 = (*qfn1(fn))(fn, v_17);
    }
    env = stack[-1];
    v_17 = lisp_true;
    {   LispObject fn = basic_elt(env, 4); // indent!*
    v_17 = (*qfn1(fn))(fn, v_17);
    }
    env = stack[-1];
    v_17 = stack[0];
    if (!car_legal(v_17)) v_17 = carerror(v_17); else
    v_17 = car(v_17);
    {   LispObject fn = basic_elt(env, 5); // expression
    v_17 = (*qfn1(fn))(fn, v_17);
    }
    env = stack[-1];
    v_17 = nil;
    {   LispObject fn = basic_elt(env, 4); // indent!*
    v_17 = (*qfn1(fn))(fn, v_17);
    }
    env = stack[-1];
    v_17 = basic_elt(env, 2); // "</condition>"
    {   LispObject fn = basic_elt(env, 3); // printout
    v_17 = (*qfn1(fn))(fn, v_17);
    }
    v_17 = nil;
    return onevalue(v_17);
}



// Code for simpu

static LispObject CC_simpu(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20 = v_2;
// end of prologue
    stack[-1] = basic_elt(env, 1); // u
    v_19 = v_20;
    if (!car_legal(v_19)) stack[0] = carerror(v_19); else
    stack[0] = car(v_19);
    v_19 = v_20;
    if (!car_legal(v_19)) v_19 = cdrerror(v_19); else
    v_19 = cdr(v_19);
    {   LispObject fn = basic_elt(env, 2); // ordn
    v_19 = (*qfn1(fn))(fn, v_19);
    }
    env = stack[-2];
    v_19 = Lreverse(nil, v_19);
    env = stack[-2];
    v_20 = list2star(stack[-1], stack[0], v_19);
    env = stack[-2];
    v_19 = (LispObject)16+TAG_FIXNUM; // 1
    {   LispObject fn = basic_elt(env, 3); // mksp
    v_20 = (*qfn2(fn))(fn, v_20, v_19);
    }
    env = stack[-2];
    v_19 = (LispObject)16+TAG_FIXNUM; // 1
    v_19 = cons(v_20, v_19);
    env = stack[-2];
    v_20 = ncons(v_19);
    v_19 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_20, v_19);
}



// Code for assgnpri

static LispObject CC_assgnpri(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_205, v_206, v_207;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_4;
    stack[-3] = v_3;
    stack[-4] = v_2;
// end of prologue
    stack[-5] = nil;
    v_205 = nil;
    setvalue(basic_elt(env, 1), v_205); // overflowed!*
    setvalue(basic_elt(env, 2), v_205); // testing!-width!*
    v_205 = stack[-4];
    if (v_205 == nil) goto v_13;
    else goto v_14;
v_13:
    v_205 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_205;
    goto v_12;
v_14:
v_12:
    v_205 = qvalue(basic_elt(env, 3)); // !*nero
    if (v_205 == nil) goto v_20;
    v_206 = stack[-4];
    v_205 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_206 == v_205) goto v_23;
    else goto v_20;
v_23:
    v_205 = nil;
    goto v_9;
v_20:
    v_205 = qvalue(basic_elt(env, 4)); // !*tex
    if (v_205 == nil) goto v_30;
    v_207 = stack[-4];
    v_206 = stack[-3];
    v_205 = stack[-2];
    {
        LispObject fn = basic_elt(env, 20); // texpri
        return (*qfn3(fn))(fn, v_207, v_206, v_205);
    }
v_30:
    v_205 = basic_elt(env, 5); // vecp
    {   LispObject fn = basic_elt(env, 21); // getd
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    if (v_205 == nil) goto v_37;
    v_205 = stack[-4];
    {   LispObject fn = basic_elt(env, 5); // vecp
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    if (v_205 == nil) goto v_37;
    v_206 = stack[-4];
    v_205 = basic_elt(env, 6); // mat
    {
        LispObject fn = basic_elt(env, 22); // vecpri
        return (*qfn2(fn))(fn, v_206, v_205);
    }
v_37:
    v_206 = basic_elt(env, 7); // csl
    v_205 = qvalue(basic_elt(env, 8)); // lispsystem!*
    v_205 = Lmemq(nil, v_206, v_205);
    if (v_205 == nil) goto v_50;
    v_205 = basic_elt(env, 9); // math!-display
    {   LispObject fn = basic_elt(env, 21); // getd
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    if (v_205 == nil) goto v_50;
    v_205 = (LispObject)0+TAG_FIXNUM; // 0
    {   LispObject fn = basic_elt(env, 9); // math!-display
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    if (v_205 == nil) goto v_50;
    v_206 = qvalue(basic_elt(env, 10)); // outputhandler!*
    v_205 = basic_elt(env, 11); // fancy!-output
    if (v_206 == v_205) goto v_66;
    else goto v_67;
v_66:
    v_205 = stack[-4];
    {   LispObject fn = basic_elt(env, 23); // would!-be!-huge
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    goto v_65;
v_67:
    v_205 = nil;
    goto v_65;
    v_205 = nil;
v_65:
    if (v_205 == nil) goto v_50;
    v_205 = nil;
    {   LispObject fn = basic_elt(env, 24); // fmp!-switch
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    v_205 = lisp_true;
    stack[-5] = v_205;
    goto v_48;
v_50:
v_48:
    v_205 = stack[-4];
    {   LispObject fn = basic_elt(env, 25); // getrtype
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    v_207 = v_205;
    if (v_205 == nil) goto v_81;
    v_206 = v_207;
    v_205 = basic_elt(env, 12); // sprifn
    v_205 = Lflagp(nil, v_206, v_205);
    env = stack[-6];
    if (v_205 == nil) goto v_81;
    v_205 = qvalue(basic_elt(env, 10)); // outputhandler!*
    if (v_205 == nil) goto v_91;
    else goto v_92;
v_91:
    v_205 = stack[-3];
    if (v_205 == nil) goto v_96;
    else goto v_97;
v_96:
    v_206 = v_207;
    v_205 = basic_elt(env, 13); // tag
    v_205 = get(v_206, v_205);
    env = stack[-6];
    if (!symbolp(v_205)) v_206 = nil;
    else { v_206 = qfastgets(v_205);
           if (v_206 != nil) { v_206 = elt(v_206, 57); // prifn
#ifdef RECORD_GET
             if (v_206 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_206 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_206 == SPID_NOPROP) v_206 = nil; }}
#endif
    v_205 = stack[-4];
    v_205 = Lapply1(nil, v_206, v_205);
    env = stack[-6];
    goto v_95;
v_97:
    stack[0] = basic_elt(env, 14); // setq
    v_206 = stack[-3];
    v_205 = stack[-4];
    {   LispObject fn = basic_elt(env, 26); // aconc
    v_205 = (*qfn2(fn))(fn, v_206, v_205);
    }
    env = stack[-6];
    v_205 = cons(stack[0], v_205);
    env = stack[-6];
    {   LispObject fn = basic_elt(env, 27); // maprin
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    goto v_95;
v_95:
    goto v_90;
v_92:
    stack[-1] = qvalue(basic_elt(env, 10)); // outputhandler!*
    stack[0] = basic_elt(env, 0); // assgnpri
    v_207 = stack[-4];
    v_206 = stack[-3];
    v_205 = stack[-2];
    v_205 = list3(v_207, v_206, v_205);
    env = stack[-6];
    v_205 = Lapply2(nil, stack[-1], stack[0], v_205);
    env = stack[-6];
    goto v_90;
v_90:
    goto v_79;
v_81:
    v_206 = stack[-2];
    v_205 = basic_elt(env, 15); // (first only)
    v_205 = Lmemq(nil, v_206, v_205);
    if (v_205 == nil) goto v_127;
    v_205 = lisp_true;
    {   LispObject fn = basic_elt(env, 28); // terpri!*
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    goto v_125;
v_127:
v_125:
    v_205 = stack[-3];
    {   LispObject fn = basic_elt(env, 29); // evalvars
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    stack[-3] = v_205;
    v_205 = qvalue(basic_elt(env, 16)); // !*fort
    if (v_205 == nil) goto v_138;
    v_207 = stack[-4];
    v_206 = stack[-3];
    v_205 = stack[-2];
    {   LispObject fn = basic_elt(env, 30); // fvarpri
    v_205 = (*qfn3(fn))(fn, v_207, v_206, v_205);
    }
    env = stack[-6];
    v_205 = stack[-5];
    if (v_205 == nil) goto v_147;
    v_205 = lisp_true;
    {   LispObject fn = basic_elt(env, 24); // fmp!-switch
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    goto v_145;
v_147:
v_145:
    v_205 = nil;
    goto v_9;
v_138:
    v_205 = stack[-3];
    if (v_205 == nil) goto v_156;
    stack[0] = basic_elt(env, 14); // setq
    v_206 = stack[-3];
    v_205 = stack[-4];
    {   LispObject fn = basic_elt(env, 26); // aconc
    v_205 = (*qfn2(fn))(fn, v_206, v_205);
    }
    env = stack[-6];
    v_205 = cons(stack[0], v_205);
    env = stack[-6];
    goto v_154;
v_156:
    v_205 = stack[-4];
    goto v_154;
    v_205 = nil;
v_154:
    {   LispObject fn = basic_elt(env, 27); // maprin
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    v_205 = stack[-2];
    if (v_205 == nil) goto v_172;
    else goto v_173;
v_172:
    v_205 = lisp_true;
    goto v_171;
v_173:
    v_206 = stack[-2];
    v_205 = basic_elt(env, 17); // first
    v_205 = (v_206 == v_205 ? lisp_true : nil);
    goto v_171;
    v_205 = nil;
v_171:
    if (v_205 == nil) goto v_169;
    v_205 = stack[-5];
    if (v_205 == nil) goto v_184;
    v_205 = lisp_true;
    {   LispObject fn = basic_elt(env, 24); // fmp!-switch
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    goto v_182;
v_184:
v_182:
    v_205 = nil;
    goto v_9;
v_169:
    v_205 = qvalue(basic_elt(env, 18)); // !*nat
    if (v_205 == nil) goto v_189;
    else goto v_190;
v_189:
    v_205 = basic_elt(env, 19); // "$"
    {   LispObject fn = basic_elt(env, 31); // prin2!*
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    goto v_167;
v_190:
v_167:
    v_205 = qvalue(basic_elt(env, 18)); // !*nat
    v_205 = (v_205 == nil ? lisp_true : nil);
    {   LispObject fn = basic_elt(env, 28); // terpri!*
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    env = stack[-6];
    goto v_79;
v_79:
    v_205 = stack[-5];
    if (v_205 == nil) goto v_200;
    v_205 = lisp_true;
    {   LispObject fn = basic_elt(env, 24); // fmp!-switch
    v_205 = (*qfn1(fn))(fn, v_205);
    }
    goto v_198;
v_200:
v_198:
    v_205 = nil;
v_9:
    return onevalue(v_205);
}



// Code for qsimpcomb_standard_integer_part_sf

static LispObject CC_qsimpcomb_standard_integer_part_sf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_63, v_64, v_65;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_2;
// end of prologue
    v_63 = nil;
    stack[-3] = v_63;
v_12:
    v_63 = stack[-2];
    v_63 = Lconsp(nil, v_63);
    env = stack[-4];
    if (v_63 == nil) goto v_15;
    else goto v_16;
v_15:
    goto v_11;
v_16:
    v_63 = stack[-2];
    if (!car_legal(v_63)) v_63 = carerror(v_63); else
    v_63 = car(v_63);
    if (!car_legal(v_63)) v_63 = cdrerror(v_63); else
    v_63 = cdr(v_63);
    {   LispObject fn = basic_elt(env, 0); // qsimpcomb_standard_integer_part_sf
    v_63 = (*qfn1(fn))(fn, v_63);
    }
    env = stack[-4];
    stack[-1] = v_63;
    v_63 = stack[-2];
    if (!car_legal(v_63)) v_63 = carerror(v_63); else
    v_63 = car(v_63);
    if (!car_legal(v_63)) v_63 = carerror(v_63); else
    v_63 = car(v_63);
    if (!car_legal(v_63)) v_64 = carerror(v_63); else
    v_64 = car(v_63);
    v_63 = stack[-2];
    if (!car_legal(v_63)) v_63 = carerror(v_63); else
    v_63 = car(v_63);
    if (!car_legal(v_63)) v_63 = carerror(v_63); else
    v_63 = car(v_63);
    if (!car_legal(v_63)) v_63 = cdrerror(v_63); else
    v_63 = cdr(v_63);
    v_63 = cons(v_64, v_63);
    env = stack[-4];
    stack[0] = v_63;
v_35:
    v_64 = stack[0];
    v_63 = stack[-1];
    if (!car_legal(v_63)) v_63 = carerror(v_63); else
    v_63 = car(v_63);
    v_65 = cons(v_64, v_63);
    env = stack[-4];
    v_64 = nil;
    v_63 = stack[-3];
    v_63 = acons(v_65, v_64, v_63);
    env = stack[-4];
    stack[-3] = v_63;
    v_63 = stack[-1];
    if (!car_legal(v_63)) v_63 = cdrerror(v_63); else
    v_63 = cdr(v_63);
    stack[-1] = v_63;
    v_63 = stack[-1];
    if (v_63 == nil) goto v_49;
    goto v_35;
v_49:
    v_63 = stack[-2];
    if (!car_legal(v_63)) v_63 = cdrerror(v_63); else
    v_63 = cdr(v_63);
    stack[-2] = v_63;
    goto v_12;
v_11:
    v_63 = stack[-2];
    if (v_63 == nil) goto v_57;
    v_64 = stack[-2];
    v_63 = stack[-3];
    v_63 = cons(v_64, v_63);
    stack[-3] = v_63;
    goto v_55;
v_57:
v_55:
    v_63 = stack[-3];
    return onevalue(v_63);
}



// Code for a2vdp

static LispObject CC_a2vdp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_43, v_44, v_45;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_45 = v_2;
// end of prologue
    v_44 = v_45;
    v_43 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_44 == v_43) goto v_10;
    else goto v_11;
v_10:
    v_43 = lisp_true;
    goto v_9;
v_11:
    v_43 = v_45;
    v_43 = (v_43 == nil ? lisp_true : nil);
    goto v_9;
    v_43 = nil;
v_9:
    if (v_43 == nil) goto v_7;
    stack[-2] = basic_elt(env, 1); // vdp
    stack[-1] = nil;
    v_44 = nil;
    v_43 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = cons(v_44, v_43);
    env = stack[-3];
    v_44 = nil;
    v_43 = nil;
    v_43 = list2(v_44, v_43);
    {
        LispObject v_49 = stack[-2];
        LispObject v_50 = stack[-1];
        LispObject v_51 = stack[0];
        return list3star(v_49, v_50, v_51, v_43);
    }
v_7:
    v_43 = v_45;
    {   LispObject fn = basic_elt(env, 2); // a2dip
    v_43 = (*qfn1(fn))(fn, v_43);
    }
    env = stack[-3];
    v_44 = v_43;
    stack[-2] = basic_elt(env, 1); // vdp
    v_43 = v_44;
    if (!car_legal(v_43)) stack[-1] = carerror(v_43); else
    stack[-1] = car(v_43);
    v_43 = v_44;
    if (!car_legal(v_43)) v_43 = cdrerror(v_43); else
    v_43 = cdr(v_43);
    if (!car_legal(v_43)) stack[0] = carerror(v_43); else
    stack[0] = car(v_43);
    v_43 = nil;
    v_43 = list2(v_44, v_43);
    {
        LispObject v_52 = stack[-2];
        LispObject v_53 = stack[-1];
        LispObject v_54 = stack[0];
        return list3star(v_52, v_53, v_54, v_43);
    }
    v_43 = nil;
    return onevalue(v_43);
}



// Code for markedvarp

static LispObject CC_markedvarp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7, v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    v_8 = basic_elt(env, 1); // !*marked!*
        return Lflagp(nil, v_7, v_8);
}



// Code for evalwhereexp

static LispObject CC_evalwhereexp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_20 = v_2;
// end of prologue
    v_19 = v_20;
    if (!car_legal(v_19)) v_19 = carerror(v_19); else
    v_19 = car(v_19);
    if (!car_legal(v_19)) stack[-2] = cdrerror(v_19); else
    stack[-2] = cdr(v_19);
    stack[-1] = basic_elt(env, 1); // aeval
    stack[0] = basic_elt(env, 1); // aeval
    v_19 = v_20;
    if (!car_legal(v_19)) v_20 = cdrerror(v_19); else
    v_20 = cdr(v_19);
    v_19 = basic_elt(env, 2); // where
    {   LispObject fn = basic_elt(env, 3); // carx
    v_19 = (*qfn2(fn))(fn, v_20, v_19);
    }
    env = stack[-3];
    v_19 = list2(stack[0], v_19);
    env = stack[-3];
    v_19 = Lmkquote(nil, v_19);
    env = stack[-3];
    v_19 = list2(stack[-1], v_19);
    env = stack[-3];
    v_20 = list2(stack[-2], v_19);
    env = stack[-3];
    v_19 = nil;
    {
        LispObject fn = basic_elt(env, 4); // evalletsub
        return (*qfn2(fn))(fn, v_20, v_19);
    }
}



// Code for mv!-compact2

static LispObject CC_mvKcompact2(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_34, v_35, v_36;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_35 = stack[-1];
    v_34 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // equiv!-coeffs
    v_34 = (*qfn2(fn))(fn, v_35, v_34);
    }
    env = stack[-3];
    stack[-2] = v_34;
    v_34 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // mv!-domainlist
    v_34 = (*qfn1(fn))(fn, v_34);
    }
    env = stack[-3];
    v_35 = stack[-2];
    {   LispObject fn = basic_elt(env, 3); // reduce
    v_34 = (*qfn2(fn))(fn, v_35, v_34);
    }
    env = stack[-3];
    v_36 = v_34;
    v_35 = v_36;
    v_34 = stack[-2];
    if (equal(v_35, v_34)) goto v_20;
    else goto v_21;
v_20:
    v_34 = nil;
    goto v_19;
v_21:
    v_35 = v_36;
    v_34 = stack[-2];
    {   LispObject fn = basic_elt(env, 4); // mv!-domainlist!-!-
    v_34 = (*qfn2(fn))(fn, v_35, v_34);
    }
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 5); // mv!-coeff!-replace
    v_35 = (*qfn2(fn))(fn, stack[0], v_34);
    }
    env = stack[-3];
    v_34 = stack[-1];
    {
        LispObject fn = basic_elt(env, 6); // mv!-!+
        return (*qfn2(fn))(fn, v_35, v_34);
    }
    v_34 = nil;
v_19:
    return onevalue(v_34);
}



// Code for extract_vars

static LispObject CC_extract_vars(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_32, v_33;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    stack[-1] = nil;
v_7:
    v_32 = stack[0];
    if (v_32 == nil) goto v_10;
    else goto v_11;
v_10:
    v_32 = stack[-1];
    {
        LispObject fn = basic_elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_32);
    }
v_11:
    v_32 = stack[0];
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = car(v_32);
    {   LispObject fn = basic_elt(env, 3); // raiseind!:
    v_33 = (*qfn1(fn))(fn, v_32);
    }
    env = stack[-2];
    v_32 = basic_elt(env, 1); // variable
    v_32 = Lflagp(nil, v_33, v_32);
    env = stack[-2];
    if (v_32 == nil) goto v_16;
    v_32 = stack[0];
    if (!car_legal(v_32)) v_33 = carerror(v_32); else
    v_33 = car(v_32);
    v_32 = stack[-1];
    v_32 = cons(v_33, v_32);
    env = stack[-2];
    stack[-1] = v_32;
    v_32 = stack[0];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    stack[0] = v_32;
    goto v_7;
v_16:
    v_32 = stack[0];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    stack[0] = v_32;
    goto v_7;
    v_32 = nil;
    return onevalue(v_32);
}



// Code for expand_terminal

static LispObject CC_expand_terminal(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_364, v_365, v_366;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_2;
// end of prologue
    v_364 = stack[-2];
    if (!consp(v_364)) goto v_11;
    else goto v_12;
v_11:
    v_364 = stack[-2];
    goto v_8;
v_12:
    v_365 = stack[-2];
    v_364 = basic_elt(env, 1); // opt
    if (!consp(v_365)) goto v_16;
    v_365 = car(v_365);
    if (v_365 == v_364) goto v_15;
    else goto v_16;
v_15:
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-5] = v_364;
    stack[-1] = stack[-5];
    stack[0] = basic_elt(env, 2); // (nil)
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_365 = list3(stack[-1], stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    v_364 = stack[-5];
    goto v_8;
v_16:
    v_365 = stack[-2];
    v_364 = basic_elt(env, 4); // seq
    if (!consp(v_365)) goto v_31;
    v_365 = car(v_365);
    if (v_365 == v_364) goto v_30;
    else goto v_31;
v_30:
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-5] = v_364;
    stack[0] = stack[-5];
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_365 = list2(stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    v_364 = stack[-5];
    goto v_8;
v_31:
    v_365 = stack[-2];
    v_364 = basic_elt(env, 5); // star
    if (!consp(v_365)) goto v_45;
    v_365 = car(v_365);
    if (v_365 == v_364) goto v_44;
    else goto v_45;
v_44:
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-5] = v_364;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-4] = v_364;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_54;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_61;
    else goto v_62;
v_61:
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    v_364 = (consp(v_364) ? nil : lisp_true);
    goto v_60;
v_62:
    v_364 = nil;
    goto v_60;
    v_364 = nil;
v_60:
    if (v_364 == nil) goto v_54;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    stack[-4] = v_364;
    goto v_52;
v_54:
    stack[0] = stack[-4];
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_365 = list2(stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    goto v_52;
v_52:
    stack[-1] = stack[-5];
    stack[0] = basic_elt(env, 2); // (nil)
    v_365 = stack[-4];
    v_364 = stack[-5];
    v_365 = list2(v_365, v_364);
    env = stack[-6];
    v_364 = basic_elt(env, 6); // (cons !$1 !$2)
    v_364 = list2(v_365, v_364);
    env = stack[-6];
    v_365 = list3(stack[-1], stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    v_364 = stack[-5];
    goto v_8;
v_45:
    v_365 = stack[-2];
    v_364 = basic_elt(env, 7); // plus
    if (!consp(v_365)) goto v_97;
    v_365 = car(v_365);
    if (v_365 == v_364) goto v_96;
    else goto v_97;
v_96:
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-5] = v_364;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-4] = v_364;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_106;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_113;
    else goto v_114;
v_113:
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    v_364 = (consp(v_364) ? nil : lisp_true);
    goto v_112;
v_114:
    v_364 = nil;
    goto v_112;
    v_364 = nil;
v_112:
    if (v_364 == nil) goto v_106;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    stack[-4] = v_364;
    goto v_104;
v_106:
    stack[0] = stack[-4];
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_365 = list2(stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    goto v_104;
v_104:
    stack[-1] = stack[-5];
    v_364 = stack[-4];
    v_365 = ncons(v_364);
    env = stack[-6];
    v_364 = basic_elt(env, 8); // (list !$1)
    stack[0] = list2(v_365, v_364);
    env = stack[-6];
    v_365 = stack[-4];
    v_364 = stack[-5];
    v_365 = list2(v_365, v_364);
    env = stack[-6];
    v_364 = basic_elt(env, 6); // (cons !$1 !$2)
    v_364 = list2(v_365, v_364);
    env = stack[-6];
    v_365 = list3(stack[-1], stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    v_364 = stack[-5];
    goto v_8;
v_97:
    v_365 = stack[-2];
    v_364 = basic_elt(env, 9); // list
    if (!consp(v_365)) goto v_156;
    v_365 = car(v_365);
    if (v_365 == v_364) goto v_155;
    else goto v_156;
v_155:
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    goto v_154;
v_156:
    v_364 = nil;
    goto v_154;
    v_364 = nil;
v_154:
    if (v_364 == nil) goto v_152;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-5] = v_364;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-4] = v_364;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-3] = v_364;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_171;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_179;
    else goto v_180;
v_179:
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    v_364 = (consp(v_364) ? nil : lisp_true);
    goto v_178;
v_180:
    v_364 = nil;
    goto v_178;
    v_364 = nil;
v_178:
    if (v_364 == nil) goto v_171;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    stack[-4] = v_364;
    goto v_169;
v_171:
    stack[0] = stack[-4];
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_365 = list2(stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    goto v_169;
v_169:
    stack[-1] = stack[-3];
    stack[0] = basic_elt(env, 2); // (nil)
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_366 = carerror(v_364); else
    v_366 = car(v_364);
    v_365 = stack[-4];
    v_364 = stack[-3];
    v_365 = list3(v_366, v_365, v_364);
    env = stack[-6];
    v_364 = basic_elt(env, 10); // (cons !$2 !$3)
    v_364 = list2(v_365, v_364);
    env = stack[-6];
    v_365 = list3(stack[-1], stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    stack[-1] = stack[-5];
    stack[0] = basic_elt(env, 2); // (nil)
    v_365 = stack[-4];
    v_364 = stack[-3];
    v_365 = list2(v_365, v_364);
    env = stack[-6];
    v_364 = basic_elt(env, 6); // (cons !$1 !$2)
    v_364 = list2(v_365, v_364);
    env = stack[-6];
    v_365 = list3(stack[-1], stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    v_364 = stack[-5];
    goto v_8;
v_152:
    v_365 = stack[-2];
    v_364 = basic_elt(env, 11); // listplus
    if (!consp(v_365)) goto v_236;
    v_365 = car(v_365);
    if (v_365 == v_364) goto v_235;
    else goto v_236;
v_235:
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    goto v_234;
v_236:
    v_364 = nil;
    goto v_234;
    v_364 = nil;
v_234:
    if (v_364 == nil) goto v_232;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-5] = v_364;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-4] = v_364;
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-3] = v_364;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_251;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (v_364 == nil) goto v_259;
    else goto v_260;
v_259:
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    v_364 = (consp(v_364) ? nil : lisp_true);
    goto v_258;
v_260:
    v_364 = nil;
    goto v_258;
    v_364 = nil;
v_258:
    if (v_364 == nil) goto v_251;
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    stack[-4] = v_364;
    goto v_249;
v_251:
    stack[0] = stack[-4];
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_365 = list2(stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    goto v_249;
v_249:
    stack[-1] = stack[-3];
    stack[0] = basic_elt(env, 2); // (nil)
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    if (!car_legal(v_364)) v_366 = carerror(v_364); else
    v_366 = car(v_364);
    v_365 = stack[-4];
    v_364 = stack[-3];
    v_365 = list3(v_366, v_365, v_364);
    env = stack[-6];
    v_364 = basic_elt(env, 10); // (cons !$2 !$3)
    v_364 = list2(v_365, v_364);
    env = stack[-6];
    v_365 = list3(stack[-1], stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    stack[0] = stack[-5];
    v_365 = stack[-4];
    v_364 = stack[-3];
    v_365 = list2(v_365, v_364);
    env = stack[-6];
    v_364 = basic_elt(env, 6); // (cons !$1 !$2)
    v_364 = list2(v_365, v_364);
    env = stack[-6];
    v_365 = list2(stack[0], v_364);
    env = stack[-6];
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = cons(v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    v_364 = stack[-5];
    goto v_8;
v_232:
    v_365 = stack[-2];
    v_364 = basic_elt(env, 12); // or
    if (!consp(v_365)) goto v_311;
    v_365 = car(v_365);
    if (v_365 == v_364) goto v_310;
    else goto v_311;
v_310:
    {   LispObject fn = basic_elt(env, 14); // expansion_name
    v_364 = (*qfn0(fn))(fn);
    }
    env = stack[-6];
    stack[-5] = v_364;
    stack[-4] = stack[-5];
    v_364 = stack[-2];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    stack[-3] = v_364;
    v_364 = stack[-3];
    if (v_364 == nil) goto v_328;
    else goto v_329;
v_328:
    v_364 = nil;
    v_365 = v_364;
    goto v_322;
v_329:
    v_364 = stack[-3];
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_364 = ncons(v_364);
    env = stack[-6];
    v_364 = ncons(v_364);
    env = stack[-6];
    stack[-1] = v_364;
    stack[-2] = v_364;
v_323:
    v_364 = stack[-3];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    stack[-3] = v_364;
    v_364 = stack[-3];
    if (v_364 == nil) goto v_343;
    else goto v_344;
v_343:
    v_364 = stack[-2];
    v_365 = v_364;
    goto v_322;
v_344:
    stack[0] = stack[-1];
    v_364 = stack[-3];
    if (!car_legal(v_364)) v_364 = carerror(v_364); else
    v_364 = car(v_364);
    v_364 = ncons(v_364);
    env = stack[-6];
    v_364 = ncons(v_364);
    env = stack[-6];
    v_364 = ncons(v_364);
    env = stack[-6];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_364);
    v_364 = stack[-1];
    if (!car_legal(v_364)) v_364 = cdrerror(v_364); else
    v_364 = cdr(v_364);
    stack[-1] = v_364;
    goto v_323;
v_322:
    v_364 = qvalue(basic_elt(env, 3)); // pending_rules!*
    v_364 = acons(stack[-4], v_365, v_364);
    env = stack[-6];
    setvalue(basic_elt(env, 3), v_364); // pending_rules!*
    v_364 = stack[-5];
    goto v_8;
v_311:
    v_364 = basic_elt(env, 13); // "Invalid item in a rule"
    {   LispObject fn = basic_elt(env, 15); // rederr
    v_364 = (*qfn1(fn))(fn, v_364);
    }
    goto v_10;
v_10:
    v_364 = nil;
v_8:
    return onevalue(v_364);
}



// Code for not_included

static LispObject CC_not_included(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_51, v_52, v_53, v_54, v_55;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_53 = v_3;
    v_54 = v_2;
// end of prologue
    v_51 = lisp_true;
    v_55 = v_51;
v_11:
    v_51 = v_54;
    if (v_51 == nil) goto v_14;
    v_51 = v_55;
    if (v_51 == nil) goto v_14;
    goto v_15;
v_14:
    goto v_10;
v_15:
    v_51 = v_53;
    v_55 = v_51;
v_24:
    v_51 = v_55;
    if (v_51 == nil) goto v_27;
    v_51 = v_54;
    if (!car_legal(v_51)) v_52 = carerror(v_51); else
    v_52 = car(v_51);
    v_51 = v_55;
    if (!car_legal(v_51)) v_51 = carerror(v_51); else
    v_51 = car(v_51);
    if (equal(v_52, v_51)) goto v_27;
    goto v_28;
v_27:
    goto v_23;
v_28:
    v_51 = v_55;
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    v_55 = v_51;
    goto v_24;
v_23:
    v_51 = v_54;
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    v_54 = v_51;
    goto v_11;
v_10:
    v_51 = v_55;
    if (v_51 == nil) goto v_45;
    v_51 = nil;
    goto v_43;
v_45:
    v_51 = lisp_true;
    goto v_43;
    v_51 = nil;
v_43:
    return onevalue(v_51);
}



// Code for valuechk

static LispObject CC_valuechk(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_110, v_111, v_112;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_110 = stack[-2];
    if (!symbolp(v_110)) v_110 = nil;
    else { v_110 = qfastgets(v_110);
           if (v_110 != nil) { v_110 = elt(v_110, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_110 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_110 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_110 == SPID_NOPROP) v_110 = nil; }}
#endif
    stack[0] = v_110;
    if (v_110 == nil) goto v_12;
    v_110 = stack[-1];
    v_111 = Llength(nil, v_110);
    env = stack[-4];
    v_110 = stack[0];
    if (equal(v_111, v_110)) goto v_20;
    v_111 = stack[-2];
    v_110 = basic_elt(env, 1); // variadic
    v_110 = Lflagp(nil, v_111, v_110);
    env = stack[-4];
    v_110 = (v_110 == nil ? lisp_true : nil);
    goto v_18;
v_20:
    v_110 = nil;
    goto v_18;
    v_110 = nil;
v_18:
    if (v_110 == nil) goto v_12;
    goto v_10;
v_12:
    v_110 = stack[0];
    if (v_110 == nil) goto v_34;
    else goto v_35;
v_34:
    v_110 = stack[-1];
    if (v_110 == nil) goto v_39;
    else goto v_40;
v_39:
    v_110 = nil;
    goto v_38;
v_40:
    v_110 = stack[-1];
    if (!car_legal(v_110)) v_110 = cdrerror(v_110); else
    v_110 = cdr(v_110);
    if (v_110 == nil) goto v_47;
    else goto v_48;
v_47:
    v_110 = nil;
    goto v_46;
v_48:
    v_111 = stack[-2];
    v_110 = basic_elt(env, 2); // !:rd!:
    v_110 = get(v_111, v_110);
    env = stack[-4];
    if (v_110 == nil) goto v_56;
    else goto v_55;
v_56:
    v_111 = stack[-2];
    v_110 = basic_elt(env, 3); // !:rn!:
    v_110 = get(v_111, v_110);
    env = stack[-4];
v_55:
    goto v_46;
    v_110 = nil;
v_46:
    goto v_38;
    v_110 = nil;
v_38:
    goto v_33;
v_35:
    v_110 = nil;
    goto v_33;
    v_110 = nil;
v_33:
    if (v_110 == nil) goto v_31;
    else goto v_10;
v_31:
    goto v_11;
v_10:
    v_110 = qvalue(basic_elt(env, 4)); // !*strict_argcount
    if (v_110 == nil) goto v_69;
    stack[-3] = basic_elt(env, 5); // alg
    stack[0] = (LispObject)272+TAG_FIXNUM; // 17
    v_111 = basic_elt(env, 6); // "Wrong number of arguments to"
    v_110 = stack[-2];
    v_110 = list2(v_111, v_110);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // rerror
    v_110 = (*qfn3(fn))(fn, stack[-3], stack[0], v_110);
    }
    env = stack[-4];
    goto v_67;
v_69:
    v_111 = basic_elt(env, 6); // "Wrong number of arguments to"
    v_110 = stack[-2];
    v_110 = list2(v_111, v_110);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 9); // lprim
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-4];
    goto v_67;
v_67:
    goto v_9;
v_11:
v_9:
    v_111 = stack[-2];
    v_110 = stack[-1];
    v_110 = cons(v_111, v_110);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 10); // opfchk!!
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-4];
    stack[-1] = v_110;
    v_110 = stack[-1];
    if (v_110 == nil) goto v_90;
    v_111 = stack[-1];
    v_110 = basic_elt(env, 7); // list
    if (!consp(v_111)) goto v_97;
    v_111 = car(v_111);
    if (v_111 == v_110) goto v_96;
    else goto v_97;
v_96:
    v_112 = stack[-1];
    v_111 = (LispObject)16+TAG_FIXNUM; // 1
    v_110 = (LispObject)16+TAG_FIXNUM; // 1
    v_110 = acons(v_112, v_111, v_110);
    env = stack[-4];
    v_110 = ncons(v_110);
    env = stack[-4];
    v_111 = v_110;
    goto v_95;
v_97:
    v_110 = stack[-1];
    v_111 = v_110;
    goto v_95;
    v_111 = nil;
v_95:
    v_110 = (LispObject)16+TAG_FIXNUM; // 1
    v_110 = cons(v_111, v_110);
    env = stack[-4];
    {
        LispObject fn = basic_elt(env, 11); // znumrnil
        return (*qfn1(fn))(fn, v_110);
    }
v_90:
    v_110 = nil;
    return onevalue(v_110);
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // cgp_rp
    v_7 = (*qfn1(fn))(fn, v_7);
    }
    v_7 = (v_7 == nil ? lisp_true : nil);
    return onevalue(v_7);
}



// Code for integralir

static LispObject CC_integralir(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_53, v_54;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// end of prologue
    v_54 = qvalue(basic_elt(env, 1)); // atts
    v_53 = basic_elt(env, 2); // name
    {   LispObject fn = basic_elt(env, 6); // find
    v_53 = (*qfn2(fn))(fn, v_54, v_53);
    }
    env = stack[-3];
    v_53 = Lintern(nil, v_53);
    env = stack[-3];
    stack[-1] = v_53;
    v_53 = basic_elt(env, 3); // (bvar x 1)
    v_53 = ncons(v_53);
    env = stack[-3];
    stack[0] = v_53;
    v_54 = stack[-1];
    v_53 = basic_elt(env, 4); // defint
    if (v_54 == v_53) goto v_18;
    else goto v_19;
v_18:
    {   LispObject fn = basic_elt(env, 7); // lex
    v_53 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 8); // omobj
    v_53 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    goto v_17;
v_19:
v_17:
    {   LispObject fn = basic_elt(env, 7); // lex
    v_53 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 8); // omobj
    v_53 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    stack[-2] = v_53;
    v_53 = stack[-2];
    v_53 = Lconsp(nil, v_53);
    env = stack[-3];
    if (v_53 == nil) goto v_30;
    v_53 = stack[-2];
    if (!car_legal(v_53)) v_54 = carerror(v_53); else
    v_54 = car(v_53);
    v_53 = basic_elt(env, 5); // lambda
    if (v_54 == v_53) goto v_35;
    else goto v_36;
v_35:
    v_53 = stack[-2];
    {   LispObject fn = basic_elt(env, 9); // lambdavar
    v_53 = (*qfn1(fn))(fn, v_53);
    }
    env = stack[-3];
    stack[0] = v_53;
    v_53 = stack[-2];
    {   LispObject fn = basic_elt(env, 10); // lambdafun
    v_53 = (*qfn1(fn))(fn, v_53);
    }
    env = stack[-3];
    stack[-2] = v_53;
    goto v_34;
v_36:
v_34:
    goto v_28;
v_30:
v_28:
    v_54 = stack[-1];
    v_53 = nil;
    stack[-1] = list2(v_54, v_53);
    env = stack[-3];
    v_53 = stack[-2];
    v_53 = ncons(v_53);
    env = stack[-3];
    v_53 = Lappend_2(nil, stack[0], v_53);
    {
        LispObject v_58 = stack[-1];
        return Lappend_2(nil, v_58, v_53);
    }
    return onevalue(v_53);
}



// Code for specrd!:times

static LispObject CC_specrdTtimes(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_66, v_67;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
    v_66 = stack[-1];
    {   LispObject fn = basic_elt(env, 2); // add_minus
    v_66 = (*qfn1(fn))(fn, v_66);
    }
    env = stack[-3];
    stack[-1] = v_66;
    v_66 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // add_minus
    v_66 = (*qfn1(fn))(fn, v_66);
    }
    env = stack[-3];
    stack[0] = v_66;
    v_67 = stack[-1];
    v_66 = basic_elt(env, 1); // minus
    if (!consp(v_67)) goto v_15;
    v_67 = car(v_67);
    if (v_67 == v_66) goto v_14;
    else goto v_15;
v_14:
    v_66 = stack[-1];
    if (!car_legal(v_66)) v_66 = cdrerror(v_66); else
    v_66 = cdr(v_66);
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = car(v_66);
    stack[-1] = v_66;
    v_66 = lisp_true;
    stack[-2] = v_66;
    goto v_13;
v_15:
v_13:
    v_67 = stack[0];
    v_66 = basic_elt(env, 1); // minus
    if (!consp(v_67)) goto v_26;
    v_67 = car(v_67);
    if (v_67 == v_66) goto v_25;
    else goto v_26;
v_25:
    v_66 = stack[0];
    if (!car_legal(v_66)) v_66 = cdrerror(v_66); else
    v_66 = cdr(v_66);
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = car(v_66);
    stack[0] = v_66;
    v_66 = stack[-2];
    v_66 = (v_66 == nil ? lisp_true : nil);
    stack[-2] = v_66;
    goto v_24;
v_26:
v_24:
    v_66 = stack[-1];
    if (!consp(v_66)) goto v_37;
    else goto v_38;
v_37:
    v_66 = stack[-1];
    v_66 = Lfloat(nil, v_66);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 3); // mkround
    v_66 = (*qfn1(fn))(fn, v_66);
    }
    env = stack[-3];
    stack[-1] = v_66;
    goto v_36;
v_38:
v_36:
    v_66 = stack[0];
    if (!consp(v_66)) goto v_45;
    else goto v_46;
v_45:
    v_66 = stack[0];
    v_66 = Lfloat(nil, v_66);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 3); // mkround
    v_66 = (*qfn1(fn))(fn, v_66);
    }
    env = stack[-3];
    stack[0] = v_66;
    goto v_44;
v_46:
v_44:
    v_66 = stack[-2];
    if (v_66 == nil) goto v_54;
    stack[-2] = basic_elt(env, 1); // minus
    v_67 = stack[-1];
    v_66 = stack[0];
    {   LispObject fn = basic_elt(env, 4); // rd!:times
    v_66 = (*qfn2(fn))(fn, v_67, v_66);
    }
    {
        LispObject v_71 = stack[-2];
        return list2(v_71, v_66);
    }
v_54:
    v_67 = stack[-1];
    v_66 = stack[0];
    {
        LispObject fn = basic_elt(env, 4); // rd!:times
        return (*qfn2(fn))(fn, v_67, v_66);
    }
    v_66 = nil;
    return onevalue(v_66);
}



// Code for dip2a

static LispObject CC_dip2a(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16 = v_2;
// end of prologue
    v_15 = v_16;
    if (v_15 == nil) goto v_6;
    else goto v_7;
v_6:
    v_15 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5;
v_7:
    v_15 = v_16;
    {   LispObject fn = basic_elt(env, 1); // dip2a1
    v_15 = (*qfn1(fn))(fn, v_15);
    }
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // dipreplus
        return (*qfn1(fn))(fn, v_15);
    }
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for evalmember

static LispObject CC_evalmember(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9 = v_3;
    v_10 = v_2;
// end of prologue
    stack[0] = v_10;
    {   LispObject fn = basic_elt(env, 1); // getrlist
    v_9 = (*qfn1(fn))(fn, v_9);
    }
    v_9 = Lmember(nil, stack[0], v_9);
    return onevalue(v_9);
}



// Code for gbfdiff

static LispObject CC_gbfdiff(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_16, v_17;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_16 = stack[-1];
    if (!car_legal(v_16)) v_17 = carerror(v_16); else
    v_17 = car(v_16);
    v_16 = stack[0];
    if (!car_legal(v_16)) v_16 = carerror(v_16); else
    v_16 = car(v_16);
    {   LispObject fn = basic_elt(env, 1); // difbf
    stack[-2] = (*qfn2(fn))(fn, v_17, v_16);
    }
    env = stack[-3];
    v_16 = stack[-1];
    if (!car_legal(v_16)) v_17 = cdrerror(v_16); else
    v_17 = cdr(v_16);
    v_16 = stack[0];
    if (!car_legal(v_16)) v_16 = cdrerror(v_16); else
    v_16 = cdr(v_16);
    {   LispObject fn = basic_elt(env, 1); // difbf
    v_16 = (*qfn2(fn))(fn, v_17, v_16);
    }
    {
        LispObject v_21 = stack[-2];
        return cons(v_21, v_16);
    }
}



// Code for gpargp

static LispObject CC_gpargp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_16 = stack[0];
    v_16 = Lstringp(nil, v_16);
    env = stack[-1];
    if (v_16 == nil) goto v_6;
    else goto v_5;
v_6:
    v_16 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // gpexpp
    v_16 = (*qfn1(fn))(fn, v_16);
    }
    env = stack[-1];
    if (v_16 == nil) goto v_11;
    else goto v_10;
v_11:
    v_16 = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // gplogexpp
        return (*qfn1(fn))(fn, v_16);
    }
v_10:
v_5:
    return onevalue(v_16);
}



// Code for indexvp

static LispObject CC_indexvp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_16 = v_15;
    if (!consp(v_16)) goto v_7;
    if (!car_legal(v_15)) v_15 = carerror(v_15); else
    v_15 = car(v_15);
    if (!symbolp(v_15)) v_15 = nil;
    else { v_15 = qfastgets(v_15);
           if (v_15 != nil) { v_15 = elt(v_15, 16); // indexvar
#ifdef RECORD_GET
             if (v_15 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_15 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_15 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_15 == SPID_NOPROP) v_15 = nil; else v_15 = lisp_true; }}
#endif
    goto v_5;
v_7:
    v_15 = nil;
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for mk_simpl_map_

static LispObject CC_mk_simpl_map_(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7, v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    v_8 = v_7;
    v_7 = nil;
    {
        LispObject fn = basic_elt(env, 1); // mk_simpl_map_1
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for simpdfp

static LispObject CC_simpdfp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_222, v_223, v_224, v_225, v_226;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_222 = stack[0];
    v_223 = Llength(nil, v_222);
    env = stack[-6];
    v_222 = (LispObject)32+TAG_FIXNUM; // 2
    v_222 = (LispObject)lessp2(v_223, v_222);
    v_222 = v_222 ? lisp_true : nil;
    env = stack[-6];
    if (v_222 == nil) goto v_16;
    goto v_12;
v_16:
    v_222 = stack[0];
    if (!car_legal(v_222)) v_222 = carerror(v_222); else
    v_222 = car(v_222);
    {   LispObject fn = basic_elt(env, 10); // reval
    v_222 = (*qfn1(fn))(fn, v_222);
    }
    env = stack[-6];
    stack[-5] = v_222;
    v_222 = stack[-5];
    v_222 = Lconsp(nil, v_222);
    env = stack[-6];
    if (v_222 == nil) goto v_26;
    else goto v_27;
v_26:
    v_222 = stack[0];
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    if (!car_legal(v_222)) v_223 = carerror(v_222); else
    v_223 = car(v_222);
    v_222 = qvalue(basic_elt(env, 1)); // frlis!*
    v_222 = Lmember(nil, v_223, v_222);
    if (v_222 == nil) goto v_33;
    v_223 = basic_elt(env, 2); // dfp
    v_222 = stack[0];
    v_223 = cons(v_223, v_222);
    env = stack[-6];
    v_222 = (LispObject)16+TAG_FIXNUM; // 1
    {
        LispObject fn = basic_elt(env, 11); // mksq
        return (*qfn2(fn))(fn, v_223, v_222);
    }
v_33:
    v_223 = stack[-5];
    v_222 = stack[0];
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    if (!car_legal(v_222)) v_222 = carerror(v_222); else
    v_222 = car(v_222);
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    v_222 = cons(v_223, v_222);
    env = stack[-6];
    {
        LispObject fn = basic_elt(env, 12); // simpdf
        return (*qfn1(fn))(fn, v_222);
    }
    v_222 = nil;
    goto v_11;
v_27:
    v_222 = stack[-5];
    if (!car_legal(v_222)) v_222 = carerror(v_222); else
    v_222 = car(v_222);
    stack[-1] = v_222;
    v_222 = stack[0];
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    if (!car_legal(v_222)) v_222 = carerror(v_222); else
    v_222 = car(v_222);
    {   LispObject fn = basic_elt(env, 10); // reval
    v_222 = (*qfn1(fn))(fn, v_222);
    }
    env = stack[-6];
    v_226 = v_222;
    v_223 = v_226;
    v_222 = qvalue(basic_elt(env, 1)); // frlis!*
    v_222 = Lmember(nil, v_223, v_222);
    if (v_222 == nil) goto v_67;
    else goto v_68;
v_67:
    v_223 = v_226;
    v_222 = basic_elt(env, 3); // list
    v_222 = Leqcar(nil, v_223, v_222);
    env = stack[-6];
    v_222 = (v_222 == nil ? lisp_true : nil);
    goto v_66;
v_68:
    v_222 = nil;
    goto v_66;
    v_222 = nil;
v_66:
    if (v_222 == nil) goto v_64;
    stack[-4] = v_226;
    v_222 = stack[0];
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    stack[-3] = v_222;
    v_222 = stack[-3];
    if (v_222 == nil) goto v_92;
    else goto v_93;
v_92:
    v_222 = nil;
    goto v_85;
v_93:
    v_222 = stack[-3];
    if (!car_legal(v_222)) v_222 = carerror(v_222); else
    v_222 = car(v_222);
    {   LispObject fn = basic_elt(env, 10); // reval
    v_222 = (*qfn1(fn))(fn, v_222);
    }
    env = stack[-6];
    v_222 = ncons(v_222);
    env = stack[-6];
    stack[-1] = v_222;
    stack[-2] = v_222;
v_86:
    v_222 = stack[-3];
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    stack[-3] = v_222;
    v_222 = stack[-3];
    if (v_222 == nil) goto v_106;
    else goto v_107;
v_106:
    v_222 = stack[-2];
    goto v_85;
v_107:
    stack[0] = stack[-1];
    v_222 = stack[-3];
    if (!car_legal(v_222)) v_222 = carerror(v_222); else
    v_222 = car(v_222);
    {   LispObject fn = basic_elt(env, 10); // reval
    v_222 = (*qfn1(fn))(fn, v_222);
    }
    env = stack[-6];
    v_222 = ncons(v_222);
    env = stack[-6];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_222);
    v_222 = stack[-1];
    if (!car_legal(v_222)) v_222 = cdrerror(v_222); else
    v_222 = cdr(v_222);
    stack[-1] = v_222;
    goto v_86;
v_85:
    v_222 = cons(stack[-4], v_222);
    env = stack[-6];
    v_226 = v_222;
    stack[0] = basic_elt(env, 3); // list
    v_223 = v_226;
    v_222 = nil;
    {   LispObject fn = basic_elt(env, 13); // dfp!-normalize
    v_222 = (*qfn2(fn))(fn, v_223, v_222);
    }
    env = stack[-6];
    v_222 = cons(stack[0], v_222);
    env = stack[-6];
    v_226 = v_222;
    v_223 = basic_elt(env, 2); // dfp
    v_222 = stack[-5];
    v_224 = v_226;
    v_222 = list3(v_223, v_222, v_224);
    env = stack[-6];
    {
        LispObject fn = basic_elt(env, 14); // simp
        return (*qfn1(fn))(fn, v_222);
    }
v_64:
    v_223 = stack[-1];
    v_222 = basic_elt(env, 4); // generic_function
    v_222 = get(v_223, v_222);
    env = stack[-6];
    v_225 = v_222;
    v_222 = lisp_true;
    v_223 = v_225;
    if (v_223 == nil) goto v_138;
    v_224 = v_226;
    v_223 = basic_elt(env, 3); // list
    if (!consp(v_224)) goto v_138;
    v_224 = car(v_224);
    if (v_224 == v_223) goto v_141;
    else goto v_138;
v_141:
    v_223 = v_226;
    if (!car_legal(v_223)) v_223 = cdrerror(v_223); else
    v_223 = cdr(v_223);
    v_224 = v_223;
v_148:
    v_223 = v_224;
    if (v_223 == nil) goto v_153;
    else goto v_154;
v_153:
    goto v_147;
v_154:
    v_223 = v_224;
    if (!car_legal(v_223)) v_223 = carerror(v_223); else
    v_223 = car(v_223);
    if (v_222 == nil) goto v_162;
    else goto v_163;
v_162:
    v_222 = nil;
    goto v_161;
v_163:
    v_222 = v_225;
    v_222 = Lmember(nil, v_223, v_222);
    goto v_161;
    v_222 = nil;
v_161:
    v_223 = v_224;
    if (!car_legal(v_223)) v_223 = cdrerror(v_223); else
    v_223 = cdr(v_223);
    v_224 = v_223;
    goto v_148;
v_147:
    goto v_136;
v_138:
v_136:
    if (v_222 == nil) goto v_175;
    else goto v_176;
v_175:
    v_223 = nil;
    v_222 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_223, v_222);
v_176:
    v_223 = v_226;
    v_222 = basic_elt(env, 5); // (list)
    if (equal(v_223, v_222)) goto v_183;
    else goto v_184;
v_183:
    v_223 = stack[-5];
    v_222 = (LispObject)16+TAG_FIXNUM; // 1
    {
        LispObject fn = basic_elt(env, 11); // mksq
        return (*qfn2(fn))(fn, v_223, v_222);
    }
v_184:
    v_222 = v_225;
    if (v_222 == nil) goto v_193;
    v_223 = stack[-1];
    v_222 = basic_elt(env, 6); // dfp_commute
    v_222 = Lflagp(nil, v_223, v_222);
    env = stack[-6];
    if (v_222 == nil) goto v_193;
    v_222 = v_225;
// Binding kord!*
// FLUIDBIND: reloadenv=6 litvec-offset=7 saveloc=1
{   bind_fluid_stack bind_fluid_var(-6, 7, -1);
    setvalue(basic_elt(env, 7), v_222); // kord!*
    stack[0] = basic_elt(env, 3); // list
    v_222 = v_226;
    if (!car_legal(v_222)) v_223 = cdrerror(v_222); else
    v_223 = cdr(v_222);
    v_222 = basic_elt(env, 8); // ordp
    {   LispObject fn = basic_elt(env, 15); // sort
    v_222 = (*qfn2(fn))(fn, v_223, v_222);
    }
    env = stack[-6];
    v_222 = cons(stack[0], v_222);
    env = stack[-6];
    v_226 = v_222;
    ;}  // end of a binding scope
    goto v_191;
v_193:
v_191:
    v_223 = basic_elt(env, 2); // dfp
    v_222 = stack[-5];
    v_224 = v_226;
    v_222 = list3(v_223, v_222, v_224);
    env = stack[-6];
    stack[0] = v_222;
    v_223 = stack[0];
    v_222 = (LispObject)16+TAG_FIXNUM; // 1
    {
        LispObject fn = basic_elt(env, 11); // mksq
        return (*qfn2(fn))(fn, v_223, v_222);
    }
v_12:
    v_223 = basic_elt(env, 2); // dfp
    v_222 = stack[0];
    v_223 = cons(v_223, v_222);
    env = stack[-6];
    v_222 = basic_elt(env, 9); // "generic differential"
    {   LispObject fn = basic_elt(env, 16); // typerr
    v_222 = (*qfn2(fn))(fn, v_223, v_222);
    }
    v_222 = nil;
v_11:
    return onevalue(v_222);
}



// Code for balance_mod

static LispObject CC_balance_mod(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_20, v_21;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_21 = stack[-1];
    v_20 = stack[-1];
    v_21 = plus2(v_21, v_20);
    env = stack[-2];
    v_20 = stack[0];
    v_20 = (LispObject)greaterp2(v_21, v_20);
    v_20 = v_20 ? lisp_true : nil;
    if (v_20 == nil) goto v_8;
    v_21 = stack[-1];
    v_20 = stack[0];
    return difference2(v_21, v_20);
v_8:
    v_20 = stack[-1];
    goto v_6;
    v_20 = nil;
v_6:
    return onevalue(v_20);
}



// Code for super_vectorfield

static LispObject CC_super_vectorfield(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_153, v_154, v_155;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_4;
    stack[-4] = v_3;
    stack[-5] = v_2;
// end of prologue
    v_153 = stack[-5];
    if (symbolp(v_153)) goto v_12;
    stack[-3] = basic_elt(env, 1); // "SUPER_VECTORFIELD:"
    stack[-2] = stack[-5];
    stack[0] = basic_elt(env, 2); // "is not an identifier"
    v_154 = nil;
    v_153 = lisp_true;
    v_153 = list2(v_154, v_153);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 14); // msgpri
    v_153 = (*qfn4up(fn))(fn, stack[-3], stack[-2], stack[0], v_153);
    }
    env = stack[-7];
    goto v_10;
v_12:
v_10:
    v_155 = stack[-5];
    v_154 = basic_elt(env, 3); // simpfn
    v_153 = basic_elt(env, 4); // super_der_simp
    v_153 = Lputprop(nil, v_155, v_154, v_153);
    env = stack[-7];
    v_153 = stack[-5];
    v_154 = ncons(v_153);
    env = stack[-7];
    v_153 = basic_elt(env, 5); // full
    v_153 = Lflag(nil, v_154, v_153);
    env = stack[-7];
    v_153 = stack[-4];
    if (v_153 == nil) goto v_31;
    else goto v_32;
v_31:
    v_153 = stack[-4];
    goto v_30;
v_32:
    v_153 = stack[-4];
    if (!consp(v_153)) goto v_35;
    else goto v_36;
v_35:
    v_153 = stack[-4];
    v_153 = ncons(v_153);
    env = stack[-7];
    goto v_30;
v_36:
    v_153 = stack[-4];
    if (!car_legal(v_153)) v_154 = carerror(v_153); else
    v_154 = car(v_153);
    v_153 = basic_elt(env, 6); // list
    if (v_154 == v_153) goto v_40;
    else goto v_41;
v_40:
    v_153 = stack[-4];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = cdr(v_153);
    goto v_30;
v_41:
    v_153 = stack[-4];
    goto v_30;
    v_153 = nil;
v_30:
    stack[-4] = v_153;
    v_153 = stack[-1];
    if (v_153 == nil) goto v_52;
    else goto v_53;
v_52:
    v_153 = stack[-1];
    goto v_51;
v_53:
    v_153 = stack[-1];
    if (!consp(v_153)) goto v_56;
    else goto v_57;
v_56:
    v_153 = stack[-1];
    v_153 = ncons(v_153);
    env = stack[-7];
    goto v_51;
v_57:
    v_153 = stack[-1];
    if (!car_legal(v_153)) v_154 = carerror(v_153); else
    v_154 = car(v_153);
    v_153 = basic_elt(env, 6); // list
    if (v_154 == v_153) goto v_61;
    else goto v_62;
v_61:
    v_153 = stack[-1];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = cdr(v_153);
    goto v_51;
v_62:
    v_153 = stack[-1];
    goto v_51;
    v_153 = nil;
v_51:
    stack[-1] = v_153;
    v_153 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_153;
    v_153 = stack[-1];
    stack[-3] = v_153;
v_75:
    v_153 = stack[-3];
    if (v_153 == nil) goto v_79;
    else goto v_80;
v_79:
    goto v_74;
v_80:
    v_153 = stack[-3];
    if (!car_legal(v_153)) v_153 = carerror(v_153); else
    v_153 = car(v_153);
    stack[0] = v_153;
    v_153 = stack[0];
    v_154 = Llength(nil, v_153);
    env = stack[-7];
    v_153 = (LispObject)32+TAG_FIXNUM; // 2
    if (v_154 == v_153) goto v_93;
    v_153 = lisp_true;
    goto v_91;
v_93:
    v_153 = stack[0];
    if (!car_legal(v_153)) v_154 = carerror(v_153); else
    v_154 = car(v_153);
    v_153 = basic_elt(env, 7); // ext
    if (v_154 == v_153) goto v_103;
    v_153 = lisp_true;
    goto v_101;
v_103:
    v_153 = stack[0];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = cdr(v_153);
    if (!car_legal(v_153)) v_153 = carerror(v_153); else
    v_153 = car(v_153);
    v_153 = integerp(v_153);
    v_153 = (v_153 == nil ? lisp_true : nil);
    goto v_101;
    v_153 = nil;
v_101:
    goto v_91;
    v_153 = nil;
v_91:
    if (v_153 == nil) goto v_89;
    stack[-2] = basic_elt(env, 1); // "SUPER_VECTORFIELD:"
    stack[-1] = stack[0];
    stack[0] = basic_elt(env, 8); // "not a valid odd variable"
    v_154 = nil;
    v_153 = lisp_true;
    v_153 = list2(v_154, v_153);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 14); // msgpri
    v_153 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_153);
    }
    env = stack[-7];
    goto v_87;
v_89:
    v_154 = stack[-6];
    v_153 = stack[0];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = cdr(v_153);
    if (!car_legal(v_153)) v_153 = carerror(v_153); else
    v_153 = car(v_153);
    {   LispObject fn = basic_elt(env, 15); // max
    v_153 = (*qfn2(fn))(fn, v_154, v_153);
    }
    env = stack[-7];
    stack[-6] = v_153;
    goto v_87;
v_87:
    v_153 = stack[-3];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = cdr(v_153);
    stack[-3] = v_153;
    goto v_75;
v_74:
    v_155 = stack[-5];
    v_154 = basic_elt(env, 9); // variables
    v_153 = stack[-4];
    v_153 = Lputprop(nil, v_155, v_154, v_153);
    env = stack[-7];
    stack[-1] = stack[-5];
    stack[0] = basic_elt(env, 10); // even_dimension
    v_153 = stack[-4];
    v_153 = Llength(nil, v_153);
    env = stack[-7];
    v_153 = Lputprop(nil, stack[-1], stack[0], v_153);
    env = stack[-7];
    v_155 = stack[-5];
    v_154 = basic_elt(env, 11); // odd_dimension
    v_153 = stack[-6];
    v_153 = Lputprop(nil, v_155, v_154, v_153);
    env = stack[-7];
    v_155 = stack[-5];
    v_154 = basic_elt(env, 12); // setkfn
    v_153 = basic_elt(env, 13); // setk_super_vectorfield
    v_153 = Lputprop(nil, v_155, v_154, v_153);
    env = stack[-7];
    stack[0] = basic_elt(env, 6); // list
    v_153 = stack[-4];
    v_154 = Llength(nil, v_153);
    v_153 = stack[-6];
    {
        LispObject v_163 = stack[0];
        return list3(v_163, v_154, v_153);
    }
    return onevalue(v_153);
}



// Code for rtypepart

static LispObject CC_rtypepart(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_14 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 2); // getrtypecar
    v_14 = (*qfn1(fn))(fn, v_14);
    }
    env = stack[0];
    if (v_14 == nil) goto v_7;
    v_14 = basic_elt(env, 1); // yetunknowntype
    goto v_5;
v_7:
    v_14 = nil;
    goto v_5;
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for fctlength

static LispObject CC_fctlength(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
#endif // CONSERVATIVE
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // fctargs
    v_7 = (*qfn1(fn))(fn, v_7);
    }
        return Llength(nil, v_7);
}



// Code for gigcdsq

static LispObject CC_gigcdsq(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41, v_42;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_41 = stack[-1];
    if (v_41 == nil) goto v_8;
    v_42 = stack[0];
    v_41 = (LispObject)0+TAG_FIXNUM; // 0
    {   LispObject fn = basic_elt(env, 1); // giintgcd
    v_41 = (*qfn2(fn))(fn, v_42, v_41);
    }
    env = stack[-3];
    stack[-2] = v_41;
    v_42 = stack[-2];
    v_41 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_42 == v_41) goto v_21;
    v_42 = stack[-1];
    v_41 = stack[-2];
    {   LispObject fn = basic_elt(env, 1); // giintgcd
    v_42 = (*qfn2(fn))(fn, v_42, v_41);
    }
    env = stack[-3];
    stack[-2] = v_42;
    v_41 = (LispObject)16+TAG_FIXNUM; // 1
    v_41 = Lneq_2(nil, v_42, v_41);
    env = stack[-3];
    goto v_19;
v_21:
    v_41 = nil;
    goto v_19;
    v_41 = nil;
v_19:
    if (v_41 == nil) goto v_17;
    v_42 = stack[-1];
    v_41 = stack[-2];
    {   LispObject fn = basic_elt(env, 2); // quotf
    v_41 = (*qfn2(fn))(fn, v_42, v_41);
    }
    env = stack[-3];
    stack[-1] = v_41;
    v_42 = stack[0];
    v_41 = stack[-2];
    {   LispObject fn = basic_elt(env, 2); // quotf
    v_41 = (*qfn2(fn))(fn, v_42, v_41);
    }
    stack[0] = v_41;
    goto v_15;
v_17:
v_15:
    goto v_6;
v_8:
v_6:
    v_42 = stack[-1];
    v_41 = stack[0];
    return cons(v_42, v_41);
}



// Code for subtractinds

static LispObject CC_subtractinds(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_45, v_46;
#ifdef CHECK_STACK
    if_check_stack;
#endif
#ifdef CONSERVATIVE
    poll();
#else // CONSERVATIVE
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stackLimit)
    {
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
#endif // CONSERVATIVE
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_4;
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
v_10:
    v_45 = stack[-2];
    if (v_45 == nil) goto v_13;
    else goto v_14;
v_13:
    v_45 = stack[-1];
        return Lnreverse(nil, v_45);
v_14:
    v_45 = stack[-3];
    if (!car_legal(v_45)) v_46 = carerror(v_45); else
    v_46 = car(v_45);
    v_45 = stack[-2];
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = car(v_45);
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = car(v_45);
    v_46 = difference2(v_46, v_45);
    env = stack[-5];
    v_45 = (LispObject)0+TAG_FIXNUM; // 0
    v_45 = (LispObject)lessp2(v_46, v_45);
    v_45 = v_45 ? lisp_true : nil;
    env = stack[-5];
    if (v_45 == nil) goto v_19;
    v_45 = nil;
    goto v_9;
v_19:
    v_45 = stack[-3];
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = cdr(v_45);
    stack[-4] = v_45;
    v_45 = stack[-2];
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = cdr(v_45);
    stack[0] = v_45;
    v_45 = stack[-3];
    if (!car_legal(v_45)) v_46 = carerror(v_45); else
    v_46 = car(v_45);
    v_45 = stack[-2];
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = car(v_45);
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = car(v_45);
    v_46 = difference2(v_46, v_45);
    env = stack[-5];
    v_45 = stack[-1];
    v_45 = cons(v_46, v_45);
    env = stack[-5];
    stack[-1] = v_45;
    v_45 = stack[0];
    stack[-2] = v_45;
    v_45 = stack[-4];
    stack[-3] = v_45;
    goto v_10;
    v_45 = nil;
v_9:
    return onevalue(v_45);
}



setup_type const u43_setup[] =
{
    {"xquotient-mod-p",         G0W3,     G1W3,     G2W3,     CC_xquotientKmodKp,G4W3},
    {"mkcrn",                   G0W2,     G1W2,     CC_mkcrn, G3W2,     G4W2},
    {"extadd",                  G0W2,     G1W2,     CC_extadd,G3W2,     G4W2},
    {"read-comment1",           G0W1,     CC_readKcomment1,G2W1,G3W1,   G4W1},
    {"sfto_yun-updecf",         G0W1,     CC_sfto_yunKupdecf,G2W1,G3W1, G4W1},
    {"rl_identity1",            G0W1,     CC_rl_identity1,G2W1,G3W1,    G4W1},
    {"pasf_anegateat",          G0W1,     CC_pasf_anegateat,G2W1,G3W1,  G4W1},
    {"bc_sum",                  G0W2,     G1W2,     CC_bc_sum,G3W2,     G4W2},
    {"ciom",                    G0W1,     CC_ciom,  G2W1,     G3W1,     G4W1},
    {"f4",                      G0W1,     CC_f4,    G2W1,     G3W1,     G4W1},
    {"evzero",                  CC_evzero,G1W0,     G2W0,     G3W0,     G4W0},
    {"chksymmetries&sub1",      G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_chksymmetriesGsub1},
    {"strand-alg-top",          G0W3,     G1W3,     G2W3,     CC_strandKalgKtop,G4W3},
    {"cali=min",                G0W3,     G1W3,     G2W3,     CC_caliMmin,G4W3},
    {"appr",                    G0W2,     G1W2,     CC_appr,  G3W2,     G4W2},
    {"sfto_psrem",              G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_sfto_psrem},
    {"co_hfn",                  G0W1,     CC_co_hfn,G2W1,     G3W1,     G4W1},
    {"ofsf_updsigndom",         G0W1,     CC_ofsf_updsigndom,G2W1,G3W1, G4W1},
    {"change+int+to+sq",        G0W1,     CC_changeLintLtoLsq,G2W1,G3W1,G4W1},
    {"cl_subfof",               G0W2,     G1W2,     CC_cl_subfof,G3W2,  G4W2},
    {"rl_sacatlp",              G0W2,     G1W2,     CC_rl_sacatlp,G3W2, G4W2},
    {"conditionml",             G0W1,     CC_conditionml,G2W1,G3W1,     G4W1},
    {"simpu",                   G0W1,     CC_simpu, G2W1,     G3W1,     G4W1},
    {"assgnpri",                G0W3,     G1W3,     G2W3,     CC_assgnpri,G4W3},
    {"qsimpcomb_standard_integer_part_sf",G0W1,CC_qsimpcomb_standard_integer_part_sf,G2W1,G3W1,G4W1},
    {"a2vdp",                   G0W1,     CC_a2vdp, G2W1,     G3W1,     G4W1},
    {"markedvarp",              G0W1,     CC_markedvarp,G2W1, G3W1,     G4W1},
    {"evalwhereexp",            G0W1,     CC_evalwhereexp,G2W1,G3W1,    G4W1},
    {"mv-compact2",             G0W2,     G1W2,     CC_mvKcompact2,G3W2,G4W2},
    {"extract_vars",            G0W1,     CC_extract_vars,G2W1,G3W1,    G4W1},
    {"expand_terminal",         G0W1,     CC_expand_terminal,G2W1,G3W1, G4W1},
    {"not_included",            G0W2,     G1W2,     CC_not_included,G3W2,G4W2},
    {"valuechk",                G0W2,     G1W2,     CC_valuechk,G3W2,   G4W2},
    {"cgp_greenp",              G0W1,     CC_cgp_greenp,G2W1, G3W1,     G4W1},
    {"integralir",              CC_integralir,G1W0, G2W0,     G3W0,     G4W0},
    {"specrd:times",            G0W2,     G1W2,     CC_specrdTtimes,G3W2,G4W2},
    {"dip2a",                   G0W1,     CC_dip2a, G2W1,     G3W1,     G4W1},
    {"evalmember",              G0W2,     G1W2,     CC_evalmember,G3W2, G4W2},
    {"gbfdiff",                 G0W2,     G1W2,     CC_gbfdiff,G3W2,    G4W2},
    {"gpargp",                  G0W1,     CC_gpargp,G2W1,     G3W1,     G4W1},
    {"indexvp",                 G0W1,     CC_indexvp,G2W1,    G3W1,     G4W1},
    {"mk_simpl_map_",           G0W1,     CC_mk_simpl_map_,G2W1,G3W1,   G4W1},
    {"simpdfp",                 G0W1,     CC_simpdfp,G2W1,    G3W1,     G4W1},
    {"balance_mod",             G0W2,     G1W2,     CC_balance_mod,G3W2,G4W2},
    {"super_vectorfield",       G0W3,     G1W3,     G2W3,     CC_super_vectorfield,G4W3},
    {"rtypepart",               G0W1,     CC_rtypepart,G2W1,  G3W1,     G4W1},
    {"fctlength",               G0W1,     CC_fctlength,G2W1,  G3W1,     G4W1},
    {"gigcdsq",                 G0W2,     G1W2,     CC_gigcdsq,G3W2,    G4W2},
    {"subtractinds",            G0W3,     G1W3,     G2W3,     CC_subtractinds,G4W3},
    {NULL, (no_args *)"u43", (one_arg *)"120711 2091747 8134471",
        NULL, NULL, NULL}
};

// end of generated code
