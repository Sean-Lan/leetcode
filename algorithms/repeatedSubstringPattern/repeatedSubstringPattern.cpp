/**
 *
 * Sean
 * 2016-11-17
 *
 * https://leetcode.com/problems/repeated-substring-pattern/
 *
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 *
 * Example 1:
 * Input: "abab"
 *
 * Output: True
 *
 * Explanation: It's the substring "ab" twice.
 * Example 2:
 * Input: "aba"
 *
 * Output: False
 * Example 3:
 * Input: "abcabcabcabc"
 *
 * Output: True
 *
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 *
 */
#include <iostream>
#include <string>
using namespace std;

// O(n^2)
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int length = str.size();
        for (int l = length/2; l>0; --l) {
            if (length%l != 0) continue;
            string pattern = str.substr(0, l);
            bool isEqual = true;
            for (int s=l; s<length; s+=l) {
                for (int i=0; i<l; ++i) {
                    if (pattern[i] != str[s+i]) {
                        isEqual = false;
                        break;
                    }
                }
                if (!isEqual) break;
            }
            if (isEqual) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
