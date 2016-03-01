/**
 *
 * Sean
 * 2016-03-01
 *
 * https://leetcode.com/problems/maximum-gap/
 *
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

/**
 *
 * Similar to bucket sort, first divide the numbers into different intervals and record the minimum and maximum
 * of each interval. A pass of calculate the difference between adjacent intervals' max and min can get the max
 * difference.
 *
 */
class Solution
{
    public:
        int maximumGap(vector<int>& nums) {
            if (nums.size() < 2)
                return 0;
            int len = nums.size();
            auto its = minmax_element(nums.begin(), nums.end());
            int minElement = *(its.first);
            int maxElement = *(its.second);
            if (minElement == maxElement)
                return 0;
            double intervalSize = (double)(maxElement-minElement)/len;
            vector<int> maxInInterval(len+1, std::numeric_limits<int>::min());
            vector<int> minInInterval(len+1, std::numeric_limits<int>::max());

            int index;
            for (auto &num : nums) {
                index = (num-minElement)/intervalSize;
                maxInInterval[index] = max(maxInInterval[index], num);
                minInInterval[index] = min(minInInterval[index], num);
            }

            int prevMax = maxInInterval[0];
            int maxGap = 0;
            for (int i=1; i<len+1; ++i) {
                if (minInInterval[i] != numeric_limits<int>::max())
                    maxGap = max(maxGap, minInInterval[i]-prevMax);
                if (maxInInterval[i] != numeric_limits<int>::min())
                    prevMax = maxInInterval[i];
            }
            return maxGap;
        }

        // naive sort and find.
        int maximumGap2(vector<int>& nums)
        {
            if (nums.size() < 2)
            {
                return 0;
            }

            sort(nums.begin(), nums.end());
            int maxGap = 0;
            for (int i = 1; i < nums.size(); i++)
            {
                maxGap = max(maxGap, nums[i] - nums[i - 1]);
            }
            return maxGap;
        }
};

int main() {
    vector<int> nums = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,
                        16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,
                        30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,
                        7926,22101,32406,21540,31799,3768,26679,21799,23740};
    Solution solution;
    cout << solution.maximumGap(nums) << endl;
    cout << solution.maximumGap2(nums) << endl;
}
