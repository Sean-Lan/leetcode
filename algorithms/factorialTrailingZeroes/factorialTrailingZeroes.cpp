/**
 *
 * Sean
 * 2016-04-21
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 */

#include <iostream>
using namespace std;

// Just counts how many 5s in 1*2*..*n.
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n) {
            cnt += n/5;
            n /= 5;
        }
        return cnt;
    }
};

int main() {}
