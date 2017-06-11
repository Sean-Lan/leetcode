/**
 *
 * Sean
 * 2017-06-11
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/#/description
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 *
 * Example 1:
 *
 * nums = [
 *   [9,9,4],
 *   [6,6,8],
 *   [2,1,1]
 * ]
 * Return 4
 * The longest increasing path is [1, 2, 6, 9].
 *
 * Example 2:
 *
 * nums = [
 *   [3,4,5],
 *   [3,2,6],
 *   [2,2,1]
 * ]
 * Return 4
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 *
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
#include <queue>
using namespace std;

static const int dirs[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

struct PairHash {
    size_t operator() (const pair<int, int> &aPair) const {
        return std::hash<int>()(aPair.first) ^
               (std::hash<int>()(aPair.second) << 1);
    }
};

// similar to topological sort, and in a level visiting way
// every time we remove those *peak* values until the very end, the number of iterations is the longest path count
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> mark(m, vector<bool>(n, false));
        auto isPeak = [&](int i, int j) {
            return (j == 0 || mark[i][j-1] || matrix[i][j] >= matrix[i][j-1]) && // left
                (j == n-1 || mark[i][j+1] || matrix[i][j] >= matrix[i][j+1]) && // right
                (i == 0 || mark[i-1][j] || matrix[i][j] >= matrix[i-1][j]) && // up
                (i == m-1 || mark[i+1][j] || matrix[i][j] >= matrix[i+1][j]); // bottom
        };

        // use a Set to remove duplicate
        unordered_set<pair<int, int>, PairHash> nextLevel;
        queue<pair<int, int>> aQueue;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (isPeak(i, j)) {
                    nextLevel.insert({i, j});
                }
            }
        }

        for (auto &aPair : nextLevel) {
            aQueue.push(aPair);
            mark[aPair.first][aPair.second] = true;
        }

        int len = 0;
        int levelCnt = 0;
        pair<int, int> next;

        while (!aQueue.empty()) {
            ++len;
            levelCnt = aQueue.size();
            nextLevel.clear();
            for (int i=0; i<levelCnt; ++i) {
                auto &cur = aQueue.front();
                for (auto &d : dirs) {
                    next.first = cur.first + d[0];
                    next.second = cur.second + d[1];
                    if (next.first >= 0 && next.first < m &&
                        next.second >=0 && next.second < n &&
                        !mark[next.first][next.second] &&
                        isPeak(next.first, next.second)) {
                        nextLevel.insert(next);
                    }
                }
                aQueue.pop();
            }
            for (auto &aPair : nextLevel) {
                aQueue.push(aPair);
                mark[aPair.first][aPair.second] = true;
            }
        }
        return len;
    }
};

int main() {
    return 0;
}
