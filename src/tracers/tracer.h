#pragma once 

#include "../utilities/color.h"
#include "../utilities/ray.h"
#include "../world/world.h"

class Tracer {
public:
    Tracer() = default;
    Tracer(World& world_ptr);

    virtual Color trace_ray(const Ray& ray) const;

protected:
    World* world_ptr;
};
