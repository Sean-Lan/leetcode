/**
 *
 * Sean
 * 2017-08-27
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
 *
 * Example 1:
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * Note:
 * The value k is positive and will always be smaller than the length of the sorted array.
 * Length of the given array is positive and will not exceed 10^4
 * Absolute value of elements in the array and x will not exceed 10^4
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// O(n*log(k))
// use a head to keep the top k elements
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [&](int a, int b) {
            int d1 = abs(a-x), d2 = abs(b-x);
            if (d1 != d2) return d1 < d2;
            return a < b;
        };

        priority_queue<int, vector<int>, decltype(cmp)> Q(cmp);

        for (auto & i : arr) {
            Q.push(i);
            if (Q.size() > k) Q.pop();
        }

        vector<int> res;
        while (!Q.empty()) { res.push_back(Q.top()); Q.pop(); }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
