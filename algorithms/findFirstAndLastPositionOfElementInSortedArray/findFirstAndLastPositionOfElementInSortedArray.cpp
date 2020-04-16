/**
 *
 * Sean
 * 2020-04-16
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
 *
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */
#include <vector>
#include <functional>

using namespace std;

class Solution {
    // FFFTT, find 1st T
    int bs(int s, int e, function<bool(int)> p) {
        while (s < e) {
            int m = s + (e-s)/2;
            if (p(m)) {
                e = m;
            } else {
                s = m+1;
            }
        }
        return s;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> notFoundRes = {-1, -1};
        if (nums.empty()) return notFoundRes;

        int s = bs(0, nums.size()-1, [&] (int x) {
            return nums[x] >= target;
        });

        if (nums[s] != target) return notFoundRes;

        int e = bs(s, nums.size()-1, [&] (int x) {
            return nums[x] > target;
        });
        if (nums[e] == target) return {s, e};
        return {s, e-1};
    }
};

int main() {
  return 0;
}
