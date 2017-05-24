/**
 *
 * Sean
 * 2017-05-24
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-ii/#/description
 *
 * Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
 *
 * The input string does not contain leading or trailing spaces and the words are always separated by a single space.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Could you do it in-place without allocating extra space?
 *
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // first reverse the whole string
        reverse(s.begin(), s.end());

        // reverse each word then
        string::iterator start, end;
        start = end = s.begin();
        while (end != s.end()) {
            if (*end == ' ') {
                reverse(start, end);
                start = ++end;
            } else {
                ++ end;
            }
        }
        reverse(start, end);
    }
};

int main() {
    return 0;
}
