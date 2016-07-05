/**
 *
 * Sean
 * 2016-07-05
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = (int)s.size();
        // isPalindrome[i][j] == true means s[i..j] is palindrome
        vector<vector<bool>> isPalindrome(len, vector<bool>(len));
        for (int i=0; i<len; ++i)
            isPalindrome[i][i] = true;

        // use DP to calculate isPalindrome
        for (int l=2; l<=len; ++l) {
            for (int i=0; i+l-1<len; ++i)
                isPalindrome[i][i+l-1] = (s[i] == s[i+l-1] &&
                                          (l<=2 || isPalindrome[i+1][i+l-2]));
        }

        // dp[i] is the minCut for s[0..i]
        vector<int> dp(len);
        for (int i=0; i<len; ++i) dp[i] = i;

        // use DP to calculate dp.
        for (int i=1; i<len; ++i) {
            for (int j=0; j<=i; ++j) {
                if (isPalindrome[j][i]) {
                    if (j == 0) {
                        dp[i] = 0;
                        break;
                    } else {
                        dp[i] = min(dp[i], dp[j-1]+1);
                    }
                }
            }
        }
        return dp[len-1];
    }
};

int main() {}
