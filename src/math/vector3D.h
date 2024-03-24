#pragma once

#include <cmath>

constexpr double EPSILON = 10e-6;

class Vector3D {
public:
    double x;
    double y;
    double z;
    double w;

    Vector3D() = default;
    Vector3D(double t);
    Vector3D(double x, double y, double z, double w = 0.0);
    
    ~Vector3D() = default;

    Vector3D& operator+ (const Vector3D& rhs);
    Vector3D& operator- (const Vector3D& rhs);
    Vector3D  operator- () const;
    Vector3D& operator* (const Vector3D& rhs);
    Vector3D& operator* (double rhs);
    Vector3D& operator/ (double rhs);
    bool      operator==(const Vector3D& other);
    

    double length() const;    
};

Vector3D operator*(double lhs, const Vector3D& rhs);

double   dot  (const Vector3D& u, const Vector3D& v);
Vector3D cross(const Vector3D& u, const Vector3D& v);

