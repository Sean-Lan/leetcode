/**
 *
 * Sean
 * 2017-03-19
 *
 * https://leetcode.com/problems/diagonal-traverse/#/description
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
 *
 * Example:
 *
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 *
 * Output:  [1,2,4,7,5,3,6,8,9]
 *
 * Note:
 * The total number of elements of the given matrix will not exceed 10,000.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// O(n)
// Keep moving at a direction until can't go ahead any more
const pair<int, int> directions[2] = {{-1, 1}, {1, -1}};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int d = 0;
        vector<int> res = {matrix[0][0]};
        int i=0, j=0;
        while (i != m-1 || j != n-1) {
            i += directions[d].first;
            j += directions[d].second;
            if (d == 0) {
                // `if` order matters
                if (j >= n) {
                    j = n-1;
                    i += 2;
                    d = 1;
                }
                if (i < 0) {
                    i = 0;
                    d = 1;
                }
            } else {
                // `if` order matters
                if (i >= m) {
                    i = m - 1;
                    j += 2;
                    d = 0;
                }
                if (j < 0) {
                    j = 0;
                    d = 0;
                }
            }
            res.push_back(matrix[i][j]);
        }
        return res;
    }
};

int main() {
    return 0;
}
