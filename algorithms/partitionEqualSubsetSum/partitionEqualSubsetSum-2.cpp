/**
 *
 * Sean
 * 2016-10-10
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/
 *
 * Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 *
 * Note:
 * Both the array size and each of the array element will not exceed 100.
 *
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * Example 2:
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// DFS solution

class Solution {
    private:
        bool dfs(int index, int target, vector<int> &nums) {
            // remember to prune
            if (target <= 0) return target==0;
            if (index == nums.size()) return false;
            if (dfs(index+1, target-nums[index], nums)) return true;
            return dfs(index+1, target, nums);
        }

    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for (auto &n : nums) sum += n;
            if (sum&1) return false;
            // due to symmetry.
            return dfs(1, (sum>>1)-nums[0], nums);
        }
};

int main() {
    Solution solution;
    vector<int> nums = { 17,58,41,75,61,70,52,7,38,11,40,58,44,45,4,81,67,54,79,80,15,3,14,16,9,66,69,41,72,37,28,3,33,90,56,12,72,49,35,22,49,27,49,82,41,77,100,82,18,95,24,51,37,2,34,82,70,53,73,32,90,98,81,22,73,76,79,40,27,62,45,96,36,15,63,28,54,88,63,37,58,9,62,98,93,72,99,53,91,29,61,31,11,42,20,35,50,68,10,86 };
    cout << solution.canPartition(nums) << endl;
}
