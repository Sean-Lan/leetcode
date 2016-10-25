/**
 *
 * Sean
 * 2016-10-25
 *
 * https://leetcode.com/problems/battleships-in-a-board/
 *
 * Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
 *
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
 * Example:
 *      X..X
 *      ...X
 *      ...X
 * In the above board there are 2 battleships.
 *
 * Invalid Example:
 *      ...X
 *      XXXX
 *      ...X
 * This is not a valid board - as battleships will always have a cell separating between them.
 *
 * Your algorithm should not modify the value of the board.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// keep order, from top-left to bottom-right.
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == '.') continue;
                if (i > 0 && board[i-1][j]=='X') continue;
                if (j > 0 && board[i][j-1]=='X') continue;
                ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}
