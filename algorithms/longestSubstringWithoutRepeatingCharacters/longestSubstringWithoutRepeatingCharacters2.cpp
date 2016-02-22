#include <iostream>
/**
 *
 * Sean
 * 2016-02-22
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 */

#include <algorithm>
#include <unordered_map>
using namespace std;

/** Use a unordered_map to mark the last ocurrence of a certain character. */

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> dict;
            int latest = -1;
            int maxLength = 0;
            char c;
            for (int i=0; i<s.size(); ++i) {
                c = s[i];
                if (dict.find(c)!=dict.end() && latest < dict[c]) {
                    latest = dict[c];
                }
                maxLength = max(maxLength, i-latest);
                dict[c] = i;
            }
            return maxLength;
        }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
}
