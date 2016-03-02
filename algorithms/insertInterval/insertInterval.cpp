/**
 *
 * Sean
 * 2016-03-02
 *
 * https://leetcode.com/problems/insert-interval/
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 */
#include <iostream>
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


/**
 *
 * Use a bool flag to mark whether the newInterval has been put into result set,
 * If not, check whether the newInterval overlap with the interals, and merge them if
 * nessesary.
 *
 */
class Solution {
private:
    inline bool overlap(const Interval &interval1, const Interval &interval2) {
        if (interval1.end < interval2.start || interval1.start > interval2.end)
            return false;
        return true;
    }

    inline void mergeInterval(Interval &sourceInterval, const Interval &newInterval) {
        sourceInterval.start = min(sourceInterval.start, newInterval.start);
        sourceInterval.end = max(sourceInterval.end, newInterval.end);
    }

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool flag = false;
        for (auto &interval : intervals) {
            if (!flag && overlap(newInterval, interval)) {
                mergeInterval(newInterval, interval);
            } else {
                if (!flag && newInterval.end < interval.start) {
                    flag = true;
                    res.push_back(newInterval);
                }
                res.push_back(interval);
            }
        }
        if (!flag)
            res.push_back(newInterval);
        return res;
    }
};

void printIntervals(vector<Interval> &intervals) {
    for (auto &interval : intervals)
        cout << "[" << interval.start << ","
            << interval.end << "]" << endl;
}

int main() {
    /* vector<Interval> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}}; */
    vector<Interval> intervals = {{2,5},{6,7},{8,9}};
    cout << "before:" << endl;
    printIntervals(intervals);
    cout << endl;
    cout << "after:" << endl;

    Solution solution;
    /* auto res = solution.insert(intervals, {4,9}); */
    auto res = solution.insert(intervals, {0,1});
    printIntervals(res);
    
    return 0;
}
