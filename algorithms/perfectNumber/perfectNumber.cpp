/**
 *
 * Sean
 * 2017-08-10
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
 *
 * Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
 *
 * Example:
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 *
 * Note: The input number n will not exceed 100,000,000. (1e8)
 *
 */
#include <iostream>
using namespace std;

// O(sqrt(n)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int i=2; i*i <= num; ++i) {
            if (num % i == 0) {
                sum += i;

                if (num / i != i) sum += num / i;
            }
        }
        return sum == num;
    }
};

int main() {
    return 0;
}
