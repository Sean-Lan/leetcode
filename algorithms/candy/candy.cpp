/**
 *
 * Sean
 * 2016-07-06
 *
 * https://leetcode.com/problems/candy/
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// Gready
class Solution {
    typedef vector<int> vi;
    public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int n = ratings.size();
        vi cnt(n, 1);
        cnt[0] = 1;
        for (int i=1; i<n; ++i) {
            if (ratings[i] > ratings[i-1])
                cnt[i] = cnt[i-1] + 1;
        }

        for (int i=n-1; i>0; --i) {
            if (ratings[i] < ratings[i-1])
                cnt[i-1] = max(cnt[i-1], cnt[i]+1);
        }

        int total = 0;
        for (int i=0; i<n; ++i)
            total += cnt[i];
        return total;
    }
};

int main() {
}
