/**
 *
 * Sean
 * 2017-02-15
 *
 * https://leetcode.com/problems/next-greater-element-i/
 *
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 * 
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
 * 
 * Example 1:
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 *     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 *     For number 1 in the first array, the next greater number for it in the second array is 3.
 *     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 *
 * Example 2:
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 *     For number 2 in the first array, the next greater number for it in the second array is 3.
 *     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 *
 * Note:
 * All elements in nums1 and nums2 are unique.
 * The length of both nums1 and nums2 would not exceed 1000.
 *
 */
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// O(m+n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> aStack;
        unordered_map<int, int> table;
        // elements in `aStack` is monotonically decreasing
        for (auto i : nums) {
            while (!aStack.empty() && aStack.top() < i) {
                table[aStack.top()] = i;
                aStack.pop();
            }
            aStack.push(i);
        }
        while (!aStack.empty()) {
            table[aStack.top()] = -1;
            aStack.pop();
        }
        
        vector<int> res;
        for (auto i : findNums) {
            res.push_back(table[i]);
        }
        return res;
    }
};
