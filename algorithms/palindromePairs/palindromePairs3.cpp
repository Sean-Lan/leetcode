/**
 *
 * Sean
 * 2017-08-20
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
 *
 * Example 1:
 * Given words = ["bat", "tab", "cat"]
 * Return [[0, 1], [1, 0]]
 * The palindromes are ["battab", "tabbat"]
 *
 * Example 2:
 * Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 * Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 * The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 *
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// O(n*l^2): n size of words, l maximum length of word
class Solution {
    bool isPalindrome(const string &s) {
        if (s.empty()) return true;
        int i = 0, j = s.size() -1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> table;
        int emptyIndex = -1;
        for (int i=0; i<n; ++i) {
            if (words[i] == "") emptyIndex = i;
            else {
                table[words[i]] = i;
            }
        }

        vector<vector<int>> res;

        for (int i=0; i<n; ++i) {
            auto &word = words[i];
            if (word.empty()) continue;

            int sz = word.size();
            for (int j=1; j<sz; ++j) {
                string p1 = word.substr(0, j);
                string p2 = word.substr(j);
                if (isPalindrome(p1)) {
                    string rev(p2.rbegin(), p2.rend());
                    if (table.count(rev)) {
                        res.push_back({table[rev], i});
                    }
                }
                if (isPalindrome(p2)) {
                    string rev(p1.rbegin(), p1.rend());
                    if (table.count(rev)) {
                        res.push_back({i, table[rev]});
                    }
                }
            }

            // redup
            // case 1: the word itself is a palindrome, check whether empty string exists
            if (isPalindrome(word)) {
                if (emptyIndex != -1) {
                    res.push_back({i, emptyIndex});
                    res.push_back({emptyIndex, i});
                }
            } else { // case 2: the rev exists, only append rev to the end to avoid counting twice
                string rev(word.rbegin(), word.rend());
                if (table.count(rev)) {
                    res.push_back({i, table[rev]});
                }
            }
        }

        return res;
    }
};
