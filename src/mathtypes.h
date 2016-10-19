#pragma once

#include <stdint.h>
#include <climits>


namespace fmormath {

typedef float   real;

typedef unsigned int uint;
typedef uint8_t      u8;
typedef uint16_t     u16;
typedef uint32_t     u32;
typedef uint64_t     u64;

typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;


static_assert(sizeof(float)*CHAR_BIT==32,   "float is not 32 bit on this architecture, fix the f32 typedef.");
static_assert(sizeof(double)*CHAR_BIT==64,  "float is not 32 bit on this architecture, fix the f32 typedef.");

typedef float f32;
typedef double f64;



}
