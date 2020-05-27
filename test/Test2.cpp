#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

TEST_CASE("Test2") {
    int trueNumber = 21;
    int FalseNumber = -21;
    std::string notNumber = "twenty one";
    std::string numberToo = "21";
    int checkNumber = atoi(numberToo.c_str());
    
    CHECK(trueNumber == FalseNumber);
    CHECK(trueNumber == checkNumber);
    CHECK(FalseNumber == trueNumber);
    CHECK(FalseNumber == checkNumber);
    CHECK(checkNumber == trueNumber);
    CHECK(checkNumber == FalseNumber);
    CHECK(notNumber == numberToo);

}
