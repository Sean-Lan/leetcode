/**
 *
 * Sean
 * 2016-07-07
 *
 * https://leetcode.com/problems/single-number-ii/
 *
 * Given an array of integers, every element appears three times except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 */
#include <iostream>
#include <vector>

using namespace std;

// Reference to this post:
// https://discuss.leetcode.com/topic/11877/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1= 0;
        int x2 = 0;
        int mask = 0;
        for (auto &i : nums) {
            x2 ^= (x1 & i);
            x1 ^= i;
            mask = ~(x2&x1);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};

int main() {}
