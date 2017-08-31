/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
 *
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 *
 * Example 1:
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first
 * 4
 * to
 * 1
 * to get a non-decreasing array.
 *
 * Example 2:
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one element.
 * Note: The n belongs to [1, 10,000].
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// O(n)
// use `h` to keep the current height of increasing array, when meet a number `nums[i]` < `h`, try to make `h` as small as possible:
// 1. change nums[i] to h: i > 1 && nums[i-2] > nums[i]
// 2. change h to nums[i]: i==1 || nums[i-2] <= nums[i]
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int h = nums[0];
        int n = nums.size();
        bool changed = false;
        for (int i=1; i<n; ++i) {
            if (nums[i] < h) {
                if (changed) return false;
                if (i == 1 || nums[i-2] <= nums[i]) h = nums[i];
                changed = true;
            } else {
                h = nums[i];
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
