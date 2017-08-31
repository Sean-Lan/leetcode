/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/beautiful-arrangement/?tab=Description
 *
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:
 *
 * The number at the ith position is divisible by i.
 * i is divisible by the number at the ith position.
 * Now given N, how many beautiful arrangements can you construct?
 *
 * Example 1:
 * Input: 2
 * Output: 2
 *
 * Explanation:
 *
 * The first beautiful arrangement is [1, 2]:
 *
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 *
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 *
 * The second beautiful arrangement is [2, 1]:
 *
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 *
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 *
 * Note:
 * N is a positive integer and will not exceed 15.
 *
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// DFS with backtracking
class Solution {
    int sovle(int index, vector<bool> &mark, int N) {
        if (index == N+1) return 1;
        int cnt = 0;
        for (int i=1; i<=N; ++i) {
            if (!mark[i] && (i%index == 0 || index%i == 0)) {
                mark[i] = true;
                cnt += sovle(index+1, mark, N);
                mark[i] = false;
            }
        }
        return cnt;
    }
public:
    int countArrangement(int N) {
        vector<int> path;
        vector<bool> mark(N+1, false);
        return sovle(1, mark, N);
    }
};

int main() {
    return 0;
}
