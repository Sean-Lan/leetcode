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

// O(n) in place sort.
// Every swap, we place one num at its right position, so total time complexity is O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            while (nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }

        vector<int> result;
        for (int i=0; i<n; ++i) {
            if (nums[i] != i+1) result.push_back(i+1);
        }
        return result;
    }
};

int main() {
    vector<int> nums = { 4,3,2,7,8,2,3,1 };
    Solution solution;
    vector<int> result = solution.findDisappearedNumbers(nums);
    for (auto &i : result) cout << i << " ";
    cout << endl;
    return 0;
}
