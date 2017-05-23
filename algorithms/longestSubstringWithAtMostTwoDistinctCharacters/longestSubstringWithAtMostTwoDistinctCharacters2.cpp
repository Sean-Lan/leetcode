/**
 *
 * Sean
 * 2017-05-23
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/#/description
 *
 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 *
 * For example, Given s = “eceba”,
 *
 * T is "ece" which its length is 3.
 *
 */
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

// O(n)
// Sliding window
// use `table` to maintain the character counters of s[start:i] (inclusive)
// every time a new character is discovered, move start ahead to make sure
// no more than two distinct characters in s[start:i]
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n < 3) return n;
        unordered_map<int, int> table;
        int start = 0;
        int maxLen = 2;
        char c;
        for (int i=0; i<n; ++i) {
            c = s[i];
            ++ table[c];
            if (table[c] == 1) { // first time to show
                while (table.size() > 2) {
                    c = s[start++];
                    if (--table[c] == 0) table.erase(c);
                }
            }
            maxLen = max(maxLen, i-start+1);
        }
        return maxLen;
    }
};

int main() {
    return 0;
}
