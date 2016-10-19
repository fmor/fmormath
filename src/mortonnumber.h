#pragma once

#include <cmath>

#include "mathtypes.h"


namespace fmormath {

// MORTON_TYPE : 0 -> std::uint16_t , 3 dimensions

#define MORTON_TYPE  0


struct Vector3Neighbour
{
    u16 x;
    u16 y;
    u16 z;


    inline Vector3Neighbour(){}

    inline Vector3Neighbour( u16  _x, u16 _y, u16 _z   ) :
        x( _x ),
        y( _y ),
        z( _z )

    {

    }




};

template< typename T, u32 dimCount >
struct MortonNumberConfig
{
    u32 dimensionCount;
    u32 numberBitCount;
    u32 numberCount;
//    T maxValue;

    inline MortonNumberConfig() :
        dimensionCount( dimCount ),
        numberBitCount( sizeof(T) * 8 ),
        numberCount( std::pow( 2, sizeof(T) * 8 ) )
//        maxValue( numberCount -1)
    {
    }
};






class MortonNumber
{
public:
    MortonNumber();
    ~MortonNumber();

    static void  init();



    static u64 hashIt( const Vector3Neighbour& v3 );
    static u64 hashIt( u16 x, u16 y, u16 z );


//#ifdef _DEBUG_
//    static void _LogTable();
//    static void _test();
//#endif


private:
#if MORTON_TYPE == 0
    static const MortonNumberConfig< u16, 3  > mConfig;
    static u64 _LookupTable[ 65536 ];
#endif




};

}

