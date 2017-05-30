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
 * Note: Do not use the eval built-in library function.
 *
 */
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        istringstream ss(s);
        int res = 0;
        int temp = 0; // temp value separate by '+' and '-'
        int num;
        char op = '+';
        do { // every time enter the loop we will obtain next integer value
            if (op == '+' || op == '-') {
                res += temp;
                ss >> temp;
                if (op == '-') temp = -temp;
            } else { // * || /
                ss >> num;
                temp = (op == '*') ? temp * num : temp / num;
            }
        } while (ss >> op);
        res += temp;
        return res;
    }
};

int main() {
    return 0;
}
