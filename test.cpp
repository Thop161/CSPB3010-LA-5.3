/**
 * Tyler Hopkins
 * LA 5.2 - Catch2 Unit Testing
 * This file contains unit tests for various string and vector manipulation functions.
 * Uses the Catch2 testing framework to verify function correctness.
 * Run the compiled executable to execute all tests.
 */

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

TEST_CASE("RemoveAllSubstrings removes all occurrences", "[removeallsubstrings]")
{
	SECTION("removing simple substring")
	{
		std::string s1 = "hello world hello";
		std::string s2 = "hello";
		std::string result = RemoveAllSubstrings(s1, s2);
		REQUIRE(result == " world ");
	}

	SECTION("removing substring that doesn't exist")
	{
		std::string s1 = "hello world";
		std::string s2 = "xyz";
		std::string result = RemoveAllSubstrings(s1, s2);
		REQUIRE(result == "hello world");
	}

	SECTION("removing multiple occurrences")
	{
		std::string s1 = "aaabbbaaacccaaa";
		std::string s2 = "aaa";
		std::string result = RemoveAllSubstrings(s1, s2);
		REQUIRE(result == "bbbccc");
	}

	SECTION("removing entire string")
	{
		std::string s1 = "test";
		std::string s2 = "test";
		std::string result = RemoveAllSubstrings(s1, s2);
		REQUIRE(result == "");
	}
}

TEST_CASE("Join concatenates strings with glue", "[join]")
{
	SECTION("joining with space")
	{
		std::vector<std::string> pieces{"hello", "world", "test"};
		std::string result = Join(pieces, " ");
		REQUIRE(result == "hello world test");
	}

	SECTION("joining with comma")
	{
		std::vector<std::string> pieces{"apple", "banana", "cherry"};
		std::string result = Join(pieces, ", ");
		REQUIRE(result == "apple, banana, cherry");
	}

	SECTION("joining empty vector")
	{
		std::vector<std::string> pieces;
		std::string result = Join(pieces, " ");
		REQUIRE(result == "");
	}

	SECTION("joining single element")
	{
		std::vector<std::string> pieces{"only"};
		std::string result = Join(pieces, "-");
		REQUIRE(result == "only");
	}

	SECTION("joining with empty glue")
	{
		std::vector<std::string> pieces{"a", "b", "c"};
		std::string result = Join(pieces, "");
		REQUIRE(result == "abc");
	}
}

TEST_CASE("Sum adds all integers in vector", "[sum]")
{
	SECTION("summing positive numbers")
	{
		std::vector<int> nums{1, 2, 3, 4, 5};
		REQUIRE(Sum(nums) == 15);
	}

	SECTION("summing negative numbers")
	{
		std::vector<int> nums{-1, -2, -3};
		REQUIRE(Sum(nums) == -6);
	}

	SECTION("summing mixed numbers")
	{
		std::vector<int> nums{-5, 10, -3, 8};
		REQUIRE(Sum(nums) == 10);
	}

	SECTION("summing empty vector")
	{
		std::vector<int> nums;
		REQUIRE(Sum(nums) == 0);
	}

	SECTION("summing single element")
	{
		std::vector<int> nums{42};
		REQUIRE(Sum(nums) == 42);
	}
}

TEST_CASE("Product multiplies all integers in vector", "[product]")
{
	SECTION("multiplying positive numbers")
	{
		std::vector<int> nums{2, 3, 4};
		REQUIRE(Product(nums) == 24);
	}

	SECTION("multiplying with zero")
	{
		std::vector<int> nums{2, 0, 5};
		REQUIRE(Product(nums) == 0);
	}

	SECTION("multiplying negative numbers")
	{
		std::vector<int> nums{-2, 3, -4};
		REQUIRE(Product(nums) == 24);
	}

	SECTION("multiplying empty vector")
	{
		std::vector<int> nums;
		REQUIRE(Product(nums) == 0);
	}

	SECTION("multiplying single element")
	{
		std::vector<int> nums{7};
		REQUIRE(Product(nums) == 7);
	}
}

TEST_CASE("EvenMask returns true for even numbers", "[evenmask]")
{
	SECTION("testing mixed even and odd")
	{
		std::vector<int> nums{1, 2, 3, 4, 5, 6};
		std::vector<bool> result = EvenMask(nums);
		REQUIRE(result.size() == 6);
		REQUIRE(result[0] == false);  // 1 is odd
		REQUIRE(result[1] == true);   // 2 is even
		REQUIRE(result[2] == false);  // 3 is odd
		REQUIRE(result[3] == true);   // 4 is even
		REQUIRE(result[4] == false);  // 5 is odd
		REQUIRE(result[5] == true);   // 6 is even
	}

	SECTION("testing all even")
	{
		std::vector<int> nums{2, 4, 6, 8};
		std::vector<bool> result = EvenMask(nums);
		for(bool val : result)
		{
			REQUIRE(val == true);
		}
	}

	SECTION("testing all odd")
	{
		std::vector<int> nums{1, 3, 5, 7};
		std::vector<bool> result = EvenMask(nums);
		for(bool val : result)
		{
			REQUIRE(val == false);
		}
	}

	SECTION("testing with zero")
	{
		std::vector<int> nums{0};
		std::vector<bool> result = EvenMask(nums);
		REQUIRE(result[0] == true);  // 0 is even
	}

	SECTION("testing empty vector")
	{
		std::vector<int> nums;
		std::vector<bool> result = EvenMask(nums);
		REQUIRE(result.empty());
	}
}

TEST_CASE("MultiplesFilter removes divisible elements", "[multiplesfilter]")
{
	SECTION("filtering multiples of 2")
	{
		std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
		std::vector<int> result = MultiplesFilter(nums, 2);
		std::vector<int> expected{1, 3, 5, 7};
		REQUIRE(result == expected);
	}

	SECTION("filtering multiples of 3")
	{
		std::vector<int> nums{1, 2, 3, 4, 5, 6, 9, 12};
		std::vector<int> result = MultiplesFilter(nums, 3);
		std::vector<int> expected{1, 2, 4, 5};
		REQUIRE(result == expected);
	}

	SECTION("filtering multiples of 5")
	{
		std::vector<int> nums{5, 10, 15, 20, 7, 13};
		std::vector<int> result = MultiplesFilter(nums, 5);
		std::vector<int> expected{7, 13};
		REQUIRE(result == expected);
	}

	SECTION("no multiples to filter")
	{
		std::vector<int> nums{1, 3, 5, 7};
		std::vector<int> result = MultiplesFilter(nums, 2);
		REQUIRE(result == nums);
	}

	SECTION("all multiples filtered")
	{
		std::vector<int> nums{2, 4, 6, 8};
		std::vector<int> result = MultiplesFilter(nums, 2);
		REQUIRE(result.empty());
	}

	SECTION("filtering empty vector")
	{
		std::vector<int> nums;
		std::vector<int> result = MultiplesFilter(nums, 2);
		REQUIRE(result.empty());
	}
}
