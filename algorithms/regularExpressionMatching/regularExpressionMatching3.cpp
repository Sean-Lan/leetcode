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

// use reference
class Solution
{
    private:
        bool isMatch(const string &s, int sPos, const string &p, int pPos) {
            if (pPos == p.size())
                return sPos == s.size();
            if (pPos+1 < p.size() && p[pPos+1] == '*') {
                while (sPos!=s.size() && (s[sPos]==p[pPos]||p[pPos]=='.')) {
                    if (isMatch(s, sPos, p, pPos+2))
                        return true;
                    ++sPos;
                }
                return isMatch(s, sPos, p, pPos+2);
            } else
                return !(sPos==s.size()) && (s[sPos]==p[pPos]||p[pPos]=='.')
                        && isMatch(s, sPos+1, p, pPos+1);

        }

    public:
        bool isMatch(string s, string p) {
            return isMatch(s, 0, p, 0);
        }
};

int main() {
    Solution solution;
    cout << solution.isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c") << endl;
    cout << solution.isMatch("aaaa", "a*") << endl;
}
