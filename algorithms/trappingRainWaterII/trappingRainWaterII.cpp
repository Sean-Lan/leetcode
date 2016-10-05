/**
 *
 * Sean
 * 2016-10-05
 *
 * https://leetcode.com/problems/trapping-rain-water-ii/
 *
 * Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
 *
 * Note:
 * Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
 *
 * Example:
 *
 * Given the following 3x6 height map:
 * [
 *   [1,4,3,1,3,2],
 *   [3,2,1,3,2,4],
 *   [2,3,3,2,3,1]
 * ]
 *
 * Return 4.
 *
 */
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

// Using priority_queue.
struct Cell {
    int row, col, height;
    Cell(int r, int c, int h): row(r), col(c), height(h) {}
    bool operator<(const Cell &other) const {
        return this->height > other.height;
    }
};
class Solution {
    const static int directions[4][2] ;
    public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        priority_queue<Cell> aQueue;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> mark(m, vector<bool>(n, false));

        // enqueue the boundary
        for (int i=0; i<m; ++i) {
            aQueue.push(Cell(i, 0, heightMap[i][0]));
            aQueue.push(Cell(i, n-1, heightMap[i][n-1]));
            mark[i][0] = mark[i][n-1] = true;
        }

        for (int i=1; i<n-1; ++i) {
            aQueue.push(Cell(0, i, heightMap[0][i]));
            aQueue.push(Cell(m-1, i, heightMap[m-1][i]));
            mark[0][i] = mark[m-1][i] = true;
        }

        int result = 0;
        while (!aQueue.empty()) {
            Cell aCell = aQueue.top();
            int row, col;
            for (auto &d : directions) {
                row = aCell.row + d[0];
                col = aCell.col + d[1];
                if (row >= 0 && row < m && col >= 0 && col < n && !mark[row][col]) {
                    mark[row][col] = true;
                    if (heightMap[row][col] < aCell.height)
                        result += aCell.height-heightMap[row][col];
                    aQueue.push(Cell(row, col, max(heightMap[row][col], aCell.height)));
                }
            }
            aQueue.pop();
        }
        return result;
    }
};

const int Solution::directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
    vector<vector<int>> heightMap =
    { { 1,4,3,1,3,2 },
        { 3,2,1,3,2,4 },
        { 2,3,3,2,3,1 }
    };
    Solution solution;
    cout << solution.trapRainWater(heightMap) << endl;
    return 0;
}
