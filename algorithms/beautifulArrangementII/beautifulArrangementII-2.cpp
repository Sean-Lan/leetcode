/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/beautiful-arrangement-ii/description/
 *
 * Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
 * Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
 *
 * If there are multiple answers, print any of them.
 *
 * Example 1:
 * Input: n = 3, k = 1
 * Output: [1, 2, 3]
 * Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
 * Example 2:
 * Input: n = 3, k = 2
 * Output: [1, 3, 2]
 * Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
 * Note:
 * The n and k are in the range 1 <= k < n <= 10^4.
 *
 */
#include <vector>
#include <list>
#include <numeric>
using namespace std;

// O(n) with list
// first make an array as 1..n
// move the smallest number before the largest one, and do it recursively
// k -> k-2
class Solution {
    typedef list<int>::iterator It;
    void sovle(int k, list<int> &nums, It p) {
        if (k <= 1) return;
        nums.insert(p, nums.front());
        nums.erase(nums.begin());
        --p; --p;
        sovle(k-2, nums, p);
    }
public:
    vector<int> constructArray(int n, int k) {
        list<int> nums(n, 0);
        iota(nums.begin(), nums.end(), 1);
        It p = nums.begin();
        for (int i=0; i<k; ++i) ++p;
        sovle(k, nums, p);
        return vector<int>(nums.begin(), nums.end());
    }
};

int main() {
    return 0;
}
