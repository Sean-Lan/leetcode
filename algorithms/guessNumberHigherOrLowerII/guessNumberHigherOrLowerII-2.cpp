/**
 *
 * Sean
 * 2016-11-24
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
 *
 * However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
 *
 * Example:
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = $21.
 * Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
 *
 */
#include <vector>
using namespace std;

// a recursive solution
class Solution {
    vector<vector<int>> cache;
    int helper(int start, int end) {
        if (start == end) return 0;
        if (start+1 == end) return start;
        if (cache[start][end] != -1) return cache[start][end];
        int cost = start + helper(start+1, end);
        for (int i=start+1; i<end; ++i) {
            cost = min(cost, i + max(helper(start, i-1), helper(i+1, end)));
        }
        cost = min(cost, end + helper(start, end-1));
        cache[start][end] = cost;
        return cost;
    }
public:
    int getMoneyAmount(int n) {
        cache = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return helper(1, n);
    }
};

int main() {
    return 0;
}
