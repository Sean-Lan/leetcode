/**
 *
 * Sean
 * 2016-08-24
 *
 * https://leetcode.com/problems/sliding-window-maximum/
 *
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * 1 [3  -1  -3] 5  3  6  7       3
 * 1  3 [-1  -3  5] 3  6  7       5
 * 1  3  -1 [-3  5  3] 6  7       5
 * 1  3  -1  -3 [5  3  6] 7       6
 * 1  3  -1  -3  5 [3  6  7]      7
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 *
 * Note:
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 *
 * Follow up:
 * Could you solve it in linear time?
 *
 * Hint:
 *
 * How about using a data structure such as deque (double-ended queue)?
 * The queue size need not be the same as the window’s size.
 * Remove redundant elements and the queue should store only elements that need to be considered.
 *
 */
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

// Monotonic decreasing queue.
class Solution {
    void insertIntoQueue(deque<int> &aQueue, vector<int> &nums, int i) {
        int value = nums[i];
        while (!aQueue.empty() && nums[aQueue.front()] < value) aQueue.pop_front();
        aQueue.push_front(i);
    }

    int getMaxValue(deque<int> &aQueue, vector<int> &nums, int i, int k) {
        while (!aQueue.empty() && i-aQueue.back() >= k) aQueue.pop_back();
        return nums[aQueue.back()];
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> aQueue;
        int i=0;
        for (; i<k-1; ++i)
            insertIntoQueue(aQueue, nums, i);
        int len = nums.size();
        for (; i<len; ++i) {
            insertIntoQueue(aQueue, nums, i);
            result.push_back(getMaxValue(aQueue, nums, i, k));
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums { 4, -2};
    int k = 2;
    vector<int> result = solution.maxSlidingWindow(nums, k);
    for (auto &i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}
