/**
 *
 * Sean
 * 2017-08-09
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 *
 * Example 1:
 * Input: tasks = ['A','A','A','B','B','B'], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 * Note:
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// greedy, O(time)
// in every cool down window with length n+1, put the task with the most cnt first
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};

        for (auto &c : tasks) {
            ++ cnt[c-'A'];
        }

        sort(cnt, cnt+26, std::greater<int>());

        int time = 0;
        int t;
        while (cnt[0]) {
            t = 0;
            while (t <= n) {
                if (t < 26 && cnt[t] > 0) -- cnt[t];
                ++t;
                ++time;
                if (cnt[0] == 0) break;
            }
            sort(cnt, cnt+26, std::greater<int>());
        }
        return time;
    }
};

int main() {
    return 0;
}
