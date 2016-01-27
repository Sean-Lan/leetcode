/**
 *
 * Sean
 * 2016-01-27
 *
 * https://leetcode.com/problems/3sum-closest/
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to
 * a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 */
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sum;
        int tmpDiff;
        sort(nums.begin(), nums.end());
        int i, j, k;
        for (i=0; i+2<nums.size(); ++i) {
            j=i+1;
            k=nums.size()-1;
            while(j<k) {
                sum = nums[i]+nums[j]+nums[k];
                tmpDiff = target-sum;
                if (tmpDiff == 0) return target;
                if (abs(tmpDiff) < abs(diff)) {
                    diff = tmpDiff;
                }
                if (tmpDiff > 0) {
                    ++j;
                    while(j<k && nums[j]==nums[j-1]) ++j;
                } else {
                    --k;
                    while(j<k && nums[k]==nums[k+1]) --k;
                }
            }
        }
        return target-diff;
    }
};

int main() {
    vector<int> nums = {0,2,1,-3};
    int target = 1;
    Solution s;
    cout << s.threeSumClosest(nums, target) << endl;
    return 0;
}
