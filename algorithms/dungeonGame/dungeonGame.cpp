/**
 *
 * Sean
 * 2016-03-17
 *
 * https://leetcode.com/problems/dungeon-game/
 *
 * The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
 * The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially
 * positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
 *
 * The knight has an initial health point represented by a positive integer.
 * If at any point his health point drops to 0 or below, he dies immediately.
 *
 * Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
 * other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
 *
 * In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
 *
 * Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
 *
 *
 * Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
 *
 * For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows
 * the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
 *
 * -2(K)  -3   3
 * -5    -10   1
 * 10     30  -5(P)
 *
 * Notes:
 *
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *
 * Use DP.
 * dp[i][j] means the minimun health needed to survive at dungeon[i][j].
 * The order is from right to left and from bottom to up.
 *
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 1));

        dp[m-1][n-1] = max(1-dungeon[m-1][n-1], 1);

        // initialize the right-most line
        for (int i=m-2; i>=0; --i) {
            dp[i][n-1] = dp[i+1][n-1]-dungeon[i][n-1];
            dp[i][n-1] = max(1, dp[i][n-1]);
        }

        // initialize the bottom line
        for (int i=n-2; i>=0; --i) {
            dp[m-1][i] = dp[m-1][i+1]-dungeon[m-1][i];
            dp[m-1][i] = max(1, dp[m-1][i]);
        }

        // from right to left and from bottom to up
        for (int j=n-2; j>=0; --j) {
            for (int i=m-2; i>=0; --i) {
                dp[i][j] = min(
                        dp[i][j+1]-dungeon[i][j],
                        dp[i+1][j]-dungeon[i][j]
                        );
                dp[i][j] = max(dp[i][j], 1);
            }
        }
        return dp[0][0];
    }
};

int main() {
    /* vector<vector<int>> dungeon = */
    /*     { */
    /*       {-2, -3, 3}, */
    /*       {-5, -10, 1}, */
    /*       {10, 30, -5} */
    /*     }; */
    vector<vector<int>> dungeon = { {100} };
    Solution solution;
    cout << solution.calculateMinimumHP(dungeon) << endl;
    return 0;
}
