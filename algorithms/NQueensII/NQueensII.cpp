/**
 *
 * Sean
 * 2016-03-19
 *
 * https://leetcode.com/problems/n-queens-ii/
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// DFS with backtracking.
class Solution {
    public:
        int totalNQueens(int n) {
            vector<int> current;
            return dfs(current, n);
        }
    private:
        int dfs(vector<int> &current, const int &n) {
            if (current.size() == n)
                return 1;
            int result = 0;
            for (int i=0; i<n; ++i) {
                if (valid(current, i)) {
                    current.push_back(i);
                    result += dfs(current, n);
                    current.pop_back();
                }
            }
            return result;
        }

        inline bool valid(vector<int> &current, const int &y2) {
            int x2 = current.size();
            int y1;
            for (int x1=0; x1<x2; ++x1) {
                y1 = current[x1];
               if (y2==y1 || (y1-y2)==(x1-x2) ||
                       (y1-y2)==(x2-x1))
                   return false;
            }
            return true;
        }
};

int main() {
    Solution solution;
    cout << solution.totalNQueens(8) << endl;
}
