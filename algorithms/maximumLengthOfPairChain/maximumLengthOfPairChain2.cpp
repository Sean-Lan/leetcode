/**
 *
 * Sean
 * 2017-07-28
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/tabs/description
 *
 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
 *
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
 *
 * Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
 *
 * Example 1:
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * Note:
 * The number of given pairs will be in the range [1, 1000].
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// greedy, O(n*log(n))
class Solution {
    typedef vector<int> vi;
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vi &p1, const vi &p2) {
            if (p1[1] != p2[1]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        });

        int n = pairs.size();
        int len = 0;
        int i=0;
        while (i < n) {
            ++len;
            int curEnd = pairs[i][1];
            ++i;
            // find the next with start > curEnd
            while (i < n && pairs[i][0] <= curEnd) ++i;
        }
        return len;
    }
};

int main() {
    return 0;
}
