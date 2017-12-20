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
    void setScale( const Vector3f& v );

    inline void setTranslation( Real x, Real y, Real z ) { setTranslation( Vector3f(x,y,z) ); }
    inline void setScale(Real x, Real y, Real z) { setScale(Vector3f(x,y,z) ); }




    Vector3f getTranslation() const;
    Vector3f getScale() const;




    Real determinant() const;
    Matrix4x4 inverse() const;
    Matrix4x4 tranpose() const;
    Matrix4x4 inverseTranspose() const;


    // make*** //
    inline Matrix4x4& makeScaleMatrix( Real x, Real y, Real z )         { return makeScaleMatrix( Vector3f(x,y,z) ); }
    inline Matrix4x4& makeTranslationMatrix( Real x, Real y, Real z )   { return makeTranslationMatrix( Vector3f(x,y,z)); }
    inline Matrix4x4& makeRotationMatrix( Real radian, const Vector3f& axis ){ return makeRotationMatrix(Quaternion(radian,axis)); }


    Matrix4x4& makeRotationMatrix( const Quaternion& rotation );
    Matrix4x4& makeScaleMatrix( const Vector3f& scale );
    Matrix4x4& makeTranslationMatrix( const Vector3f& translation );
    Matrix4x4& makeProjOrthoMatrix( uint width, uint height, uint deep );
    Matrix4x4& makeProjOrthoMatrix( Real left, Real right, Real bottom, Real top, Real near, Real far );
    Matrix4x4& makeProj2DMatrix( Real width, Real height );



    void translate( const Vector3f& translation );
    void rotate( const Quaternion& quaternion );


    inline void rotate( Real radian, const Vector3f& axis ) { rotate(Quaternion(radian,axis) ); }
    inline void translate(  Real x, Real y, Real z ) { translate(Vector3f(x,y,z)); }


    static const Matrix4x4 ZERO;
    static const Matrix4x4 IDENTITY;

};

}
