/*
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
      int source, target;
      int n = nums.size();

      for (int i=0; i<n; ++i) {
        source = nums[i];
        while (source > 0 && source <= n) {
          target = nums[source-1];
          if (target == source) break;
          nums[source-1] = source;
          source = target;
        }
      }

      for (int i=0; i<n; ++i) {
        if (nums[i] != i+1) return i+1;
      }
      return n+1;
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
