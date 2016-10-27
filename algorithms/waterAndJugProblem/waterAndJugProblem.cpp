/**
 *
 * Sean
 * 2016-10-27
 *
 * https://leetcode.com/problems/water-and-jug-problem/
 *
 * You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
 *
 * If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
 *
 * Operations allowed:
 *
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
 * Example 1: (From the famous "Die Hard" example)
 *
 * Input: x = 3, y = 5, z = 4
 * Output: True
 * Example 2:
 *
 * Input: x = 2, y = 6, z = 5
 * Output: False
 *
 */
#include <algorithm>
using namespace std;

// reference from https://discuss.leetcode.com/topic/49262/a-little-explanation-on-gcd-method-c-java-python
int gcd(int a, int b) {
    int aa = max(a, b);
    int bb = min(a, b);
    if (bb == 0) return aa;

    int r;
    while ((r = aa%bb)) {
        aa = bb;
        bb = r;
    }
    return bb;
}
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == 0) return z == 0 || y == z;
        if (y == 0) return z== 0 || x == z;
        return z <= (long long)x+y && z % gcd(x, y) == 0;
    }
};

int main() { return 0; }
