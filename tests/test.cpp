#include "test.h"
#include <iostream>
#include <string>

std::string& UnitTest::name() {
    return test_name;
}

void UnitTest::assert_that(bool statement) {
    std::string res_mes = "OK";
    if (!statement) {
      res_mes = "FAILED";
    }
    std::cout << "[Test: " << test_name << "] =====> " << res_mes << "\n";
}
