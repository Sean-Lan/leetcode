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
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

struct Event {
    bool isStart;
    int timeStamp;
    int index;

    Event(int index, int timeStamp, bool isStart) {
        this->index = index;
        this->timeStamp = timeStamp;
        this-> isStart = isStart;
    }

    bool operator<(const Event &event) const {
        if (this->timeStamp != event.timeStamp)
            return this->timeStamp < event.timeStamp;
        return this->isStart > event.isStart;
    }
};

class Solution {
    typedef long long ll;

    inline ll calRectArea(int minX, int minY, int maxX, int maxY) {
        return (ll)(maxX-minX+1)*(maxY-minY+1);
    }

public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return true;
        int minX, minY, maxX, maxY;
        -- rectangles[0][2];
        -- rectangles[0][3];
        minX = rectangles[0][0];
        minY = rectangles[0][1];
        maxX = rectangles[0][2];
        maxY = rectangles[0][3];
        ll areaSum = calRectArea(minX, minY, maxX, maxY);
        vector<Event> events;
        events.emplace_back(0, minY, true);
        events.emplace_back(0, maxY, false);

        int rectNums = rectangles.size();
        for (int i=1; i<rectNums; ++i) {
            auto &aRect = rectangles[i];
            -- aRect[2];
            -- aRect[3];
            int x1 = aRect[0], y1 = aRect[1], x2 = aRect[2], y2 = aRect[3];
            events.emplace_back(i, y1, true);
            events.emplace_back(i, y2, false);
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);
            areaSum += calRectArea(x1, y1, x2, y2);
        }

        ll maxArea = calRectArea(minX, minY, maxX, maxY);
        if (areaSum != maxArea)
            return false;

        sort(events.begin(), events.end());

        auto leftCmp = [&rectangles](int index1, int index2) {
            return rectangles[index1][0] < rectangles[index2][0];
        };

        auto rightCmp = [&rectangles](int index1, int index2) {
            return rectangles[index1][2] < rectangles[index2][2];
        };

        set<int, decltype(leftCmp)> leftSet(leftCmp);
        set<int, decltype(rightCmp)> rightSet(rightCmp);

        for (auto &event : events) {
            if (event.isStart) {
                // check whether overlap
                if (!rightSet.empty()) {
                    auto it = rightSet.lower_bound(event.index);
                    int index1 = -1, index2= -1;
                    if (it!=rightSet.end()) {
                        index1 = *it;
                        if (rectangles[index1][0] <= rectangles[event.index][2])
                            return false;
                    }

                    it = leftSet.lower_bound(event.index);
                    if (it != leftSet.end()) {
                        index2 = *it;
                        if (index1 != index2)
                            return false;
                        if (it!=leftSet.begin()) {
                            index2 = *std::prev(it);
                            if (rectangles[index2][2] >= rectangles[event.index][0])
                                return false;
                        }
                    } else {
                        if (index1 != -1)
                            return false;
                        index2 = *std::prev(it);
                        if (rectangles[index2][2] >= rectangles[event.index][0])
                            return false;
                    }
                }

                leftSet.insert(event.index);
                rightSet.insert(event.index);
            } else {
                leftSet.erase(event.index);
                rightSet.erase(event.index);
            }
        }

        return true;
    }
};

typedef vector<vector<int>> vii;
int main() {
    Solution solution;
    vii rectangles = {
        { 0,0,4,1 },
        { 7,0,8,2 },
        { 6,2,8,3 },
        { 5,1,6,3 },
        { 4,0,5,1 },
        { 6,0,7,2 },
        { 4,2,5,3 },
        { 2,1,4,3 },
        { 0,1,2,2 },
        { 0,2,2,3 },
        { 4,1,5,2 },
        { 5,0,6,1 }
    };

    cout << solution.isRectangleCover(rectangles) << endl;
    return 0;
}
