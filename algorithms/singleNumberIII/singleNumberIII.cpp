/**
 *
 * Sean
 * 2016-12-14
 *
 * https://leetcode.com/problems/single-number-iii/
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 *
 * For example:
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 *
 */
#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> singleNumber(vector<int>& nums) {
            int xorValue = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
            int mask = xorValue & (-xorValue);

            int a = 0;
            for (auto &i : nums)
                if (i & mask) a ^=i;
            int b = xorValue ^ a;
            return {a, b};
        }
};

int main() {}
