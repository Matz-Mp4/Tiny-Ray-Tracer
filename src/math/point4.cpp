#include "../../include/point4.h"

#include <cmath>

Point4::Point4(double x, double y, double z) {
  this->data[0] = x;
  this->data[1] = y;
  this->data[2] = z;
  this->data[3] = 1;
}

Point4::Point4(double x, double y, double z, double w) {
  this->data[0] = x;
  this->data[1] = y;
  this->data[2] = z;
  this->data[3] = w;
}

Vector4 Point4::operator-(const Point4& p) const {
  return Vector4(this->data[0] - p.data[0], this->data[1] - p.data[1],
                 this->data[2] - p.data[2], this->data[3] - p.data[3]);
}

Point4  operator-(const Point4& lhs, const Vector4& rhs){
  return Point4(lhs.data[0] - rhs.data[0], lhs.data[1] - rhs.data[1],
                 lhs.data[2] - rhs.data[2], lhs.data[3] - rhs.data[3]);
}

Point4  operator+(const Point4& lhs, const Vector4& rhs){
  return Point4(lhs.data[0] + rhs.data[0], lhs.data[1] + rhs.data[1],
                 lhs.data[2] + rhs.data[2], lhs.data[3] + rhs.data[3]);
}

double Point4::len(const Point4& p) const {
  double x2 = this->data[0] * p.data[0];
  double y2 = this->data[1] * p.data[1];
  double z2 = this->data[2] * p.data[2];
  double w2 = this->data[3] * p.data[3];
  return std::sqrt(x2 + y2 + z2 + w2);

}


