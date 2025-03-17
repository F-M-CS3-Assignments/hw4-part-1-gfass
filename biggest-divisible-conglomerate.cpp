#include "bdc.h"
#include <vector>
#include <algorithm>

using namespace std;

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

bool passes_divisibility_check(const vector<int>& conglomerate, int num) {
    for (int element : conglomerate) {
        if (element % num != 0 && num % element != 0) {
            return false; 
        }
    }
    return true;
}

vector<int> find_conglomerate(vector<int>& input, vector<int> curr, int idx) {
    if (idx == input.size()) {
        return curr;
    }

    vector<int> newConglomerate = curr;
    if (passes_divisibility_check(curr, input[idx])) {
        newConglomerate.push_back(input[idx]);
    }

    vector<int> withCurr = find_conglomerate(input, newConglomerate, idx + 1);
    vector<int> withoutCurr = find_conglomerate(input, curr, idx + 1);

    return (withCurr.size() > withoutCurr.size()) ? withCurr : withoutCurr;
}

vector<int> biggest_divisible_conglomerate(vector<int> input) {
    if (input.empty()) return {};

    reverse(input.begin(), input.end());
    vector<int> bestConglomerate;
    
   
    vector<int> candidate = find_conglomerate(input, {}, 0);
    
    if (candidate.size() > 1) {
        return candidate; 
    }

//  int largest = *max_element(input.begin(), input.end());
    int smallest = *min_element(input.begin(), input.end());

    return {smallest}; // or return {largest} (both are correct per the instructions)

    
}