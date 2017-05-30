/**
 *
 * Sean
 * 2017-05-30
 *
 * https://leetcode.com/problems/basic-calculator-ii/#/description
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 *
 * Note: Do not use the eval built-in library function.
 *
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int multi(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

const function<int(int, int)> OPERATORS[] = {
    add, sub, multi, divide
};

// lower[op1][op2] == true: op1 has lower precedence than op2
bool lower[4][4] = {
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

int getOpIndex(char op) {
    if (op == '+') return 0;
    if (op == '-') return 1;
    if (op == '*') return 2;
    return 3;
}

class Solution {
public:
    int calculate(string s) {
        stack<int> ops; // +: 0, -: 1, *: 2, /: 3
        stack<int> nums;
        int num = 0;
        for (auto c : s) {
            if (isspace(c)) continue;
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else {
                nums.push(num);
                num = 0;
                int opIndex = getOpIndex(c);

                while (!ops.empty()) {
                    int lastOp = ops.top();
                    if (lower[lastOp][opIndex]) break;
                    ops.pop();
                    int b = nums.top(); // second operand
                    nums.pop();
                    int a = nums.top(); // first operand
                    nums.pop();
                    auto op = OPERATORS[lastOp];
                    nums.push(op(a, b));
                }
                ops.push(opIndex);
            }
        }
        nums.push(num);
        while (!ops.empty()) {
            int opIndex = ops.top();
            ops.pop();
            int b = nums.top(); // second operand
            nums.pop();
            int a = nums.top(); // first operand
            nums.pop();
            auto op = OPERATORS[opIndex];
            nums.push(op(a, b));
        }
        return nums.top();
    }
};

int main() {
    return 0;
}
