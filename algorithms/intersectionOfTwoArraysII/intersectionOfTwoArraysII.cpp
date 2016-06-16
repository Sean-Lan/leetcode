/**
 *
 * Sean
 * 2016-06-16
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 *      Using two pointers, one points to nums1, another points to nums2.
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 *      Build hash table using nums1.
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 *      Build hash table using nums1, and scan nums2 for one pass.
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        for (auto &i : nums1) {
            ++map1[i];
        }
        vector<int> result;
        for (auto &i : nums2) {
            if (map1[i]) {
                result.push_back(i);
                --map1[i];
            }
        }
        return result;
    }
};

int main() {}
