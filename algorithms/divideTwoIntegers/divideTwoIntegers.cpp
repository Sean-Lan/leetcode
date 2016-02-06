#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        bool sign = true;
        long long longDivisor = divisor;
        long long longDividend = dividend;
        if (longDividend < 0) {
            sign = !sign;
            longDividend = -longDividend;
        }
        if (longDivisor < 0) {
            sign = !sign;
            longDivisor = -longDivisor;
        }

        long long result = 0;
        int current = 0;
        long long diff = 0;
        while (true) {
            current = 0;
            diff = longDividend - (longDivisor>>current);
            while (diff >= 0) {
                longDividend = diff;
                result += 1<<current;
                ++current;
                diff = longDividend - (longDivisor<<current);
            }
            if (diff < 0 && current==0) break;
        }
        if (!sign)
            result = -result;
        return result>INT_MAX?INT_MAX:result;
    }
};

int main() {
    Solution s;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(201, 10) << endl;
    int a = 1<<31;
    cout << a << endl;
    cout << s.divide(a, -1) << endl;
    cout << -2147483648/-1 << endl;
    cout << s.divide(-2147483648, 1) << endl;
    int b = -1;
    cout << "a: " << a<< " b: " << b << endl;
    cout << a/b << endl;
}
