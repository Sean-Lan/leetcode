/**
 *
 * Sean
 * 2016-11-23
 *
 * https://leetcode.com/problems/number-of-boomerangs/
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 *
 */
#include <vector>
#include <unordered_map>
using namespace std;

// use a hash table to remember the number of points with the same distance to a certain point.
class Solution {
    typedef long long ll;
    typedef pair<int, int> pii;
    ll calDistance(pii &p1, pii &p2) {
        ll diff1 = (ll)p1.first - p2.first;
        ll diff2 = (ll)p1.second - p2.second;
        return diff1*diff1 + diff2*diff2;
    }
    public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n < 3) return 0;
        unordered_map<ll, int> counts;
        int res = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==j) continue;
                counts[calDistance(points[i], points[j])] ++;
            }
            for (auto &aPair : counts) {
                if (aPair.second >=2 ) {
                    res += aPair.second * (aPair.second - 1);
                }
            }
            counts.clear();
        }
        return res;
    }
};

int main() {
    return 0;
}
