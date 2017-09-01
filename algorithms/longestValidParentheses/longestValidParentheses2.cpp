/**
 *
 * Sean
 * 2017-09-01
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 */
#include <string>
#include <iostream>
#include <stack>
using namespace std;

// you can use an array succ to store all the "("'s position if the substring is valid at index i
// here I figure out a way to save the trouble: when we meet a "(" at index i,
// check the last valid substring's ending position, taken as e, if e + 1 == i,
// we push the last valid substring's starting position into the stack.
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        stack<int> aStack;

        int lastStart = INT_MAX, lastEnd = INT_MAX;
        int n = s.size();

        int length = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') {
                aStack.push(lastEnd + 1 == i ? lastStart : i);
            } else if (!aStack.empty()) {
                lastStart = aStack.top();
                aStack.pop();
                lastEnd = i;
                length = max(length, lastEnd-lastStart+1);
            } else {
                lastStart = lastEnd = INT_MAX;
            }
        }
        return length;
    }
};

int main() {
    return 0;
}
