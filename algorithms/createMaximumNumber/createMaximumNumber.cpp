/**
 *
 * Sean
 * 2016-06-18
 *
 * https://leetcode.com/problems/create-maximum-number/
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.
 *
 * Example 1:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * return [9, 8, 6, 5, 3]
 *
 * Example 2:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * return [6, 7, 6, 0, 4]
 *
 * Example 3:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * return [9, 8, 9]
 *
 */
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void printVi(vector<int> &vi) {
    for (auto &i : vi)
        cout << i << " ";
    cout << endl;
}

// O(k*max(m,n))
// First find the largest numbers we can obtain from nums1 and nums2 separately,
// then merge the numbers into the final one.
class Solution {
public:
    vector<int> maxNumber(vector<int>& num, int k) {
        if (k >= num.size()) return num;
        list<int> aList(num.begin(), num.end());
        int cnt = num.size() - k;
        auto it = aList.begin();
        auto prevIt = it;
        // delete digits until the digit count is k
        while (cnt--) {
            while (it!=aList.end() && *it>=*(next(it))) ++it;
            if (it == aList.end()) {
                aList.pop_back();
                it = aList.end();
            } else {
                if (it == aList.begin()) {
                    aList.pop_front();
                    it = aList.begin();
                } else {
                    prevIt = prev(it);
                    aList.erase(it);
                    it = prevIt;
                }
            }
        }
        return vector<int>(aList.begin(), aList.end());
    }

    void mergeNumbers(vector<int> &num1, vector<int> &num2, vector<int> &result) {
        int m = num1.size();
        int n = num2.size();
        int i=0, j=0, k=0;
        while (i<m && j<n) {
            if (num1[i] < num2[j])
                result[k++] = num2[j++];
            else if (num1[i] > num2[j])
                result[k++] = num1[i++];
            else {
                // trikiest thing: we need *look ahead* when two digit are equal
                if (greaterThan(num1, i, num2, j)) result[k++] = num1[i++];
                else result[k++] = num2[j++];
            }
        }
        while (i<m) result[k++] = num1[i++];
        while (j<n) result[k++] = num2[j++];
    }

    bool greaterThan(vector<int> &num1, int i, vector<int> &num2, int j) {
        int m = num1.size();
        int n = num2.size();
        while (i<m && j<n) {
            if (num1[i] > num2[j])
                return true;
            if (num1[i] < num2[j])
                return false;
            ++i; ++j;
        }
        if (i < m) return true;
        return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> maxNum(k);
        vector<int> result(k);
        int m = nums1.size();
        int n = nums2.size();
        for (int i=max(0, k-n); i<=k && i<=m; ++i) {
            auto vi1 = maxNumber(nums1, i);
            auto vi2 = maxNumber(nums2, k-i);
            mergeNumbers(vi1, vi2, result);
            if (greaterThan(result, 0, maxNum, 0))
                maxNum.assign(result.begin(), result.end());
        }
        return maxNum;
    }
};

int main() {
    Solution solution;
    vector<int> nums1, nums2, result;
    int k;

    nums1 = {2,5,6,4,4,0};
    nums2 = {7,3,8,0,6,5,7,6,2};
    k = 15;
    result = solution.maxNumber(nums1, nums2, k);
    printVi(result);

}
