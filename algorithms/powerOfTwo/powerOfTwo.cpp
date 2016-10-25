/**
 *
 * Sean
 * 2016-10-25
 *
 * https://leetcode.com/problems/power-of-two/
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 */
#include <iostream>
using namespace std;

class Solution {
    public:
        // counts how many 1s.
        bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            short cnt = 0;
            while (n) {
                if (n & 1) ++cnt;
                n >>= 1;
            }
            return cnt == 1;
        }

        // n & (n-1) remove the last one-bit.
        bool isPowerOfTwo2(int n) {
            if (n <= 0) return false;
            return !(n & (n-1));
        }

};

int main() {
    return 0;
}
