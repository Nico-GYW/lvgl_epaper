/*******************************************************************************
 * Size: 10 px
 * Bpp: 4
 * Opts: --bpp 4 --size 10 --font RalewayThin-wght400.ttf --range 32-127,160-255 --format lvgl -o generated_fonts/raleway_10.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef RALEWAY_10
#define RALEWAY_10 1
#endif

#if RALEWAY_10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x19, 0x0, 0xf0, 0xe0, 0x28, 0xc8,

    /* U+0022 "\"" */
    0x5a, 0x31, 0x20,

    /* U+0023 "#" */
    0x0, 0x31, 0x4, 0x80, 0x5e, 0x47, 0xe0, 0x2e,
    0xaf, 0x1c, 0x62, 0xb4, 0xe5, 0x6, 0xb3, 0xf0,
    0xb0, 0xa, 0x53, 0x73, 0x0, 0x19, 0x1c, 0x0,

    /* U+0024 "$" */
    0x0, 0xa, 0x80, 0x4f, 0x76, 0x92, 0x40, 0xbb,
    0x49, 0x3e, 0x80, 0x63, 0xea, 0xa3, 0x80, 0x12,
    0xa8, 0x34, 0x62, 0x0, 0x71, 0x14, 0x5d, 0xd2,
    0x53, 0x76, 0xa2,

    /* U+0025 "%" */
    0x37, 0x70, 0x81, 0x99, 0x1d, 0x14, 0x54, 0xd9,
    0x8a, 0x8c, 0xc0, 0x16, 0x63, 0xb8, 0x3, 0x33,
    0x15, 0x88, 0x15, 0x46, 0xd, 0x44, 0x6, 0x5a,
    0xd8,

    /* U+0026 "&" */
    0x6, 0x89, 0x10, 0xb, 0x23, 0x50, 0x2, 0x28,
    0xd5, 0x0, 0xcf, 0x40, 0x80, 0xbd, 0xf2, 0x7a,
    0x4, 0x40, 0xac, 0xe0, 0x7d, 0x89, 0x96, 0x98,

    /* U+0027 "'" */
    0x54, 0x17,

    /* U+0028 "(" */
    0x6, 0x20, 0xf2, 0x5d, 0xd, 0x50, 0xf3, 0x5,
    0xa0, 0x21, 0x10, 0x40, 0x80,

    /* U+0029 ")" */
    0x61, 0x6, 0x80, 0xe, 0xf3, 0x1, 0x20, 0xd1,
    0x4f, 0x6, 0x50,

    /* U+002A "*" */
    0x19, 0x31, 0xe2,

    /* U+002B "+" */
    0x3, 0x60, 0x3a, 0xd5, 0x3a, 0xd5, 0x3, 0x60,

    /* U+002C "," */
    0x26, 0x22, 0x0,

    /* U+002D "-" */
    0x39, 0x92, 0x80,

    /* U+002E "." */
    0x53,

    /* U+002F "/" */
    0x0, 0xca, 0xc0, 0x10, 0xfb, 0x0, 0x57, 0x0,
    0x13, 0x61, 0x0, 0x7, 0x18, 0x2, 0xbb, 0x0,
    0x4d, 0x82, 0x1, 0x0,

    /* U+0030 "0" */
    0x3, 0x99, 0x20, 0xc, 0x4c, 0xb8, 0x9f, 0x80,
    0x12, 0xa0, 0x20, 0x17, 0xa7, 0x0, 0x2e, 0xc5,
    0xf5, 0x4f, 0x30,

    /* U+0031 "1" */
    0x2, 0x60, 0x2, 0xab, 0x40, 0xa, 0xe0, 0x1f,
    0xfc, 0x13, 0x96, 0x90,

    /* U+0032 "2" */
    0x7, 0x98, 0x2, 0x59, 0xc8, 0x22, 0x6, 0x68,
    0x1d, 0x62, 0x94, 0xd2, 0x5, 0x4, 0xc9, 0x80,

    /* U+0033 "3" */
    0x8, 0x98, 0x13, 0xb9, 0xab, 0x33, 0x0, 0x8,
    0x0, 0xfd, 0x40, 0x7, 0xd8, 0x41, 0x0, 0x96,
    0x26, 0x56,

    /* U+0034 "4" */
    0x0, 0x84, 0x3, 0xb4, 0xc0, 0x28, 0x40, 0x9,
    0xb3, 0x80, 0x6, 0x28, 0x1, 0x57, 0x4d, 0x48,
    0xcc, 0xd7, 0x22, 0x1, 0x31, 0x0,

    /* U+0035 "5" */
    0x9, 0x99, 0x80, 0x29, 0x93, 0x1, 0x94, 0xc8,
    0x41, 0xfe, 0x62, 0x81, 0x10, 0x2, 0x20, 0x63,
    0x1, 0x10, 0x32, 0x4c, 0x50, 0x0,

    /* U+0036 "6" */
    0x4, 0x99, 0x40, 0x3, 0x66, 0x58, 0x2b, 0xef,
    0x0, 0x25, 0x8f, 0x18, 0x81, 0xc0, 0xa, 0xc4,
    0xc0, 0x2, 0x69, 0xf5, 0x48, 0xa8,

    /* U+0037 "7" */
    0x69, 0x9a, 0xc1, 0xa6, 0x54, 0x60, 0x1a, 0x24,
    0x2, 0x5c, 0x10, 0xb, 0x9c, 0x2, 0x6e, 0x0,
    0xde, 0xa0, 0x10,

    /* U+0038 "8" */
    0x7, 0x9a, 0x60, 0x2e, 0x9a, 0xc1, 0x33, 0x0,
    0x42, 0x22, 0xbb, 0x68, 0x27, 0xdd, 0xbc, 0xc8,
    0x80, 0xe, 0x66, 0x6c, 0xcb, 0x94,

    /* U+0039 "9" */
    0x5, 0x99, 0x18, 0x29, 0x4c, 0xc3, 0x8c, 0x0,
    0xf7, 0xc6, 0x0, 0x78, 0x29, 0x44, 0x9, 0x44,
    0x22, 0x4, 0x62, 0x73, 0x28, 0x0,

    /* U+003A ":" */
    0x53, 0x53, 0x0, 0xca, 0x60,

    /* U+003B ";" */
    0x44, 0xc0, 0x19, 0x15, 0x4e,

    /* U+003C "<" */
    0x0, 0x99, 0x41, 0x28, 0x95, 0xfe, 0x90, 0x1f,
    0x68, 0xc0, 0xd, 0x56, 0xa0, 0x14, 0x28,

    /* U+003D "=" */
    0x27, 0x72, 0x0, 0x42,

    /* U+003E ">" */
    0x57, 0x0, 0x94, 0xe9, 0x0, 0x9, 0x5d, 0x0,
    0x55, 0xb0, 0xb5, 0x6e, 0xb, 0x2, 0x0,

    /* U+003F "?" */
    0x29, 0x89, 0x1, 0x98, 0xc4, 0x30, 0x1, 0x38,
    0x2, 0x8, 0xc1, 0x71, 0x40, 0xa, 0x80, 0x13,
    0x90, 0x0,

    /* U+0040 "@" */
    0x0, 0x1a, 0xa9, 0x0, 0x25, 0x73, 0x20, 0x60,
    0x36, 0x46, 0x7c, 0x66, 0x29, 0x8b, 0x30, 0x80,
    0x34, 0xb3, 0x8, 0xd, 0x4f, 0x5d, 0x85, 0x84,
    0xd9, 0xdc, 0xd2, 0xc8, 0xa, 0x2a, 0xa4, 0x0,
    0x0,

    /* U+0041 "A" */
    0x0, 0x16, 0x80, 0x75, 0x51, 0x40, 0x30, 0xbf,
    0x80, 0x4d, 0x41, 0xa4, 0x0, 0xdb, 0x8f, 0xb0,
    0x3c, 0x88, 0x8c, 0x25, 0x80, 0x2f, 0x60,

    /* U+0042 "B" */
    0x1d, 0x99, 0x5a, 0x80, 0x12, 0x65, 0x7c, 0x1,
    0xe1, 0x0, 0x2c, 0x42, 0xf8, 0x0, 0xb1, 0xb,
    0xe1, 0x0, 0xe3, 0x30, 0x24, 0xcc, 0x24,

    /* U+0043 "C" */
    0x2, 0xaa, 0x9c, 0x1, 0x37, 0x54, 0x12, 0x6f,
    0x10, 0x3, 0x17, 0x30, 0x7, 0x6b, 0x80, 0x72,
    0xf0, 0x80, 0x15, 0x2, 0xae, 0xa8, 0x48,

    /* U+0044 "D" */
    0x1d, 0x99, 0x52, 0x0, 0x12, 0x65, 0x5c, 0x40,
    0x1d, 0x14, 0x1, 0xc4, 0x40, 0xe, 0x22, 0x0,
    0x74, 0x50, 0x24, 0xca, 0xb8, 0x80,

    /* U+0045 "E" */
    0x1d, 0x99, 0x94, 0x12, 0x66, 0x50, 0xf, 0x92,
    0x66, 0x0, 0x24, 0xcc, 0x1, 0xf9, 0x26, 0x66,

    /* U+0046 "F" */
    0x1d, 0x99, 0x94, 0x12, 0x66, 0x50, 0xf, 0x96,
    0x20, 0xe0, 0x5, 0x88, 0x38, 0x7, 0xff, 0x4,

    /* U+0047 "G" */
    0x1, 0xaa, 0x9c, 0x1, 0x57, 0x54, 0x22, 0x37,
    0x8, 0x1, 0x4b, 0x9c, 0x0, 0x90, 0xfc, 0xe0,
    0x4, 0x8e, 0x6e, 0x10, 0x3, 0x10, 0x54, 0x54,
    0x99, 0x0,

    /* U+0048 "H" */
    0x19, 0x0, 0x8d, 0xc0, 0x3f, 0xf8, 0x69, 0x33,
    0x80, 0x9, 0x33, 0x80, 0x3f, 0xf8, 0x60,

    /* U+0049 "I" */
    0x19, 0x0, 0xff, 0xe0, 0x0,

    /* U+004A "J" */
    0x0, 0xac, 0x3, 0xff, 0x8e, 0x20, 0x1e, 0x79,
    0xb9, 0x0,

    /* U+004B "K" */
    0x19, 0x0, 0xd, 0x0, 0x61, 0xba, 0x0, 0x86,
    0xec, 0x1, 0x1d, 0x80, 0x80, 0x4f, 0x7c, 0xe0,
    0x12, 0xa, 0x7a, 0x0, 0x74, 0x70, 0x80,

    /* U+004C "L" */
    0x19, 0x0, 0xff, 0xeb, 0xa4, 0xcc, 0xc0,

    /* U+004D "M" */
    0x1d, 0x0, 0xc5, 0xa0, 0x7, 0x0, 0xa0, 0x41,
    0x34, 0x41, 0x35, 0xc0, 0x11, 0x0, 0xf7, 0x0,
    0x88, 0x6b, 0x80, 0x3a, 0xd, 0x40, 0x3d, 0x20,
    0x10,

    /* U+004E "N" */
    0x1d, 0x0, 0xd6, 0x3, 0x40, 0x1c, 0xb8, 0xe0,
    0x1c, 0xdc, 0x80, 0x1d, 0x3e, 0x40, 0x1d, 0x52,
    0x1, 0xc3, 0xe,

    /* U+004F "O" */
    0x1, 0x9a, 0xa3, 0x0, 0x55, 0x15, 0x40, 0x60,
    0x6e, 0x10, 0x3, 0x68, 0x73, 0x80, 0x61, 0xe,
    0x70, 0xc, 0x20, 0xdc, 0x20, 0x6, 0xd0, 0x5,
    0x5d, 0x50, 0x18, 0x0,

    /* U+0050 "P" */
    0x1d, 0x99, 0x51, 0x2, 0x4c, 0xae, 0x0, 0x30,
    0x88, 0x3, 0x11, 0x1, 0x26, 0x57, 0x0, 0x93,
    0x30, 0x80, 0x78,

    /* U+0051 "Q" */
    0x1, 0x9a, 0xa3, 0x0, 0x55, 0x15, 0x40, 0x60,
    0x6e, 0x10, 0x3, 0x68, 0x73, 0x80, 0x61, 0xe,
    0x70, 0x0, 0x80, 0x83, 0x70, 0x81, 0xfe, 0x80,
    0x2a, 0xea, 0x14, 0x40,

    /* U+0052 "R" */
    0x1d, 0x99, 0x51, 0x0, 0x12, 0x65, 0x50, 0x1,
    0xe1, 0x0, 0xe1, 0x10, 0x1, 0x26, 0xa9, 0x60,
    0x4, 0x9a, 0x10, 0xf, 0x5d, 0x80,

    /* U+0053 "S" */
    0x7, 0x89, 0x90, 0xa8, 0xc4, 0xc8, 0x45, 0xe0,
    0x19, 0x32, 0xad, 0x80, 0xb, 0x56, 0x32, 0x62,
    0x0, 0x63, 0x18, 0x99, 0x5c, 0x0,

    /* U+0054 "T" */
    0x79, 0xbc, 0x98, 0x79, 0xfa, 0x98, 0x0, 0xff,
    0xe9, 0x0,

    /* U+0055 "U" */
    0x37, 0x0, 0xd6, 0x1, 0xff, 0xc9, 0x2e, 0x0,
    0x84, 0x63, 0x10, 0x3, 0x70, 0x5d, 0xaa, 0x80,
    0x80,

    /* U+0056 "V" */
    0xa1, 0x0, 0x91, 0xe5, 0x80, 0x2e, 0x63, 0xc0,
    0x0, 0x98, 0x86, 0xa0, 0x4d, 0x80, 0x1b, 0x80,
    0x88, 0x1, 0x13, 0xf8, 0x6, 0xa9, 0x50, 0x0,

    /* U+0057 "W" */
    0xa1, 0x3, 0x60, 0xa0, 0x4, 0x94, 0xb0, 0x1e,
    0x37, 0x0, 0x99, 0x1e, 0x0, 0x32, 0x90, 0x1b,
    0x80, 0x1a, 0xa0, 0x1d, 0x88, 0x0, 0x6f, 0xc,
    0x94, 0x46, 0x80, 0x62, 0x6c, 0x5d, 0xe6, 0x0,
    0xd3, 0xc, 0x1c, 0x40, 0x10,

    /* U+0058 "X" */
    0x83, 0x0, 0xa8, 0x22, 0x44, 0x26, 0x0, 0x17,
    0x66, 0xc2, 0x0, 0xe, 0x6a, 0x80, 0x43, 0x86,
    0x80, 0x15, 0xc4, 0x38, 0x41, 0xfc, 0x82, 0xec,
    0x0,

    /* U+0059 "Y" */
    0x83, 0x0, 0xa8, 0x62, 0x0, 0x5, 0xc1, 0xf,
    0x70, 0xf6, 0x0, 0x27, 0x54, 0x0, 0x6b, 0x2,
    0x0, 0xc6, 0x60, 0xf, 0xf0,

    /* U+005A "Z" */
    0x59, 0x9d, 0xab, 0x33, 0x7, 0x0, 0x4d, 0x86,
    0x0, 0x4e, 0x50, 0x1, 0x74, 0x0, 0x53, 0x60,
    0x14, 0x84, 0x4c, 0xa0,

    /* U+005B "[" */
    0x2c, 0x0, 0x20, 0x7, 0xff, 0x10, 0xc8, 0x0,

    /* U+005C "\\" */
    0x65, 0x0, 0xcd, 0xc2, 0x1, 0xa6, 0x0, 0x31,
    0x9, 0x80, 0x68, 0x80, 0x7, 0x7b, 0x80, 0x64,
    0xd2,

    /* U+005D "]" */
    0x4a, 0x40, 0xf, 0xf9, 0x8,

    /* U+005E "^" */
    0x0, 0x61, 0x80, 0x16, 0x28, 0x1, 0x89, 0xe6,
    0xba, 0xd, 0x40,

    /* U+005F "_" */
    0x39, 0x99, 0x0,

    /* U+0060 "`" */
    0x27, 0x27,

    /* U+0061 "a" */
    0x19, 0x8a, 0x21, 0x98, 0xb8, 0x17, 0x67, 0x18,
    0x66, 0x82, 0xa5, 0x98, 0x0,

    /* U+0062 "b" */
    0x47, 0x0, 0xff, 0xbe, 0x26, 0x40, 0x2, 0x89,
    0xd8, 0xd, 0x0, 0x21, 0x87, 0x0, 0x10, 0xc0,
    0x62, 0x76, 0x0,

    /* U+0063 "c" */
    0x8, 0x99, 0x38, 0x37, 0x4c, 0x90, 0x3d, 0x0,
    0x6, 0x18, 0x80, 0x3, 0x5, 0x19, 0x92, 0x0,

    /* U+0064 "d" */
    0x0, 0xc8, 0xe0, 0x1f, 0x45, 0x41, 0x82, 0xf5,
    0x40, 0x3, 0x50, 0x0, 0x61, 0xa8, 0x0, 0x20,
    0x51, 0x87, 0xf, 0x7, 0x87, 0x68,

    /* U+0065 "e" */
    0x7, 0x88, 0x30, 0x28, 0xc4, 0x1, 0x33, 0x9d,
    0xc2, 0x59, 0xce, 0xe5, 0x65, 0x18, 0x82, 0x80,

    /* U+0066 "f" */
    0x7, 0x94, 0xd, 0x94, 0x57, 0x81, 0x56, 0x81,
    0x0, 0xff, 0xe0, 0x0,

    /* U+0067 "g" */
    0x8, 0x98, 0x67, 0x5e, 0x98, 0x10, 0xd4, 0x0,
    0x18, 0x6a, 0x0, 0x8, 0x17, 0xa6, 0x4, 0x69,
    0x94, 0x9, 0x8c, 0x44, 0x2a,

    /* U+0068 "h" */
    0x47, 0x0, 0xff, 0xbe, 0x65, 0x0, 0x3, 0x99,
    0x10, 0x3, 0x0, 0x4, 0x20, 0x1c, 0x60, 0x1e,

    /* U+0069 "i" */
    0x36, 0x36, 0x47, 0x0, 0xfc,

    /* U+006A "j" */
    0x0, 0x13, 0x80, 0x9, 0xc0, 0x7, 0x0, 0x1f,
    0xfc, 0x67, 0xe0, 0x8c, 0x60,

    /* U+006B "k" */
    0x47, 0x0, 0xff, 0xe0, 0x9c, 0x0, 0x49, 0x70,
    0x0, 0xce, 0xd0, 0x8, 0xeb, 0x8, 0x1, 0xe1,
    0x30, 0x0,

    /* U+006C "l" */
    0x37, 0x0, 0xff, 0xe2, 0x16, 0x28,

    /* U+006D "m" */
    0x48, 0x79, 0x75, 0x7a, 0x10, 0x27, 0x9b, 0x67,
    0xe7, 0xd, 0x0, 0x31, 0x83, 0x88, 0x7, 0xef,
    0x0, 0xfe,

    /* U+006E "n" */
    0x48, 0x8a, 0x40, 0x7, 0x10, 0x31, 0xc, 0x0,
    0x10, 0x7, 0x8c, 0x3, 0xc0,

    /* U+006F "o" */
    0x7, 0x99, 0x38, 0x28, 0xcc, 0x81, 0x35, 0x0,
    0xb, 0x9a, 0x80, 0x5, 0xc5, 0x19, 0x90, 0x20,

    /* U+0070 "p" */
    0x48, 0x78, 0x80, 0x4, 0xf1, 0x6e, 0x1e, 0x0,
    0x3c, 0xd, 0x0, 0x21, 0x81, 0x44, 0xf4, 0x7,
    0xc4, 0xd0, 0x7, 0xc0,

    /* U+0071 "q" */
    0x8, 0x98, 0x76, 0x5f, 0x98, 0x0, 0x6a, 0x80,
    0xc, 0x35, 0x0, 0x6, 0xb, 0xd3, 0x0, 0x14,
    0x4c, 0x18, 0x7, 0xc0,

    /* U+0072 "r" */
    0x48, 0x93, 0x2, 0x93, 0xd, 0x0, 0xff, 0x0,

    /* U+0073 "s" */
    0x19, 0x89, 0x25, 0xf8, 0x92, 0x41, 0x97, 0x0,
    0x3c, 0x92, 0xa4, 0xc6, 0x20,

    /* U+0074 "t" */
    0xa, 0x0, 0xf3, 0x3b, 0x3, 0x3b, 0x0, 0x7f,
    0x86, 0x44,

    /* U+0075 "u" */
    0x46, 0x0, 0x41, 0x0, 0x7f, 0xf0, 0x1c, 0x40,
    0x8, 0x7, 0xb3, 0x14, 0xc0,

    /* U+0076 "v" */
    0x91, 0x0, 0x50, 0x5c, 0x81, 0x68, 0x11, 0x2,
    0x98, 0x1, 0xea, 0x22, 0x0, 0x2c, 0x50, 0x0,

    /* U+0077 "w" */
    0x91, 0x8, 0x72, 0xa, 0xb6, 0x0, 0x71, 0x2f,
    0x17, 0x7, 0x88, 0x7a, 0x6, 0xaf, 0xf9, 0x30,
    0x0, 0x93, 0x6d, 0x2c, 0x0,

    /* U+0078 "x" */
    0x74, 0x4, 0x77, 0x6a, 0x73, 0x84, 0x5d, 0x80,
    0x11, 0x70, 0xf, 0x89, 0xae,

    /* U+0079 "y" */
    0x91, 0x0, 0x48, 0x5c, 0x80, 0x88, 0x8, 0x80,
    0xd4, 0x0, 0x97, 0xe2, 0x0, 0x1e, 0x68, 0x7,
    0x20, 0x5, 0x5c, 0x1, 0x0,

    /* U+007A "z" */
    0x47, 0x75, 0xb2, 0x3a, 0x93, 0x0, 0xc4, 0x80,
    0x2e, 0xc0, 0x8, 0x6, 0x74,

    /* U+007B "{" */
    0x1c, 0x0, 0x20, 0x6, 0x5f, 0x6, 0xf0, 0x30,
    0xe, 0x12, 0x0,

    /* U+007C "|" */
    0x13, 0x32, 0x0, 0x7f, 0xf0, 0x80,

    /* U+007D "}" */
    0x4a, 0x4, 0x0, 0xf0, 0x80, 0x70, 0x80, 0x64,
    0xd0,

    /* U+007E "~" */
    0x6, 0x30, 0x32, 0x40, 0x73,

    /* U+00A0 " " */

    /* U+00A1 "¡" */
    0x19, 0x19, 0x5, 0x1c, 0x0, 0xf0,

    /* U+00A2 "¢" */
    0x0, 0x19, 0x0, 0x4f, 0x10, 0x70, 0x50, 0x88,
    0x28, 0x6a, 0x80, 0x8, 0x31, 0x40, 0x6, 0x8,
    0x11, 0xb, 0x0, 0x3c, 0x44, 0x0,

    /* U+00A3 "£" */
    0x8, 0x84, 0x89, 0x7c, 0x40, 0xb, 0x80, 0x44,
    0x6d, 0x4e, 0x7, 0x7e, 0xe0, 0xd, 0x40, 0x2,
    0x2c, 0xc1, 0x80,

    /* U+00A4 "¤" */
    0x10, 0x8, 0x42, 0xe2, 0x9c, 0xe, 0x24, 0x4,
    0x40, 0xe6, 0x42, 0xe6, 0x60,

    /* U+00A5 "¥" */
    0x65, 0x0, 0xa4, 0x9b, 0xc4, 0x13, 0x88, 0x2e,
    0x3, 0x9c, 0x0, 0x66, 0xb2, 0x10, 0xb, 0x5b,
    0xc0, 0x22, 0x76, 0x71, 0x0, 0xfc,

    /* U+00A6 "¦" */
    0x16, 0x31, 0x0, 0xc4, 0xe2, 0xc6, 0x20, 0x18,

    /* U+00A7 "§" */
    0x2a, 0x99, 0x2, 0xcc, 0xc0, 0xbf, 0xe, 0x3,
    0x50, 0x4a, 0x7d, 0x18, 0x0, 0x88, 0x66, 0x89,
    0x80, 0xf8, 0xdc, 0xe3, 0x80,

    /* U+00A8 "¨" */
    0x52, 0x80,

    /* U+00A9 "©" */
    0x0, 0x22, 0xac, 0x1, 0x38, 0x66, 0xd, 0xc5,
    0x55, 0xf1, 0x26, 0xec, 0x66, 0x11, 0x2, 0x80,
    0x98, 0x8, 0x81, 0x40, 0xa, 0xd1, 0x32, 0x6,
    0x70, 0x77, 0x6e, 0x3, 0x8,

    /* U+00AA "ª" */
    0x15, 0x71, 0x2, 0x19, 0x65, 0x71, 0x6a, 0x4f,

    /* U+00AB "«" */
    0x0, 0xf9, 0x58, 0xe0, 0x18, 0x16, 0xe0, 0x18,
    0xd7, 0x5c, 0x0, 0xce, 0xac, 0x0,

    /* U+00AC "¬" */
    0x29, 0x9a, 0xc4, 0xa6, 0x6c, 0x30, 0xc, 0xa4,

    /* U+00AD "­" */
    0x39, 0x9c, 0x0,

    /* U+00AE "®" */
    0x0, 0x22, 0xac, 0x1, 0x39, 0x14, 0x2e, 0x2a,
    0xa0, 0x57, 0xc7, 0x63, 0x20, 0xa9, 0xc0, 0x13,
    0x20, 0xab, 0x20, 0x2, 0xa8, 0x8a, 0x56, 0x70,
    0x70, 0x55, 0x33, 0x4,

    /* U+00AF "¯" */
    0x37, 0x71, 0x80,

    /* U+00B0 "°" */
    0x26, 0x1, 0x0, 0x0,

    /* U+00B1 "±" */
    0x0, 0x50, 0x14, 0x3c, 0x14, 0x3c, 0x0, 0x2c,
    0xa, 0x26, 0x0,

    /* U+00B2 "²" */
    0x37, 0x83, 0x33, 0xe3, 0xb, 0x82, 0xcf, 0x99,
    0x80,

    /* U+00B3 "³" */
    0x36, 0x73, 0x31, 0x69, 0xa, 0x53, 0xa3, 0xc2,
    0x0,

    /* U+00B4 "´" */
    0x36, 0x36,

    /* U+00B5 "µ" */
    0x38, 0x0, 0x32, 0x0, 0x7f, 0xf0, 0x44, 0x1,
    0xe0, 0x5, 0x88, 0x79, 0x5, 0xc4, 0x19, 0x80,
    0x1e,

    /* U+00B6 "¶" */
    0x8, 0x86, 0x61, 0x1e, 0xa5, 0x15, 0x38, 0x80,
    0x37, 0xa8, 0x6, 0x63, 0x84, 0x20, 0x3, 0x42,
    0x10, 0x7, 0xf0, 0xe6, 0x0,

    /* U+00B7 "·" */
    0x53, 0x53,

    /* U+00B8 "¸" */
    0x0, 0xc4, 0xa6, 0xac,

    /* U+00B9 "¹" */
    0x48, 0x4, 0xf0, 0xc, 0x78, 0x60,

    /* U+00BA "º" */
    0x7, 0x71, 0x83, 0x2b, 0xd0, 0x7, 0x99, 0x62,
    0x80,

    /* U+00BB "»" */
    0x0, 0xf1, 0x41, 0x41, 0x1, 0x44, 0xc5, 0x90,
    0xc4, 0x5a, 0x41, 0x7, 0x8, 0x0,

    /* U+00BC "¼" */
    0x48, 0x0, 0x90, 0x81, 0x3c, 0x0, 0x45, 0x0,
    0x72, 0xb0, 0x0, 0xfc, 0xdd, 0xc0, 0xc2, 0x70,
    0xac, 0xa, 0x60, 0x5, 0x41, 0x63, 0xc4, 0x20,
    0x20, 0x66, 0x62, 0x12, 0x80, 0x65, 0x10,

    /* U+00BD "½" */
    0x2, 0x0, 0xf2, 0x50, 0x4, 0xc4, 0x9, 0xe0,
    0x4, 0x22, 0x0, 0x62, 0x14, 0x0, 0x1f, 0xa2,
    0x4c, 0xe6, 0x68, 0x36, 0x16, 0x62, 0x3, 0xb0,
    0x1, 0x89, 0xcd, 0x44, 0xf, 0x95, 0x0,

    /* U+00BE "¾" */
    0x25, 0x61, 0x0, 0x8c, 0x8, 0x78, 0xc0, 0xe,
    0x40, 0x29, 0x8, 0xc, 0xc1, 0x5, 0x67, 0x72,
    0x20, 0x50, 0xd1, 0x9c, 0x9c, 0x91, 0xdc, 0x0,
    0x36, 0x34, 0x3b, 0xc0, 0x15, 0x50, 0x23, 0xde,
    0x0, 0xb0, 0x6, 0x34,

    /* U+00BF "¿" */
    0x0, 0x31, 0x0, 0x4c, 0x40, 0x14, 0x8, 0x1,
    0xf8, 0x42, 0x11, 0x80, 0x2, 0x60, 0x43, 0x75,
    0x14, 0x20,

    /* U+00C0 "À" */
    0x0, 0x11, 0x80, 0x71, 0x8, 0x7, 0x17, 0x80,
    0x75, 0x51, 0x40, 0x30, 0xbf, 0x80, 0x4d, 0x41,
    0xa4, 0x0, 0xdb, 0x8f, 0xb0, 0x3c, 0x88, 0x8c,
    0x25, 0x80, 0x2f, 0x60,

    /* U+00C1 "Á" */
    0x0, 0x8c, 0x40, 0x38, 0x44, 0x1, 0x8b, 0xc0,
    0x3a, 0xa8, 0xa0, 0x18, 0x5f, 0xc0, 0x26, 0xa0,
    0xd2, 0x0, 0x6d, 0xc7, 0xd8, 0x1e, 0x44, 0x46,
    0x12, 0xc0, 0x17, 0xb0,

    /* U+00C2 "Â" */
    0x0, 0x13, 0x0, 0x79, 0x84, 0x3, 0xb4, 0x40,
    0x35, 0x51, 0x40, 0x30, 0xbf, 0x80, 0x4d, 0x41,
    0xa4, 0x0, 0xdb, 0x8f, 0xb0, 0x3c, 0x88, 0x8c,
    0x25, 0x80, 0x2f, 0x60,

    /* U+00C3 "Ã" */
    0x0, 0x31, 0x20, 0x4, 0x2a, 0xe2, 0x1, 0x8,
    0xa1, 0x40, 0x35, 0x51, 0x40, 0x30, 0xbf, 0x80,
    0x4d, 0x41, 0xa4, 0x0, 0xdb, 0x8f, 0xb0, 0x3c,
    0x88, 0x8c, 0x25, 0x80, 0x2f, 0x60,

    /* U+00C4 "Ä" */
    0x0, 0x41, 0x28, 0x6, 0x82, 0x50, 0xc, 0x5a,
    0x1, 0xd5, 0x45, 0x0, 0xc2, 0xfe, 0x1, 0x35,
    0x6, 0x90, 0x3, 0x6e, 0x3e, 0xc0, 0xf2, 0x22,
    0x30, 0x96, 0x0, 0xbd, 0x80,

    /* U+00C5 "Å" */
    0x0, 0x12, 0x88, 0x6, 0x10, 0xf, 0xc, 0x8,
    0x6, 0xaa, 0x28, 0x6, 0x17, 0xf0, 0x9, 0xa8,
    0x34, 0x80, 0x1b, 0x71, 0xf6, 0x7, 0x91, 0x11,
    0x84, 0xb0, 0x5, 0xec,

    /* U+00C6 "Æ" */
    0x0, 0xc3, 0xd5, 0x33, 0x8, 0x6, 0x84, 0x99,
    0xc2, 0x1, 0x2e, 0x10, 0x7, 0xc3, 0x8a, 0x13,
    0x32, 0x80, 0x50, 0x72, 0x93, 0x32, 0x80, 0x13,
    0xaa, 0x50, 0x3, 0xde, 0xe0, 0x14, 0xce, 0x10,

    /* U+00C7 "Ç" */
    0x2, 0xaa, 0x9c, 0x1, 0x37, 0x54, 0x12, 0x6f,
    0x10, 0x3, 0x17, 0x30, 0x7, 0x6b, 0x80, 0x72,
    0xf0, 0x80, 0x15, 0x2, 0xae, 0xd4, 0x48, 0x3,
    0x54, 0xc7, 0x0, 0x89, 0xc8, 0x0,

    /* U+00C8 "È" */
    0x0, 0x11, 0x80, 0x62, 0x10, 0x0, 0xec, 0xdc,
    0xa8, 0x24, 0xcc, 0xa0, 0x1f, 0x24, 0xcc, 0x0,
    0x49, 0x98, 0x3, 0xf2, 0x4c, 0xcc,

    /* U+00C9 "É" */
    0x0, 0x8c, 0x40, 0x30, 0x88, 0x7, 0x66, 0xe5,
    0x41, 0x26, 0x65, 0x0, 0xf9, 0x26, 0x60, 0x2,
    0x4c, 0xc0, 0x1f, 0x92, 0x66, 0x60,

    /* U+00CA "Ê" */
    0x0, 0x13, 0x0, 0x73, 0x8, 0xe, 0xdc, 0xc2,
    0x82, 0x4c, 0xca, 0x1, 0xf2, 0x4c, 0xc0, 0x4,
    0x99, 0x80, 0x3f, 0x24, 0xcc, 0xc0,

    /* U+00CB "Ë" */
    0x0, 0x41, 0x28, 0x5, 0x4, 0xa0, 0x3b, 0x33,
    0x28, 0x24, 0xcc, 0xa0, 0x1f, 0x24, 0xcc, 0x0,
    0x49, 0x98, 0x3, 0xf2, 0x4c, 0xcc,

    /* U+00CC "Ì" */
    0x31, 0x33, 0xd, 0x80, 0x7f, 0xf0, 0x0,

    /* U+00CD "Í" */
    0x4, 0x0, 0x30, 0xd, 0x80, 0x7f, 0xf1, 0xc0,

    /* U+00CE "Î" */
    0x35, 0x1, 0x51, 0x39, 0x10, 0xf, 0xfe, 0x30,

    /* U+00CF "Ï" */
    0x84, 0x38, 0x43, 0x19, 0x0, 0xff, 0xe3, 0x80,

    /* U+00D0 "Ð" */
    0xd, 0x99, 0x52, 0x80, 0x1e, 0x65, 0x58, 0x60,
    0x1d, 0x14, 0xcb, 0x4, 0x2, 0x4c, 0xb0, 0x40,
    0x24, 0x1, 0xd7, 0x40, 0xf3, 0x2a, 0xf3,

    /* U+00D1 "Ñ" */
    0x0, 0x1a, 0x82, 0x0, 0x4e, 0x8e, 0xa0, 0x3a,
    0x82, 0xe3, 0x60, 0x34, 0x1, 0xcb, 0x8e, 0x1,
    0xcd, 0xc8, 0x1, 0xd3, 0xe4, 0x1, 0xd5, 0x20,
    0x1c, 0x30, 0xe0,

    /* U+00D2 "Ò" */
    0x0, 0x94, 0x3, 0xe7, 0x0, 0xe1, 0x98, 0xa6,
    0x0, 0xaa, 0x2a, 0x80, 0xc0, 0xdc, 0x20, 0x6,
    0xd0, 0xe7, 0x0, 0xc2, 0x1c, 0xe0, 0x18, 0x41,
    0xb8, 0x40, 0xd, 0xa0, 0xa, 0xba, 0xa0, 0x30,
    0x0,

    /* U+00D3 "Ó" */
    0x0, 0xc8, 0x1, 0xe1, 0x40, 0xc, 0x33, 0x74,
    0xc0, 0x15, 0x45, 0x50, 0x18, 0x1b, 0x84, 0x0,
    0xda, 0x1c, 0xe0, 0x18, 0x43, 0x9c, 0x3, 0x8,
    0x37, 0x8, 0x1, 0xb4, 0x1, 0x57, 0x54, 0x6,
    0x0,

    /* U+00D4 "Ô" */
    0x0, 0x94, 0xc0, 0x38, 0x54, 0x40, 0x30, 0xc5,
    0x43, 0x0, 0x55, 0x15, 0x40, 0x60, 0x6e, 0x10,
    0x3, 0x68, 0x73, 0x80, 0x61, 0xe, 0x70, 0xc,
    0x20, 0xdc, 0x20, 0x6, 0xd0, 0x5, 0x5d, 0x50,
    0x18, 0x0,

    /* U+00D5 "Õ" */
    0x0, 0x23, 0x30, 0x40, 0x32, 0x33, 0x4, 0x2,
    0x19, 0xaa, 0x30, 0x5, 0x51, 0x54, 0x6, 0x6,
    0xe1, 0x0, 0x36, 0x87, 0x38, 0x6, 0x10, 0xe7,
    0x0, 0xc2, 0xd, 0xc2, 0x0, 0x6d, 0x0, 0x55,
    0xd5, 0x1, 0x80,

    /* U+00D6 "Ö" */
    0x0, 0x1a, 0x40, 0x7, 0x1a, 0x40, 0x6, 0x19,
    0xaa, 0x30, 0x5, 0x51, 0x54, 0x6, 0x6, 0xe1,
    0x0, 0x36, 0x87, 0x38, 0x6, 0x10, 0xe7, 0x0,
    0xc2, 0xd, 0xc2, 0x0, 0x6d, 0x0, 0x55, 0xd5,
    0x1, 0x80,

    /* U+00D7 "×" */
    0x0, 0xc3, 0x49, 0x3, 0x95, 0x5, 0xd9, 0x0,

    /* U+00D8 "Ø" */
    0x1, 0x9a, 0xa7, 0x90, 0x2, 0xa2, 0xb8, 0x50,
    0x1b, 0x84, 0x3f, 0xb4, 0x39, 0xc2, 0x64, 0x2,
    0x1c, 0xe9, 0xc4, 0x2, 0xd, 0x30, 0xe0, 0xda,
    0x0, 0x70, 0xaa, 0x3, 0x0,

    /* U+00D9 "Ù" */
    0x0, 0x94, 0x3, 0xc8, 0x1, 0x1b, 0x80, 0x80,
    0x2c, 0x3, 0xff, 0x92, 0x5c, 0x1, 0x8, 0xc6,
    0x20, 0x6, 0xe0, 0xbb, 0x55, 0x1, 0x0,

    /* U+00DA "Ú" */
    0x0, 0xc8, 0x1, 0xc2, 0x80, 0x3, 0x70, 0x10,
    0x5, 0x80, 0x7f, 0xf2, 0x4b, 0x80, 0x21, 0x18,
    0xc4, 0x0, 0xdc, 0x17, 0x6a, 0xa0, 0x20,

    /* U+00DB "Û" */
    0x0, 0x94, 0xc0, 0x30, 0xa8, 0x80, 0xd, 0xc4,
    0x8, 0x2c, 0x3, 0xff, 0x92, 0x5c, 0x1, 0x8,
    0xc6, 0x20, 0x6, 0xe0, 0xbb, 0x55, 0x1, 0x0,

    /* U+00DC "Ü" */
    0x0, 0x1a, 0x40, 0x6, 0x34, 0x80, 0x1, 0xb8,
    0x6, 0xb0, 0xf, 0xfe, 0x49, 0x70, 0x4, 0x23,
    0x18, 0x80, 0x1b, 0x82, 0xed, 0x54, 0x4,

    /* U+00DD "Ý" */
    0x0, 0x90, 0x3, 0xcc, 0x1, 0x41, 0x81, 0x5,
    0xc, 0x40, 0x0, 0xb8, 0x21, 0xee, 0x1e, 0xc0,
    0x4, 0xea, 0x80, 0xd, 0x60, 0x40, 0x18, 0xcc,
    0x1, 0xfe,

    /* U+00DE "Þ" */
    0x19, 0x0, 0xe4, 0x99, 0x40, 0x1, 0x26, 0x58,
    0xe0, 0x19, 0x30, 0x3, 0x26, 0x2, 0x4c, 0xb1,
    0xc1, 0x26, 0x50, 0x0,

    /* U+00DF "ß" */
    0x7, 0x9a, 0x10, 0x2f, 0x98, 0x90, 0x6e, 0x1,
    0xe0, 0x9, 0x3d, 0x0, 0x24, 0xc9, 0x0, 0xe1,
    0x0, 0x96, 0x7c, 0x0,

    /* U+00E0 "à" */
    0x0, 0x48, 0x6, 0x90, 0x0, 0xcc, 0x51, 0xc,
    0xc5, 0xc0, 0xbb, 0x38, 0xc3, 0x34, 0x15, 0x2c,
    0xc0,

    /* U+00E1 "á" */
    0x0, 0x22, 0x80, 0x48, 0xa0, 0x33, 0x14, 0x43,
    0x31, 0x70, 0x2e, 0xce, 0x30, 0xcd, 0x5, 0x4b,
    0x30, 0x0,

    /* U+00E2 "â" */
    0x3, 0x96, 0x0, 0x1c, 0xb0, 0xc, 0xc5, 0x10,
    0xcc, 0x5c, 0xb, 0xb3, 0x8c, 0x33, 0x41, 0x52,
    0xcc, 0x0,

    /* U+00E3 "ã" */
    0x6, 0x68, 0x0, 0xcd, 0x0, 0xcc, 0x51, 0xc,
    0xc5, 0xc0, 0xbb, 0x38, 0xc3, 0x34, 0x15, 0x2c,
    0xc0,

    /* U+00E4 "ä" */
    0x5, 0x28, 0x0, 0x29, 0x40, 0xc, 0xc5, 0x10,
    0xcc, 0x5c, 0xb, 0xb3, 0x8c, 0x33, 0x41, 0x52,
    0xcc, 0x0,

    /* U+00E5 "å" */
    0x1, 0x64, 0x0, 0x9, 0xb0, 0xc, 0xec, 0x10,
    0xcc, 0x5c, 0xb, 0xb3, 0x8c, 0x33, 0x41, 0x52,
    0xcc, 0x0,

    /* U+00E6 "æ" */
    0x18, 0x79, 0x38, 0x84, 0x88, 0xc, 0x3c, 0x7c,
    0x42, 0x6c, 0x5, 0x9a, 0x76, 0x68, 0xc2, 0x1d,
    0x98, 0xec, 0xd5, 0x85, 0x43, 0xb7, 0xcc, 0x40,
    0x0,

    /* U+00E7 "ç" */
    0x8, 0x99, 0x38, 0x37, 0x4c, 0x90, 0x3d, 0x0,
    0x6, 0x18, 0x80, 0x3, 0x5, 0x19, 0xa4, 0x0,
    0x3c, 0xeb, 0x80, 0x5, 0x84, 0x0,

    /* U+00E8 "è" */
    0x0, 0x40, 0x80, 0x68, 0x10, 0x9, 0xe2, 0xc,
    0xa, 0x31, 0x0, 0x4c, 0xe7, 0x70, 0x96, 0x73,
    0xb9, 0x59, 0x46, 0x20, 0xa0,

    /* U+00E9 "é" */
    0x0, 0xa4, 0x3, 0xa4, 0x2, 0x78, 0x83, 0x2,
    0x8c, 0x40, 0x13, 0x39, 0xdc, 0x25, 0x9c, 0xee,
    0x56, 0x51, 0x88, 0x28, 0x0,

    /* U+00EA "ê" */
    0x0, 0x44, 0x0, 0x34, 0x40, 0x2, 0x78, 0x83,
    0x2, 0x8c, 0x40, 0x13, 0x39, 0xdc, 0x25, 0x9c,
    0xee, 0x56, 0x51, 0x88, 0x28, 0x0,

    /* U+00EB "ë" */
    0x0, 0x3c, 0x0, 0x67, 0x80, 0x9, 0xe2, 0xc,
    0xa, 0x31, 0x0, 0x4c, 0xe7, 0x70, 0x96, 0x73,
    0xb9, 0x59, 0x46, 0x20, 0xa0,

    /* U+00EC "ì" */
    0x63, 0x63, 0x47, 0x0, 0xfc,

    /* U+00ED "í" */
    0x9, 0x0, 0x48, 0x23, 0x80, 0x7f, 0xf0, 0x40,

    /* U+00EE "î" */
    0x8, 0x80, 0x84, 0x40, 0x41, 0x1c, 0x3, 0xff,
    0x8a,

    /* U+00EF "ï" */
    0x86, 0x18, 0x61, 0x47, 0x0, 0xff, 0xe0, 0x80,

    /* U+00F0 "ð" */
    0x0, 0x2d, 0xa8, 0x4, 0xdf, 0xa0, 0x4, 0xac,
    0x13, 0x36, 0xcc, 0xa, 0x5d, 0x80, 0x15, 0xfa,
    0x80, 0x5, 0xc5, 0x1a, 0x91, 0x40,

    /* U+00F1 "ñ" */
    0x4, 0x66, 0x18, 0x1, 0x19, 0x86, 0x9, 0x11,
    0x48, 0x0, 0xe2, 0x6, 0x21, 0x80, 0x2, 0x0,
    0xf1, 0x80, 0x78,

    /* U+00F2 "ò" */
    0x0, 0x40, 0x80, 0x68, 0x10, 0x9, 0xe6, 0x4e,
    0xa, 0x33, 0x20, 0x4d, 0x40, 0x2, 0xe6, 0xa0,
    0x1, 0x71, 0x46, 0x64, 0x8,

    /* U+00F3 "ó" */
    0x0, 0xa4, 0x3, 0xa4, 0x2, 0x79, 0x93, 0x82,
    0x8c, 0xc8, 0x13, 0x50, 0x0, 0xb9, 0xa8, 0x0,
    0x5c, 0x51, 0x99, 0x2, 0x0,

    /* U+00F4 "ô" */
    0x0, 0x44, 0x0, 0x34, 0x40, 0x2, 0x79, 0x93,
    0x82, 0x8c, 0xc8, 0x13, 0x50, 0x0, 0xb9, 0xa8,
    0x0, 0x5c, 0x51, 0x99, 0x2, 0x0,

    /* U+00F5 "õ" */
    0x4, 0x66, 0x18, 0x1, 0x19, 0x86, 0x0, 0x79,
    0x93, 0x82, 0x8c, 0xc8, 0x13, 0x50, 0x0, 0xb9,
    0xa8, 0x0, 0x5c, 0x51, 0x99, 0x2, 0x0,

    /* U+00F6 "ö" */
    0x0, 0x3c, 0x0, 0x67, 0x80, 0x9, 0xe6, 0x4e,
    0xa, 0x33, 0x20, 0x4d, 0x40, 0x2, 0xe6, 0xa0,
    0x1, 0x71, 0x46, 0x64, 0x8,

    /* U+00F7 "÷" */
    0x0, 0x40, 0x0, 0xa0, 0x21, 0x4a, 0x22, 0x50,
    0x4, 0x0, 0x0,

    /* U+00F8 "ø" */
    0x7, 0x99, 0x78, 0x28, 0xcf, 0x32, 0x6a, 0x20,
    0xef, 0x36, 0x8d, 0x17, 0x15, 0xfa, 0x41, 0x0,

    /* U+00F9 "ù" */
    0x0, 0x40, 0x80, 0x68, 0x10, 0x2, 0x30, 0x2,
    0x8, 0x3, 0xff, 0x80, 0xe2, 0x0, 0x40, 0x3d,
    0x98, 0xa6,

    /* U+00FA "ú" */
    0x0, 0xc, 0x0, 0x61, 0x80, 0x2, 0x30, 0x2,
    0x8, 0x3, 0xff, 0x80, 0xe2, 0x0, 0x40, 0x3d,
    0x98, 0xa6,

    /* U+00FB "û" */
    0x1, 0x88, 0x0, 0x43, 0x10, 0x0, 0x23, 0x0,
    0x20, 0x80, 0x3f, 0xf8, 0xe, 0x20, 0x4, 0x3,
    0xd9, 0x8a, 0x60,

    /* U+00FC "ü" */
    0x1, 0x68, 0x0, 0x85, 0xa0, 0x0, 0x8c, 0x0,
    0x82, 0x0, 0xff, 0xe0, 0x38, 0x80, 0x10, 0xf,
    0x66, 0x29, 0x80,

    /* U+00FD "ý" */
    0x0, 0x13, 0x80, 0x62, 0x70, 0x4, 0x88, 0x2,
    0x42, 0xe4, 0x4, 0x40, 0x44, 0x6, 0xa0, 0x4,
    0xbf, 0x10, 0x0, 0xf3, 0x40, 0x39, 0x0, 0x2a,
    0xe0, 0x8,

    /* U+00FE "þ" */
    0x47, 0x0, 0xff, 0xb6, 0x65, 0x0, 0x3, 0x99,
    0x73, 0x7, 0x0, 0x1f, 0xc3, 0x80, 0xf, 0x80,
    0x73, 0x21, 0x50, 0xd9, 0x93, 0x80, 0x7c,

    /* U+00FF "ÿ" */
    0x3, 0x48, 0x0, 0x8d, 0x20, 0x1, 0x22, 0x0,
    0x90, 0xb9, 0x1, 0x10, 0x11, 0x1, 0xa8, 0x1,
    0x2f, 0xc4, 0x0, 0x3c, 0xd0, 0xe, 0x40, 0xa,
    0xb8, 0x2
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 41, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 40, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 47, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 9, .adv_w = 109, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 99, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 60, .adv_w = 114, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 107, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 32, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 111, .adv_w = 43, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 124, .adv_w = 43, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 135, .adv_w = 51, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 138, .adv_w = 66, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 146, .adv_w = 36, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 149, .adv_w = 68, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 152, .adv_w = 30, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 97, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 98, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 68, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 83, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 85, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 238, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 260, .adv_w = 87, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 282, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 304, .adv_w = 86, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 323, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 367, .adv_w = 30, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 33, .box_w = 2, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 377, .adv_w = 81, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 392, .adv_w = 70, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 396, .adv_w = 81, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 411, .adv_w = 76, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 462, .adv_w = 108, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 107, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 110, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 531, .adv_w = 114, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 97, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 585, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 118, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 40, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 631, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 103, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 93, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 671, .adv_w = 140, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 124, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 715, .adv_w = 120, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 743, .adv_w = 100, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 120, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 104, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 812, .adv_w = 97, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 834, .adv_w = 98, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 844, .adv_w = 121, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 861, .adv_w = 109, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 885, .adv_w = 167, .box_w = 11, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 922, .adv_w = 101, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 947, .adv_w = 104, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 968, .adv_w = 101, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 988, .adv_w = 41, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 996, .adv_w = 91, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1013, .adv_w = 41, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1018, .adv_w = 86, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1029, .adv_w = 82, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1032, .adv_w = 36, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1034, .adv_w = 87, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1047, .adv_w = 99, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1066, .adv_w = 88, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1082, .adv_w = 100, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1104, .adv_w = 94, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1120, .adv_w = 53, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1132, .adv_w = 99, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1153, .adv_w = 93, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1169, .adv_w = 35, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1174, .adv_w = 36, .box_w = 4, .box_h = 9, .ofs_x = -2, .ofs_y = -2},
    {.bitmap_index = 1187, .adv_w = 85, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1205, .adv_w = 44, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1211, .adv_w = 147, .box_w = 9, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1229, .adv_w = 93, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1242, .adv_w = 95, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1258, .adv_w = 99, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1278, .adv_w = 99, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1298, .adv_w = 56, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1306, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1319, .adv_w = 54, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1329, .adv_w = 95, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1342, .adv_w = 85, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1358, .adv_w = 130, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1379, .adv_w = 81, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1392, .adv_w = 87, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1413, .adv_w = 79, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1426, .adv_w = 41, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1437, .adv_w = 37, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1443, .adv_w = 41, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1452, .adv_w = 82, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1457, .adv_w = 41, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1457, .adv_w = 40, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1463, .adv_w = 90, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1485, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1504, .adv_w = 86, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1517, .adv_w = 108, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1539, .adv_w = 37, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1547, .adv_w = 81, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1568, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 1570, .adv_w = 133, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1599, .adv_w = 69, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1607, .adv_w = 92, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1621, .adv_w = 93, .box_w = 6, .box_h = 3, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1629, .adv_w = 91, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1632, .adv_w = 133, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1660, .adv_w = 63, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 1663, .adv_w = 43, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1667, .adv_w = 75, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1678, .adv_w = 62, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1687, .adv_w = 62, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1696, .adv_w = 36, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1698, .adv_w = 99, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1715, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1736, .adv_w = 30, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1738, .adv_w = 45, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1742, .adv_w = 44, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1748, .adv_w = 72, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1757, .adv_w = 92, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1771, .adv_w = 127, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1802, .adv_w = 129, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1833, .adv_w = 146, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1869, .adv_w = 75, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1887, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1915, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1943, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1971, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2001, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2030, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2058, .adv_w = 154, .box_w = 11, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2090, .adv_w = 110, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2120, .adv_w = 97, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2142, .adv_w = 97, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2164, .adv_w = 97, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2186, .adv_w = 97, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2208, .adv_w = 40, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2215, .adv_w = 40, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2223, .adv_w = 40, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2231, .adv_w = 40, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2239, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2262, .adv_w = 124, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2289, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2322, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2355, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2389, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2424, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2458, .adv_w = 73, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 2466, .adv_w = 120, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2495, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2518, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2541, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2565, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2588, .adv_w = 104, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2614, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2634, .adv_w = 88, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2654, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2671, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2689, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2707, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2724, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2742, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2760, .adv_w = 149, .box_w = 10, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2785, .adv_w = 88, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2807, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2828, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2849, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2871, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2892, .adv_w = 35, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2897, .adv_w = 35, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2905, .adv_w = 35, .box_w = 4, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2914, .adv_w = 35, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2922, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2944, .adv_w = 93, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2963, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2984, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3005, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3027, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3050, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3071, .adv_w = 86, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 3082, .adv_w = 95, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3098, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3116, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3134, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3153, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3172, .adv_w = 87, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 3198, .adv_w = 96, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 3221, .adv_w = 87, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 96, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 1, 0, 2, 3, 4, 0, 5,
    2, 6, 7, 8, 9, 10, 11, 10,
    12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 23, 0, 24, 0,
    0, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 33, 34, 35, 36, 33, 33,
    37, 38, 39, 40, 41, 42, 43, 44,
    45, 46, 47, 48, 49, 50, 0, 0,
    0, 0, 51, 52, 53, 54, 55, 56,
    57, 58, 59, 60, 61, 62, 63, 63,
    64, 52, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 0, 0,
    0, 77, 0, 0, 0, 0, 78, 0,
    0, 0, 0, 79, 0, 11, 0, 0,
    80, 0, 0, 0, 0, 0, 0, 81,
    0, 0, 0, 82, 0, 0, 0, 83,
    26, 26, 26, 26, 26, 26, 30, 28,
    30, 30, 30, 30, 33, 33, 33, 33,
    29, 33, 37, 37, 37, 37, 37, 84,
    37, 43, 43, 43, 43, 47, 85, 86,
    51, 51, 51, 51, 51, 51, 55, 53,
    55, 55, 55, 55, 59, 59, 87, 88,
    89, 63, 64, 64, 64, 64, 64, 90,
    64, 69, 69, 69, 69, 73, 52, 73
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 0, 2, 0, 0, 0, 3,
    2, 4, 5, 6, 7, 8, 9, 8,
    10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 21, 0, 22, 0,
    23, 24, 25, 26, 27, 26, 26, 26,
    27, 26, 26, 28, 26, 26, 26, 26,
    27, 26, 27, 26, 29, 30, 31, 32,
    33, 34, 35, 36, 0, 37, 38, 0,
    0, 0, 39, 40, 41, 42, 41, 43,
    42, 40, 44, 45, 40, 46, 47, 47,
    41, 47, 42, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 0, 0, 38, 0,
    0, 0, 56, 0, 0, 0, 0, 0,
    0, 57, 58, 59, 0, 9, 57, 0,
    60, 0, 0, 0, 0, 0, 0, 61,
    0, 0, 62, 63, 0, 0, 0, 0,
    25, 25, 25, 25, 25, 25, 64, 27,
    26, 26, 26, 26, 26, 26, 26, 26,
    65, 26, 27, 27, 27, 27, 27, 22,
    27, 31, 31, 31, 31, 35, 26, 66,
    39, 39, 39, 67, 39, 39, 39, 41,
    41, 41, 41, 41, 68, 69, 70, 71,
    72, 47, 41, 41, 41, 41, 41, 73,
    41, 50, 50, 50, 50, 54, 40, 54
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 0, 0, -4, 0, -5, 0, -5,
    -6, -2, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -4, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    -15, -3, -13, -1, 0, 0, -1, -12,
    -3, 0, 0, 0, -2, 0, 0, 0,
    -4, -10, 0, 0, -14, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, -3, 0, 3, 3, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, -1,
    -14, 0, 0, 0, 3, 3, 3, 3,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 0, 0, 0,
    0, -9, -1, -8, -8, 3, -11, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, -3,
    2, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, -3, 0,
    0, 0, 0, 0, 0, 0, -2, -3,
    -2, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 4, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -11,
    0, 0, -15, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, -3,
    -4, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -14, 0,
    0, -2, 0, 0, 3, 1, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, -3, -3, -5, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -15, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, -11, -3,
    -12, -12, 0, -13, 0, 0, 0, 0,
    0, -3, 0, -1, 0, 0, 0, 0,
    0, 0, 0, -11, -12, 0, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, -1, -6,
    -1, 0, 0, -6, 0, 0, 0, 0,
    0, 0, -1, 0, 0, -9, 0, -10,
    0, -6, -6, -3, -12, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -2, -3, -2,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -42, -7, -3, -4,
    -4, -15, -6, -3, 0, -1, -5, 0,
    0, 0, 0, -13, 0, -4, -16, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    0, -6, 0, -7, -8, -1, 0, 0,
    0, -4, -6, 0, -4, -2, -2, -1,
    -2, -3, 0, 0, 0, 0, 0, 0,
    0, 0, -17, 0, 0, -6, 0, 0,
    0, 1, -8, 0, 0, -1, 0, 0,
    -3, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, -10, 0, -6, -6, -3, -10, -2,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, 0, 0, -4, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -9, -2, -8, -8, 0, -10,
    0, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, -2, 0, 0, 6, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -9, 0, -4, -4, 0,
    -8, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, 0, -6, -6,
    0, -8, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -8, 0, -6,
    -6, 0, -8, 0, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, -4,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    -3, -2, 0, -4, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, -1,
    0, -3, -3, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -10, -5, -9, -1, 0, 0,
    0, -8, -2, 0, 0, 0, 0, 0,
    -3, 0, 0, -7, 0, 0, -10, 0,
    -2, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, -3,
    0, 0, -9, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, -1, 0, -3, -3, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, -6, -6, 0, -10,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -8, 0, -2, -2, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, -12, 0, -8,
    -8, 0, -12, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, -2, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, -10, -1, 0, 0, -11, 0,
    0, -1, 0, -3, 0, 0, 0, 0,
    0, -3, -3, -2, 0, 0, 0, -5,
    -2, 0, 0, -4, 0, -2, -11, -5,
    -9, -10, 0, -13, 0, -12, 0, -1,
    0, -2, -2, -3, 0, 0, 0, 0,
    -1, -3, -2, -5, -5, 0, -6, 0,
    0, -4, -8, -2, 0, 0, -8, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, -2,
    0, -3, -3, -2, -5, 0, -1, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, -1, -1, 0, -1, -1, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, -1, 0, 0,
    0, 0, -2, -2, -1, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, -2, 0, -4, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, -4,
    0, -4, 0, -4, -4, -5, -7, -2,
    -3, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -1, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -2, -2,
    0, 0, 0, -1, 0, -1, -2, -3,
    -3, 0, -3, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -4, 0,
    -1, 0, 0, 0, 0, -15, -3, -12,
    0, -3, -4, -5, -10, -4, 0, -2,
    0, -2, -2, 0, 0, -3, -10, 0,
    -2, -20, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -10, 0, -5, -5,
    -3, 0, 0, 0, -6, -7, -1, -5,
    -3, -3, -3, -3, -5, 0, 0, 0,
    -5, 0, 0, 0, -4, -18, 0, -2,
    -10, 0, 0, 2, 0, -7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -4, -4,
    0, -5, 0, -1, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, -1,
    0, -1, -1, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -1, -1, -1, 0, 0, 0, 0, -1,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, -1, -1, -1, 0, 0, -1, 0,
    -2, -1, -1, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, -1, 0, 0, 0, 0,
    -2, 0, -2, 0, 0, 0, 0, 0,
    0, 0, -3, 1, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, -5, -2, 0, 0, 0,
    0, 0, -1, -3, -6, -6, 0, -6,
    0, 0, -3, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    2, -4, 0, -5, -16, 0, 0, 0,
    -19, 0, 0, -11, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, -4, 0, 0, 0, -5, 0, 0,
    -18, -5, -16, -16, 0, -18, 0, -17,
    0, 0, 0, -2, -2, -1, 0, 0,
    0, 0, 0, -1, 0, -12, -12, 0,
    -13, 0, 0, -4, -19, -6, 0, -27,
    -19, 0, 2, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    -3, 0, 0, -3, 0, -4, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, -4,
    0, -4, 0, -4, -4, -5, -8, -3,
    -4, 0, -1, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    -2, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -1, 0, -1, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, -14, -1, -11, 0,
    0, 0, 0, -9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -8, 0, 0,
    -16, 0, 0, 0, -2, -2, -3, -3,
    0, 0, 0, -1, 0, -2, -1, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, -13, 0, 0, -1,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, -3, 0, 0, -3, 0, -4,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, -4, 0, -4, 0, -4, -4, -4,
    -8, -3, -4, 0, -1, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, -2, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, -3, -3,
    0, -5, 0, 0, 0, -1, -1, -3,
    -3, 0, -1, -1, -1, -1, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    -1, -1, -1, -1, -1, -1, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, -3,
    -3, -1, -3, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, -1,
    -1, 0, -3, -3, -1, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, 0, -1, 0, 0, 0, 0,
    -11, -10, -13, -10, -11, -9, -11, -13,
    -9, -3, -3, -1, -12, -8, 0, 0,
    -12, -11, 0, -4, -16, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -17,
    0, -18, -18, -4, 0, 0, 0, -14,
    -17, -1, -13, -13, -13, -12, -13, -14,
    0, -4, 0, -14, 0, 0, 0, -13,
    -13, 0, -3, -15, 0, -1, 3, 2,
    -12, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, -4, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, -1, -2, -2, -1, -1, -1, -1,
    -1, -2, -1, -2, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, -5, -1, -1, -2, -1, -1, -1,
    -1, -2, 0, -5, 0, -4, 0, 0,
    0, 0, -12, -6, -13, -6, -4, -4,
    -4, -11, -6, -4, 0, -3, -6, -2,
    0, 0, -8, -9, 0, -4, -13, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, -11, -10, -2, 0, 0,
    0, -7, -9, -2, -6, -2, -2, -2,
    -2, -3, 0, -4, 0, -9, 0, 0,
    0, -6, -13, 0, -4, -8, 0, 0,
    1, 2, -12, 0, -6, 0, -3, 0,
    0, 0, 0, -12, -6, -13, -6, -3,
    -4, -4, -11, -6, -3, 0, -3, -6,
    -2, 0, 0, -8, -10, 0, -4, -13,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -8, 0, -11, -11, -2, 0,
    0, 0, -7, -9, -1, -6, -2, -2,
    -2, -2, -3, 0, -4, 0, -9, 0,
    0, 0, -5, -14, 0, -4, -8, 0,
    0, 1, 3, -12, 0, -2, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 1, 0, -1, 0, -6, -6, -1,
    0, 0, 0, -1, 0, -1, -3, -4,
    -4, 0, -4, 0, 0, -3, 0, -4,
    0, 0, 0, 0, 0, 0, -1, -1,
    0, 0, 0, 3, -5, 0, -6, 0,
    -5, 0, 0, 0, 0, -13, -12, -13,
    -10, -7, -6, -7, -13, -8, -6, 0,
    -4, -9, -5, 0, 0, -11, -13, 0,
    -8, -14, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, 0, -15, -14,
    -5, 0, 0, 0, -11, -15, -3, -10,
    -6, -5, -5, -6, -6, 0, -7, 0,
    -13, 0, 0, 0, -9, -17, -2, -6,
    -14, 0, -2, 0, 2, -15, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -3, -1, 0, 0, 0, -1, 0, -1,
    -2, -3, -3, 0, -3, 0, 0, -2,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, -12, -3,
    -12, -12, 0, -13, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -6, -7, 0, -7, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, -18,
    -1, -9, -9, 0, -14, 0, -8, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, -1, 0, -3, -3, 0, -3,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, -4,
    -4, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, -2, -1, 0, -2, -1,
    -18, -2, -11, -11, -6, -14, -3, -7,
    -2, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, -1, 0, -3, -3, -4,
    -3, -2, 0, 0, 0, 0, 0, 0,
    -1, 0, -2, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, -1, 0,
    0, -16, -1, -9, -9, -1, -13, 0,
    -5, 0, 0, 0, -1, -1, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -1,
    0, -1, 0, 0, 0, 0, -2, 0,
    0, 0, 0, -1, -1, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, -1, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, -3, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -2, -1,
    0, -2, -1, -17, -1, -9, -9, -3,
    -17, -2, -6, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, -1, 0,
    -2, -2, -3, -2, -1, 0, 0, 0,
    0, 0, 0, 0, 0, -1, -2, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    6, 0, 0, 5, 1, 0, -6, -4,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -6,
    0, 0, -7, 0, 7, 0, 8, 8,
    9, 7, 4, 6, 2, 0, 0, -3,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, 0, -1, -6, 0,
    0, 0, 4, 0, 6, 9, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -15, -1, -7,
    -7, -1, -12, -1, -5, 0, 0, 0,
    0, 0, 0, 0, 4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, -1, 0, 0, -18, -1,
    -9, -9, -1, -13, -1, -7, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, -1, 0, -2, -2, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -7, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, -12, 0, -3, -3, 0, -6, 0,
    -1, 0, 0, 0, -4, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, -5, -2, 0,
    0, 0, -2, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, -2,
    0, 0, -4, -2, -3, -3, 0, -4,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -3, 0, -3, 0, 0, -3, -2, -5,
    0, -12, -2, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    -1, 0, 0, -18, -1, -9, -9, -1,
    -13, -1, -6, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, -1, 0,
    -2, -2, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, -3, -3, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -2,
    -1, 0, -2, -1, -18, -2, -11, -11,
    -6, -15, -3, -7, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, -1,
    0, -3, -3, -4, -3, -2, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -15, -1, -7,
    0, -1, -12, -1, -5, 0, 0, 0,
    0, 0, 0, 0, 11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, -2, 0, 0,
    -16, -6, -8, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, -7, 0, 0, -12, 0, -12, 0,
    -1, -1, -4, -4, -3, 0, 0, 0,
    0, -3, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -8, 0, 0, 0, -1,
    -9, -1, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, -1, 0, 0, 0, -16,
    -2, -8, -8, -1, -12, 0, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -2, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    -10, -2, -5, -5, 0, -8, 0, -3,
    0, 0, 0, -1, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, -15, -1, -7, -7, 0, -12, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, -3, 0, 0, -11, -2, -7, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -5, 0, 0,
    -12, 0, -13, 0, -2, -2, -4, -6,
    -3, -2, 0, -2, 0, -3, -3, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, 0, 0, -8, -2, 0, -2,
    0, 0, 0, 0, -4, 0, -4, 0,
    0, 0, -2, 0, 0, -12, -2, -7,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    0, -12, 0, -13, 0, -2, -2, -4,
    -6, -3, -2, 0, -2, 0, -3, -3,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, -8, 0, 0,
    -2, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, -12, 0, -2, -2,
    0, -5, 0, 0, 0, -1, 0, -4,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, -4, 0,
    -4, 0, 0, 0, -3, 0, 0, -12,
    -2, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -5, 0, 0, -12, 0, -13, 0, -2,
    -2, -4, -6, -3, -2, 0, -2, 0,
    -3, -3, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 0, 0, 0, 0, -8,
    -2, 0, -2, 0, 0, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -14, -1,
    -4, -4, 0, -7, 0, -2, 0, 0,
    0, -2, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, -1, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -13, 0, -5, -6, 0,
    -9, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, -1, -1, -3, -14, -3, 0,
    0, 0, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, -1, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, -4, 0, -14, 0,
    -9, -9, -4, -13, -2, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, -2, 0, -4, -4, -6, -5, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, -3, -4, -4, -4, -15,
    -5, -10, -9, -1, -12, -2, 0, 0,
    -5, -3, -5, -5, -4, -3, 13, -4,
    -3, -5, -4, -4, -6, -6, -1, -4,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -3, -5, -3, -3, -3,
    -3, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    -4, -3, 0, -5, 0, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -4, 0, 0, -6,
    0, -8, 0, -5, -5, -7, -9, -4,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -1, 0,
    0, -1, -4, -2, -5, -5, -4, -8,
    -1, -3, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, -1, 0, -3,
    -3, -3, -3, -1, 0, 0, 0, 0,
    0, 0, 0, 0, -1, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, -1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, -1, 0, -2, -1, -4, -1, -4,
    -4, -5, -6, -5, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, -2, -1, -2, -2, -1, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -3, -6, -2,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 90,
    .right_class_cnt     = 73,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 4,
    .kern_classes = 1,
    .bitmap_format = 1,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t raleway_10 = {
#else
lv_font_t raleway_10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 11,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if RALEWAY_10*/

