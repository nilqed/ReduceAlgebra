// charmetrics.c                           Copyright (C) 2015 Codemist Ltd

//=======================================================================//
//                                                                       //
//  WARNING. In "-DCREATE=1" mode this program takes about 40 minutes    //
//  of CPU time on a computer that in 2015 counts as fairly fast. So     //
//  when you run it be prepared to be reasonably patient. The slow run   //
//  really only needed to be done once to extract font information from  //
//  a collection of ".afm" files and form it into a compact table, so it //
//  should only need to be run if the fonts being used change.           //
//                                                                       //
//=======================================================================//


// $Id: charmetrics.c 2928 2015-01-21 23:36:54Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


#ifdef CREATE
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// This takes a bunch of font information files and creates some C
// tables that can be used to access the information rapidly.

// Well if I compile this with -DCREATE=1 it makes a program that
// inspects the raw font metric and kerning files and creates a file
// called charmetrics.h containing a packed version of it. Otherwise it
// makes the code that inspects those tables and retrieves information.
// The "raw" input files are in ".afm" (Adobe Font Metric) format and
// the ones I use here were created from some .otf and .ttf font files
// using fontforge. The fonts I start from have generous licenses that
// permit re-distribution and so even more so I will hold that the
// file generated here that contains metrics is not subject to any
// severe limits on its use.

// You can also pass -DSTART=nnn and -DBEST=m. That will start checking
// for a hash table of size nnn and investigate upwards from there until
// it finds the m-th one that it can pack all the data in.
//
// I ran this code with a small value of START so it ran for a VERY long time
// and the setting that using -DCOMPACT=1 gives as a default is the one
// that uses the smallest tables I know of. Obviously no table can be
// smaller than the number of hash cells that will be used (10042) so
// starting my scan from there will find the most compact arrangement
// that the very cheap and simple hash functions used here offer - and the
// search with START=10042 runs for around a day of CPU time. The default
// setting here slightly larger tables but ends up with lower costs. The
// choice between these (and many other options) is a micro-optimisation
// that hardly matters except as a matter of neurosis and pride.

#ifdef COMPACT

#ifndef BEST
#define BEST 1
#endif

#ifndef START
#define START 10289
#endif

#else

#ifndef BEST
#define BEST 4
#endif

#ifndef START
#define START 10361
#endif

#endif

// The default setting creates a table of size 10361 which is 96.9% full.
// All Basic Latin codepoints are looked up in just one probe. On average
// Western and Mathematical characters are found in 1.591 probes, while
// overall including all the CJK characters the average for a successful
// lookup is 1.724 probes. The worst case lookup and all unsuccessful
// cases are 3 probes.
// Note that for a common or gerden hash table the average cost of a
// successful lookup would be ln(1/(1-alpha)/alpha if hashing was perfectly
// uniform: that would give the same performance for Western characters at
// a loading of 63.7% and overall at around 70% so what I have done here
// mainly saves space by allowing a hash table loading of almost 97% rather
// then 70% - this saving is around 150 Kbytes (in the C code version of the
// tables). 
//
// The COMPACT case make the table just slightly smaller at 10289, which
// means that the occupancy is 97.6%. To put things in numbers that saves
// 2880 bytes when the full table size is a little over 400 Kbytes in size.
// Again all Basic Latin characters (ie those with code U+0000 to U+007f) that
// are present in the fonts are found on the first probe. This time Western
// and Maths characters average out at 1.764 and the full character set at
// 1.852. Worst case remains at 3 probes.


// I also generate a charmetrics.red that can give access to the same
// information from within Reduce... I am considering use from Java as well
// but somewhat amazingly Java deals with statically initialised arrays
// in a way that puts limits on their size such as to BREAK this - and
// so with a naive conversion I get both a "code too large" and a
// "too many constants" error from the Java compiler. The first of these
// persists even if I split the main hash table to give just one
// column at a time - so an initialised array of 10000 simple long values
// more than Java is willing to support. Thus any Java code will need to
// load metric information from a resource, and I think that C code that
// uses the charmetrics.h file as created here can be used to create the
// data that will be loaded. Ugh.

// I have inspected the fonts that concern me and the sizes
// shown here will suffice. There are less than 32000 characters in
// total defined in all of the fonts I have (fireflysung is by far
// the biggest with over 17K characters defined). There are also less
// then 5000 kerning pairs listed. I will in fact have 31 distinct fonts.

// The code to create the font data tables is very careless and would
// be thoroughly succeptible to all sorts of bad effects from buffer overflow
// if it were ever to be fed font files other than the ones distributed with
// it. Here I follow a path of fixed and unchecked size limits in a search
// for code simplicity in a utility I only intend for use in a single
// context. But anybody minded to add extra fonts MUST be aware and should
// check all the limits before running anything.

// My code here is also not especially tidy, and it uses C-99 style "//"
// comments (as here!) and <stding.h> with uint64_t, UINT64_C() and their
// friends. In fact gcc has supported both of these for some time now and
// since this is a run-once sort of program I feel I can rely on using
// either a tolerably recent gcc or some other C compiler that supports
// C-99.

// "wx -L" tells me that all my font-metric files have lines that are
// less than 750 characters long. The worst case is for the cmuntt font
// where thare are a large number of ligatures specified for "space"
// followed by various characters (that I believe are probably all the
// combining characters present, so that putting a space ahead of any of then
// can lead to a comversion to a non-combining variant.

// Having statically fixed limits here simplifies my coding.

#define MAXFONTS 32
#define MAXCHARS 32000
#define MAXKERNS 5000
#define MAXLIGATURES 100
#define MAXLINE  750

#else // CREATE
#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#else // TEST
#include "headers.h"
#endif // TEST

#include "charmetrics.h"  // A file I must have created earlier
#endif // CREATE

#define IS_LIGATURE 0x00200000
#define IS_BLOCKEND 0x00400000

// The list of font codes here must be kept in step with the list
// of names in the table.

#define F_cmuntt                      0

#define F_General                     1
#define F_General_Bold                2
#define F_General_Italic              3
#define F_General_BoldItalic          4

#define F_IntegralsD                  5
#define F_IntegralsD_Bold             6

#define F_IntegralsSm                 7
#define F_IntegralsSm_Bold            8

#define F_IntegralsUp                 9
#define F_IntegralsUp_Bold            10

#define F_IntegralsUpD                11
#define F_IntegralsUpD_Bold           12

#define F_IntegralsUpSm               13
#define F_IntegralsUpSm_Bold          14

#define F_NonUnicode                  15
#define F_NonUnicode_Bold             16
#define F_NonUnicode_Italic           17
#define F_NonUnicode_BoldItalic       18

#define F_SizeOneSym                  19
#define F_SizeOneSym_Bold             20
#define F_SizeTwoSym                  21
#define F_SizeTwoSym_Bold             22
#define F_SizeThreeSym                23
#define F_SizeThreeSym_Bold           24
#define F_SizeFourSym                 25
#define F_SizeFourSym_Bold            26
#define F_SizeFiveSym                 27

#define F_Variants                    28
#define F_Variants_Bold               29

#define F_fireflysung                 30
#define F_end                         31

// In the ".afm" files and hence the main metrics I work with each
// character is measured and positioned relative to a base-line. However
// when wxWidgets draws things it uses the top left corner of a bounding
// box for text as its reference point. However the "bounding box" used
// does not seem to be related to any information I can find in the .afm
// file so I file values by running a wxWidgets program and seeing what
// it reports and put in a table of values here...

// To re-calculate these values you could check out revision 2916 of
// Reduce, configure "--with-csl --with-wx", make wxshowmath and run
// wxshowmath or wxdata/fontsizes.dat. The trace output should include
//....        Need to process CMU Typewriter Text
//....        Gives CMU Typewriter Text with flags 0
//....        font[0] = "CMU Typewriter Text" size 10000
//....        ( CMU Typewriter Text/10000: 12597.7 2330 [10267.7]
//....            1027,           // cmuntt
//....        from table baseline offset = 10270
//....        convert General
//....        Need to process STIXGeneral
//....        Gives STIXGeneral with flags 10000
//....        font[1] = "STIXGeneral" size 10000
//....        ( STIXGeneral/10000: 15097.7 4550 [10547.7]
//....            1055,           // General
// and I extracted the information I need here using
//    grep "    // " wxshowmath.log > DESTINATION
// I edited the file to remove a comma after the final entry...
// (revisions much before then may not display the relevant
// information - ones significantly after may have removed the trace
// output...).


// I note with some distress that the adjustments needed here differ
// across operating systems. That backs up the fact that this data can not
// be deduced from a set of Adobe Font Metrics. So although in many cases
// the numbers match up, for General-BoldItalic the win32 case is out of
// line with the other two platforms. For all the Integrals fonts the
// Macintosh offset is odd man out. Fireflysung makes Linux the exceptional
// case. 
// So I provide three versions of this table (it is not very large) and
// a tolerably cheap run-time test can pick which one to use. I feel it is
// nicer for my runtime code to check no more than 3 cases to choose between
// these tables rather than getting it to measure all 31 fonts.

const uint16_t *chardepth = NULL;

const uint16_t chardepth_WIN32[] =
{
    1027,           // cmuntt
    1055,           // General
    1055,           // General-Bold
    1055,           // General-Italic
    1055,           // General-BoldItalic
    2182,           // IntegralsD
    2182,           // IntegralsD-Bold
    1055,           // IntegralsSm
    1055,           // IntegralsSm-Bold
    1055,           // IntegralsUp
    1055,           // IntegralsUp-Bold
    2182,           // IntegralsUpD
    2182,           // IntegralsUpD-Bold
    1055,           // IntegralsUpSm
    1055,           // IntegralsUpSm-Bold
    1450,           // NonUnicode
    1450,           // NonUnicode-Bold
    1450,           // NonUnicode-Italic
    1450,           // NonUnicode-BoldItalic
    1588,           // SizeOneSym
    1588,           // SizeOneSym-Bold
    2095,           // SizeTwoSym
    2095,           // SizeTwoSym-Bold
    2604,           // SizeThreeSym
    2604,           // SizeThreeSym-Bold
    2604,           // SizeFourSym
    2604,           // SizeFourSym-Bold
    960,            // SizeFiveSym
    1055,           // Variants
    1055,           // Variants-Bold
    885             // fireflysung
};

