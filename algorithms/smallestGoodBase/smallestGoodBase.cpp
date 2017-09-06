/**
 *
 * Sean
 * 2017-09-06
 *
 * https://leetcode.com/problems/smallest-good-base/description/
 *
 * For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.
 *
 * Now given a string representing n, you should return the smallest good base of n in string format.
 *
 * Example 1:
 * Input: "13"
 * Output: "3"
 * Explanation: 13 base 3 is 111.
 *
 * Example 2:
 * Input: "4681"
 * Output: "8"
 * Explanation: 4681 base 8 is 11111.
 *
 * Example 3:
 * Input: "1000000000000000000"
 * Output: "999999999999999999"
 * Explanation: 1000000000000000000 base 999999999999999999 is 11.
 *
 * Note:
 * The range of n is [3, 10^18].
 * The string representing n is always valid and will not have leading zeros.
 *
 */
#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

// binary search, note the overflow
class Solution {
    typedef unsigned long long ll;
    ll solve(ll s, ll e, function<bool(ll)> p) {
        ll mid;
        while (s < e) {
            mid = s + (e-s)/2;
            if (p(mid)) {
                e = mid;
            } else {
                s = mid+1;
            }
        }
        return s;
    }
    ll f(ll k, ll i) {
        ll sum = 0, cur = 1;
        for (int j=0; j<=i; ++j) {
            sum += cur;
            cur *= k;
        }
        return sum;
    }
public:
    string smallestGoodBase(string n) {
        ll target = atoll(n.c_str());
        ll k = -1;
        for (int i=61; i>=1; --i) {
            ll top = i==1 ? target : (ll)(pow(target, 1.0/(i-1)) + 1);
            k = solve(2, top, [&](ll x) {
                return f(x, i) >= target;
            });
            if (f(k, i) == target) break;
        }
        return to_string(k);
    }
};

int main() {
    return 0;
}
