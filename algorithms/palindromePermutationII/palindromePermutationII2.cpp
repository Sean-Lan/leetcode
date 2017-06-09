/**
 *
 * Sean
 * 2017-06-09
 *
 * https://leetcode.com/problems/palindrome-permutation-ii/#/description
 *
 * Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
 *
 * For example:
 *
 * Given s = "aabb", return ["abba", "baab"].
 *
 * Given s = "abc", return [].
 *
 */
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// DFS with backtracking
// `rem` is the remaining count of characters, it's initialized with the total count of possible characters
// To avoid duplicate, we need to go DFS in a level way, take "aabb" as an example:
//      a - b - a - b
//      a - bb - a
//      aa - bb
//      b - aa - b
//      b - a - b - a
//      bb - aa
//  At each different level of dfs, the characters pushed into `cur` must be different, as the code shows.
class Solution {
    void sovle(string &cur, vector<string> &res, unordered_map<char, int> &cnts, const string &mid, int rem) {
        if (rem == 0) {
            string rev(cur.rbegin(), cur.rend());
            res.push_back(cur + mid + rev);
            return;
        }

        char c;
        int cnt;
        for (auto &aPair : cnts) {
            c = aPair.first;
            cnt = aPair.second;
            if (!cur.empty() && cur.back() == c) continue;
            for (int i = 0; i<cnt; ++i) {
                cur.push_back(c);
                -- aPair.second;
                sovle(cur, res, cnts, mid, rem-i-1);
            }
            aPair.second = cnt;
            cur.resize(cur.size()-cnt);
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> cnts;
        for (auto c : s) ++ cnts[c];

        char odd = -1;
        int total = 0;
        for (auto &aPair : cnts) {
            if (aPair.second & 1) {
                if (odd != -1) return {};
                odd = aPair.first;
            }
            aPair.second /= 2; // we only need half
            total += aPair.second;
        }

        vector<string> res;
        string cur;
        string mid = odd == -1 ? "" : string(1, odd);

        sovle(cur, res, cnts, mid, total);
        return res;
    }
};

int main() {
    return 0;
}
