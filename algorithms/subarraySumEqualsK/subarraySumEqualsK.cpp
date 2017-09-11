/**
 *
 * Sean
 * 2017-09-11
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 * Note:
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n) time & space complexity
// table[sum] mean the number of continuous array from start which sums up to `sum`
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cumSum = 0;

        unordered_map<int, int> table;
        table[0] = 1;

        int res = 0;

        for (int i=0; i<n; ++i) {
            cumSum += nums[i];
            if (table.count(cumSum-k)) res += table[cumSum-k];
            ++table[cumSum];
        }

        return res;
    }
};

int main() {
    return 0;
}
