/**
 *
 * Sean Lan
 * 2017-05-16
 *
 * https://leetcode.com/problems/integer-to-roman/#/description
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Use a table to minize the code lines
class Solution {
    static const vector<string> table[4];
public:
    string intToRoman(int num) {
        string res;
        res += table[3][num/1000];
        num %= 1000;
        res += table[2][num/100];
        num %= 100;
        res += table[1][num/10];
        num %= 10;
        res += table[0][num];
        return res;
    }
};

const vector<string> Solution::table[4] = {
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    {"", "M", "MM", "MMM"}
};

int main() {
    return 0;
}
