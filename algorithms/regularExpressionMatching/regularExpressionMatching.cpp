/**
 * Sean
 * 2015-09-22
 *
 * https://leetcode.com/problems/regular-expression-matching/
 *
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 */

#include <string>
#include <iostream>
using namespace std;

/**
 *
 * Reference from http://blog.csdn.net/doc_sgl/article/details/12719761
 *
 */

bool isMatch(char *s, char* p) {
    if (*p == 0) return *s == 0;
    if (*(p+1) != '*') {
        if (*s != 0 && (*s == *p || *p == '.')) return isMatch(s+1, p+1);
        else return false;
    }
    while (*s != 0 && (*s == *p || *p == '.')) {
        if (isMatch(s, p+2)) return true;
        ++s;
    }
    return isMatch(s, p+2);
}

int main() {
    cout << isMatch("aaaa", ".*") << endl;
    cout << isMatch("aaaa", "a*") << endl;
}
