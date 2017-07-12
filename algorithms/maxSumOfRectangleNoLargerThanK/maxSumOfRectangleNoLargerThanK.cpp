/**
 *
 * Sean
 * 2017-07-12
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/#/description
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
 *
 * Example:
 * Given matrix = [
 *   [1,  0, 1],
 *   [0, -2, 3]
 * ]
 *
 * k = 2
 * The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
 *
 * Note:
 * 1. The rectangle inside the matrix must have an area > 0.
 * 2. What if the number of rows is much larger than the number of columns?
 *
 */
#include <vector>
#include <iostream>
#include <set>
using namespace std;

// Just an extension for the problem:
// Find the largest sum of a continous subarray of an integer array that the sum is no greater than k
// => https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> cumSum(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                cumSum[i+1][j+1] = cumSum[i+1][j] + matrix[i][j];
            }
        }

        int res = INT_MIN;

        set<int> aSet;
        vector<int> arr(m+1, 0);
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                for (int l=0; l<m; ++l) {
                    arr[l+1] = arr[l] + cumSum[l+1][j+1] - cumSum[l+1][i];
                }

                aSet.clear();
                aSet.insert(0);
                for (int l=0; l<m; ++l) {
                    auto it = aSet.lower_bound(arr[l+1]-k);
                    aSet.insert(arr[l+1]);
                    if (it == aSet.end()) continue;
                    res = max(res, arr[l+1]-*it);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
