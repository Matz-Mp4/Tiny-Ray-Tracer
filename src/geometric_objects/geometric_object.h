#pragma once

#include "../utilities/ray.h"
#include "../utilities/color.h"
#include "../utilities/shade_rec.h"

class GeometricObject {
public: 
    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& shade_rec) const = 0; 

protected: 
    Color color;

};
