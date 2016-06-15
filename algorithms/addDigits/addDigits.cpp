/**
 *
 * Sean
 * 2016-06-15
 *
 * https://leetcode.com/problems/add-digits/
 *
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * For example:
 *
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 *
 */
#include <iostream>
using namespace std;


// reference to https://en.wikipedia.org/wiki/Digital_root
class Solution {
    public:
        int addDigits(int num) {
            if (num == 0) return 0;
            if (num%9 == 0) return 9;
            return num % 9;
        }
};

int main() {
}
