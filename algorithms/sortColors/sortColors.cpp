/**
 *
 * Sean
 * 2016-04-21
 *
 * https://leetcode.com/problems/sort-colors/
 *
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 *
 */
#include <iostream>
#include <vector>
using namespace std;

void printNums(const vector<int> & nums) {
    for (auto &i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

/**
 *
 * Invariant:
 * 0,..,0,1,..,1,0/2, ..., 0/1, 2,..,2
 *        ^      ^         ^
 *        i      j         k
 *
 */
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            if (nums.empty()) return;
            int i = 0, j = 0, k = nums.size()-1;
            int val;
            while (i<nums.size() && nums[i]==0) ++i;
            j = i;
            while (j<nums.size() && nums[j]==1) ++j;
            while (j<=k) {
                while (k>=j && nums[k]==2) --k;
                if (k < j) break;
                if (nums[k] == 0) {
                    val = nums[i];
                    nums[i++] = 0;
                }
                if (j>=i) {
                    val = nums[j];
                    nums[j++] = 1;
                } else
                    j=i;
                if (j > k) break;
                nums[k] = val;
            }
        }
};

int main() {
    vector<int> nums = {1,0};
    Solution solution;
    solution.sortColors(nums);
    printNums(nums);
}
