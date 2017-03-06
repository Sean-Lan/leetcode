/**
 *
 * Sean
 * 2017-03-06
 *
 * https://leetcode.com/problems/detect-capital/
 *
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 *
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one letter, like "Google".
 * Otherwise, we define that this word doesn't use capitals in a right way.
 *
 */
#include <string>
using namespace std;

// One pass solution, first count, then check whether it is valid.
class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount = count_if(word.begin(), word.end(), [](char c) { return c <= 'Z';});
        return !capCount || capCount == word.size() || (capCount==1) && word[0] <= 'Z';
    }
};

int main() {
    return 0;
}
