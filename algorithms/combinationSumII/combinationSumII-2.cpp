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

// use a unordered_map to maintain the existing count of each value of candiates
class Solution {
    private:
        void dfs(vector<int> &candidates, const int &target, int step,
                vector<int> &currentResult, int currentSum, vector<vector<int>> &results, unordered_map<int, int> &valueCnt) {
            if (currentSum == target) {
                results.push_back(currentResult);
                return;
            }
            if (step >= candidates.size() || currentSum > target)
                return;
            int currentValue = candidates[step];
            int currentCnt = valueCnt[currentValue];
            for (int i=0; i<=currentCnt; ++i) {
                for (int j=0; j<i; ++j)
                    currentResult.push_back(currentValue);
                dfs(candidates, target, step+1, currentResult, currentSum+currentValue*i, results, valueCnt);
                for (int j=0; j<i; ++j)
                    currentResult.pop_back();
            }
        }

    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> results;
            vector<int> currentResult;
            unordered_map<int, int> valueCnt;
            for (auto &i : candidates)
                ++valueCnt[i];
            candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
            dfs(candidates, target, 0, currentResult, 0, results, valueCnt);
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
