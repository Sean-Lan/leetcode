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

// O(m*log(m) * n^2) time complexity and O(m) space complexity
// reference to the https://www.youtube.com/watch?v=yCQN096CwWM video for calculating max sub-matrix sum for a 2D matrix
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> sum(m);
        set<int> aSet;
        int cumSum;
        int res = INT_MIN;
        for (int i=0; i<n; ++i) {
            for (int l=0; l<m; ++l)
                sum[l] = 0;
            for (int j=i; j<n; ++j) {
                cumSum = 0;
                aSet.insert(0);
                for (int l=0; l<m; ++l) {
                    sum[l] += matrix[l][j];
                    cumSum += sum[l];
                    auto it = aSet.lower_bound(cumSum-k);
                    aSet.insert(cumSum);
                    if (it != aSet.end()) {
                        res = max(res, cumSum-*it);
                    }
                }
                aSet.clear();
            }
        }

        return res;
    }
};

int main() {
    return 0;
}
