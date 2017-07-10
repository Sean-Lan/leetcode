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
    // FFFTTT find the first T
    int bs_search(int s, int e, function<bool(int)> p) {
        int mid;
        while (s < e) {
            mid = s + (e-s)/2;
            if (p(mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> table(n, INT_MAX);
        // table[i-1] means the end value of increasing sequence of length i
        int idx;
        int maxLen = 1;
        for (int i=0; i<n; ++i) {
            int cur = nums[i];
            idx = bs_search(0, i, [&] (int x) {
                return table[x] >= cur;
            });
            table[idx] = cur;
            maxLen = max(maxLen, idx+1);
        }
        return maxLen;
    }
};

int main() {
    return 0;
}
