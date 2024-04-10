#include "single_sphere.h"
#include "../utilities/shade_rec.h"
#include "../world/world.h"

SingleSphere::SingleSphere(): 
    Tracer() {};

SingleSphere::SingleSphere(World* world):
    Tracer(world) {};


Color SingleSphere::trace_ray(const Ray& ray) const {
    ShadeRec shade_rec(*world_ptr); //not used
    double t; //not used
    
    if(world_ptr->sphere.hit(ray,t,shade_rec))
        return (RED);
    else
        return (BLACK);
}
