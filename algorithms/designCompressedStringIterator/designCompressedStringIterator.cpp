/**
 *
 * Sean
 * 2017-09-21
 *
 * https://leetcode.com/problems/design-compressed-string-iterator/description/
 *
 * Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.
 *
 * The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.
 *
 * next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
 * hasNext() - Judge whether there is any letter needs to be uncompressed.
 *
 * Note:
 * Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.
 *
 * Example:
 *
 * StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");
 *
 * iterator.next(); // return 'L'
 * iterator.next(); // return 'e'
 * iterator.next(); // return 'e'
 * iterator.next(); // return 't'
 * iterator.next(); // return 'C'
 * iterator.next(); // return 'o'
 * iterator.next(); // return 'd'
 * iterator.hasNext(); // return true
 * iterator.next(); // return 'e'
 * iterator.hasNext(); // return false
 * iterator.next(); // return ' '
 *
 */
#include <string>
using namespace std;

class StringIterator {
    string s;
    char c;
    int cnt;
    int curCnt;
    char nextIndex;
public:
    StringIterator(string compressedString) {
        s = compressedString;
        nextIndex = 0;
        curCnt = 0;
        cnt = 0;
    }

    char next() {
        if (hasNext()) {
            ++ curCnt;
            return c;
        }
        return ' ';
    }

    bool hasNext() {
        if (curCnt < cnt) return true;
        if (nextIndex >= s.size()) return false;
        c = s[nextIndex++];
        curCnt = 0;
        cnt = 0;
        while (nextIndex < s.size() && isdigit(s[nextIndex])) {
            cnt = cnt*10 + s[nextIndex] - '0';
            ++ nextIndex;
        }
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

int main() {
    return 0;
}
