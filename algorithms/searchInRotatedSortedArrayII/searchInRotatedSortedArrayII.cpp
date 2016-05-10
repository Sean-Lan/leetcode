/**
 *
 * Sean
 * 2016-05-10
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 *
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// O(n) solution
class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int size = nums.size();
            for (int i=0; i<size; ++i) {
                if (nums[i] == target)
                    return true;
            }
            return false;
        }
};

int main() {}
