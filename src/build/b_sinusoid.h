#include "../../include/world.h"
#include "../../include/hit_info.h"
#include "../../include/world.h"
#include "../../include/jittered.h"
#include "../../include/regular.h"
#include "../../include/sinusoid.h"


void World::build() {
    bg = BLACK;
    vp.with_sampler(new Jittered(50, 50));
    vp.pixel_size = 0.01;
    vp.length = 600;
    vp.height = 600;
    tracer_ptr = new Sinusoid(this);

}


