/**
 *
 * Sean
 * 2017-06-13
 *
 * https://leetcode.com/problems/convex-polygon/#/description
 *
 * Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).
 *
 * Note:
 *
 * There are at least 3 and at most 10,000 points.
 * Coordinates are in the range -10,000 to 10,000.
 * You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.
 *
 */
#include <vector>
using namespace std;

class Solution {
    int crossProduct(vector<int> &A, vector<int> &B, vector<int> &C) {
        int abx = B[0] - A[0];
        int aby = B[1] - A[1];
        int bcx = C[0] - B[0];
        int bcy = C[1] - B[1];
        return abx*bcy - bcx*aby;
    }

public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return false;
        bool positive = false;
        bool negative = false;
        int val = crossProduct(points[n-1], points[0], points[1]);
        // three points may be in a line, like the following two:
        // ----
        // |  |
        // ----
        //
        // -----
        // |    |_
        // |      |
        // --------
        //
        // so, simply check whether the product of adjacent cross products < 0 doestn't work
        if (val > 0) positive = true;
        if (val < 0) negative = true;

        for (int i=1; i<n; ++i) {
            int a = i-1;
            int b = i;
            int c = i+1;
            if (c == n) c = 0;
            val = crossProduct(points[a], points[b], points[c]);
            if (val > 0) positive = true;
            if (val < 0) negative = true;
            if (positive && negative) return false;
        }
        return true;
    }

};

int main() {
    return 0;
}
