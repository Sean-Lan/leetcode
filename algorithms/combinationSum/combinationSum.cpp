/**
 *
 * Sean
 * 2016-02-27
 *
 * https://leetcode.com/problems/combination-sum/
 *
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS and backtracking.
class Solution {
    private:
        void recursiveSearch(vector<vector<int>> &results, vector<int> &candidates, vector<int> &currentResult, int &target, int n) {
            if (target == 0) {
                results.push_back(currentResult);
                return;
            }

            if (n >= candidates.size())
                return;

            int currentNumber = candidates[n];
            int ratio = target/currentNumber;
            for (int i=0; i<=ratio; ++i) {
                for (int j=0; j<i; ++j)
                    currentResult.push_back(currentNumber);
                target -= currentNumber*i;
                recursiveSearch(results, candidates, currentResult, target, n+1);
                target += currentNumber*i;
                for (int j=0; j<i; ++j)
                    currentResult.pop_back();
            }
        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            if (candidates.empty()) return {};
            sort(candidates.begin(), candidates.end());
            candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

            vector<vector<int>> results;
            vector<int> currentResult;
            recursiveSearch(results, candidates, currentResult, target, 0);
            return results;
        }
};

void printResults (const vector<vector<int>> &results) {
    for (auto &iv : results) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution solution;
    printResults(solution.combinationSum(candidates, target));
}
