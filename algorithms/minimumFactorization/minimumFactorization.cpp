/**
 *
 * Sean
 * 2017-08-17
 *
 * https://leetcode.com/problems/minimum-factorization/description/
 *
 * Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.
 *
 * If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.
 *
 * Example 1
 * Input:
 *
 * 48
 * Output:
 * 68
 * Example 2
 * Input:
 *
 * 15
 * Output:
 * 35
 *
 */
#include <iostream>
#include <climits>

using namespace std;

// every time, pick the largest possible digit which is the factor of a
class Solution {
    typedef long long ll;
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        ll res = 0;
        ll weight = 1;
        for (int i=9; i>=2; --i) {
            while (a%i == 0) {
                res = i * weight + res;
                weight *= 10;
                if (res > INT_MAX) return 0;
                a /= i;
            }
        }
        if (a != 1) return 0;
        return res;
    }
};

int main() {
    return 0;
}
