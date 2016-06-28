/**
 *
 * Sean
 * 2016-06-28
 *
 * https://leetcode.com/problems/valid-palindrome/
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string converted;
        for (auto c : s) {
            if (c>='a' && c<='z' || c>='0'&&c<='9')
                converted.push_back(c);
            else if(c>='A' && c<='Z')
                converted.push_back(c+32);
        }
        if (converted.empty())
            return true;

        for (int i=0, j=converted.size()-1; i<j; ++i, --j) {
            if (converted[i] != converted[j])
                return false;
        }
        return true;
    }
};

int main() {}
