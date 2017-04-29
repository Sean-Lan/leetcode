/**
 *
 * Sean
 * 2017-04-29
 *
 * https://leetcode.com/problems/3sum-smaller/#/description
 *
 * Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 *
 * For example, given nums = [-2, 0, 1, 3], and target = 2.
 *
 * Return 2. Because there are two triplets which sums are less than 2:
 *
 * [-2, 0, 1]
 * [-2, 0, 3]
 *
 * Follow up:
 * Could you solve it in O(n2) runtime?
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
// two pointers
// tricky part is how to calculate the count with certain j, k
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j, k;
        int cnt = 0;
        while (i < n-2) {
            j = i + 1;
            k = n - 1;
            int a = nums [i];
            while (j<k) {
                int b = nums[j];
                int c = nums[k];
                if (a+b+c < target) {
                    cnt += k-j;
                    ++j;
                } else {
                    --k;
                }
            }
            ++i;
        }
        return cnt;
    }
};

int main() {
    return 0;
}
