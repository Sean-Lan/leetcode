/**
 *
 * Sean
 * 2016-10-27
 *
 * https://leetcode.com/problems/third-maximum-number/
 *
 * Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 *
 * Example 1:
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 * Example 2:
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * Example 3:
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// use set
class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            set<int> maxValues;
            for (auto &num : nums) {
                maxValues.insert(num);
                if (maxValues.size() > 3)
                    maxValues.erase(maxValues.begin());
            }
            return maxValues.size() == 3 ? *maxValues.begin() : *maxValues.rbegin();
        }
};

int main() {
    Solution solution;
    vector<int> nums = {2,3};
    cout << solution.thirdMax(nums) << endl;
    return 0;
}
