/**
 *
 * Sean
 * 2015-04-10
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 */

#include <iostream>
#include <map>
using namespace std;

/**
 *
 * Scan the string from left to right. Use a map to mark down the last position a
 * character occurs, and mark down the last postion a repeation occurs. The 
 * longest substring contains currenct charater is calculated as: 
 *   min{distance between currenct postion and last repeation place,
 *     distance between current postion and last occurence of currenct charater}
 *
 */

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {	
			map<char, int> dict;
			int lastRepeatPlace = -1;
			int maxLen = 0;
			for (int i = 0; i < s.size(); i++) {
				if (dict.find(s[i]) != dict.end() && lastRepeatPlace < dict[s[i]]) {
					lastRepeatPlace = dict[s[i]];
				}
				if (i - lastRepeatPlace > maxLen) {
					maxLen = i - lastRepeatPlace;
				}
				dict[s[i]] = i;
			}
			return maxLen;
		}
};

int main() {
	Solution solution;
	string s = "abcabcbb";
	cout << s << " " << solution.lengthOfLongestSubstring(s) << endl;

	s = "tmmzuxt";
	cout << s << " " << solution.lengthOfLongestSubstring(s) << endl;

}
