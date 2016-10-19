#pragma once

#include "vector3f.h"


namespace fmormath {

class AxisAlignedBoundingBox
{
    Vector3f mCenter;
    Vector3f mMin;
    Vector3f mMax;

    float mWidth;
    float mHeight;
    float mDeep;



public:

    AxisAlignedBoundingBox();
    AxisAlignedBoundingBox( const Vector3f& min, const Vector3f& max );
    AxisAlignedBoundingBox( const AxisAlignedBoundingBox& aabb1, const AxisAlignedBoundingBox& aabb2 );
    ~AxisAlignedBoundingBox();



    inline const Vector3f& getCenter() const { return mCenter; }
    inline const Vector3f& getMin() const { return mMin; }
    inline const Vector3f& getMax() const { return mMax; }


    inline float getWidth() const { return mWidth; }
    inline float getHeight() const { return mHeight; }
    inline float getDeep() const { return mDeep; }




    void set(const Vector3f& _min, const Vector3f& _max );
    void set( const Vector3f& center, float width, float height, float deep );

    void setMin( const Vector3f& min );
    void setMax( const Vector3f& max );





    bool isInside( const Vector3f& position ) const;
    bool isOutside( const Vector3f& point, Vector3f& delta ) const;
    void scale( const Vector3f& scale );



//    AxisAlignedBoundingBox operator *( const ofMatrix4x4& matrix );


    void add( const AxisAlignedBoundingBox& other );



    float getScaleToFitIn( const AxisAlignedBoundingBox& other );




};

}
