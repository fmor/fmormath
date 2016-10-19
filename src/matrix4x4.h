#pragma once

#include "mathtypes.h"
#include "vector3f.h"
#include "vector4f.h"
#include "quaternion.h"

namespace fmormath
{

class Matrix4x4
{
    float   m_Reals[4][4];

public:



    inline Matrix4x4()
    {}
    Matrix4x4(    float r00, float r01, float r02, float r03,
                    float r10, float r11, float r12, float r13,
                    float r20, float r21, float r22, float r23,
                    float r30, float r31, float r32, float r33 );

    void set( float r00, float r01, float r02, float r03,
              float r10, float r11, float r12, float r13,
              float r20, float r21, float r22, float r23,
              float r30, float r31, float r32, float r33 );


    inline const float* operator []( uint index ) const { return m_Reals[index]; }
    inline float* operator []( uint index ) { return m_Reals[index]; }

    inline const real* getPtr() const { return &m_Reals[0][0]; }

    bool operator ==( const Matrix4x4& other ) const;
    bool operator !=( const Matrix4x4& other ) const;
    void operator *=( float f );
    void operator *=( const Matrix4x4& other );
    void operator +=( const Matrix4x4& other );
    void operator -=( const Matrix4x4& other );

    Vector3f    operator *( const Vector3f& v3 ) const;
    Vector4f    operator *( const Vector4f& v4 ) const;
    Matrix4x4 operator *( const Matrix4x4& other ) const;


    inline void setTranslation( const Vector3f& v3 ) { setTranslation(v3.x,v3.y,v3.z); }
    void setTranslation( float x, float y, float z );


    void decompose( Vector3f& translation, Quaternion& orientation, Vector3f& scale ) const;
    Vector3f translation() const;




    float determinant() const;
    Matrix4x4 inverse() const;
    Matrix4x4 tranpose() const;
    Matrix4x4 inverseTranspose() const;



    void makeRotationMatrix( float degree, const Vector3f& axis );
    void makeScaleMatrix( const Vector3f& scale );
    void makeTranslationMatrix( const Vector3f& translation );




    inline void translate( const Vector3f& v3 ) { translate( v3.x, v3.y, v3.z); }
    void translate( float x, float y, float z );



    void rotate( const Quaternion& quaternion );
    void rotate( float degrees, const Vector3f& axis );

    static const Matrix4x4 ZERO;
    static const Matrix4x4 IDENTITY;

};

}
