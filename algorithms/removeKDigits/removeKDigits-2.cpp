/**
 *
 * Sean
 * 2016-10-08
 *
 * https://leetcode.com/problems/remove-k-digits/
 *
 * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
 *
 * Note:
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * Example 1:
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 * Example 2:
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 * Example 3:
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 *
 */
#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Greedy method using a stack.
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> aStack;
        for (auto c : num) {
            while (k && !aStack.empty() && aStack.top() > c) {
                aStack.pop();
                --k;
            }
            aStack.push(c);
        }
        while (k && !aStack.empty()) {
            aStack.pop();
            --k;
        }
        string res;
        while (!aStack.empty()) {
            res.push_back(aStack.top());
            aStack.pop();
        }
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }
        if (res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {}
