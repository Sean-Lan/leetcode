#include <iostream>
/**
 *
 * Sean
 * https://leetcode.com/problems/rotate-image/
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 *
 * Subscribe to see which companies asked this question
 *
 */
#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            if (matrix.empty()) return;
            int n = matrix.size();
            int centerX = n>>1;
            int tmp;
            for (int i=0; i<centerX; ++i) {
                for (int j=0; j+i*2<n-1; ++j) {
                    tmp = matrix[i][i+j];
                    matrix[i][i+j] = matrix[n-1-i-j][i];
                    matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];
                    matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
                    matrix[i+j][n-1-i] = tmp;
                }
            }
        }
};

int main() {
}
