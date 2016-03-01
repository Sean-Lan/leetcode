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

/**
 *
 * This problem is tedious, but it's a good exercise for practicing hash table.
 * Some notes:
 * 1. Be sure to force the cast when dealing with integer division.
 * 2. Points may be idencal, and both of them count.
 *
 */

// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

size_t double_hash(const double &dValue) {
    int e = 0;
    double tmp = dValue;
    if (dValue<0) {
        tmp = -dValue;
    }
    e = ceil(log(tmp));
    return size_t((INT64_MAX + 1.0) * tmp * exp(-e));
}

typedef pair<double, double> Line;

struct LineHash {
    size_t operator() (const Line& line) const {
        return double_hash(line.first)*31 + double_hash(line.second);
    }
};

struct LineEqual {
 bool operator()(const Line& lhs, const Line& rhs) const
 {
    return lhs.first == rhs.first && lhs.second == rhs.second;
 }
};

struct PointHash {
    size_t operator() (const Point & point) const {
        return point.x * 31 + point.y;
    }
};

struct PointEqual {
 bool operator()(const Point& lhs, const Point& rhs) const
 {
    return lhs.x == rhs.x && lhs.y == rhs.y;
 }
};

class Solution {
    private:
        Line calculateLine(Point& point1, Point& point2) {
            return make_pair((double)(point2.y-point1.y)/(point2.x-point1.x),
                    (double)(point2.x*point1.y-point1.x*point2.y)/(point2.x-point1.x));
        }
        typedef unordered_set<Point, PointHash, PointEqual> PointSet;

    public:
        int maxPoints(vector<Point>& points) {
            if (points.size()<=1)
                return points.size();
            unordered_map<Point, int, PointHash, PointEqual> pointCnt;
            unordered_map<Line, int, LineHash, LineEqual> lineCnt;
            unordered_map<int, int> verticalLineCnt;
            for (auto &point : points)
                ++pointCnt[point];
            int maxCnt = 0;
            unordered_map<Line, PointSet, LineHash, LineEqual> lines;
            unordered_map<int, unordered_set<int>> vecticalLines;
            for (int i=0; i<points.size(); ++i) {
                for (int j=i+1; j<points.size(); ++j) {
                    auto &point1 = points[i];
                    auto &point2 = points[j];
                    if (point1.x == point2.x) {
                        if (vecticalLines[point1.x].count(point1.y) == 0) {
                            vecticalLines[point1.x].insert(point1.y);
                            verticalLineCnt[point1.x] += pointCnt[point1];
                        }
                        if (vecticalLines[point1.x].count(point2.y) == 0) {
                            vecticalLines[point1.x].insert(point2.y);
                            verticalLineCnt[point1.x] += pointCnt[point2];
                        }
                        maxCnt = max(maxCnt, verticalLineCnt[point1.x]);
                        continue;
                    }
                    Line line = calculateLine(point1, point2);
                    /* cout << line.first << " " << line.second << endl; */
                    if (lines[line].count(point1) == 0) {
                        lines[line].insert(point1);
                        lineCnt[line] += pointCnt[point1];
                    }
                    if (lines[line].count(point2) == 0) {
                        lines[line].insert(point2);
                        lineCnt[line] += pointCnt[point2];
                    }
                    maxCnt = max(maxCnt, lineCnt[line]);
                }
            }
            return maxCnt;
        }
};

int main() {
    vector<Point> points = { {0,9}, {138,429}, {115, 359}, {150, 774} };
    Solution solution;
    cout << solution.maxPoints(points) << endl;
}
