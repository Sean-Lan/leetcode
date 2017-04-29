/**
 *
 * Sean
 * 2017-04-29
 *
 * https://leetcode.com/problems/search-insert-position/#/description
 *
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// typical binary search problem.
// find the first one where the predicate returns true
class Solution {
    // 0 0 0 .. 0 1 1
    int bs(int s, int e, function<bool(int)> f) {
        int m;
        while (s <e) {
            m = s + (e-s)/2;
            if (f(m)) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        auto p = [&](int i) {
            if (i >= n) return true;
            return target <= nums[i];
        };
        return bs(0, n, p);
    }
};
