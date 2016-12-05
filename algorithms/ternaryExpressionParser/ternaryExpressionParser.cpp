/**
 *
 * Sean
 * 2016-12-05
 *
 * https://leetcode.com/problems/ternary-expression-parser/
 *
 * Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).
 * 
 * Note:
 * 
 * The length of the given string is ≤ 10000.
 * Each number will contain only one digit.
 * The conditional expressions group right-to-left (as usual in most languages).
 * The condition will always be either T or F. That is, the condition will never be a digit.
 * The result of the expression will always evaluate to either a digit 0-9, T or F.
 * Example 1:
 * 
 * Input: "T?2:3"
 * 
 * Output: "2"
 * 
 * Explanation: If true, then result is 2; otherwise result is 3.
 * Example 2:
 * 
 * Input: "F?1:T?4:5"
 * 
 * Output: "4"
 * 
 * Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:
 * 
 *              "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
 *           -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
 *           -> "4"                                    -> "4"
 * Example 3:
 * 
 * Input: "T?T?F:5:3"
 * 
 * Output: "F"
 * 
 * Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:
 * 
 *              "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
 *           -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
 *           -> "F"                                    -> "F"
 *
 */
#include <string>
#include <iostream>
using namespace std;

// DFS
class Solution {
    char parse(const string &expression, int &start) {
        char res;
        if (start == expression.size()-1) {
            res = expression[start];
            ++ start;
        } else if (start+1 < expression.size() && expression[start+1] == ':') {
            res = expression[start];
            start += 2;
        } else {
            char condition = expression[start];
            start += 2;
            char trueRes = parse(expression, start);
            char falseRes = parse(expression, start);
            res = (condition == 'T') ? trueRes : falseRes;
        }
        return res;
    }
public:
    string parseTernary(string expression) {
        int start = 0;
        char res = parse(expression, start);
        string result;
        result.push_back(res);
        return result;
    }
};

int main() {
    string expression = "T?2:3";
    Solution solution;
    cout << solution.parseTernary(expression) << endl;
    return 0;
}
