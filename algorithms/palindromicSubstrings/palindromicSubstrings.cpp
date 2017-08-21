/**
 *
 * Sean
 * 2017-08-21
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * Given a string, your task is to count how many palindromic substrings in this string.
 *
 * The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 *
 * Example 1:
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 * Example 2:
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 * Note:
 * The input string length won't exceed 1000.
 *
 */
#include <vector>
#include <iostream>

using namespace std;

// length based DP similar to https://leetcode.com/problems/longest-palindromic-subsequence/description/
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i=0; i<n; ++i) dp[i][i] = true;
        int cnt = n;
        for (int l=2; l<=n; ++l) {
            for (int i=0; i+l<=n; ++i) {
                if (s[i] == s[i+l-1] && (l==2 || dp[i+1][i+l-2])) {
                    dp[i][i+l-1] = true;
                    ++ cnt;
                }
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}
