#pragma once

#include <vector>
#include "view_plane.h" 
#include "../utilities/color.h" 
#include "../geometric_objects/sphere.h" 
#include "../tracers/tracer.h" 

class World {
public:
    ViewPlane vp;
    Color bg; //background color
    Sphere sphere;
    Tracer* tracer_ptr;
    std::vector<GeometricObject*> objects;


    void build();
    void render_scene() const;
    void open_window(const int length, const int hight) const;
    void display_pixel(const int row, const int column, const Color& pixel_color) const;
    void add_object(GeometricObject* object_ptr);
    ShadeRec hit_bare_bones_objects(const Ray& ray) ;

};
