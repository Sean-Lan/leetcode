/**
 *
 * Sean
 * 2017-08-22
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 */
#include <vector>
using namespace std;

// O(n): |state| = n, O(trans) = c
// top-down dp
class Solution {
    vector<int> cache;
    int solve(int i, vector<int> &nums) {
        if (i >= nums.size()) return 0;
        if (cache[i] >= 0) return cache[i];
        return cache[i] = max(
            nums[i] + solve(i+2, nums),
            solve(i+1, nums)
        );
    }
public:
    int rob(vector<int>& nums) {
        cache = vector<int>(nums.size(), -1);
        return solve(0, nums);
    }
};

int main() {
    return 0;
}
