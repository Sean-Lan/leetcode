/**
 *
 * Sean
 * 2017-06-08
 *
 * https://leetcode.com/problems/paint-house-ii/#/description
 *
 * There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
 *
 * Note:
 * All costs are positive integers.
 *
 * Follow up:
 * Could you solve it in O(nk) runtime?
 *
 */
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

// DP
// save smallest cost and second smallest cost to obtain the min cost of the previous round not with the same color in O(1) time complexity
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int k = costs[0].size();
        if (k == 1) return costs[0][0];
        int n = costs.size();
        vector<int> dp(k, 0);
        pair<int, int> min1 = {-1, 0}, min2 = {-1, 0};
        pair<int, int> curMin1, curMin2;
        for (int i=0; i<n; ++i) {
            curMin1.second = curMin2.second = INT_MAX;
            for (int j=0; j<k; ++j) {
                if (j != min1.first) {
                    dp[j] = min1.second + costs[i][j];
                } else {
                    dp[j] = min2.second + costs[i][j];
                }
                if (dp[j] <= curMin1.second) {
                    curMin2 = curMin1;
                    curMin1.first = j;
                    curMin1.second = dp[j];
                } else if (dp[j] <= curMin2.second) {
                    curMin2.first = j;
                    curMin2.second = dp[j];
                }
            }
            min1 = curMin1;
            min2 = curMin2;
        }
        return min(curMin1.second, curMin2.second);
    }
};

int main() {
    return 0;
}
