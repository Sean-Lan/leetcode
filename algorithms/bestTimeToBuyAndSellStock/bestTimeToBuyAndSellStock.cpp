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

// Divide and conquer, O(n*log(n))
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.empty()) return 0;
            return maxProfit(prices, 0, prices.size()-1);
        }
    private:
        int maxProfit(vector<int> &prices, int beg, int end) {
            if (beg >= end) return 0;
            if (beg+1 == end) return max(0, prices[end]-prices[beg]);

            int mid = (beg+end)>>1;
            int minElement = *min_element(prices.begin()+beg, prices.begin()+mid+1);
            int maxElement = *max_element(prices.begin()+mid+1, prices.begin()+end+1);
            return max(max(max(0, maxElement-minElement),
                        maxProfit(prices, beg, mid)),
                    maxProfit(prices, mid+1, end));
        }
};

int main() {
}
