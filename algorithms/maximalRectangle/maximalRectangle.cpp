/**
 *
 * Sean
 * 2016-05-21
 *
 * https://leetcode.com/problems/maximal-rectangle/
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// O(m*n)
// monotonic increasing queue
// every time an index i is pop out from the stack, which mean we get a height <= the maximum height of the queue
// we can obtain the rightmost index of height < heights[i] (the previous index in the stack) and thus we can get the area
// formed with the height to be popped out and width (index difference).
// add an 0 to it to pop out all the remaining indexes in the stack
class Solution {
    int getMaxArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> s;
        int area = 0;
        for (int i=0; i<=n; ++i) {
            int h = i == n ? 0 : heights[i];
            while (!s.empty()  && heights[s.top()] >= h) {
                int maxH = heights[s.top()];
                s.pop();
                area = max(area,  maxH * (s.empty() ? i : i-s.top()-1));
            }
            s.push(i);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int area = 0;
        for (int i=0; i<m; ++i) {
            auto &row = matrix[i];
            for (int j=0; j<n; ++j) {
                if (row[j] == '0') heights[j] = 0;
                else ++heights[j];
            }
            area = max(area, getMaxArea(heights));
        }
        return area;
    }
};

int main() {
    return 0;
}
