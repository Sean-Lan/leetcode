/**
 *
 * Sean
 * 2016-02-28
 *
 * https://leetcode.com/problems/word-break-ii/
 *
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Use DFS and use vector<bool> impossible to perform the pruning work.
 */
class Solution {
    private:
        void dfs(const string &s, int pos, unordered_set<string> &wordDict,
                vector<bool> &impossible, vector<string> &currentRes, vector<string> &results) {
            if (impossible[pos]) return;
            int len = s.size();
            string word;
            int originalSize = results.size();
            for (int j=pos+1; j<=len; ++j) {
                word = s.substr(pos, j-pos);
                if (wordDict.count(word)) {
                    if (j == len) {
                        string res;
                        for (auto &s : currentRes) {
                            res += s+' ';
                        }
                        res += word;
                        results.push_back(res);
                    } else {
                        currentRes.push_back(word);
                        dfs(s, j, wordDict, impossible, currentRes, results);
                        currentRes.pop_back();
                    }
                }
            }
            if (results.size() == originalSize)
                impossible[pos] = true;
        }

    public:
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            if (s.empty() || wordDict.empty()) return {};
            vector<bool> impossible(s.size());
            vector<string> results;
            vector<string> currentRes;
            dfs(s, 0, wordDict, impossible, currentRes, results);
            return results;
        }
};

void printResult(const vector<string> &results) {
    for (auto &result : results) {
        cout << result << endl;
    }
}

int main() {
    string s = "catsanddog";
    unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    Solution solution;
    printResult(solution.wordBreak(s, wordDict));
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    printResult(solution.wordBreak(s, wordDict));
}
