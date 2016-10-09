/**
 *
 * Sean
 * 2016-10-09
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/
 *
 * Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
 *
 * Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
 *
 * Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
 *
 * Note:
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * Example:
 *
 * Given the following 5x5 matrix:
 *
 *   Pacific ~   ~   ~   ~   ~
 *        ~  1   2   2   3  (5) *
 *        ~  3   2   3  (4) (4) *
 *        ~  2   4  (5)  3   1  *
 *        ~ (6) (7)  1   4   5  *
 *        ~ (5)  1   1   2   4  *
 *           *   *   *   *   * Atlantic
 *
 * Return:
 *
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int row, col, height;
    Cell(int r, int c, int h): row(r), col(c), height(h) {}
    bool operator<(const Cell& cell) const {
        return height > cell.height;
    }
};

const int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// BFS with priority_queue
class Solution {
    private:
        void visit(priority_queue<Cell> &aQueue, vector<vector<bool>> &visited, vector<vector<bool>> &canFlow, const vector<vector<int>> &matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            while (!aQueue.empty()) {
                Cell aCell = aQueue.top();
                aQueue.pop();
                int nextR, nextC, nextH;
                for (auto &dir : directions) {
                    nextR = aCell.row + dir[0];
                    nextC = aCell.col + dir[1];
                    if (nextR>=0 && nextR < m && nextC >=0 && nextC < n && !visited[nextR][nextC]) {
                        visited[nextR][nextC] = true;
                        nextH = matrix[nextR][nextC];
                        if (nextH >= aCell.height) {
                            visited[nextR][nextC] = true;
                            canFlow[nextR][nextC] = true;
                            Cell next(nextR, nextC, nextH);
                            aQueue.push(next);
                        }
                    }
                }
            }
        }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        priority_queue<Cell> aQueue;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> can1(m, vector<bool> (n, false));
        vector<vector<bool>> can2(m, vector<bool> (n, false));
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i=0; i<m; ++i) {
            can1[i][0] = true;
            visited[i][0] = true;
            aQueue.push(Cell(i, 0, matrix[i][0]));
        }

        for (int i=1; i<n; ++i) {
            can1[0][i] = true;
            aQueue.push(Cell(0, i, matrix[0][i]));
            visited[0][i] = true;
        }

        visit(aQueue, visited, can1, matrix);

        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                visited[i][j] = false;

        for (int i=0; i<m; ++i) {
            can2[i][n-1] = true;
            visited[i][n-1] = true;
            aQueue.push(Cell(i, n-1, matrix[i][n-1]));
        }

        for (int i=0; i<n-1; ++i) {
            can2[m-1][i] = true;
            visited[m-1][i] = true;
            aQueue.push(Cell(m-1, i, matrix[m-1][i]));
        }

        visit(aQueue, visited, can2, matrix);

        vector<pair<int, int>> res;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (can1[i][j] && can2[i][j])
                    res.push_back({i, j});

        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    Solution solution;
    auto res = solution.pacificAtlantic(matrix);
    for (auto &aPair : res)
        cout << aPair.first << " " << aPair.second << endl;
    return 0;
}
