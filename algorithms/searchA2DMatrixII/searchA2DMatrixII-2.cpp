/**
 *
 * Sean
 * 2016-03-09
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 *
 * Given target = 20, return false.
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 *
 * O(M+N) solution.
 * From top-right to left-bottom.
 *
 */
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty() || matrix[0].empty()) return false;
            int i=0, j=matrix[0].size()-1;
            while (i<matrix.size() && j>=0) {
                if (target < matrix[i][j]) --j;
                else if (target > matrix[i][j]) ++i;
                else
                    return true;
            }
            return false;
        }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << solution.searchMatrix(matrix, 5) << endl;
    cout << solution.searchMatrix(matrix, 20) << endl;
    cout << solution.searchMatrix(matrix, 24) << endl;
}
