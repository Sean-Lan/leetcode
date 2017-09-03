/**
 *
 * Sean
 * 2017-09-03
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
 *
 * You need to return the number of important reverse pairs in the given array.
 *
 * Example1:
 *
 * Input: [1,3,2,3,1]
 * Output: 2
 * Example2:
 *
 * Input: [2,4,3,5,1]
 * Output: 3
 * Note:
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// divide and conquer
class Solution {
    int mergeCount(vector<int> &nums, int s, int e) {
        if (s >= e) return 0;
        int m = s + (e-s)/2;
        int cnt = mergeCount(nums, s, m) + mergeCount(nums, m+1, e);

        // count
        int i = s, j = m+1;
        while (i<=m && j<=e) {
            long long important = 2L * nums[j];
            while (i<=m && nums[i]<=important) ++i;
            cnt += m-i+1;
            ++j;
        }

        // merge
        vector<int> backup;
        i = s, j = m+1;

        while (i<=m && j<=e) {
            if (nums[i] <= nums[j]) backup.push_back(nums[i++]);
            else backup.push_back(nums[j++]);
        }

        while (i<=m) backup.push_back(nums[i++]);

        while (j<=e) backup.push_back(nums[j++]);

        int n = e-s+1;
        for (int k=0; k<n; ++k) nums[s+k] = backup[k];

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeCount(nums, 0, nums.size()-1);
    }
};

int main() {
    return 0;
}
