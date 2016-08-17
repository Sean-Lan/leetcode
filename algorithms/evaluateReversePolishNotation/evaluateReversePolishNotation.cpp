/**
 *
 * Sean
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 */
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> aStack;
        int operand1, operand2, result;
        char op;
        for (auto &s : tokens) {
            if (s.size() == 1 && !isdigit(s[0])) {
                op = s[0];
                operand2 = aStack.top();
                aStack.pop();
                operand1 = aStack.top();
                aStack.pop();
                switch (op) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        result = operand1 / operand2;
                        break;
                }
                aStack.push(result);
            } else {
                aStack.push(std::stoi(s));
            }
        }
        return aStack.top();
    }
};

int main() {
    Solution solution;
    vector<string> tokens = { "4","13","5","/","+" };
    cout << solution.evalRPN(tokens) << endl;
    return 0;
}
