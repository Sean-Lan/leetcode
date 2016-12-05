/**
 *
 * Sean
 * 2016-12-05
 *
 * https://leetcode.com/problems/paint-house/
 *
 * There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
 *
 * Note:
 * All costs are positive integers.
 *
 */
#include <vector>
using namespace std;

// classical dp.
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0] = costs[0];
        for (int i=1; i<n; ++i) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};

int main() {
    return 0;
}
