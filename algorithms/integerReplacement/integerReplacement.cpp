/**
 *
 * Sean
 * 2016-11-16
 *
 * Given a positive integer n and you can do operations as follow:
 *
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * What is the minimum number of replacements needed for n to become 1?
 *
 * Example 1:
 *
 * Input:
 * 8
 *
 * Output:
 * 3
 *
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * Example 2:
 *
 * Input:
 * 7
 *
 * Output:
 * 4
 *
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 *
 */
#include <iostream>
using namespace std;

// bit manipulation
// If the last two bits are 11, add one (except the number is 3).
// If the last two bits are 01, minus one.
// If the last bit is zero, halve it.
class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int cnt = 0;
        while (num != 1) {
            ++cnt;
            if (num == 3) {
                num -= 1;
                continue;
            }
            if ((num & 1) == 0) {
                num >>= 1;
                continue;
            }
            if ((num & 0x3) == 3) {
                num += 1;
            } else {
                num -= 1;
            }
        }
        return cnt;
    }
};

int main() { return 0; }
