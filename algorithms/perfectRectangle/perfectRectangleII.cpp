/**
 *
 * Sean
 * 2016-08-31
 *
 * https://leetcode.com/problems/perfect-rectangle/
 *
 * Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.
 *
 * Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).
 *
 *
 * Example 1:
 *
 * rectangles = [
 *   [1,1,3,3],
 *   [3,1,4,2],
 *   [3,2,4,4],
 *   [1,3,2,4],
 *   [2,3,3,4]
 * ]
 *
 * Return true. All 5 rectangles together form an exact cover of a rectangular region.
 *
 * Example 2:
 *
 * rectangles = [
 *   [1,1,2,3],
 *   [1,3,2,4],
 *   [3,1,4,2],
 *   [3,2,4,4]
 * ]
 *
 * Return false. Because there is a gap between the two rectangular regions.
 *
 * Example 3:
 *
 * rectangles = [
 *   [1,1,3,3],
 *   [3,1,4,2],
 *   [1,3,2,4],
 *   [3,2,4,4]
 * ]
 *
 * Return false. Because there is a gap in the top center.
 *
 * Example 4:
 *
 * rectangles = [
 *   [1,1,3,3],
 *   [3,1,4,2],
 *   [1,3,2,4],
 *   [2,2,4,4]
 * ]
 *
 * Return false. Because two of the rectangles overlap with each other.
 *
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Use event-based method to handle the X-axis, and use a Set to handle the Y-axis.
class Solution {
    typedef long long ll;
    public:
        bool isRectangleCover(vector<vector<int>>& rectangles) {
            int minX = rectangles[0][0],
                minY = rectangles[0][1],
                maxX = rectangles[0][2],
                maxY = rectangles[0][3];
            vector<pair<int, int>> events;
            events.emplace_back(minX, 1);
            events.emplace_back(maxX, -1);

            ll sumArea = (ll)(maxX-minX)*(maxY-minY);
            int n = rectangles.size();
            for (int i=1; i<rectangles.size(); ++i) {
                int x1 = rectangles[i][0],
                    y1 = rectangles[i][1],
                    x2 = rectangles[i][2],
                    y2 = rectangles[i][3];
                events.emplace_back(x1, i+1);
                events.emplace_back(x2, -(i+1));
                minX = min(minX, x1);
                minY = min(minY, y1);
                maxX = max(maxX, x2);
                maxY = max(maxY, y2);
                sumArea += (ll)(x2-x1) * (y2-y1);
            }

            ll idealSize = (ll)(maxX-minX) * (maxY-minY);
            if (sumArea != idealSize)
                return false;

            sort(events.begin(), events.end());

            auto overlap = [&rectangles](int i, int j) {
                // !((s2 >= e1) || (s1 >= e2))
                return rectangles[i][1] < rectangles[j][3] && rectangles[j][1] < rectangles[i][3];
            };

            auto cmp = [&](int i, int j) {
                if (overlap(i, j)) return false; // won't insert the new
                return rectangles[i][1] < rectangles[j][1];
            };

            set<int, decltype(cmp)> verticals(cmp);

            for (auto &event : events) {
                if (event.second > 0) {
                    if (verticals.find(event.second-1) != verticals.end())
                        return false;
                    verticals.insert(event.second-1);
                } else {
                    verticals.erase(-event.second-1);
                }
            }
            return true;
        }
};

int main() {
    Solution solution;
    vector<vector<int>> rectangles = {
        { 1,1,3,3 },
        { 3,1,4,2 },
        { 3,2,4,4 },
        { 1,3,2,4 },
        { 2,3,3,4 }
    };
    cout << solution.isRectangleCover(rectangles) << endl;
    return 0;
}
