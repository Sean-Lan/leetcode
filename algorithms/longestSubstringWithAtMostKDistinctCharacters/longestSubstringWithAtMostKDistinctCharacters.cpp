/**
 *
 * Sean
 * 2017-05-23
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/#/description
 *
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.
 *
 * For example, Given s = “eceba” and k = 2,
 *
 * T is "ece" which its length is 3.
 *
 */
#include <iostream>
#include <unordered_map>
using namespace std;

// O(n)
// sliding window
// `table` stores the character counter of s[start:i]
// every time a new character shows, move `start` ahead to make sure
// the number of distinct characters of s[start:i] <= k
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n <= k) return n;
        if (k <= 0) return 0;
        unordered_map<int, int> table;
        int start = 0;
        int maxLen = k;
        char c;
        for (int i=0; i<n; ++i) {
            c = s[i];
            ++ table[c];
            if (table[c] == 1) { // first time to show
                while (table.size() > k) {
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
