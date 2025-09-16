#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}

}

TEST_CASE ( "Split string on separator", "[splitString]") // tag
{
  REQUIRE( Split("ban,app", ",") == std::vector<std::string>{"ban", "app"} ); // assertion
  REQUIRE(Split("banana,apple,orange,cherry", ",") == std::vector<std::string>{"banana", "apple", "orange", "cherry"} );
  REQUIRE(Split("1,2,3,4,5,6,7,8,9,0", ",") == std::vector<std::string>{"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"} );
  REQUIRE(Split("ban,bapp", "b") == std::vector<std::string>{"an,", "app"} );
//   REQUIRE(Split("ban,app", ",") == std::vector<std::string>{"ban", "app"} );
}

TEST_CASE ( "Join pieces with glue", "[gluePieces]") // tag
{
  REQUIRE( Join({"ban", "app"}, ",") == std::string{"ban,app"} ); // assertion
  REQUIRE( Join({"banana", "apple", "orange", "cherry"}, ",") == std::string{"banana,apple,orange,cherry"} );
  REQUIRE( Join({"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"}, ",") == std::string{"1,2,3,4,5,6,7,8,9,0"} );
  REQUIRE( Join({"an,", "app"}, "b") == std::string{"an,bapp"} );
}

TEST_CASE ( "Divide by 2", "[divideTwo]") // tag
{
  REQUIRE( RemoveTwos(17) == int{17} ); // assertion
  REQUIRE( RemoveTwos(20) == int{5} );
  REQUIRE( RemoveTwos(66) == int{33} );
  REQUIRE( RemoveTwos(14) == int{7} );
}

TEST_CASE ( "Product of vector", "[vectorProduct]") // tag
{
  REQUIRE( Product(std::vector<int>{1,2,3,4,5}) == int{120} ); // assertion
  REQUIRE( Product(std::vector<int>{5,4}) == int{20} ); // assertion
  REQUIRE( Product(std::vector<int>{1,1,1,1,1}) == int{1} ); // assertion
  REQUIRE( Product(std::vector<int>{0,3,45}) == int{0} ); // assertion
}
