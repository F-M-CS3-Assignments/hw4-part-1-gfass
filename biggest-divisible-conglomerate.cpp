#include "bdc.h"
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Converts a vector of integers into a formatted string representation.
 */
string vec_to_string(vector<int> vec) {
    string result = "[";
    for (size_t i = 0; i < vec.size(); i++) {
        result += to_string(vec[i]);
        if (i < vec.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

/**
 * Checks if a given number can be added to the current conglomerate
 * while satisfying the divisibility requirement.
 * 
 * The requirement states that for any two numbers in the conglomerate,
 * the larger number must be evenly divisible by the smaller number (L % S == 0).
 * 
 * @param conglomerate The current set of selected numbers.
 * @param num The number to check for divisibility compatibility.
 * @return True if `num` can be added without breaking the rule, otherwise false.
 */
bool passes_divisibility_check(const vector<int>& conglomerate, int num) {
    for (int element : conglomerate) {
        // If num and element are not divisible by each other, num is not valid
        if (element % num != 0 && num % element != 0) {
            return false; 
        }
    }
    return true; // If all elements satisfy divisibility, num is valid
}

/**
 * Recursively finds the largest valid divisible conglomerate from the given list.
 * 
 * @param input The original list of numbers.
 * @param curr The current conglomerate being built.
 * @param idx The current index in the input list being considered.
 * @return The largest valid conglomerate found.
 */
vector<int> find_conglomerate(vector<int>& input, vector<int> curr, size_t idx) {
    // Base case: If we have checked all numbers, return the current conglomerate
    if (idx == input.size()) {
        return curr;
    }

    // Case 1: Try including input[idx] if it maintains divisibility
    vector<int> newConglomerate = curr;
    if (passes_divisibility_check(curr, input[idx])) {
        newConglomerate.push_back(input[idx]);
    }

    // Recursive call: Explore both possibilities - with and without the current number
    vector<int> withCurr = find_conglomerate(input, newConglomerate, idx + 1);
    vector<int> withoutCurr = find_conglomerate(input, curr, idx + 1);

    // Return the larger of the two conglomerates
    return (withCurr.size() > withoutCurr.size()) ? withCurr : withoutCurr;
}

/**
 * Finds the biggest divisible conglomerate from a given list of numbers.
 * 
 * The function recursively explores all possible subsets that satisfy 
 * the divisibility rule and returns the largest valid subset.
 * 
 * If no valid subset larger than one number exists, the function returns
 * either the smallest or largest number in the input, as per instructions.
 * 
 * @param input A list of numbers (assumed to be unique, positive integers).
 * @return The largest valid conglomerate found.
 */
vector<int> biggest_divisible_conglomerate(vector<int> input) {
    if (input.empty()) return {}; // If input is empty, return an empty list

    // Reverse the input to prioritize checking larger numbers first
    reverse(input.begin(), input.end());

    // Find the best conglomerate using recursion
    vector<int> candidate = find_conglomerate(input, {}, 0);
    
    if (candidate.size() > 1) {
        return candidate; // Return valid conglomerate if it exists
    }

    // If no valid conglomerate is found, return the smallest number
    int smallest = *min_element(input.begin(), input.end());
    return {smallest}; // Per instructions, returning either largest or smallest is valid
}