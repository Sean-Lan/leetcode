/**
 *
 * Sean
 * 2017-04-23
 *
 * https://leetcode.com/problems/regular-expression-matching/#/description
 *
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming
// dp[i][j] denotes whether the first i characters of p match first j characters of s
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int j=1; j<=n; ++j) {
            dp[0][j] = false;
        }

        for (int i=1; i<=m; ++i) {
            for (int j=0; j<=n; ++j) {
                if (i > 1 && p[i-1] == '*') {
                    dp[i][j] = dp[i-2][j] // repeat 0 time
                    || (j > 0 && dp[i][j-1] && (p[i-2] == '.' || p[i-2] == s[j-1])); // repeat >=1 times
                } else if (p[i-1] == '.') {
                    dp[i][j] = j>0 && dp[i-1][j-1];
                } else {
                    dp[i][j] = j>0 && dp[i-1][j-1] && p[i-1] == s[j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    return 0;
}
