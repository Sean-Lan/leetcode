/**
 *
 * Sean
 * 2017-08-22
 *
 * https://leetcode.com/problems/image-smoother/description/
 *
 * Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
 *
 * Example 1:
 * Input:
 * [[1,1,1],
 *  [1,0,1],
 *  [1,1,1]]
 * Output:
 * [[0, 0, 0],
 *  [0, 0, 0],
 *  [0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * Note:
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 *
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return M;
        vector<vector<int>> res = M;
        int m = M.size();
        int n = M[0].size();
        auto getAvg = [&](int x, int y) {
            int cnt = 1;
            int sum = M[x][y];
            if (x-1 >= 0) { sum += M[x-1][y]; ++cnt; }
            if (y-1 >= 0) { sum += M[x][y-1]; ++cnt; }
            if (x+1 < m) { sum += M[x+1][y]; ++cnt; }
            if (y+1 < n) { sum += M[x][y+1]; ++cnt; }
            if (x-1 >= 0 && y-1 >= 0) { sum += M[x-1][y-1]; ++cnt; }
            if (x-1 >= 0 && y+1 < n) { sum += M[x-1][y+1]; ++cnt; }
            if (x+1 < m && y-1 >= 0) { sum += M[x+1][y-1]; ++cnt; }
            if (x+1 < m && y+1 < n) { sum += M[x+1][y+1]; ++cnt; }
            return sum/cnt;
        };
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                res[i][j] = getAvg(i, j);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
