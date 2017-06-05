/**
 *
 * Sean
 * 2017-06-05
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/#/description
 *
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 *
 *
 * Example 1
 * Input: "2-1-1".
 *
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 *
 *
 * Example 2
 * Input: "2*3-4*5"
 *
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10]
 *
 */
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int multi(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

const function<int(int, int)> OPERATORS[] = {
    add, sub, multi, divide
};

int getOpIndex(char op) {
    if (op == '+') return 0;
    if (op == '-') return 1;
    if (op == '*') return 2;
    return 3;
}

// The total number of values is a Catalan number:
// https://en.wikipedia.org/wiki/Catalan_number
class Solution {
    // calculate the possible values of nums[start:end], ops[start:end-1]
    // the edge case is when start equals to end, which means there is no op and the formula is a single number
    vector<int> dfs(vector<int> &ops, vector<int> &nums, int start, int end) {
        if (start == end) return { nums[start] };
        vector<int> res;
        for (int i=start; i<end; ++i) {
            auto op = OPERATORS[ops[i]];
            auto leftRes = dfs(ops, nums, start, i);
            auto rightRes = dfs(ops, nums, i+1, end);
            for (auto leftValue : leftRes)
                for (auto rightValue : rightRes) {
                    res.push_back(op(leftValue, rightValue));
                }
        }
        return res;
    }

public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ops;
        vector<int> nums;
        int num;
        char op;
        istringstream is(input);
        is >> num;
        nums.push_back(num);

        while (is >> op) {
            ops.push_back(getOpIndex(op));
            is >> num;
            nums.push_back(num);
        }

        return dfs(ops, nums, 0, nums.size()-1);
    }
};

int main() {
    string formula = "2*3-4*5";
    Solution solution;
    auto res = solution.diffWaysToCompute(formula);

    cout << "Result is: " << endl;
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}
