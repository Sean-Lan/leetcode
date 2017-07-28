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
 *
 * Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 *
 */
#include <map>
#include <vector>
using namespace std;

// similar to https://leetcode.com/problems/find-median-from-data-stream/tabs/description
// maintain two heaps and preserve their size when insertion/removal happens
class Solution {
    map<int, int, std::greater<int>> firstHalf;
    map<int, int> secondHalf;
    int sz1 = 0;
    int sz2 = 0;

    // make sz2 <= sz1 <= sz2+1
    void adjust() {
        if (sz1 > sz2 + 1) {
            -- sz1;
            ++ sz2;
            auto it = firstHalf.begin();
            ++ secondHalf[it->first];
            if (--it->second == 0) {
                firstHalf.erase(it);
            }

        } else if (sz1 < sz2) {
            ++sz1;
            --sz2;
            auto it = secondHalf.begin();
            ++firstHalf[it->first];
            if (--it->second == 0) {
                secondHalf.erase(it);
            }
        }
    }

    void insert(int x) {
        if (sz1 == 0) {
            firstHalf[x] = 1;
            ++ sz1;
            return;
        }
        if (x <= firstHalf.begin()->first) {
            ++ firstHalf[x];
            ++ sz1;
        } else {
            ++ secondHalf[x];
            ++ sz2;
        }
        adjust();
    }

    void remove(int x) {
        if (firstHalf.count(x)) {
            -- sz1;
            if (--firstHalf[x] == 0) {
                firstHalf.erase(x);
            }
        } else {
            --sz2;
            if (--secondHalf[x] == 0) {
                secondHalf.erase(x);
            }
        }
        adjust();
    }

    double getMedian() {
        if (sz1 == sz2) {
            return ((double)firstHalf.begin()->first + (double)secondHalf.begin()->first) / 2.0;
        }
        return firstHalf.begin()->first;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        firstHalf.clear();
        secondHalf.clear();

        sz1 = 0;
        sz2 = 0;

        for (int i=0; i<k; ++i) {
            insert(nums[i]);
        }

        vector<double> result = {getMedian()};
        int n = nums.size();

        for (int i=k; i<n; ++i) {
            remove(nums[i-k]);
            insert(nums[i]);
            result.push_back(getMedian());
        }
        return result;
    }
};

int main() {
    return 0;
}
