/**
 *
 * Sean
 * 2016-03-26
 *
 * https://leetcode.com/problems/interleaving-string/
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        // use DP, dp[i][j] means whether the first i characters of s1 and first j characters of s2
        // matches first i+j characters of s3
        bool isInterleave(string s1, string s2, string s3) {
            int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
            if (len1 == 0)
                return s2 == s3;
            if (len2 == 0)
                return s1 == s3;
            if (len1+len2 != len3)
                return false;

            vector<vector<bool>> dp(len1+1, vector<bool>(len2+1));
            dp[0][0] = true;
            for (int i=1; i<=len1; ++i)
                dp[i][0] = dp[i-1][0] && s1[i-1]==s3[i-1];

            for (int j=1; j<=len2; ++j)
                dp[0][j] = dp[0][j-1] && s2[j-1]==s3[j-1];

            for (int i=1; i<=len1; ++i)
                for (int j=1; j<=len2; ++j)
                    dp[i][j] = (dp[i][j-1] && s2[j-1]==s3[i+j-1]) ||
                        (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
            return dp[len1][len2];
        }

        // simply dfs will lead to a TLE
        bool isInterleave_tle(string s1, string s2, string s3) {
            int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
            if (len1 == 0)
                return s2 == s3;
            if (len2 == 0)
                return s1 == s3;
            if (len1+len2 != len3)
                return false;
            return dfs(0, 0, 0, s1, s2, s3);
        }

    private:
        bool dfs(int cur1, int cur2, int cur, const string &s1, const string &s2, const string&s3) {
            if (cur == s3.size())
                return true;
            if (s1[cur1] == s3[cur] && dfs(cur1+1, cur2, cur+1, s1, s2, s3))
                return true;
            if (s2[cur2] == s3[cur] && dfs(cur1, cur2+1, cur+1, s1, s2, s3))
                return true;
            return false;
        }
};

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    Solution solution;
    cout << solution.isInterleave(s1, s2, "aadbbcbcac") << endl;
    cout << solution.isInterleave(s1, s2, "aadbbbaccj") << endl;
}
