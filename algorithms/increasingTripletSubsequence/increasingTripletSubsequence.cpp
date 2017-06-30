/**
 *
 * Sean
 * 2017-06-30
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/#/description
 *
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 *
 * Formally the function should:
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Your algorithm should run in O(n) time complexity and O(1) space complexity.
 *
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 *
 * Given [5, 4, 3, 2, 1],
 * return false.
 *
 */
#include <vector>
using namespace std;

// Greedy
// `aStack` stores current smallest increasing sequence
//
// One trick used here is that we can use the size of `aStack` to avoid endless edge cases
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> aStack;
        int smallest;

        int cur;
        for (int i=0; i<n; ++i) {
            cur = nums[i];
            if (aStack.empty()) {
                aStack.push_back(cur);
                smallest = cur;
            } else if (aStack.size() == 1) {
                if (cur < smallest) {
                    aStack[0] = cur;
                    smallest = cur;
                } else if (cur > smallest){
                    aStack.push_back(cur);
                }
            } else { // size == 2
                if (cur > aStack[1]) return true;
                if (cur > smallest) {
                    aStack[0] = smallest;
                    aStack[1] = cur;
                } else {
                    smallest = cur;
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
