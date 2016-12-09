#pragma once

#include "spacemap.h"
#include "vector3f.h"
#include "mathtypes.h"
#include "nanoflann.hpp"

namespace fmormath {





template< typename T>
class SpaceMap3D : public SpaceMap
{

    struct Space
    {
        std::vector<Vector3f> mPositions;

        inline Space() :
            mPositions()
        {
            mPositions.clear();
        }



        inline std::size_t kdtree_get_point_count() const {
            return mPositions.size();
        }

        inline float kdtree_distance(const  float* __restrict__ p1, const size_t idx_p2,size_t size) const
        {
            const float d0=p1[0]-mPositions[idx_p2].x;
            const float d1=p1[1]-mPositions[idx_p2].y;
            const float d2=p1[2]-mPositions[idx_p2].z;
            return d0*d0+d1*d1+d2*d2;
        }


        inline float kdtree_get_pt(const size_t idx, int dim) const
        {
            if (dim==0)
                return mPositions[idx].x;
            if (dim==1)
                return mPositions[idx].y;
            else
                return mPositions[idx].z;
        }




        template <class BBOX>
        bool kdtree_get_bbox(BBOX &bb) const { return false; }

    };


    // Euclidien
    typedef nanoflann::KDTreeSingleIndexAdaptor< nanoflann::L2_Simple_Adaptor< float, Space > , Space, 3  > KDTree3D;

    Space m_Space;
    std::vector<T> m_Datas;
    KDTree3D m_KDTree;

public:

    struct SearchResult
    {
        u32         m_LocatorIndex;
        Vector3f    m_Position;
        float       m_Distance;
        T           m_Data;


        inline SearchResult( u32 index, const Vector3f& position, Real distance, T data ) :
            m_LocatorIndex( index ),
            m_Position( position ),
            m_Distance( distance ),
            m_Data( data )
        {}
    };



    SpaceMap3D() :
        m_Space(),
        m_Datas(),
        m_KDTree( 3 , m_Space )
    {

    }

    ~SpaceMap3D()
    {
        if( m_Datas.empty() == false )
        {
            clear();
        }
    }

    void addPosition(  const Vector3f& position, const T data )
    {
        m_Space.mPositions.push_back( position );
        m_Datas.push_back(  data );
    }

    void buildIndex()
    {
        m_KDTree.buildIndex();
    }

    void clear()
    {
        m_KDTree.freeIndex();
        m_Datas.clear();
        m_Space.mPositions.clear();
    }


    inline bool empty() const { return m_Datas.empty(); }


    u32 findClosest( const Vector3f& postion, std::vector<SearchResult>& result, const u32 maxResult ) const
    {

        //    nanoflann::KNNResultSet< KDTree3D::DistanceType, KDTree3D::IndexType> resultSet(num_closest);
        //    resultSet.init(out_indices, out_distances_sq);
        //    m_KDTree.findNeighbors(resultSet, query_point, nanoflann::SearchParams());

        if( empty() )
        {
            return 0;
        }


        Real distances[ maxResult ];
        std::size_t indices[ maxResult ];

        for( u32 i =0; i < maxResult; ++i )
        {
            distances[i] = -1.0f;
        }


        m_KDTree.knnSearch( &(postion.x) , maxResult, indices, distances  );

        s32 cnt = 0;

        for( s32 i = 0; i < maxResult; ++i )
        {
            if( distances[i] !=  -1.0f )
            {
                u32 index = indices[i];
                result.push_back( SearchResult(index, m_Space.mPositions[index], distances[i], m_Datas[index]) );
                ++cnt;
            }
            else
            {
                // no more result
                break;
            }
        }
        return cnt;
    }



};

} // namespace lightengine



///** Manhattan distance functor (generic version, optimized for high-dimensionality data sets).
//  *  Corresponding distance traits: nanoflann::metric_L1
//  * \tparam T Type of the elements (e.g. double, float, uint8_t)
//  * \tparam DistanceType Type of distance variables (must be signed) (e.g. float, double, int64_t)
//  */
//template<class T, class DataSource, typename _DistanceType = T>
//struct L1_Adaptor

//typedef nanoflann::KDTreeSingleIndexAdaptor< nanoflann::L1_Adaptor

