/**
 *
 * Sean
 * 2016-10-19
 *
 * https://leetcode.com/problems/arithmetic-slices/
 *
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 *
 * For example, these are arithmetic sequence:
 *
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * The following sequence is not arithmetic.
 *
 * 1, 1, 2, 5, 7
 *
 * A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 *
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 *
 * The function should return the number of arithmetic slices in the array A.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// O(n).
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> deltas;
        int n = A.size();
        for (int i=0; i<n-1; ++i) {
            deltas.push_back(A[i+1]-A[i]);
        }

        vector<int> lengths;
        int cnt = 1;
        for (int i=0; i<deltas.size()-1; ++i) {
            if (deltas[i+1] == deltas[i]) {
                ++cnt;
            } else {
                if (cnt >= 2)
                    lengths.push_back(cnt);
                cnt = 1;
            }
        }

        if (cnt >= 2)
            lengths.push_back(cnt);

        int result = 0;
        for (auto i : lengths) {
            result += i*(i-1)/2;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    cout << solution.numberOfArithmeticSlices(nums) << endl;
}
