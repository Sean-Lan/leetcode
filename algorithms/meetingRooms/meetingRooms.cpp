/**
 *
 * Sean
 * 2017-09-05
 *
 * https://leetcode.com/problems/meeting-rooms/
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return false.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// sort and check.
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if (i1.start != i2.start) return i1.start < i2.start;
            return i1.end < i2.end;
        });

        int end = intervals[0].end;
        int n = intervals.size();
        for (int i=1; i<n; ++i) {
            auto interval = intervals[i];
            if (interval.start < end) return false;
            end = interval.end;
        }
        return true;
    }
};

int main() {
    return 0;
}
