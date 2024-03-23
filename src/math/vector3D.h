#pragma once

class Vector3D {

public:
  double x;
  double y;
  double z;
  double w;

  Vector3D() = default;
  Vector3D(double x, double y, double z, double w);
  Vector3D(double t);
  ~Vector3D() = default;

  Vector3D& operator=(const Vector3D &vec);
};
