#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/**
 * First sort the array in ascending order.
 * Let `sum` equal to nums[0] + nums[1] + nums[2] + .. + nums[n-1].
 * Let `curSum(i)` equal to nums[0] + nums[1] + nums[2] + .. + nums[i-1].
 * Let the final number be `k`, `k` must be in range (nums[0], nums[n-1]), inclusive.
 * The target is minimize { abs(k-nums[0]) + abs(k-nums[1]) + abs(k-nums[2]) + .. + abs(k-nums[n-1]) },
 * and define the equation as F, let `i` be the first array index so that `k` <= nums[i], then:
 *
 * F = k-nums[0] + k-nums[1] + .. + k-nums[i-1] + nums[i]-k + nums[i+1]-k + .. + nums[n-1]-k
 *   = i*k - (nums[0]+nums[1]+..+nums[i-1]) + (nums[i]+nums[i+1]+..+nums[n-1]) - (n-i)*k
 *   = 2*i*k - n*k + sum - 2*curSum(i)
 *
 * Now, we need iterate all `i` to obtain the result.
 *
 * The time complexity is O(n*log(n)) since we need sort the array first, the space complexity is O(1).
 */
class Solution {
    typedef long long ll;
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        ll curSum = 0;
        ll res = LLONG_MAX;
        int n = nums.size();
        ll k;
        for (int i=0; i<n; ++i) {
            k = nums[i];
            curSum += k;
            res = min(res, 2*(i+1)*k - n*k  + sum - 2*curSum);
        }
        return res;
    }
};

int main() {
    return 0;
}
