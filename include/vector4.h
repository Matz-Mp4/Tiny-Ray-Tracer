#pragma once

#include <cmath>
#include <ostream>

constexpr double EPSILON = 10e-6;

class Vector4 {
public:
    double x;
    double y;
    double z;
    double w;

    Vector4() = default;
    Vector4(double t);
    Vector4(double x, double y, double z);
    Vector4(double x, double y, double z, double w);
    
    double          operator*(const Vector4&) const; //dot product
    Vector4         operator+(const Vector4& ) const;
    Vector4  operator*(double) const; 
    Vector4  operator/(double ) const;
 
    Vector4         operator-(const Vector4& ) const;
    Vector4         operator-() const;
    bool            operator==(const Vector4& ) const;
    friend std::ostream& operator<<(std::ostream& stream, const Vector4& vec); //print Vector4
                                                                               //
    double length() const;    
};

Vector4 cross(const Vector4& u, const Vector4& v);
Vector4  operator*(double, const Vector4&) ; 
Vector4  operator/(double, const Vector4&);
 

using Point4 = Vector4;
