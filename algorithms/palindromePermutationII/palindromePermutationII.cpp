/**
 *
 * Sean
 * 2017-06-08
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
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// iterative solution with `next_permutation`
class Solution {
    vector<string> getPermutations(string s) {
        vector<string> res;
        sort(s.begin(), s.end());
        do {
            res.push_back(s);
        } while(next_permutation(s.begin(), s.end()));
        return res;
    }

public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) return {};
        unordered_map<char, int> table;
        char odd = -1;
        for (auto c : s)
            ++ table[c];

        string possible;
        for (auto &aPair : table) {
            if (aPair.second & 1) {
                if (odd != -1) return {};
                odd = aPair.first;
            }
            for (int i=0; i<aPair.second/2; ++i) {
                possible.push_back(aPair.first);
            }
        }
        vector<string> res = getPermutations(possible);
        for (auto &p : res) {
            string reversed(p.rbegin(), p.rend());
            if (odd != -1) {
                p += odd;
            }
            p += reversed;
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    auto res = solution.generatePalindromes(s);
    for (auto &s : res) cout << s << endl;
    return 0;
}
