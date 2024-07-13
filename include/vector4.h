#pragma once

#include <cmath>
#include <ostream>

constexpr double epsilon = 10e-6;

class Vector4 {
public:
    double y;
    double x;
    double z;
    double w;

    Vector4() = default;
    ~Vector4() = default;

    Vector4(double t);
    Vector4(double x, double y, double z);
    Vector4(double x, double y, double z, double w);
    
    Vector4 operator+ (const Vector4& rhs) const;
    Vector4 operator- (const Vector4& rhs) const;
    Vector4 operator- (                  ) const;
    double  operator* (const Vector4& rhs) const; //dot product
    Vector4 operator* (double         rhs) const;
    Vector4 operator/ (double         rhs) const;
    bool    operator==(const Vector4& rhs) const;

    friend std::ostream& operator<<(std::ostream& stream, const Vector4& vec); //print Vector4

    double length() const;
};

using Point4 = Vector4;

Vector4 operator*(double, const Vector4& rhs);
Vector4 operator/(double, const Vector4& rhs);
 
Vector4 cross(const Vector4& u, const Vector4& v);
