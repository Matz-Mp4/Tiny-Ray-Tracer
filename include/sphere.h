#pragma once

#include "geometric_object.h"

class Sphere: public GeometricObject {
public:
    Point4 center;
    double radius;

    Sphere() = default;
    Sphere(const Point4& center, const double radius);
    ~Sphere();

    bool hit(const Ray& ray, double& t, ShadeRec& shade_rec) const override;
    Color get_color() const override;

private: 
    static const double k_epsilon;
};
