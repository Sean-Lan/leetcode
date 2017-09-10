/**
 *
 * Sean
 * 2017-09-10
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * Given an unsorted array of integers, find the number of longest increasing subsequence.
 *
 * Example 1:
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
 *
 * Example 2:
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
 *
 * Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
// dp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n, 1); // max length LIS ending with nums[i];
        vector<int> count(n, 1); // the number of LIS ending with nums[i];

        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    } else if (dp[j]+1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }

        }

        int len = 1;
        for (auto &i : dp) len = max(len, i);

        int sum = 0;
        for (int i=0; i<n; ++i) {
            if (dp[i] == len) {
                sum += count[i];
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}
