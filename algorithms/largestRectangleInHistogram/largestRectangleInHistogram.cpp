/**
 *
 * Sean
 * 2016-05-20
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 *
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        // O(n^2): TLE
        int largestRectangleArea_tle(vector<int>& heights) {
            if (heights.empty()) return 0;
            int minH;
            int maxArea = 0;
            int size = heights.size();
            for (int i=0; i<size; ++i) {
                minH = heights[i];
                for (int j=i; j<size; ++j) {
                    minH = min(minH, heights[j]);
                    maxArea = max(maxArea, minH*(j-i+1));
                }
            }
            return maxArea;
        }

        // Reference from https://siddontang.gitbooks.io/leetcode-solution/content/array/largest_rectangle_in_histogram.html
        // O(n)
        int largestRectangleArea(vector<int>& heights) {
            heights.push_back(-1); // a sentinal
            stack<int> aStack; // store the monotone increasing sequence's indexes

            int size = heights.size();
            int i = 0;
            int maxArea = 0;
            int topIndex;
            while (i < size) {
                if (aStack.empty() || heights[i] > heights[aStack.top()]) {
                    aStack.push(i);
                    ++i;
                } else {
                    topIndex = aStack.top();
                    aStack.pop();
                    maxArea =
                        max(maxArea,
                            heights[topIndex]*(aStack.empty()?i:i-aStack.top()-1));
                }
            }
            return maxArea;
        }
};

int main() {
    /* vector<int> heights = { 2, 1, 5, 6, 2, 3 }; */
    vector<int> heights = { 0, 9 };
    Solution solution;
    cout << solution.largestRectangleArea(heights) << endl;
}
