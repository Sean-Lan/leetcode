/**
 *
 * Sean
 * 2017-03-20
 *
 * A magical string S consists of only '1' and '2' and obeys the following rules:
 *
 * The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.
 *
 * The first few elements of string S is the following: S = "1221121221221121122……"
 *
 * If we group the consecutive '1's and '2's in S, it will be:
 *
 * 1 22 11 2 1 22 1 22 11 2 11 22 ......
 *
 * and the occurrences of '1's or '2's in each group are:
 *
 * 1 2  2 1 1 2 1 2 2 1 2 2 ......
 *
 * You can see that the occurrence sequence above is the S itself.
 *
 * Given an integer N as input, return the number of '1's in the first N number in the magical string S.
 *
 * Note: N will not exceed 100,000.
 *
 * Example 1:
 * Input: 6
 * Output: 3
 * Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
 *
 */
#include <vector>
using namespace std;

// reference to https://discuss.leetcode.com/topic/74917/simple-java-solution-using-one-array-and-two-pointers
// Construct the string and count
class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        vector<int> s(n+1);
        s[0] = 1;
        s[1] = s[2] = 2;

        int head = 2;
        int tail = 3;
        int cur = 1;
        int cnt = 1;

        while(tail < n) {
            for (int i=0; i<s[head]; ++i) {
                if (cur == 1 && tail < n) ++cnt;
                s[tail++] = cur;
            }
            ++ head;
            cur = cur == 1 ? 2 : 1;
        }
        return cnt;
    }
};

int main() {
    return 0;
}
