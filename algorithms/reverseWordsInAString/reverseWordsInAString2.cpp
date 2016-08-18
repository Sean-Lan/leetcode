/**
 *
 * Sean
 * 2016-08-18
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 *
 * click to show clarification.
 *
 * Clarification:
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 *
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 *
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 *
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// O(1) space complexity and O(n) time complexity.
class Solution {
public:
    void reverseString(string &s, int i, int j) {
        char tmp;
        while (i < j) {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            ++i; --j;
        }
    }

    void reverseWords(string &s) {
        int i = 0;
        int j = 0;
        int k = 0;
        int len = (int)s.size();
        bool isFirst = true;
        while (true) {
            while (i < len && s[i] == ' ') ++i; // skip spaces.
            if (i == len) break;
            if (isFirst) {
                isFirst = false;
            } else {
                s[k++] = ' ';
            }
            j = k;
            while (i < len && s[i] != ' ') s[k++] = s[i++];
            reverseString(s, j, k-1);
        }
        reverseString(s, 0, k-1);
        s.resize(k);
    }
};

int main() {
    string s = "  the sky is blue  ";
    Solution solution;
    solution.reverseWords(s);
    cout << s << endl;
    return 0;
}

