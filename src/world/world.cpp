#include "../../include/world.h"
#include "../../include/hit_info.h"
/* #include "../build/b_single_sphere.h" */
/* #include "../build/b_sinusoid.h" */
#include "../build/b_camera.h"

#include <iostream>


const double kHugeValue	= 1.0E6;
World::World()
    :bg(BLACK),
    tracer_ptr(nullptr),
    window(nullptr),
    camera_ptr(nullptr)

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

    if(camera_ptr) {
        delete camera_ptr;
        camera_ptr = nullptr;
    }

    for (int i = 0 ; i < objects.size(); i++) {
        delete objects[i];
    }
	/* delete_objects(); */
}

void World::render_scene() {
    Color pixel_color;
    Ray ray;
    double x, y, zw = 100.0; //hard wired in (temporary)
    init_window(vp.length, vp.height);
    ray.direction = Vec4(0.0,0.0,-1.0);
    Tuple<2> sp;
    bool quit = false; 

    int n_samples = vp.n_samples();

    for (int r = 0; r < vp.height; r++) {			// up
		for (int c = 0; c < vp.length; c++) {		// across 					
           //Anti-Alisign
           pixel_color = BLACK;
            for (int j = 0; j < n_samples; j++) {
                sp = vp.sampler_ptr->sample_unit_square();
                x = vp.pixel_size * (c - 0.5 *  vp.length + sp[0]);
                y = vp.pixel_size * (r - 0.5 *  vp.height + sp[1]);
                ray.origin = Point4(x, y, zw);
                pixel_color = pixel_color +  tracer_ptr->trace_ray(ray);
            }

            pixel_color = pixel_color  * (1.0 / n_samples);
            display_pixel(r, c, pixel_color);

            if (window->should_close()){
		    	quit = true;
		    }
        }
        window->show_window();
    }

    while (!quit && !window->should_close()) {
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
