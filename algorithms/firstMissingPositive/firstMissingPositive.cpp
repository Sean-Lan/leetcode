/**
 *
 * Sean
 * 2016-02-27
 * https://leetcode.com/problems/first-missing-positive/
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Move the number to the right place in nums.
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int i;
            int source, target;
            for (i=0; i<nums.size(); ++i) {
                source = nums[i];
                while (source>0 && source<=nums.size()) {
                    target = nums[source-1];
                    nums[source-1] = source;
                    if (source == target) break;
                    source = target;
                }
            }

            for (i=0; i<nums.size(); ++i) {
                if (nums[i]!=i+1)
                    break;
            }
            return i+1;
        }
};

int main() {
    vector<int> nums = {1,2,0};
    Solution solution;
    cout << solution.firstMissingPositive(nums) << endl;

    nums = {3,4,-1,1};
    cout << solution.firstMissingPositive(nums) << endl;

    nums = {4,1,2,3};
    cout << solution.firstMissingPositive(nums) << endl;
}
