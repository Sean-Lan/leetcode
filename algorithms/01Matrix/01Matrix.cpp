/**
 *
 * Sean
 * 2017-08-04
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 * Example 1:
 * Input:
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 * Output:
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 * Example 2:
 * Input:
 * 0 0 0
 * 0 1 0
 * 1 1 1
 *
 * Output:
 * 0 0 0
 * 0 1 0
 * 1 2 1
 *
 * Note:
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 *
 */
#include <vector>
#include <queue>
using namespace std;

static const int D[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

// BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<pair<int, int>> Q;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == 0) {
                    Q.push({i, j});
                }
            }
        }

        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        int sz, x, y, xx, yy;
        int level = 0;
        while (!Q.empty()) {
            sz = Q.size();
            ++ level;
            for (int i=0; i<sz; ++i) {
                x = Q.front().first;
                y = Q.front().second;
                Q.pop();
                for (auto &d : D) {
                    xx = x + d[0];
                    yy = y + d[1];
                    if (isValid(xx, yy) && matrix[xx][yy] == 1 && res[xx][yy] == 0) {
                        res[xx][yy] = level;
                        Q.push({xx, yy});
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    return 0;
}
