/**
 *
 * Sean
 * 2017-02-14
 *
 * https://leetcode.com/problems/keyboard-row/
 *
 * Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
 *
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <cctype>
using namespace std;

unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

// hash table, O(n)
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        int last = -1;
        for (auto &word : words) {
            bool valid = true;
            for (auto c : word) {
                c = tolower(c);
                if (row1.count(c)) {
                    if (last != -1 && last != 1) {
                        valid = false;
                        break;
                    }
                    last = 1;
                } else if (row2.count(c)) {
                    if (last != -1 && last != 2) {
                        valid = false;
                        break;
                    }
                    last = 2;
                } else {
                    if (last != -1 && last != 3) {
                        valid = false;
                        break;
                    }
                    last = 3;
                }
            }
            if (valid) res.push_back(word);
        }
        return res;
    }
};

int main() {
    return 0;
}
