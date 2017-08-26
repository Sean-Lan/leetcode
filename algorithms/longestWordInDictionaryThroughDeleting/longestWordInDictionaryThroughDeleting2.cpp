/**
 *
 * Sean
 * 2017-08-26
 *
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
 *
 * Example 1:
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 *
 * Output:
 * "apple"
 * Example 2:
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 *
 * Output:
 * "a"
 *
 * Note:
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O(n*l) without sorting
class Solution {
    bool isOk(const string &s, const string &t) {
        if (t.size() > s.size()) return false;
        int i=0, j=0;
        while (j < t.size()) {
            if (s[i] == t[j]) {
                ++j;
            }
            if (++i == s.size()) break;
        }
        return j == t.size();
    }

    inline bool better(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) return s1.size() > s2.size();
        return s1 < s2;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (auto & t : d) {
            if (isOk(s, t) && better(t, res)) res = t;
        }
        return res;
    }
};

int main() {
    return 0;
}
