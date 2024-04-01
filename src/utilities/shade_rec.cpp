#include "shade_rec.h"

ShadeRec::ShadeRec(World& world):
    hit_object(false),
    local_hit_point(),
    normal(),
    color(Color(0.0,0.0,0.0)),
    world(world)
{}
