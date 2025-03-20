#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);

	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// write your own tests here!

	// Test 3 (empty set)
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {};
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3 == soln);

	// Test 4 (only one number)
	values = {4};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {4};
	set<int> answerSet4(ans.begin(), ans.end());
	assert(answerSet4 == soln);

	// Test 5 (no pairs that satisfy the divisibility requirement)
	values = {7, 11, 17, 3};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> soln1 = {17}; // Largest number
	set<int> soln2 = {3};  // Smallest number
	set<int> answerSet5(ans.begin(), ans.end());
	assert(answerSet5 == soln1 || answerSet5 == soln2);
	

	// Test 6 (all even numbers)
	values = {2, 4, 8, 16, 32, 64};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {64, 32, 16, 8, 4, 2};
	set<int> answerSet6(ans.begin(), ans.end());
	assert(answerSet6 == soln);

	// Test 7 (all odd numbers AND no divisibility)
	values = {3, 5, 7, 9, 11};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {9, 3};
	set<int> answerSet7(ans.begin(), ans.end());
	assert(answerSet7 == soln);

	// Test 8 (List with prime numbers)
	values = {2, 3, 5, 7, 11, 13};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> soln3 = {13};
	set<int> soln4 = {2};
	set<int> answerSet8(ans.begin(), ans.end());
	assert(answerSet8 == soln3 || answerSet8 == soln4);

    // Test 9 (List with large numbers)
	values = {1000000, 500000, 250000, 125000, 62500};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {62500, 125000, 250000, 500000, 1000000};
	set<int> answerSet9(ans.begin(), ans.end());
	assert(answerSet9 == soln);

	// Test 10 (Same List as previous with large numbers but with random prime number)
	values = {1000000, 500000, 13, 250000, 125000, 62500};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {62500, 125000, 250000, 500000, 1000000};
	set<int> answerSet10(ans.begin(), ans.end());
	assert(answerSet10 == soln);

	// Test 11 (Mixed numbers with multiple possible conglomerates)
	values = {12, 24, 36, 48, 72, 144, 5, 10, 20, 40};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> soln5 = {144, 72, 36, 12};
	set<int> soln50 {144, 48, 24, 12};
	set<int> soln6 = {40, 20, 10, 5};
	set<int> answerSet11(ans.begin(), ans.end());
	assert(answerSet11 == soln5 || answerSet11 == soln6 || answerSet11 == soln50);

	// Test 12 (Sequential numbers)
	values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> soln7 = {8, 4, 2, 1};
	set<int> answerSet12(ans.begin(), ans.end());
	assert(answerSet12 == soln7);

	// Test 13 (long chain length)
	values = {1, 2, 4, 8, 16, 32, 64, 128};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {128, 64, 32, 16, 8, 4, 2, 1};
	set<int> answerSet13(ans.begin(), ans.end());
	assert(answerSet13 == soln);

	// Test 14 (mixed large and small nums)
	values = {2, 4, 6, 8, 16, 32, 64, 1000000, 500000, 250000};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {1000000, 64, 32, 16, 8, 4, 2};
	set<int> answerSet14(ans.begin(), ans.end());
	assert(answerSet14 == soln);
   
	
	return 0;
}