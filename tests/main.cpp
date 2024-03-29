#include "vector4_test.h"
#include "matrix4_test.h"


int main() {
    vec_normal_ops::add();
    vec_normal_ops::sub();
    vec_scalar_ops::mul();
    vec_scalar_ops::div();

    matrix_scalar_ops::mul();
    matrix_normal_ops::add();
    matrix_normal_ops::mul();

    
    return 0;
}
