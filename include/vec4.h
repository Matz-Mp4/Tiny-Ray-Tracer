#pragma once 
#include "tuple.h"

class Vec4: public Tuple<4> {
    public:
        Vec4() = default;
       ~Vec4() = default;

       
        Vec4(double x, double y, double z);
        Vec4(double x, double y, double z, double w);
        
        Vec4    operator+(const Vec4& rhs) const;
        Vec4    operator-(const Vec4& rhs) const;
        Vec4    operator-() const;
        Vec4    operator*(double t) const;
        double  operator*(const Vec4& rhs) const; //dot product
        Vec4    operator/(double t) const;
        Vec4    operator|(const Vec4&   v) const;
        double  length() const;
        void    normalize();

};


Vec4 operator*(double, const Vec4& rhs);
Vec4 operator/(double, const Vec4& rhs);
 
