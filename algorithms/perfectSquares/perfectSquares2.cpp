/**
 *
 * Sean
 * 2017-06-15
 *
 * https://leetcode.com/problems/perfect-squares/#/description
 *
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS
// compared with DP, it will terminate faster
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i=1; i*i <= n; ++i) {
            squares.push_back(i*i);
        }

        queue<int> aQueue;
        aQueue.push(0);

        vector<bool> mark(n, false);
        int size;
        int cur;
        int next;
        int cnt = 0;

        while(!aQueue.empty()) {
            size = aQueue.size();
            ++ cnt;
            while (size--) {
                cur = aQueue.front();
                aQueue.pop();
                for (auto &i :squares) {
                    next = cur + i;
                    if (next < n) {
                        if (mark[next]) continue;
                        mark[next] = true;
                        aQueue.push(next);
                    } else if (next == n) {
                        return cnt;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}
