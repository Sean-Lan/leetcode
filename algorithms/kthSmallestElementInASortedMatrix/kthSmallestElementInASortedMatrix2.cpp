/**
 *
 * Sean
 * 2016-12-14
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 *
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
 *
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 *
 * Example:
 *
 * matrix = [
 *    [ 1,  5,  9],
 *    [10, 11, 13],
 *    [12, 13, 15]
 * ],
 *
 * k = 8,
 *
 * return 13.
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// binary search reference to https://discuss.leetcode.com/topic/52948/share-my-thoughts-and-clean-java-code
// and https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c
// O(log(INT_MAX) * m * log(n))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int start = matrix[0][0], end = matrix[m-1][n-1], mid, cnt;
        while (start < end) {
            mid = start + (end-start)/2;
            cnt = 0;
            for (int i=0; i<m; ++i)
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid)
                       - matrix[i].begin();
            if (cnt < k) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,5,9}, {10,11,13}, {12,13,15}
    };
    Solution solution;
    cout << solution.kthSmallest(matrix, 8) << endl;
    return 0;
}
