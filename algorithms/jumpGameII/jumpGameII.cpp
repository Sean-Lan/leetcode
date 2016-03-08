/**
 *
 * Sean
 * 2016-03-08
 *
 * https://leetcode.com/problems/jump-game-ii/
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 *
 * Note:
 * You can assume that you can always reach the last index.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Greedy
class Solution {
    public:
        int jump(vector<int> &nums) {
            if (nums.size() <= 1) return 0;
            int maxRangeSofar = 0;
            int maxNext = 0;
            int lastIndex = nums.size()-1;
            int step = 0;
            int current = 0;
            while (maxRangeSofar < lastIndex) {
                ++step;
                for (; current<=maxRangeSofar; ++current)
                    maxNext = max(maxNext, current + nums[current]);
                maxRangeSofar = maxNext;
            }
            return step;
        }
};

int main() {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    cout << solution.jump(nums) << endl;

    nums = {2,1};
    cout << solution.jump(nums) << endl;
}
