/**
 *
 * Sean
 * 2016-02-23
 *
 * https://leetcode.com/problems/minimum-window-substring/
 *
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 *
 */
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * Using slide window [left, right].
 */
class Solution {
    public:
        string minWindow(string s, string t) {
            if (s.empty() || t.empty()) return "";
            unordered_map<char, int> charMap;
            for (auto c : t)
                ++charMap[c];

            int left = 0, right = 0;
            int cnt = 0;
            int newLength;
            int minLength = -1;
            int minLeft, minRight;
            char c;
            unordered_map<char, int> curMap;
            while (right < s.size()) {
                c = s[right];
                auto it = charMap.find(c);
                if (it!=charMap.end()) {
                    if (curMap[c] < it->second)
                        ++cnt;
                    ++curMap[c];
                }
                while (cnt == t.size()) {
                    newLength = right-left+1;
                    if (minLength==-1 || newLength<minLength) {
                        minLeft = left;
                        minRight = right;
                        minLength = newLength;
                    }
                    c = s[left];
                    auto it = curMap.find(c);
                    if (it != curMap.end()) {
                        --it->second;
                        if (it->second < charMap[c])
                            --cnt;
                    }
                    ++left;
                }
                ++right;
            }
            if (minLength == -1)
                return "";
            return s.substr(minLeft, minLength);
        }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << solution.minWindow(s, t) << endl;
    s = "a";
    t = "a";
    cout << solution.minWindow(s, t) << endl;
}
