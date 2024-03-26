#include "vector4.h"

#include <cmath>


Vector4::Vector4(double x, double y, double z, double w = 0.0)
    : x(x), y(y), z(z), w(w) {}

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

Vector4& Vector4::operator+(const Vector4& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

// Vector4& Vector4::operator=(const Vector4& vec) {
//    if ( *this == vec) return *this;
//    
//    this->x = vec.x;
//    this->y = vec.y;
//    this->z = vec.z;
//    this->w = vec.w;
// }

Vector4& Vector4::operator-(const Vector4& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

Vector4 Vector4::operator-() const {
    return Vector4(-x, -y, -z, -w);
}

Vector4& Vector4::operator*(const Vector4& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    w *= rhs.w;
    return *this;
}

// Scalar right hand side
Vector4& Vector4::operator*(double rhs) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;
    return *this;
}

// Multiplication right hand side
Vector4& Vector4::operator/(double rhs) {
    return *this * (1.0 / rhs);
}

Vector4 operator*(double t, const Vector4& v) {
    return Vector4(t * v.x, t * v.y, t * v.z, t * v.w);
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

double dot(const Vector4& u, const Vector4& v) {
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z) + (u.w * v.w);
}

Vector4 cross(const Vector4& u, const Vector4& v) {
    return Vector4(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}
