/**
 *
 * Sean
 * 2017-06-21
 *
 * https://leetcode.com/problems/number-of-islands-ii/#/description
 *
 * A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example:
 *
 * Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
 * Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
 *
 * 0 0 0
 * 0 0 0
 * 0 0 0
 * Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
 *
 * 1 0 0
 * 0 0 0   Number of islands = 1
 * 0 0 0
 * Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
 *
 * 1 1 0
 * 0 0 0   Number of islands = 1
 * 0 0 0
 * Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
 *
 * 1 1 0
 * 0 0 1   Number of islands = 2
 * 0 0 0
 * Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
 *
 * 1 1 0
 * 0 0 1   Number of islands = 3
 * 0 1 0
 * We return the result as an array: [1, 1, 2, 3]
 *
 * Challenge:
 *
 * Can you do it in time complexity O(k log mn), where k is the length of the positions?
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// UnionFind
// maintain a count, every time a gird is made into land, +1
// every time two different ilands merge, -1
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (m == 0 || n == 0) return {};
        vector<int> roots(m*n, -1);
        vector<int> ranks(m*n, 1);
        int cnt = 0;

        function<int(int)> findRoot = [&] (int x) {
            if (roots[x] != x) {
                roots[x] = findRoot(roots[x]);
            }
            return roots[x];
        };

        auto unionTwo = [&] (int x, int y) {
            int r1 = findRoot(x);
            int r2 = findRoot(y);
            if (r1 == r2) return r1;
            --cnt;
            if (ranks[r1] > ranks[r2]) {
                return roots[r2] = r1;
            }
            if (ranks[r1] < ranks[r2]) {
                return roots[r1] = r2;
            }

            ++ ranks[r1];
            return roots[r2] = r1;
        };


        vector<int> res;
        for (auto &aPair : positions) {
            int index = aPair.first*n + aPair.second;
            if (roots[index] != -1) { // already be land
                res.push_back(cnt);
                continue;
            }
            roots[index] = index;
            ++ cnt;
            int nextIndex;
            if (aPair.first > 0) { // up
                nextIndex = index - n;
                if (roots[nextIndex] != -1) unionTwo(index, nextIndex);
            }
            if (aPair.first < m-1) { // down
                nextIndex = index + n;
                if (roots[nextIndex] != -1) unionTwo(index, nextIndex);
            }
            if (aPair.second > 0) { // left
                nextIndex = index - 1;
                if (roots[nextIndex] != -1) unionTwo(index, nextIndex);
            }
            if (aPair.second < n-1) { // right
                nextIndex = index + 1;
                if (roots[nextIndex] != -1) unionTwo(index, nextIndex);
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main() {
    Solution solution;
    int m = 3;
    int n = 3;
    vector<pair<int, int>> positions = {
        {0,1}, {1,2}, {2,1}, {1,0}, {0,2}, {0,0}, {1,1}
    };
    auto res = solution.numIslands2(m, n, positions);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
