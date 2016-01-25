/**
 *
 * Sean
 * 2016-01-25
 *
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2. Please note that
 * your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int index1, index2;
            // create index
            for (int i=0; i<nums.size(); ++i) {
                supplementary[target-nums[i]] = i;
            }
            // find the answer
            for (int i=0; i<nums.size(); ++i) {
                auto it = supplementary.find(nums[i]);
                if (it != supplementary.end() && it->second!=i) {
                    index1 = i;
                    index2 = it->second;
                    break;
                }
            }
            return {index1+1, index2+1};
        }
    private:
        unordered_map<int, int> supplementary;
};

int main() {
    Solution s;
    vector<int> nums = {3,2,4};
    auto v = s.twoSum(nums, 6);
    for (int& i : v)
        cout << i << " ";
    cout << endl;
}
