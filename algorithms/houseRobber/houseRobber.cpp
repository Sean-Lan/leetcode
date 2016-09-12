/**
 *
 * Sean
 * 2016-09-12
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// DP
class Solution {
    public:
    int rob(vector<int>& nums) {
            if (nums.empty()) return 0;
            int n = nums.size();
            vector<int> dp_selected(n+1);
            vector<int> dp_unselected(n+1);
            dp_selected[1] = nums[0];
            for (int i=2; i<=n; ++i) {
                        dp_selected[i] = nums[i-1]+dp_unselected[i-1];
                        dp_unselected[i] = max(dp_selected[i-1], dp_unselected[i-1]);
                    }
            return max(dp_selected[n], dp_unselected[n]);
        }
};

int main() {
    return 0;
}
