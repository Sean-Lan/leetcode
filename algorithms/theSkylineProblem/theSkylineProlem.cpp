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
#include <algorithm>
#include <utility>
using namespace std;

struct LXNode {
    int begin;
    int end;
    int height;
    int update;
};

// Segment Tree. Very tricky, not recommended.
// Little tricks:
//  1. We need to convert endpoint range [left, right] to [left, right] line
//     range to apply segment tree.
//  2. Since the left and right side of one building is between [0, INT_MAX],
//     we need to discretize the left and right values.
//     e.g: [200, 300, 500] -> [0, 1, 2]
//  3. We need to insert one value between adjacent values so that non-coterminous
//     buildings still keep non-coterminous.
//     e.g: [200, 300], [400, 500] -> [0, 1], (2), [3, 4]
//  4. We need to use lazy tag to each node.
//  5. Finally we get the maxHeights array. We need to check the relationship between
//     adjacent values. If left > right, the exact pair should be {Real[left]+1, height}.
//     If left < right, the exact pair should be {Real[right], height}.
class Solution {
    public:
        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
            if (buildings.empty()) return {};
            // first discretize
            vector<int> total, left, right;
            for (auto &building : buildings) {
                total.push_back(building[0]);
                total.push_back(building[1]-1);
                left.push_back(building[0]);
                right.push_back(building[1]-1);
            }
            sort(total.begin(), total.end());
            vector<int> processed = {total[0]};
            for (int i=1; i<total.size(); ++i) {
                if (total[i-1]!=total[i]) {
                    processed.push_back(total[i]);
                }
            }

            for (int i=processed.size()-1; i>0; --i) {
                if (processed[i-1]+1 != processed[i])
                    processed.push_back(total[i-1]+1);
            }

            sort(processed.begin(), processed.end());

            for (int i=0; i<left.size(); ++i) {
                left[i] = std::lower_bound(processed.begin(), processed.end(), left[i]) - processed.begin();
                right[i] = std::lower_bound(processed.begin(), processed.end(), right[i]) - processed.begin();
            }

            int maxValue = processed.size();
            vector<LXNode> tree(maxValue<<2);
            buildTree(1, 0, maxValue-1, tree);

            for (int i=0; i<buildings.size(); ++i)
                update(1, left[i], right[i], buildings[i][2], tree);
            vector<int> maxHeights(processed.size());
            query(1, 0, processed.size()-1, tree, maxHeights);
            vector<pair<int, int>> result;
            result.push_back({processed[0], maxHeights[0]});
            for (int i=1; i<maxHeights.size(); ++i) {
                if (maxHeights[i]>maxHeights[i-1])
                    result.push_back({processed[i], maxHeights[i]});
                else if (maxHeights[i]<maxHeights[i-1])
                    result.push_back({processed[i-1]+1, maxHeights[i]});
            }
            result.push_back({processed[maxValue-1]+1, 0});
            return result;
        }

        void buildTree(int root, int begin, int end, vector<LXNode> &tree) {
            LXNode &node = tree[root];
            node.begin = begin;
            node.end = end;
            node.height = 0;
            node.update = -1;
            if (begin == end)
                return;
            int leftChild = root<<1;
            int rightChild = leftChild|1;
            int mid = (begin+end)>>1;
            buildTree(leftChild, begin, mid, tree);
            buildTree(rightChild, mid+1, end, tree);
        }

        void pushDown(int root, vector<LXNode> &tree) {
            LXNode &node = tree[root];
            if (node.update!=-1) {
                LXNode &leftNode = tree[root<<1];
                LXNode &rightNode = tree[root<<1|1];
                leftNode.update = max(node.update, leftNode.update);
                rightNode.update = max(node.update, rightNode.update);
                node.update = -1;
            }
        }

        void update(int root, int begin, int end, int height, vector<LXNode> &tree) {
            LXNode &node = tree[root];
            if (node.begin>=begin && node.end<=end) {
                node.update = max(height, node.update);
                if (node.height!=-1)
                    node.height = max(node.height, node.update);
                return;
            }
            // push down;
            pushDown(root, tree);
            int mid = (node.begin+node.end)/2;
            int leftChild = root<<1;
            int rightChild = leftChild|1;
            if (end<=mid)
                update(leftChild, begin, end, height, tree);
            else if (begin>mid)
                update(rightChild, begin, end, height, tree);
            else {
                update(leftChild, begin, mid, height, tree);
                update(rightChild, mid+1, end, height, tree);
            }
            node.height = -1;
        }

        void query(int root, int begin, int end, vector<LXNode> &tree, vector<int> &maxHeights) {
            LXNode &node = tree[root];
            if (node.height!=-1) {
                node.height = max(node.height, node.update);
                for (int i=node.begin; i<=node.end; ++i)
                    maxHeights[i] = node.height;
                return;
            }
            pushDown(root, tree);
            int mid = (node.begin+node.end)>>1;
            int leftChild = root<<1;
            int rightChild = leftChild|1;
            if (end <= mid)
                query(leftChild, begin, end, tree, maxHeights);
            else if (begin > mid)
                query(rightChild, begin, end, tree, maxHeights);
            else {
                query(leftChild, begin, mid, tree, maxHeights);
                query(rightChild, mid+1, end, tree, maxHeights);
            }
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
    vector<vector<int>> buildings = { { 2,4,7 },{ 2,4,5 },{ 2,4,6 } };
    Solution solution;
    auto result = solution.getSkyline(buildings);
    printResult(result);

}
