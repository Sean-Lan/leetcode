/**
 *
 * Sean
 * 2017-09-01
 *
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 */
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

// typical bs
// note the hack in predicate for n
class Solution {
    // FFFFTTTT
    int bs(int s, int e, function<bool(int)> p) {
        int m;
        while (s < e) {
            m = s + (e-s)/2;
            if (p(m))
                e = m;
            else
                s = m+1;
        }
        return s;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int n = nums.size();

        int lo = bs(0, n, [&](int x) {
            if (x >= n) return true;
            return nums[x] >= target;
        });

        if (lo == n || nums[lo] != target) return {-1, -1};
        int hi = bs(lo, n, [&](int x) {
            if (x >= n) return true;
            return nums[x] > target;
        });
        return {lo, hi-1};
    }
};

int main() {
    return 0;
}
