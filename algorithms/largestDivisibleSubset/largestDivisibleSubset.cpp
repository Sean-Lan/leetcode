/**
 *
 * Sean
 * 2017-07-07
 *
 * https://leetcode.com/problems/largest-divisible-subset/#/description
 *
 * Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
 *
 * If there are multiple solutions, return any subset is fine.
 *
 * Example 1:
 *
 * nums: [1,2,3]
 *
 * Result: [1,2] (of course, [1,3] will also be ok)
 * Example 2:
 *
 * nums: [1,2,4,8]
 *
 * Result: [1,2,4,8]
 *
 */
#include <vector>
using namespace std;

// DP
// A new number can be added to an existing divisible set iff it can be divided by the largest number in the set
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        // pair<cnt, prev_index>
        // if we only need to calculate the number of the largest divisible set, the prev_index part is not needed.
        // here we use `prev_index` to reconstruct the largest divisible set.
        vector<pair<int, int>> dp(n);
        for (int i=0; i<n; ++i) {
            dp[i] = make_pair(1, -1);
        }

        sort(nums.begin(), nums.end());
        int maxIndex = 0;
        for (int i=1; i<n; ++i) {
            for (int j=i-1; j>=0; --j) {
                if (nums[i] % nums[j] == 0 && dp[j].first + 1 > dp[i].first) {
                    dp[i].first = dp[j].first+1;
                    dp[i].second = j;
                    if (dp[i].first > dp[maxIndex].first) maxIndex = i;
                }
            }
        }

        // construct the result
        vector<int> res;
        int idx = maxIndex;
        while (idx != -1) {
            res.push_back(nums[idx]);
            idx = dp[idx].second;
        }

        return res;
    }
};

int main() {
    return 0;
}
