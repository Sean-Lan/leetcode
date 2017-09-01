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
using namespace std;

// two pass solution, which makes sure we won't miss the valid longest substring
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int n = s.size();

        int length = 0;
        // =>>
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') ++left;
            else {
                ++ right;
                if (right == left) length = max(length, left+right);
                else if (right > left) left = right = 0;
            }
        }

        left = right = 0;
        // <<=
        for (int i=n-1; i>=0; --i) {
            if (s[i] == ')') ++right;
            else {
                ++ left;
                if (right == left) length = max(length, left+right);
                else if (left > right) left = right = 0;
            }
        }

        return length;
    }
};

int main() {
    return 0;
}
