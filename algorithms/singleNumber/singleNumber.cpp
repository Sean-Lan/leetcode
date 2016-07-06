/**
 *
 * Sean
 * 2016-07-06
 *
 * https://leetcode.com/problems/single-number/
 *
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Using XOR
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            return accumulate(nums.begin(), nums.end(), 0,
                    [](int &a, int &b) {
                    return a^b;
                    });
        }
};

int main() {
}
