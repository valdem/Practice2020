#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

TEST_CASE("Test0") {

    int expectedIntValue = 10;
    int actualIntValue = 13;
    
    CHECK( actualIntValue == expectedIntValue );
    CHECK( expectedIntValue == actualIntValue );
    CHECK( actualIntValue == 13 );
    CHECK( 10 == expectedIntValue);
    
    std::string expectedStrValue = "Check for testers";
    std::string actualStrValue = "Check for testers 2";
    
    CHECK( actualStrValue == expectedStrValue );
    CHECK( expectedStrValue == actualStrValue );
    CHECK( expectedStrValue == "Check for testers" );
    CHECK( "UNTIL IT IS DONE" == actualStrValue );
}

TEST_CASE("Test1") {
    long long int array[10];
    for (size_t i = 0; i<10; i++) {
        array[i] = i*i;
    }
    long long int array2[10];
    size_t j = 0;
    for (size_t i = 10; i<18; i++, j++) {
        array2[j] = i*i;
    }
    array2[8] = 0;
    CHECK(array[9] == 81);
    CHECK(array2[9] == 361);
    CHECK(array2[8] == array[0]);
}
