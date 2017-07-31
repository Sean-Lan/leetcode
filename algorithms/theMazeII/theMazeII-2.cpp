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
 * The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
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
#include <set>
#include <vector>
using namespace std;

static const int D[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

struct State {
    int x, y, d; // d is the distance from start
    bool operator<(const State &s) const {
        if (d != s.d) return d < s.d;
        if (x != s.x) return x < s.x;
        return y < s.y;
    }
    State(int x, int y, int d): x(x), y(y), d(d) {}
};

// Dijkstra with set implementation
// O(mn*max(m,n, log(mn))), may not be the tight complexity:
// at most O(m,n) points, each point runs in 4 directions O(max(m, n)), and update the set O(log(mn))
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        int x = start[0], y = start[1];
        distance[x][y] = 0;
        int d;

        set<State> Q;
        Q.insert(State(x, y, 0));

        while (!Q.empty()) {
            auto s = *Q.begin();
            Q.erase(Q.begin());
            for (auto &dir : D) {
                x = s.x; y = s.y; d = s.d;
                while (x>=0 && x<m && y>=0 && y<n && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    ++ d;
                }
                x -= dir[0];
                y -= dir[1];
                --d;
                if (distance[x][y] > d) {
                    if (distance[x][y] != INT_MAX)
                        Q.erase(Q.find(State(x, y, distance[x][y])));
                    distance[x][y] = d;
                    Q.insert(State(x, y, d));
                }
                if (x == destination[0] && y == destination[1]) return d;
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    Solution solution;
    vector<int> start = {0, 4}, destination = {4, 4};
    cout << solution.shortestDistance(maze, start, destination);
    return 0;
}
