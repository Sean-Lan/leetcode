/**
 *
 * Sean
 * 2017-06-25
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/#/description
 *
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.
 *
 * Example 1:
 * Input: [1,2,3]
 * Output: 6
 * Example 2:
 * Input: [1,2,3,4]
 * Output: 24
 * Note:
 * The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

// There are only two possible maximum values
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::greater<int>());
        int n = nums.size();
        int m1 = nums[0]*nums[1]*nums[2];
        int m2 = nums[0]*nums[n-2]*nums[n-1];
        return max(m1, m2);
    }
};

int main() {
    return 0;
}
