#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int sum;

bool dfs (int index, vector<int> &nums, vector<int> &cnts) {
    if (index == nums.size()) {
        int e = cnts[0];
        for (int i=1; i<4; ++i)
            if (e != cnts[i]) return false;
        return true;
    }
    for (int i=0; i<4; ++i) {
        if (cnts[i]+nums[index] > sum/4) {
            continue;
        }
        cnts[i] += nums[index];
        if (dfs(index+1, nums, cnts)) return true;
        cnts[i] -= nums[index];
    }
    return false;
}


class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) return false;
        vector<int> cnts(4, 0);
        cnts[0] = nums[0];
        return dfs(1, nums, cnts);
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1,1,2,2,2 };
    // vector<int> nums = {10,6,5,5,5,3,3,3,2,2,2,2};
    // vector<int> nums =  { 7215807,6967211,5551998,6632092,2802439,821366,2465584,9415257,8663937,3976802,2850841,803069,2294462,8242205,9922998 };
    cout << solution.makesquare(nums) << endl;
    return 0;
}
