#pragma once

#include "vec4.h"
#include "point4.h"

class Ray {
public: 
    Point4 origin;
    Vec4 direction; //direction of ray

    Ray() = default;
    Ray(const Point4& origin, const Vec4& direction);

    bool operator==(const Ray& rhs);
};
