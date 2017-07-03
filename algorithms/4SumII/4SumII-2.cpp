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
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

// hashtable, O(n*n)
class Solution {
    typedef long long ll;
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        ll total;
        int cnt = 0;
        unordered_map<ll, int> sumCnt;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                ++sumCnt[(ll)C[i]+D[j]];

        for (int i = 0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                total = (ll)A[i] + B[j];
                if (sumCnt.count(-total))
                    cnt += sumCnt[-total];
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
