/**
 *
 * Sean
 * 2016-03-25
 *
 * https://leetcode.com/problems/the-skyline-problem/
 *
 * A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
 *
 *  Buildings  Skyline Contour
 *  The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
 *
 *  For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
 *
 *  The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
 *
 *  For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
 *
 *  Notes:
 *
 *  The number of buildings in any input list is guaranteed to be in the range [0, 10000].
 *  The input list is already sorted in ascending order by the left x position Li.
 *  The output list must be sorted by the x position.
 *  There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
 *
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <functional>
using namespace std;

// reference to https://leetcode.com/discuss/61274/17-line-log-time-space-accepted-easy-solution-explanations
class Solution {
    public:
        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
            // first sort all the points according to x
            vector<pair<int, int>> points;
            for (auto &building : buildings) {
                points.emplace_back(building[0], building[2]);
                points.emplace_back(building[1], -building[2]);
            }
            std::sort(points.begin(), points.end(),
                    [](pair<int, int> &p1, pair<int, int> &p2) {
                        return p1.first < p2.first;
                    });

            // construct the corners map
            std::multiset<int, greater<int>> heights = {0};
            map<int, int> corners;
            int maxHeight;
            for (auto &aPair : points) {
                if (aPair.second > 0) {
                    heights.insert(aPair.second);
                } else {
                    heights.erase(heights.find(-aPair.second));
                }
                maxHeight = *heights.begin();
                corners[aPair.first] = maxHeight;
            }

            // remove duplicates
            vector<pair<int, int>> result;
            std::unique_copy(corners.begin(), corners.end(), std::back_inserter(result),
                    [](const pair<int, int> &p1, const pair<int, int> &p2) {
                        return p1.second == p2.second;
                    });
            return result;
        }
};


void printResult(vector<pair<int, int>> &result) {
    for (auto &aPair : result) {
        cout << "[" << aPair.first << "," << aPair.second << "]" << " ";
    }
    cout << endl;
}

int main() {
    /* vector<vector<int>> buildings = { { 2,9,10 }, { 3,7,15 }, { 5,12,12 }, { 15,20,10 }, { 19,24,8 } }; */
    /* vector<vector<int>> buildings = { { 2,13,10 },{ 10,17,25 },{ 12,20,14 } }; */
    /* vector<vector<int>> buildings = { { 2,4,5 },{ 2,4,7 },{ 2,4,6 } }; */
    vector<vector<int>> buildings;
    Solution solution;
    auto result = solution.getSkyline(buildings);
    printResult(result);

}
