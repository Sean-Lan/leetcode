/**
 *
 * Sean
 * 2016-03-21
 *
 * https://leetcode.com/problems/length-of-last-word/
 *
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 *
 */
#include <string>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            if (s.empty()) return 0;
            int i = s.size()-1;
            while (i>=0&&s[i]==' ')--i;
            int j = i;
            for (;j>=0&&s[j]!=' ';--j);
            return i-j;
        }
};

int main() {}
