/**
 *
 * Sean
 * 2016-02-02
 *
 * https://leetcode.com/problems/generate-parentheses/
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int n;
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        result = vector<string>();
        fillResult("(", 1, 0);
        return result;
    }
    
    void fillResult(string currentStr, int nLeft, int nRight) {
        if (nLeft==n && nRight==n) {
            this->result.push_back(currentStr);
            return;
        }
        if (nLeft>n||nLeft<nRight) return;
        fillResult(currentStr+'(', nLeft+1, nRight);
        fillResult(currentStr+')', nLeft, nRight+1);
    }
};

void printResult(vector<string>& result) {
    for (auto &s : result)
        cout << s << endl;
}

int main() {
    Solution s;
    auto result = s.generateParenthesis(3);
    printResult(result);
}
