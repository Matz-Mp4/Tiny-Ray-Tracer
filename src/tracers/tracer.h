#pragma once 

#include "../utilities/color.h"
#include "../utilities/ray.h"
/* #include "../world/world.h" */

class World;

class Tracer {
public:
	Tracer();									
    Tracer(World* world_ptr);
    virtual ~Tracer();

    virtual Color trace_ray(const Ray& ray) const;

protected:
    World* world_ptr;
};
