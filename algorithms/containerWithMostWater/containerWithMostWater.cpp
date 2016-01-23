/**
 *
 * Sean
 * 2016-01-23
 *
 * https://leetcode.com/problems/container-with-most-water/
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a 
 * point at coordinate (i, ai). n vertical lines are drawn such that the 
 * two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
 * together with x-axis forms a container, such that the container contains 
 * the most water.
 *
 * Note: You may not slant the container.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size()-1;
            int maxArea = containerSize(height[left], height[right], right-left);
            int newArea;
            while (left < right) {
                if (height[left] < height[right])
                    ++left;
                else
                    --right;
                newArea = containerSize(height[left], height[right], right-left);
                maxArea = max(maxArea, newArea);
            }
            return maxArea;
        }

    private:
        int containerSize(int height1, int height2, int width) {
            return min(height1, height2) * width;
        }
        typedef vector<int>::const_iterator It;
};

int main() {
    Solution s;
    vector<int> height = {3,2,2,3};
    cout << s.maxArea(height) << endl;
}
