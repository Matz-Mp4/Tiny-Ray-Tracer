#pragma once

#include "vector4.h"

class Matrix4 {
    Vector4 data[4];
public:

    Matrix4() = default;
    ~Matrix4() = default;

    Matrix4(Vector4 arg1, Vector4 arg2, Vector4 arg3,Vector4 arg4) ;

    Matrix4& operator+(const Matrix4& );
    Matrix4& operator*(const Matrix4&);
    Matrix4& operator*(const double d);
    bool     operator==(const Matrix4& ) const;
    friend std::ostream& operator<<(std::ostream& stream, const Matrix4& mtx); //print Matrix4 

};
