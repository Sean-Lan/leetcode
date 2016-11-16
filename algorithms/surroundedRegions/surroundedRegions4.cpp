/**
 *
 * Sean
 * 2016-11-16
 *
 * https://leetcode.com/problems/surrounded-regions/
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 */
#include <queue>
#include <vector>
using namespace std;

static const int directions[4][2] = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

// BFS
class Solution {
    typedef pair<int, int> pii;
    public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m < 3) return;
        int n = board[0].size();
        if (n < 3) return;
        queue<pii> aQueue;
        vector<vector<bool>> mark(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            if (board[i][0] == 'O') {
                mark[i][0] = true;
                aQueue.push({i, 0});
            }
            if (board[i][n-1] == 'O') {
                mark[i][n-1] = true;
                aQueue.push({i, n-1});
            }
        }

        for (int j=1; j<n-1; ++j) {
            if (board[0][j] == 'O') {
                mark[0][j] = true;
                aQueue.push({0, j});
            }
            if (board[m-1][j] == 'O') {
                mark[m-1][j] = true;
                aQueue.push({m-1, j});
            }
        }
        pii cur;
        int nextI, nextJ;
        while (!aQueue.empty()) {
            cur = aQueue.front();
            aQueue.pop();
            board[cur.first][cur.second] = '*';
            for (auto direction : directions) {
                nextI = cur.first + direction[0];
                nextJ = cur.second + direction[1];
                if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n) continue;
                if (board[nextI][nextJ] == 'O' && !mark[nextI][nextJ]) {
                    mark[nextI][nextJ] = true;
                    aQueue.push({nextI, nextJ});
                }
            }
        }

        for (auto &row : board)
            for (auto &c : row)
                if (c == '*') c = 'O';
                else if (c == 'O') c = 'X';
    }
};

int main() {
    return 0;
}
