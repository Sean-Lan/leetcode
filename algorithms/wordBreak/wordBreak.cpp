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
#include <unordered_set>
#include <iterator>
#include <vector>

using namespace std;

/**
 *
 * Simple dfs turns out to a TLE.
 * Use vector<bool> to mark it impossible that to perform the word break from begin.
 *
 */
class Solution {
    private:
        bool dfs(int begin, int end, const string &s, const unordered_set<string>&wordDict, vector<bool> &impossible) {
            if (impossible[begin] || end > s.size()) return false;
            string word = s.substr(begin, end-begin);

            if (wordDict.find(word) != wordDict.end()) {
                if (end == s.size())
                    return true;
                if (dfs(end, end+1, s, wordDict, impossible)) return true;
            }
            bool ret = dfs(begin, end+1, s, wordDict, impossible);
            if (ret) return true;
            impossible[begin] = true;
            return false;
        }

    public:
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            vector<bool> impossible(s.size());
            return dfs(0, 1, s, wordDict, impossible);
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
