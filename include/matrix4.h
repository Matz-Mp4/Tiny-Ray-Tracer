#pragma once

#include "vec4.h"

class Matrix4 {
public:
    Vec4 data[4];

    Matrix4() = default;
    ~Matrix4() = default;

    Matrix4(const Vec4& arg1, const Vec4& arg2, const Vec4& arg3, const Vec4& arg4);

    Matrix4& operator+ (const Matrix4& rhs);
    Matrix4& operator* (const Matrix4& rhs);
    Matrix4& operator* (const double   rhs);
    bool     operator==(const Matrix4& rhs) const;
    
    friend std::ostream& operator<<(std::ostream& stream, const Matrix4& mtx); //print Matrix4 

};
