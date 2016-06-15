/**
 *
 * Sean
 * 2016-06-15
 *
 * https://leetcode.com/problems/distinct-subsequences/
 *
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (n == 0) return 1;
        if (m < n) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=0; i<=m; ++i)
            dp[i][0] = 1;

        for (int i=1; i<=m; ++i)
            for (int j=1; j<=n; ++j) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        return dp[m][n];
    }
};

int main() {}
