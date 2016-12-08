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
#include <map>
#include <iostream>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const Interval &in1, const Interval &in2) {
            if (in1.start != in2.start) return in1.start < in2.start;
            return in1.end < in2.end;
        });

        map<int, int> rooms; // { end_time, cnt } pairs, sort by end_time in ascending order
        rooms[intervals[0].end] = 1;
        for (int i=1; i<intervals.size(); ++i) {
            auto &firstEndedRoom = *rooms.begin();
            if (firstEndedRoom.first <= intervals[i].start) {
                -- firstEndedRoom.second;
                if (firstEndedRoom.second == 0) rooms.erase(rooms.begin());
            }
            ++ rooms[intervals[i].end];
        }
        int cnt = 0;
        for (auto &aPair : rooms)
            cnt += aPair.second;
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<Interval> intervals = {Interval(5, 8), Interval(6, 8)};
    cout << solution.minMeetingRooms(intervals) << endl;
    return 0;
}
