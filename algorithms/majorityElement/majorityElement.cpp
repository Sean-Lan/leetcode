/**
 *
 * Sean
 * 2016-09-07
 *
 * https://leetcode.com/problems/majority-element/
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// reference from https://discuss.leetcode.com/topic/17446/6-suggested-solutions-in-c-with-explanations
class Solution {
	public:
		// hash
		int majorityElement(vector<int>& nums) {
			unordered_map<int, int> cnts;
			int halfSize = nums.size()/2;
			int ret = -1;
			for (auto &i : nums)
				if (++cnts[i] > halfSize) {
					ret = i;
					break;
				}
			return ret;
		}

		// the middle one in the sorted array is the majority element.
		int majorityElement2(vector<int>& nums) {
			nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
			return nums[nums.size()/2];
		}

		// Divide and Conquer
		int majorityElement3(vector<int>& nums) {
			return majority(nums, 0, nums.size()-1);
		}

		int majority(vector<int> &nums, int start, int end) {
			if (start == end) return nums[start];
			int mid = (start+end)>>1;
			int lm = majority(nums, start, mid);
			int rm = majority(nums, mid+1, end);
			int lcnt = 0, rcnt = 0;
			for (int i=start; i<=end; ++i) {
				if (nums[i] == lm) ++lcnt;
				if (nums[i] == rm) ++rcnt;
			}
			return (lcnt > rcnt) ? lm: rm;
		}

		// Moore Voting Algorithm
		int majorityElement4(vector<int>& nums) {
			int majority = 0;
			int cnt = 0;
			for (auto &i : nums) {
				if (cnt == 0)
					majority = i;
				cnt += (majority==i) ? 1 : -1;
			}
			return majority;
		}

		// bit manipulation
		int majorityElement5(vector<int>& nums) {
			int majority = 0;
			int halfSize = nums.size() >> 1;
			for (int i=0, mask = 1; i<32; ++i, mask<<=1) {
				int cnt = 0;
				for (auto &i : nums)
					if (i & mask) ++cnt;
				if (cnt > halfSize)
					majority |= mask;
			}
			return majority;
		}
};

int main() {
	return 0;
}
