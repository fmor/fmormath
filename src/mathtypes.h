#pragma once

#include <stdint.h>
#include <climits>


namespace fmormath {

#ifdef DEFINE_REAL_AS_DOUBLE
typedef double  Real;
#else
typedef float   Real;
#endif


typedef unsigned int uint;
typedef uint8_t      u8;
typedef uint16_t     u16;
typedef uint32_t     u32;
typedef uint64_t     u64;

typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;
typedef int64_t     s64;


}
