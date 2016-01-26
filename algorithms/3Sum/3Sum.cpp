/**
 *
 * Sean
 * 2016-01-26
 *
 * https://leetcode.com/problems/3sum/
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        /**
         * Use two pointer, j is from left and k is from right.
         * Careful to remove duplicates.
         */
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            if (nums.empty()) return result;
            sort(nums.begin(), nums.end());
            int i, j, k;
            int size = nums.size();
            int sum;
            for (i = 0; i<size; ++i) {
                while (i>0 && i<size && nums[i]==nums[i-1])
                    ++i;
                j = i+1;
                k = size-1;
                while (j<k) {
                    sum = nums[i]+nums[j]+nums[k];
                    if (sum == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        ++j;
                        while (j<k && nums[j] == nums[j-1])
                            ++j;
                        --k;
                        while (j<k && nums[k] == nums[k+1])
                            --k;
                    } else if (sum < 0) {
                        ++j;
                        while (j<k && nums[j] == nums[j-1])
                            ++j;
                    } else {
                        --k;
                        while (j<k && nums[k] == nums[k+1])
                            --k;
                    }
                }
            }
            return result;
        }
};

void printResult(const vector<vector<int>> &result) {
    for (auto ivec: result) {
        for (auto i : ivec) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    /* vector<int> nums = {-1,0,1,2,-1,-4}; */
    vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,
                        -5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,
                        1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,
                        2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,
                        4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,
                        -2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,
                        -1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,
                        8,6,-13,14,-2,-5,-11,1,3,-6};
    /* vector<int> nums = {}; */
    /* vector<int> nums = {-1, 0, 1}; */
    /* vector<int> nums = {1,1,-2}; */
    Solution s;
    auto result = s.threeSum(nums);
    printResult(result);
}
