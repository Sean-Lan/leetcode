/**
 *
 * Sean
 * 2016-02-24
 *
 * https://leetcode.com/problems/longest-valid-parentheses/
 *
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 */
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/**
 *
 * Use a stack to store the positions of '(' and do the validation.
 * Use a array to store the earliest match postion of a '(' or ')', more detailedly:
 * If the previous char of '(' is a ')', then the earliest match position of current '(' is
 * that of the previous ')', else the earliest match position of current '(' is its own position.
 *
 */
class Solution {
    public:
        int longestValidParentheses(string s) {
            if (s.empty()) return 0;
            int *successPos = new int[s.size()];
            fill(successPos, successPos+s.size(), -1);
            stack<int> aStack;
            int longestLength = 0;
            char c;
            int matchPos;
            for (int i=0; i<s.size(); ++i) {
                c = s[i];
                if (c == '(') {
                    aStack.push(i);
                    if (i>0 && s[i-1]==')' && successPos[i-1]!=-1) {
                        successPos[i] = successPos[i-1];
                    } else {
                        successPos[i] = i;
                    }
                } else {
                    if (!aStack.empty()) {
                        matchPos = aStack.top();
                        aStack.pop();
                        longestLength = max(longestLength, i-successPos[matchPos]+1);
                        successPos[i] = successPos[matchPos];
                    }
                }
            }
            delete[] successPos;
            return longestLength;
        }
};

int main() {
    Solution solution;
    string s = ")()())";
    cout << solution.longestValidParentheses(s) << endl;

    s = "()";
    cout << solution.longestValidParentheses(s) << endl;

    s = "(";
    cout << solution.longestValidParentheses(s) << endl;

    s = ")((()))()()((())";
    cout << solution.longestValidParentheses(s) << endl;
}
