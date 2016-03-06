/**
 *
 * Sean
 * 2016-03-06
 *
 * https://leetcode.com/problems/wildcard-matching/
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
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
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// use DP
class Solution {
    public:
        bool isMatch(string s, string p) {
            vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1));
            dp[0][0] = true;
            for (int j=1; j<=p.size(); ++j)
                dp[0][j] = dp[0][j-1] && p[j-1]=='*';

            for (int i=1; i<=s.size(); ++i)
                for (int j=1; j<=p.size(); ++j) {
                    if (p[j-1] == '*') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    } else {
                        dp[i][j] = dp[i-1][j-1] &&
                                   (s[i-1]==p[j-1]||p[j-1]=='?');
                    }
                }
            return dp[s.size()][p.size()];
        }
};

int main() {
    Solution solution;
    cout << solution.isMatch("aa","a") << endl;
    cout << solution.isMatch("aa","aa") << endl;
    cout << solution.isMatch("aaa","aa") << endl;
    cout << solution.isMatch("aa", "*") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("ab", "?*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
}
