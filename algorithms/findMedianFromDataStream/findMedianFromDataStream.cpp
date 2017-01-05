/**
 *
 * Sean
 * 2017-01-05
 *
 * https://leetcode.com/problems/find-median-from-data-stream/
 *
 * Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 *
 * Examples:
 *
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
 * add(1)
 * add(2)
 * findMedian() -> 1.5
 * add(3)
 * findMedian() -> 2
 *
 */
#include <set>
using namespace std;

// Heap. Use two multiset to store the the first ordered half and last ordered half of existing numbers
class MedianFinder {
    multiset<int, std::greater<int>> firstHalf;
    multiset<int> lastHalf;
public:
    MedianFinder() {}
    // Adds a number into the data structure.
    void addNum(int num) {
        if (firstHalf.empty()) {
            firstHalf.insert(num);
            return;
        }
        int firstHalfLargest = *firstHalf.begin();
        if (num <= firstHalfLargest) {
            firstHalf.insert(num);
            if (firstHalf.size() > lastHalf.size()+1) {
                firstHalf.erase(firstHalf.begin());
                lastHalf.insert(firstHalfLargest);
            }
        } else {
            lastHalf.insert(num);
            if (lastHalf.size() > firstHalf.size()) {
                firstHalf.insert(*lastHalf.begin());
                lastHalf.erase(lastHalf.begin());
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (firstHalf.size() > lastHalf.size()) return *firstHalf.begin();
        return ((double)*firstHalf.begin() + *lastHalf.begin())/2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
    return 0;
}
