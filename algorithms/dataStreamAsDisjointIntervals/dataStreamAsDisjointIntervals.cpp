/**
 *
 * Sean
 * 2017-07-04
 *
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals/#/description
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
 *
 * For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
 *
 * [1, 1]
 * [1, 1], [3, 3]
 * [1, 1], [3, 3], [7, 7]
 * [1, 3], [7, 7]
 * [1, 3], [6, 7]
 *
 * Follow up:
 * What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
 *
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


struct Comparator {
    bool operator()(const Interval &i1, const Interval &i2) const {
        if (i1.start != i2.start) return i1.start < i2.start;
        return i2.end < i2.end;
    }
};

// store the intervals in a set, every time a new number is added, check the interval with start >= val,
// and the one before the interval to check whether a merge is needed.
// One thing worthy of noting is that we need to check whether val is included in the intervals.
class SummaryRanges {
    set<Interval, Comparator> aSet;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    // log(n)
    void addNum(int val) {
        auto interval = Interval(val, val);
        auto it = aSet.lower_bound(interval);
        bool contained = false;
        if (it != aSet.begin()) {
            auto prev_it = prev(it);
            if (val == prev_it->end+1) {
                interval.start = prev_it->start;
                aSet.erase(prev_it);
            } else if (val >= prev_it->start && val <= prev_it->end) {
                contained = true;
            }
        }
        if (it != aSet.end()) {
            if (val == it->start - 1) {
                interval.end = it->end;
                aSet.erase(it);
            } else if (val == it->start) {
                contained = true;
            }
        }
        if (!contained)
            aSet.insert(interval);
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto &interval : aSet) {
            res.push_back(interval);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int main() {
    return 0;
}
