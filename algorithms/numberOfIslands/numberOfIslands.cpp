/**
 *
 * Sean
 * 2016-09-28
 *
 * https://leetcode.com/problems/number-of-islands/
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 *
 * Example 2:
 *
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 *
 */
#include <iostream>
#include <vector>
using namespace std;

const int MOVE[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> mark(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1' && !mark[i][j]) {
                    ++cnt;
                    dfsVisit(grid, mark, i, j);
                }
            }
        }
        return cnt;
    }

private:
    inline bool isValid(int i, int j, int m, int n) {
        return i>=0 && i<m && j>=0 && j<n;
    }

    void dfsVisit(vector<vector<char>>& grid, vector<vector<bool>>& mark, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        mark[i][j] = true;
        int nextI, nextJ;

        for (auto &direction : MOVE) {
            nextI = i + direction[0];
            nextJ = j + direction[1];
            if (isValid(nextI, nextJ, m, n) && grid[nextI][nextJ] == '1' && !mark[nextI][nextJ])
                dfsVisit(grid, mark, nextI, nextJ);
        }
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    Solution solution;
    cout << solution.numIslands(grid) << endl;
    return 0;
}
