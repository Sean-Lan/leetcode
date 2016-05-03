/**
 *
 * Sean
 * 2016-05-03
 *
 * https://leetcode.com/problems/subsets/
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printResult(const vector<vector<int>> &results) {
    for (auto &iv : results) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

// Typical backtracking
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> current;
            vector<vector<int>> results;
            sort(nums.begin(), nums.end());
            dfs(0, current, results, nums);
            return results;
        }
    private:
        void dfs(int n, vector<int> &current, vector<vector<int>> &results, vector<int> &nums) {
            if (n == nums.size()) {
                results.push_back(current);
                return;
            }
            current.push_back(nums[n]);
            ++n;
            dfs(n, current, results, nums);
            current.pop_back();
            dfs(n, current, results, nums);
        }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    auto results = solution.subsets(nums);
    printResult(results);
}
