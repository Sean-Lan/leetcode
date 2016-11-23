/**
 *
 * Sean
 * 2016-11-23
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 *
 * Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
 *
 * You may assume the array's length is at most 10,000.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 2
 *
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one element):
 *
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 */
#include <vector>
#include <cstdlib>
using namespace std;

// O(n).
// Image the nums are sorted, and the final value is k, we start find k from the first element.
// If we increase k, the elements <= k will need move one step more, and the elements > k will need to move one step less.
// If there are more elements > k than elements <= k, we should increase k to minimize the moves.
// So we just increase k, until k reach the median of of the nums array. By then, the number of elements <= k equals to that of elements > k.
// (There is a slight different when the number of array is odd, but it's similar).
// If we keep increasing k after k reach the median of the array, more numbers >k than <= k, and more moves needed, so we should stop.
//
// The sort is not needed since we find the k is the median of the array, there is an average O(n) algorithm to find such k.
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        int total = 0;
        for (auto &i : nums)
            total += abs(i-median);
        return total;
    }
};
