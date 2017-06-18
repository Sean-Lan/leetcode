/**
 *
 * Sean
 * 2017-06-18
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/#/description
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 *
 * Your algorithm should run in O(n2) complexity.
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 */
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

// O(n*log(n))
// binary search with length
class Solution {
    // TTTTFFF find the last T
    int bs_search(int s, int e, function<bool(int)> p) {
        int mid;
        while (s < e) {
            mid = s + (e-s)/2;
            if (s+1 == e) {
                return p(e) ? e : s;
            }
            if (p(mid)) {
                s = mid;
            } else {
                e = mid - 1;
            }
        }
        return s;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> table(n+1, INT_MAX);
        table[0] = INT_MIN;
        // table[i] means the end value of increasing sequence of length i
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i=0; i<n; ++i) {
            int cur = nums[i];
            dp[i] = 1 + bs_search(0, i, [&] (int len) {
                return table[len] < cur;
            });
            table[dp[i]] = cur;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

int main() {
    return 0;
}
