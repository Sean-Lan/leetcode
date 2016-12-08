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

// naive O(m*n)
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size();
        int m = image[0].size();
        int minX = INT_MAX, minY = INT_MAX, maxX = 0, maxY =0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (image[i][j] == '1') {
                    minX = min(minX, i);
                    minY = min(minY, j);
                    maxX = max(maxX, i);
                    maxY = max(maxY, j);
                }
            }
        }
        return (maxX-minX+1) * (maxY-minY+1);
    }
};

int main() {
    return 0;
}
