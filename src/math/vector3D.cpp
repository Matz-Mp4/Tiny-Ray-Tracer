#include "vector3D.h"

#include <cmath>

Vector3D::Vector3D(double x, double y, double z, double w = 0.0)
    : x(x), y(y), z(z), w(w) {}

Vector3D::Vector3D(double t)
    : x(t), y(t), z(t), w(t) {}
    

Vector3D& Vector3D::operator+(const Vector3D& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

Vector3D& Vector3D::operator-(const Vector3D& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z, -w);
}

Vector3D& Vector3D::operator*(const Vector3D& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    w *= rhs.w;
    return *this;
}

// Scalar right hand side
Vector3D& Vector3D::operator*(double rhs) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;
    return *this;
}

// Multiplication right hand side
Vector3D& Vector3D::operator/(double rhs) {
    return *this * (1.0 / rhs);
}

Vector3D operator*(double t, const Vector3D& v) {
    return Vector3D(t * v.x, t * v.y, t * v.z, t * v.w);
}

bool Vector3D::operator==(const Vector3D& other) const{
    return (std::abs(x - other.x) < EPSILON &&
            std::abs(y - other.y) < EPSILON &&
            std::abs(z - other.z) < EPSILON &&
            std::abs(w - other.w) < EPSILON);
}


double Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

double dot(const Vector3D& u, const Vector3D& v) {
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z) + (u.w * v.w);
}

Vector3D cross(const Vector3D& u, const Vector3D& v) {
    return Vector3D(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}
