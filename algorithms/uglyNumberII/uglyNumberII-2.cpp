/**
 *
 * Sean
 * 2017-01-05
 *
 * https://leetcode.com/problems/ugly-number-ii/
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;

// DP
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> uglyNumbers(n, INT_MAX);
        // next index of number to multiply by {2, 3, 5}
        vector<int> indexes(3, 0);
        int candidates[3] = {2, 3, 5};
        uglyNumbers[0] = 1;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<3; ++j) {
                uglyNumbers[i] = min(uglyNumbers[i], (long long)uglyNumbers[indexes[j]]*candidates[j]);
            }
            // remove duplicates
            for (int j=0; j<3; ++j) {
                if ((long long)uglyNumbers[indexes[j]]*candidates[j] == uglyNumbers[i]) {
                    ++ indexes[j];
                }
            }
        }
        return uglyNumbers[n-1];
    }
};

int main() {
    return 0;
}
