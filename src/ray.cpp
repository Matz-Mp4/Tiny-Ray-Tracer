#include "ray.h"
Ray::Ray(const Point4& origin, const Vector4& direction):
    origin(origin),
    direction(direction) {};

bool Ray::operator==(const Ray& rhs) {
    return this->direction == rhs.direction && this->origin == rhs.origin; 
}



