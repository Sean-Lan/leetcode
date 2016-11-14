/**
 *
 * Sean
 * 2016-11-14
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
 *
 * Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
 *
 * Example 1:
 *
 * Input:
 * s = "aaabb", k = 3
 *
 * Output:
 * 3
 *
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * Example 2:
 *
 * Input:
 * s = "ababbc", k = 2
 *
 * Output:
 * 5
 *
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// Divide and Conquer
// First find all the low frequency characters, then use them as the separator
// For each substring, calculate their own longest substring, and return the max.
// The stop condition is:
//  1. `s` is empty()
//  2. `s` is valid, i.e, all characters exist more than 3 times.
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) return 0;
        vector<int> cnts(26);
        for (auto c : s) ++cnts[c-'a'];
        unordered_set<char> notValid;
        for (int i=0; i<26; ++i) {
            if (cnts[i] && cnts[i] < k) {
                notValid.insert('a' + i);
            }
        }
        if (notValid.empty()) return s.size();

        vector<int> curCnts(26);
        int maxLen = 0;
        int curLen = 0;
        auto isValid = [&curCnts, k] {
            for (auto &i : curCnts) {
                if (i && i<k) return false;
            }
            return true;
        };
        char c;
        int i=0, last=0;
        for (; i<s.size(); ++i) {
            c = s[i];
            if (notValid.count(c)) {
                if (i > last)
                    maxLen = max(maxLen, longestSubstring(s.substr(last, i-last), k));
                last = i+1;
            }
        }
        if (i > last)
            maxLen = max(maxLen, longestSubstring(s.substr(last, i-last), k));
        return maxLen;
    }
};

int main() {
    Solution solution;
    cout << solution.longestSubstring("aaabb", 3) << endl;
    return 0;
}

