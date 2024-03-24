#include "../src/math/vector3D.h"
#include "test.h"

namespace vec_normal_ops {

    inline void add() {
        Vector3D u(1.0, 2.0, 3.0);
        Vector3D v(3.0, 2.0, 1.0);

        Vector3D res = u + v;
        Vector3D expt(4.0, 4.0, 4.0);
        
        UnitTest test("Vector Addition");
        test.assert_that(res == expt);
    }

    inline void sub() {

        Vector3D v(1.0, 2.0, 3.0);
        Vector3D t(5.0, 6.0, 7.0);
        Vector3D res = v - t;
        Vector3D expt(-4.0, -4.0, -4.0);

        UnitTest test("Vector Subtration");
        test.assert_that(res == expt );
    }
    
    inline void mul() {
        Vector3D v(1.0, 2.0, 3.0);

        Vector3D res = v * 10.0;
        Vector3D expt(10.0, 20.0, 30.0);

        
        UnitTest test("Vector Multiplication");
        test.assert_that(res == expt);
    }
    inline void dot_product() {
        Vector3D u(1.0, 2.0, 3.0);
        Vector3D v(2.0, 3.0, 4.0);
        
        double res = dot(u, v);
        double expt = 20.0;

        
        UnitTest test("Vector Dot Product");
        test.assert_that(res == expt);

    }

    inline void cross_prod() {
        Vector3D u(1.0, 2.0, 3.0);
        Vector3D v(2.0, 3.0, 4.0);
        
        Vector3D res = cross(u, v);
        Vector3D expt(-1.0, 2.0, -1.0);

        
        UnitTest test("Vector Cross Product");
        test.assert_that(res == expt);
 
    }
}

namespace vec_scalar_ops {
    inline void mul() {
        Vector3D v(1.1, 2.2, 3.3);

        Vector3D res = v * 10.0;
        Vector3D expt(11.0, 22.0, 33.0);
         
        UnitTest test("Vector Scalar Multiplication");
        test.assert_that(res == expt);
        
    }

    inline void div() {
        Vector3D v(10.0, 20.0, 30.0);

        Vector3D res = v / 10.0;
        Vector3D expt(1.0, 2.0, 3.0);

        UnitTest test("Vector Scalar Division");
        test.assert_that(res == expt);
        
    }
}
