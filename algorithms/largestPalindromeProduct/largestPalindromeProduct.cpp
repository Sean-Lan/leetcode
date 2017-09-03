/**
 *
 * Sean
 * 2017-09-03
 *
 * https://leetcode.com/problems/largest-palindrome-product/description/
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 *
 * Since the result could be very large, you should return the largest palindrome mod 1337.
 *
 * Example:
 *
 * Input: 2
 *
 * Output: 987
 *
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 *
 * Note:
 *
 * The range of n is [1,8].
 *
 */
#include <string>
#include <cstdlib>
using namespace std;

// disgusting
class Solution {
    typedef long long ll;
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        string a(n, '9');
        string b(n, '0');
        b[0] = '1';

        ll largest = atoll(a.c_str());
        ll smallest = atoll(b.c_str());
        ll MAX_N = largest * largest;

        auto isValid = [&](const string & number) {
            ll x = atoll(number.c_str());
            if (x > MAX_N) return false;
            for (ll i=largest; i>=smallest; --i) {
                if (x/i > largest || i*i < x) break;
                if (x % i) continue;
                ll j = x/i;
                if (j <= largest && j>=smallest) return true;
            }
            return false;
        };

        string number;
        bool found = false;
        ll firstHalf = atoll(to_string(MAX_N).substr(0, n).c_str());
        for (ll i=firstHalf; i>=smallest; --i) {
            string tmp = to_string(i);
            string reversed(tmp.rbegin(), tmp.rend());
            number = tmp + reversed;
            if (isValid(number)) {found = true; break;}
        }
        if (found)
            return atoll(number.c_str()) % 1337;

        for (ll i=largest/10; i>=smallest/10; --i) {
            string tmp = to_string(i);
            string reversed(tmp.rbegin(), tmp.rend());
            for (char c='9'; c>='0'; --c) {
                number = tmp + c + reversed;
                if (isValid(number)) {found = true; break;}
            }
            if (found) break;
        }
        return atoll(number.c_str()) % 1337;
    }
};

int main() {
    return 0;
}
