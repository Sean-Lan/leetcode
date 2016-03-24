/**
 *
 * Sean
 * 2016-03-24
 *
 * https://leetcode.com/problems/rotate-array/
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 */
#include <vector>
#include <algorithm>
using namespace std;

// Reference to Programming Pearls.
// Three passes of reverse.
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if (nums.empty()) return;
            int len = nums.size();
            k %= len;
            if (k==0) return;
            auto it = nums.end()-k;
            std::reverse(nums.begin(), it);
            std::reverse(it, nums.end());
            std::reverse(nums.begin(), nums.end());
        }
};

int main() {}
