/**
 *
 * Sean
 * 2017-01-05
 *
 * https://leetcode.com/problems/super-ugly-number/
 *
 * Write a program to find the nth super ugly number.
 *
 * Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 *
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 *
 */
#include <queue>
#include <vector>
using namespace std;

bool MyCmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second > b.second;
}

typedef bool (*MyCmpType)(const pair<int, int>&, const pair<int, int>&);

// DP with priority_queue.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglyNumbers(n, INT_MAX);
        int k = primes.size();
        vector<int> indexes(k, 0);
        uglyNumbers[0] = 1;

        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(&MyCmp)> aQueue(MyCmp);
        // without decltype
        // priority_queue<pair<int, int>, vector<pair<int,int>>, MyCmpType> aQueue(MyCmp);
        for (int j=0; j<k; ++j) {
            aQueue.push({j, uglyNumbers[indexes[j]]*primes[j]});
        }
        for (int i=1; i<n; ++i) {
            int minIndex = aQueue.top().first;
            uglyNumbers[i] = min((long long)uglyNumbers[i], (long long)uglyNumbers[indexes[minIndex]]*primes[minIndex]);
            while (aQueue.top().second == uglyNumbers[i]) {
                int curIndex = aQueue.top().first;
                ++ indexes[curIndex];
                aQueue.pop();
                aQueue.push({curIndex, uglyNumbers[indexes[curIndex]]*primes[curIndex]});
            }
        }
        return uglyNumbers[n-1];
    }
};

int main() {
    return 0;
}
