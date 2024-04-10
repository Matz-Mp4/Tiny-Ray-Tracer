#pragma once

#include "geometric_object.h"
#include "vector4.h"

class Plane: public GeometricObject {
public: 
    Plane() = default;
    Plane(const Point4& point, const Vector4& normal);
    bool hit(const Ray& ray, double& t, ShadeRec& shade_rec) const override;
    Color get_color() const override;    
    
private:
    Point4 point;   //point through which plane passes
    Vector4 normal; //normal to the plane
    static const double k_epsilon;
};


