/**
 *
 * Sean
 * 2017-03-09
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 *
 * You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
 *
 * Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:
 *
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
 * Return the board when no more squares will be revealed.
 *
 * Example 1:
 * Input:
 *
 * [['E', 'E', 'E', 'E', 'E'],
 *  ['E', 'E', 'M', 'E', 'E'],
 *  ['E', 'E', 'E', 'E', 'E'],
 *  ['E', 'E', 'E', 'E', 'E']]
 *
 * Click : [3,0]
 *
 * Output:
 *
 * [['B', '1', 'E', '1', 'B'],
 *  ['B', '1', 'M', '1', 'B'],
 *  ['B', '1', '1', '1', 'B'],
 *  ['B', 'B', 'B', 'B', 'B']]
 *
 * Example 2:
 * Input:
 *
 * [['B', '1', 'E', '1', 'B'],
 *  ['B', '1', 'M', '1', 'B'],
 *  ['B', '1', '1', '1', 'B'],
 *  ['B', 'B', 'B', 'B', 'B']]
 *
 * Click : [1,2]
 *
 * Output:
 *
 * [['B', '1', 'E', '1', 'B'],
 *  ['B', '1', 'X', '1', 'B'],
 *  ['B', '1', '1', '1', 'B'],
 *  ['B', 'B', 'B', 'B', 'B']]
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int directions[8][2] = {
    {-1,-1},
    {-1,0},
    {-1,1},
    {0,-1},
    {0,1},
    {1,-1},
    {1,0},
    {1,1}
};

class Solution {
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    int getMineCnt(int x, int y, vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();

        int cnt = 0;
        int nextX, nextY;
        for (auto d : directions) {
            nextX = x + d[0];
            nextY = y + d[1];
            if (isValid(nextX, nextY, m, n) && board[nextX][nextY] == 'M') ++cnt;
        }
        return cnt;
    }
public:
    // BFS with a queue
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        int cnt = getMineCnt(x, y, board);
        if (cnt) {
            board[x][y] = '0' + cnt;
            return board;
        }

        int m = board.size();
        int n = board[0].size();

        board[x][y] = 'B';
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[x][y] = true;
        queue<pair<int, int>> aQueue;
        aQueue.push({x, y});

        while (!aQueue.empty()) {
            auto aPair = aQueue.front();
            aQueue.pop();
            int curX = aPair.first;
            int curY = aPair.second;
            int mineCnt = 0;
            int nextX, nextY;
            for (auto d : directions) {
                nextX = curX + d[0];
                nextY = curY + d[1];
                // remember to check validity
                if (!isValid(nextX, nextY, m, n) || visited[nextX][nextY]) continue;
                visited[nextX][nextY] = true;
                mineCnt = getMineCnt(nextX, nextY, board);
                if (mineCnt) board[nextX][nextY] = '0' + mineCnt;
                else {
                    board[nextX][nextY] = 'B';
                    aQueue.push({nextX, nextY});
                }
            }
        }
        return board;
    }
};

int main() {
    return 0;
}