const uint16_t chardepth_X11[] =
{
    1027,           // cmuntt
    1055,           // General
    1055,           // General-Bold
    1055,           // General-Italic
    1042,           // General-BoldItalic
    2182,           // IntegralsD
    2182,           // IntegralsD-Bold
    1055,           // IntegralsSm
    1055,           // IntegralsSm-Bold
    1055,           // IntegralsUp
    1055,           // IntegralsUp-Bold
    2182,           // IntegralsUpD
    2182,           // IntegralsUpD-Bold
    1055,           // IntegralsUpSm
    1055,           // IntegralsUpSm-Bold
    1450,           // NonUnicode
    1450,           // NonUnicode-Bold
    1450,           // NonUnicode-Italic
    1450,           // NonUnicode-BoldItalic
    1588,           // SizeOneSym
    1588,           // SizeOneSym-Bold
    2095,           // SizeTwoSym
    2095,           // SizeTwoSym-Bold
    2604,           // SizeThreeSym
    2604,           // SizeThreeSym-Bold
    2604,           // SizeFourSym
    2604,           // SizeFourSym-Bold
    960,            // SizeFiveSym
    1055,           // Variants
    1055,           // Variants-Bold
    928             // fireflysung
};

const uint16_t chardepth_OSX[] =
{
    1027,           // cmuntt
    1055,           // General
    1055,           // General-Bold
    1055,           // General-Italic
    1042,           // General-BoldItalic
    967,            // IntegralsD
    967,            // IntegralsD-Bold
    967,            // IntegralsSm
    967,            // IntegralsSm-Bold
    967,            // IntegralsUp
    967,            // IntegralsUp-Bold
    967,            // IntegralsUpD
    967,            // IntegralsUpD-Bold
    967,            // IntegralsUpSm
    967,            // IntegralsUpSm-Bold
    967,            // NonUnicode
    967,            // NonUnicode-Bold
    967,            // NonUnicode-Italic
    967,            // NonUnicode-BoldItalic
    1588,           // SizeOneSym
    1588,           // SizeOneSym-Bold
    2095,           // SizeTwoSym
    2095,           // SizeTwoSym-Bold
    2604,           // SizeThreeSym
    2604,           // SizeThreeSym-Bold
    2604,           // SizeFourSym
    2604,           // SizeFourSym-Bold
    967,            // SizeFiveSym
    967,            // Variants
    967,            // Variants-Bold
    885             // fireflysung
};

const char *fontnames[31] =
{
    "cmuntt",

    "STIXGeneral-Regular",
    "STIXGeneral-Bold",
    "STIXGeneral-Italic",
    "STIXGeneral-BoldItalic",

    "STIXIntegralsD-Regular",
    "STIXIntegralsD-Bold",

    "STIXIntegralsSm-Regular",
    "STIXIntegralsSm-Bold",

    "STIXIntegralsUp-Regular",
    "STIXIntegralsUp-Bold",

    "STIXIntegralsUpD-Regular",
    "STIXIntegralsUpD-Bold",

    "STIXIntegralsUpSm-Regular",
    "STIXIntegralsUpSm-Bold",

    "STIXNonUnicode-Regular",
    "STIXNonUnicode-Bold",
    "STIXNonUnicode-Italic",
    "STIXNonUnicode-BoldItalic",

    "STIXSizeOneSym-Regular",
    "STIXSizeOneSym-Bold",
    "STIXSizeTwoSym-Regular",
    "STIXSizeTwoSym-Bold",
    "STIXSizeThreeSym-Regular",
    "STIXSizeThreeSym-Bold",
    "STIXSizeFourSym-Regular",
    "STIXSizeFourSym-Bold",
    "STIXSizeFiveSym-Regular",

    "STIXVariants-Regular",
    "STIXVariants-Bold",

    "fireflysung"
};

// The font metric information I use will be quite bulky, so I will be
// trying to balance speed, compactness and simplicity here.
// I will only need to support the 31 fonts listed above, so I will
// exploit some observed features. The first is that I only need to
// map U+000000 to U+01ffff and hence I can use just 17 bits to specify
// a code-point. Since I have (just) under than 32 fonts I can use 5 bits
// to indicate a font.
// However I only use a modest range of codes over 0xffff so I will map them
// onto otherwise unused codes (in these fonts) for the purposes of my
// tables. Because I am always carrying my font identifier it is only
// necessary to arrange to be clash-free within a single font. Whew.
// A conseqence will be that I can use just 16-bit "adjusted
// codepoints" and that plus 5 bits of font leaves me needing 21 bits.

static int pack_character(int font, int codepoint)
{
// The cases that apply here are
//    cmuntt    U+10144 - U+10147    map to U+d144 - U+d147
//              these would be Hangul syllables but same are not present
//              in cmuntt. The above are the only characters present in
//              cmuntt that have codes over U+ffff.
//    STIXGeneral-Regular and -Bold   U+1d400 - U+1d7ff to U+d400 - U+d7ff 
//              The first character present above U+ffff is U+1d400 and the
//              last is U+1d7f5. The region U+d400 to U+dfff  is not
//              populated.
//   All the other fints here seem to stick to the basic multilingual plane.
// If at any stage I added more fonts I would need to review this!
    if (codepoint >= 0x10000)
        codepoint = 0xd000 + (codepoint & 0xfff);
// I need the bottom two bits of this packed code to be the bottom
// two bits of the codepoint because my hash table will be using
// buckets of four adjacent codepoints.
    return (font << 16) | codepoint;
}

// I will store information in a hash table that puts four codepoints per
// "hash table line". Each hash table entry will involve five 64-bit words.
// The first will contain the key and some information to help with kerning
// and ligatures. Because I will have a line size of 4 I only need to use 19
// bits of key. That leaves me with space to put four 11-bit kern entries
// in, one for each of the 4 codepoints covered. There will be a 31-entry
// table indexed by font that gives a value to be added to one of these
// offsets. That allows for up to 2048 kern entries per font. I count 1016
// kern declarations and 16 ligature declarations for STIXGeneral-Regular
// and those together add up to 1032 which fits reasonably.
//
// I assessed having individual entries is the hash table and line sizes
// of 2 and 8 as well as 4. A line size of 8 saves a small emount of space
// but at the cost of seeming noticably messier. A line size of only 2
// consumes distinctly more memory.
//
// The other four 64-bit values each hold four 13-bit fields and one 12
// bit one. These store the character width and its bounding box. For my
// fonts I observe
//     0   <=   width   <=  3238        use 13 bits unsigned
//   -3000 <=   llx     <=  930         use 13 bits unsigned offset by -3000
//    -522 <=   lly     <=  820         use *12* bits unsigned offset by -1000
//    -234 <=   urx     <=  3472        use 13 bits unsigned offset by -500
//    -166 <=   ury     <=  2604        use 13 bits unsigned offset by -1000
// that packing is a bit ugly but ends up using exactly 64 bits which is
// really convenient.

// When a character starts a kern I have a 11 bit index value that gets added
// to a further value that depends on the font to give an offset into a table
// of 32-bit words. Each word contains
//    last item mark      1 bit set if this is the last item of
//                        kern information associated with the current
//                        lead character.
//    kern-or-ligature    1 bit flag set if this is ligature not kern data.
//    successor char      21-bit codepoint for a successor character. Note
//                        that this will always be in the same font. The
//                        codepoint is stored plain here with no compression
//                        or adjustment.
//    offset              for kerning this is a 9-bit signed adjustment
//                        to make the spacing. For a ligature it is a
//                        9 bit offset into a table of 21-bit codepoints
//                        for replacement characters. I only seem to see
//                        77 cases of ligatures in all so this final
//                        table is not too bulky.
// The kern index values atart at 1 so that a kern index of zero can
// indicate no kerning is needed. The range of kern adjustment I see in my
// fonts is -149 to 87, and so the 9-bit field I have (coping with -256 to
// +255) will suffice comfortably.
//

#ifdef CREATE

// In the official full list of Unicode names there are some remarkably
// long names used, of which maybe the worst is
//    "CLOCKWISE RIGHTWARDS AND LEFTWARDS OPEN CIRCLE ARROWS WITH
//     CIRCLED ONE OVERLAY"
// however the fonts I use here all have embedded names that are reasonably
// short. I would detect it if any were longer than 31 characters and stop.
// If that happened I would merely increase MAXUNILEN here. The names present
// while processing fonts here are purely local to the treatment here (they
// are used to link kerning tables).

#define MAXUNILEN 32

static int       charcount = 0;
static int       fontkey[MAXCHARS];
static int32_t   codepoint[MAXCHARS];
static int32_t   width[MAXCHARS];
static int32_t   llx[MAXCHARS];
static int32_t   lly[MAXCHARS];
static int32_t   urx[MAXCHARS];
static int32_t   ury[MAXCHARS];
static char      uninames[MAXCHARS][MAXUNILEN];
static int       kernreference[MAXCHARS];

// For ligature information I will store the identity of the
// start character and then the names of the follower and the
// replacement.

static int       nligatures = 0;
static int       ligfont[MAXLIGATURES];
static int32_t   ligstart[MAXLIGATURES];
static char      ligfollow[MAXLIGATURES][MAXUNILEN];
static char      ligreplacement[MAXLIGATURES][MAXUNILEN];
static int32_t   ligfollowcode[MAXLIGATURES];
static int32_t   ligreplacementcode[MAXLIGATURES];

// For kerning information I will store the identity of the
// start and follow characters and the integer adjustment to be made.

static int       nkerns = 0;
static int       kernfont[MAXKERNS];
static char      kernstart[MAXKERNS][MAXUNILEN];
static char      kernfollow[MAXKERNS][MAXUNILEN];
static int       kernadjustment[MAXKERNS];
static int32_t   kernstartcode[MAXKERNS];
static int32_t   kernfollowcode[MAXKERNS];

static int kernp = 0;
static int16_t  fontkern[F_end];
static uint32_t kerntable[MAXKERNS];
static char     ktstart[MAXKERNS][MAXUNILEN];
static char     ktfollow[MAXKERNS][MAXUNILEN];
static int      ktadjustment[MAXKERNS];
static char     ktfont[MAXKERNS][32];
static int      ktfontn[MAXKERNS];

