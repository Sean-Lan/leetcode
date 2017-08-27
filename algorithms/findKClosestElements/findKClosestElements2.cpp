/**
 *
 * Sean
 * 2017-08-27
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
 *
 * Example 1:
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * Note:
 * The value k is positive and will always be smaller than the length of the sorted array.
 * Length of the given array is positive and will not exceed 10^4
 * Absolute value of elements in the array and x will not exceed 10^4
 *
 */
#include <vector>
#include <cstdlib>
using namespace std;

// binary search
// O(log(n) + k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.front() >= x) {
            return vector<int>(arr.begin(), arr.begin()+k);
        } else if (arr.back() <= x) {
            return vector<int>(arr.end()-k, arr.end());
        } else {
            auto it = lower_bound(arr.begin(), arr.end(), x);
            auto s = (it-arr.begin()>=k ? it-k : arr.begin()); // must remain [it-k, it] k+1 numbers in total cauz it points to a number >= x
            auto e = (arr.end()-it >= k ? it+(k-1) : prev(arr.end()));
            while (e - s + 1 > k) {
                if (abs(*s - x) >  abs(*e -x)) { ++s; }
                else { --e; }
            }
            return vector<int>(s, next(e));
        }
    }
};

int main() {
    return 0;
}
