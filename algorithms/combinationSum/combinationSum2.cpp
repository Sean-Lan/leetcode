/**
 *
 * Sean
 * 2020-04-17
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
  void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& cur, int index, int r) {
    if (r == 0) {
      res.push_back(cur);
      return;
    }

    if (index == candidates.size()) return;

    int v = candidates[index];

    int cnt = 0; // 0 means don't use v
    while (r >= cnt * v) {
      for (int i=0; i<cnt; ++i) cur.push_back(v);
      dfs(candidates, res, cur, index+1, r - cnt*v);
      for (int i=0; i<cnt; ++i) cur.pop_back();
      ++cnt;
    }
  }
  public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs(candidates, res, cur, 0, target);
    return res;
  }
};

int main() {
  return 0;
}
