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
#include <unordered_set>
using namespace std;

// use a unordered_set to remove duplicates
struct VectorHash {
    size_t operator() (const vector<int> &intVec) const {
        size_t ret = 0;
        for (auto &i : intVec)
            ret = ret*31 + i;
        return ret;
    }
};

class Solution {
    private:
        void dfs(vector<int> &candidates, const int &target, int step,
                vector<int> &currentResult, int currentSum, vector<vector<int>> &results, unordered_set<vector<int>, VectorHash> &mark) {
            if (currentSum == target && !mark.count(currentResult)) {
                mark.insert(currentResult);
                results.push_back(currentResult);
                return;
            }
            if (step >= candidates.size() || currentSum > target)
                return;
            int currentValue = candidates[step];
            // use this one
            currentResult.push_back(currentValue);
            dfs(candidates, target, ++step, currentResult, currentSum+currentValue, results, mark);
            currentResult.pop_back();
            // not use this one
            dfs(candidates, target, step, currentResult, currentSum, results, mark);
        }

    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> results;
            vector<int> currentResult;
            unordered_set<vector<int>, VectorHash> mark;
            dfs(candidates, target, 0, currentResult, 0, results, mark);
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
