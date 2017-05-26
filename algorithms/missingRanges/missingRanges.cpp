/**
 *
 * Sean
 * 2017-05-26
 *
 * https://leetcode.com/problems/missing-ranges/#/description
 *
 * Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
 *
 * For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// note: i+1 may greater the INT_MAX, using long long instead
class Solution {
    string getRange(int start, int end) {
        if (start == end) return to_string(start);
        return to_string(start) + "->" + to_string(end);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long long next = lower;
        vector<string> res;
        for (auto &i : nums) {
            if (i < next) continue;
            if (i != next)
                res.push_back(getRange(next, i-1));
            next = (long long)i+1;
        }
        if (next <= upper) {
            res.push_back(getRange(next, upper));
        }
        return res;
    }
};

int main() {
    return 0;
}
