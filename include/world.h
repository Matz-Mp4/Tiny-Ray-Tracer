#pragma once

#include <vector>
#include "view_plane.h" 
#include "color.h" 
#include "sphere.h" 
#include "tracer.h" 
#include "window.h"

class World {
public:
    ViewPlane vp;
    Color bg; //background color
    Sphere sphere;
    Tracer* tracer_ptr;
    std::vector<GeometricObject*> objects;
    Window* window;

    World();
    ~World();


    void build();
    void render_scene() ;
    void init_window(const int length, const int hight);
    void display_pixel(const int row, const int column, const Color& pixel_color);
    void add_object(GeometricObject* object_ptr);
    ShadeRec hit_bare_bones_objects(const Ray& ray) ;

};
