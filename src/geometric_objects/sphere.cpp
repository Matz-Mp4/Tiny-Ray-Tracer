#include "../../include/sphere.h"

const double Sphere::k_epsilon = 0.001;

Sphere::Sphere(const Point4 &center, const double radius)
    : center(center), radius(radius) {}


Color Sphere::get_color() const {
    return RED;
}
bool Sphere::hit(const Ray &ray, double &tmin, ShadeRec &shade_rec) const {
    double t;
    Vector4 temp = ray.origin - center;
    double a = ray.direction * ray.direction;
    double b = 2.0 * temp * ray.direction;
    double c = temp * temp - radius * radius;
    double disc = b * b - 4.0 * a * c;

    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root
        if (t > k_epsilon) {
          tmin = t;
          shade_rec.normal = (temp + t * ray.direction) / radius;
          shade_rec.local_hit_point = ray.origin + t * ray.direction;
          return true;
        }
        t = (-b + e) / denom; // larger root
        if (t > k_epsilon) {
          tmin = t;
          shade_rec.normal = (temp + t * ray.direction) / radius;
          shade_rec.local_hit_point = ray.origin + t * ray.direction;
          return  true;
        }
    }
    return (false);
}
