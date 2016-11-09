/**
 *
 * Sean
 * 2016-11-09
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/
 *
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 */
#include <string>
using namespace std;

const static char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

bool isVowel(char c) {
    for (auto v : vowels) {
        if (c == v) return true;
    }
    return false;
}

// two pointers
class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty()) return "";
        int start = 0;
        int end = s.size() - 1;
        char tmp;
        while (start < end) {
            while (start < end && !isVowel(s[start])) ++ start;
            while (start < end && !isVowel(s[end])) -- end;
            if (start < end) {
                tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                ++start;
                --end;
            }
        }
        return s;
    }
};

int main() { return 0; }
