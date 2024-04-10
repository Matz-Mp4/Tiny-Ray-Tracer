#include "../../include/plane.h"

const double Plane::k_epsilon = 0.001;

Plane::Plane(const Point4& point, const Vector4& normal):
    point(point),
    normal(normal)
{}


Color Plane::get_color() const {
    return CYAN;
}


bool Plane::hit(const Ray& ray, double& tmin, ShadeRec& shade_rec) const {
    double t = (point - ray.origin) * normal /  ray.direction  * normal ;

    if (t > k_epsilon) {
        tmin = t;
        shade_rec.normal = normal;
        shade_rec.local_hit_point = ray.origin + (t * ray.direction);

        return true;
    }

    return false;
}
