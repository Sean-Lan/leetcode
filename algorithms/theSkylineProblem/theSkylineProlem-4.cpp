/**
 *
 * Sean
 * 2016-09-07
 *
 * https://leetcode.com/problems/the-skyline-problem/
 *
 * A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
 *
 *  Buildings Skyline Contour
 * The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
 *
 * For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
 *
 * The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
 *
 * For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
 *
 * Notes:
 *
 * The number of buildings in any input list is guaranteed to be in the range [0, 10000].
 * The input list is already sorted in ascending order by the left x position Li.
 * The output list must be sorted by the x position.
 * There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

// Using segment tree and lazy propagation.
class SegTree {
    vector<int> values;
public:
    SegTree(int n): values(vector<int>(n<<2, 0)) {}
    void update(int root, int left, int right, int leftRange, int rightRange, int value) {
        if (leftRange > rightRange || leftRange > right || rightRange < left) // no intersection
            return;
        if (leftRange <= left && rightRange >= right) {// totally cover
            values[root] = max(values[root], value);
            return;
        }

        // partically
        int mid = (left+right) >> 1;
        update(root<<1, left, mid, leftRange, rightRange, value);
        update((root<<1)+1, mid+1, right, leftRange, rightRange, value);
    }

    int query(int root, int left, int right, int index) {
        if (left == right)
            return values[root];
        int mid = (left+right) >> 1;
        int res = (index <= mid) ? query(root << 1, left, mid, index) : query((root<<1)+1, mid+1, right, index);
        return max(res, values[root]); // because of the lazy propagation
    }

};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> endPoints;
        for (auto &building : buildings) {
            endPoints.insert(building[0]);
            endPoints.insert(building[1]);
        }

        // intMap maps endPoints to [0, .., k]
        // rMap maps [0, .., k] to endPoints
        unordered_map<int, int> intMap, rMap;
        int k = 0;
        for (auto endPoint : endPoints) {
            intMap[endPoint] = k;
            rMap[k++] = endPoint;
        }
        SegTree segTree(k--);

        // build the SegTree
        for (auto &building : buildings)
            segTree.update(1, 0, k, intMap[building[0]], intMap[building[1]]-1, building[2]);

        int preHeight = 0, height;
        vector<pair<int, int>> contour;
        for (int i=0; i <= k; ++i) { // the k-th height is zero.
            height = segTree.query(1, 0, k, i);
            if (preHeight == height) continue;
            contour.emplace_back(rMap[i], height);
            preHeight = height;
        }
        return contour;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> buildings = {
        { 2,9,10 },
        { 5,9,8 },
        { 3,7,15 },
        { 5,12,12 },
        { 15,20,10 },
        { 19,24,8 },
        { 9,11,12 }
    };

    auto contour = solution.getSkyline(buildings);
    for (auto &aPair : contour)
        cout << aPair.first << " " << aPair.second << endl;
    return 0;
}
