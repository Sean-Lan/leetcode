/**
 *
 * Sean
 * 2017-06-17
 *
 * https://leetcode.com/problems/word-pattern/#/description
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 *
 */
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

// use two hash table to maintain the bijection
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> table;
        unordered_map<string, char> rTable;

        vector<string> words;
        istringstream iss(str);
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        int n = pattern.size();
        if (words.size() != n) return false;

        char c;
        for (int i=0; i<n; ++i) {
            string &word = words[i];
            c = pattern[i];

            if (!table.count(c)) {
                table[c] = word;
            } else if (table[c] != word) {
                return false;
            }

            if (!rTable.count(word)) {
                rTable[word] = c;
            } else if (rTable[word] != c) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
