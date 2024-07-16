#pragma once 
#include "tuple.h"
#include "vec4.h"

class Point4: public Tuple<4> {
    public:
        Point4() = default;
       ~Point4() = default;

 
        Point4(double x, double y, double z);
        Point4(double x, double y, double z, double w);
        

       Vec4           operator-(const Point4& p) const;
       friend Point4  operator-(const Point4& lhs, const Vec4& rhs);
       friend Point4  operator+(const Point4& lhs, const Vec4& rhs);
       double         len(const Point4& p) const;

};


