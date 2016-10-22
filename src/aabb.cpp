#include "aabb.h"


namespace fmormath {



static inline Vector3f Min( const Vector3f& v1, const Vector3f& v2 )
{
    Vector3f min;

    min.x =  ( v1.x < v2.x ) ? v1.x : v2.x;
    min.y =  ( v1.y < v2.y ) ? v1.y : v2.y;
    min.z =  ( v1.z < v2.z ) ? v1.z : v2.z;

    return min;
}


static inline Vector3f Max( const Vector3f& v1, const Vector3f& v2 )
{
    Vector3f max;

    if( v1.x > v2.x )
        max.x = v1.x;
    else
        max.x = v2.x;


    if( v1.y > v2.y )
        max.y = v1.y;
    else
        max.y = v2.y;

    if( v1.z > v2.z )
        max.z = v1.z;
    else
        max.z = v2.z;

    return max;
}



AxisAlignedBoundingBox::AxisAlignedBoundingBox() :
    mCenter( Vector3f::ZERO ),
    mMin( Vector3f::ZERO ),
    mMax( Vector3f::ZERO ),
    mWidth( 0 ),
    mHeight( 0 ),
    mDeep( 0 )
{

}

AxisAlignedBoundingBox::AxisAlignedBoundingBox(const Vector3f &min, const Vector3f &max)
{
    set( min, max );

}

AxisAlignedBoundingBox::AxisAlignedBoundingBox(const AxisAlignedBoundingBox& aabb1, const AxisAlignedBoundingBox& aabb2 )
{
        setMin( Min( aabb1.mMin, aabb2.mMin ) ) ;
        setMax( Max( aabb1.mMax, aabb2.mMax ) );
}


AxisAlignedBoundingBox::~AxisAlignedBoundingBox()
{

}

bool AxisAlignedBoundingBox::isInside(const fmormath::Vector3f &position) const
{
    if( (position.x < mMin.x) || (position.x > mMax.x) )
        return false;
    if( (position.y < mMin.y) || (position.y > mMax.y) )
        return false;
    if( (position.z < mMin.z) || (position.z > mMax.z) )
        return false;

    return true;
}

void AxisAlignedBoundingBox::set(const Vector3f& _min, const Vector3f& _max )
{
//#ifdef _DEBUG_
//        assert( _min.x < _max.x );
//        assert( _min.y < _max.y );
//        assert( _min.z < _max.z );
//#endif
    mMin = _min;
    mMax = _max;

    mWidth = mMax.x - mMin.x;
    mHeight= mMax.y - mMin.y;
    mDeep  = mMax.z - mMin.z;


    mCenter  = mMin;
    mCenter += Vector3f( mWidth*0.5f, mHeight*0.5f, mDeep*0.5f );
}

void AxisAlignedBoundingBox::set(const Vector3f &center, float width, float height, float deep)
{
    mCenter = center;

    mWidth = width;
    mHeight = height;
    mDeep = deep;

    mMin = center;
    mMin -= Vector3f( width*0.5f, height*0.5f, deep*0.5f );

    mMax = center;
    mMax += Vector3f( width*0.5f, height*0.5f, deep*0.5f );

}

void AxisAlignedBoundingBox::setMin(const Vector3f &min)
{
    set(  min, mMax );
}

void AxisAlignedBoundingBox::setMax(const Vector3f &max)
{
    set( mMin, max );
}

bool AxisAlignedBoundingBox::isOutside(const Vector3f &point, Vector3f &delta) const
{
    bool b = false;

    if( point.x < mMin.x )
    {
        delta.x = mMin.x - point.x;
        b =true;
    }
    else if( point.x > mMax.x )
    {
        delta.x = mMax.x -point.x;
        b =true;
    }


    if( point.y < mMin.y )
    {
        delta.y = mMin.y - point.y;
        b =true;
    }
    else if( point.y > mMax.y )
    {
        delta.y = mMax.y - point.y;
        b =true;
    }


    if( point.z < mMin.z )
    {
        delta.z = mMin.z - point.z;
        b =true;
    }
    else if( point.z > mMax.z )
    {
        delta.z = mMax.z - point.z;
        b =true;
    }

    return b;


}

void AxisAlignedBoundingBox::add(const AxisAlignedBoundingBox& other )
{
    set( Min(mMin, other.getMin()), Max(mMax, other.getMax()) );
}


void AxisAlignedBoundingBox::scale(const Vector3f &scale)
{
    Vector3f min = mMin;
    Vector3f max = mMax;

    min.scale( scale );
    max.scale( scale );

    set( min, max );

}



float AxisAlignedBoundingBox::getScaleToFitIn( const AxisAlignedBoundingBox& other )
{
    const float scaleX = other.mWidth   / mWidth;
    const float scaleY = other.mHeight  / mHeight;
    const float scaleZ = other.mDeep    / mDeep;


    float scale = scaleX;

    if( scaleY < scale )
        scale = scaleY;

    if( scaleZ < scale )
        scale = scaleZ;

    return scale;
}




}
