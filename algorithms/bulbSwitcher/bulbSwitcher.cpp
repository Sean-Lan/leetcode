/**
 *
 * Sean
 * 2017-06-28
 *
 * https://leetcode.com/problems/bulb-switcher/#/solutions
 *
 * There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.
 *
 * Example:
 *
 * Given n = 3.
 *
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off].
 *
 * So you should return 1, because there is only one bulb is on.
 *
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// if the i-th bulb is on after all the switches, i must be a square because all the factors comes in pair, e.g., i = 36, (1,36), (2,18), (3, 12), (4,9), (6,6)
// and any non equal factor pair will make the bulb triggered twice.
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main() {
    return 0;
}
