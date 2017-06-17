/**
 *
 * Sean
 * 2017-06-17
 *
 * https://leetcode.com/problems/word-pattern-ii/#/description
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
 *
 * Examples:
 * pattern = "abab", str = "redblueredblue" should return true.
 * pattern = "aaaa", str = "asdasdasdasd" should return true.
 * pattern = "aabb", str = "xyzabcxzyabc" should return false.
 *
 * Notes:
 * You may assume both pattern and str contains only lowercase letters.
 *
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// backtracking
class Solution {
    // use table and shown to maintain the bijection
    unordered_map<char, string> table;
    unordered_set<string> shown;

    bool dfs(int pi, string &pattern, int si, string &str) {
        int m = pattern.size();
        int n = str.size();

        if (pi == m || si == n) {
            return pi == m && si == n;
        }

        char c = pattern[pi];
        bool cHasShown = table.count(c);
        string validWord = cHasShown ? table[c] : "";

        for (int i = si; i<n; ++i) {
            string word = str.substr(si, i-si+1);
            if (cHasShown && word == validWord) {
                if (dfs(pi+1, pattern, i+1, str)) return true;
                continue;
            }
            if (!cHasShown && !shown.count(word)) { // new word
                table[c] = word;
                shown.insert(word);
                if (dfs(pi+1, pattern, i+1, str)) return true;
                table.erase(c);
                shown.erase(word);
            }
        }
        return false;
    }
public:
    bool wordPatternMatch(string pattern, string str) {
        table.clear();
        shown.clear();
        return dfs(0, pattern, 0, str);
    }
};

int main() {
    return 0;
}
