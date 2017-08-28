/**
 *
 * Sean
 * 2017-08-28
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
 *
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 *
 * Example 2:
 * Input: 3
 * Output: False
 *
 */
#include <iostream>
#include <unordered_set>
using namespace std;

// put the square into the hash table, and check whether c-square in it.
class Solution {
    typedef long long ll;
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> squares;
        ll square;
        for (ll i=0; (square=i*i) <= c; ++i) {
            squares.insert(square);
            if (squares.count(c - square)) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
