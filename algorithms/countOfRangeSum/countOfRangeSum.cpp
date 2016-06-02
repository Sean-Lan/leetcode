/**
 *
 * Sean
 * 2016-06-02
 *
 * https://leetcode.com/problems/count-of-range-sum/
 *
 * Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * A naive algorithm of O(n2) is trivial. You MUST do better than that.
 *
 * Example:
 * Given nums = [-2, 5, -1], lower = -2, upper = 2,
 * Return 3.
 * The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Divide and Conquer, reference to https://leetcode.com/discuss/79907/summary-divide-conquer-based-binary-indexed-based-solutions.
// Use binary search to find the right postiton of the prefix array.
// T(n) = 2T(n/2) + O(nlog(n))
// The final time complexity is O(n*log(n)^2)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty() || lower > upper) return 0;
        return helper(nums, 0, nums.size()-1, lower, upper);
    }

    int helper(vector<int> &nums, int start, int end, const int &lower, const int &upper) {
        int total = 0;
        if (start == end) {
            return nums[start] >= lower && nums[start] <= upper;
        }
        int mid = (start+end) >> 1;
        total += helper(nums, start, mid, lower, upper);
        total += helper(nums, mid+1, end, lower, upper);

        // calculate the prefix array of range[mid+1, end]
        vector<long long> prefix(end-mid, 0);
        prefix[0] = nums[mid+1];
        for (int i=1; i<prefix.size(); ++i) {
            prefix[i] = prefix[i-1]+nums[mid+1+i];
        }

        // calculate the suffix array of range[start, mid]
        vector<long long> suffix(mid-start+1, 0);
        int j = suffix.size()-1;
        suffix[j] = nums[start+j];
        --j;
        for (; j>=0; --j) {
            suffix[j] = suffix[j+1] + nums[start+j];
        }

        // sort the prefix array
        sort(prefix.begin(), prefix.end());

        for (int i=0; i<suffix.size(); ++i) {
            auto it1 = lower_bound(prefix.begin(), prefix.end(), lower-suffix[i]);
            auto it2 = upper_bound(prefix.begin(), prefix.end(), upper-suffix[i]);
            total += it2-it1;
        }
        return total;

    }
};




int main() {
    Solution solution;
    vector<int> nums {2147483647,-2147483648,-1,0};
    int lower = -1, upper = 0;
    cout << solution.countRangeSum(nums, lower, upper) << endl;
}
