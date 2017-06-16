/**
 *
 * Sean
 * 2017-06-16
 *
 * https://leetcode.com/problems/game-of-life/#/description
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * Write a function to compute the next state (after one update) of the board given its current state.
 *
 * Follow up:
 * Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// use the second bit of each board grid to store the next state
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        int cnt;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                cnt = 0;
                for (int ii=max(i-1, 0); ii<=min(i+1, m-1); ++ii) {
                    for (int jj=max(j-1, 0); jj<=min(j+1, n-1); ++jj) {
                        if (i == ii && j == jj) continue;
                        if (board[ii][jj] & 1) ++cnt;
                    }
                }
                if (cnt == 3) board[i][j] |= 2;
                if (cnt == 2) board[i][j] = (board[i][j] & 1) ? 3 : 0;
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};

int main() {
    return 0;
}
