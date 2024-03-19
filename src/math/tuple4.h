#pragma once

class Tuple4 {
public:
    double x;
    double y;
    double z;
    double w;

    Tuple4 &operator=(const Tuple4 &tuple);
    bool operator==(const Tuple4 &tuple);
};
