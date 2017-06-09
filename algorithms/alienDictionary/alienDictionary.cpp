/**
 *
 * Sean
 * 2017-06-09
 *
 * https://leetcode.com/problems/alien-dictionary/#/description
 *
 * There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
 *
 * Example 1:
 * Given the following words in dictionary,
 *
 * [
 *   "wrt",
 *   "wrf",
 *   "er",
 *   "ett",
 *   "rftt"
 * ]
 * The correct order is: "wertf".
 *
 * Example 2:
 * Given the following words in dictionary,
 *
 * [
 *   "z",
 *   "x"
 * ]
 * The correct order is: "zx".
 *
 * Example 3:
 * Given the following words in dictionary,
 *
 * [
 *   "z",
 *   "x",
 *   "z"
 * ]
 * The order is invalid, so return "".
 *
 * Note:
 * You may assume all letters are in lowercase.
 * You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
 * If the order is invalid, return an empty string.
 * There may be multiple valid order of letters, return any one of them is fine.
 *
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

// Topological sort
// Key point is compare two ajacent words, and find the first different characters to get the topo order
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> chars;
        unordered_map<char, unordered_set<char>> sucs;
        unordered_map<char, unordered_set<char>> pres;

        string s;
        int len;
        for (auto &t : words) {
            chars.insert(t.begin(), t.end());
            len = min(s.size(), t.size());
            for (int i=0; i < len; ++i) {
                if (s[i] != t[i]) {
                    sucs[s[i]].insert(t[i]);
                    pres[t[i]].insert(s[i]);
                    break;
                }
            }
            s = t;
        }

        unordered_set<char> frees;
        for (auto c : chars) {
            if (pres.count(c) == 0 || pres[c].empty())
                frees.insert(c);
        }

        string res;
        while (!frees.empty()) {
            char c = *frees.begin();
            frees.erase(frees.begin());
            res.push_back(c);
            auto &suc = sucs[c];
            for (auto c1 : suc) {
                auto &pre = pres[c1];
                pre.erase(c);
                if (pre.empty()) frees.insert(c1);
            }
        }

        return res.size() == chars.size() ? res : "";
    }
};
