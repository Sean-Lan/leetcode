/**
 *
 * Sean
 * 2017-07-29
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * Given an integer, return its base 7 string representation.
 *
 * Example 1:
 * Input: 100
 * Output: "202"
 *
 * Example 2:
 * Input: -7
 * Output: "-10"
 * Note: The input will be in range of [-1e7, 1e7].
 *
 */
#include <vector>
#include <string>
using namespace std;

// just note for negative numbers
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool positive = num > 0;
        if (!positive) num = -num;
        string res;
        while (num) {
            res.push_back(num%7 + '0');
            num /= 7;
        }
        if (!positive) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
