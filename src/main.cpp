#include "math/vector4.h"
#include <iostream>

int main() {
    Vector4 vec(1.0,2.0,3.0,0.0);
    Vector4 other(1.0,2.0,3.0,0.0);
    std::cout << "vec = "<< vec + other;
    return 0;
}
