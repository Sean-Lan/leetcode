/**
 *
 * Sean
 * 2016-05-29
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/
 *
 */
#include <iostream>
using namespace std;

/**
 * 3 2 1 0
 * 0 0 0 1
 * 0 0 1 0
 * 0 0 1 1
 * 0 1 0 0
 * 0 1 0 1
 * 0 1 1 0
 * 0 1 1 1
 * 1 0 0 0
 *  ...
 *
 * if the number of numbers in the range is large than 2^i ( i = 0, 1, 2, ....)
 * then 0, 1, ..., i-th bit must be zero.
 *
 * The following algorithm return the most common part of m and n, which is the answer.
 *
 */
class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            int cnt = 0;
            while (m != n) {
                m >>= 1;
                n >>= 1;
                ++cnt;
            }
            return m << cnt;
        }
};

int main() {}
