/**
 *
 * Sean
 * 2017-09-26
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 *
 */
#include <vector>
using namespace std;

// O(n)
// from outside to inside
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        int rs = 0, re = m-1;
        int cs = 0, ce = n-1;

        vector<int> res;
        while (cs <= ce && rs <= re) {
            for (int i=cs; i<=ce; ++i) res.push_back(matrix[rs][i]);
            ++rs;

            for (int i=rs; i<=re; ++i) res.push_back(matrix[i][ce]);
            --ce;

            if (rs > re || cs > ce) break;
            for (int i=ce; i>=cs; --i) res.push_back(matrix[re][i]);
            --re;

            for (int i=re; i>=rs; --i) res.push_back(matrix[i][cs]);
            ++cs;
        }

        return res;
    }
};

int main() {
    return 0;
}
