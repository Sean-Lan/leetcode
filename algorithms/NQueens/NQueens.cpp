/**
 *
 * Sean
 * 2016-03-14
 *
 * https://leetcode.com/problems/n-queens/
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// classic DFS with backtracking.
// Note: A queen can attack others queens if others queen are in the same row, same column or same digonal line.
class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<int>> results;
            vector<int> currentResult;
            dfs(0, n, currentResult, results);
            int solutionCnt = results.size();
            vector<vector<string>> converted(solutionCnt,
                    vector<string>(n,string(n, '.')));
            for (int i=0; i<solutionCnt; ++i) {
                auto &result = results[i];
                for (int j=0; j<n; ++j)
                    converted[i][j][result[j]] = 'Q';
            }
            return converted;
        }

    private:
        void dfs(int step, const int& n, vector<int> &currentResult,
                vector<vector<int>> &results) {
            if (step == n) {
                results.push_back(currentResult);
                return;
            }
            for (int i=0; i<n; ++i) {
                if (conflict(currentResult, i))
                    continue;
                currentResult.push_back(i);
                dfs(step+1, n, currentResult, results);
                currentResult.pop_back();

            }
        }

        inline bool conflict(const vector<int> &currAnswer, int pos)
        {
            int currentLine = currAnswer.size();
            for (int i=0; i<currentLine; ++i) {
                int pos1 = currAnswer[i];
                if (pos == pos1 || currentLine-i==pos-pos1 ||
                        currentLine-i==pos1-pos)
                    return true;
            }
            return false;
        }
};

void printResult(vector<vector<string>> &results) {
    for (auto &result : results) {
        for (auto &aLine : result) {
            cout << aLine << endl;
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    auto results = solution.solveNQueens(9);
    printResult(results);
}
