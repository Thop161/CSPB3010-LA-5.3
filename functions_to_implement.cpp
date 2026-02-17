/**
 * Tyler Hopkins
 * LA 5.2 - Catch2 Unit Testing
 * This file contains implementations of various string and vector manipulation functions.
 * These functions are tested using the Catch2 testing framework in test.cpp.
 */

#include <iostream>
#include <vector>
#include <string>
/* String functions section */

// Splits a single string on separator into a vector of strings
std::vector<std::string> Split(std::string whole, std::string separator);

// takes two strings and returns a new string that is the result of removing all occurrences of s2 from s1.
std::string RemoveAllSubstrings(std::string s1, std::string s2);

// takes two strings and returns a new string that is the result of removing the first occurrence of s2 from s1.
std::string RemoveFirstSubstring(std::string s1, std::string s2);


/* Vector functions section */

// Joins all strings in a vector together, using the glue string in between them
std::string Join(std::vector<std::string> pieces, std::string glue);

// takes two vectors of integers, a and b. The function then removes elements from a if they are also in b.
// If the integer is in b, but not in a, nothing happens.
std::vector<int> MatchVectors(std::vector<int> a, std::vector<int> b);

// divides an input integer by 2 until it is impossible to do so, then returns the final number.
// (16 = 2 * 2 * 2 * 2 * 1 -> 1, 7 -> 7, 26 = 2 * 13 -> 13, 52 = 2 * 2 * 13 -> 13)
int RemoveTwos(int original);

// takes a vector of integers and removes all elements evenly divisible by the passed in int
std::vector<int> MultiplesFilter(std::vector<int>, int divides_by);

// returns a vector with true for even numbers and false for odd numbers
std::vector<bool> EvenMask(std::vector<int>);

// returns a vector with true for odd numbers and false for even numbers
std::vector<bool> OddMask(std::vector<int>);

// Sums all numbers in a vector and returns the resulting value
int Sum(std::vector<int> nums);

// Multiplies all numbers in a vector together and returns the resulting value
int Product(std::vector<int> nums);

// Adds an integer n to each element of a given vector
std::vector<int> VectorPlusN(std::vector<int> v, int n);

// Multiples an integer n with each element of a given vector
std::vector<int> VectorTimesN(std::vector<int> v, int n);

// takes in two integers and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<int> Multiples(int n, int m);

// takes an integer n that is >= 0 and returns a vector of all squares up to n^n (1^1, 2^2, 3^3, .... n^n)
std::vector<int> SquaresUntil(int n);

// takes an int, n, and returns the nth value of the fibonacci sequence (1, 1, 2, 3, 5, 8, 13, ...)
int NthFibonacci(int n);

// returns -1 if the number is negative and 1 if positive
int Sign(int num);

// takes two vectors of doubles, a and b. The function then removes elements from a if they are also in b.
// If the double is in b, but not in a, nothing happens.
std::vector<double> MatchVectors(std::vector<double> a, std::vector<double> b);

// takes a vector of doubles and removes all elements evenly divisible by the passed in double
std::vector<double> MultiplesFilter(std::vector<double>, double divides_by);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<double> nums, double greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<double> nums, double less_than);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<int> nums, int greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<int> nums, int less_than);

// Sums all numbers in a vector and returns the resulting value
double Sum(std::vector<double> nums);

// Multiplies all numbers in a vector together and returns the resulting value
double Product(std::vector<double> nums);

// Adds an double n to each element of a given vector
std::vector<double> VectorPlusN(std::vector<double> v, double n);

// Multiples an double n with each element of a given vector
std::vector<double> VectorTimesN(std::vector<double> v, double n);

// takes in two doubles and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<double> Multiples(double n, double m);

// returns -1 if the number is negative and 1 if positive
double Sign(double num);

// adds n to each element of the vector
std::vector<double> AddN(std::vector<double>, double n);

// adds n to each element of the vector
std::vector<std::string> AddN(std::vector<std::string>, std::string n);

// subtracts n to each element of the vector
std::vector<int> SubtractN(std::vector<int>, int n);

// subtracts n to each element of the vector
std::vector<double> SubtractN(std::vector<double>, double n);

// ====================================================================

/**
 * Computes the factorial of a given integer using recursion.
 *
 * @param n The integer to compute the factorial of (n!)
 * @return The factorial of n (n!)
 */
int Factorial(int n)
{
	if(n>1)
		return n*Factorial(n-1);
	else
		return 1;
}

/**
 * Adds a value n to each element in the vector.
 *
 * @param v The vector of integers to modify
 * @param n The value to add to each element
 * @return A new vector with n added to each element
 */
std::vector<int> AddN(std::vector<int> v, int n)
{
	for(int i=0;i<(int)v.size();i++)
	{
		v[i]+=n;
	}
	return v;
}

// ====================================================================

/**
 * Removes all occurrences of substring s2 from string s1.
 *
 * @param s1 The string to remove substrings from
 * @param s2 The substring to remove from s1
 * @return A new string with all occurrences of s2 removed
 */
std::string RemoveAllSubstrings(std::string s1, std::string s2)
{
	size_t pos = s1.find(s2);
	while(pos != std::string::npos)
	{
		s1.erase(pos, s2.length());
		pos = s1.find(s2);
	}
	return s1;
}

/**
 * Joins all strings in a vector together using a glue string between them.
 *
 * @param pieces The vector of strings to join
 * @param glue The string to insert between each element
 * @return A single concatenated string with glue between elements
 */
std::string Join(std::vector<std::string> pieces, std::string glue)
{
	if(pieces.empty())
		return "";

	std::string result = pieces[0];
	for(size_t i = 1; i < pieces.size(); i++)
	{
		result += glue + pieces[i];
	}
	return result;
}

/**
 * Sums all integers in a vector.
 *
 * @param nums The vector of integers to sum
 * @return The sum of all elements in the vector
 */
int Sum(std::vector<int> nums)
{
	int sum = 0;
	for(int num : nums)
	{
		sum += num;
	}
	return sum;
}

/**
 * Multiplies all integers in a vector together.
 *
 * @param nums The vector of integers to multiply
 * @return The product of all elements in the vector, or 0 if empty
 */
int Product(std::vector<int> nums)
{
	if(nums.empty())
		return 0;

	int product = 1;
	for(int num : nums)
	{
		product *= num;
	}
	return product;
}

/**
 * Creates a boolean mask where true indicates even numbers.
 *
 * @param nums The vector of integers to process
 * @return A vector of booleans, true for even numbers, false for odd
 */
std::vector<bool> EvenMask(std::vector<int> nums)
{
	std::vector<bool> mask;
	for(int num : nums)
	{
		mask.push_back(num % 2 == 0);
	}
	return mask;
}

/**
 * Filters out elements from a vector that are evenly divisible by divides_by.
 *
 * @param v The vector of integers to filter
 * @param divides_by The divisor to check against
 * @return A new vector containing only elements not divisible by divides_by
 */
std::vector<int> MultiplesFilter(std::vector<int> v, int divides_by)
{
	std::vector<int> result;
	for(int num : v)
	{
		if(num % divides_by != 0)
		{
			result.push_back(num);
		}
	}
	return result;
}

// ====================================================================
