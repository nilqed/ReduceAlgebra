#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "FXHash.h"
#include "FXStream.h"
#include "FXTextCodec.h"
#include "FXCP864Codec.h"

namespace FX {

FXIMPLEMENT(FXCP864Codec,FXTextCodec,NULL,0)


//// Created by codec tool on 03/25/2005 from: CP864.TXT ////
const unsigned short forward_data[256]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   1642, 38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   176,  183,  8729, 8730, 9618, 9472, 9474, 9532, 9508, 9516, 9500, 9524, 9488, 9484, 9492, 9496,
   946,  8734, 966,  177,  189,  188,  8776, 171,  187,  65271, 65272, 65533, 65533, 65275, 65276, 65533,
   160,  173,  65154, 163,  164,  65156, 65533, 65533, 65166, 65167, 65173, 65177, 1548, 65181, 65185, 65189,
   1632, 1633, 1634, 1635, 1636, 1637, 1638, 1639, 1640, 1641, 65233, 1563, 65201, 65205, 65209, 1567,
   162,  65152, 65153, 65155, 65157, 65226, 65163, 65165, 65169, 65171, 65175, 65179, 65183, 65187, 65191, 65193,
   65195, 65197, 65199, 65203, 65207, 65211, 65215, 65217, 65221, 65227, 65231, 166,  172,  247,  215,  65225,
   1600, 65235, 65239, 65243, 65247, 65251, 65255, 65259, 65261, 65263, 65267, 65213, 65228, 65230, 65229, 65249,
   65149, 1617, 65253, 65257, 65260, 65264, 65266, 65232, 65237, 65269, 65270, 65245, 65241, 65265, 9632, 65533,
  };


const unsigned char reverse_plane[17]={
  0, 64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
  };

const unsigned char reverse_pages[128]={
  0,  61, 100,100,100,100,100,100,131,179,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,206,
  100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
  };

const unsigned short reverse_block[270]={
  0,   16,  32,  48,  64,  80,  96,  112, 128, 128, 144, 160, 128, 174, 128, 183,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 197, 207, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 214, 227, 128,
  128, 243, 258, 274, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 285, 128, 128, 300, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 316, 332, 345, 358, 128, 128, 128, 128, 128, 372, 388, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 391, 407, 423, 439, 455, 471, 487, 503, 519, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  };

const unsigned char reverse_data[535]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   26,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   160,  26,   192,  163,  164,  26,   219,  26,   26,   26,   26,   151,  220,  161,  26,   26,
   128,  147,  26,   26,   26,   26,   26,   129,  26,   26,   26,   152,  149,  148,  26,   26,
   26,   26,   26,   26,   26,   222,  26,   26,   26,   26,   26,   26,   26,   26,   221,  26,
   26,   26,   26,   26,   26,   26,   26,   144,  26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   146,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   172,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   187,  26,
   26,   26,   191,  224,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   241,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  37,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   130,  131,  26,   26,   26,   145,  26,   26,   26,   26,
   26,   26,   26,   26,   150,  26,   26,   26,   26,   26,   26,   26,   133,  26,   134,  26,
   26,   26,   26,   26,   26,   26,   26,   26,   141,  26,   26,   26,   140,  26,   26,   26,
   142,  26,   26,   26,   143,  26,   26,   26,   138,  26,   26,   26,   26,   136,  26,   26,
   26,   26,   26,   26,   26,   137,  26,   26,   26,   26,   139,  26,   26,   26,   26,   26,
   26,   26,   135,  26,   26,   26,   132,  26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   254,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   240,  26,   26,   193,  194,  162,  195,  165,  196,  26,   26,   26,
   26,   26,   198,  26,   199,  168,  169,  26,   200,  26,   201,  26,   170,  26,   202,  26,
   171,  26,   203,  26,   173,  26,   204,  26,   174,  26,   205,  26,   175,  26,   206,  26,
   207,  26,   208,  26,   209,  26,   210,  26,   188,  26,   211,  26,   189,  26,   212,  26,
   190,  26,   213,  26,   235,  26,   214,  26,   215,  26,   26,   26,   216,  26,   26,   26,
   223,  197,  217,  236,  238,  237,  218,  247,  186,  26,   225,  26,   248,  26,   226,  26,
   252,  26,   227,  26,   251,  26,   228,  26,   239,  26,   229,  26,   242,  26,   230,  26,
   243,  26,   231,  244,  232,  26,   233,  245,  253,  246,  234,  26,   249,  250,  153,  154,
   26,   26,   157,  158,  26,   26,   26,
  };


FXint FXCP864Codec::mb2wc(FXwchar& wc,const FXchar* src,FXint nsrc) const {
  if(nsrc<1) return -1;
  wc=forward_data[(FXuchar)src[0]];
  return 1;
  }


FXint FXCP864Codec::wc2mb(FXchar* dst,FXint ndst,FXwchar wc) const {
  if(ndst<1) return -1;
  dst[0]=reverse_data[reverse_block[reverse_pages[reverse_plane[wc>>16]+((wc>>10)&63)]+((wc>>4)&63)]+(wc&15)];
  return 1;
  }

FXint FXCP864Codec::mibEnum() const {
  return 2051;
  }


const FXchar* FXCP864Codec::name() const {
  return "IBM864";
  }


const FXchar* FXCP864Codec::mimeName() const {
  return "IBM864";
  }


const FXchar* const* FXCP864Codec::aliases() const {
  static const FXchar *const list[]={"microsoft-cp864","IBM864","cp864","csIBM864",NULL};
  return list;
  }

}

