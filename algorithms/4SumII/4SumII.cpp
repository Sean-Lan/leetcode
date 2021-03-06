/**
 *
 * Sean
 * 2016-12-24
 *
 * https://leetcode.com/problems/4sum-ii/
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
 *
 * Example:
 *
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Binary search. O(n*n*log(n))
class Solution {
    typedef long long ll;
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int n = A.size();
        ll total;
        int cnt = 0;
        vector<ll> cdSums;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cdSums.push_back((ll)C[i]+D[j]);
        sort(cdSums.begin(), cdSums.end());

        for (int i = 0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                total = (ll)A[i] + B[j];
                auto it1 = upper_bound(cdSums.begin(), cdSums.end(), -total);
                if (it1 == cdSums.begin()) break;
                auto it2 = lower_bound(cdSums.begin(), cdSums.end(), -total);
                cnt += it1 - it2;
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> A = {-1, -1};
    vector<int> B = {1, -1};
    vector<int> C = {-1, 1};
    vector<int> D = {-1, 1};
    Solution solution;
    cout << solution.fourSumCount(A, B, C, D) << endl;
    return 0;
}
