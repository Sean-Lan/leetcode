/**
 *
 * Sean
 * 2016-11-24
 *
 * https://leetcode.com/problems/move-zeroes/
 *
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 * Credits:
 *
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
            int cur = 0;
            for (int i=0; i<n; ++i) {
                if (nums[i] != 0)
                    nums[cur++] = nums[i];
            }
            while (cur < n) nums[cur++] = 0;
        }
};

int main() {
    return 0;
}
