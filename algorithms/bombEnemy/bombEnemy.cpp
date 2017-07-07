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
#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// binary search, O(m*n*log(m)*log(n))
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();

        // wall index => enemy count before previous wall to current wall
        vector<map<int, int>> rowW(m);
        vector<map<int, int>> colW(n);
        int cnt = 0;
        queue<pair<int, int>> emptyPos;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 'E') {
                    ++ cnt;
                } else if (grid[i][j] == 'W') {
                    rowW[i][j] = cnt;
                    cnt = 0;
                } else {
                    emptyPos.push({i, j});
                }
            }
            rowW[i][INT_MAX] = cnt;
            cnt = 0;
        }

        for (int j=0; j<n; ++j) {
            for (int i=0; i<m; ++i) {
                if (grid[i][j] == 'E') {
                    ++ cnt;
                } else if (grid[i][j] == 'W') {
                    colW[j][i] = cnt;
                    cnt = 0;
                }
            }
            colW[j][INT_MAX] = cnt;
            cnt = 0;
        }

        int res = 0;

        int x, y;
        while (!emptyPos.empty()) {
            cnt = 0;
            x = emptyPos.front().first;
            y = emptyPos.front().second;
            emptyPos.pop();

            auto it = rowW[x].lower_bound(y);
            cnt += it->second;

            it = colW[y].lower_bound(x);
            cnt += it->second;

            if (cnt > res) res = cnt;
        }

        return res;
    }
};

int main() {
    return 0;
}
