/**
 *
 * Sean
 * 2016-11-14
 *
 * https://leetcode.com/problems/is-subsequence/
 *
 * Given a string s and a string t, check if s is subsequence of t.
 *
 * You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
 *
 * Example 1:
 * s = "abc", t = "ahbgdc"
 *
 * Return true.
 *
 * Example 2:
 * s = "axc", t = "ahbgdc"
 *
 * Return false.
 *
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
 *
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Binary search for the follow up.
// If there're n search queries of length k and t's length is m, the time complexity is O(n*k*log(m) + m)
class Solution {
public:
    bool isSubsequence(string s, string t) {

        vector<vector<int>> indexTable(26);
        for (int i = 0; i<t.size(); ++i) {
            auto c = t[i];
            indexTable[c-'a'].push_back(i);
        }

        int pos = 0;
        for (auto c : s) {
            auto &indexes = indexTable[c-'a'];
            if (indexes.empty()) return false;
            auto cur = lower_bound(indexes.begin(), indexes.end(), pos);
            if (cur == indexes.end()) return false;
            pos = *cur + 1;
        }
        return true;
    }
};

int main() { return 0; }
