/**
 *
 * Sean
 * 2016-12-08
 *
 * https://leetcode.com/problems/meeting-rooms-ii/
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return 2.
 *
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// greedy algo using priority_queue:
// check if the current conference overlaps with the first ended one,
// if so, one more room needed, otherwise we can arrange the conference
// right int the first ended conference's room.
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &in1, const Interval &in2) {
            return in1.start < in2.start;
        });
        priority_queue<int, vector<int>, greater<int>> aQueue;
        
        for (auto &interval : intervals) {
            if (!aQueue.empty() && aQueue.top() <= interval.start) 
                aQueue.pop();
            aQueue.push(interval.end);
        }
        return aQueue.size();
    }
};

int main() {
    Solution solution;
    vector<Interval> intervals = {Interval(5, 8), Interval(6, 8)};
    cout << solution.minMeetingRooms(intervals) << endl;
    return 0;
}
