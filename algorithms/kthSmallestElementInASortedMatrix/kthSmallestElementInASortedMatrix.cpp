/**
 *
 * Sean
 * 2016-12-14
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 *
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
 *
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 *
 * Example:
 *
 * matrix = [
 *    [ 1,  5,  9],
 *    [10, 11, 13],
 *    [12, 13, 15]
 * ],
 *
 * k = 8,
 *
 * return 13.
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct MyPoint {
    int x, y, val;
    MyPoint (int x, int y, int val): x(x), y(y), val(val) {}
    bool operator<(const MyPoint& point) const { return val > point.val; }
};

// heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<MyPoint> aQueue;
        int m = matrix.size(), n = matrix[0].size();
        int minVal = min(k, n);
        for (int i=0; i<minVal; ++i)
            aQueue.push(MyPoint(0, i, matrix[0][i]));
           
        for (int i=1; i<k; ++i) {
            MyPoint p = aQueue.top();
            aQueue.pop();
            if (p.x == m-1) continue;
            aQueue.push(MyPoint(p.x+1, p.y, matrix[p.x+1][p.y]));
        }
        
        return aQueue.top().val;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,5,9}, {10,11,13}, {12,13,15}
    };
    Solution solution;
    cout << solution.kthSmallest(matrix, 8) << endl;
    return 0;
}
