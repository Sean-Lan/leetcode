/**
 *
 * Sean
 * 2016-04-22
 *
 * https://leetcode.com/problems/integer-break/
 *
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.
 * Return the maximum product you can get.
 *
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        /* O(n^2) */
        int integerBreak2(int n) {
            vector<int> dp(n+1, 0);
            dp[1] = 1;
            dp[2] = 1;
            for (int i=3; i<=n; ++i) {
                for (int j=2; j<i; ++j) {
                    dp[i] = max(dp[i], max(j, dp[j]) * max(i-j, dp[i-j]));
                }
            }
            return dp[n];
        }

        /**
         *
         * O(n)
         * Separate n into two parts, the first part is 2 or 3.
         *
         */
        int integerBreak(int n) {
            vector<int> dp(n+1, 1);
            if (n == 2)
                return 1;
            if (n == 3)
                return 2;
            dp [3] = 2;
            for (int i=4; i<=n; ++i) {
                dp[i] = max(2*max(i-2, dp[i-2]),
                            3*max(i-3, dp[i-3]));
            }
            return dp[n];
        }
};

int main() {
    Solution solution;
    cout << solution.integerBreak(10) << endl;
}
