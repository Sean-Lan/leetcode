/**
 *
 * Sean
 * 2016-11-08
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
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    typedef long long ll;
public:
    // O(n^3)
    // dp[i][j] means the minimax cost of guess value with the range [i, j].
    int getMoneyAmount(int n) {
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, std::numeric_limits<ll>::max()));
        for (int i=1; i<=n; ++i) {
            dp[i][i] = 0;
        }
        for (int i=1; i<n; ++i) {
            dp[i][i+1] = i;
        }
        for (ll l=3; l<=n; ++l) {
            for (ll i=1; i+l-1<=n; ++i) {
                ll cost = std::numeric_limits<ll>::max();
                for (ll j=i; j<=i+l-1; ++j) {
                    if (j == i) {
                        cost = min(cost, j + dp[j+1][i+l-1]);
                        continue;
                    }
                    if (j == i+l-1) {
                        cost = min(cost, j + dp[i][j-1]);
                        continue;
                    }
                    cost = min(cost, j + max(dp[i][j-1], dp[j+1][i+l-1]));
                }
                dp[i][i+l-1] = cost;
            }
        }
        return dp[1][n];
    }
};

int main() { return 0; }
