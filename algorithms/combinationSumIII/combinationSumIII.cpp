/**
 *
 * Sean
 * 2016-05-04
 *
 * https://leetcode.com/problems/combination-sum-iii/
 *
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9
 * can be used and each combination should be a unique set of numbers.
 *
 * Ensure that numbers within the set are sorted in ascending order.
 *
 *
 * Example 1:
 *
 * Input: k = 3, n = 7
 *
 * Output:
 *
 * [[1,2,4]]
 *
 * Example 2:
 *
 * Input: k = 3, n = 9
 *
 * Output:
 *
 * [[1,2,6], [1,3,5], [2,3,4]]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

void printResults(vector<vector<int>> &results) {
    for (auto &iv : results) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

// DFS with backtracking.
class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> results;
            vector<int> current;
            dfs(current, results, 1, k, n);
            return results;
        }

    private:
        void dfs(vector<int> &current, vector<vector<int>> &results, int i, int k, int n) {
            if (current.size() == k && n == 0) {
                results.push_back(current);
                return;
            }
            if (i <= 9 && i <= n) {
                if (current.size() < k) {
                    current.push_back(i);
                    dfs(current, results, i+1, k, n-i);
                    current.pop_back();
                }
                dfs(current, results, i+1, k, n);
            }
        }
};

int main() {
    Solution solution;
    auto results = solution.combinationSum3(3, 9);
    printResults(results);
}
