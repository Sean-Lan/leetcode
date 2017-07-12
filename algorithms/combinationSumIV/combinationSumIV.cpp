/**
 *
 * Sean
 * 2017-07-12
 *
 * https://leetcode.com/problems/combination-sum-iv/#/description
 *
 * Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
 *
 * Example:
 *
 * nums = [1, 2, 3]
 * target = 4
 *
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 *
 * Note that different sequences are counted as different combinations.
 *
 * Therefore the output is 7.
 *
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// top-down DP
// dp[i] = sum(dp[i-num]), for all number num in numbers where num <= i
class Solution {
    vector<int> cache;
    int helper(vector<int> &nums, int target) {
        if (cache[target] != -1) return cache[target];
        cache[target] = 0;
        for (auto &i : nums) {
            if (i <= target) {
                cache[target] += helper(nums, target-i);
            }
        }
        return cache[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 0;

        cache = vector<int>(target+1, -1);
        cache[0] = 1;

        helper(nums, target);
        return this->cache[target];
    }
};

int main() {
    return 0;
}
