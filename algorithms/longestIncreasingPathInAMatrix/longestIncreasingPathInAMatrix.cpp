/**
 *
 * Sean
 * 2017-06-10
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/#/description
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 *
 * Example 1:
 *
 * nums = [
 *   [9,9,4],
 *   [6,6,8],
 *   [2,1,1]
 * ]
 * Return 4
 * The longest increasing path is [1, 2, 6, 9].
 *
 * Example 2:
 *
 * nums = [
 *   [3,4,5],
 *   [3,2,6],
 *   [2,2,1]
 * ]
 * Return 4
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 *
 */
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

static const int dirs[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

// DFS with DP
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;

        // dp[i][j] means the length of longest increasing path starting with (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // need to explictly declare the type of dfs since we use dfs inside itself
        function<int(int, int)> dfs = [&](int i, int j) {
            if (dp[i][j]) return dp[i][j];

            int longest = 0;
            int nextI, nextJ;
            int cur = matrix[i][j];
            for (auto d : dirs) {
                nextI = i+d[0];
                nextJ = j+d[1];
                if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || cur >= matrix[nextI][nextJ]) continue;
                longest = max(longest, dfs(i+d[0], j+d[1]));
            }
            dp[i][j] = longest + 1;
            return dp[i][j];
        };

        int maxLen = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                maxLen = max(maxLen, dfs(i, j));
            }
        }
        return maxLen;
    }
};

int main() {
    return 0;
}
