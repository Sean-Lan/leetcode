/**
 *
 * Sean
 * 2016-03-21
 *
 * https://leetcode.com/problems/spiral-matrix-ii/
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

/**
 *     minX       maxX
 * minY -----------> x
 *      |
 *      |   (x, y)
 *      |
 *      |
 * maxY V y
 */
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            if (n==0) return {};
            vector<vector<int>> result(n, vector<int>(n));
            result[0][0] = 1;
            int x = 0, y = 0;
            int minX = 0, minY = 0;
            int maxX = n-1, maxY = n-1;
            Direction d = RIGHT;
            int cur = 1;
            while (canMove(x, y, minX, maxX, minY, maxY, d)) {
                makeMove(x, y, d);
                result[y][x] = ++cur;
            }
            return result;
        }

    private:
        bool canMove(const int &x, const int &y, int &minX, int &maxX,
                int &minY, int &maxY, Direction &d) {
            switch (d) {
                case UP:
                    if (y>minY) return true;
                    d = RIGHT;
                    ++minX;
                    return x<maxX;
                case RIGHT:
                    if (x<maxX) return true;
                    d = DOWN;
                    ++minY;
                    return y<maxY;
                case DOWN:
                    if (y<maxY) return true;
                    d = LEFT;
                    --maxX;
                    return x>minX;
                case LEFT:
                    if (x>minX) return true;
                    d = UP;
                    --maxY;
                    return y>minY;
            }
        }

        void makeMove(int &x, int &y, Direction &d) {
            switch (d) {
                case UP:
                    --y; break;
                case DOWN:
                    ++y; break;
                case LEFT:
                    --x; break;
                case RIGHT:
                    ++x; break;
            }
        }
};

void printResult(const vector<vector<int>> &result) {
    for (auto &iv : result) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    Solution solution;
    auto result = solution.generateMatrix(5);
    printResult(result);
}
