#pragma once


#include "mathtypes.h"

#include "vector2f.h"
#include "vector3f.h"
#include "vector4f.h"

#include "matrix2x2.h"
#include "matrix3x3.h"
#include "matrix4x4.h"


namespace fmormath {


enum DataType : uint16_t
{
    DT_NONE,
    DT_REAL,
    DT_BOOLEAN,
    DT_VECTOR2F,
    DT_VECTOR3F,
    DT_VECTOR4F,
    DT_MATRIX2X2,
    DT_MATRIX3X3,
    DT_MATRIX4X4,
    DT_QUATERNION
};

// https://en.wikipedia.org/wiki/C%2B%2B11#Unrestricted_unions

union MathVariantUnion
{
    Real      real;
    bool      boolean;
    Vector2f  vector2f;
    Vector3f  vector3f;
    Vector4f  vector4f;
    Matrix2x2 matrix2x2;
    Matrix3x3 matrix3x3;
    Matrix4x4 matrix4x4;

    Quaternion quaternion;

    inline MathVariantUnion(){}

    inline MathVariantUnion( Real r ) : real(r) {}
    inline MathVariantUnion( bool b ) : boolean(b) {}
    inline MathVariantUnion( const Vector2f& v )  : vector2f(v) {}
    inline MathVariantUnion( const Vector3f& v )  : vector3f(v) {}
    inline MathVariantUnion( const Vector4f& v )  : vector4f(v) {}
    inline MathVariantUnion( const Matrix2x2& m )  : matrix2x2(m) {}
    inline MathVariantUnion( const Matrix3x3& m )  : matrix3x3(m) {}
    inline MathVariantUnion( const Matrix4x4& m )  : matrix4x4(m) {}
    inline MathVariantUnion( const Quaternion& q ) : quaternion(q) {}


    inline MathVariantUnion& operator =( const Vector2f& v ) { new(&vector2f) Vector2f(v); return *this; }
    inline MathVariantUnion& operator =( const Vector3f& v ) { new(&vector3f) Vector3f(v); return *this; }
    inline MathVariantUnion& operator =( const Vector4f& v ) { new(&vector4f) Vector4f(v); return *this; }
    inline MathVariantUnion& operator =( const Matrix2x2& m ) { new(&matrix2x2) Matrix2x2(m); return *this; }
    inline MathVariantUnion& operator =( const Matrix3x3& m ) { new(&matrix3x3) Matrix3x3(m); return *this; }
    inline MathVariantUnion& operator =( const Matrix4x4& m ) { new(&matrix4x4) Matrix4x4(m); return *this; }
    inline MathVariantUnion& operator =( const Quaternion& q) { new(&quaternion) Quaternion(q); return *this; }
};


struct MathVariant
{
    DataType m_Type;
    MathVariantUnion m_Data;


    inline MathVariant() : m_Type( DT_NONE ), m_Data( Real(0) ) {}
    inline MathVariant( Real r ) : m_Type( DT_REAL ), m_Data( r ) {}
    inline MathVariant( bool b ) : m_Type( DT_BOOLEAN ), m_Data(b) {}
    inline MathVariant( const Vector2f& v )  : m_Type( DT_VECTOR2F),  m_Data(v) {}
    inline MathVariant( const Vector3f& v )  : m_Type( DT_VECTOR3F),  m_Data(v) {}
    inline MathVariant( const Vector4f& v )  : m_Type( DT_VECTOR4F),  m_Data(v) {}
    inline MathVariant( const Matrix2x2& m ) : m_Type( DT_MATRIX2X2), m_Data(m) {}
    inline MathVariant( const Matrix3x3& m ) : m_Type( DT_MATRIX3X3), m_Data(m) {}
    inline MathVariant( const Matrix4x4& m ) : m_Type( DT_MATRIX4X4), m_Data(m) {}
    inline MathVariant( const Quaternion& q ): m_Type( DT_QUATERNION), m_Data(q){}

    inline bool isNone() const { return m_Type == DT_NONE; }


    inline bool isReal() const { return m_Type == DT_REAL; }
    inline bool isBoolean() const { return m_Type == DT_BOOLEAN; }

