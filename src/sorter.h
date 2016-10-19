#pragma once

#include <algorithm>
#include <vector>

#include "vector3f.h"

//#include <tbb/parallel_sort.h>


namespace fmormath {


namespace vectorsort {

class BaseSort
{
protected:
    const std::vector<Vector3f>* m_Vertices;

public:
    inline BaseSort() :
        m_Vertices( nullptr )
    {}

    void setVector( const std::vector<Vector3f>* vector3Vector );
};

struct XSort : public BaseSort
{
    inline bool operator() ( int i, int j) const
    {
        return (*m_Vertices)[i].x < (*m_Vertices)[j].x;

    }
};

struct YSort : public BaseSort
{
    inline bool operator() ( int i, int j) const
    {
        return (*m_Vertices)[i].y < (*m_Vertices)[j].y;
    }
};
struct ZSort : public BaseSort
{
    inline bool operator() ( int i, int j) const
    {
        return (*m_Vertices)[i].z < (*m_Vertices)[j].z;
    }
};




struct XYZSort
{
    XSort mXSort;
    YSort mYSort;
    ZSort mZSort;

    inline void setVector( const std::vector<Vector3f>* vector3Vector )
    {
        mXSort.setVector( vector3Vector );
        mYSort.setVector( vector3Vector );
        mZSort.setVector( vector3Vector );
    }

    template< typename T >
    inline void sort( T& x, T& y, T& z )
    {
//        tbb::parallel_sort( x.begin(), x.end(), mXSort );
//        tbb::parallel_sort( y.begin(), y.end(), mYSort );
//        tbb::parallel_sort( z.begin(), z.end(), mZSort );

        std::sort( x.begin(), x.end(), mXSort );
        std::sort( y.begin(), y.end(), mYSort );
        std::sort( z.begin(), z.end(), mZSort );
    }


};


}}
