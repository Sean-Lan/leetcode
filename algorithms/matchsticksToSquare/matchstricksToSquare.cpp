/**
 *
 * Sean
 * 2016-12-24
 *
 * https://leetcode.com/problems/matchsticks-to-square/
 *
 * Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
 *
 * Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
 *
 * Example 1:
 * Input: [1,1,2,2,2]
 * Output: true
 *
 * Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
 * Example 2:
 * Input: [3,3,3,3,4]
 * Output: false
 *
 * Explanation: You cannot find a way to form a square with all the matchsticks.
 *
 * Note:
 *
 * The length sum of the given matchsticks is in the range of 0 to 10^9.
 * The length of the given matchstick array will not exceed 15.
 *
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int sum;
bool dfs (int index, vector<int> &nums, vector<int> &cnts) {
    if (index == nums.size()) {
        int e = cnts[0];
        for (int i=1; i<4; ++i)
            if (e != cnts[i]) return false;
        return true;
    }
    for (int i=0; i<4; ++i) {
        // prune
        if (cnts[i]+nums[index] > sum/4) {
            continue;
        }
        cnts[i] += nums[index];
        if (dfs(index+1, nums, cnts)) return true;
        cnts[i] -= nums[index];
    }
    return false;
}


class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        // help to prune
        sum = accumulate(nums.begin(), nums.end(), 0);
        // choose longer matchsticks first to make invalid combinations exit faster
        sort(nums.begin(), nums.end(), std::greater<int>());
        if (sum % 4) return false;
        vector<int> cnts(4, 0);
        // put the first matchstick into the first edge to reduce the complexity
        cnts[0] = nums[0];
        return dfs(1, nums, cnts);
    }
};

int main() {
    return 0;
}
