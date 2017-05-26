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

// Only 3 cases need to be considered
// rob first and skip last
// skip first and rob last
// skip both first and last
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int res = 0;
        // rob first, skip last
        int rob = 0;
        int skip = 0;
        int lastRob;
        for (int i=2; i<n-1; ++i) {
            lastRob = rob;
            rob = skip + nums[i];
            skip = max(skip, lastRob);
        }
        res = nums[0] + max(rob, skip);

        // skip first, rob last
        rob = nums[1];
        skip = 0;
        for (int i=2; i<n-1; ++i) {
            lastRob = rob;
            rob = skip + nums[i];
            skip = max(skip, lastRob);
        }
        res = max(res, skip + nums[n-1]);

        // skip both first and last
        rob = nums[1];
        skip = 0;
        for (int i=2; i<n-1; ++i) {
            lastRob = rob;
            rob = skip + nums[i];
            skip = max(skip, lastRob);
        }
        res = max(res, max(rob, skip));
        return res;
    }
};

int main() {
    return 0;
}

