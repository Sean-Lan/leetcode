/**
 *
 * Sean
 * 2017-07-28
 *
 * https://leetcode.com/problems/increasing-subsequences/tabs/description
 *
 * Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
 *
 * Example:
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 *
 * Note:
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
 *
 */
#include <vector>
#include <unordered_set>
using namespace std;

// every time we pick one number from nums[pos:] that appears the first time to remove the reduadancy.
class Solution {
    void dfs(vector<vector<int>> &res, vector<int> &path, int pos, vector<int> &nums) {
        if (path.size() > 1) res.push_back(path);
        int n = nums.size();
        unordered_set<int> mark;
        int cur;
        for (int i=pos; i<n; ++i) {
            cur = nums[i];
            if (!mark.count(cur)) {
                mark.insert(cur);
                if (path.empty() || path.back() <= cur) {
                    path.push_back(cur);
                    dfs(res, path, i+1, nums);
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, 0, nums);
        return res;
    }
};

int main() {
    return 0;
}
