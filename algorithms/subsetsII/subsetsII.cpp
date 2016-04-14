/**
 *
 * Sean
 * 2016-04-14
 *
 * https://leetcode.com/problems/subsets-ii/
 *
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// DFS with backtracking.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (auto &i : nums)
            ++cnts[i];
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<int> current;
        vector<vector<int>> results;
        dfs(current, results, nums, cnts, 0);
        return results;
    }

private:
    void dfs(vector<int> &current, vector<vector<int>> &results, vector<int> &nums,
            unordered_map<int, int> &cnts, int index) {
        if (index == nums.size()) {
            results.push_back(current);
            return;
        }
        int nextVal = nums[index];
        int cnt = cnts[nextVal];
        ++index;
        for (int i=0; i<=cnt; ++i) {
            for (int j=0; j<i; ++j)
                current.push_back(nextVal);
            dfs(current, results, nums, cnts, index);
            for (int j=0; j<i; ++j)
                current.pop_back();
        }
    }
};

void printResults(vector<vector<int>> &results) {
    cout << "[" << endl;
    for (auto &iv : results) {
        cout << "\t[";
        for (auto &i : iv)
            cout << i << ",";
        cout << "]," << endl;;
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {1, 2, 2};
    Solution solution;
    auto results = solution.subsetsWithDup(nums);
    printResults(results);
}
