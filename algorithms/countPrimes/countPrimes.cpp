/**
 *
 * Sean
 * 2016-09-29
 *
 * https://leetcode.com/problems/count-primes/
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i=2; i*i < n; ++i) {
            if (isPrime[i]) {
                for (int j=i*i; j<n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};

int main() {}
