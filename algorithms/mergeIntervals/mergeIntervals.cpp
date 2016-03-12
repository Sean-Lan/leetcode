/**
 *
 * Sean
 * 2016-03-02
 *
 * https://leetcode.com/problems/merge-intervals/
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// First sort, then iterate over intervals, check whether currentInterval and preInterval overlap.
// If so, merge them, otherwise, put the smaller one into the result vector.
class Solution {
    private:
        bool overlap(const Interval &interval1, const Interval &interval2) {
            if (interval1.start>interval2.end || interval2.start>interval1.end)
                return false;
            return true;
        }

        Interval mergeInterval(const Interval &interval1, const Interval &interval2) {
            return {
                min(interval1.start, interval2.start),
                max(interval1.end, interval2.end)
            };
        }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(),
                [](Interval &interval1, Interval &interval2) {
                    return (interval1.start!=interval2.start)
                           ?(interval1.start<interval2.start)
                           :(interval1.end<interval2.end);
                });
        vector<Interval> res;
        Interval prevInterval = intervals[0];
        for (size_t i=1; i<intervals.size(); ++i) {
            Interval &currentInterval = intervals[i];
            if (overlap(prevInterval, currentInterval))
                prevInterval = mergeInterval(prevInterval, currentInterval);
            else {
                if (prevInterval.end < currentInterval.start) {
                    res.push_back(prevInterval);
                    prevInterval = currentInterval;
                } else
                    res.push_back(currentInterval);
            }
        }
        res.push_back(prevInterval);
        return res;
    }
};

int main() {
}
