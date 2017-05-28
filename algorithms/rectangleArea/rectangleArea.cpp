/**
 *
 * Sean
 * 2017-05-28
 *
 * https://leetcode.com/problems/rectangle-area/#/description
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *
 * Assume that the total area is never beyond the maximum possible value of int.
 *
 */
#include <iostream>
using namespace std;

class Solution {
    int getArea(int A, int B, int C, int D) {
        return (C-A) * (D-B);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int right = max(min(C, G), left);
        int bottom = max(B, F);
        int top = max(min(D, H), bottom);
        return getArea(A, B, C, D) + getArea(E, F, G, H)
                - getArea(left, bottom, right, top);
    }
};

int main() {
    return 0;
}

