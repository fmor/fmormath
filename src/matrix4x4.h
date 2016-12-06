#pragma once

#include "mathtypes.h"
#include "vector2f.h"
#include "vector3f.h"
#include "vector4f.h"
#include "quaternion.h"

namespace fmormath
{

class Matrix4x4
{
    Real   m_Reals[4][4];

public:



    inline Matrix4x4()
    {}
    Matrix4x4(    Real r00, Real r01, Real r02, Real r03,
                    Real r10, Real r11, Real r12, Real r13,
                    Real r20, Real r21, Real r22, Real r23,
                    Real r30, Real r31, Real r32, Real r33 );

    void set( Real r00, Real r01, Real r02, Real r03,
              Real r10, Real r11, Real r12, Real r13,
              Real r20, Real r21, Real r22, Real r23,
              Real r30, Real r31, Real r32, Real r33 );


    inline const Real* operator []( uint index ) const { return m_Reals[index]; }
    inline Real* operator []( uint index ) { return m_Reals[index]; }

    inline const Real* getPtr() const { return &m_Reals[0][0]; }

    bool operator ==( const Matrix4x4& other ) const;
    bool operator !=( const Matrix4x4& other ) const;
    void operator *=( Real f );
    void operator *=( const Matrix4x4& other );
    void operator +=( const Matrix4x4& other );
    void operator -=( const Matrix4x4& other );


    Matrix4x4 operator *( Real r ) const;
    Vector2f  operator *( const Vector2f& v2 ) const;
    Vector3f  operator *( const Vector3f& v3 ) const;
    Vector4f  operator *( const Vector4f& v4 ) const;
    Matrix4x4 operator *( const Matrix4x4& other ) const;
    Matrix4x4 operator +( const Matrix4x4& other ) const;
    Matrix4x4 operator -( const Matrix4x4& other ) const;


    void setTranslation( const Vector3f& v3 );
    void setOrientation( const Quaternion& q );
    void setScale( const Vector3f& v );

    inline void setTranslation( Real x, Real y, Real z ) { setTranslation( Vector3f(x,y,z) ); }
    inline void setScale(Real x, Real y, Real z) { setScale(Vector3f(x,y,z) ); }



    void decompose( Vector3f& translation, Quaternion& orientation, Vector3f& scale ) const;

    Vector3f getTranslation() const;
    Quaternion getOrientation() const;
    Vector3f getScale() const;




    Real determinant() const;
    Matrix4x4 inverse() const;
    Matrix4x4 tranpose() const;
    Matrix4x4 inverseTranspose() const;



    Matrix4x4& makeRotationMatrix( const Quaternion& rotation );
    Matrix4x4& makeScaleMatrix( const Vector3f& scale );
    Matrix4x4& makeTranslationMatrix( const Vector3f& translation );
    Matrix4x4& makeOrthoMatrix( const Real width, const Real height );




    inline void translate( const Vector3f& v3 ) { translate( v3.x, v3.y, v3.z); }
    void translate( Real x, Real y, Real z );



    void rotate( const Quaternion& quaternion );
    void rotate( Real degrees, const Vector3f& axis );

    static const Matrix4x4 ZERO;
    static const Matrix4x4 IDENTITY;

};

}
