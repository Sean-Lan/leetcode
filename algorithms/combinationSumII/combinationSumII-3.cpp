/**
 *
 * Sean
 * 2016-03-05
 *
 * https://leetcode.com/problems/combination-sum-ii/
 *
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// the for loop in dfs make sure no duplicates exist and won't miss any
// possible solution.
class Solution {
    private:
        void dfs(vector<int> &candidates, int target, int index,
                vector<int> &currentResult, vector<vector<int>> &results) {
            if (target == 0) {
                results.push_back(currentResult);
                return;
            }
            if (index>=candidates.size() || target<0)
                return;
            int currentValue = candidates[index];
            int len = candidates.size();
            for (int i=index; i<len; ++i) {
                if (i!=index && candidates[i]==candidates[i-1])
                    continue;
                currentResult.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], i+1, currentResult, results);
                currentResult.pop_back();
            }
        }

    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> results;
            vector<int> currentResult;
            dfs(candidates, target, 0, currentResult, results);
            return results;
        }
};

void printResults(const vector<vector<int>> &results) {
    for (auto &iv : results) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution solution;
    printResults(solution.combinationSum2(candidates, target));

    return 0;
}
