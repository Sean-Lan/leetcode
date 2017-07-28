/**
 *
 * Sean
 * 2017-07-28
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/tabs/description
 *
 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
 *
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
 *
 * Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
 *
 * Example 1:
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 *
 * Note:
 * The number of given pairs will be in the range [1, 1000].
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// DP, O(n^2)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &p1, const vector<int> &p2) {
            if (p1[1] != p2[1]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        });

        int n = pairs.size();
        // dp[i] means the max length of chain ends with the i-th pair
        vector<int> dp(n, 1);

        for (int i=1; i<n; ++i) {
            int maxLen = 0;
            for (int j=0; j<i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    maxLen = max(maxLen, dp[j]);
                }
            }
            dp[i] = maxLen + 1;
        }

        int res = 0;
        for (int i=0; i<n; ++i) {
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main() {
    return 0;
}
