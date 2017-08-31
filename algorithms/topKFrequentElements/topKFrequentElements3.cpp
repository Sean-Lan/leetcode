/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
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
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // table[num] means the shown times of number num
        unordered_map<int, int> table;
        for (auto &num : nums) ++table[num];

        int n = nums.size();
        // reverted[i] contains the numbers which shows exactly i times
        vector<unordered_set<int>> reverted(n+1);
        for (auto &a_pair : table) {
            reverted[a_pair.second].insert(a_pair.first);
        }

        vector<int> res;

        for (int i=n; i>=1; --i) {
            if (!reverted[i].empty()) {
                for (auto &num : reverted[i]) {
                    if (res.size() >= k) break;
                    res.push_back(num);
                }
            }
            if (res.size() >= k) break;
        }
        return res;
    }
};

int main() {
    return 0;
}
