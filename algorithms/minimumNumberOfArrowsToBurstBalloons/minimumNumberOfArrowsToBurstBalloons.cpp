/**
 *
 * Sean
 * 2017-06-07
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/#/description
 *
 * There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
 *
 * An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.
 *
 * Example:
 *
 * Input:
 * [[10,16], [2,8], [1,6], [7,12]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
 *
 */
#include <queue>
#include <iostream>
using namespace std;

// Greedy
// Sort by the end position fo the balloons
// Every time we add an arrow at the end position of balloon with the smallest end, otherwise this balloon will not be bursted. Then, bursted all the balloons with start position <= the arrow position
// This greedy method works because every time we burst the maximum number of the balloons: suppose we set the arrow ahead of the end position of the balloon with the smallest end, more balloons could remain
// O (n*log(n)) with priority_queue
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        auto endCmp = [&points] (int i, int j) {
            auto &point1 = points[i];
            auto &point2 = points[j];
            if (point1.second != point2.second)
                return point1.second > point2.second;
            return point1.first > point2.first;
        };
        
        auto startCmp = [&points] (int i, int j) {
            auto &point1 = points[i];
            auto &point2 = points[j];
            if (point1.first != point2.first)
                return point1.first > point2.first;
            return point1.second > point2.second;
        };
        priority_queue<int, vector<int>, decltype(endCmp)> endQ(endCmp);
        priority_queue<int, vector<int>, decltype(startCmp)> startQ(startCmp);
        
        int n = points.size();
        for (int i=0; i<n; ++i) {
            endQ.push(i);
            startQ.push(i);
        }
        
        vector<bool> bursted(n, false);
        int cnt = 0;
        int e;
        int s;
        int endPos;
        while (!endQ.empty()) {
            e = endQ.top();
            if (!bursted[e]) {
                ++ cnt;
                endPos = points[e].second;
                while(!startQ.empty()) {
                    s = startQ.top();
                    if (points[s].first <= endPos) {
                        bursted[s] = true;
                        startQ.pop();
                    } else break;
                }
            }
            endQ.pop();
        }
        return cnt;
    }
};

int main() {
    return 0;
}
