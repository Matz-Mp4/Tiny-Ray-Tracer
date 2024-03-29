#include "../src/math/vector4.h"
#include "test.h"
#include <iostream>

namespace vec_normal_ops {

    inline void add() {
        Vector4 u(1.0, 2.0, 3.0);
        Vector4 v(3.0, 2.0, 1.0);

        Vector4 res = u + v;
        Vector4 expt(4.0, 4.0, 4.0);
        
        UnitTest test("Vector Addition");
        test.assert_that(res == expt);
    }

    inline void sub() {

        Vector4 v(1.0, 2.0, 3.0);
        Point4 t(5.0, 6.0, 7.0);
        Vector4 res = v - t;
        Vector4 expt(-4.0, -4.0, -4.0);

        UnitTest test("Vector Subtration");
        test.assert_that(res == expt );
    }
   inline void dot_product() {
        Vector4 u(1.0, 2.0, 3.0);
        Vector4 v(2.0, 3.0, 4.0);
        
        double res = u *  v;
        double expt = 20.0;
        
        UnitTest test("Vector Dot Product");
        test.assert_that(res == expt);

    }

    inline void cross_prod() {
        Vector4 u(1.0, 2.0, 3.0);
        Vector4 v(2.0, 3.0, 4.0);
        
        Vector4 res = cross(u, v);
        Vector4 expt(-1.0, 2.0, -1.0);

        
        UnitTest test("Vector Cross Product");
        test.assert_that(res == expt);
 
    }
}

namespace vec_scalar_ops {
    inline void mul() {
        Vector4 v(1.1, 2.2, 3.3);

        Vector4 res =  v * 10.0;
        Vector4 expt(11.0, 22.0, 33.0);

        UnitTest test("Vector Scalar Multiplication");
        test.assert_that(res == expt);
        
    }

    inline void div() {
        Vector4 v(11.0, 22.0, 33.0);

        Vector4 res =   v / 10.0 ;
        Vector4 expt(1.1, 2.2, 3.3);

        UnitTest test("Vector Scalar Division");
        test.assert_that(res == expt);
        
    }
}
