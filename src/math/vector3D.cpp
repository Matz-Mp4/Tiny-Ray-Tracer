#include "vector3D.h"

Vector3D::Vector3D() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
    this->w = 0.0;
}

Vector3D::Vector3D(double t) {
    this->x = t;
    this->y = t;
    this->z = t;
    this->w = 0.0;
}

Vector3D::Vector3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 0.0;
}


Vector3D &Vector3D::operator+(const Vector3D &other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}
