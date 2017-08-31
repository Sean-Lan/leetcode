/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
 *
 * Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?
 *
 * Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.
 *
 * Example 1:
 * Input: m = 3, n = 3, k = 5
 * Output:
 * Explanation:
 * The Multiplication Table:
 *
 * 1  2  3
 * 2  4  6
 * 3  6  9
 *
 * The 5-th smallest number is 3 (1, 2, 2, 3, 3).
 *
 * Example 2:
 * Input: m = 2, n = 3, k = 6
 * Output:
 * Explanation:
 * The Multiplication Table:
 * 1  2  3
 * 2  4  6
 *
 * The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
 * Note:
 * The m and n will be in the range [1, 30000].
 * The k will be in the range [1, m * n]
 *
 */
#include <iostream>
using namespace std;

// very similar to https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
// Binary Search with value range
// Note that to avoid infinite loop, you need to check the number of numbers which <= mid instead < mid
// the range should always *DECREASE*
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int s = 1, e = m*n, mid, cnt;
        while (s < e) {
            mid = s + (e-s)/2;
            cnt = 0;
            for (int i=1; i<=m; ++i) {
                cnt += min(n, mid/i);
            }
            if (cnt < k) s = mid+1;
            else e = mid;
        }
        return s;
    }
};

int main() {
    return 0;
}
