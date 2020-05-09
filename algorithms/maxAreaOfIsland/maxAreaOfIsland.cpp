/**
 *
 * Sean
 * 2020-05-09
 *
 * https://leetcode.com/problems/max-area-of-island/
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 *
 * Example 1:
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
 * Example 2:
 *
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * Note: The length of each dimension in the given grid does not exceed 50.
*
*/
#include <iostream>
#include <vector>
using namespace std;

const int directions[4][2] = {
  {0, 1},
  {1, 0},
  {-1, 0},
  {0, -1}
};


// DFS
class Solution {
  bool isValid(int x, int y, int m, int n) {
    return x >=0 && x < m && y >=0 && y < n;
  }

  int area(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &mark) {
    mark[i][j] = true;
    int cnt = 1;
    for (int k=0; k<4; ++k) {
      int nextI = i + directions[k][0];
      int nextJ = j + directions[k][1];
      if (isValid(nextI, nextJ, grid.size(), grid[0].size()) && grid[nextI][nextJ] && !mark[nextI][nextJ]) {
        cnt += area(nextI, nextJ, grid, mark);
      }
    }
    return cnt;
  }
  public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> mark(m, vector<bool>(n, false));
    int maxArea = 0;
    for (int i=0; i<m; ++i) {
      for(int j=0; j<n; ++j) {
        if (grid[i][j] && !mark[i][j]) {
          maxArea = max(maxArea, area(i, j, grid, mark));
        }
      }
    }
    return maxArea;
  }
};

int main() {
  return 0;
}
