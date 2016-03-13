/**
 *
 * Sean
 * 2016-03-13
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n)
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.empty()) return 0;
            int diff = 0;
            int minSofar = prices[0];
            for (int i=1; i<prices.size(); ++i) {
                diff = max(diff, prices[i]-minSofar);
                minSofar = min(minSofar, prices[i]);
            }
            return diff;
        }
};

int main() {
}
