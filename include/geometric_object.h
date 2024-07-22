#pragma once

#include "ray.h"
#include "hit_info.h"

class GeometricObject {
public: 
    Color color;
    virtual bool hit(const Ray& ray, double& tmin, HitInfo& shade_rec) const = 0; 
    virtual Color get_color() const = 0;
    virtual ~GeometricObject();
};
