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
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (auto &price : prices) {
            buy1 = max(buy1, -price);           // max money left after buying the first stock.
            sell1 = max(sell1, buy1+price);     // max money left after selling the first stock.
            buy2 = max(buy2, sell1-price);      // max money left after buying the second stock.
            sell2 = max(sell2, buy2+price);     // max money left after selling the second stock.
        }
        return sell2;
    }
};

int main() {}
