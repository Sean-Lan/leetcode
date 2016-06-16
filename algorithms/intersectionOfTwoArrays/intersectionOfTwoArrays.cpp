/**
 *
 * Sean
 * 2016-06-16
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for (auto &i : nums2) {
            if (set1.count(i))
                result.insert(i);
        }
        vector<int> ret(result.begin(), result.end());
        return ret;
    }
};

int main() {}
