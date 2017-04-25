/**
 *
 * Sean
 * 2017-04-25
 *
 * https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/#/description
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 *
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
 *
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 *
 * Note:
 * The read function may be called multiple times.
 *
 */
#include <iostream>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

// refer from https://discuss.leetcode.com/topic/32780/simple-short-java-c
// first read the characters into a temporary buff, then copy the characters from the temporary buff to the target output buff
class Solution {
    char buf4[4];
    int i4 = 0;
    int n4 = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (i4 < n4) buf[i++] = buf4[i4++];
            else {
                i4 = 0;
                n4 = read4(buf4);
                if (!n4) break;
            }
        }
        return i;
    }
};

int main() {
    return 0;
}
