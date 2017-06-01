/**
 *
 * Sean
 * 2017-06-01
 *
 * https://leetcode.com/problems/majority-element-ii/#/description
 *
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1)
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// Boyer–Moore majority vote algorithm
// Simple proof:
// Take the problem in another way: every time we remove k different elements in the array until we cannot find k different elements.
// Two facts:
// 1. < k elemnts will remain, otherwise we could perform another removal
// 2. elements which show more than n/k times will remain
//
// We could maintain k-1 counters to represent the k-1 different elements. i.e., { num1: cnt1, num2: cnt2, .. numk-1, cntk-1 }
// Each time a new element x come:
// 1. If x is the same with numj, increase cntj by 1
// 2. If cnti equals to zero, let x be numi, and set cnti 1
// 3. if no counter is 0 and the element is different from any of the tracked number, then we find k different elements and we do the removal once by decreasing each of the k-1 counters by 1.
//
// Note than the remained k-1 numbers may not necessarily show more than n/k times, so the final check is necessary
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2;
        int c1, c2;
        c1 = c2 = num1 = num2 = 0;
        for (auto num : nums) {
            if (num == num1) ++c1;
            else if (num == num2) ++c2;
            else {
                if (c1 == 0) {
                    num1 = num;
                    c1 = 1;
                } else if (c2 == 0) {
                    num2 = num;
                    c2 = 1;
                } else {
                    -- c1;
                    -- c2;
                }
            }
        }

        vector<int> res;
        c1 = c2 = 0;
        for (auto num : nums) {
            if (num == num1) ++c1;
            else if (num == num2) ++c2;
        }

        int bar = nums.size()/3;
        if (c1 > bar) res.push_back(num1);
        if (c2 > bar) res.push_back(num2);
        return res;
    }
};

int main() {
    return 0;
}
