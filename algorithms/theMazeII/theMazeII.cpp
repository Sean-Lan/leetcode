/**
 *
 * Sean
 * 2017-07-31
 *
 * https://leetcode.com/problems/the-maze-ii/description/
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
 *
 * Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.
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
 * Output: 12
 * Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
 *              The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
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
 * Output: -1
 * Explanation: There is no way for the ball to stop at the destination.
 *
 * Note:
 * There is only one ball and one destination in the maze.
 * Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
 * The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
 * The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int D[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

struct State {
    int x, y, d;
    State(int x, int y, int d): x(x), y(y), d(d) {}
};

// BFS
// O(m*n) since a grid at most be visited 4 times
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<bool>> mark[4];
        fill(mark, mark+4, vector<vector<bool>>(m, vector<bool>(n, false)));
        queue<State> aQueue;
        int x = start[0], y = start[1], d;

        for (d=0; d<4; ++d) {
            aQueue.push(State(x, y, d));
            mark[d][x][y] = true;
        }

        auto isWall = [&](int x, int y) {
            return x<0 || x>=m || y<0 || y>=n || maze[x][y] == 1;
        };

        int level = 0;
        int sz;
        int nextX, nextY;
        while (!aQueue.empty()) {
            sz = aQueue.size();
            for (int i=0; i<sz; ++i) {
                auto cur = aQueue.front();
                aQueue.pop();
                x = cur.x; y = cur.y; d = cur.d;
                nextX = x + D[d][0];
                nextY = y + D[d][1];

                if (isWall(nextX, nextY)) {
                    if (x == destination[0] && y == destination[1]) {
                        return level;
                    }
                    for (int j=0; j<4; ++j) {
                        if (j == d) continue;
                        nextX = x + D[j][0];
                        nextY = y + D[j][1];
                        if (!isWall(nextX, nextY) && !mark[j][nextX][nextY]) {
                            mark[j][nextX][nextY] = true;
                            aQueue.push(State(nextX, nextY, j));
                        }
                    }
                } else if (!mark[d][nextX][nextY]) {
                    mark[d][nextX][nextY] = true;
                    aQueue.push(State(nextX, nextY, d));
                }
            }
            ++ level;
        }

        return -1;
    }
};

int main() {
    return 0;
}
