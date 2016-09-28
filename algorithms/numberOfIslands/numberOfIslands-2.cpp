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
#include <queue>
using namespace std;

static const int MOVE[4][2] {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty() || grid[0].empty())
                return 0;
            int m = grid.size();
            int n = grid[0].size();
            int cnt = 0;
            for (int i=0; i<m; ++i)
                for (int j=0; j<n; ++j)
                    if (grid[i][j] == '1') {
                        ++cnt;
                        bfsVisit(grid, i, j);
                    }
            return cnt;
        }

    private:
        // **NOTE**: It's critical that you should mark a point visited the time you push it into the queue,
        // instead of pop it from the queue. Otherwise, the same point would be push into the queue for mutiple
        // times.
        void bfsVisit(vector<vector<char>> &grid, int i, int j) {
            int m = grid.size();
            int n = grid[0].size();
            queue<pair<int, int>> aQueue;
            aQueue.push({i, j});
            grid[i][j] = 0;

            int nextI, nextJ;
            while (!aQueue.empty()) {
                i = aQueue.front().first;
                j = aQueue.front().second;
                aQueue.pop();
                for (auto delta : MOVE) {
                    nextI = i+delta[0];
                    nextJ = j+delta[1];
                    if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n
                            && grid[nextI][nextJ] == '1') {
                        grid[nextI][nextJ] = '0';
                        aQueue.push({nextI, nextJ});
                    }
                }
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
