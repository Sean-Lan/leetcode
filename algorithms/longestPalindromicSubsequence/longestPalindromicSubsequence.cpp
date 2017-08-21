/**
 *
 * Sean
 * 2017-08-21
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 * Input:
 * "bbbab"
 * Output:
 * 4
 * One possible longest palindromic subsequence is "bbbb".
 *
 * Example 2:
 * Input:
 * "cbbd"
 * Output:
 * 2
 * One possible longest palindromic subsequence is "bb".
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// DP, O(n^2)
// dp[i][j] means the longest palindromic subsequence's length of s[i:j] (inclusive)
// dp[i][j] =
//      dp[i+1][j-1], s[i] == s[j]
//      max(dp[i+1][j], dp[i][j-1]), s[i] != s[j]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i=0; i<n; ++i) {
            dp[i][i] = 1;
        }

        for (int l=2; l<=n; ++l) {
            for (int i=0; i+l<=n; ++i) {
                if (s[i] == s[i+l-1])
                    dp[i][i+l-1] = dp[i+1][i+l-2] + 2;
                else
                    dp[i][i+l-1] = max(dp[i+1][i+l-1], dp[i][i+l-2]);
            }
        }

        return dp[0][n-1];
    }
};

int main() {
    return 0;
}
