/**
 *
 * Sean
 * 2016-11-01
 *
 * https://leetcode.com/problems/arranging-coins/
 *
 * You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
 *
 * Given n, find the total number of full staircase rows that can be formed.
 *
 * n is a non-negative integer and fits within the range of a 32-bit signed integer.
 *
 * Example 1:
 *
 * n = 5
 *
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 *
 * Because the 3rd row is incomplete, we return 2.
 * Example 2:
 *
 * n = 8
 *
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 *
 * Because the 4th row is incomplete, we return 3.
 *
 */
#include <iostream>
#include <functional>
using namespace std;

// binary search, refer to https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/.
class Solution {
    typedef long long ll;
    // find the last one where p holds false.
    int binarySearch(ll start, ll end, std::function<ll(ll)> p) {
        ll mid;
        while (start < end) {
            // round up instead of down
            mid = start + (end - start + 1)/2;
            if (p(mid)) {
                end = mid-1;
            } else {
                start = mid;
            }
        }
        return start;
    }

    public:
        int arrangeCoins(int n) {
            auto p = [&n] (ll x) {
                return x*(x+1)/2 > n;
            };
            return binarySearch(0, n, p);
        }
};

int main() {
    Solution solution;
    cout << solution.arrangeCoins(0) << endl;
    return 0;
}

