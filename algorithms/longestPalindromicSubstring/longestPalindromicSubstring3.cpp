/**
 *
 * Sean
 * 2017-04-16
 *
 * https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 * Example:
 *
 * Input: "cbbd"
 *
 * Output: "bb"
 *
 */
#include <iostream>
#include <string>
using namespace std;

/**
 *
 * O(N^2)
 * expand the string at `i` to the begin and end
 * 2 optimization:
 * 1. skip the same characters
 * 2. if the length of the possible palindromic substring is less than current max length, just skip the remaining process
 *
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int i = 0;
        int beg = 0;
        int length = 1;
        int n = s.size();
        int j, k;
        while (i < n) {
            if ((n-i-1)*2+1 <=length) break;
            j = k = i;
            while (k+1 < n && s[k] == s[k+1]) ++k;
            i = k+1;
            while (j > 0 && k+1 < n && s[k+1] == s[j-1]) {
                ++k;
                --j;
            }
            if (k-j+1 > length) {
                beg = j;
                length = k-j+1;
            }
        }
        return s.substr(beg, length);
    }
};

int main() {
    return 0;
}
