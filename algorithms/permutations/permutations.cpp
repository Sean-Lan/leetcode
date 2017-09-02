/**
 *
 * Sean
 * 2017-09-02
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// typical backtracking
class Solution {
    void sovle(vector<vector<int>> &res, vector<int> &path, vector<int> &nums, vector<bool> &mark) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (!mark[i]) {
                mark[i] = true;
                path.push_back(nums[i]);
                sovle(res, path, nums, mark);
                path.pop_back();
                mark[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> mark(n, false);
        vector<int> path;
        vector<vector<int>> res;
        sovle(res, path, nums, mark);
        return res;
    }
};

int main() {
    return 0;
}
