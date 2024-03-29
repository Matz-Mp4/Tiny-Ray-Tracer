#include "vector4.h"

#include <cmath>


Vector4::Vector4(double x, double y, double z ) : x(x), y(y), z(z), w(0.0) {}
Vector4::Vector4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(double t)
    : x(t), y(t), z(t), w(t) {}
    

std::ostream& operator<<(std::ostream& stream, const Vector4& vec){
     stream << '(';
     stream << vec.x<< " ,";
     stream << vec.y<< " ,";
     stream << vec.z<< " ,";
     stream << vec.w<< " ,";
     stream << "\b\b) ";
     
     return stream;
 }


Vector4  Vector4::operator-(const Vector4& rhs) const{
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4  Vector4::operator+(const Vector4& rhs) const{
    return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Vector4 Vector4::operator-() const {
    return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator*(double t) const {
    return Vector4(t * this->x, t * this->y, t * this->z, t * this->w);
}

Vector4 Vector4::operator/(double t) const {
    return Vector4( this->x / t,  this->y / t,  this->z / t,  this->w / t);
}



double Vector4::operator*(const Vector4& rhs) const{
    return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);
}

Vector4 operator*(double t, const Vector4& v) {
    return Vector4(t * v.x, t * v.y, t * v.z, t * v.w);
}

Vector4 operator/(double t, const Vector4& v) {
    return Vector4( v.x / t,  v.y / t,  v.z / t,  v.w / t);
}

bool Vector4::operator==(const Vector4& other) const{
    return (std::abs(x - other.x) < EPSILON &&
            std::abs(y - other.y) < EPSILON &&
            std::abs(z - other.z) < EPSILON &&
            std::abs(w - other.w) < EPSILON);
}


double Vector4::length() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

Vector4 cross(const Vector4& u, const Vector4& v) {
    return Vector4(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}
