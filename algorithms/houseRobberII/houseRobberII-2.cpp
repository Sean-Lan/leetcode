/**
 *
 * Sean
 * 2017-05-26
 *
 * https://leetcode.com/problems/house-robber-ii/#/description
 *
 * Note: This is an extension of House Robber.
 *
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// different from house-robber-i
// we rob in *two* pass:
// 1. skip first one
// 2. skip last one
class Solution {
    int rob(vector<int>& nums, int start, int end) {
        int rob = nums[start];
        int skip = 0;
        int lastRob;
        for (int i=start+1; i<=end; ++i) {
            lastRob = rob;
            rob = skip + nums[i];
            skip = max(skip, lastRob);
        }
        return max(rob, skip);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }
};

int main() {
    return 0;
}
