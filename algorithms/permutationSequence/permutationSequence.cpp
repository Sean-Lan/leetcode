/**
 *
 * Sean
 * 2016-03-22
 *
 * https://leetcode.com/problems/permutation-sequence/
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * 1."123"
 * 2."132"
 * 3."213"
 * 4."231"
 * 5."312"
 * 6."321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// use the ordinal number.
class Solution {
    public:
            string getPermutation(int n, int k) {
                // first perform the Cantor expansion.
                vector<int> coefficients;
                int curFactorial = 1;
                for (int i=1; i<n; ++i)
                    curFactorial *= i;
                --k;
                for (int i=n-1; i>0; --i) {
                    coefficients.push_back(k/curFactorial);
                    k %= curFactorial;
                    curFactorial/=i;
                }
                vector<bool> used(n);
                string result;
                int coefficient;
                for (int i=0; i<n-1; ++i) {
                    coefficient = coefficients[i];
                    int cnt = 0, j=0;
                    while (cnt<=coefficient) {
                        if (!used[j]) ++cnt;
                        ++j;
                    }
                    result.push_back('0'+j);
                    used[j-1] = true;
                }
                for (int i=0; i<n; ++i) {
                    if (used[i]) continue;
                    result.push_back('1'+i);
                    break;
                }
                return result;
            }
};

int main() {
    Solution solution;
    auto result = solution.getPermutation(5,8);
    cout << result << endl;
}
