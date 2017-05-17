/**
 *
 * Sean
 * 2016-01-27
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> table = {
    " ",
    "_",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

class Solution {
    void dfs(string &cur, vector<string> &res, const string &digits) {
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }
        string &possibleChars = table[digits[cur.size()] - '0'];
        for (auto c : possibleChars) {
            cur.push_back(c);
            dfs(cur, res, digits);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string cur;
        dfs(cur, res, digits);
        return res;
    }
};

void printResult (vector<string> & result) {
    for (auto& s : result)
        cout << s << endl;
}

int main() {
    string digits = "23";
    Solution s;
    auto result = s.letterCombinations(digits);
    printResult(result);
}