static int ligp = 0;
static uint32_t ligtable[MAXLIGATURES];
static char ltfirst[MAXLIGATURES][MAXUNILEN],
            ltfollow[MAXLIGATURES][MAXUNILEN],
            ltname[MAXLIGATURES][MAXUNILEN],
            ltfont[MAXLIGATURES][32];

// It will be necessary at times to look up a name given its name

int32_t decodename(int fontnum, const char *name)
{
    int i;
    for (i=0; i<charcount; i++)
        if (fontnum == fontkey[i] &&
            strcmp(name, uninames[i]) == 0)
        return codepoint[i];
    printf("Character called %s not found in font %d\n", name, fontnum);
    exit(EXIT_FAILURE);
}

// The hash table will end up holding information about around 32000
// characters. It is arranged in lines each of which store data on
// four characters, so assuming few isolated character codes that
// means it will use around 8000 entries. I make its size a prime.
// If I make it 10091 then my tables are fairly full - around 99.5%.
// The hashing scheme I use will guarantee that not many probes are
// needed even at this high loading level!!!

#define MAXHASHTABLESIZE 10505
int HASHTABLESIZE = START;

// This is around 400 Kbytes... I tend to count that as quite large.
// By far the largest contribution to it is data from fireflysung.afm.
// Although almost all characters there are specified with a width of 1000
// the character bounding boxes are all individual and varied, and so trying
// to save space by having an index of bounding boxes does not appear to be
// useful.

static uint64_t hashtable[MAXHASHTABLESIZE][5];

// In my hashing schere I sometimes relocate items. An entry in
// pinned that is non-zero will inhibit this. This marking is only
// relevant while creating the table.
//
int pinned[MAXHASHTABLESIZE];


//==================================================================

static int probes = 0, occupancy = 0;

// I do some breadth-first (well iterative deepening) search when trying
// to insert characters in the table. This parameter limits the depth of
// the search.
#define MAXDEPTH 13

// calcplaces selects the three locations that a key might hash to.
// It is desirable to balance how well it spreads things out against
// how costly it might be to compute, and you can see here that it
// is seriously simple here. Because my hashing will be limited to
// just three probes all issues of having a probe sequence that eventually
// visits everywhere do not apply. I can even survive if the stride is
// sometimes zero since in those cases all that happens is that the
// key concerned will have to end up in its home position!

int secondhash = 2;

#define SECONDHASHMODULUS (HASHTABLESIZE-secondhash)

static void calcplaces(uint32_t key, uint32_t *p)
{
    int base = key % HASHTABLESIZE;
    int stride = key % (HASHTABLESIZE-secondhash);
    p[0] = base;
    p[1] = (base + stride) % HASHTABLESIZE;
    p[2] = (2*base + stride) % HASHTABLESIZE;
}

// hashinsert will return -1 on failure, otherwise the index into the
// hash table where the item was inserted.
// I think I view it as a little amazing that the code here is as compact
// as it is!

int hashinsert(uint32_t key, int depth)
{
    uint32_t p[5], r;
    uint32_t d[5];
    int i, depth1;
    calcplaces(key, p);
// If the key is already in the table just return
    for (i=0; i<3; i++)
        if ((hashtable[p[i]][0] & 0x7ffff) == key) return p[i];
// If one of the preferred gaps is free then use it. To start with I will use
// insertions in order of preference.
    for (i=0; i<3; i++)
    {   if (hashtable[p[i]][0] == 0)
        {   hashtable[p[i]][0] = key;
// There is a delicacy here. When I FIRST insert an entry I can afford to
// write the whole of the word in the hashtable not just the field within
// that that could hold a key...
            return p[i];
        }
    }
// Now I need to move something that has previously been inserted in order
// to make space for the new item. If the depth parameter says I have run
// our of energy to search then just report failure.
    if (depth <= 0) return -1;
// ... otherwise try in turn seeing if it is possible to clear each of
// the places this item would like to go. I do this in a spirit of
// iterative deepening so I prefer adjustments that only move a small
// number of items. Ie this is a breadth-first search.
//
// An alternative sceheme would be a random walk...
    for (depth1=0; depth1<depth; depth1++)
    {   for (i=0; i<3; i++)
        {   int w;
            if (pinned[p[i]]) continue;  // do not move pinned thing
            w = hashtable[p[i]][0];      // displaced key
            hashtable[p[i]][0] = key;    // put this in where it would like to go
            if (hashinsert(w, depth1)>=0) return p[i];
            hashtable[p[i]][0] = w;      // re-insert failed so restore things
        }
    }
// If none of the re-works help then I give up.
    return -1;
}

// Display information on how many of each categroy of character will end
// up needing 1, 2 or 3 probes.

int report(char *flag)
{
    int i, k, pins = 0, r = 0;
    for (i=0; i<HASHTABLESIZE; i++)
        if (pinned[i]) pins++;
    for (k=0; k<3; k++)
    {   uint32_t p[5];
        uint32_t n1=0, n2=0, n3=0;
        for (i=0; i<charcount; i++)
        {   int font = fontkey[i];
            int cp = codepoint[i];
            int fullkey = pack_character(font, cp); // 21-bit key
            int key = fullkey >> 2; // because my hash table has line-size 4
            int w;
            if (cp == 0) continue;
            switch (k)
            {
        case 0: if (cp >= 0x80) continue;
                break;
        case 1: if (font == F_fireflysung) continue;
                break;
        default:break;
            }
            calcplaces(key, p);
            if (key == hashtable[p[0]][0]) n1++;
            else if (key == hashtable[p[1]][0]) n2++;
            else if (key == hashtable[p[2]][0]) n3++;
            else printf("Error data not found\n");
        }
        switch (k)
        {
    case 0: printf("%sU+0000-U+007f ", flag);
            r = n2 + n3;
            break;
    case 1: printf("%sWestern fonts ", flag);
            break;
    default:printf("%sEverything    ", flag);
            break;
        }
        printf("%5d %5d %5d: %6.3f", n1, n2, n3,
           (double)(1*n1+2*n2+3*n3)/
           (double)(n1+n2+n3));
        if (k == 2) printf(" pins=%d", pins);
        printf("\n");
    }
    return r;
}




static char      line[MAXLINE];
static char      saveline[MAXLINE];
static char      segment[MAXLINE];

int maxw=-10000, maxllx=-10000, maxlly=-10000, maxurx=-10000, maxury=-10000;
int minw=10000, minllx=10000, minlly=10000, minurx=10000, minury=10000;

