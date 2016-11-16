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
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

static const int Directions[4][2] = {
    {1,0}, {-1, 0}, {0, 1}, {0, -1}
};

// DFS runtime Error.
class Solution {
    typedef pair<int, int> pii;

    bool dfs_visit(int i, int j, stack<pii> &aStack, vector<vector<char>> &board, vector<vector<bool>> &mark) {
        aStack.push({i, j});
        bool shouldFlip = true;
        int nextI, nextJ;
        if (i == 0 || i==board.size()-1 || j == 0 || j == board[0].size()-1) {
            shouldFlip = false;
        }
        for (auto &direction : Directions) {
            nextI = i + direction[0];
            nextJ = j + direction[1];
            if (nextI < 0 || nextI >= board.size() || nextJ < 0 || nextJ >= board[0].size()) continue;
            if (board[nextI][nextJ] == 'O' && !mark[nextI][nextJ]) {
                mark[nextI][nextJ] = true;
                if (dfs_visit(nextI, nextJ, aStack, board, mark) == false) shouldFlip = false;
            }
        }
        return shouldFlip;
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) return;
        stack<pii> aStack;
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> mark(n, vector<bool>(m, false));
        for (int i = 1; i<n; ++i) {
            for (int j=1; j<m; ++j) {
                if (board[i][j] == 'O' && !mark[i][j]) {
                    mark[i][j] = true;
                    if (dfs_visit(i, j, aStack, board, mark)) {
                        while (!aStack.empty()) {
                            auto coords = aStack.top();
                            aStack.pop();
                            board[coords.first][coords.second] = 'X';
                        }
                    } else { // clear the stack.
                        aStack = stack<pii>();
                    }
                }
            }
        }

    }
};

int main() {
    Solution solution;
    return 0;
}
