/**
 *
 * Sean
 * 2016-06-16
 *
 * https://leetcode.com/problems/top-k-frequent-elements/
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts; // frequency count table
        // cumulative frequency count table,
        // i.e., table[i] means the number of numbers whose frequency is no less than i
        vector<int> cumulativeFrequencyTable(nums.size()+1, 0);
        for (auto &i : nums) {
            ++cumulativeFrequencyTable[++cnts[i]];
        }

        // find the largest mininum frequency Fmin so that the number of numbers with frequency larger than Fmin >= k.
        int minFrequency = nums.size();
        for (; minFrequency>0 && cumulativeFrequencyTable[minFrequency]<k; --minFrequency);

        // construct the final result
        vector<int> result(k);
        int cnt = 0;
        // first insert those numbers with frequency large than Fmin.
        for (auto &aPair : cnts) {
            if (aPair.second > minFrequency && cnt < k) {
                result[cnt++] = aPair.first;
            }
        }

        // in case numbers not enough, insert some numbers with frequency equals to Fmin.
        for (auto &aPair : cnts) {
            if (aPair.second == minFrequency && cnt < k) {
                result[cnt++] = aPair.first;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    int k = 2;
    vector<int> nums = {1,1,1,2,2,3};
    auto result = solution.topKFrequent(nums, k);
    for (auto &i : result)
        cout << i << " ";
    cout << endl;
}
