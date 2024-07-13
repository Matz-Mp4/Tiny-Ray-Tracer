#include "../../include/vec4.h"

#include <cmath>

Vector4::Vector4(double x, double y, double z) {
  this->data[0] = x;
  this->data[1] = y;
  this->data[2] = z;
  this->data[3] = 0;
}

Vector4::Vector4(double x, double y, double z, double w) {
  this->data[0] = x;
  this->data[1] = y;
  this->data[2] = z;
  this->data[3] = w;
}

Vector4 Vector4::operator+(const Vector4 &rhs) const {
  return Vector4(this->data[0] + rhs.data[0], this->data[1] + rhs.data[1],
                 this->data[2] + rhs.data[2], this->data[3] + rhs.data[3]);
}

Vector4 Vector4::operator-(const Vector4 &rhs) const {
  return Vector4(this->data[0] - rhs.data[0], this->data[1] - rhs.data[1],
                 this->data[2] - rhs.data[2], this->data[3] - rhs.data[3]);
}

Vector4 Vector4::operator-() const {
  return Vector4(-this->data[0], -this->data[1], -this->data[2],
                 -this->data[3]);
}

double Vector4::operator*(const Vector4 &rhs) const {
  double x2 = this->data[0] * this->data[0];
  double y2 = this->data[1] * this->data[1];
  double z2 = this->data[2] * this->data[2];
  double w2 = this->data[3] * this->data[3];

  return x2 + y2 + z2 + w2;
}

Vector4 Vector4::operator*(double t) const {
  return Vector4(t * this->data[0], t * this->data[1], t * this->data[2],
                 t * this->data[3]);
}

Vector4 Vector4::operator|(const Vector4 &v) const {
  return Vector4(this->data[1] * v.data[2] - this->data[2] * v.data[1], 
                 this->data[2] * v.data[0] - this->data[0] * v.data[2],
                 this->data[0] * v.data[1] - this->data[1] * v.data[0]);
}

Vector4 Vector4::operator/(double t) const {
  return Vector4(this->data[0] / t, 
                 this->data[1] / t,
                 this->data[2] / t,
                 this->data[3] / t);
}

// Friend operator

double Vector4::length() const {
  double x2 = this->data[0] * this->data[0];
  double y2 = this->data[1] * this->data[1];
  double z2 = this->data[2] * this->data[2];
  double w2 = this->data[3] * this->data[3];
  return std::sqrt(x2 + y2 + z2 + w2);
}


/*
Vector4 operator*(double t, const Vector4 &v) {
  return Vector4(t * v.x, t * v.y, t * v.z, t * v.w);
}
*/




