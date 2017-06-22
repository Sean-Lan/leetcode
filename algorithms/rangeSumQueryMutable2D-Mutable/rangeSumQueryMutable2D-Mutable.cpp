/**
 *
 * Sean
 * 2017-06-22
 *
 * https://leetcode.com/problems/range-sum-query-2d-mutable/#/description
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 * Range Sum Query 2D
 * The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
 *
 * Example:
 * Given matrix = [
 *   [3, 0, 1, 4, 2],
 *   [5, 6, 3, 2, 1],
 *   [1, 2, 0, 1, 5],
 *   [4, 1, 0, 1, 7],
 *   [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * update(3, 2, 2)
 * sumRegion(2, 1, 4, 3) -> 10
 * Note:
 * The matrix is only modifiable by the update function.
 * You may assume the number of calls to update and sumRegion function is distributed evenly.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// Binary Indexed Tree: https://discuss.leetcode.com/topic/30343/java-2d-binary-indexed-tree-solution-clean-and-short-17ms/2
class NumMatrix {
    int m, n;
    vector<vector<int>> BIT;
    vector<vector<int>> nums;

    int getSum(int row, int col) {
        int sum = 0;
        for (int i=row; i; i-=(i&-i)) {
            for (int j=col; j; j-=(j&-j)) {
                sum += BIT[i][j];
            }
        }
        return sum;
    }

    void printVvi(vector<vector<int>> &vvi) {
        for (auto &vi : vvi) {
            for (auto &i : vi) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    NumMatrix(vector<vector<int>> matrix) {
        this->m = matrix.size();
        if (m == 0) return;
        this->n = matrix[0].size();
        this->BIT = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        this->nums = matrix;
        int idx1, idx2;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                idx1 = i+1;
                idx2 = j+1;
                for (int ii=idx1-(idx1&-idx1)+1; ii<=idx1; ++ii) {
                    for (int jj=idx2-(idx2&-idx2)+1; jj<=idx2; ++jj) {
                        BIT[idx1][idx2] += matrix[ii-1][jj-1];
                    }
                }
            }
        }
    }

    void update(int row, int col, int val) {
        int delta = val - nums[row][col];
        nums[row][col] = val;
        for (int i=row+1; i<=m; i+=i&(-i)) {
            for (int j=col+1; j<=n; j+=j&(-j)) {
                BIT[i][j] += delta;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2+1, col2+1) - getSum(row2+1, col1) - getSum(row1, col2+1) + getSum(row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */

int main() {
    return 0;
}

