/**
 *
 * Sean
 * 2017-07-07
 *
 * https://leetcode.com/problems/bomb-enemy/#/description
 *
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
 * Note that you can only put the bomb at an empty cell.
 *
 * Example:
 * For the given grid
 *
 * 0 E 0 0
 * E 0 W E
 * 0 E 0 0
 *
 * return 3. (Placing a bomb at (1,1) kills 3 enemies)
 *
 */
#include <vector>
#include <queue>
using namespace std;

// DP
// O(m*n)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();

        // dp1[i][j] (1<=i<=m && 1<=j<=m) means the number of enemies to the prev-left and prev-top wall
        // dp2[i][j] (1<=i<=m && 1<=j<=m) means the number of enemies to the prev-right and prev-bottom wall
        vector<vector<pair<int, int>>> dp1, dp2;
        dp1 = dp2 = vector<vector<pair<int, int>>>(m+2, vector<pair<int, int>>(n+2, {0, 0}));

        queue<pair<int, int>> aQueue;

        // from  top-left to bottom-right
        char c;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                c = grid[i-1][j-1];
                auto &cur = dp1[i][j];
                if (c == 'E') {
                    cur.first = dp1[i-1][j].first + 1;
                    cur.second = dp1[i][j-1].second + 1;
                } else if (c == 'W') {
                    cur.first = 0;
                    cur.second = 0;
                } else {
                    aQueue.push({i, j});
                    cur.first = dp1[i-1][j].first;
                    cur.second = dp1[i][j-1].second;
                }
            }
        }

        // from  bottom-right to top-left
        for (int i=m; i>=1; --i) {
            for (int j=n; j>=1; --j) {
                c = grid[i-1][j-1];
                auto &cur = dp2[i][j];
                if (c == 'E') {
                    cur.first = dp2[i+1][j].first + 1;
                    cur.second = dp2[i][j+1].second + 1;
                } else if (c == 'W') {
                    cur.first = 0;
                    cur.second = 0;
                } else {
                    cur.first = dp2[i+1][j].first;
                    cur.second = dp2[i][j+1].second;
                }
            }
        }

        int res = 0;
        int x, y;
        int cnt = 0;
        while (!aQueue.empty()) {
            cnt = 0;
            x = aQueue.front().first;
            y = aQueue.front().second;
            aQueue.pop();
            cnt += dp1[x][y].first;
            cnt += dp1[x][y].second;
            cnt += dp2[x][y].first;
            cnt += dp2[x][y].second;
            if (cnt > res) res = cnt;
        }

        return res;
    }
};

int main() {
    return 0;
}
