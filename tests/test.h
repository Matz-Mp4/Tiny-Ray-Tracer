#pragma once
#include <string>

class UnitTest {
public:
    std::string& name();
    UnitTest(std::string name) : test_name(name){};
    void assert_that(bool statement);

private:
    std::string test_name;
};
