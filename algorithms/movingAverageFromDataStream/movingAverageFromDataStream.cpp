/**
 *
 * Sean
 * 2016-11-27
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/
 *
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 *
 * For example,
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 *
 */
#include <queue>
using namespace std;

// sliding window with a queue.
class MovingAverage {
    queue<int> window;
    int maxLen;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): maxLen(size), sum(0) {
    }

    double next(int val) {
        if (window.size() == maxLen) {
            sum -= window.front();
            window.pop();
        }
        sum += val;
        window.push(val);
        return (double)sum/window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
