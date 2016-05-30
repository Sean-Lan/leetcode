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
#include <queue>
#include <vector>
using namespace std;

// The Union Find implementation uses union by rank and path compression.
// All we need is to find all 'O's in the boundary and union all adjacent 'O's.
class Unions {
private:
    vector<int> roots;
    vector<int> ranks;
public:
    Unions(int m, int n) {
        int size = m*n;
        roots.resize(size);
        ranks.resize(size);
        for (int i=0; i<size; ++i) {
            roots[i] = i;
            ranks[i] = 0;
        }
    }

    int findRoot (int x) {
        if (x != roots[x]) {
            roots[x] = findRoot(roots[x]);
        }
        return roots[x];
    }

    void unionAll(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if (ranks[rootX] > ranks[rootY]) {
            roots[rootY] = rootX;
        } else {
            roots[rootX] = rootY;
            if (ranks[rootX] == ranks[rootY]) {
                ++ranks[rootY];
            }
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        Unions unions(m, n);
        int boundary = -1;
        int cur;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') {
                    cur = i*n+j;
                    if (inBoundary(i, j, m, n)) {
                        if (boundary != -1) {
                            unions.unionAll(boundary, cur);
                        } else {
                            boundary = cur;
                        }
                    }
                    if (i+1<m && board[i+1][j] == 'O') {
                        unions.unionAll(cur, (i+1)*n+j);
                    }
                    if (j+1<n && board[i][j+1] == 'O') {
                        unions.unionAll(cur, i*n+j+1);
                    }
                }
            }
        }

        if (boundary == -1) {
            for (auto &aLine : board) {
                for (auto &c: aLine) {
                    c = 'X';
                }
            }
            return;
        }

        int boundaryRoot = unions.findRoot(boundary);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (unions.findRoot(i*n+j) != boundaryRoot) {
                    board[i][j] = 'X';
                }
            }
        }

    }

    inline bool inBoundary(int x, int y, int m, int n) {
        return (x==0 || y==0 || x==m-1 || y==n-1);
    }
};




int main() {
    Solution solution;
    vector<string> raw = {"XOOOOOOOOOOOOOOOOOOO","OXOOOOXOOOOOOOOOOOXX","OOOOOOOOXOOOOOOOOOOX","OOXOOOOOOOOOOOOOOOXO","OOOOOXOOOOXOOOOOXOOX","XOOOXOOOOOXOXOXOXOXO","OOOOXOOXOOOOOXOOXOOO","XOOOXXXOXOOOOXXOXOOO","OOOOOXXXXOOOOXOOXOOO","XOOOOXOOOOOOXXOOXOOX","OOOOOOOOOOXOOXOOOXOX","OOOOXOXOOXXOOOOOXOOO","XXOOOOOXOOOOOOOOOOOO","OXOXOOOXOXOOOXOXOXOO","OOXOOOOOOOXOOOOOXOXO","XXOOOOOOOOXOXXOOOXOO","OOXOOOOOOOXOOXOXOXOO","OOOXOOOOOXXXOOXOOOXO","OOOOOOOOOOOOOOOOOOOO","XOOOOXOOOXXOOXOXOXOO"};
    vector<vector<char>> board = vector<vector<char>>(raw.size(), vector<char>(raw[0].size()));
    for (int i=0; i<raw.size(); ++i) {
        string& aLine = raw[i];
        for (int j=0; j<raw[0].size(); ++j) {
            board[i][j] = aLine[j];
        }
    }
    solution.solve(board);
    for (auto &cv : board) {
        for (char c: cv)
            cout << c << " ";
        cout << endl;
    }
}
