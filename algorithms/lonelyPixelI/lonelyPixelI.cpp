/**
 *
 * Sean
 * 2017-03-17
 *
 * https://leetcode.com/problems/lonely-pixel-i/
 *
 * Given a picture consisting of black and white pixels, find the number of black lonely pixels.
 *
 * The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
 *
 * A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.
 *
 * Example:
 * Input: 
 * [['W', 'W', 'B'],
 *  ['W', 'B', 'W'],
 *  ['B', 'W', 'W']]
 *
 * Output: 3
 *  Explanation: All the three 'B's are black lonely pixels.
 *
 * Note:
 *  The range of width and height of the input 2D array is [1,500].
 */
#include <iostream>
#include <vector>
using namespace std;

// O (m * n)
// first count the black pixels in rows and columns separately
// then tranverse the while picture to get the number of the
// lonely picxels
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size();
        int n = picture[0].size();
        vector<int> rowCnts(m, 0);
        vector<int> colCnts(n, 0);
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (picture[i][j] == 'B') ++ rowCnts[i];
            }
        }
        
        for (int j=0; j<n; ++j) {
            for (int i=0; i<m; ++i) {
                if (picture[i][j] == 'B') ++colCnts[j];
            }
        }
        
        int cnt = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (picture[i][j] == 'B' && rowCnts[i] == 1 && colCnts[j] == 1)
                    ++ cnt;
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}
