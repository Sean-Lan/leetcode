/**
 *
 * Sean
 * 2017-09-26
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 *
 */
#include <vector>
using namespace std;

// DP, O(n) time & space complexity
// calculate leftMax & rightMax separately
class Solution {
public:
int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 1) return 0;

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for (int i=1; i<n; ++i) {
                    leftMax[i] = max(leftMax[i-1], height[i]);
                }
        for (int i=n-2; i>=0; --i) {
                    rightMax[i] = max(rightMax[i+1], height[i]);
                }

        int total = 0;
        for (int i=0; i<n-1; ++i) {
                    int minH = min(leftMax[i], rightMax[i]);
                    if (minH > height[i]) total += minH - height[i];
                }

        return total;
    }
};

int main() {
    return 0;
}
