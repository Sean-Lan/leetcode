/**
 *
 * Sean
 * 2017-08-29
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// two pointers to check cycle
class Solution {
    int squareSum(int n) {
        int sum = 0, r;
        while (n) {
            r = n % 10;
            n /= 10;
            sum += r*r;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(fast);
            fast = squareSum(fast);
        } while (slow != fast);
        return slow == 1;
    }
};

int main() {
    return 0;
}
