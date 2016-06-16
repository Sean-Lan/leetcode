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
    // get the frequency of every number.
    unordered_map<int, int> cnts;
    for (auto &i : nums) {
        ++cnts[i];
    }

    // using nth_element to partition the numbers into two parts,
    // the first part is the top k frequent elements.
    // the complexity is linear in distance(begin, kth) on average.
    vector<pair<int, int>> aVector(cnts.begin(), cnts.end());
    auto kth = aVector.begin() + k-1;
    nth_element(aVector.begin(), kth, aVector.end(), [](pair<int, int> &pair1, pair<int, int> &pair2){
        return pair1.second > pair2.second;
    });

    // construct the final result.
    vector<int> result;
    for (int i=0; i<k; ++i) {
        result.push_back(aVector[i].first);
    }
    return result;
}
};

int main() {}
