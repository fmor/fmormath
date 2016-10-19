#include "mortonnumber.h"


#include <bitset>
#include <cmath>
#include <cstring>



namespace fmormath {

static bool bIsInitialized = false;


// MORTON_TYPE : 0 -> std::uint16_t , 3 dimensions
#if MORTON_TYPE == 0
const MortonNumberConfig< u16, 3  > MortonNumber::mConfig;
u64 MortonNumber::_LookupTable[ 65536 ] = {};

#else

#endif


MortonNumber::MortonNumber()
{

}

MortonNumber::~MortonNumber()
{

}

std::uint64_t MortonNumber::hashIt(const Vector3Neighbour& v3)
{
    return hashIt( v3.x, v3.y, v3.z );
}

std::uint64_t MortonNumber::hashIt(u_int16_t x, u_int16_t y, u_int16_t z)
{
    std::uint64_t result = _LookupTable[ x ];
    std::uint64_t maskY  = _LookupTable[ y ] << 1;
    std::uint64_t maskZ  = _LookupTable[ z ] << 2;
    result |= maskY;
    result |= maskZ;




//#ifdef _DEBUG_
//    mLogger <<  "MortonNumber::hashIt : std::bitset< 64 >( "<< x << " )         : " << (std::bitset< 64 >) result << LoggerLevel::DEBUG;
//#endif

    return result;

}


void MortonNumber::init()
{


    if( bIsInitialized )
        return;






    std::memset( &_LookupTable[0], 0, sizeof(std::uint64_t) * mConfig.numberCount );






    std::uint64_t mortonNumber = 0;

    for( std::size_t number = 0; number < mConfig.numberCount; ++number )
    {

//        mLogger << "number == " << number << LoggerLevel::DEBUG;

        mortonNumber = 0;


        for( std::uint16_t shift = 0; shift < mConfig.numberBitCount; ++shift )
        {
            std::uint64_t mask = std::uint64_t(1) << shift;
//            mLogger << "mask[" << shift << "] = " << std::bitset< 64 >(mask) << LoggerLevel::DEBUG;
            if( (number & mask) == mask )
            {
                std::size_t dimShift = shift*mConfig.dimensionCount;
                std::uint64_t tmp = std::uint64_t(1) << dimShift;
                mortonNumber = mortonNumber | tmp;

//                mLogger <<
//                                          "mortonNumber = " << (std::bitset< 64 >) mortonNumber << " "
//                                          "tmp[" << dimShift << "] = " << std::bitset< 64 >(tmp)
//                                       << LoggerLevel::DEBUG;
            }
        }


    _LookupTable[ number ] = mortonNumber;

    }


    bIsInitialized = true;



//#ifdef _DEBUG_
//    _test();
//#endif

}

//#ifdef _DEBUG_
//void MortonNumber::_LogTable()
//{


//    mLogger << "MortonNumber : config : \n"
//              "\tmConfig.dimen  sionCount = " << mConfig.dimensionCount << "\n"
////              "\tmConfig.maxValue = " << mConfig.maxValue << "\n"
//              "\tmConfig.numberBitCount = " << mConfig.numberBitCount << "\n"
//              "\tmConfig.numberCount = "<< mConfig.numberCount << "\n"
//           << LoggerLevel::DEBUG;




//    for( std::size_t i = 0 ; i < mConfig.numberCount; ++i )
//    {
//        std::uint16_t n  = i;

//        mLogger << "_LookupTable["<< n << "] : " << (std::bitset<16>) n << " - " << (std::bitset< 64 >) _LookupTable[n] << LoggerLevel::DEBUG;
//    }
//}
//void MortonNumber::_test()
//{
//    _LogTable();



//    std::vector< u_int16_t > dump ;

//    dump = { 1,2,4, 8,16,32,64,128, 256,512, 1024};

//    for( u_int16_t &x : dump )
//    {


//        mLogger <<  "std::bitset< 16 >( "<< x << " )         : " << (std::bitset< 16 >) x << LoggerLevel::DEBUG;
//        mLogger <<  "_LookupTable["<< x << "]                : " << (std::bitset< 64 >) _LookupTable[x] << LoggerLevel::DEBUG;
//    }



//    dump = { 30, 197, 6048 };
//    for( u_int16_t &x : dump )
//    {


//        mLogger <<  "std::bitset< 16 >( "<< x << " )         : " << (std::bitset< 16 >) x << LoggerLevel::DEBUG;
//        mLogger <<  "_LookupTable["<< x << "]                : " << (std::bitset< 64 >) _LookupTable[x] << LoggerLevel::DEBUG;
//    }



//    std::uint64_t t  = hashIt( 65535, 65535, 65535 );

//    mLogger << "hashIt( 0, 0, 0 )                = "  << (std::bitset< 64 >) hashIt( 0, 0, 0 ) << LoggerLevel::DEBUG;
//    mLogger << "hashIt( 65535, 65535, 65535 )    = "  << (std::bitset< 64 >) hashIt( 65535, 65535, 65535 ) << LoggerLevel::DEBUG;



//}
//#endif


}

