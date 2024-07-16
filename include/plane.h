#pragma once

#include "geometric_object.h"
#include "vec4.h"

class Plane: public GeometricObject {
public: 
    Plane() = default;
    ~Plane();
    Plane(const Point4& point, const Vec4& normal);

    bool hit(const Ray& ray, double& t, ShadeRec& shade_rec) const override;
    Color get_color() const override;    
    
private:
    Point4 point;   //point through which plane passes
    Vec4 normal; //normal to the plane
    static const double k_epsilon;
};


