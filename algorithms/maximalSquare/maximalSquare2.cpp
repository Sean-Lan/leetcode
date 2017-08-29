/**
 *
 * Sean
 * 2017-08-29
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 4.
 *
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// O(m*n)
// monotonic increasing queue
class Solution {
    // 3 pass to get the maximum width can reach given the bar heights
    int getMaxWidth(vector<int> &heights) {
        int n = heights.size();
        vector<int> pre(n, 0); // the number of bars before current bar that are not lower (current bar included)
        vector<int> suc(n, 0); // the number bars after current bar that are not lower (current bar included)
        // monotonic increasing queue which stores indexs
        stack<int> s;
        for (int i=0; i<n; ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            int start = s.empty() ? -1 : s.top();
            pre[i] = i - start;
            s.push(i);
        }

        s = stack<int>();
        for (int i=n-1; i>=0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            int end = s.empty() ? n : s.top();
            suc[i] = end - i;
            s.push(i);
        }
        int w = 0;
        for (int i=0; i<n; ++i) {
            w = max(w, min(heights[i], pre[i]+suc[i]-1));
        }
        return w;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxW = 0;
        for (int i=0; i<m; ++i) {
            auto &row = matrix[i];
            for (int j=0; j<n; ++j) {
                if (row[j] == '0') heights[j] = 0;
                else ++heights[j];
            }
            maxW = max(maxW, getMaxWidth(heights));
        }
        return maxW * maxW;
    }
};

int main() {
    return 0;
}
