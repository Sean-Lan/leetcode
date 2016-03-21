/**
 *
 * Sean
 * 2016-03-21
 *
 * https://leetcode.com/problems/spiral-matrix/
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 *
*/
#include <iostream>
#include <vector>
using namespace std;

enum Direction {
    LEFT,
    DOWN,
    RIGHT,
    UP
};

/**
 *
 *       ------------> x
 *  minY | minX      maxX
 *       |
 *       |  (x, y)
 *       |
 *  maxY |
 *       Vy
 *
 */
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            if (matrix.empty() || matrix[0].empty()) return {};
            int x=0, y=0;
            int minX = 0, maxX = matrix[0].size()-1;
            int minY = 1, maxY = matrix.size()-1;
            Direction d = RIGHT;
            vector <int> result = { matrix[0][0] };
            while (canMove(x, y, minX, maxX, minY, maxY, d)) {
                makeMove(x, y, d);
                result.push_back(matrix[y][x]);
            }
            return result;
        }

    private:
        // can move check whether it can move to next position in current direction,
        // and change direction if necessary.
        inline bool canMove(const int &x, const int &y, int &minX, int &maxX,
                int &minY, int&maxY, Direction& d) {
            switch(d) {
                case LEFT:
                    if (x>minX)
                        return true;
                    d = UP;
                    ++minX;
                    return y>minY;
                case RIGHT:
                    if (x<maxX)
                        return true;
                    --maxX;
                    d = DOWN;
                    return y<maxY;
                case UP:
                    if (y>minY)
                        return true;
                    ++minY;
                    d = RIGHT;
                    return x<maxX;
                case DOWN:
                    if (y<maxY)
                        return true;
                    --maxY;
                    d = LEFT;
                    return x>minX;
            }
        }

        inline void makeMove(int &x, int &y, Direction &d) {
            switch (d) {
                case LEFT:
                    --x;
                    break;
                case RIGHT:
                    ++x;
                    break;
                case UP:
                    --y;
                    break;
                case DOWN:
                    ++y;
                    break;
            }
        }
};

int main() {
    vector<vector<int>> matrix =
        {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 }
        };
    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);
    for (auto &i : result)
        cout << i << " ";
    cout << endl;
}
