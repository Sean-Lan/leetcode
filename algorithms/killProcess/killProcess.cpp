/**
 *
 * Sean
 * 2017-08-01
 *
 * https://leetcode.com/problems/kill-process/description/
 *
 * Given n processes, each process has a unique PID (process id) and its PPID (parent process id).
 *
 * Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.
 *
 * We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.
 *
 * Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.
 *
 * Example 1:
 * Input:
 * pid =  [1, 3, 10, 5]
 * ppid = [3, 0, 5, 3]
 * kill = 5
 * Output: [5,10]
 * Explanation:
 *            3
 *          /   \
 *         1     5
 *              /
 *             10
 * Kill 5 will also kill 10.
 * Note:
 * The given kill id is guaranteed to be one of the given PIDs.
 * n >= 1.
 *
 */
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;

// O(n) time & space complexity
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        queue<int> Q;
        Q.push(kill);
        vector<int> killed;
        int n = pid.size();

        unordered_map<int, vector<int>> table;
        for (int i=0; i<n; ++i) {
            table[ppid[i]].push_back(pid[i]);
        }

        while (!Q.empty()) {
            auto cur = Q.front();
            killed.push_back(cur);
            Q.pop();
            auto &vi = table[cur];
            for (auto &i : vi) {
                Q.push(i);
            }
        }
        return killed;
    }
};

int main() {
    return 0;
}
