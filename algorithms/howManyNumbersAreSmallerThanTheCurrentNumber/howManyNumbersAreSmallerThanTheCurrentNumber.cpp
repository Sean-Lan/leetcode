/**
 *
 * Sean
 * 2020-03-31
 *
 * https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 *
 * Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
 *
 * Return the answer in an array.
 *
 * Example 1:
 *
 * Input: nums = [8,1,2,2,3]
 * Output: [4,0,1,1,3]
 * Explanation:
 * For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
 * For nums[1]=1 does not exist any smaller number than it.
 * For nums[2]=2 there exist one smaller number than it (1).
 * For nums[3]=2 there exist one smaller number than it (1).
 * For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
 *
 * Example 2:
 *
 * Input: nums = [6,5,4,8]
 * Output: [2,1,0,3]
 * Example 3:
 *
 * Input: nums = [7,7,7,7]
 * Output: [0,0,0,0]
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // O (n * log n)
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n);
      vector<int> rank(101, -1);

      vector<int> numsSorted(nums);

      sort(numsSorted.begin(), numsSorted.end());

      for (int i=0; i<n; ++i) {
        if (rank[numsSorted[i]] == -1) rank[numsSorted[i]] = i;
      }

      for (int i =0; i<n; ++i) {
        res[i] = rank[nums[i]];
      }
      return res;
    }

    // O (n^2)
    vector<int> smallerNumbersThanCurrent_O_N2(vector<int>& nums) {
        int  n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) ++ res[i];
                else if (nums[i] < nums[j]) ++ res[j];
            }
        }
        return res;
    }
};

int main() {
  int xs[3] = {100};
  for (auto i : xs) {
    cout << i << endl;
  }
  return 0;
}
