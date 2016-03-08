/**
 *
 * Sean
 * 2016-03-08
 *
 * https://leetcode.com/problems/permutations-ii/
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// DFS
class Solution {
    private:
        void dfs(vector<int> &uniqueNumbers, unordered_map<int, int> &counts,
                int step, const int &size, vector<int> &currentResult, vector<vector<int>> &results) {
            if (step == size) {
                results.push_back(currentResult);
                return;
            }

            for (auto &num : uniqueNumbers) {
                if (counts[num]) {
                    currentResult.push_back(num);
                    --counts[num];
                    dfs(uniqueNumbers, counts, step+1, size, currentResult, results);
                    ++counts[num];
                    currentResult.pop_back();
                }
            }
        }
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            if (nums.empty()) return {};
            sort(nums.begin(), nums.end());
            unordered_map<int, int> counts;
            int size = nums.size();
            for (auto &i : nums)
                ++counts[i];
            nums.erase(unique(nums.begin(), nums.end()), nums.end());
            vector<vector<int>> results;
            vector<int> currentResult;
            dfs(nums, counts, 0, size, currentResult, results);
            return results;
        }
};

void printResults (const vector<vector<int>> &results) {
    for (auto &iv : results) {
        for (auto &i: iv)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    Solution solution;
    vector<int> nums = {1,1,2};
    printResults(solution.permuteUnique(nums));
}
