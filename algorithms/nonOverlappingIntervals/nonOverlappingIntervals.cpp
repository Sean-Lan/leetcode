/**
 *
 * Sean
 * 2017-07-17
 *
 * https://leetcode.com/problems/non-overlapping-intervals/#/discuss
 *
 * Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 *
 * Note:
 * You may assume the interval's end point is always bigger than its start point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
 * Example 1:
 * Input: [ [1,2], [2,3], [3,4], [1,3] ]
 *
 * Output: 1
 *
 * Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 * Example 2:
 * Input: [ [1,2], [1,2], [1,2] ]
 *
 * Output: 2
 *
 * Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 * Example 3:
 * Input: [ [1,2], [2,3] ]
 *
 * Output: 0
 *
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 *
 */
#include <vector>
using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// O(n*logn)
// greedy
// sort according to the end
// the proof is to transform the optimal solution to the solution given by following greedy rule:
//  1. both sort according to the end
//  2. find the first different interval, and we can transform it into one following greedy rule (it must end earlier)
//  3. repeat step 2
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2) {
            if (i1.end != i2.end) return i1.end < i2.end;
            return i1.start < i2.start;
        });
        int cnt = 0;
        int curEnd = intervals.front().end;

        int n = intervals.size();
        for (int i=1; i<n; ++i) {
            if (curEnd > intervals[i].start) ++cnt;
            else curEnd = intervals[i].end;
        }
        return cnt;
    }
};

int main() {
    return 0;
}
