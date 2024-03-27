#pragma once

#include "../math/vector4.h"

class Ray {
public: 
    Point4 origin;
    Vector4 dir; //direction of ray

    Ray() = default;
    Ray(const Point4& origin, const Vector4& dir);
    Ray(const Ray& ray);

    bool operator==(const Ray& rhs);
};
