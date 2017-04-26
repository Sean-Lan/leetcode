/**
 *
 * Sean
 * 2017-04-26
 *
 * https://leetcode.com/problems/array-partition-i/#/description
 *
 * Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 *
 * Example 1:
 * Input: [1,4,3,2]
 *
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4.
 *
 * Note:
 *  n is a positive integer, which is in the range of [1, 10000].
 *  All the integers in the array will be in the range of [-10000, 10000].
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += nums[2*i];
        }
        return sum;
    }
};

int main() {
    return 0;
}
