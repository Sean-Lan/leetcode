/**
 *
 * Sean
 * 2016-11-21
 *
 * https://leetcode.com/problems/island-perimeter/
 *
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 *
 * Example:
 *
 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]
 *
 * Answer: 16
 */
#include <iostream>
#include <vector>
using namespace std;

const static int directions[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

// O(m, n) check & count
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int perimeter = 0;
        auto getLength = [&grid, &m, &n](int i, int j) {
            int nextI, nextJ;
            int length = 0;
            for (auto direction : directions) {
                nextI = i+direction[0];
                nextJ = j+direction[1];
                if (nextI<0 || nextI>m-1 || nextJ<0 || nextJ>n-1 ||
                    grid[nextI][nextJ]==0) {
                    ++length;
                }
            }
            return length;
        };
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j])
                    perimeter += getLength(i, j);
            }
        }
        return perimeter;
    }
};

int main() {
    return 0;
}
