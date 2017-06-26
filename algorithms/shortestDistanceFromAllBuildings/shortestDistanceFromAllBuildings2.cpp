/**
 *
 * Sean
 * 2017-06-26
 *
 * https://leetcode.com/problems/shortest-distance-from-all-buildings/#/description
 *
 * You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
 *
 * Each 0 marks an empty land which you can pass by freely.
 * Each 1 marks a building which you cannot pass through.
 * Each 2 marks an obstacle which you cannot pass through.
 * For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
 *
 * 1 - 0 - 2 - 0 - 1
 * |   |   |   |   |
 * 0 - 0 - 0 - 0 - 0
 * |   |   |   |   |
 * 0 - 0 - 1 - 0 - 0
 *
 * The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
 *
 * Note:
 * There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS from all the buildings
// In the `bfs` helper, update the `minDist` by the way.
// vis[i][j] is now a integer instead of boolean. If vis[i][j] == index, it means i, j could be visited in current `bfs`
// In this way, we could terminate the algorithm faster since we skip all the points that can not be reached from the last building
class Solution {
    int m, n;
    vector<vector<int>> vis;
    vector<vector<int>> total;
    int index;
    int minDist;

    void bfs(int x, int y, vector<vector<int>> &grid) {
        minDist = INT_MAX;
        int dist = 1;
        queue<pair<int, int>> aQueue;
        aQueue.push({x, y});
        int sz;
        int nextX, nextY;
        while(!aQueue.empty()) {
            sz = aQueue.size();
            for (int i=0; i<sz; ++i) {
                x = aQueue.front().first;
                y = aQueue.front().second;
                aQueue.pop();

                for (auto &d : D) {
                    nextX = x + d[0];
                    nextY = y + d[1];
                    if (!isValid(nextX, nextY) || grid[nextX][nextY] != 0 || vis[nextX][nextY] != index) continue;
                    vis[nextX][nextY] = index+1;
                    total[nextX][nextY] += dist;
                    minDist = min(minDist, total[nextX][nextY]);
                    aQueue.push({nextX, nextY});
                }
            }
            ++dist;
        }
    }

    bool isValid(int x, int y) {
        return x>=0 && x<m && y>=0 && y<n;
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->vis = vector<vector<int>>(m, vector<int> (n));
        this->total = vector<vector<int>>(m, vector<int>(n));
        this->index = 0;
        this->minDist = INT_MAX;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    bfs(i, j, grid);
                    ++index;
                }
            }
        }

        return this->minDist == INT_MAX ? -1 : this->minDist;
    }
};

int main() {
    return 0;
}
