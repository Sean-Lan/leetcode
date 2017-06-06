/**
 *
 * Sean
 * 2017-06-06
 *
 * https://leetcode.com/problems/flatten-2d-vector/#/description
 *
 * Implement an iterator to flatten a 2d vector.
 *
 * For example,
 * Given 2d vector =
 *
 * [
 *   [1,2],
 *   [3],
 *   [4,5,6]
 * ]
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
 *
 */
#include <vector>
using namespace std;

class Vector2D {
    vector<vector<int>>::iterator it1;
    vector<int>::iterator it2;
    vector<vector<int>>::iterator vec2dEnd;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vec2dEnd = vec2d.end();
        it1 = vec2d.begin();
        if (it1 != vec2dEnd) it2 = (*it1).begin();
    }

    int next() {
        if (hasNext()) {
            int val = *it2;
            ++it2;
            return val;
        }
        return INT_MIN;
    }

    bool hasNext() {
        if (it1 == vec2dEnd) return false;
        while (it2 == (*it1).end()) {
            ++it1;
            if (it1 == vec2dEnd) return false;
            it2 = (*it1).begin();
        }
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    return 0;
}
