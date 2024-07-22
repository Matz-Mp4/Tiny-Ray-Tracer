#include "../../include/world.h"
#include "../../include/multiple_objects.h"
#include "../../include/hit_info.h"
#include "../../include/sphere.h"
#include "../../include/world.h"
#include "../../include/plane.h"
#include "../../include/jittered.h"
#include "../../include/regular.h"


void World::build() {
    bg = BLACK;
    vp.with_sampler(new Jittered(1, 1));
    tracer_ptr = new MultipleObjects(this);
    vp.pixel_size = 1.0;
    vp.length = 200;
    vp.height = 200;

    Sphere* sphere1 = new Sphere(Point4(0.0, -25.0, 0.0), 80.0);
    sphere1->color = RED;
    add_object(sphere1);

}


