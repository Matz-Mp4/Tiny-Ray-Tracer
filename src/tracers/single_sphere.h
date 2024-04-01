#pragma once 

#include "tracer.h"

class SingleSphere: public Tracer {
public:
    SingleSphere();
    SingleSphere(World* _worldPtr);

    Color trace_ray(const Ray& ray) const override;
};
