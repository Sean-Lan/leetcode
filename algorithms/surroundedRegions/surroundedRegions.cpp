/**
 *
 * Sean
 * 2016-05-30
 *
 * https://leetcode.com/problems/surrounded-regions/
 *
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 *      X X X X
 *      X O O X
 *      X X O X
 *      X O X X
 * After running your function, the board should be:
 *
 *      X X X X
 *      X X X X
 *      X X X X
 *      X O X X
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using DFS will lead to a stack overflow when the board is too large.
// Usig BFS with queue is a good choice.
// Start from the boundary, if there is an 'O', BFS it.
// Remember to mark the positions visited.
class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            if (board.empty() || board[0].empty()) return;

            int m = board.size(), n = board[0].size();

            for (int i=0; i<m; ++i) {
                if (board[i][0]=='O') {
                    bfs(board, i, 0);
                }
                if (board[i][n-1]=='O') {
                    bfs(board, i, n-1);
                }
            }

            for (int i=0; i<n; ++i) {
                if (board[0][i] == 'O') {
                    bfs(board, 0, i);
                }
                if (board[m-1][i] == 'O') {
                    bfs(board, m-1, i);
                }
            }

            for (auto &aLine : board) {
                for (auto &c : aLine) {
                    c = (c==' '?'O':'X');
                }
            }
        }

        void bfs(vector<vector<char>> &board, int x, int y) {
            queue<pair<int, int>> aQueue;
            board[x][y] = ' ';
            aQueue.push({x, y});
            int nextX, nextY;
            int m = board.size();
            int n = board[0].size();
            while (!aQueue.empty()) {
                auto cur = aQueue.front();
                aQueue.pop();
                // up
                nextX = cur.first-1;
                nextY = cur.second;
                if (nextX>=0 && board[nextX][nextY] == 'O') {
                    board[nextX][nextY] = ' ';
                    aQueue.push({nextX, nextY});
                }

                // down
                nextX = cur.first+1;
                nextY = cur.second;
                if (nextX<m && board[nextX][nextY] == 'O') {
                    board[nextX][nextY] = ' ';
                    aQueue.push({nextX, nextY});
                }

                // left
                nextX = cur.first;
                nextY = cur.second-1;
                if (nextY>=0 && board[nextX][nextY] == 'O') {
                    board[nextX][nextY] = ' ';
                    aQueue.push({nextX, nextY});
                }

                // right
                nextX = cur.first;
                nextY = cur.second+1;
                if (nextY<n && board[nextX][nextY] == 'O') {
                    board[nextX][nextY] = ' ';
                    aQueue.push({nextX, nextY});
                }
            }
        }
};

int main() {}
