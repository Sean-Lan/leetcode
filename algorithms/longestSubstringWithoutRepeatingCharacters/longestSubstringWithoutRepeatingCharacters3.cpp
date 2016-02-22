/**
 *
 * Sean
 * 2016-02-22
 *
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
// using slide window.
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> lastOcurrence;
            int maxLength = 0;
            int left = 0;
            int right = 0;
            char c;
            while (right < s.size()) {
                c = s[right];
                if (lastOcurrence.find(c)!=lastOcurrence.end() && left <= lastOcurrence[c]) {
                    left = lastOcurrence[c]+1;
                }
                lastOcurrence[c] = right;
                maxLength = max(right-left+1, maxLength);
                ++right;
            }
            return maxLength;
        }
};

int main() {
	Solution solution;
	string s = "abcabcbb";
	cout << s << " " << solution.lengthOfLongestSubstring(s) << endl;

	s = "tmmzuxt";
	cout << s << " " << solution.lengthOfLongestSubstring(s) << endl;

	s = "abcde";
	cout << s << " " << solution.lengthOfLongestSubstring(s) << endl;

}
