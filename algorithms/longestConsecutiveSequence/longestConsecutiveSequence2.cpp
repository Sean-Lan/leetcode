/**
 *
 * Sean
 * 2017-09-26
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 */
#include <vector>
#include <unordered_set>
using namespace std;

// O(n)
// refer to https://discuss.leetcode.com/topic/15383/simple-o-n-with-explanation-just-walk-each-streak
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> table;
        for (auto &i : nums) table.insert(i);
        int maxLen = 0;
        for (auto &i: table) {
            if (table.count(i-1)) continue;
            int j = i+1;
            while (table.count(j)) ++j;
            maxLen = max(maxLen, j-i);
        }
        return maxLen;
    }
};

int main() {
    return 0;
}
