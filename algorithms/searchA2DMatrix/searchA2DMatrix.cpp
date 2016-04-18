/**
 *
 * Sean
 *
 * 2016-04-18
 *
 * https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Typical binary search.
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty() || matrix[0].empty()) return false;
            return searchMatrix(matrix, target, 0, matrix.size()-1);
        }

    private:
        bool searchMatrix(vector<vector<int>>& matrix, int target,
                int startRowIndex, int endRowIndex) {
            if (startRowIndex > endRowIndex) return false;
            if (startRowIndex == endRowIndex) {
                auto &aRow = matrix[startRowIndex];
                return std::binary_search(aRow.begin(), aRow.end(), target);
            }
            int i = (startRowIndex + endRowIndex) >> 1;
            int j = matrix[0].size() >> 1;
            int pivot = matrix[i][j];
            if (target == pivot) return true;
            if (target < pivot) {
                auto &aRow = matrix[i];
                return std::binary_search(aRow.begin(), aRow.begin()+j, target) ||
                    searchMatrix(matrix, target, startRowIndex, i-1);
            }
            auto & aRow = matrix[i];
            return std::binary_search(aRow.begin()+j+1, aRow.end(), target) ||
                searchMatrix(matrix, target, i+1, endRowIndex);
        }
};

int main() {
    vector<vector<int>> matrix = 
    {
        { 1,   3,  5,  7 },
        { 10, 11, 16, 20 },
        { 23, 30, 34, 50 }
    };
    Solution solution;
    cout << solution.searchMatrix(matrix, 0) << endl;
    cout << solution.searchMatrix(matrix, 34) << endl;
}
