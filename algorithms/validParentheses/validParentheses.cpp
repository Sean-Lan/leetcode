/**
 *
 * Sean
 * 2016-01-29
 *
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

char firstHalf(char c) {
    if (c == ')') return '(';
    if (c == '}') return '{';
    return '[';
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char& c : s) {
            if (c == '(' ||
                c == '{' ||
                c == '[') {
                brackets.push(c);
            } else {
                if (brackets.empty() || brackets.top()!=firstHalf(c)) return false;
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("()()[][[[]]]{{{{}}}}") << endl;
}
