/**
 *
 * Sean
 * 2016-10-25
 *
 * https://leetcode.com/problems/power-of-three/
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 *
 */
#include <iostream>
using namespace std;

// reference from https://discuss.leetcode.com/topic/36150/1-line-java-solution-without-loop-recursion
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n>0 &&  1162261467%n==0);
    }
};

int main() {
    return 0;
}
