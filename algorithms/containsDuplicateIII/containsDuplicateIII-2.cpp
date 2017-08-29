/**
 *
 * Sean
 * 2017-08-29
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
 *
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// binary search with set
// O(n*logn)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        set<long long> window;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            long long num = nums[i];
            auto it = window.lower_bound(num-t);
            if (it != window.end() && abs(*it - num) <= t) return true;
            if (i >= k) window.erase(nums[i-k]);
            window.insert(num);
        }
        return false;
    }
};

int main() {
    return 0;
}
