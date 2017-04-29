/**
 *
 * Sean
 * 2017-04-29
 *
 * https://leetcode.com/problems/first-bad-version/#/description
 *
 * You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 *
 */
#include <iostream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// Binary Search
class Solution {
    int bs(int s, int e, function<bool(int)> f) {
        int m;
        while (s < e) {
            m = s + (e-s)/2;
            if (f(m)) e = m;
            else s = m + 1;
        }
        return s;
    }
public:
    int firstBadVersion(int n) {
        return bs(1, n, isBadVersion);
    }
};

int main() {
    return 0;
}
