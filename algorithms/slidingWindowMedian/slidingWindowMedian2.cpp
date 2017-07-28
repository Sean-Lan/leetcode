/**
 *
 * Sean
 * 2017-07-28
 *
 * https://leetcode.com/problems/sliding-window-median/tabs/description
 *
 * Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 *
 * Examples:
 * [2,3,4] , the median is 3
 *
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position                Median
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 *  1 [3  -1  -3] 5  3  6  7       -1
 *  1  3 [-1  -3  5] 3  6  7       -1
 *  1  3  -1 [-3  5  3] 6  7       3
 *  1  3  -1  -3 [5  3  6] 7       5
 *  1  3  -1  -3  5 [3  6  7]      6
 * Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 *
 */
#include <set>
#include <vector>
using namespace std;

// similar to the two maps solution, but with multiset it is more succinct.
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> lo, hi;
        int n = nums.size();
        vector<double> res;
        for (int i=0; i<n; ++i) {
            if (i >= k) {
                if (nums[i-k] <= *lo.rbegin()) {
                    lo.erase(lo.find(nums[i-k]));
                } else {
                    hi.erase(hi.find(nums[i-k]));
                }
            }

            lo.insert(nums[i]);
            // in case nums[i] is greater than the smallest of hi
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));

            // balance the size
            if (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }

            if (i >= k-1) {
                res.push_back(k&1 ? *lo.rbegin() : ((double)*lo.rbegin()+(double)*hi.begin())/2.0);
            }
        }

        return res;
    }
};

int main() {
    return 0;
}
