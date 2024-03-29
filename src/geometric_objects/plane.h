#pragma once

#include "geometric_object.h"
#include "../math/vector4.h"

class Plane: public GeometricObject {
public: 
    Plane(const Point4& point, const Vector4& normal);
    bool hit(const Ray& ray, double& t, ShadeRec& shade_rec) const override;

private:
    Point4 point;   //point through which plane passes
    Vector4 normal; //normal to the plane
    static const double k_epsilon;
};


