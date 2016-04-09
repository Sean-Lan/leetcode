/**
 *
 * Sean
 * 2016-04-09
 *
 * https://leetcode.com/problems/maximal-square/
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 4.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// typical DP.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        int globalMax = 0;
        for (int i=0; i<matrix.size(); ++i)
            if (matrix[i][0] == '1')
                globalMax = dp[i][0] = 1;
        for (int j=0; j<matrix[0].size(); ++j)
            if (matrix[0][j] == '1')
                globalMax = dp[0][j] = 1;

        for (int i=1; i<matrix.size(); ++i)
            for (int j=1; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]),
                                    dp[i][j-1]) + 1;
                    globalMax = max(globalMax, dp[i][j]);
                }
            }
        return globalMax*globalMax;
    }
};

int main() {
}
