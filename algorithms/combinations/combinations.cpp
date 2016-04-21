#include <iostream>
/**
 *
 * Sean
 * 2016-04-21
 *
 * https://leetcode.com/problems/combinations/
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 */
#include <vector>
using namespace std;

// backtracking.
class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<int> current;
            vector<vector<int>> results;
            dfs(current, results, k, 1, n);
            return results;
        }
    private:
        void dfs(vector<int> &current, vector<vector<int>> &results, int cnt, int index, int n) {
            // there are not enough numbers from index to n.
            if (index + cnt > n + 1)
                return;
            // current contains enough numbers.
            if (cnt == 0) {
                results.push_back(current);
                return;
            }

            current.push_back(index);
            dfs(current, results, cnt-1, index+1, n);
            current.pop_back();
            dfs(current, results, cnt, index+1, n);
        }
};

void printResults(vector<vector<int>> &results) {
    for (auto &iv : results) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    Solution solution;
    auto results = solution.combine(4,2);
    printResults(results);
}