    inline bool isVector()   const { return (m_Type == DT_VECTOR2F) || (m_Type==DT_VECTOR3F) || (m_Type==DT_VECTOR4F); }
    inline bool isVector2f() const { return m_Type == DT_VECTOR2F; }
    inline bool isVector3f() const { return m_Type == DT_VECTOR3F; }
    inline bool isVector4f() const { return m_Type == DT_VECTOR4F; }

    inline bool isMatrix() const { return (m_Type == DT_MATRIX2X2) || (m_Type==DT_MATRIX3X3) || (m_Type==DT_MATRIX4X4); }
    inline bool isMatrix2x2() const { return m_Type == DT_MATRIX2X2; }
    inline bool isMatrix3x3() const { return m_Type == DT_MATRIX3X3; }
    inline bool isMatrix4x4() const { return m_Type == DT_MATRIX4X4; }
    inline bool isQuaternion() const{ return m_Type == DT_QUATERNION; }



    inline MathVariant& operator =( Real r ) { m_Type = DT_REAL; m_Data.real = r; return *this; }
    inline MathVariant& operator =( bool b ) { m_Type = DT_BOOLEAN; m_Data.boolean = b; return *this; }
    inline MathVariant& operator =( const Vector2f& v ) { m_Type = DT_VECTOR2F; m_Data.vector2f = v; return *this; }
    inline MathVariant& operator =( const Vector3f& v ) { m_Type = DT_VECTOR3F; m_Data.vector3f = v; return *this; }
    inline MathVariant& operator =( const Vector4f& v ) { m_Type = DT_VECTOR4F; m_Data.vector4f = v; return *this; }
    inline MathVariant& operator =( const Matrix2x2& m ) { m_Type = DT_MATRIX2X2; m_Data.matrix2x2 = m; return *this; }
    inline MathVariant& operator =( const Matrix3x3& m ) { m_Type = DT_MATRIX3X3; m_Data.matrix3x3 = m; return *this; }
    inline MathVariant& operator =( const Matrix4x4& m ) { m_Type = DT_MATRIX4X4; m_Data.matrix4x4 = m; return *this; }
    inline MathVariant& operator =( const Quaternion& q) { m_Type = DT_QUATERNION; m_Data.quaternion = q; return *this; }



    inline bool operator ==( Real r ) const { return (m_Type == DT_REAL) && (m_Data.real == r); }
    inline bool operator ==( bool b ) const { return (m_Type == DT_BOOLEAN) && (m_Data.boolean == b); }
    inline bool operator ==( const Vector2f& v )   const { return (m_Type == DT_VECTOR2F) && (m_Data.vector2f==v); }
    inline bool operator ==( const Vector3f& v )   const { return (m_Type == DT_VECTOR3F) && (m_Data.vector3f==v); }
    inline bool operator ==( const Vector4f& v )   const { return (m_Type == DT_VECTOR4F) && (m_Data.vector4f==v); }
    inline bool operator ==( const Matrix2x2& m )  const { return (m_Type == DT_MATRIX2X2) && (m_Data.matrix2x2==m); }
    inline bool operator ==( const Matrix3x3& m )  const { return (m_Type == DT_MATRIX3X3) && (m_Data.matrix3x3==m); }
    inline bool operator ==( const Matrix4x4& m )  const { return (m_Type == DT_MATRIX4X4) && (m_Data.matrix4x4==m); }
    inline bool operator ==( const Quaternion& q ) const { return (m_Type == DT_QUATERNION) && (m_Data.quaternion==q); }





    inline Real& asReal() { return m_Data.real; }
    inline bool  asBool() { return m_Data.boolean; }
    inline Vector2f&  asVector2f() { return m_Data.vector2f; }
    inline Vector3f&  asVector3f() { return m_Data.vector3f; }
    inline Vector4f&  asVector4f() { return m_Data.vector4f; }
    inline Matrix2x2& asMatrix2x2() { return m_Data.matrix2x2; }
    inline Matrix3x3& asMatrix3x3() { return m_Data.matrix3x3; }
    inline Matrix4x4& asMatrix4x4() { return m_Data.matrix4x4; }
    inline Quaternion& asQuaternion() { return m_Data.quaternion; }


};


}
