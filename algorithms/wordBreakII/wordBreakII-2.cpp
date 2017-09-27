/**
 *
 * Sean
 * 2017-09-27
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

class Solution {
    string buildSentence(vector<string> &path) {
            string sentence;
            int sz = path.size();
            sentence += path[0];
            for (int i=1; i<sz; ++i) {
                        sentence += ' ';
                        sentence += path[i];
                    }
            return sentence;
        }
    bool solve(vector<string> &path, vector<string> &res, const string &s, int index) {
            int n = s.size();
            if (index < n && !cache[index]) return false;
            if (index == n) {
                        res.push_back(buildSentence(path));
                        return true;
                    }

            bool canBreak = false;
            for (int i=index; i<n; ++i) {
                        string word = s.substr(index, i-index+1);
                        if (table.count(word)) {
                                        path.push_back(word);
                                        if (solve(path, res, s, i+1)) canBreak = true;
                                        path.pop_back();
                                    }
                    }

            return cache[index] = canBreak;
        }
    unordered_set<string> table;
    vector<int> cache;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
            table.clear();
            for (auto &word : wordDict) table.insert(word);
            vector<string> path;
            vector<string> res;
            cache = vector<int>(s.size(), true);
            solve(path, res, s, 0);
            return res;
        }
};

int main() {
    return 0;
}
