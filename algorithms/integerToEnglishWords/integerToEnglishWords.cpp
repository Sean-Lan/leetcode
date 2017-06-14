/**
 *
 * Sean
 * 2017-06-14
 *
 * https://leetcode.com/problems/integer-to-english-words/#/description
 *
 * Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
 *
 * For example,
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 *
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> below20 = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> below100 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

static const int BILLION = 1000000000;
static const int MILLION = 1000000;
static const int THOUSAND = 1000;
static const int HUNDRED = 100;

// solve it in a recursive way:
// 1. define the edge case
// 2. use the recursive formula
class Solution {
    string helper(int num) {
        if (num >= BILLION) return helper(num / BILLION) + " Billion" + helper(num % BILLION);
        if (num >= MILLION) return helper(num / MILLION) + " Million" + helper(num % MILLION);
        if (num >= THOUSAND) return helper(num / THOUSAND) + " Thousand" + helper(num % THOUSAND);
        if (num >= HUNDRED) return helper(num / HUNDRED) + " Hundred" + helper(num % HUNDRED);
        if (num >= 20) return " " + below100[num/10 - 2] + helper(num % 10);
        if (num >= 1) return " " + below20[num-1];
        return "";
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num).substr(1); // skip the space
    }
};

int main() {
    return 0;
}
