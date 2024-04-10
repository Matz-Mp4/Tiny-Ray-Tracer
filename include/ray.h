#pragma once

#include "vector4.h"

class Ray {
public: 
    Point4 origin;
    Vector4 direction; //direction of ray

    Ray() = default;
    Ray(const Point4& origin, const Vector4& direction);

    bool operator==(const Ray& rhs);
};
