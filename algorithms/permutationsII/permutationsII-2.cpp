/**
 *
 * Sean
 * 2017-09-02
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 *
 */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// DFS
class Solution {
    void sovle(vector<int> &path, vector<vector<int>> &res, vector<int> &nums, vector<bool> &mark) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        // take the search process as a Tree, every tree node must have different child to avoid duplicates
        unordered_set<int> used;
        for (int i=0; i<nums.size(); ++i) {
            if (mark[i] || used.count(nums[i])) continue;
            used.insert(nums[i]);
            mark[i] = true;
            path.push_back(nums[i]);
            sovle(path, res, nums, mark);
            path.pop_back();
            mark[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> mark(nums.size(), false);

        sovle(path, res, nums, mark);
        return res;
    }
};

int main() {
    return 0;
}
