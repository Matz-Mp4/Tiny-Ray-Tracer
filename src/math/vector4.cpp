#include "../../include/vector4.h"

#include <cmath>

Vector4::Vector4(double x, double y, double z ) : x(x), y(y), z(z), w(0.0) {}

Vector4::Vector4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(double t)
    : x(t), y(t), z(t), w(t) {}


Vector4  Vector4::operator+(const Vector4& rhs) const{
    return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Vector4  Vector4::operator-(const Vector4& rhs) const{
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4 Vector4::operator-() const {
    return Vector4(-x, -y, -z, -w);
}

double Vector4::operator*(const Vector4& rhs) const{
    return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);
}

Vector4 Vector4::operator*(double rhs) const {
    return Vector4(rhs * this->x, rhs * this->y, rhs * this->z, rhs * this->w);
}

Vector4 Vector4::operator/(double rhs) const {
    return Vector4( this->x / rhs,  this->y / rhs,  this->z / rhs,  this->w / rhs);
}

bool Vector4::operator==(const Vector4& other) const{
    return (std::abs(x - other.x) < epsilon &&
            std::abs(y - other.y) < epsilon &&
            std::abs(z - other.z) < epsilon &&
            std::abs(w - other.w) < epsilon);
}


// Friend operator
std::ostream& operator<<(std::ostream& stream, const Vector4& vec) {
    stream << '(';
    stream << vec.x<< " ,";
    stream << vec.y<< " ,";
    stream << vec.z<< " ,";
    stream << vec.w<< " ,";
    stream << "\b\b) ";
    return stream;
}


double Vector4::length() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}


Vector4 operator*(double t, const Vector4& v) {
    return Vector4(t * v.x, t * v.y, t * v.z, t * v.w);
}

Vector4 operator/(double t, const Vector4& v) {
    return Vector4( v.x / t,  v.y / t,  v.z / t,  v.w / t);
}


Vector4 cross(const Vector4& u, const Vector4& v) {
    return Vector4(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}
