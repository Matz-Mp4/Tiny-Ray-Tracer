#include "../src/math/matrix4.h"
#include "../src/math/vector4.h"
#include "test.h"
#include <iostream>

namespace matrix_normal_ops {
    inline void add() {
        Vector4 v(40.0, 20.0, 20.0, 40.0);
        Matrix4 m(v,v,v,v); 

        Matrix4 res = m + m;

        Vector4 temp_v(80.0,40.0,40.0, 80.0);
        Matrix4 expt(temp_v, temp_v, temp_v, temp_v);
         
        UnitTest test("Matrix Addition");
        test.assert_that(res == expt);
    }

    inline void mul() {
        Vector4 v1(1.0,2.0,3.0,4.0);
        Vector4 v2(5.0,6.0,7.0,8.0);
        Vector4 v3(9.0,8.0,7.0,6.0);
        Vector4 v4(5.0,4.0,3.0,2.0);
        Matrix4 m1(v1,v2,v3,v4); 

        v1 = Vector4(-2.0, 1.0, 2.0, 3.0);
        v2 = Vector4 (3.0, 2.0, 1.0, -1.0);
        v3 = Vector4(4.0, 3.0, 6.0, 5.0);
        v4 = Vector4(1.0, 2.0, 7.0, 8.0);
        Matrix4 m2(v1,v2,v3,v4); 

        Matrix4 res = m1 * m2;

        v1 = Vector4(20.0, 22.0, 50.0, 48.0);
        v2 = Vector4 (44.0, 54.0, 114.0, 108.0);
        v3 = Vector4(40.0, 58.0, 110.0, 102.0);
        v4 = Vector4(16.0, 26.0, 46.0, 42.0);
 
        Matrix4 expt(v1, v2, v3, v4);
         
        UnitTest test("Matrix Multiplication");
        test.assert_that(res == expt);
    }
}

namespace matrix_scalar_ops {
    inline void mul() {
        Vector4 v(1.0, 2.0, 3.0, 4.0);
        Matrix4 m(v,v,v,v); 
        Vector4 temp_v(10.0,20.0,30.0, 40.0);

        Matrix4 res = m * 10.0;
        Matrix4 expt(temp_v, temp_v, temp_v, temp_v);
         
        UnitTest test("Matrix Scalar Multiplication");
        test.assert_that(res == expt);
    }


}

