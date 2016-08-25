/**
 *
 * Sean
 * 2016-08-25
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/
 *
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 *
 * For example,
 *
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * Hint:
 *
 * No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
 * Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
 * Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
 *
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
typedef long long ll;
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        // intergral part
        bool sign1 = numerator > 0;
        bool sign2 = denominator > 0;
        bool sign = sign1^sign2;

        if (sign && numerator!=0)
            result += '-';

        ll lnumerator = numerator<0 ? -(ll)numerator : numerator;
        ll ldenominator = denominator<0 ? -(ll)denominator : denominator;

        result += to_string(lnumerator/ldenominator);
        lnumerator %= ldenominator;
        if (lnumerator == 0) return result;

        // fractional part
        string fraction;
        int repeatStartIndex = -1;
        unordered_map<ll, int> shownIndex { {lnumerator, 0} };
        lnumerator *= 10;
        while (lnumerator && repeatStartIndex==-1) {
            if (lnumerator < ldenominator) {
                fraction += '0';
            } else {
                fraction += lnumerator/ldenominator + '0';
                lnumerator %= ldenominator;
            }
            if (shownIndex.count(lnumerator)) {
                repeatStartIndex = shownIndex[lnumerator];
            }
            shownIndex[lnumerator] = fraction.size();
            lnumerator *= 10;
        }
        if (repeatStartIndex != -1) {
            result += ".";
            fraction.insert(repeatStartIndex, "(");
            result += fraction;
            result += ')';
        } else {
            result += '.';
            result += fraction;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.fractionToDecimal(-2147483648, -1) << endl;
    cout << solution.fractionToDecimal(10, 5) << endl;
    cout << solution.fractionToDecimal(5, 10) << endl;
    cout << solution.fractionToDecimal(1, 6) << endl;
    cout << solution.fractionToDecimal(4, 333) << endl;
}
