/**
 *
 * Sean
 * 2016-10-05
 *
 * https://leetcode.com/problems/trapping-rain-water/
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Using a monotonic inceasing stack
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<int> aStack;
        int i=0;
        int n = height.size();
        while (i < n) {
            if (aStack.empty() || height[i] < height[aStack.top()])
                aStack.push( i++ );
            else {
                int cur = aStack.top();
                aStack.pop();
                if (!aStack.empty()) {
                    result += (i - aStack.top() - 1) *
                        (min(height[i], height[aStack.top()])-height[cur]);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout << solution.trap(height) << endl;
}
