#define CATCH_CONFIG_MAIN 

#include "catch.hpp"
#include <string>

TEST_CASE("Example") {

	int expectedIntValue = 10;
	int actualIntValue = 1;
	
	CHECK( actualIntValue == expectedIntValue );
	CHECK( expectedIntValue == actualIntValue );
	CHECK( actualIntValue == 20 );
	CHECK( 20 == actualIntValue);
	
	std::string expectedStrValue = "2020 will be a great year";
	std::string actualStrValue = "NOOOO I DONT WANT TO DIE";
	
	CHECK( actualStrValue == expectedStrValue );
	CHECK( expectedStrValue == actualStrValue );
	CHECK( actualStrValue == "RIP AND TEAR" );
	CHECK( "UNTIL IT IS DONE" == actualStrValue );
}
