/**
 *
 * Sean
 * 2017-03-10
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
    int dfs(vector<int> &arr, vector<bool> &used, int cur) {
        int n = arr.size();
        if (cur == n + 1) {
            return 1;
        }
        int cnt = 0;
        for (int i=1; i<=n; ++i) {
            if (!used[i-1] && (i % cur == 0 || cur % i==0)) {
                used[i-1] = true;
                arr[cur-1] = i;
                cnt += dfs(arr, used, cur+1);
                used[i-1] = false;
            }
        }
        return cnt;
    }
public:
    int countArrangement(int N) {
        vector<int> arr(N);
        iota(arr.begin(), arr.end(), 1);
        vector<bool> used(N, false);
        return dfs(arr, used, 1);
    }
};
