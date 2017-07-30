/**
 *
 * Sean
 * 2017-07-30
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
 *
 * Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
 *
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Note:
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 *
 */
#include <vector>
using namespace std;

// O(n)
// in-place sort
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            while (nums[i] != i+1) { // not in its right place
                // if it equals destination number, we found the two numbers
                if (nums[i] == nums[nums[i]-1]) {
                    res[0] = nums[i];
                    res[1] = i+1;
                    break;
                }
                // move it to its right place
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        return res;
    }
};

int main() {
    return 0;
}
