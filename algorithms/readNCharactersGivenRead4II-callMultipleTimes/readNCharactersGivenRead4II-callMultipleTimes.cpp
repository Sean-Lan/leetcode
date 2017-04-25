/**
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

class Solution {
    // temporary buff
    char tmpBuf[4];
    int bufCnt;
    int bufOfs;

public:
    Solution(): bufCnt(0), bufOfs(0) {}
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        // first check whether there are some characters remaining in `tmpBuf`
        if (bufCnt) {
            if (n >= bufCnt) {
                memcpy(buf, tmpBuf+bufOfs, bufCnt);
                total += bufCnt;
                buf += bufCnt;
                n -= bufCnt;
                bufOfs = 0;
                bufCnt = 0;
            } else {
                memcpy(buf, tmpBuf+bufOfs, n);
                total += n;
                buf += n;
                bufOfs += n;
                bufCnt -= n;
                return total;
            }
        }
        // read characters
        while ((bufCnt = read4(tmpBuf)) == 4 && n >= bufCnt) {
            memcpy(buf, tmpBuf, bufCnt);
            buf += bufCnt;
            total += bufCnt;
            n -= bufCnt;
        }

        // set temporary buff
        if (n >= bufCnt) {
            memcpy(buf, tmpBuf, bufCnt);
            total += bufCnt;
            bufCnt = 0;
            bufOfs = 0;
        } else {
            memcpy(buf, tmpBuf, n);
            total += n;
            bufCnt -= n;
            bufOfs = n;
        }
        return total;
    }
};

int main() {
    return 0;
}
