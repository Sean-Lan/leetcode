/**
 *
 * Sean
 * 2017-09-01
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty() || (nums.front()>target && nums.back()<target)) return -1;

        bool inFirst = nums.front() <= target;

        int s = 0, e = nums.size()-1, m;
        while (s < e) {
            m = s + (e-s)/2;
            if (nums[m] < target) {
                if (inFirst) {
                    // nums[m] is in the first half
                    if (nums[m] >= nums.front()) s = m+1;
                    else e = m -1;
                } else {
                    s = m+1;
                }
            } else {
                if (inFirst) {
                    e = m;
                } else {
                    // nums[m] is in the first half
                    if (nums[m] >= nums.front()) s = m+1;
                    else e = m;
                }
            }
        }
        return (nums[s] == target) ? s : -1;
    }
};

int main() {
    return 0;
}
