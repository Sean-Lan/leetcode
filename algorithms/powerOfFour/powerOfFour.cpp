/**
 *
 * Sean
 * 2016-10-25
 *
 * https://leetcode.com/problems/power-of-four/
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 *
 * Follow up: Could you solve it without loops/recursion?
 *
 */
#include <iostream>
using namespace std;

// Reference from https://discuss.leetcode.com/topic/42860/java-1-line-cheating-for-the-purpose-of-not-using-loops
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && !(num & (num-1)) && (num & 0x55555555));
    }
};

int main() { return 0;}
