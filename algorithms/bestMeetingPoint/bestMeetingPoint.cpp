/**
 *
 * Sean
 * 2016-12-01
 *
 * A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
 *
 * For example, given three people living at (0,0), (0,4), and (2,2):
 *
 * 1 - 0 - 0 - 0 - 1
 * |   |   |   |   |
 * 0 - 0 - 0 - 0 - 0
 * |   |   |   |   |
 * 0 - 0 - 1 - 0 - 0
 *
 * The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
 *
 */
#include <cstdlib>
#include <vector>
using namespace std;

// Consider each dimension separately.
// It is an extension to problem https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> xValues;
        vector<int> yValues;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]) {
                    xValues.push_back(i);
                    yValues.push_back(j);
                }
            }
        }

        int totalCnt = xValues.size();
        nth_element(xValues.begin(), xValues.begin()+totalCnt/2, xValues.end());
        nth_element(yValues.begin(), yValues.begin()+totalCnt/2, yValues.end());
        int midX = *(xValues.begin()+totalCnt/2);
        int midY = *(yValues.begin()+totalCnt/2);

        int totalDistance = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]) {
                    totalDistance += abs(i-midX) + abs(j-midY);
                }
            }
        }
        return totalDistance;
    }
};

int main() {
    return 0;
}
