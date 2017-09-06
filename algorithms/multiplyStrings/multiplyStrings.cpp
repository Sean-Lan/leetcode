/**
 *
 * Sean
 * 2017-09-06
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 *
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// big number addition
class Solution {
    string add(string &num1, string &num2) {
        int m = num1.size();
        int n = num2.size();
        int carry = 0;
        string res;
        int i=0, j=0;

        while (i<m && j<n) {
            int tmp = carry + num1[i] + num2[j] - '0' - '0';
            carry = tmp/10;
            res.push_back('0' + tmp%10);
            ++i; ++j;
        }

        while (i<m) {
            int tmp = carry + num1[i] - '0';
            carry = tmp/10;
            res.push_back('0' + tmp%10);
            ++i;
        }

        while (j<n) {
            int tmp = carry + num2[j] - '0';
            carry = tmp/10;
            res.push_back('0' + tmp%10);
            ++j;
        }

        if (carry) res.push_back('0' + carry);
        return res;
    }
    string multiply(string &num, char c) {
        if (c == '0') return "0";
        int carry = 0;
        int n = num.size();
        int x = c-'0';
        string res;
        for (int i=0; i<n; ++i) {
            int tmp = carry + (num[i]-'0') * x;
            carry = tmp/10;
            res.push_back('0' + tmp%10);
        }
        if (carry) res.push_back(carry+'0');
        return res;
    }
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.size();
        string res = "0";
        for (int i=0; i<n; ++i) {
            string product = multiply(num2, num1[i]);
            string prefix(i, '0');
            if (product != "0") {
                product = prefix + product;
            }
            res = add(res, product);
        }

        return string(res.rbegin(), res.rend());
    }
};

int main() {
    return 0;
}
