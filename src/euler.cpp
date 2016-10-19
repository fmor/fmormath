#include "euler.h"
#include "matrix3x3.h"


namespace fmormath {

Vector3f euler::RotateAroundAxis(const Vector3f& v3, real radian, const Vector3f& _axis )
{
    Matrix3x3 stepRx;
    Matrix3x3 stepRxInv;
    Matrix3x3 stepRy;
    Matrix3x3 stepRyInv;
    Matrix3x3 stepRz;
    Matrix3x3 matRotation;

    Vector3f axis = _axis;
    axis.normalize();

    const float l1 = std::sqrt( axis.y*axis.y + axis.z*axis.z );
    bool bNotColineraToX = l1 != 0;

    if( bNotColineraToX )
    {
        stepRx.set( 1, 0, 0,
                    0, axis.z/l1, -axis.y/l1,
                    0, axis.y/l1, axis.z/l1
                    );
        stepRxInv.set( 1, 0, 0,
                       0, axis.z/l1,  axis.y/l1,
                       0, -axis.y/l1, axis.z/l1
                       );
    }





    stepRy.set(
                l1, 0, -axis.x,
                0, 1, 0,
                axis.x, 0, l1
                );

    stepRyInv.set(
                    l1, 0, axis.x,
                    0, 1, 0,
                    -axis.x, 0, l1
                );







    ///
    stepRz.set( cos(radian), -sin(radian), 0,
                sin(radian), cos(radian), 0,
                0,0,1);





    matRotation = Matrix3x3::IDENTITY;
    if( bNotColineraToX )
        matRotation  *= stepRxInv;

    matRotation *= stepRyInv;
    matRotation *= stepRz;
    matRotation *= stepRy;

    if( bNotColineraToX )
        matRotation *= stepRx;


    Vector3f rotated = matRotation * v3;

    return rotated;
}




}
