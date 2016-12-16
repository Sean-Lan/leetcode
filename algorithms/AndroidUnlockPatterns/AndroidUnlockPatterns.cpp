/**
 *
 * Sean
 * 2016-12-16
 *
 * https://leetcode.com/problems/android-unlock-patterns/
 *
 * Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
 *
 * Rules for a valid pattern:
 *
 * 1. Each pattern must connect at least m keys and at most n keys.
 * 2. All the keys must be distinct.
 * 3. If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
 * 4. The order of keys used matters.
 *
 * | 1 | 2 | 3 |
 * | 4 | 5 | 6 |
 * | 7 | 8 | 9 |
 *
 * Invalid move: 4 - 1 - 3 - 6 
 * Line 1 - 3 passes through key 2 which had not been selected in the pattern.
 *
 * Invalid move: 4 - 1 - 9 - 2
 * Line 1 - 9 passes through key 5 which had not been selected in the pattern.
 *
 * Valid move: 2 - 4 - 1 - 3 - 6
 * Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
 *
 * Valid move: 6 - 5 - 4 - 1 - 9 - 2
 * Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
 *
 * Example:
 * Given m = 1, n = 1, return 9.
 *
 */
#include <vector>
using namespace std;

// DFS
class Solution {
    bool valid(int current, int next, const vector<bool> &mark) {
        if (mark[next]) return false;
        switch (current) {
            case 1:
                if (next == 3 && !mark[2] || 
                    next == 7 && !mark[4] ||
                    next == 9 && !mark[5]) return false;
                break;
            case 2:
                if (next == 8 && !mark[5]) return false;
                break;
            case 3:
                if (next == 1 && !mark[2] ||
                    next == 7 && !mark[5] ||
                    next == 9 && !mark[6]) return false;
                break;
            case 4:
                if (next == 6 && !mark[5]) return false;
                break;
            case 6:
                if (next == 4 && !mark[5]) return false;
                break;
            case 7:
                if (next == 1 && !mark[4] ||
                    next == 9 && !mark[8] ||
                    next == 3 && !mark[5]) return false;
                break;
            case 8:
                if (next == 2 && !mark[5]) return false;
                break;
            case 9:
                if (next == 3 && !mark[6] ||
                    next == 1 && !mark[5] ||
                    next == 7 && !mark[8]) return false;
        }
        return true;
    }
    int dfs(int current, int length, vector<bool> &mark, const int &m, const int &n) {
        int totalCnt = 0;
        if (length >= m && length <= n) ++totalCnt;
        if (length >= n) return totalCnt;
        for (int i=1; i<=9; ++i) {
            if (valid(current, i, mark)) {
                mark[i] = true;
                totalCnt += dfs(i, length+1, mark, m, n);
                mark[i] = false;
            }
        }
        return totalCnt;
    }
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> mark(10, false);
        int totalCnt = 0;
        for (int i=1; i<=9; ++i) {
            mark[i] = true;
            totalCnt += dfs(i, 1, mark, m, n);
            mark[i] = false;
        }
        return totalCnt;
    }
};

int main() {
    return 0;
}
