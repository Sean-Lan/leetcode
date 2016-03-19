/**
 *
 * Sean
 * 2016-03-19
 *
 * https://leetcode.com/problems/powx-n/
 *
 * Implement pow(x, n).
 *
 */
#include <iostream>
using namespace std;

/**
 *
 * Use the binary format of n, if one digit of n's binary format is 1,
 * result needs mutiply weight.
 * Care for negative value, and min value of int.
 *
 */
class Solution {
    public:
        double myPow(double x, int n) {
            double weight = x;
            double result = 1.0;
            bool negative = false;
            long long nn = n;
            if (nn<0) {
                negative = true;
                nn = -nn;
            }
            while (nn) {
                if (nn&1) result *= weight;
                weight *= weight;
                nn>>=1;
            }
            return negative?1/result:result;
        }
};

int main() {
    Solution solution;
    cout << solution.myPow(1,-2147483648) << endl;
}
