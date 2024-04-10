#include "../../include/ray.h"
Ray::Ray(const Point4& origin, const Vector4& direction):
    origin(origin),
    direction(direction) {};

bool Ray::operator==(const Ray& rhs) {
    auto test = this->direction.operator==(rhs.direction) ;
    return true;
}



