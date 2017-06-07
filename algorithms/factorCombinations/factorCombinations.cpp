/**
 *
 * Sean
 * 2017-06-07
 *
 * https://leetcode.com/problems/factor-combinations/#/description
 *
 * Numbers can be regarded as product of its factors. For example,
 * 
 * 8 = 2 x 2 x 2;
 *   = 2 x 4.
 * Write a function that takes an integer n and return all possible combinations of its factors.
 * 
 * Note: 
 * You may assume that n is always positive.
 * Factors should be greater than 1 and less than n.
 *
 * Examples: 
 * input: 1
 * output: 
 * []
 *
 * input: 37
 * output: 
 * []
 *
 * input: 12
 * output:
 * [
 *   [2, 6],
 *   [2, 2, 3],
 *   [3, 4]
 * ]
 *
 * input: 32
 * output:
 * [
 *   [2, 16],
 *   [2, 2, 8],
 *   [2, 2, 2, 4],
 *   [2, 2, 2, 2, 2],
 *   [2, 4, 4],
 *   [4, 8]
 * ]
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// use `minFactor` to keep `cur` in ascending order
class Solution {
    void sovle(int minFactor, int remainer, vector<int> &cur, vector<vector<int>> &res) {
        cur.push_back(remainer);
        res.push_back(cur);
        cur.pop_back();

        for (int i=minFactor; i*i<=remainer; ++i) {
            if (remainer%i == 0) {
                cur.push_back(i);
                sovle(i, remainer/i, cur, res);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> cur;
        vector<vector<int>> res;
        // `i*i <= n` makes sure that the remainer is no less than i
        for (int i=2; i*i <= n; ++i) {
            if (n%i == 0) {
                cur.push_back(i);
                sovle(i, n/i, cur, res);
                cur.pop_back();
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
