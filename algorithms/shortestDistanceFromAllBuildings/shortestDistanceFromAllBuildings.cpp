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

int D[4][2] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

// BFS from every empty land
class Solution {
    int buildingCnt;
    int m, n;
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }

    int calDist(int x, int y, vector<vector<int>>& grid) {
        vector<vector<bool>> mark(m, vector<bool>(n, false));
        queue<pair<int, int>> aQueue;
        aQueue.push({x, y});
        mark[x][y] = true;
        int total = 0;
        int cnt = 0;
        int curX, curY, nextX, nextY;
        int sz;
        int dist = 1;
        while (!aQueue.empty()) {
            sz = aQueue.size();
            for (int i=0; i<sz; ++i) {
                auto cur = aQueue.front();
                aQueue.pop();
                curX = cur.first;
                curY = cur.second;

                for (auto &d : D) {
                    nextX = curX + d[0];
                    nextY = curY + d[1];
                    if (!isValid(nextX, nextY) || mark[nextX][nextY]) continue;
                    mark[nextX][nextY] = true;
                    if (grid[nextX][nextY] == 1) {
                        total += dist;
                        ++ cnt;
                    } else if (grid[nextX][nextY] == 0) {
                        aQueue.push({nextX, nextY});
                    }
                }
            }
            ++ dist;
        }
        return cnt == buildingCnt ? total : INT_MAX;
    }

public:
    int shortestDistance(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->buildingCnt = 0;

        for (auto &line : grid) {
            for (auto &i : line) {
                if (i == 1) ++ this->buildingCnt;
            }
        }

        int shortest = INT_MAX;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 0)
                    shortest = min(shortest, calDist(i, j, grid));
            }
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};

int main() {
    return 0;
}
