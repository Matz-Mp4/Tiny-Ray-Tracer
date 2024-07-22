#include "../../include/hit_info.h"
#include "../../include/world.h"

HitInfo::HitInfo(World& world)
    : hit_object(false),
      local_hit_point(),
      normal(),
      color(Color(0.0,0.0,0.0)),
      world(world)
{}
