/**
 *
 * Sean
 * 2016-10-26
 *
 * https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
 *
 * Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.
 *
 * Note: 1 ≤ k ≤ n ≤ 109.
 *
 * Example:
 *
 * Input:
 * n: 13   k: 2
 *
 * Output:
 * 10
 *
 * Explanation:
 * The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
 *
 */
#include <algorithm>
using namespace std;

// reference from https://discuss.leetcode.com/topic/64462/c-python-0ms-o-log-n-2-time-o-1-space-super-easy-solution-with-detailed-explanations
class Solution {
    typedef long long ll;
public:
    int findKthNumber(int n, int k) {
        int result = 1;
        --k;
        while (k) {
            int cnt = 0;
            for (ll first=result, last = first+1; first<=n; first*=10, last*=10) {
                cnt += min(n+1LL, last) - first;
            }
            if (k >= cnt) {
                k -= cnt;
                ++result;
            } else {
                result *= 10;
                --k;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
