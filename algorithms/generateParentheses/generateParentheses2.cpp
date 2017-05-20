/**
 *
 * Sean
 * 2017-05-20
 *
 * https://leetcode.com/problems/generate-parentheses/#/description
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 *
 */
#include <string>
#include <vector>
using namespace std;

// backtracking
class Solution {
    void helper(vector<string> &res, string &cur, int nLeft, int nRight) {
        // edge case
        if (nLeft == 0) {
            for (int i=0; i<nRight; ++i)
                cur += ')';
            res.push_back(cur);
            // make sure `cur` is what it looks like when entering
            for (int i=0; i<nRight; ++i)
                cur.pop_back();
            return;
        }
        cur += '(';
        helper(res, cur, nLeft-1, nRight);
        cur.pop_back();

        if (nLeft < nRight) {
            cur += ')';
            helper(res, cur, nLeft, nRight-1);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        helper(res, cur, n, n);
        return res;
    }
};

int main() {
    return 0;
}
