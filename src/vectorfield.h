#pragma once

#include <vector>

#include "vector3f.h"
#include "mathtypes.h"

namespace fmormath {

class VectorField
{
public:
    struct VectorDesc
    {
        Vector3f m_Origin;
        Vector3f m_Direction;
        real    m_length;

        inline VectorDesc( const Vector3f& origin, const Vector3f& direction, real length = 1.0f ) :
            m_Origin( origin ),
            m_Direction( direction ),
            m_length( length )
        {}
    };

private:
    std::vector<VectorDesc> m_Vectors;


public:
    VectorField();
    ~VectorField();


    inline const std::vector<VectorDesc>& getVectors() const { return m_Vectors; }
    inline const VectorDesc& getVector( u32 index ){ return m_Vectors[index]; }

    inline u32 size() const { return m_Vectors.size(); }
    inline void clear() { m_Vectors.clear(); }

    void addVector( const Vector3f& origin, const Vector3f& direction, float length = 1.0f  );

};


}

