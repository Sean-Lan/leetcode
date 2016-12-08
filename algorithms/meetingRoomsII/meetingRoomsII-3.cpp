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

// curMeeting = cnt(time0) + cnt(time1) + ..
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> timeCnts;
        for (auto &interval : intervals) {
            ++ timeCnts[interval.start];
            -- timeCnts[interval.end];
        }
        int cnt = 0;
        int maxCnt = 0;
        for (auto &aPair : timeCnts) {
            cnt += aPair.second;
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};

int main() {
    Solution solution;
    vector<Interval> intervals = {Interval(5, 8), Interval(6, 8)};
    cout << solution.minMeetingRooms(intervals) << endl;
    return 0;
}
