#pragma once

#include "tracer.h"

class MultipleObjects: public Tracer {
public:
    MultipleObjects();
    MultipleObjects(World* _worldPtr);

    Color trace_ray(const Ray& ray) const override;
};
