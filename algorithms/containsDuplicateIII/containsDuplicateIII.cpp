/**
 *
 * Sean
 * 2016-05-31
 *
 * https://leetcode.com/problems/contains-duplicate-iii/
 *
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that 
 * the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 *
 */
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

// O(n) solution. Using buckets and sliding window.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if (size<2 || k<1 || t<0) return false;
        
        unordered_map<int, int> buckets;
        int bucketWidth = t+1;
        for (int i=0; i<size; ++i) {
            int bucketId = getBucketId(nums[i], bucketWidth);
            if (buckets.find(bucketId)!=buckets.end()) return true;
            
            // adjacent buckets
            if ((buckets.find(bucketId+1) != buckets.end() &&
                 abs((long long)buckets[bucketId+1]-nums[i])<=t) ||
                (buckets.find(bucketId-1) != buckets.end() &&
                 abs((long long)buckets[bucketId-1]-nums[i])<=t))
                return true;
            
            buckets[bucketId] = nums[i];
            
            if (i>=k) {
                buckets.erase(getBucketId(nums[i-k], bucketWidth));
            }
        }
        return false;
    }
private:
    int getBucketId(int num, int bucketWidth) {
        if (num < 0)
            return (num+1)/bucketWidth-1;
        return num/bucketWidth;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1,2147483647};
    int k=1, t= 2147483647;
    cout << solution.containsNearbyAlmostDuplicate(nums, k, t)<< endl;
}
