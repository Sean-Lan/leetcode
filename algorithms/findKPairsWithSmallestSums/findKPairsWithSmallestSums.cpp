/**
 *
 * Sean
 * 2016-07-09
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 *
 * Define a pair (u,v) which consists of one element from the first array and one element from the second array.
 *
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 *
 * Example 1:
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 *
 * Return: [1,2],[1,4],[1,6]
 *
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * Example 2:
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 *
 * Return: [1,1],[1,1]
 *
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * Example 3:
 * Given nums1 = [1,2], nums2 = [3],  k = 3
 *
 * Return: [1,3],[2,3]
 *
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 *
 */
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
    typedef pair<int, int> ii;
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0 || n == 0) return {};
        vector<ii> result;

        // use a reference capure to save the code.
        auto cmp = [&nums1, &nums2] (const ii &a, const ii &b) {
            return nums1[a.first] + nums2[a.second] >
                nums1[b.first] + nums2[b.second];
        };

        // the queue sort the {i, j} pairs in ascending order according to
        // the sum of nums1[i]+nums2[j]
        priority_queue<ii, vector<ii>, decltype(cmp)> aQueue(cmp);
        aQueue.push({0, 0});

        while (k != 0 && !aQueue.empty()) {
            auto aPair = aQueue.top();
            aQueue.pop();
            result.push_back({nums1[aPair.first], nums2[aPair.second]});
            // {i, 0} is used, and we should put {i+1, 0} into the queue.
            if (aPair.first < m-1 && aPair.second == 0)
                aQueue.push({aPair.first+1, 0});
            // {i, j} is used, and we should put {i, j+1} into the queue.
            if (aPair.second < n-1)
                aQueue.push({aPair.first, aPair.second+1});
            --k;
        }

        return result;
    }
};

void printResult(vector<pair<int, int>> &result) {
    for (auto &aPair : result) {
        cout << aPair.first << " " << aPair.second << endl;
    }
}

int main() {
    Solution solution;
    vector<int> nums1 {1, 7, 11};
    vector<int> nums2 {2, 4, 6};
    int k = 3;
    auto result1 = solution.kSmallestPairs(nums1, nums2, k);
    printResult(result1);
    cout << endl;

    nums1 = {1, 1, 2};
    nums2 = {1, 2, 3};
    k = 2;
    auto result2 = solution.kSmallestPairs(nums1, nums2, k);
    printResult(result2);
    cout << endl;

    nums1 = {1, 2};
    nums2 = {3};
    k = 3;
    auto result3 = solution.kSmallestPairs(nums1, nums2, k);
    printResult(result3);

    return 0;
}
