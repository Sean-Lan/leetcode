/**
 *
 * Sean
 * 2016-03-28
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 *
 */
#include <iostream>
using namespace std;

// Binary search
class Solution {
    public:
        int mySqrt(int x) {
            long long start = 0;
            long long end = x;
            long long mid;
            long long square;
            while (true) {
                mid = (start+end)>>1;
                square = mid*mid;
                if (square<=x && (square+(mid<<1)+1)>x)
                    break;
                if (square>x)
                    end = mid-1;
                else
                    start = mid+1;
            }
            return mid;
        }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(0) << endl;
    cout << solution.mySqrt(150) << endl;
    cout << solution.mySqrt(INT_MAX) << endl;
}
