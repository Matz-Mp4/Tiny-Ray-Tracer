class Tuple4 {
public:
  double x;
  double y;
  double z;
  double w;

  
  Tuple4 &operator=(const Tuple4 &tuple) {

    if (this == &tuple)
      return *this;
    this->x = tuple.x;
    this->y = tuple.y;
    this->z = tuple.z;
    this->w = tuple.w;

    return *this;
  }

  bool operator==(const Tuple4 &tuple) {
    return this->x == tuple.x && 
           this->y == tuple.y && 
           this->z == tuple.z &&
           this->w == tuple.w;
  }

};
