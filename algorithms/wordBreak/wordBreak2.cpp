/**
 *
 * Sean
 * 2016-02-28
 *
 * https://leetcode.com/problems/word-break/
 *
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// Use DP. It's far more simple than DFS and runs much faster.
class Solution
{
    public:
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            int len = s.size();
            vector<bool> dp(len, false);
            dp[0] = true;
            for (int i=1; i<=len; ++i)
                for (int j=i-1; j>=0; --j)
                    if (dp[j] && wordDict.count(s.substr(j,i-j))) {
                        dp[i] = true;
                        break;
                    }
            return dp[len];
        }
};

int main() {
    unordered_set<string> wordDict = {"leet2", "code"};
    string s = "leetcode";
    Solution solution;
    cout << solution.wordBreak(s, wordDict) << endl;
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << solution.wordBreak(s, wordDict) << endl;
}
