/**
 *
 * Sean
 * 2016-05-03
 *
 * https://leetcode.com/problems/word-search/
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 *
 * DFS with backtracking.
 * Use mark to mark all the positions visited, for each position, check for directions.
 * The tricky thing is the start should be any of the positions of the board, and remember
 * to set mark when enter the start point.
 *
 */
class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            auto mark = vector<vector<bool>>(board.size(),
                            vector<bool>(board[0].size()));
            for (int i=0; i<board.size(); ++i)
                for (int j=0; j<board[0].size(); ++j) {
                    mark[i][j] = true;
                    if (dfs(board, word, mark, 0, i, j))
                        return true;
                    mark[i][j] = false;
                }
            return false;
        }

    private:
        bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &mark,
                int n, int i, int j) {
            int nextI, nextJ;
            if (board[i][j] == word[n]) {
                if (n == word.size()-1)
                    return true;
                // right
                nextI = i;
                nextJ = j+1;
                if (nextJ < board[0].size() && !mark[nextI][nextJ]) {
                    mark[nextI][nextJ] = true;
                    if (dfs(board, word, mark, n+1, nextI, nextJ))
                        return true;
                    mark[nextI][nextJ] = false;
                }

                // down
                nextI = i+1;
                nextJ = j;
                if (nextI < board.size() && !mark[nextI][nextJ]) {
                    mark[nextI][nextJ] = true;
                    if (dfs(board, word, mark, n+1, nextI, nextJ))
                        return true;
                    mark[nextI][nextJ] = false;
                }

                // left
                nextI = i;
                nextJ = j-1;
                if (nextJ >= 0 && !mark[nextI][nextJ]) {
                    mark[nextI][nextJ] = true;
                    if (dfs(board, word, mark, n+1, nextI, nextJ))
                        return true;
                    mark[nextI][nextJ] = false;
                }

                // up
                nextI = i-1;
                nextJ = j;
                if (nextI >= 0 && !mark[nextI][nextJ]) {
                    mark[nextI][nextJ] = true;
                    if (dfs(board, word, mark, n+1, nextI, nextJ))
                        return true;
                    mark[nextI][nextJ] = false;
                }
            }
            return false;
        }
};

int main() {
    vector<vector<char>> board =
    {
        { 'A','B','C','E' },
        { 'S','F','C','S' },
        { 'A','D','E','E' }
    };
    Solution solution;
    cout << solution.exist(board, "ABCCED") << endl;
    cout << solution.exist(board, "SEE") << endl;
    cout << solution.exist(board, "ABCB") << endl;
    vector<vector<char>> board2 = { {'a', 'a'} };
    cout << solution.exist(board2, "aaa") << endl;
}
