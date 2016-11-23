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
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// reference to https://discuss.leetcode.com/topic/68896/java-solution-using-hashmap-with-detailed-explanation
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        vector<bool> mark(maxChoosableInteger);
        unordered_map<int, bool> cache;
        return helper(desiredTotal, mark, cache);
    }

    bool helper(int desiredTotal, vector<bool> &mark, unordered_map<int, bool> &cache) {
        if (desiredTotal <= 0) return false;
        int state = convert(mark);
        if (cache.count(state)) return cache[state];
        for (int i=1; i<=mark.size(); ++i) {
            if (!mark[i-1]) {
                mark[i-1] = true;
                if (!helper(desiredTotal-i, mark, cache)) {
                    mark[i-1] = false;
                    cache[state] = true;
                    return true;
                }
                mark[i-1] = false;
            }
        }
        cache[state] = false;
        return false;
    }

    int convert(vector<bool> &mark) {
        int res = 0;
        for (int i=0; i<mark.size(); ++i) {
            if (mark[i])
                res |= 1 << i;
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.canIWin(15, 104) << endl;
    return 0;
}
