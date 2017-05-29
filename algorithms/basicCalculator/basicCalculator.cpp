/**
 *
 * Sean
 * 2017-05-29
 *
 * https://leetcode.com/problems/basic-calculator/#/description
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * Note: Do not use the eval built-in library function.
 *
 */
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int sign = 1;
        int num = 0;
        stack<int> ops, nums;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = c=='+' ? 1 : -1;
            } else if (c == '(') {
                nums.push(res);
                ops.push(sign);
                sign = 1;
                res = 0;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                if (!ops.empty()) {
                    res = nums.top() + ops.top()*res;
                    ops.pop();
                    nums.pop();
                }
            }
        }
        res += sign * num;
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.calculate("1+(1-3)") << endl;
    return 0;
}
