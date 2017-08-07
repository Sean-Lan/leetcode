/**
 *
 * Sean
 * 2017-08-07
 *
 * https://leetcode.com/problems/predict-the-winner/description/
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
 *
 * Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
 *
 * Example 1:
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2.
 * If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
 * So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
 * Hence, player 1 will never be the winner and you need to return False.
 *
 * Example 2:
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
 * Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 *
 * Note:
 * 1 <= length of the array <= 20.
 * Any scores in the given array are non-negative integers and will not exceed 10,000,000.
 * If the scores of both players are equal, then player 1 is still the winner.
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;

// DP, O(n^2)
// cache[start, end] means if a player plays at nums[start : end], how many points could he win
class Solution {
    typedef long long ll;
    ll p2l(int s, int e) {
        return ((ll)s << 32) | e;
    }
    int helper(vector<int> &nums, int start, int end) {
        if (start > end) return 0;
        if (start == end) return nums[start];
        ll key = p2l(start, end);
        if (cache.count(key)) return cache[key];
        int diff1 = nums[start] - helper(nums, start+1, end);
        int diff2 = nums[end] - helper(nums, start, end-1);
        return cache[key] = max(diff1, diff2);
    }
    unordered_map<ll, int> cache;
public:
    bool PredictTheWinner(vector<int>& nums) {
        cache.clear();
        int diff = helper(nums, 0, nums.size()-1);
        return diff >= 0;
    }
};

int main() {
    return 0;
}
