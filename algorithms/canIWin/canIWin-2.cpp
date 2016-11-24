/**
 *
 * Sean
 * 2016-11-24
 *
 * https://leetcode.com/problems/can-i-win/
 *
 * In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
 *
 * What if we change the game so that players cannot re-use integers?
 *
 * For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
 *
 * Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
 *
 * You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
 *
 * Example
 *
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 *
 * Output:
 * false
 *
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
 * Same with other integers chosen by the first player, the second player will always win.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// reference to https://discuss.leetcode.com/topic/68896/java-solution-using-hashmap-with-detailed-explanation/11
// use bit manipulation and vector<int> as cache to speed up.
class Solution {
    vector<int> cache;
    int state;
    int maxInt;
    public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        maxInt = maxChoosableInteger;
        state = 0;
        cache = vector<int> (1<<maxChoosableInteger, -1);
        return helper(desiredTotal);
    }

    bool helper(int desiredTotal) {
        if (desiredTotal <= 0) return false;
        if (cache[state] != -1) return cache[state];
        int mask = 1;
        for (int i=0; i<maxInt; ++i) {
            if (!(state & mask)) {
                state |= mask;
                if (!helper(desiredTotal-i-1)) {
                    state &= ~mask;
                    cache[state] = 1;
                    return true;
                }
                state &= ~mask;
            }
            mask <<= 1;
        }
        cache[state] = 0;
        return false;
    }

};



int main() {
    Solution solution;
    cout << solution.canIWin(10, 11) << endl;
    return 0;
}
