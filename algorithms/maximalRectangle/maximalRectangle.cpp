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

// O(n^2).
// First use DP to get the histo heights level by level, then use a stakc similar to Largest Rectangle in Histogram problem
// to get the max area level by level.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> histos = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        int m = matrix.size();
        int n = matrix[0].size();
        auto &firstLine = matrix[0];
        auto &firstHisto = histos[0];
        for (int i=0; i<n; ++i) {
            firstHisto[i] = (firstLine[i]=='1');
        }

        for (int i=1; i<m; ++i) {
            auto &lastHisto = histos[i-1];
            auto &curHisto = histos[i];
            auto &curLine = matrix[i];
            for (int j=0; j<n; ++j) {
                if (curLine[j] == '1') {
                    curHisto[j] = lastHisto[j]+1;
                }
            }
        }

        int maxArea = 0;
        for (auto &histo : histos) {
            maxArea = max(maxArea,
                        maxRectArea(histo));
        }

        return maxArea;
    }

    int maxRectArea(vector<int> &histo) {
        histo.push_back(-1);
        stack<int> aStack;
        int i = 0;
        int size = histo.size();
        int maxArea = 0;
        int maxH = 0;
        while (i < size) {
            if (aStack.empty() || histo[i] > histo[aStack.top()]) {
                aStack.push(i);
                ++i;
            } else {
                maxH = histo[aStack.top()];
                aStack.pop();
                maxArea = max(maxArea,
                              maxH * (aStack.empty()?i:i-aStack.top()-1));
            }
        }
        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix =
            { {'0', '0', '1', '1'}, {'0', '1', '1', '1'}, {'0', '1', '1', '1'} };
    Solution solution;
    cout << solution.maximalRectangle(matrix) << endl;
}
