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
// If so, merge them, otherwise, put the previous one into the result vector because it ends first
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if (i1.start != i2.start) return i1.start < i2.start;
            return i1.end < i2.end;
        });
        
        Interval prev = intervals[0];
        int n = intervals.size();
        vector<Interval> res;
        for (int i=1; i<n; ++i) {
            auto &cur = intervals[i];
            if (cur.start <= prev.end) { // overlap
                prev.end = max(prev.end, cur.end);
            } else {
                res.push_back(prev);
                prev.start = cur.start;
                prev.end = cur.end;
            }
        }
        res.push_back(prev);
        return res;
    }
};

int main() {
    return 0;
}
