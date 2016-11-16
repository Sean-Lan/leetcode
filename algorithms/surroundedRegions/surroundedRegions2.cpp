/**
 *
 * Sean
 * 2016-11-16
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
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

// The Union Find implementation uses union by rank and path compression.
// All we need is to find all 'O's in the boundary and union all adjacent 'O's.
class Unions {
private:
    vector<int> roots;
    vector<int> ranks;
public:
    Unions(int size) {
        roots = vector<int>(size);
        ranks = vector<int>(size, 0);
        // fill roots[i] with i
        iota(roots.begin(), roots.end(), 0);
    }

    int findRoot(int i) {
        if (roots[i] != i)
            roots[i] = findRoot(roots[i]);
        return roots[i];
    }

    int unionAll(int i, int j) {
        int root1 = findRoot(i);
        int root2 = findRoot(j);
        if (root1 == root2) return root1;
        if (ranks[root1] > ranks[root2])
            return roots[root2] = root1;
        else {
            if (ranks[root1] == ranks[root2])
                ++ ranks[root2];
            return roots[root1] = root2;
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m < 3) return;
        int n = board[0].size();
        if (n < 3) return;

        Unions unions(m*n);
        auto onBoundary = [m, n] (int i, int j) {
            return i == 0 || j == 0 || i == m-1 || j == n-1;
        };
        int boundary = -1;
        int idx;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'X') continue;
                idx = i*n + j;
                if (onBoundary(i, j)) {
                    if (boundary == -1) {
                        boundary = idx;
                    } else {
                        boundary = unions.unionAll(boundary, idx);
                    }
                }
                if (i+1 < m && board[i+1][j] == 'O') unions.unionAll(idx, idx+n);
                if (j+1 < n && board[i][j+1] == 'O') unions.unionAll(idx, idx+1);
            }

        if (boundary == -1) {
            for (auto &row : board)
                for (auto &c: row)
                    if (c == 'O') c = 'X';
            return;
        }

        boundary = unions.findRoot(boundary);
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (board[i][j] == 'O' && unions.findRoot(i*n+j) != boundary)
                    board[i][j] = 'X';
    }
};

int main() {
    Solution solution;
    vector<string> raw = { "XOXOXO","OXOXOX","XOXOXO","OXOXOX" };
    vector<vector<char>> board = vector<vector<char>>(raw.size(), vector<char>(raw[0].size()));

    for (int i=0; i<raw.size(); ++i) {
        string& aLine = raw[i];
        for (int j=0; j<raw[0].size(); ++j) {
            board[i][j] = aLine[j];
        }
    }

    for (auto &cv : board) {
        for (char c: cv)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;

    solution.solve(board);

    for (auto &cv : board) {
        for (char c: cv)
            cout << c << " ";
        cout << endl;
    }
}
