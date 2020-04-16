/**
 *
 * Sean
 * 2020-04-16
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
#include <vector>
using namespace std;

// basically the same idea as solution 1, just more generalized.
// First find the pivot position, then perform two binary search.
class Solution {
    // FFFFTTT
    // * T might not show in the range, in this case `end` will be returned
    int firstTrue(int start, int end, function<bool(int)> p) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (p(mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int n = nums.size();
        int idx = -1;
        if (n == 1) {
            if (nums[0] == target) return 0;
            return -1;
        }
        auto geTarget = [&] (int x) {
            return nums[x] >= target;
        };

        // if it's sorted, pivot will be n-1
        int pivot = firstTrue(0, n-1, [&] (int x){
            return nums[x] < nums[0];
        });

        // left part

        idx = firstTrue(0, pivot-1, geTarget);

        if (nums[idx] == target) return idx;

        // right part
        idx = firstTrue(pivot, n-1, geTarget);

        if (nums[idx] == target) return idx;

        return -1;
    }
};

int main() {
  return 0;
}
