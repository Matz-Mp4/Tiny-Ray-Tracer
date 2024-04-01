#include "world.h"
#include "../tracers/single_sphere.h"

void World::build() {
    vp.length = 200;
    vp.height = 200;
    vp.pixel_size = 1.0;
    vp.gamma = 1.0;

    bg = BLACK;
    tracer_ptr = new SingleSphere(this);

    sphere.center = 0.0;
    sphere.radius = 85.0;
}

void World::render_scene() const {
    Color pixel_color;
    Ray ray;
    double x, y, zw = 100.0; //hard wired in (temporary)
    
    open_window(vp.length, vp.height);
    ray.direction = Vector4(0.0,0.0,-1.0);

    for(int i = 0; i < vp.height; i++) {
        for(int j = 0; j < vp.length; j++) {
            x = vp.pixel_size * (j - 0.5 * (vp.length - 1.0));
            y = vp.pixel_size * (i - 0.5 * (vp.height - 1.0));
            ray.origin = Point4(x, y, zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(i, j, pixel_color);
        }
    }

}
