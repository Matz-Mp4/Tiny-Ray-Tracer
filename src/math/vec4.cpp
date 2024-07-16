#include "../../include/vec4.h"

#include <cmath>

Vec4::Vec4(double x, double y, double z) {
  this->data[0] = x;
  this->data[1] = y;
  this->data[2] = z;
  this->data[3] = 0.0;
}

Vec4::Vec4(double x, double y, double z, double w) {
  this->data[0] = x;
  this->data[1] = y;
  this->data[2] = z;
  this->data[3] = w;
}

Vec4 Vec4::operator+(const Vec4 &rhs) const {
  return Vec4(this->data[0] + rhs.data[0], this->data[1] + rhs.data[1],
                 this->data[2] + rhs.data[2], this->data[3] + rhs.data[3]);
}

Vec4 Vec4::operator-(const Vec4 &rhs) const {
  return Vec4(this->data[0] - rhs.data[0], this->data[1] - rhs.data[1],
                 this->data[2] - rhs.data[2], this->data[3] - rhs.data[3]);
}

Vec4 Vec4::operator-() const {
  return Vec4(-this->data[0], -this->data[1], -this->data[2],
                 -this->data[3]);
}

//dot product
double Vec4::operator*(const Vec4 &rhs) const {
  double x2 = this->data[0] * rhs.data[0];
  double y2 = this->data[1] * rhs.data[1];
  double z2 = this->data[2] * rhs.data[2];
  double w2 = this->data[3] * rhs.data[3];

  return x2 + y2 + z2 + w2;
}

Vec4 Vec4::operator*(double t) const {
  return Vec4(t * this->data[0], t * this->data[1], 
                 t * this->data[2], t * this->data[3]);
}

//cross product
Vec4 Vec4::operator|(const Vec4 &v) const {
  return Vec4(this->data[1] * v.data[2] - this->data[2] * v.data[1], 
                 this->data[2] * v.data[0] - this->data[0] * v.data[2],
                 this->data[0] * v.data[1] - this->data[1] * v.data[0]);
}

Vec4 Vec4::operator/(double t) const {
  return Vec4(this->data[0] / t, 
                 this->data[1] / t,
                 this->data[2] / t,
                 this->data[3] / t);
}

double Vec4::length() const {
  double x2 = this->data[0] * this->data[0];
  double y2 = this->data[1] * this->data[1];
  double z2 = this->data[2] * this->data[2];
  double w2 = this->data[3] * this->data[3];
  return std::sqrt(x2 + y2 + z2 + w2);
}


Vec4 operator*(double t, const Vec4 &v) {
  return Vec4(t * v[0], t * v[1], t * v[2], t * v[3]);
}

Vec4 operator/(double t, const Vec4 &v) {
  return v / t;
}






