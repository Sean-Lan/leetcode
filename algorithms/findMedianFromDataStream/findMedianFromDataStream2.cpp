/**
 *
 * Sean
 * 2017-09-06
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 *
 * Examples:
 * [2,3,4] , the median is 3
 *
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Design a data structure that supports the following two operations:
 *
 * void addNum(int num) - Add a integer number from the data stream to the data structure.
 * double findMedian() - Return the median of all elements so far.
 * For example:
 *
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3)
 * findMedian() -> 2
 *
 */
#include <queue>
#include <vector>
using namespace std;

// heap with pq
class MedianFinder {
    priority_queue<int, vector<int>> Q1;
    priority_queue<int, vector<int>, std::greater<int>> Q2;
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (Q1.empty()) {
            Q1.push(num);
            return;
        }
        if (num > Q1.top()) Q2.push(num);
        else Q1.push(num);

        if (Q1.size() > Q2.size() + 1) {
            Q2.push(Q1.top());
            Q1.pop();
        } else if (Q2.size() > Q1.size()) {
            Q1.push(Q2.top());
            Q2.pop();
        }
    }

    double findMedian() {
        int n = Q1.size() + Q2.size();
        return n & 1 ? Q1.top() : (Q1.top()+Q2.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main() {
    return 0;
}
