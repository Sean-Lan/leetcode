/**
 *
 * Sean
 * 2016-03-07
 *
 * https://leetcode.com/problems/jump-game/
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Gready. maxLength records the max steps can go.
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if (nums.empty()) return true;
            int lastIndex = nums.size()-1;
            int maxLength = 0;
            for (int i=0; maxLength < lastIndex && i<=maxLength; ++i) {
                maxLength = max(maxLength, i+nums[i]);
            }
            return maxLength>=lastIndex;
        }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution solution;
    cout << solution.canJump(nums) << endl;

    nums = {3,2,1,0,4};
    cout << solution.canJump(nums) << endl;
}
