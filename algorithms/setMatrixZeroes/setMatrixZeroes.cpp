/**
 *
 * Sean
 * 2016-04-11
 *
 * https://leetcode.com/problems/set-matrix-zeroes/
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 * click to show follow up.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 */
#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>> &matrix);

// use the first column and row to mark whether a column or row needs to filled with 0.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        bool zeroInFirstColumn = false, zeroInFirstRow = false;
        int m = matrix.size();
        int n = matrix[0].size();
        // find whether the first row and first column has zero;
        for (int i=0; i<m; ++i)
            if (matrix[i][0] == 0) {
                zeroInFirstColumn = true;
                break;
            }
        for (int j=0; j<n; ++j)
            if (matrix[0][j] == 0) {
                zeroInFirstRow = true;
                break;
            }

        // use first column and row to mark whether the corresponding
        // column and row shound be set all zeros.
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        // perform the real work.
        for (int i=1; i<m; ++i) {
            if (matrix[i][0] == 0)
                for (int j=1; j<n; ++j) {
                        matrix[i][j] = 0;
                }
        }
        for (int j=1; j<n; ++j) {
            if (matrix[0][j] == 0)
                for (int i=1; i<m; ++i) {
                    matrix[i][j] = 0;
                }
        }

        // set the first row and first column.
        if (zeroInFirstRow)
            for (int j=0; j<n; ++j)
                matrix[0][j] = 0;

        if (zeroInFirstColumn)
            for (int i=0; i<m; ++i)
                matrix[i][0] = 0;
    }
};

void printMatrix(const vector<vector<int>> &matrix) {
    for (auto &iv : matrix) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{-1}, {2}, {3}};
    Solution solution;
    solution.setZeroes(matrix);
    printMatrix(matrix);
}
