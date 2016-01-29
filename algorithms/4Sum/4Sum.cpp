/**
 *
 * Sean
 * 2016-01-29
 *
 * https://leetcode.com/problems/4sum/
 * Given an array S of n integers, are there elements a, b, c, and d in S
 * such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i, j, k, l;
        int tmpSum;
        int num1, num2, num3, num4;
        for (i=0; i+3<nums.size();) {
            num1 = nums[i];
            for (j=i+1; j+2<nums.size();) {
                num2 = nums[j];
                k = j+1;
                l = nums.size()-1;
                while (k<l) {
                    num3 = nums[k];
                    num4 = nums[l];
                    tmpSum = num1 + num2 + num3 + num4;
                    if (tmpSum == target) {
                        result.push_back({num1, num2, num3, num4});
                        // skip same nums[k]
                        while (++k < l && nums[k]==nums[k-1]);
                        // skip same nums[l]
                        while (k < --l && nums[l]==nums[l+1]);
                    } else if (tmpSum < target) {
                        // skip same nums[k]
                        while (++k < l && nums[k]==nums[k-1]);
                    } else {
                        while (k < --l && nums[l]==nums[l+1]);
                    }
                }
                // skip same nums[j]
                while (++j+2<nums.size() && nums[j]==nums[j-1]);
            }
            // skip same nums[i]
            while (++i+3<nums.size() && nums[i]==nums[i-1]);
        }
        return result;
    }
};

void printResult(vector<vector<int>>& result) {
    for (auto& iv : result) {
        for (auto& i : iv) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    auto result = s.fourSum(nums, target);
    printResult(result);
}
