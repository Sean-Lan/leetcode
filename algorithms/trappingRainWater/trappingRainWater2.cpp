/**
 *
 * Sean
 * 2016-03-05
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
#include <vector>
#include <algorithm>
using namespace std;

// O(N) solution.
class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.size()<3) return 0;
            int result = 0;
            auto maxIt = max_element(height.begin(), height.end());
            int currentMax = 0;
            int currentValue;
            for (auto it=height.begin(); it!=maxIt; ++it) {
                currentValue = *it;
                if (currentValue < currentMax)
                    result += currentMax-currentValue;
                else
                    currentMax = currentValue;
            }

            currentMax = 0;
            for (auto it=prev(height.end()); it!=maxIt; --it) {
                currentValue = *it;
                if (currentValue < currentMax)
                    result += currentMax-currentValue;
                else
                    currentMax = currentValue;
            }

            return result;
        }
};

int main() {
    /* vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; */
    /* vector<int> height = {5,4,1,2}; */
    vector<int> height = {5,2,1,2,1,5};
    Solution solution;
    cout << solution.trap(height) << endl;
}
