#pragma once

#include "../math/vector4.h"
#include "color.h"
#include "../world/world.h"

class ShadeRec{
public:
    bool hit_object;        //the ray hit and object ?
    Point4 local_hit_point; //world coordinates of hit point 
    Vector4 normal;         //noraml of hit Point4
    World& world;           //world for shading
    Color color;
                            
    ShadeRec(World& world);

};
