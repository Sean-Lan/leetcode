/**
 *
 * Sean
 * 2016-11-14
 *
 * https://leetcode.com/problems/elimination-game/
 *
 * There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
 *
 * Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
 *
 * We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
 *
 * Find the last number that remains starting with a list of length n.
 *
 * Example:
 *
 * Input:
 * n = 9,
 * 1 2 3 4 5 6 7 8 9
 * 2 4 6 8
 * 2 6
 * 6
 *
 * Output:
 * 6
 *
 */
#include <iostream>
using namespace std;

// A typical variant of Josephus problem: https://en.wikipedia.org/wiki/Josephus_problem
// Here is a link to O(log(n)) solution of Josephus problem: https://maskray.me/blog/2013-08-27-josephus-problem-two-log-n-solutions
class Solution {
    int helper(int n, bool isRight) {
        if (n == 1) return 1;
        if (n%2 == 1) return 2*helper(n/2, !isRight);
        // now `n` is even
        if (isRight) return 2*helper(n/2, false);
        return 2*helper(n/2, true) -1;
    }
public:
    int lastRemaining(int n) {
        return helper(n, true);
    }
};
