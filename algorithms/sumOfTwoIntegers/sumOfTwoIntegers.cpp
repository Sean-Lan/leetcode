/**
 *
 * Sean
 * 2016-07-07
 *
 * https://leetcode.com/problems/sum-of-two-integers/
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 * Example:
 * Given a = 1 and b = 2, return 3.
 *
 */

// Use bit manipulation, reference to
// https://discuss.leetcode.com/topic/49771/java-simple-easy-understand-solution-with-explanation
class Solution {
public:
    int getSum(int a, int b) {
        return (b==0)? a : getSum(a^b, (a&b)<<1);
    }
};

int main() {}
