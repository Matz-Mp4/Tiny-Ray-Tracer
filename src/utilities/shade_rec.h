#pragma once

#include "../math/vector4.h"
#include "../utilities/color.h"
// only need a forward class declaration as the World data member is a reference
class World;

class ShadeRec{
public:
    bool hit_object;        //the ray hit and object ?
    Point4 local_hit_point; //world coordinates of hit point 
    Vector4 normal;         //noraml of hit Point4
    World& world;           //world reference for shading
    Color color;
                            
    ShadeRec(World& world);

};
