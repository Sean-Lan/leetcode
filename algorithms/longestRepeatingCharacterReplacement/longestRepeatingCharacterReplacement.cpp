/**
 *
 * Sean
 * 2016-10-26
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/
 *
 * Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
 *
 * Note:
 * Both the string's length and k will not exceed 104.
 *
 * Example 1:
 *
 * Input:
 * s = "ABAB", k = 2
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * Example 2:
 *
 * Input:
 * s = "AABABBA", k = 1
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 */
#include <string>
using namespace std;

class Solution {
public:
    // Sliding window, O(n)
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (k >= n) return n;
        int maxLen = 0;
        int start = 0; int end = 0;
        int diffCnt = 0;
        for (char c='A'; c<='Z'; ++c) {
            start = 0;
            end = 0;
            diffCnt = 0;
            while(end < n) {
                if (s[end] == c) {
                    ++end;
                } else if (diffCnt < k) {
                    ++end;
                    ++diffCnt;
                } else { // `end` can't move, move start.
                    if (s[start] != c && diffCnt > 0) {
                        --diffCnt;
                    }
                    ++start;
                    end = max(start, end);
                }
                maxLen = max(maxLen, end - start);
            }
        }
        return maxLen;
    }
};

int main() { return 0; }
