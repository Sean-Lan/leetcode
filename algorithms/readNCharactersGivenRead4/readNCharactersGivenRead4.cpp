/**
 *
 * Sean
 * 2017-04-25
 *
 * https://leetcode.com/problems/read-n-characters-given-read4/#/description
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 *
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
 *
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 *
 * Note:
 * The read function will only be called once for each test case.
 *
 *
 */
#include <iostream>
#include <cstring>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        int total = 0;
        // prepare a tmp buff in case n is not a mutiple of 4, which means the user may not provide enough buff for 4*x characters
        char * tmpBuf = new char[4];
        while ((cnt = read4(tmpBuf)) == 4 && n >= cnt) {
            memcpy(buf, tmpBuf, cnt);
            buf += cnt;
            total += cnt;
            n-=cnt;
        }
        int r = (n>=cnt) ? cnt : n;
        memcpy(buf, tmpBuf, r);
        total += r;
        delete []tmpBuf;
        return total;
    }
};

int main() {
    return 0;
}
