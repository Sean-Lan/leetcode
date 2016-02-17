/**
 *
 * Sean
 * 2016-02-17
 *
 * https://leetcode.com/problems/sudoku-solver/
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 */

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef pair<int, int> Coordinates;

class Solution {
private:
    typedef vector<vector<char>> Board;
    vector<Coordinates> blankCoordinates;
    unordered_set<char> rowTables[9];
    unordered_set<char> columnTables[9];
    unordered_set<char> gridTables[3][3];
    bool dfs(Board &board, int n) {
        if (n == blankCoordinates.size()) return true;
        auto cooridinates = blankCoordinates[n];
        auto &rowTable = rowTables[cooridinates.first];
        auto &columnTable = columnTables[cooridinates.second];
        auto &gridTable = gridTables[cooridinates.first/3][cooridinates.second/3];
        char c;
        for (int i = 0; i<9; ++i) {
            c = '1'+i;
            if (rowTable.find(c) != rowTable.end() ||
                columnTable.find(c) != columnTable.end() ||
                gridTable.find(c) != gridTable.end())
                continue;
            board[cooridinates.first][cooridinates.second] = c;
            // update char tables
            rowTable.insert(c);
            columnTable.insert(c);
            gridTable.insert(c);
            if(dfs(board, n+1)) return true;

            // undo update
            rowTable.erase(rowTable.find(c));
            columnTable.erase(columnTable.find(c));
            gridTable.erase(gridTable.find(c));
        }
        return false;
    }

    void clearAll() {
        blankCoordinates.clear();
        for (int i=0; i<9; ++i) {
            rowTables[i].clear();
            columnTables[i].clear();
        }

        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
                gridTables[i][j].clear();
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        clearAll();
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                char c = board[i][j];
                if (c == '.')
                    blankCoordinates.push_back({i,j});
                else {
                    rowTables[i].insert(c);
                    columnTables[j].insert(c);
                    gridTables[i/3][j/3].insert(c);
                }
            }
        }
        dfs(board, 0);
    }
};

int main() {
}
