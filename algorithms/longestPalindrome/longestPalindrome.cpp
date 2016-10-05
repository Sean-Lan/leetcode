/**
 *
 * Sean
 * 2016-10-05
 *
 * https://leetcode.com/problems/longest-palindrome/
 *
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int lowerCase[26] = {0};
        int upperCase[26] = {0};
        for (auto &c : s) {
            if (c >= 'a' && c <= 'z')
                ++ lowerCase[c-'a'];
            else
                ++ upperCase[c-'A'];
        }
        int total = 0;
        bool oddShown = false;
        for (auto &cnt : lowerCase) {
            if (cnt % 2 == 0) {
                total += cnt;
            } else {
                total += cnt-1;
                oddShown = true;
            }
        }
        for (auto &cnt : upperCase) {
            if (cnt % 2 == 0) {
                total += cnt;
            } else {
                total += cnt -1;
                oddShown = true;
            }
        }
        if (oddShown) ++ total;
        return total;
    }
};

int main() {
    string s = "abccccdd";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}
