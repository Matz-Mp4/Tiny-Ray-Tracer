#pragma once

#include "ray.h"
#include "shade_rec.h"

class GeometricObject {
public: 
    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& shade_rec) const = 0; 
    virtual Color get_color() const = 0;


protected: 
    Color color;

};
