/**
 *
 * Sean
 * 2016-12-30
 *
 * A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
 *
 * Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.
 *
 * If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.
 *
 * Note:
 *
 * The number of stones is ≥ 2 and is < 1,100.
 * Each stone's position will be a non-negative integer < 231.
 * The first stone's position is always 0.
 * Example 1:
 *
 * [0,1,3,5,6,8,12,17]
 *
 * There are a total of 8 stones.
 * The first stone at the 0th unit, second stone at the 1st unit,
 * third stone at the 3rd unit, and so on...
 * The last stone at the 17th unit.
 *
 * Return true. The frog can jump to the last stone by jumping
 * 1 unit to the 2nd stone, then 2 units to the 3rd stone, then
 * 2 units to the 4th stone, then 3 units to the 6th stone,
 * 4 units to the 7th stone, and 5 units to the 8th stone.
 * Example 2:
 *
 * [0,1,2,3,4,8,9,11]
 *
 * Return false. There is no way to jump to the last stone as
 * the gap between the 5th and 6th stone is too large.
 *
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    // dp[stones[i]] stores all the possible jump distance of stones[i]
    bool canCross(vector<int>& stones) {
        unordered_set<int> table;
        for (auto &i : stones) {
            table.insert(i);
        }
        if (table.count(1) == 0) return false;
        unordered_map<int, unordered_set<int>> dp;
        int n = stones.size();
        dp[1].insert(1);
        for (int i=1; i<n-1; ++i) {
            int cur = stones[i];
            auto &possible = dp[cur];
            for (auto &k : possible) {
                if (k-1>0 && table.count(cur+k-1)) dp[cur+k-1].insert(k-1);
                if (table.count(cur+k)) dp[cur+k].insert(k);
                if (table.count(cur+k+1)) dp[cur+k+1].insert(k+1);
            }
        }
        return !dp[stones[n-1]].empty();

    }
};

int main() {
    return 0;
}
