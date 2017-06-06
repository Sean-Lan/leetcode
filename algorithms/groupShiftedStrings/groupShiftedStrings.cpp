/**
 *
 * Sean
 * 2017-06-06
 *
 * https://leetcode.com/problems/group-shifted-strings/#/description
 *
 * Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
 *
 * "abc" -> "bcd" -> ... -> "xyz"
 * Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
 *
 * For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 * A solution is:
 *
 * [
 *   ["abc","bcd","xyz"],
 *   ["az","ba"],
 *   ["acef"],
 *   ["a","z"]
 * ]
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    // shift `s` to a string beginning with 'a'
    string normalize(const string &s) {
        string t = s;
        int delta = t[0]-'a';
        for (auto &c : t) {
            c -= delta;
            if (c < 'a') c += 26;
        }
        return t;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> table;
        for (auto &s : strings) {
            table[normalize(s)].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &aPair : table) {
            res.push_back(aPair.second);
        }
        return res;
    }
};

int main() {
    return 0;
}
