/**
 *
 * Sean
 * 2016-12-28
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Reference to https://discuss.leetcode.com/topic/65738/java-accepted-simple-solution
// In the first pass, mark the number at shown number position negative.
// In the second pass, check whether the number is positive or negative.
class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int val;
            for (auto &num : nums) {
                val = abs(num)-1;
                if (nums[val] > 0) nums[val] = -nums[val];
            }
            vector<int> result;
            int n = nums.size();
            for (int i=0; i<n; ++i) {
                if (nums[i] > 0) result.push_back(i+1);
            }
            return result;
        }
};

int main() {
    return 0;
}
