/* #include "src/math/vector3D.h" */
#include <stdexcept>
#include "../src/math/vector3D.h"

constexpr void assert_that(bool statement, const char* message) {
    if (!statement) throw std::runtime_error{ message }; 
}

namespace scalar_ops {
    void mul() {
        Vector3D v(1.1, 2.2, 3.3);

        Vector3D res = v * 10.0;
        Vector3D expt(11.0, 22.0, 33.0);
        
        assert_that(res == expt, "Scalar Multiplication Failed!");
    }

    void div() {
        Vector3D v(10.0, 20.0, 30.0);

        Vector3D res = v / 10.0;
        Vector3D expt(1.0, 2.0, 3.0);
        
        assert_that(res == expt, "Scalar Division Failed!");
    }
}
  