int main(int argc, char *argv[])
{
    const char *f;
    int pass, fontnum, best;
    char *p, *q;
    int relevant = 0;
    int kerndata = 0;
    FILE *src;
    time_t ttt;
    char filename[100];
    int i, probes  = 0, p1 = 0, p2 = 0, n1 = 0, n2 = 0,
        occupancy = 0, fail, qq;
    setvbuf(stdout, NULL, _IONBF, 1);
//==========================================================================
// (1) Read in all the metrics
//==========================================================================
    nkerns = charcount = 0;
// I will map characters from u+000000 to u+01ffff but not beyond - that
// way I will only need 17 bits to specify a codepoint.
    for (fontnum=0; fontnum<F_end; fontnum++)
    {   f = fontnames[fontnum];
        printf("Process font %s\n", f);
        relevant = kerndata = 0;
        sprintf(filename, "wxfonts/metrics/%s.afm", f);
        if ((src = fopen(filename, "r")) == NULL)
        {   printf("Unable to access %s\n", filename);
            exit(EXIT_FAILURE);
        }
        for (;;)
        {   int ia, ib, ic, id;
            int32_t cp, wid, bb1, bb2, bb3, bb4;
            char unn[MAXLINE], lig1[MAXLINE], lig2[MAXLINE];
            cp = -1;
            wid = bb1 = bb2 = bb3 = bb4 = 0;
            unn[0] = lig1[0] = lig2[0] = 0;
            ia = ib = ic = id = 0;
            if (fgets(line, sizeof(line)-1, src) == NULL) break;
            if (strncmp(line, "EndFontMetrics", 14) == 0) break;
            ia = (int)strlen(line);
            while (ia >= 0 &&
                   (line[ia] == 0 || line[ia] == '\n' || line[ia] == '\r'))
                ia--;
            line[ia+1] = 0; // discard final newline
            if (ia == 0) break;
            strcpy(saveline, line);
            if (strncmp(line, "StartCharMetrics", 16) == 0)
            {   relevant = 1;
                continue;
            }
            if (strncmp(line, "EndCharMetrics", 14) == 0)
            {   relevant = 0;
                continue;
            }
            if (strncmp(line, "StartKernPairs", 14) == 0)
            {   kerndata = 1;
                continue;
            }
            if (strncmp(line, "EndKernPairs", 12) == 0)
            {   kerndata = 0;
                continue;
            }
            if (kerndata)
            {   if (sscanf(line, "KPX %s %s %d", lig1, lig2, &ia) == 3)
                {   kernfont[nkerns] = fontnum;
                    strcpy(kernstart[nkerns], lig1);
                    strcpy(kernfollow[nkerns], lig2);
                    kernadjustment[nkerns] = ia;
#if 0
                    printf("[%d] %s + %s => %d\n", nkerns, lig1, lig2, ia);
#endif
                    nkerns++;
                }
                else
                {   printf("Dubious kerning data %s\n", line);
                    continue;
                }
                continue;
            }
            if (relevant == 0) continue;
// Now line contains character information. This may include
//     C nnn            decimal code point
//     WX xxx           hexacedimal width
//     N word           unicode character name, needed for kern tables
//     B nn nn nn nn    character bounding box
//     L word word      ligature specification
// with each of these separated by a semicolon.
            p = line;
            while (p != NULL)
            {   q = strchr(p, ';');
                if (q != NULL) *q = 0;
// Process segment starting at p
                while (*p == ' ' || *p == '\n' || *p == '\r') p++;
                if (*p == 0) break; // empty segment
                switch (*p)
                {
                case 'C':
                    if (sscanf(p, "C %d", &ia) != 1)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    cp = ia;
                    break;
                case 'W':
                    if (sscanf(p, "WX %d", &ia) != 1)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    wid = ia;
                    if (wid > maxw) maxw = wid;
                    if (wid < minw) minw = wid;
                    break;
                case 'N':
                    if (sscanf(p, "N %s", unn) != 1)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    if (strlen(unn) >= MAXUNILEN)
                    {   printf("Unicode name length = %d\n", (int)strlen(unn));
                        exit(EXIT_FAILURE);
                    }
                    if (cp == -1)
                    {   if (sscanf(unn, "u%x", &ia) == 1) cp = ia;
                        else if (sscanf(unn, "uni%x", &ia) == 1) cp = ia;
                        else if (strcmp(unn, ".notdef") != 0)
                            printf("Dodgy character: %s\n", saveline);
                    }
                    break;
                case 'B':
                    if (sscanf(p, "B %d %d %d %d", &ia, &ib, &ic, &id) != 4)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    bb1 = ia; bb2 = ib; bb3 = ic; bb4 = id;
                    if (bb1 > maxllx) maxllx = bb1;
                    if (bb1 < minllx) minllx = bb1;
                    if (bb2 > maxlly) maxlly = bb2;
                    if (bb2 < minlly) minlly = bb2;
                    if (bb3 > maxurx) maxurx = bb3;
                    if (bb3 < minurx) minurx = bb3;
                    if (bb4 > maxury) maxury = bb4;
                    if (bb4 < minury) minury = bb4;
                    break;
                case 'L':
// All I can do with ligature information on a first pass is to record
// it rather literally. That is because it may contain forward references
// to character names.
                    if (sscanf(p, "L %s %s", lig1, lig2) != 2)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
// I observe some redundant ligature statements in the font metrics I use,
// so that the same information appears twice in a row. I filter that
// case out here.
                    if (nligatures == 0 ||
                        fontnum != ligfont[nligatures-1] ||
                        cp != ligstart[nligatures-1] ||
                        strcmp(lig1, ligfollow[nligatures-1]) != 0)
                    {   ligfont[nligatures] = fontnum;
                        ligstart[nligatures] = cp;
                        strcpy(ligfollow[nligatures], lig1);
                        strcpy(ligreplacement[nligatures], lig2);
                        nligatures++;
                    }
                    break;
                case 0:
                    break;
                default:
                    printf("Unknown segment \"%s\" in .afm file\n", p);
                    printf("Input line: \"%s\"\n", saveline);
                    exit(EXIT_FAILURE);
                }
                if (q == NULL) break;
                else p = q+1;
            }
// The information I now have is
// fontnum, cp                          key
// wid, bb1, bb2, bb3, bb4, unn         data
            if (cp < 0 || cp > 0x01ffff)
            {   if (strcmp(unn, ".notdef") != 0)
                    printf("Discarding character <%s> with codepoint %d\n",
                           unn, cp);
                continue;
            }
            if (cp >= 0xd000 && cp < 0xe000)
                printf("Codepoint %d %x noted\n", cp, cp);
            if (cp > 0xffff &&
                !(cp >= 0x1d000 && cp < 0x1e000))
                printf("Codepoint %d %x noted\n", cp, cp);
            fontkey[charcount] = fontnum;
            codepoint[charcount] = cp;
            width[charcount] = wid;
            strcpy(uninames[charcount], unn);
            llx[charcount] = bb1;
            lly[charcount] = bb2;
            urx[charcount] = bb3;
            ury[charcount] = bb4;
{ int height = bb4 - bb2;
  if (height == 1000) printf("Font %d code %d\n", fontnum, cp);
} // @@@
            charcount++;
        }
        fclose(src);
    }
    printf("About to resolve kern and ligature names\n");
    printf("nkerns = %d nligatures = %d\n", nkerns, nligatures);
    for (i=0; i<nkerns; i++)
        kernstartcode[i] = decodename(kernfont[i], kernstart[i]);
    for (i=0; i<nkerns; i++)
        kernfollowcode[i] = decodename(kernfont[i], kernfollow[i]);
    for (i=0; i<nligatures; i++)
        ligfollowcode[i] = decodename(ligfont[i], ligfollow[i]);
    for (i=0; i<nligatures; i++)
        ligreplacementcode[i] = decodename(ligfont[i], ligreplacement[i]);
// Now I have read everything.
//
// Before I fill in the main hash table I need to collect kern and ligature
// information.
    kernp = ligp = 0;
    for (fontnum=0; fontnum<F_end; fontnum++)
    {   fontkern[fontnum] = kernp-1;
        for (i=0; i<charcount; i++)
        {   int j, v = 0, kkk = 0;
// I wish to process all chars from each font in order. In fact they will
// be in my table that way, but I still code things to scan once for each font.
            if (fontkey[i] != fontnum) continue;
// Now I will transfer any ligature and kern info about this character
// into kerntable & ligtable.
            for (j=0; j<nkerns; j++)
            {   if (kernfont[j] == fontnum &&
                    kernstartcode[j] == codepoint[i])
                {   strcpy(ktstart[kernp], kernstart[j]);
                    strcpy(ktfollow[kernp], kernfollow[j]);
                    ktadjustment[kernp] = kernadjustment[j];
                    strcpy(ktfont[kernp], fontnames[fontnum]);
                    ktfontn[kernp] = fontnum;
// kkk will be the index in the kernel tables of the FIRST item
// relating to this start character. It has 0x80000000 forced in so
// that it is a nonzero value even if the kernel table index is zero.
                    if (kkk == 0) kkk = kernp | 0x80000000;
                    kerntable[kernp++] =
                        (kernadjustment[j]<<23) | kernfollowcode[j];
                    v = 1;
                }
            }
            for (j=0; j<nligatures; j++)
            {   if (ligfont[j] == fontnum &&
                    ligstart[j] == codepoint[i])
                {   strcpy(ktstart[kernp], uninames[i]);
                    strcpy(ktfollow[kernp], ligfollow[j]);
                    ktadjustment[kernp] = 9999;
                    strcpy(ktfont[kernp], fontnames[fontnum]);
                    ktfontn[kernp] = fontnum;
                    if (kkk == 0) kkk = kernp | 0x80000000;
                    kerntable[kernp++] =
                        (ligp<<23) | IS_LIGATURE | ligfollowcode[j];
                    strcpy(ltfirst[ligp], uninames[i]);
                    strcpy(ltfollow[ligp], ligfollow[j]);
                    strcpy(ltname[ligp], ligreplacement[j]);
                    strcpy(ltfont[ligp], fontnames[fontnum]);
                    ligtable[ligp++] = ligreplacementcode[j];
                    v = 1;
                }
            }
// v was set if I found at least one kern or ligature entry starting
// with this character. Noticing that here means I can look back and
// be certain that the previous block just ended.
            if (v && kernp!=0) kerntable[kernp-1] |= IS_BLOCKEND;
#if 1
            if (kkk != 0)
                printf("Setting kernreference %d (cp=%d/%c) to %d\n",
                       i, codepoint[i],
                       ((33 <= codepoint[i] && codepoint[i] < 0x7f) ?
                        codepoint[i] : '?'),
                       kkk & 0x7fffffff);
#endif
            kernreference[i] = kkk;
        }
    }
// Make really certain that the table is terminated.
    if (kernp!=0) kerntable[kernp-1] |= IS_BLOCKEND;

    printf("charcount = %d\n", charcount);
//==========================================================================
// (2) Try inserting everything in to the hash table
//==========================================================================
    best = BEST;
    for (HASHTABLESIZE=START; HASHTABLESIZE<MAXHASHTABLESIZE; HASHTABLESIZE++)
    {   for (secondhash=1; secondhash<100; secondhash++)
        {   memset(hashtable, 0, sizeof(hashtable));
            memset(pinned, 0, sizeof(pinned));
            fail = 0;
            for (pass=0; pass<2; pass++)
            for (i=0; i<charcount; i++)
            {   int fullkey = pack_character(fontkey[i], codepoint[i]); // 21-bit key
                int key = fullkey >> 2; // because my hash table has line-size 4
                int h1;
                if (codepoint[i] == 0) continue;
                if (pass == 0 && codepoint[i] > 0x7f) continue;
                if (key != (key & 0x7ffff) ||
                    key == 0)
                {   printf("key = %x disaster\n", key);
                    exit(1);
                }
                h1 = hashinsert(key, MAXDEPTH);
                if (h1 < 0)
                {
#if 0
                    printf("hash table creation failed on %d of %d chars (%d)\n",
                           i, charcount, __LINE__);
                    printf("After %d of %d Failed to insert %d\n",
                        i, charcount, pack_character(fontkey[i], codepoint[i])/4);
#endif
                    fail = 1;
                    break;;
                }
                else if (pass == 0) pinned[h1] = 1;
            }
            if (fail)
            {
#if 0
                printf("tablesize %d failed at %.3f%%\n",
                    HASHTABLESIZE, (100.0*(double)i)/(double)charcount);
#endif
                printf("."); // So I see at least something!
                continue;
            }
            occupancy = 0;
            for (i=0; i<HASHTABLESIZE; i++)
                if (hashtable[i][0] != 0) occupancy++;
            printf("tablesize %d, 2hash=%d success with occupancy %.3f%%\n",
                    HASHTABLESIZE, secondhash,
                   (100.0*(double)occupancy)/(double)HASHTABLESIZE);
            if (report("") != 0) continue;
//=====================================================
// Here everything is in the hash table and everything
// in Basic Latin is in its home position. So I will
// try to optimise Western and Mathematical characters.
// Start by pinning them all.
//=====================================================
            ttt = time(NULL) + 20;
            for (i=0; i<HASHTABLESIZE; i++)
            {   int key = hashtable[i][0] & 0x1fffff;
                int font = key >> 14;
                int codepoint = 4*(key & 0x3fff);
                if (font == F_fireflysung || codepoint == 0) continue;
                pinned[i] = 1;
            }
            printf("About to optimise\n");
            for (qq=0; qq<20; qq++)
            {   printf("{%d}", qq);
                for (i=0; i<HASHTABLESIZE; i++)
                {   int key = hashtable[i][0] & 0x1fffff;
                    int font = key >> 14;
                    int codepoint = 4*(key & 0x3fff);
                    int w;
                    int aim = qq > 9 ? 1 : 0;
                    uint32_t p[3];
                    if (font == F_fireflysung || codepoint == 0) continue;
// Now I have a Western/Mathematical character.
                    calcplaces(key, p);
                    if (i == p[0]) continue; // Already in the right place!
#if 0
                    if (pinned[p[aim]])
                        printf("Can not move because destination is pinned\n");
#endif
                    if (pinned[p[aim]]) continue;
                    w = hashtable[p[aim]][0]; // thing that is in its way!
                    hashtable[i][0] = 0;       // gap where lifted item was
                    hashtable[p[aim]][0] = key;
                    pinned[i] = 0;
                    pinned[p[aim]] = 1;
                    if (hashinsert(w, MAXDEPTH)>=0)
                    {   printf("[%.2f%%] Moved %d/%d to better location\n",
                               100.0*((double)qq + (double)i/(double)HASHTABLESIZE)/20.0,
                               font, codepoint);
                        continue;
                    }
                    if (time(NULL) > ttt)
                    {   printf("[%.2f%%] still working\n",
                               100.0*((double)qq +
                                      (double)i/(double)HASHTABLESIZE)/20.0);
                        ttt = time(NULL) + 20;
                    }
                    hashtable[p[aim]][0] = w;      // re-insert failed so restore things
                    hashtable[i][0] = key;
                    pinned[i] = 1;
                    pinned[p[aim]] = 0;
                }
            }
            printf("Western things moved to better positions where possible\n");
// I arrange that the definitive report for this case has "@" characters at
// the start of each line.
            printf("@tablesize %d, 2hash=%d success with occupancy %.3f%%\n",
                    HASHTABLESIZE, secondhash,
                   (100.0*(double)occupancy)/(double)HASHTABLESIZE);
            printf("@empty lines in hash consume %d bytes\n",
                   40*(HASHTABLESIZE-occupancy));
            report("@");
            if (--best <= 0) break;
        }
        printf(":%d", HASHTABLESIZE); // Outer loop marker
        if (best <= 0) break;
    }

//=====================================================================
// Now the table should have everything in it and so I can merely fill
// in the actual metric information
//=====================================================================
    printf("\nNow I want to put data into the hash table.\n");
    for (i=0; i<charcount; i++)
    {   int fullkey = pack_character(fontkey[i], codepoint[i]); // 21-bit key
        int key = fullkey >> 2; // because my hash table has line-size 4
        if (codepoint[i] == 0) continue;
        int h1;
        uint64_t w;
// This call should not actually INSERT since the key should already be
// present!
        h1 = hashinsert(key, MAXDEPTH);
        if (h1 < 0)
        {   uint32_t pp[3];
            printf("hash table creation failed on %d of %d chars (%d)\n",
                   i, charcount, __LINE__);
            printf("Failed to insert %d\n,",
                pack_character(fontkey[i], codepoint[i])/4);
            calcplaces(key, pp);
            printf("%d: %d\n", pp[0], (int)(hashtable[pp[0]][0] & 0x7ffff));
            printf("%d: %d\n", pp[1], (int)(hashtable[pp[1]][0] & 0x7ffff));
            printf("%d: %d\n", pp[2], (int)(hashtable[pp[2]][0] & 0x7ffff));
            exit(1);
        }
// Pack and write in the messy information about width and bounding boxes.
        w = ((uint64_t)width[i] & 0x1fff) << 51 |
            ((uint64_t)(llx[i]+3000) & 0x1fff) << 38 |
            ((uint64_t)(lly[i]+1000) & 0x0fff) << 26 |
            ((uint64_t)(urx[i]+500) & 0x1fff) << 13 |
            ((uint64_t)(ury[i]+1000) & 0x1fff);
        hashtable[h1][1+(fullkey&3)] = w;
// Finally merge in an offset to any kern info that might be available
        if (kernreference[i] != 0)
        {   int64_t q = (kernreference[i] & 0x7fffffff)-fontkern[fontkey[i]];
#if 1
            printf("Fill in kern ref %d as %d\n",
                   kernreference[i] & 0x7fffffff, (int)q);
#endif
            hashtable[h1][0] |= q << (19+11*(fullkey&3));
        }
    }

    printf("Done after %d characters, %d ligatures, %d kerns\n",
           charcount, nligatures, nkerns);
    printf("width %d %d (%d)\n", minw, maxw, maxw-minw);
    printf("llx %d %d (%d)\n", minllx, maxllx, maxllx-minllx);
    printf("lly %d %d (%d)\n", minlly, maxlly, maxlly-minlly);
    printf("urx %d %d (%d)\n", minurx, maxurx, maxurx-minurx);
    printf("ury %d %d (%d)\n", minury, maxury, maxury-minury);

// Assess hash table performance just to be cautious!
    for (pass=0; pass<3; pass++)
    {   p1 = n1 = 0;
        printf("Start pass %d\n", pass);
        for (i=0; i<charcount; i++)
        {   int v, probes;
            int fullkey = pack_character(fontkey[i], codepoint[i]);
            int key = fullkey>>2;
            int h1, h2, h3;
            int pp[3];
            calcplaces(key, pp);
            if (codepoint[i] == 0) continue;
            if (pass == 1 && fontkey[i] == F_fireflysung) continue;
            if (pass == 0 && codepoint[i] >= 0x80) continue;
            h1 = key % HASHTABLESIZE;
            if (h1 != pp[0])
            {   printf("Disaster 1\n");
                exit(1);
            }
            v = (int)hashtable[h1][0] & 0x7ffff;
            if (v != key)
            {   h2 = h1 + (key % (SECONDHASHMODULUS));
                if (h2 >= HASHTABLESIZE) h2 = h2 - HASHTABLESIZE;
                if (h2 != pp[1])
                {   printf("Disaster 2\n");
                    printf("key=%d h1=%d h2=%d\n", key, h1, h2);
                    printf("%d %d %d\n", pp[0], pp[1], pp[2]);
                    printf("HTS=%d 2MOD=%d off=%d\n", HASHTABLESIZE, SECONDHASHMODULUS,
                           HASHTABLESIZE-SECONDHASHMODULUS);
                    exit(1);
                }
                v = (int)hashtable[h2][0] & 0x7ffff;
                if (v != key)
                {   h3 = h1 + h2;
                    if (h3 >= HASHTABLESIZE) h3 = h3 - HASHTABLESIZE;
                    if (h3 != pp[2])
                    {   printf("Disaster 3\n");
                        exit(1);
                    }
                    v = (int)hashtable[h3][0] & 0x7ffff;
                    p1 += 3;
                    if (v != key)
                    {   printf("Searching case %d for font %d char %d key %x\n",
                            i, fontkey[i], codepoint[i], key);
                        printf("Failed!!\n");
                        exit(1);
                    }
                }
                else p1 += 2;
            }
            else p1 += 1;
            n1++;
        }
        printf("probes:%d / chars:%d\n", p1, n1);
        printf("Probe count averages = %.2f (pass %d)\n",
               (double)p1/(double)n1, pass);
    }
    printf("Total space = %d\n", HASHTABLESIZE*(5*8));
    p1 = 0;
    for (i=0; i<HASHTABLESIZE; i++)
    {   if (hashtable[i][0] != 0) p1++;
    }
    printf("%d of %d entries (%d of %d bytes) used: %.4f\n",
        p1, HASHTABLESIZE, 40*p1, 40*HASHTABLESIZE, (double)p1/(double)HASHTABLESIZE);

    {   FILE *dest = fopen("charmetrics.h", "w");
        FILE *rdest = fopen("charmetrics.red", "w");
fprintf(dest, "// charmetrics.h                           Copyright (C) 2015 Codemist Ltd\n");
fprintf(dest, "\n");
fprintf(dest, "\n");
fprintf(dest, "// $Id: charmetrics.c 2928 2015-01-21 23:36:54Z arthurcnorman $\n");
fprintf(dest, "\n");
fprintf(dest, "\n");
fprintf(dest, "/**************************************************************************\n");
fprintf(dest, " * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *\n");
fprintf(dest, " *                                                                        *\n");
fprintf(dest, " * Redistribution and use in source and binary forms, with or without     *\n");
fprintf(dest, " * modification, are permitted provided that the following conditions are *\n");
fprintf(dest, " * met:                                                                   *\n");
fprintf(dest, " *                                                                        *\n");
fprintf(dest, " *     * Redistributions of source code must retain the relevant          *\n");
fprintf(dest, " *       copyright notice, this list of conditions and the following      *\n");
fprintf(dest, " *       disclaimer.                                                      *\n");
fprintf(dest, " *     * Redistributions in binary form must reproduce the above          *\n");
fprintf(dest, " *       copyright notice, this list of conditions and the following      *\n");
fprintf(dest, " *       disclaimer in the documentation and/or other materials provided  *\n");
fprintf(dest, " *       with the distribution.                                           *\n");
fprintf(dest, " *                                                                        *\n");
fprintf(dest, " * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *\n");
fprintf(dest, " * \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *\n");
fprintf(dest, " * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *\n");
fprintf(dest, " * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *\n");
fprintf(dest, " * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *\n");
fprintf(dest, " * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *\n");
fprintf(dest, " * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *\n");
fprintf(dest, " * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *\n");
fprintf(dest, " * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *\n");
fprintf(dest, " * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *\n");
fprintf(dest, " * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *\n");
fprintf(dest, " * DAMAGE.                                                                *\n");
fprintf(dest, " *************************************************************************/\n");
fprintf(dest, "\n");
fprintf(dest, "#ifdef __cplusplus\n");
fprintf(dest, "#define __STDC_CONSTANT_MACROS 1\n");
fprintf(dest, "#endif\n");
fprintf(dest, "\n#include <stdint.h>\n\n");
fprintf(dest, "// Character metric hash table created using the program charmetrics.c\n");
fprintf(dest, "// sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/cslbase/wxfonts\n");
fprintf(dest, "// contains README files with full credits to the fonts this is used with\n");
fprintf(dest, "\n\n");
fprintf(dest, "// The list of font codes here must be kept in step with the list\n");
fprintf(dest, "// of names in the table.\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_cmuntt                      0\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_General                     1\n");
fprintf(dest, "#define F_General_Bold                2\n");
fprintf(dest, "#define F_General_Italic              3\n");
fprintf(dest, "#define F_General_BoldItalic          4\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_IntegralsD                  5\n");
fprintf(dest, "#define F_IntegralsD_Bold             6\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_IntegralsSm                 7\n");
fprintf(dest, "#define F_IntegralsSm_Bold            8\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_IntegralsUp                 9\n");
fprintf(dest, "#define F_IntegralsUp_Bold            10\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_IntegralsUpD                11\n");
fprintf(dest, "#define F_IntegralsUpD_Bold           12\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_IntegralsUpSm               13\n");
fprintf(dest, "#define F_IntegralsUpSm_Bold          14\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_NonUnicode                  15\n");
fprintf(dest, "#define F_NonUnicode_Bold             16\n");
fprintf(dest, "#define F_NonUnicode_Italic           17\n");
fprintf(dest, "#define F_NonUnicode_BoldItalic       18\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_SizeOneSym                  19\n");
fprintf(dest, "#define F_SizeOneSym_Bold             20\n");
fprintf(dest, "#define F_SizeTwoSym                  21\n");
fprintf(dest, "#define F_SizeTwoSym_Bold             22\n");
fprintf(dest, "#define F_SizeThreeSym                23\n");
fprintf(dest, "#define F_SizeThreeSym_Bold           24\n");
fprintf(dest, "#define F_SizeFourSym                 25\n");
fprintf(dest, "#define F_SizeFourSym_Bold            26\n");
fprintf(dest, "#define F_SizeFiveSym                 27\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_Variants                    28\n");
fprintf(dest, "#define F_Variants_Bold               29\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_fireflysung                 30\n");
fprintf(dest, "#define F_end                         31\n");
fprintf(dest, "\n");
fprintf(dest, "#ifdef __cplusplus\n");
fprintf(dest, "extern \"C\" {\n");
fprintf(dest, "#endif // __cplusplus\n\n");
fprintf(dest, "extern int c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo;\n");
fprintf(dest, "extern int lookupchar(int fontnum, int codepoint);\n");
fprintf(dest, "extern int32_t lookupkernandligature(int codepoint);\n");
fprintf(dest, "extern int32_t lookupkernadjustment(int codepoint);\n");
fprintf(dest, "extern int32_t lookupligature(int codepoint);\n\n");
fprintf(dest, "extern const uint16_t chardepth_WIN32[31];\n");
fprintf(dest, "extern const uint16_t chardepth_X11[31];\n");
fprintf(dest, "extern const uint16_t chardepth_OSX[31];\n");
fprintf(dest, "extern const uint16_t *chardepth;\n");
fprintf(dest, "extern const char *fontnames[31];\n\n");
fprintf(dest, "#ifdef __cplusplus\n");
fprintf(dest, "}\n");
fprintf(dest, "#endif // __cplusplus\n\n");
fprintf(rdest, "%% Character metrics for the STIX (and some other) fonts...\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% Character metric hash table created using the program charmetrics.c\n");
fprintf(rdest, "%% sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/cslbase/wxfonts\n");
fprintf(rdest, "%% contains README files with full credits to the fonts this is used with\n");
fprintf(rdest, "%% Author: Arthur Norman\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% Redistribution and use in source and binary forms, with or without\n");
fprintf(rdest, "%% modification, are permitted provided that the following conditions are met:\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "%%    * Redistributions of source code must retain the relevant copyright\n");
fprintf(rdest, "%%      notice, this list of conditions and the following disclaimer.\n");
fprintf(rdest, "%%    * Redistributions in binary form must reproduce the above copyright\n");
fprintf(rdest, "%%      notice, this list of conditions and the following disclaimer in the\n");
fprintf(rdest, "%%      documentation and/or other materials provided with the distribution.\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"\n");
fprintf(rdest, "%% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,\n");
fprintf(rdest, "%% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n");
fprintf(rdest, "%% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR\n");
fprintf(rdest, "%% CONTRIBUTORS\n");
fprintf(rdest, "%% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR\n");
fprintf(rdest, "%% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF\n");
fprintf(rdest, "%% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS\n");
fprintf(rdest, "%% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN\n");
fprintf(rdest, "%% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)\n");
fprintf(rdest, "%% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE\n");
fprintf(rdest, "%% POSSIBILITY OF SUCH DAMAGE.\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% Also be aware of the (generally permissive) licenses associated with the\n");
fprintf(rdest, "%% fonts. Fill README files and license terms for the fonts themselves\n");
fprintf(rdest, "%% are in csl/cslbase/wxfonts.\n");
fprintf(rdest, "\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% $Id: charmetrics.c 2928 2015-01-21 23:36:54Z arthurcnorman $\n");
fprintf(rdest, "\n");
fprintf(rdest, "#if (or (memq 'psl lispsystem!*) (memq 'jlisp lispsystem!*))\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% CSL has special vectors that hold just 16-bit integers and 32-bit\n");
fprintf(rdest, "%% integers and use of those will decrease the amount of memory consumed\n");
fprintf(rdest, "%% here. However if PSL does not have these it does not matter much since I\n");
fprintf(rdest, "%% can just use ordinary Lisp vectors...\n");
fprintf(rdest, "%% I set initial contents as all 0 rather than all nil since these are\n");
fprintf(rdest, "%% supposed to contain (small) integer values.\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure mkvect32 n;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r;\n");
fprintf(rdest, "    r := mkvect n;\n");
fprintf(rdest, "    for i := 0:n do putv(r, i, 0);\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure putv32(v, n, x); putv(v, n, x);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure getv32(v, n); getv(v, n);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure mkvect16 n;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r;\n");
fprintf(rdest, "    r := mkvect n;\n");
fprintf(rdest, "    for i := 0:n do putv(r, i, 0);\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure putv16(v, n, x); putv(v, n, x);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure getv16(v, n); getv(v, n);\n");
fprintf(rdest, "\n");
fprintf(rdest, "#endif\n");
fprintf(rdest, "\n");
fprintf(rdest, "put('cmuntt, 'font_number,                      0)$\n");

fprintf(rdest, "put('General, 'font_number,                     1)$\n");
fprintf(rdest, "put('General_Bold, 'font_number,                2)$\n");
fprintf(rdest, "put('General_Italic, 'font_number,              3)$\n");
fprintf(rdest, "put('General_BoldItalic, 'font_number,          4)$\n");

fprintf(rdest, "put('IntegralsD, 'font_number,                  5)$\n");
fprintf(rdest, "put('IntegralsD_Bold, 'font_number,             6)$\n");

fprintf(rdest, "put('IntegralsSm, 'font_number,                 7)$\n");
fprintf(rdest, "put('IntegralsSm_Bold, 'font_number,            8)$\n");

fprintf(rdest, "put('IntegralsUp, 'font_number,                 9)$\n");
fprintf(rdest, "put('IntegralsUp_Bold, 'font_number,            10)$\n");

fprintf(rdest, "put('IntegralsUpD, 'font_number,                11)$\n");
fprintf(rdest, "put('IntegralsUpD_Bold, 'font_number,           12)$\n");

fprintf(rdest, "put('IntegralsUpSm, 'font_number,               13)$\n");
fprintf(rdest, "put('IntegralsUpSm_Bold, 'font_number,          14)$\n");

fprintf(rdest, "put('NonUnicode, 'font_number,                  15)$\n");
fprintf(rdest, "put('NonUnicode_Bold, 'font_number,             16)$\n");
fprintf(rdest, "put('NonUnicode_Italic, 'font_number,           17)$\n");
fprintf(rdest, "put('NonUnicode_BoldItalic, 'font_number,       18)$\n");

fprintf(rdest, "put('SizeOneSym, 'font_number,                  19)$\n");
fprintf(rdest, "put('SizeOneSym_Bold, 'font_number,             20)$\n");
fprintf(rdest, "put('SizeTwoSym, 'font_number,                  21)$\n");
fprintf(rdest, "put('SizeTwoSym_Bold, 'font_number,             22)$\n");
fprintf(rdest, "put('SizeThreeSym, 'font_number,                23)$\n");
fprintf(rdest, "put('SizeThreeSym_Bold, 'font_number,           24)$\n");
fprintf(rdest, "put('SizeFourSym, 'font_number,                 25)$\n");
fprintf(rdest, "put('SizeFourSym_Bold, 'font_number,            26)$\n");
fprintf(rdest, "put('SizeFiveSym, 'font_number,                 27)$\n");

fprintf(rdest, "put('Variants, 'font_number,                    28)$\n");
fprintf(rdest, "put('Variants_Bold, 'font_number,               29)$\n");

fprintf(rdest, "put('fireflysung, 'font_number,                 30)$\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure list_to_vec16 l;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r, n;\n");
fprintf(rdest, "    r := mkvect16 (n := sub1 length l);\n");
fprintf(rdest, "    for i := 0:n do <<\n");
fprintf(rdest, "       putv16(r, i, car l);\n");
fprintf(rdest, "       l := cdr l >>;\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure list_to_vec32 l;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r, n;\n");
fprintf(rdest, "    r := mkvect32 (n := sub1 length l);\n");
fprintf(rdest, "    for i := 0:n do <<\n");
fprintf(rdest, "       putv32(r, i, car l);\n");
fprintf(rdest, "       l := cdr l >>;\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% This one will take a list whose elements are thenselves 10-element lists\n");
fprintf(rdest, "%% of 32-bit integers.\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "symbolic procedure list_to_metric_table l;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r, n;\n");
fprintf(rdest, "    r := mkvect (n := sub1 length l);\n");
fprintf(rdest, "    for i := 0:n do <<\n");
fprintf(rdest, "       putv(r, i, list_to_vec32 car l);\n");
fprintf(rdest, "       l := cdr l >>;\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "fluid '(hashsize!* metrics_hash!* fontkern!* kerntable!* ligaturetable!*);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic (hashsize!* := %d);\n", HASHTABLESIZE);
fprintf(rdest, "\n");
        fprintf(dest, "const uint64_t charmetrics[%d][5] = \n{", HASHTABLESIZE);
        fprintf(rdest, "#eval (setq metrics_hash!* (list_to_metric_table '\n    (");
        for (i=0; i<HASHTABLESIZE; i++)
        {   if (i != 0) fprintf(dest, ",");
            fprintf(dest,
                "\n    {UINT64_C(0x%.16" PRIx64 "), UINT64_C(0x%.16" PRIx64 "), UINT64_C(0x%.16" PRIx64 "),"
                "\n                                   UINT64_C(0x%.16" PRIx64 "), UINT64_C(0x%.16" PRIx64 ")}",
                hashtable[i][0],
                hashtable[i][1], hashtable[i][2],
                hashtable[i][3], hashtable[i][4]);
            fprintf(rdest, "\n     (0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32,
                (int)hashtable[i][0], (int)(hashtable[i][0]>>32),
                (int)hashtable[i][1], (int)(hashtable[i][1]>>32),
                (int)hashtable[i][2]);
            fprintf(rdest, "\n      0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 ")",
                                      (int)(hashtable[i][2]>>32),
                (int)hashtable[i][3], (int)(hashtable[i][3]>>32),
                (int)hashtable[i][4], (int)(hashtable[i][4]>>32));
        }
        fprintf(dest, "\n};\n\n");
        fprintf(dest, "#define SECONDHASHMODULUS %d\n\n", HASHTABLESIZE-secondhash);
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "const int16_t fontkern[] = \n{");
        fprintf(rdest, "#eval (setq fontkern!* (list_to_vec16 '\n    (");
        for (i=0; i<F_end; i++)
        {   int w = fprintf(dest, "\n    %d", fontkern[i]);
            if (i != F_end-1) fprintf(dest, ",");
            else fprintf(dest, " ");
            while (++w < 16) fprintf(dest, " ");
            w = fprintf(rdest, "\n    %d ", fontkern[i]);
            while (++w < 16) fprintf(rdest, " ");
            fprintf(dest, "// %s", fontnames[i]);
            if (i != F_end-2 &&
                fontkern[i+1] != fontkern[i])
                fprintf(dest, " [%d items]", fontkern[i+1]-fontkern[i]);
            fprintf(rdest, "%% %s", fontnames[i]);
            if (i != F_end-2 &&
                fontkern[i+1] != fontkern[i])
                fprintf(rdest, " [%d items]", fontkern[i+1]-fontkern[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "const uint32_t kerntable[] = \n{");
        fprintf(rdest, "#eval (setq kerntable!* (list_to_vec32 '\n    (");
        for (i=0; i<kernp; i++)
        {   fprintf(dest, "\n    0x%.8" PRIx32, kerntable[i]);
            if (i != kernp-1) fprintf(dest, ",");
            else fprintf(dest, " ");
            fprintf(rdest, "\n    0x%.8" PRIx32 " ", kerntable[i]);
            if ((kerntable[i] & IS_LIGATURE) != 0)
                fprintf(dest, "   // [%d:%d] %s + %s ligature #%d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               kerntable[i]>>23, ktfont[i]);
            else
                fprintf(dest, "   // [%d:%d] %s + %s : %d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               ktadjustment[i], ktfont[i]);
            if ((kerntable[i] & IS_BLOCKEND) != 0) fprintf(dest, " ;;");
            if ((kerntable[i] & IS_LIGATURE) != 0)
                fprintf(rdest, "   %% [%d:%d] %s + %s ligature #%d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               kerntable[i]>>23, ktfont[i]);
            else
                fprintf(rdest, "   %% [%d:%d] %s + %s : %d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               ktadjustment[i], ktfont[i]);
            if ((kerntable[i] & IS_BLOCKEND) != 0) fprintf(rdest, " ;;");
        }
        fprintf(dest, "\n};\n\n");
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "const uint32_t ligaturetable[] = \n{");
        fprintf(rdest, "#eval (setq ligaturetable!* (list_to_vec32 '\n    (");
        for (i=0; i<ligp; i++)
        {   int l = fprintf(dest, "\n    %" PRId32, ligtable[i]);
            if (i != ligp-1) fprintf(dest, ",");
            else fprintf(dest, " ");
            while (++l < 12) fprintf(dest, " ");
            l = fprintf(rdest, "\n    %" PRId32 " ", ligtable[i]);
            while (++l < 12) fprintf(rdest, " ");
            fprintf(dest, "   // [%d] %s + %s => %s (%s)",
                          i, ltfirst[i], ltfollow[i], ltname[i], ltfont[i]);
            fprintf(rdest, "   %% [%d] %s + %s => %s (%s)",
                          i, ltfirst[i], ltfollow[i], ltname[i], ltfont[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "// end of charmetrics.h\n");
        fprintf(rdest, "%% The use of #eval means that the metrics above have been defined at\n");
        fprintf(rdest, "%% parse time. I now need to ensure that they will be available even\n");
        fprintf(rdest, "%% when this code is passed through the compiler and hence everything\n");
        fprintf(rdest, "%% goes via a FASL file. The slighly curious macro here should achieve\n");
        fprintf(rdest, "%% that.\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic macro procedure get_character_metrics !*unused!*;\n");
        fprintf(rdest, "  list('progn,\n");
        fprintf(rdest, "    list('setq, 'metrics_hash!*, mkquote metrics_hash!*),\n");
        fprintf(rdest, "    list('setq, 'fontkern!*, mkquote fontkern!*),\n");
        fprintf(rdest, "    list('setq, 'kerntable!*, mkquote kerntable!*),\n");
        fprintf(rdest, "    list('setq, 'ligaturetable!*, mkquote ligaturetable!*),\n");
        fprintf(rdest, "    \"character metrics established\");\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "%% The call to the macro here expands into four simple assignments.\n");
        fprintf(rdest, "symbolic get_character_metrics();\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "fluid '(c_width c_llx c_lly c_urx c_ury c_kerninfo);\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "%% This code looks up a font/codepoint pair in the tables and returns\n");
        fprintf(rdest, "%% a character width (escapement) and a bounding box. It leaves behind\n");
        fprintf(rdest, "%% c_kerninfo - and index into a kern and ligature table.\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic procedure lookupchar(fontnum, codepoint);\n");
        fprintf(rdest, "  begin\n");
        fprintf(rdest, "    scalar v, h1, h2, w, whi, wlo, fullkey, key;\n");
        fprintf(rdest, "    fullkey := lshift(fontnum, 16) +\n");
        fprintf(rdest, "      (if codepoint >= 0x10000 then 0xd000 + land(codepoint, 0xfff)\n");
        fprintf(rdest, "       else codepoint);\n");
        fprintf(rdest, "    key := lshift(fullkey, -2);\n");
        fprintf(rdest, "    h1 := remainder(land(key, 0x7fffffff), %d);\n", HASHTABLESIZE);
        fprintf(rdest, "    %% Hash table probe 1.\n");
        fprintf(rdest, "    v := land(getv32(w := getv(metrics_hash!*, h1), 0), 0x7ffff);\n");
        fprintf(rdest, "    if not (v = key) then <<\n");
        fprintf(rdest, "      h2 := h1 + remainder(key, %d);\n", HASHTABLESIZE-secondhash);
        fprintf(rdest, "      if h2 >= %d then h2 := h2 - %d;\n", HASHTABLESIZE, HASHTABLESIZE);
        fprintf(rdest, "      %% Hash table probe 2.\n");
        fprintf(rdest, "      v := land(getv32(w := getv(metrics_hash!*, h2), 0), 0x7ffff);\n");
        fprintf(rdest, "      if not (v = key) then <<\n");
        fprintf(rdest, "        h1 := h1 + h2;\n");
        fprintf(rdest, "        if h1 >= %d then h1 := h1 - %d;\n", HASHTABLESIZE, HASHTABLESIZE);
        fprintf(rdest, "        %% Hash table probe 3.\n");
        fprintf(rdest, "        v := land(getv32(w := getv(metrics_hash!*, h1), 0), 0x7ffff);\n");
        fprintf(rdest, "        if not (v = key) then return nil >> >>;\n");
        fprintf(rdest, "    v := 2*land(fullkey, 3);\n");
        fprintf(rdest, "    wlo := getv32(w, v+2);\n");
        fprintf(rdest, "    if wlo = 0 then return nil; %% in hash table but no character here.\n");
        fprintf(rdest, "    whi := getv32(w, v+3);\n");
        fprintf(rdest, "    c_width := land(lshift(whi, -19), 0x1fff);\n");
        fprintf(rdest, "    c_llx := land(lshift(whi, -6), 0x1fff) - 3000;\n");
        fprintf(rdest, "    c_lly := land(lshift(wlo, -26), 0x3f) +\n");
        fprintf(rdest, "             land(lshift(whi, 6), 0xfc0) - 1000;\n");
        fprintf(rdest, "    c_urx := land(lshift(wlo, -13), 0x1fff) - 500;\n");
        fprintf(rdest, "    c_ury := land(wlo, 0x1fff) - 1000;\n");
        fprintf(rdest, "    if v = 0 then c_kerninfo := land(lshift(getv32(w, 0), -19), 0x7ff)\n");
        fprintf(rdest, "    else if v = 2 then c_kerninfo := land(lshift(getv32(w, 0), -30), 0x3) +\n");
        fprintf(rdest, "                                     land(lshift(getv32(w, 1), 2), 0x7fc)\n");
        fprintf(rdest, "    else if v = 4 then c_kerninfo := land(lshift(getv32(w, 1), -9), 0x7ff)\n");
        fprintf(rdest, "    else c_kerninfo := land(lshift(getv32(w, 1), -20), 0x7ff);\n");
        fprintf(rdest, "    if not zerop c_kerninfo then\n");
        fprintf(rdest, "      c_kerninfo := c_kerninfo + getv16(fontkern!*, fontnum);\n");
        fprintf(rdest, "    return t\n");
        fprintf(rdest, "  end;\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic procedure lookupkernadjustment codepoint;\n");
        fprintf(rdest, "  begin\n");
        fprintf(rdest, "    scalar i, w;\n");
        fprintf(rdest, "    if zerop (i := c_kerninfo) then return 0;\n");
        fprintf(rdest, " a: w := getv32(kerntable!*, i);\n");
        fprintf(rdest, "    if land(w, 0x001fffff) = codepoint and\n");
        fprintf(rdest, "      zerop land(w, 0x00200000) then <<\n");
        fprintf(rdest, "        w := land(lshift(w, -23), 0x1ff);\n");
        fprintf(rdest, "        if not zerop land(w, 0x100) then w := w - 0x200;\n");
        fprintf(rdest, "        return w >>\n");
        fprintf(rdest, "    else if not zerop land(w, 0x00400000) then return 0;\n");
        fprintf(rdest, "    i := add1 i;\n");
        fprintf(rdest, "    go to a\n");
        fprintf(rdest, "  end;\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic procedure lookupligature codepoint;\n");
        fprintf(rdest, "  begin\n");
        fprintf(rdest, "    scalar i, w;\n");
        fprintf(rdest, "    if zerop (i := c_kerninfo) then return nil;\n");
        fprintf(rdest, " a: w := getv32(kerntable!*, i);\n");
        fprintf(rdest, "    if land(w, 0x001fffff) = codepoint and\n");
        fprintf(rdest, "      not zerop land(w, 0x00200000) then\n");
        fprintf(rdest, "        return getv32(ligaturetable!*, land(lshift(w, -23), 0x1ff))\n");
        fprintf(rdest, "    else if not zerop land(w, 0x00400000) then return nil;\n");
        fprintf(rdest, "    i := add1 i;\n");
        fprintf(rdest, "    go to a\n");
        fprintf(rdest, "  end;\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "end;\n\n");
        fprintf(rdest, "%% end of charmetrics.red\n");
        fclose(dest);
        fclose(rdest);
    }
    return 0;
}

#else // CREATE
//
// I am putting the code that decodes and accesses metric information
// in the same file as the program that reads raw ".afm" files and
// packs the information for me. I hope that this keeps coding and decoding
// together so they will remian in step.
//

// lookupchar takes a font and a codepoint and returns true if there is
// information about the character and false if not. If it returns true
// it will have left information about the character in a number of
// variables that can then be inspected.

#define HASHTABLESIZE (sizeof(charmetrics)/sizeof(charmetrics[0]))

int c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo;

int lookupchar(int fontnum, int codepoint)
{
    int fullkey = pack_character(fontnum, codepoint); // 21-bit key
    int key = fullkey >> 2; // because my hash table has line-size 4
// I compute two hash values - one for the initial probe position and
// the second to give an stride,
    int v, h1, h2;
    uint64_t w;
    h1 = key % HASHTABLESIZE;
    v = (int)charmetrics[h1][0] & 0x7ffff;
    if (v != key)
    {   h2 = key % SECONDHASHMODULUS;
        h1 += h2;
        if (h1 >= HASHTABLESIZE) h1 -= HASHTABLESIZE;
        v = (int)charmetrics[h1][0] & 0x7ffff;
        if (v != key)
        {   h1 += h2;
            if (h1 >= HASHTABLESIZE) h1 -= HASHTABLESIZE;
            v = (int)charmetrics[h1][0] & 0x7ffff;
            if (v != key) return 0;
        }
    }
    w = charmetrics[h1][1+(fullkey&3)];
// Even though the cache line exists this entry in it may be unused.
    if (w == 0) return 0;
    c_width = (int)(w >> 51) & 0x1fff;
    c_llx = ((int)(w >> 38) & 0x1fff) - 3000;
    c_lly = ((int)(w >> 26) & 0x0fff) - 1000;
    c_urx = ((int)(w >> 13) & 0x1fff) - 500;
    c_ury = ((int)w & 0x1fff) - 1000;
// Based on the font and 11 bits of information from the hash table I will
// set up a pointer into kerntable. The interpretation of that will be
// considered in the function lookupkernandligature. If the 11 bit field
// contains zero then there is neither kern nor ligature information
// associated with this character.
    v = (int)(charmetrics[h1][0] >> (19+11*(fullkey&3))) & 0x7ff;
    if (v != 0) v += fontkern[fontnum];
// c_kerninfo will be left zero if there is no information, otherwise an
// index into a table.
    c_kerninfo = v;
    return 1;
}

// Having looked up a single character I may now need to check for
// ligature or kerning information. I will do that by passing the
// codepoint of the successor character (which must be in the same
// font). Thus the complete sequence will be
//      lookupchar(font_number, codepoint_for_first_character);
//      lookupkernandligature(codepoint_for_second_character);
// This returns an int32_t where the bottom 21 bits are a codepoint for
// a character that can replace the two that were specified. For instance
// this can return a single ligature "fi" is the two input codepoints are
// for "f" and "i", or it could return first "ff" for two "f" characters
// that are adjacent, and then "ffi" for the resulting "ff" if followed
// by "i". Those bits will be returned as zero if no ligature is available
// (and that will almost always be the case).
// The top 9 bits of the 32-bit word will be a signed value for a
// kerning adjustment to the spacing between a pair of characters, relative
// to 1000 as the notional height of the character cell. This is again
// 0 if no adjustment is called for. As one of the more extreme examples,
// in one font if an "A" is followed by a "V" the space between them can be
// decreased by 109 units, while when a "T" is followed by a "W" an extra
// 41 units (and perhaps less obviously an "L" followd by "-" (hyphen)
// calls for even more extra space than that.
//
// I provide variants that collect just kern or just ligature information.

int32_t lookupkernandligature(int codepoint)
{
    int32_t r = 0;
    uint32_t w;
    int i;
    if ((i = c_kerninfo) == 0) return 0;  // No info based on current start.
// The worst cases I can see in my fonts is the kern information for "W"
// in STIXGeneral where around 50 characters following "W" get their spacing
// adjusted. That gives some impression of the most extreme number of
// times this loop will be traversed. For many characters there will be no
// kern information at all, and when there is any it will usually be
// pretty limited so average costs here should end up low.
    do
    {   w = kerntable[i++];
// The kern table contains a sequence of 32-bit words. The low 21 bits of
// each is a codepoint being the second character of a pair. The next two
// bits are flags. One indicates whether the word is documenting kern or
// ligature information. The other marks the final word of information
// relating to a lead character. That leaves 9 bits. For kern information
// that is a 9-bit signed spacing adjustment. For ligatures it is a
// 9 bit unsigned index into a table of codepoints giving the single
// character to be used to replace the initial pair. Note that one pair
// of characters can (and often well!) have both kern and ligature information
// which is why the return value here can hand back both and why searching
// continues through all information about the relevant pair. It would be a
// MESS if the tables included two entries for the same character pair but
// yielding different results! I ought to police that while creating the
// tables.
// Because w is an unsigned value I do not need to mask the result of the
// right shift.
        if ((w & 0x001fffff) == codepoint)
        {   if ((w & IS_LIGATURE) != 0) r |= ligaturetable[w >> 23];
            else r |= (w & 0xff800000);
        }
    } while ((w & IS_BLOCKEND) == 0);
    return r;
}

// Much the same as the above but ONLY looks for kern information and returns
// its result as a simple integer. In case kern information is found this
// is just slightly faster than using the more general method.

int32_t lookupkernadjustment(int codepoint)
{
    int32_t w;
    int i;
    if ((i = c_kerninfo) == 0) return 0;  // No info based on current start.
    do
    {   w = kerntable[i++];
// The shift right in the return statement relies on w being a signed
// value and on signed shifts being arithmetic.
        if ((w & 0x001fffff) == codepoint &&
            (w & IS_LIGATURE) == 0) return (w >> 23);
    } while ((w & IS_BLOCKEND) == 0);
    return 0;
}

// Much the same as the above but ONLY looks for ligature information.

int32_t lookupligature(int codepoint)
{
    uint32_t w;
    int i;
    if ((i = c_kerninfo) == 0) return 0;  // No info based on current start.
    do
    {   w = kerntable[i++];
// I made w unsigned so that the shift right returned an unsigned index.
        if ((w & 0x001fffff) == codepoint &&
            (w & IS_LIGATURE) != 0) return ligaturetable[w >> 23];
    } while ((w & IS_BLOCKEND) == 0);
    return 0;
}

#ifdef TEST
// If TEST is defined then this code will try some very minimal tests.
// Expected output is
//
//    Hash table size was 10883
//    "e": width 444   BB 25 -10 424 460  (3656)
//    "f": width 333   BB 20 0 383 683  (3662)
//    "g": width 500   BB 28 -218 470 460  (3689)
//    "h": width 500   BB 9 0 487 683  (3702)
//    "i": width 278   BB 16 0 253 683  (3704)
//    "j": width 278   BB -70 -218 194 683  (0)
//    "k": width 500   BB 7 0 505 683  (3707)
//    "l": width 278   BB 19 0 257 683  (3725)
//    "m": width 778   BB 16 0 775 460  (3727)
//    Kern/ligature data for sequence f-i is 14 64257
//    Kern/ligature data for sequence f-l is 44 64258
//
// The last two lines say that if in font STIXGeneral-Regular an "f" is
// followed by an "i" then either the two may have their spacing adjusted
// by 14 units or the pair may be replaced by the character at codepoint
// 64257 (which is "fi")... and similarly for "f" followed by "l". The output
// higher up tells us that in this font there are no special cases involving
// a "j" followed by something else. "BB" is for "Bounding Box" and the
// four numbers are for lower-left-x, lower-left-y, upper-right-x and
// upper-right-y in that order.

int main(int argc, char *argv[])
{
    int i, r;
    printf("====== Test program starting ======\n");
    printf("Hash table size was %d\n", (int)HASHTABLESIZE);
    printf("Second modulus %d (%d)\n", (int)SECONDHASHMODULUS,
           (int)(HASHTABLESIZE-SECONDHASHMODULUS));
    for (i='e'; i<'n'; i++)
    {   r = lookupchar(F_General, i);
        if (r) printf("\"%c\": width %d   BB %d %d %d %d  (%d)\n",
                      i, c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo);
        else printf("\"%c\" char not found\n", i);
        fflush(stdout);
    }
    if (!lookupchar(F_General, 'f')) printf("Character \"f\" not found\n");
    else
    {   int32_t k = lookupkernandligature('i');
        printf("Kern/ligature data for sequence f-i is %d %d\n",
               (int)(k >> 23), (int)(k & 0x001fffff));
        fflush(stdout);
        k = lookupkernandligature('l');
        printf("Kern/ligature data for sequence f-l is %d %d\n",
               (int)(k >> 23), (int)(k & 0x001fffff));
        fflush(stdout);
    }
    return 0;
}


#endif // TEST
#endif // CREATE

// end of charmetrics.c
