#pragma once

#include "tuple4.h"

class Vector3D : public Tuple4 {
public:
    Vector3D();
    Vector3D(double t);
    Vector3D(double x, double y, double z);

    Vector3D &operator+(const Vector3D &other);
};
