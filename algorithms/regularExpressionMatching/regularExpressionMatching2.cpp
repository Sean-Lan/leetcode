/**
 * Sean
 * 2016-03-06
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

// use substr, too much overhead
class Solution
{
    public:
        bool isMatch(string s, string p) {
            if (p.empty())
                return s.empty();
            // p has '*'
            if (p.size()>1 && p[1]=='*') {
                while (!s.empty() && (s[0]==p[0]||p[0]=='.')) {
                    if (isMatch(s, p.substr(2)))
                        return true;
                    s = s.substr(1);
                }
                return isMatch(s, p.substr(2));
            } else
                return !s.empty() && (s[0]==p[0]||p[0]=='.')
                        && isMatch(s.substr(1), p.substr(1));
        }
};

int main() {
    Solution solution;
    cout << solution.isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c") << endl;
    cout << solution.isMatch("aaaa", "a*") << endl;
}
