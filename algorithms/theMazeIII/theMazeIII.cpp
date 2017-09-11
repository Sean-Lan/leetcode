/**
 *
 * Sean
 * 2017-09-11
 *
 * https://leetcode.com/problems/the-maze-iii/description/
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.
 *
 * Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".
 *
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.
 *
 * Example 1
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 0 0 0
 * 1 1 0 0 1
 * 0 0 0 0 0
 * 0 1 0 0 1
 * 0 1 0 0 0
 *
 * Input 2: ball coordinate (rowBall, colBall) = (4, 3)
 * Input 3: hole coordinate (rowHole, colHole) = (0, 1)
 *
 * Output: "lul"
 * Explanation: There are two shortest ways for the ball to drop into the hole.
 * The first way is left -> up -> left, represented by "lul".
 * The second way is up -> left, represented by 'ul'.
 * Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".
 *
 * Example 2
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 0 0 0
 * 1 1 0 0 1
 * 0 0 0 0 0
 * 0 1 0 0 1
 * 0 1 0 0 0
 *
 * Input 2: ball coordinate (rowBall, colBall) = (4, 3)
 * Input 3: hole coordinate (rowHole, colHole) = (3, 0)
 * Output: "impossible"
 * Explanation: The ball cannot reach the hole.
 *
 * Note:
 * There is only one ball and one hole in the maze.
 * Both the ball and hole exist on an empty space, and they will not be at the same position initially.
 * The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
 * The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.
 *
 */
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

static const char C[4] = {
    'd', 'l', 'r', 'u'
};
static const int D[4][2] = {
    {1, 0}, {0, -1}, {0, 1}, {-1, 0}
};

// BFS
// the distance now is pair<int, string> instead of int
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<pair<int, string>>> distance(m, vector<pair<int, string>>(n, {INT_MAX, ""}));
        int sx = ball[0], sy = ball[1], ex = hole[0], ey = hole[1];

        distance[sx][sy] = {0, ""};

        queue<pair<int, int>> Q;
        Q.push({sx, sy});

        int x, y;
        int xx, yy;
        auto isValid = [&]() {
            return xx < m && xx >=0 && yy < n && yy >= 0;
        };
        while (!Q.empty()) {
            auto cur = Q.front();
            x = cur.first; y = cur.second;
            Q.pop();
            for (int i=0; i<4; ++i) {
                auto d = D[i];
                auto c = C[i];
                xx=x; yy=y;
                int dd = distance[x][y].first;
                string pp = distance[x][y].second + c;
                while (true) {
                    xx += d[0]; yy += d[1];
                    ++dd;
                    if (xx == ex && yy == ey) {
                        pair<int, string> state = {dd, pp};
                        if (state < distance[xx][yy]) distance[ex][ey] = state;
                        break;
                    }
                    if (!isValid() || (isValid() && maze[xx][yy] == 1)) {
                        --dd;
                        xx -= d[0]; yy -= d[1];
                        pair<int, string> state = {dd, pp};
                        if (state < distance[xx][yy]) {
                            distance[xx][yy] = state;
                            Q.push({xx, yy});
                        }
                        break;
                    }
                }
            }
        }
        if (distance[ex][ey].first == INT_MAX) return "impossible";
        return distance[ex][ey].second;
    }
};

int main() {
    return 0;
}
