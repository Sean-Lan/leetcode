/**
 *
 * Sean
 * 2016-06-06
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> fromFirstDay(n, 0);
        vector<int> toLastDay(n, 0);
        int minSofar = prices[0];
        for (int i=1; i<n; ++i) {
            minSofar = min(minSofar, prices[i]);
            fromFirstDay[i] = max(fromFirstDay[i-1], prices[i]-minSofar);
        }

        int maxSofar = prices[n-1];
        for (int j=n-2; j>=0; --j) {
            maxSofar = max(maxSofar, prices[j]);
            toLastDay[j] = max(toLastDay[j+1], maxSofar-prices[j]);
        }

        int profit = 0;
        for (int i=0; i<n; ++i)
            profit = max(profit, fromFirstDay[i]+toLastDay[i]);
        return profit;
    }
};

int main() {}
