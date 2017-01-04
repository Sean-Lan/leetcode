/**
 *
 * Sean
 * 2017-01-04
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [2,3]
 *
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void printVec(vector<int> &nums) {
    for (auto &i : nums) cout << i << " ";
    cout << endl;
}

// One pass in-place sort, be careful about duplicates.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> res;
        int len = nums.size();
        for (int i=0; i<len; ++i) {
            while (nums[i]-1 != i) {
                if (nums[nums[i]-1] == nums[i]) {
                    res.insert(nums[i]);
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 4,3,2,7,8,2,3,1 };
    vector<int> res = solution.findDuplicates(nums);
    printVec(res);
    return 0;
}
