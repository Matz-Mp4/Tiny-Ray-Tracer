#pragma once

#include "tracer.h"
#include <math.h>

class Sinusoid : public Tracer{
public:  
    Sinusoid(){ }
    Sinusoid(World* _world_ptr){ world_ptr = _world_ptr; }
    ~Sinusoid(){ world_ptr = NULL; }
    
    virtual Color trace_ray(const Ray& ray) const {
        double x = ray.origin[0];
        double y = ray.origin[1];
        return Color(0.5 * (1 + sin(pow(x, 2)*pow(y, 2))));
    }
};
