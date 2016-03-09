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
 * Use divide and conque.
 * The compexity  is O((M*N)^log(3/4))
 *
 */
class Solution {
    private:
        bool find(vector<vector<int>> &matrix, int minX, int minY, int maxX,
                int maxY, const int &target) {
            if (minX > maxX || minY > maxY || target < matrix[minX][minY] || target > matrix[maxX][maxY])
                return false;
            int centerX = (minX+maxX)>>1;
            int centerY = (minY+maxY)>>1;
            int centerValue = matrix[centerX][centerY];
            if (centerValue == target)
                return true;
            else if (target < centerValue) {
                // note: the compare sequence matters, the left-top part has the highest probability
                // to contain the target value.
                if (find(matrix, minX, minY, centerX-1, centerY-1, target) ||
                        find(matrix, minX, centerY, centerX-1, maxY, target) ||
                        find(matrix, centerX, minY, maxX, centerY-1, target))
                    return true;
            } else {
                // the bottom-right part has the lowest probability to contain the target value.
                if (find(matrix, centerX+1, centerY+1, maxX, maxY, target) ||
                        find(matrix, minX, centerY+1, centerX, maxY, target) ||
                        find(matrix, centerX+1, minY, maxX, centerY, target))
                    return true;
            }
            return false;
        }
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty() || matrix[0].empty()) return false;
            return find(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, target);
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
