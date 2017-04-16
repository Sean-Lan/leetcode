/**
 *
 * Sean
 * 2017-04-16
 *
 * https://leetcode.com/problems/longest-palindromic-substring/#/description
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 * Example:
 *
 * Input: "cbbd"
 *
 * Output: "bb"
 *
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// DP, O(N^2), start from substring with length = 1
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int beg = 0, length = 1;
        for (int i=0; i<n; ++i) dp[i][i] = true;
        for (int i=0; i<n-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                beg = i;
                length = 2;
            }
        }
        for (int l=3; l<=n; ++l) {
            for (int i=0; i+l-1<n; ++i) {
                if (dp[i+1][i+l-2] && s[i] == s[i+l-1]) {
                    dp[i][i+l-1] = true;
                    beg = i;
                    length = l;
                }
            }
        }
        return s.substr(beg, length);
    }
};

int main() {
    return 0;
}
