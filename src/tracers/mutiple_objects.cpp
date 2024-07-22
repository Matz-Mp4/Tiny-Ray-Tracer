#include "../../include/multiple_objects.h"
#include "../../include/hit_info.h"
#include "../../include/world.h"

MultipleObjects::MultipleObjects(): 
    Tracer() {};

MultipleObjects::MultipleObjects(World* world):
    Tracer(world) {};


Color MultipleObjects::trace_ray(const Ray& ray) const {
    HitInfo shade_rec(world_ptr->hit_bare_bones_objects(ray)); //not used
    
    if(shade_rec.hit_object)
        return shade_rec.color;
    else
        return world_ptr->bg;
}
