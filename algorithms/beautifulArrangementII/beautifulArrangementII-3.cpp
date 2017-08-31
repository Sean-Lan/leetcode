/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/beautiful-arrangement-ii/description/
 *
 * Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
 * Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
 *
 * If there are multiple answers, print any of them.
 *
 * Example 1:
 * Input: n = 3, k = 1
 * Output: [1, 2, 3]
 * Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
 * Example 2:
 * Input: n = 3, k = 2
 * Output: [1, 3, 2]
 * Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
 * Note:
 * The n and k are in the range 1 <= k < n <= 10^4.
 *
 */
#include <vector>
using namespace std;

// 1, k+1, 2, k, 3, k-1 ...;
// The distance of this sequence is k, k-1, k-2, ..., 2, 1
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i=1, j = k+1;
        vector<int> nums;
        while (i<=j) {
            nums.push_back(i); ++i;
            if (i > j) break;
            nums.push_back(j); --j;
        }
        for (int i=k+2; i<=n; ++i) {
            nums.push_back(i);
        }
        return nums;
    }
};

int main() {
    return 0;
}
