#pragma once

#include "vec4.h"
#include "point4.h"
#include "color.h"
// only need a forward class declaration as the World data member is a reference
class World;

class HitInfo{
public:
    bool hit_object;        //the ray hit and object ?
    Point4 local_hit_point; //world coordinates of hit point 
    Vec4 normal;            //noraml of hit Point4
    World& world;           //world reference for shading
    Color color;
                            
    HitInfo(World& world);
};
