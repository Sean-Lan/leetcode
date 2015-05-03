/**
 *
 * Sean
 * 2015-04-08
 * 
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

/**
 *
 * Compared to the naive O(N^2) method, we use a map to store the <complemented number, index> pair, i,e: 
 * target - numbers[i] => i. When we find the complemented number, we find the result.
 *
 */

class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			map<int, int> differenceToIndex;
			vector<int> result;
			for (int i = 0; i<numbers.size(); i++) {
				if (differenceToIndex.find(numbers[i]) == differenceToIndex.end()) {
					differenceToIndex[target - numbers[i]] = i;
				} else {
					result.push_back(differenceToIndex[numbers[i]]+1);
					result.push_back(i+1);
					break;
				}
			}
			return result;
		}
};

int main() {
	vector<int> numbers;
	int target;
	istream_iterator<int> intReader(cin);
	istream_iterator<int> intEOF;
	target = *intReader;
	++intReader;
	copy(intReader, intEOF, back_inserter(numbers));
			
	Solution solution;
	vector<int> result = solution.twoSum(numbers, target);
	copy(result.begin(), result.end(), ostream_iterator<int>(cout,"\n"));
}
