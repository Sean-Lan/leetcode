/**
 *
 * Sean
 * 2016-02-17
 *
 * https://leetcode.com/problems/valid-sudoku/
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules. (http://sudoku.com.au/TheRules.aspx)
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 */
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

inline bool characterValid(char c) {
    return (c=='.' ||
            (c<='9' && c>='1'));
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> mark;
        if (board.size() != 9) return false;
        // row
        for (auto &row : board) {
            if (row.size() != 9) return false;
            for (char c : row) {
                if (!characterValid(c)) return false;
                if (c<='9' && c>='1') {
                    auto it = mark.find(c);
                    if (it != mark.end()) return false;
                    mark.insert(c);
                }
            }
            mark.clear();
        }

        // column
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                char c = board[j][i];
                if (c<='9' && c>='1') {
                    auto it = mark.find(c);
                    if (it != mark.end()) return false;
                    mark.insert(c);
                }
            }
            mark.clear();
        }

        // grid
        int kStart, kEnd, lStart, lEnd;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                kStart = 3*i; kEnd = 3*i+3;
                lStart = 3*j; lEnd = 3*j+3;
                for (int k=kStart; k<kEnd; ++k) {
                    for (int l=lStart; l<lEnd; ++l) {
                        char c = board[k][l];
                        if (c<='9' && c>='1') {
                            auto it = mark.find(c);
                            if (it != mark.end()) return false;
                            mark.insert(c);
                        }
                    }
                }
                mark.clear();
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
