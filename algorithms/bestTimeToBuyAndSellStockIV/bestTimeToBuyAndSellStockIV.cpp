/**
 *
 * Sean
 * 2016-06-07
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * DP.
 * buys[i] stores the max money left after buying stocks for i times and
 * sells[i] stores the max money left after selling stocks for i times.
 * We have:
 *         buys[j] = max(buys[j], sells[j-1]-prices[i]);
 *         sells[j] = max(sells[j], buys[j]+prices[i]);
 *
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        if (k >= n) {
            long long maxPro = 0, diff;
            for (int i=1; i<n; ++i) {
                diff = prices[i]-prices[i-1];
                maxPro += (diff>0)?diff:0;
            }
            return maxPro;
        }

        vector<long long> buys(k+1, INT_MIN);
        vector<long long> sells(k+1, 0);

        for (int i=0; i<n; ++i) {
            for (int j=1; j<=k; ++j) {
                buys[j] = max(buys[j], sells[j-1]-prices[i]);
                sells[j] = max(sells[j], buys[j]+prices[i]);
            }
        }
        return sells[k];
    }
};

int main() {}
