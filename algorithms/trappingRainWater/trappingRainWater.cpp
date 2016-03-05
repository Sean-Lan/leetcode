/**
 *
 * Sean
 * 2016-03-05
 *
 * https://leetcode.com/problems/trapping-rain-water/
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/**
 *
 * O(N^2 solution).
 * First find the maximum of the height array.
 * Then find the next maximum of the first and second part separately.
 *
 */
class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.size()<3) return 0;
            int result = 0;
            auto maxIt = max_element(height.begin(), height.end());
            auto p1 = maxIt;
            vector<int>::iterator p2;
            int minHeight;
            while (p1 != height.begin()) {
                p2 = max_element(height.begin(), p1);
                minHeight = *p2;
                result += accumulate(p2, p1, 0, [=](int init, int value) {
                        return init + minHeight-value;
                        });
                p1 = p2;
            }

            p1 = next(maxIt);
            while (p1 != height.end()) {
                p2 = max_element(p1, height.end());
                minHeight = *p2;
                result += accumulate(p1, p2, 0, [=](int init, int value) {
                        return init + minHeight-value;
                        });
                p1 = next(p2);
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
