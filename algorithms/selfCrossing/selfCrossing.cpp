/**
 *
 * Sean
 * 2017-07-01
 *
 * https://leetcode.com/problems/self-crossing/#/description
 *
 * You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.
 *
 * Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
 *
 * Example 1:
 * Given x =
 * [2, 1, 1, 2]
 * ,
 * ┌───┐
 * │   │
 * └───┼──>
 *     │
 *
 * Return true (self crossing)
 *
 * Example 2:
 * Given x =
 * [1, 2, 3, 4]
 * ,
 * ┌──────┐
 * │      │
 * │
 * │
 * └────────────>
 *
 * Return false (not self crossing)
 *
 * Example 3:
 * Given x =
 * [1, 1, 1, 1]
 * ,
 * ┌───┐
 * │   │
 * └───┼>
 *
 * Return true (self crossing)
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // take advantage of the symmetry
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if (n < 4) return false;
        for (int i=3; i<n; ++i) {
            // x[i] crosses with x[i-3]
            if (x[i-3] >= x[i-1] && x[i] >= x[i-2]) return true;

            // x[i] crosses with x[i-4]
            if (i < 4) continue;
            if (x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true;

            // x[i] crosses with x[i-5]
            if (i < 5) continue;
            if (x[i] + x[i-4] >= x[i-2] && x[i-1] + x[i-5] >= x[i-3] && x[i-3] >= x[i-1] && x[i-2] >= x[i-4]) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
