/**
 *
 * Sean
 * 2016-05-05
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 * It doesn't matter what you leave beyond the new length.
 *
 */
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty())
                return 0;
            int cur = 0, next = 0;
            bool flag = false;
            while (++next < nums.size()) {
                if (nums[next] == nums[cur]) {
                    if (flag)
                        continue;
                    else
                        flag = true;
                } else {
                    flag = false;
                }
                nums[++cur] = nums[next];
            }
            return cur+1;
        }
};

int main() {
    vector <int> nums = {0,0,0,0,0};
    Solution solution;
    int size = solution.removeDuplicates(nums);
    for (int i=0; i<size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Size: " << size << endl;
}
