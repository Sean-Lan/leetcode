/**
 *
 * Sean
 * 2017-09-11
 *
 * https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/description/
 *
 * Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
 *
 * Example:
 * Input:
 * [[0,1,1,0],
 *  [0,1,1,0],
 *  [0,0,0,1]]
 * Output: 3
 *
 * Hint: The number of elements in the given matrix will not exceed 10,000.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// tranverse the matrix four times:
// 1. row by row
// 2. column by column
// 3. diagonal
// 4. anti-diagonal
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int maxLen = 0;
        int cnt = 0;
        int m = M.size(), n = M[0].size();

        // row
        for (int i=0; i<m; ++i) {
            cnt = 0;
            for (int j=0; j<n; ++j) {
                if (M[i][j]) {
                    ++ cnt;
                    maxLen = max(maxLen, cnt);
                } else cnt = 0;
            }
        }

        // column
        for (int j=0; j<n; ++j) {
            cnt = 0;
            for (int i=0; i<m; ++i) {
                if (M[i][j]) {
                    ++ cnt;
                    maxLen = max(maxLen, cnt);
                } else cnt = 0;
            }
        }

        int x, y;
        // diagonal
        for (int i=0; i<n; ++i) {
            cnt = 0;
            x = 0; y = i;
            while (x < m && y < n) {
                if (M[x][y]) {
                    ++ cnt;
                    maxLen = max(maxLen, cnt);
                } else cnt = 0;
                x += 1;
                y += 1;
            }
        }

        for (int i=1; i<m; ++i) {
            cnt =0;
            x = i; y = 0;
            while (x < m && y < n) {
                if (M[x][y]) {
                    ++ cnt;
                    maxLen = max(maxLen, cnt);
                } else cnt = 0;
                x += 1;
                y += 1;
            }
        }

        // anti-diagonal
        for (int i=0; i<n; ++i) {
            cnt = 0;
            x = 0; y = i;
            while (x < m && y >= 0) {
                if (M[x][y]) {
                    ++ cnt;
                    maxLen = max(maxLen, cnt);
                } else cnt = 0;
                x += 1;
                y -= 1;
            }
        }

        for (int i=1; i<m; ++i) {
            cnt = 0;
            x = i; y = n-1;
            while (x < m && y >= 0) {
                if (M[x][y]) {
                    ++ cnt;
                    maxLen = max(maxLen, cnt);
                } else cnt = 0;
                x += 1;
                y -= 1;
            }
        }

        return maxLen;
    }
};

int main() {
    return 0;
}
