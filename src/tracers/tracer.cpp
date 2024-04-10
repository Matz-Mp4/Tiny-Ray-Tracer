#include "../../include/tracer.h"

Tracer::Tracer():
    world_ptr(nullptr) {}

Tracer::Tracer(World* world_ptr):
    world_ptr(world_ptr) {}

Tracer::~Tracer() {
	if (world_ptr)
		world_ptr = nullptr;
}
Color Tracer::trace_ray(const Ray& ray) const {
    return BLACK;
}
