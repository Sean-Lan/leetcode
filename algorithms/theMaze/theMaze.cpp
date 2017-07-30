/**
 *
 * Sean
 * 2017-07-30
 *
 * https://leetcode.com/problems/the-maze/description/
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
 *
 * Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
 *
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
 *
 * Example 1
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 *
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (4, 4)
 *
 * Output: true
 * Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
 *
 * Example 2
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 *
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (3, 2)
 *
 * Output: false
 * Explanation: There is no way for the ball to stop at the destination.
 *
 * Note:
 * There is only one ball and one destination in the maze.
 * Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
 * The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
 * The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// DFS
// use mark (x, y, d) triplets to prune
static const int D[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

class Solution {
    typedef vector<bool> vb;
    typedef vector<vb> vvb;
    vvb mark[4];
    int targetX, targetY;
    int m, n;
    bool isWall(int x, int y, vector<vector<int>> &maze) {
        return x<0 || x>=m || y<0 || y>=n || maze[x][y] == 1;
    }
    bool dfs(int x, int y, int d, vector<vector<int>> &maze) {
        int nextX = x + D[d][0];
        int nextY = y + D[d][1];

        if (x == targetX && y == targetY) {
            if (isWall(nextX, nextY, maze)) return true;
        }

        if (mark[d][x][y]) return false;
        mark[d][x][y] = true;

        if (isWall(nextX, nextY, maze)) {
            for (int i=0; i<4; ++i) {
                if (i == d) continue;
                if (dfs(x, y, i, maze)) return true;
            }
        } else {
            return !mark[d][nextX][nextY] && dfs(nextX, nextY, d, maze);
        }
        return false;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze[0].size();
        fill(mark, mark+4, vvb(m, vb(n, false)));
        targetX = destination[0];
        targetY = destination[1];

        for (int d=0; d<4; ++d) {
            if (dfs(start[0], start[1], d, maze)) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
