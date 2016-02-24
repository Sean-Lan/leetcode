/**
 *
 * Sean
 * 2016-02-24
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// First find the pivot position, then perform two binary search.
class Solution {
    private:
        typedef vector<int>::iterator IT;
        IT pivotPosition(IT begin, IT end) {
            if (begin == end || begin+1 == end)
                return end;
            IT first = begin;
            IT last = end-1;
            if (*first < *last)
                return end;
            IT mid = first + (last-first)/2+1;
            IT result = pivotPosition(begin, mid);
            if (result != mid)
                return result;
            result = pivotPosition(mid, end);
            if (result != end)
                return result;
            if (*(mid-1) > *mid)
                return mid;
            return end;
        }

    public:
        int search(vector<int>& nums, int target) {
            if (nums.empty()) return -1;
            // first find the first out of order postion.
            IT pivot = pivotPosition(nums.begin(), nums.end());
            IT lower = lower_bound(nums.begin(), pivot, target);
            if (lower!=pivot && *lower==target)
                return lower-nums.begin();
            lower = lower_bound(pivot, nums.end(), target);
            if (lower!=nums.end() && *lower==target)
                return lower-nums.begin();
            return -1;
        }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution solution;
    cout << solution.search(nums, 4) << endl;
    cout << solution.search(nums, 3) << endl;
    cout << solution.search(nums, 7) << endl;
    cout << solution.search(nums, 2) << endl;
    cout << solution.search(nums, 9) << endl;
    cout << solution.search(nums, 0) << endl;
}
