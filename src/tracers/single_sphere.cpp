#include "../../include/single_sphere.h"
#include "../../include/hit_info.h"
#include "../../include/world.h"

SingleSphere::SingleSphere(): 
    Tracer() {};

SingleSphere::SingleSphere(World* world):
    Tracer(world) {};


Color SingleSphere::trace_ray(const Ray& ray) const {
    HitInfo shade_rec(*world_ptr); //not used
    double t; //not used
    
    if(world_ptr->sphere.hit(ray,t,shade_rec))
        return (RED);
    else
        return (BLACK);
}
