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
class Solution {
    typedef vector<bool> vb;
    typedef vector<vb> vvb;
    vvb mark;
    int m, n;
    int targetX, targetY;
    bool dfs(int x, int y , vector<vector<int>> &maze) {
        if (x == targetX && y == targetY) return true;
        if (mark[x][y]) return false;
        mark[x][y] = true;

        int l = y-1;
        while (l>=0 && maze[x][l] == 0) --l;
        if (dfs(x, l+1, maze)) return true;

        int r = y+1;
        while (r<n && maze[x][r] == 0) ++r;
        if (dfs(x, r-1, maze)) return true;

        int u = x-1;
        while (u>=0 && maze[u][y] == 0) --u;
        if (dfs(u+1, y, maze)) return true;

        int d = x+1;
        while (d<m && maze[d][y] == 0) ++d;
        if (dfs(d-1, y, maze)) return true;

        return false;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze[0].size();
        targetX = destination[0];
        targetY = destination[1];

        mark = vvb(m, vb(n, false));
        return dfs(start[0], start[1], maze);
    }
};

int main() {
    return 0;
}
