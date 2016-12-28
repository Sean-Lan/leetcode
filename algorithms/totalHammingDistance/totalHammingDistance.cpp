/**
 *
 * Sean
 * 2016-12-28
 *
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * Now your job is to find the total Hamming distance between all pairs of the given numbers.
 *
 * Example:
 * Input: 4, 14, 2
 *
 * Output: 6
 *
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
 *
 * Note:
 * 1. Elements of the given array are in the range of 0 to 10^9
 * 2. Length of the array will not exceed 10^4.
 *
 */
#include <vector>
using namespace std;

// count the number of i-th digit which equals to one
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int oneCnt = 0;
        int mask = 1;
        int total = 0;
        int n = nums.size();
        for (int i=0; i<32; ++i) {
            oneCnt = 0;
            for (auto &num : nums) {
                if (num & mask) ++ oneCnt;
            }
            total += oneCnt * (n - oneCnt);
            mask <<= 1;
        }
        return total;
    }
};

int main() {
    return 0;
}
