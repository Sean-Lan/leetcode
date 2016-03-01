/**
 *
 * Sean
 * 2016-03-01
 *
 * https://leetcode.com/problems/max-points-on-a-line/
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *
 */
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// referece from http://www.jianshu.com/p/6a3e931a1af3
// A good example for using lambda.
class Solution
{
public:
    int maxPoints(vector<Point>& points)
    {
        if (points.size() < 3)
        {
            return points.size();
        }

        sort(points.begin(), points.end(), 
            [](Point &pt1, Point &pt2) { return pt1.x == pt2.x ? pt1.y < pt2. y : pt1.x < pt2.x; });
        int maxPts = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (i > 0 && samePoint(points[i], points[i - 1]))  // pass duplicates.
            {
                continue;
            }

            unordered_map<double, int> ptsOnLines;
            int originPts = 1;
            for (int j = i + 1; j < points.size(); j++)
            {
                if (samePoint(points[i], points[j]))
                {
                    originPts++;
                }
                else if (verticleLine(points[i], points[j]))
                {
                    ptsOnLines[numeric_limits<double>::infinity()]++;
                }
                else
                {
                    ptsOnLines[slope(points[i], points[j])]++;
                }
            }

            using T = unordered_map<double, int>::value_type;
            auto itr = max_element(ptsOnLines.begin(), ptsOnLines.end(), 
                    [](const T &p1, const T &p2) { return p1.second < p2.second; });
            maxPts = max(maxPts, originPts + (itr == ptsOnLines.end() ? 0 : itr->second));
        }
        return maxPts;
    }

private:
    inline bool samePoint(const Point &pt1, const Point &pt2)
    {
        return pt1.x == pt2.x && pt1.y == pt2.y;
    }

    inline bool verticleLine(const Point &pt1, const Point &pt2)
    {
        return pt1.x == pt2.x && pt1.y != pt2.y;
    }

    inline double slope(const Point &pt1, const Point &pt2)
    {
        return ((double) pt2.y - pt1.y) / (pt2.x - pt1.x);
    }
};

int main() {
    vector<Point> points = { {0,9}, {138,429}, {115, 359}, {150, 774} };
    Solution solution;
    cout << solution.maxPoints(points) << endl;
}
