/**
 *
 * Sean
 * 2016-11-24
 *
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 *
 */
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n);
            res[0] = 1;
            for (int i=1; i<n; ++i) {
                res[i] = res[i-1] * nums[i-1];
            }

            int right = 1;
            for (int i=n-1; i>=0; --i) {
                res[i] *= right;
                right *= nums[i];
            }

            return res;
        }
};

int main() {
    return 0;
}
