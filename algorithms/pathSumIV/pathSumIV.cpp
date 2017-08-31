/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/path-sum-iv/description/
 *
 * If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.
 *
 * For each integer in this list:
 * The hundreds digit represents the depth D of this node, 1 <= D <= 4.
 * The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
 * The units digit represents the value V of this node, 0 <= V <= 9.
 * Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.
 *
 * Example 1:
 * Input: [113, 215, 221]
 * Output: 12
 * Explanation:
 * The tree that the list represents is:
 *     3
 *    / \
 *   5   1
 *
 * The path sum is (3 + 5) + (3 + 1) = 12.
 * Example 2:
 * Input: [113, 221]
 * Output: 4
 * Explanation:
 * The tree that the list represents is:
 *     3
 *      \
 *       1
 *
 * The path sum is (3 + 1) = 4.
 *
 */
#include <vector>
using namespace std;

// O(n), anyway, the size of the problem can NOT be very large, consider the complexity is useless.
// we only need to count how many times a node is shown in different paths, which can be done in a level order from bottom to top:
// tranverse the nums in reverse order, if the node is a leaf node, the count is 1, else the count is the sum of the count of its two children.
class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> cnts(5, vector<int>(9, 0));
        int sum = 0;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            int cur = *it;
            int v = cur % 10; cur/=10;
            int p = cur %10; cur/= 10;
            int d = cur;
            if (d == 4 || (cnts[d+1][p*2-1] == 0 && cnts[d+1][p*2] == 0)) {
                cnts[d][p] = 1;
            } else {
                cnts[d][p] = cnts[d+1][p*2-1] + cnts[d+1][p*2];
            }
            sum += v * cnts[d][p];
        }
        return sum;
    }
};

int main() {
    return 0;
}
