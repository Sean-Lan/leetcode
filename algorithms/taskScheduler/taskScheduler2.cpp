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
 * Note:
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 */
#include <vector>
#include <functional>
using namespace std;

// gready, O(n)
// 1. get the showing number of each time
// 2. sort them
// 3. arrange them like the following: (assuming A has the greatest showing number), and n = 4
//
// A _ _ _ _
// A _ _ _ _
// A _ _ _ _
// A
//
// Now there are 3*4 = 12 idle slots
// if all the slots are fitted into or more tasks than the number of slots then the total time equals to the size of task list, i.e:
//
// A B C D E M (appending M at the end of the row, and the cool down constraint is met)
// A B C D E
// A B C D F
// A B
//
// else the total time equals to the size of the task list plus the number of slots
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for (auto &c : tasks) {
            ++ cnt[c-'A'];
        }
        sort(cnt, cnt+26, std::greater<int>());

        int maxVal = cnt[0]-1;
        int idles = maxVal * n;

        for (int i=1; i<26; ++i) {
            idles -= min(maxVal, cnt[i]);
        }

        return idles <= 0 ? tasks.size() : tasks.size() + idles;
    }
};

int main() {
    return 0;
}
