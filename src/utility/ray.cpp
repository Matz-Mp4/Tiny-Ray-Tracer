#include "ray.h"

Ray::Ray(const Point4& origin, const Vector4& dir):
    origin(origin),
    dir(dir) {};

bool Ray::operator==(const Ray& rhs) {
    return this->dir == rhs.dir && this->origin == rhs.origin; 
}



