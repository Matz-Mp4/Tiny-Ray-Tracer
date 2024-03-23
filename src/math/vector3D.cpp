#include "vector3D.h"

//=======================(Constructor)==========================\\

Vector3D::Vector3D(double x, double y, double z, double w)
    : x(x), y(y), z(z), w(w) {}
Vector3D::Vector3D(double t) : x(t), y(t), z(t), w(t) {}

//=======================(Overload)==========================\\

Vector3D &Vector3D::operator=(const Vector3D &vec) {
  if (this != &vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = vec.w;
  }

  return *this;
}
