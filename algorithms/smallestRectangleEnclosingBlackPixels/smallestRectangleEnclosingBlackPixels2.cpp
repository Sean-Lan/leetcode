/**
 *
 * Sean
 * 2016-12-08
 *
 * https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
 *
 * An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
 *
 * For example, given the following image:
 *
 * [
 *   "0010",
 *   "0110",
 *   "0100"
 * ]
 * and x = 0, y = 2,
 * Return 6.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// binary search, O(m*log(n) + n*log(m))
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {

        int m = image.size(), n = image[0].size();
        auto colHasBlack = [&image, &m] (int col) {
            for (int i=0; i<m; ++i)
                if (image[i][col] == '1') return true;
            return false;
        };

        auto rowHasBlack = [&image, &n] (int row) {
            for (int i=0; i<n; ++i)
                if(image[row][i] == '1') return true;
            return false;
        };

        int minX, minY, maxX, maxY;

        // to left
        int start = 0, end = y, mid;
        while (start < end) {
            mid = start + (end-start)/2;
            if (colHasBlack(mid)) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        minX = start;

        // to right
        start = y, end = n-1;
        while (start < end) {
            // up round
            mid = start + (end-start+1)/2;
            if (colHasBlack(mid)) {
                start = mid;
            } else {
                end = mid-1;
            }
        }
        maxX = start;

        // to up
        start = 0, end = x;
        while (start < end) {
            mid = start + (end-start)/2;
            if (rowHasBlack(mid)) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        minY = start;

        // to down
        start = x, end = m-1;
        while (start < end) {
            // up round
            mid = start + (end-start+1)/2;
            if (rowHasBlack(mid)) {
                start = mid;
            } else {
                end = mid-1;
            }
        }
        maxY = start;

        return (maxX-minX+1) * (maxY-minY+1);
    }
};

int main() {
    Solution solution;
    vector<vector<char>> image = {{'0', '0', '0', '0', '1'}};
    cout << solution.minArea(image, 0, 4) << endl;
    return 0;
}
