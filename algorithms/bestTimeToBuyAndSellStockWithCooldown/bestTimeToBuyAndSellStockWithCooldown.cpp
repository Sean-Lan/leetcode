/**
 *
 * Sean
 * 2016-06-07
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 *
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * Example:
 *
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
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

        // maxBuys[i] means the max money left with one stock in hand at i-th day.
        vector<long long> maxBuys(n);
        // maxSells[i] means the max money left without any stock in hand at i-th day.
        vector<long long> maxSells(n);

        long long buy, sell;
        for (int i=0; i<n; ++i) {
            buy = -prices[i] + (i>=2 ? maxSells[i-2] : 0);
            maxBuys[i] = (i==0 ? buy : max(maxBuys[i-1], buy));

            sell = (i==0)?0:maxBuys[i-1]+prices[i];
            maxSells[i] = (i==0 ? sell : max(maxSells[i-1], sell));
        }
        return maxSells[n-1];
    }
};

int main() {}
