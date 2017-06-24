/**
 *
 * Sean
 * 2017-06-24
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/#/description
 *
 * You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 *
 * Example:
 *
 * Given nums = [5, 2, 6, 1]
 *
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * Return the array [2, 1, 1, 0].
 *
 */
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

// divide and conquer
class Solution {
    vector<pair<int, int>> cache; // back up array for merge sort
    vector<pair<int, int>> arr; // {index, number}
    vector<int> res;
    void merge(int s, int e) {
        int mid = s + (e-s)/2;
        int i = s;
        int j = mid+1;
        int k = s;
        while (i <= mid && j <= e) {
            // since equal not count a reverse, we need push i-th number into cache
            // the first time it meets a number that >= it.
            if (arr[i].second <= arr[j].second) {
                this->res[arr[i].first] += j - (mid+1);
                this->cache[k++] = arr[i++];
            } else {
                this->cache[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            this->res[arr[i].first] += e - mid;
            this->cache[k++] = arr[i++];
        }

        while (j <= e) {
            this->cache[k++] = arr[j++];
        }

        // copy back
        for (int i=s; i<=e; ++i) {
            arr[i] = this->cache[i];
        }
    }

    void mergeSort(int s, int e) {
        if (s >= e) return;
        int mid = s + (e-s)/2;
        mergeSort(s, mid);
        mergeSort(mid+1, e);
        merge(s, e);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        this->cache = vector<pair<int, int>>(n);
        this->arr = vector<pair<int, int>>(n);
        for (int i=0; i<n; ++i) {
            arr[i] = {i, nums[i]};
        }
        this->res = vector<int>(n, 0);

        mergeSort(0, n-1);
        return res;
    }
};

int main() {
    return 0;
}
