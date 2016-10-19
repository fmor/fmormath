#include "vectorfield.h"

namespace fmormath {

VectorField::VectorField()
{

}

VectorField::~VectorField()
{

}

void VectorField::addVector(const Vector3f &origin, const Vector3f &direction, float length)
{
    m_Vectors.push_back( VectorDesc(origin, direction, length) );
}

}

