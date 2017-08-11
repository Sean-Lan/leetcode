/**
 *
 * Sean
 * 2017-08-11
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
 *
 * Example 1:
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
 * Example 2:
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 * Note: The length of the given binary array will not exceed 50,000.
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;

// let diff be the different of number of occurrence of 1 and 0
// if we meet 1, ++diff
// if we meet 0, --diff
// use a hash table to store the first shown index of diff, if the same diff shown twice,
// the sequence between the two indexes has equal number of 1 and 0
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        unordered_map<int, int> table;
        table[0] = -1;

        int diff = 0;
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i]) ++diff;
            else --diff;
            if (table.count(diff)) res = max(res, i - table[diff]);
            else table[diff] = i;
        }
        return res;
    }
};

int main() {
    return 0;
}
