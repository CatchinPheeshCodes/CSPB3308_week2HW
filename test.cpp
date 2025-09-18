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

TEST_CASE("removing string 2 from string 1", "[RemoveFirstSubstring]")
{
	std::string s1 = "The second cow jumped over the moon after the first cow.";
	std::string s2 = "cow";
	s1 = RemoveFirstSubstring(s1, s2);
	CHECK(s1 == "The second  jumped over the moon after the first cow.");
}

TEST_CASE("subtracting n from integer vector", "[SubtractN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = SubtractN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]-n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = SubtractN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]-n);
	}
}

TEST_CASE("checking sign of return value", "[Sign]")
{
	double d1 = 1.5;
	double d2 = -1.5;
	REQUIRE(Sign(d1) == 1);
	REQUIRE(Sign(d2) == -1);
}

TEST_CASE("checking product of vector variables", "[Product]")
{
	std::vector<double> v{1, 2, 3, 4, 5};
	REQUIRE(Product(v) == 120);
}