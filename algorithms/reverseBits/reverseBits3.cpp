/**
 *
 * Sean
 * 2017-08-22
 *
 * https://leetcode.com/problems/reverse-bits/
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

// Note:  >> take higher precedence than &
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // abcdefgh
        n = (n >> 16) | (n << 16); // => efghabcd
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); // => ghefcdab
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); // => hgfecdba
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits(43261596) << endl;
}
