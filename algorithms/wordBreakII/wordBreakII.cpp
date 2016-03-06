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
 *
 * Use DP. First find all the indexes of s that can break, then cache the possible break combinations between
 * the indexes.
 *
 */
class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            int len = s.size();
            vector<bool> canBreak(len+1);
            vector<int> idxes;
            idxes.push_back(0);
            canBreak[0] = true;
            for (int i=1; i<=len; ++i)
                for (int j=i-1; j>=0; --j)
                    if (canBreak[j] && wordDict.count(s.substr(j, i-j))) {
                        canBreak[i] = true;
                        idxes.push_back(i);
                        break;
                    }
            if (!canBreak[len]) return {};

            int idxLen = idxes.size();
            vector<vector<string>> breaks(idxLen+1);
            breaks[0].push_back({""});
            string word;
            int idx1, idx2;
            for (int i=1; i<=idxLen; ++i) {
                for (int j=0; j<i; ++j) {
                    idx1 = idxes[j]; idx2 = idxes[i];
                    word = s.substr(idx1, idx2-idx1);
                    if (wordDict.count(word))
                        for (auto &w : breaks[j])
                            breaks[i].push_back(w + word + ' ');
                }
            }

            vector<string> res;
            for (auto &w : breaks[idxLen]) {
                res.push_back(w.substr(0, w.size()-1));
            }
            return res;
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
