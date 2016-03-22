/**
 *
 * Sean
 * 2016-03-22
 *
 * https://leetcode.com/problems/unique-paths/
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.
 *
 * How many possible unique paths are there?
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// DP
class Solution {
    public:
        int uniquePaths(int m, int n) {
            if (m==0 || n==0) return 1;
            vector<vector<int>> dp(m, vector<int>(n));
            dp[0][0] = 1;
            for (int i=1; i<m; ++i)
                dp[i][0] = 1;
            for (int j=1; j<n; ++j)
                dp[0][j] = 1;

            for (int i=1; i<m; ++i)
                for (int j=1; j<n; ++j)
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            return dp[m-1][n-1];
        }
};

int main() {}
