/**
 *
 * Sean
 * 2017-09-28
 *
 * https://leetcode.com/problems/meeting-rooms-ii/description/
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return 2.
 *
 */
#include <vector>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Event {
    int ts;
    bool isStart;
    bool operator<(const Event &e) const {
        if (ts != e.ts) return ts < e.ts;
        return !isStart;
    }
};

// event based method
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<Event> events;

        for (auto &i : intervals) {
            events.push_back({i.start, true});
            events.push_back({i.end, false});
        }

        sort(events.begin(), events.end());

        int res = 0;
        int cur = 0;
        for (auto &e : events) {
            if (e.isStart) {
                res = max(res, ++cur);
            } else {
                --cur;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
