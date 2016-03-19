/**
 *
 * Sean
 * 2016-03-19
 *
 * https://leetcode.com/problems/minimum-path-sum/
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to
 * bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DP, from top left to bottom right.
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            if (grid.empty() || grid[0].empty()) return 0;
            vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
            int m = grid.size();
            int n = grid[0].size();
            dp[0][0] = grid[0][0];
            for (int i=1; i<m; ++i)
                dp[i][0] = dp[i-1][0] + grid[i][0];

            for (int i=1; i<n; ++i)
                dp[0][i] = dp[0][i-1] + grid[0][i];

            for (int i=1; i<m; ++i) {
                for (int j=1; j<n; ++j) {
                    dp[i][j] = min(dp[i-1][j]+grid[i][j],
                                   dp[i][j-1]+grid[i][j]);
                }
            }
            return dp[m-1][n-1];
        }
};

int main() {
}
