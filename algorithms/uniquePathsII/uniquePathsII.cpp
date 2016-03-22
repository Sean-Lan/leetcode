/**
 *
 * Sean
 * 2016-03-22
 *
 * https://leetcode.com/problems/unique-paths-ii/
 *
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// DP
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> dp(m+1, vector<int>(n+1));
            dp[0][1] = 1;
            for (int i=1; i<=m; ++i)
                for (int j=1; j<=n; ++j) {
                    if (obstacleGrid[i-1][j-1])
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            return dp[m][n];
        }
};

int main() {
    vector<vector<int>> obstacleGrid =
        {{0,0,0},{0,1,0},{0,0,0}};
    Solution solution;
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
}
