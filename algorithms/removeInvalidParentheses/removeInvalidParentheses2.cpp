/**
 *
 * Sean
 * 2017-06-19
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/#/description
 *
 * Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and ).
 *
 * Examples:
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// DFS
// first get the number of '(' and ')' that should be removed, then do dfs according to the number of '(' and ')' that could be removed
// and the number of '(' that remains not to be paired
class Solution {
    void dfs(int index, const string &s, int leftRemove, int rightRemove, int leftRemain, string path, unordered_set<string> &res) {
        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && leftRemain == 0) {
                res.insert(path);
            }
            return;
        }
        char c = s[index];
        if (c != '(' && c != ')') {
            dfs(index+1, s, leftRemove, rightRemove, leftRemain, path+c, res);
            return;
        }
        if (c == '(') {
            if (leftRemove > 0) {
                dfs(index+1, s, leftRemove-1, rightRemove, leftRemain, path, res);
            }
            dfs(index+1, s, leftRemove, rightRemove, leftRemain+1, path+c, res);
        } else { // ')'
            if (rightRemove > 0) {
                dfs(index+1, s, leftRemove, rightRemove-1, leftRemain, path, res);
            }
            if (leftRemain > 0) {
                dfs(index+1, s, leftRemove, rightRemove, leftRemain-1, path+c, res);
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        int leftRemove = 0;
        int rightRemove = 0;
        for (auto c : s) {
            if (c == '(') ++leftRemove;
            else if (c == ')') {
                if (leftRemove > 0) {
                    --leftRemove;
                } else {
                    ++rightRemove;
                }
            }
        }
        dfs(0, s, leftRemove, rightRemove, 0, "", res);
        return vector<string>(res.begin(), res.end());
    }
};

int main() {
    return 0;
}
