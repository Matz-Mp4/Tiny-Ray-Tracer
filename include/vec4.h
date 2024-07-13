#pragma once 
#include "tuple.h"

class Vector4: public Tuple<4> {

    public:
        Vector4() = default;
       ~Vector4() = default;

       
        Vector4(double x, double y, double z);
        Vector4(double x, double y, double z, double w);
        
        Vector4 operator+(const Vector4& rhs) const;
        Vector4 operator-(const Vector4& rhs) const;
        Vector4 operator-(                  ) const;
        Vector4 operator*(double           t) const;
        double  operator*(const Vector4& rhs) const; //dot product
        Vector4 operator/(double           t) const;
        Vector4 operator|(const Vector4&   v) const;
        double  length   (                  ) const;

};


Vector4 operator*(double, const Vector4& rhs);
 
