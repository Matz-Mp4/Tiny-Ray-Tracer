#include "../../include/world.h"
#include "../../include/multiple_objects.h"
#include "../../include/hit_info.h"
#include "../../include/sphere.h"
#include "../../include/plane.h"


const double kHugeValue	= 1.0E6;
World::World()
    :bg(BLACK),
    tracer_ptr(nullptr),
    window(nullptr)

{}

World::~World() {		
	if (tracer_ptr) {
		delete tracer_ptr;
		tracer_ptr = nullptr;
	}

	if (window) {
		window->close();
		delete window;
		window = nullptr;
	}

    for (int i = 0 ; i < objects.size(); i++) {
        delete objects[i];
    }
	/* delete_objects(); */
}

void World::build() {
    int n_samples = 30;

    vp = vp.with_len(800)
           .with_height(800)
           .with_psize(1.0)
           .with_gamma(1.0)
           .with_samples(1);

    bg = BLACK;
    tracer_ptr = new MultipleObjects(this);
    Sphere* sphere1 = new Sphere(Point4(0.0, -25.0, 0.0), 80.0);
    sphere1->color = RED;

    Sphere* sphere2 = new Sphere(Point4(0.0,30.0,0.0), 60);
    sphere2->color = YELLOW;
    
    
    Plane* plane = new Plane(Point4(0.0, 0.0,0.0), Vec4(0.0, 1.0,1.0));
    plane->color = GREEN;

    /* add_object(plane); */
    add_object(sphere1);
    /* add_object(sphere2);  */

}

void World::render_scene() {
    Color pixel_color;
    Ray ray;
    double x, y, zw = 100.0; //hard wired in (temporary)
    
    init_window(vp.length, vp.height);
    ray.direction = Vec4(0.0,0.0,-1.0);
    bool quit = false; 

    for (int i = 0; i < vp.height; i++) {
        for (int j = 0; j < vp.length; j++) {
            x = vp.pixel_size * (j - 0.5 * (vp.length - 1.0));
            y = vp.pixel_size * (i - 0.5 * (vp.height - 1.0));

            ray.origin = Point4(x, y, zw);
            pixel_color = tracer_ptr->trace_ray(ray);

            display_pixel(i, j, pixel_color);

            if (window->should_close()){
				quit = true;
			}
        }
        window->show_window();
    }

    while (!quit && !window->should_close()) {
		// wait
	}
}

void World::display_pixel(const int row, const int column, const Color& pixel_color){
    //have to start from max y coordinate to convert to screen coordinates
    int x = column;
    int y = vp.height - row - 1;

    Color color = pixel_color;
    if (vp.gamma != 1.0) 
        color = pixel_color.powc(vp.inv_gamma);
    
    window->set_pixel(x, y, (int)(color.r * 255),
                            (int)(color.g * 255),
                            (int)(color.b * 255));
}

void World::init_window(const int length, const int hight) {
    window = new Window(length, hight);
	window->init();
}

void World::add_object(GeometricObject* object_ptr){
    objects.push_back(object_ptr);
}

HitInfo World::hit_bare_bones_objects(const Ray& ray) {
    HitInfo shade_rec(*this);
    double t;
    double tmin = 1.0E6;
    int num_objects = objects.size();

    for (int i = 0; i < num_objects; i++) {
        if (objects[i]->hit(ray, t, shade_rec) && (t < tmin) ) {
            shade_rec.hit_object = true;
            tmin = t;
            shade_rec.color = objects[i]->color;
        }
    }
    return shade_rec;
}
