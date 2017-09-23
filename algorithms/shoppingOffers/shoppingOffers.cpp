/**
 *
 * Sean
 * 2017-09-23
 *
 * https://leetcode.com/problems/shopping-offers/description/
 *
 * In LeetCode Store, there are some kinds of items to sell. Each item has a price.
 *
 * However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
 *
 * You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.
 *
 * Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.
 *
 * You could use any of special offers as many times as you want.
 *
 * Example 1:
 * Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
 * Output: 14
 * Explanation:
 * There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
 * In special offer 1, you can pay $5 for 3A and 0B
 * In special offer 2, you can pay $10 for 1A and 2B.
 * You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
 *
 * Example 2:
 * Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
 * Output: 11
 * Explanation:
 * The price of A is $2, and $3 for B, $4 for C.
 * You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
 * You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C.
 * You cannot add more items, though only $9 for 2A ,2B and 1C.
 *
 * Note:
 * There are at most 6 kinds of items, 100 special offers.
 * For each item, you need to buy at most 6 of them.
 * You are not allowed to buy more items than you want, even if that would lower the overall price.
 *
 */
#include <vector>
#include <unordered_map>
using namespace std;

// DP
// take price as another kind of special offer
struct VHash {
    size_t operator() (const vector<int> &vi) const {
        size_t res = 0;
        for (auto &i : vi) res = res*37 + i;
        return res;
    }
};
class Solution {
    unordered_map<vector<int>, int, VHash> cache;

    void useSp(vector<int> &cur, int &cost, vector<int> &sp) {
        int n = cur.size();
        for (int i=0; i<n; ++i) {
            cur[i] += sp[i];
        }
        cost += sp[n];
    }

    void unuseSp(vector<int> &cur, int &cost, vector<int> &sp, int cnt) {
        int n = cur.size();
        for (int i=0; i<n; ++i) {
            cur[i] -= sp[i]*cnt;
        }
        cost -= sp[n]*cnt;
    }

    void solve(int index, vector<int> &cur, int &cost, vector<vector<int>> &special, vector<int> &needs) {
        if (index == special.size()) return;
        vector<int> &sp = special[index];
        int cnt = INT_MAX;
        int n = cur.size();
        for (int i=0; i<n; ++i) {
            if (sp[i]) cnt = min(cnt, (needs[i]-cur[i])/sp[i]);
        }

        for (int i=0; i<cnt; ++i) {
            useSp(cur, cost, sp);
            if (!cache.count(cur) || cost < cache[cur]) {
                cache[cur] = cost;
                solve(index+1, cur, cost, special, needs);
            }
        }
        unuseSp(cur, cost, sp, cnt);
        solve(index+1, cur, cost, special, needs);
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        for (int i=0; i<n; ++i) {
            vector<int> sp(n+1, 0);
            sp[i] = 1;
            sp[n] = price[i];
            special.push_back(sp);
        }
        vector<int> cur(n, 0);
        int cost = 0;
        solve(0, cur, cost, special, needs);
        return cache[needs];
    }
};

int main() {
    return 0;
}
