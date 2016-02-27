/**
 *
 * Sean
 * 2016-02-27
 *
 * https://leetcode.com/problems/search-for-a-range/
 * Given a sorted array of integers, find the starting and ending position of a given target value.
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            auto it = lower_bound(nums.begin(), nums.end(), target);
            if (it == nums.end() || *it != target)
                return {-1, -1};
            auto it2 = upper_bound(nums.begin(), nums.end(), target);
            int pos1 = it-nums.begin();
            int pos2 = it2-nums.begin();
            return {pos1, pos2-1};
        }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution solution;
    auto result = solution.searchRange(nums, 8);
    cout << result[0] << " " << result[1] << endl;

    result = solution.searchRange(nums, 4);
    cout << result[0] << " " << result[1] << endl;

    result = solution.searchRange(nums, 10);
    cout << result[0] << " " << result[1] << endl;
}
