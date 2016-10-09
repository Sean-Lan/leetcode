/**
 *
 * Sean
 * 2016-10-09
 *
 * https://leetcode.com/problems/add-strings/
 *
 * Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        int n = num1.size();
        int m = num2.size();
        string r_num1(num1.rbegin(), num1.rend());
        string r_num2(num2.rbegin(), num2.rend());
        int tmp;
        int i = 0;
        for (; i<m && i<n; ++i) {
            tmp = (r_num1[i] -'0' + r_num2[i] - '0' + carry);
            carry = tmp/10;
            tmp %= 10;
            result.push_back(tmp+'0');
        }

        while (i<n) {
            tmp = (r_num1[i]-'0'+carry);
            carry = tmp/10;
            tmp %= 10;
            result.push_back(tmp+'0');
            ++i;
        }

        while (i<m) {
            tmp = (r_num2[i]-'0'+carry);
            carry = tmp/10;
            tmp %= 10;
            result.push_back(tmp+'0');
            ++i;
        }

        if (carry) result.push_back('1');

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.addStrings("0", "0") << endl;
}
