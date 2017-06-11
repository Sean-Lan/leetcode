/**
 *
 * Sean
 * 2017-06-11
 *
 * https://leetcode.com/problems/encode-and-decode-strings/#/description
 *
 * Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 *
 * Machine 1 (sender) has the function:
 *
 * string encode(vector<string> strs) {
 *   // ... your code
 *   return encoded_string;
 * }
 * Machine 2 (receiver) has the function:
 * vector<string> decode(string s) {
 *   //... your code
 *   return strs;
 * }
 * So Machine 1 does:
 *
 * string encoded_string = encode(strs);
 * and Machine 2 does:
 *
 * vector<string> strs2 = decode(encoded_string);
 * strs2 in Machine 2 should be the same as strs in Machine 1.
 *
 * Implement the encode and decode methods.
 *
 * Note:
 * The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
 * Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
 * Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
 */
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string head;
        string body;
        for (auto &s : strs) {
            head += to_string(s.size());
            head += ' ';
            body += s;
        }
        head += to_string(-1);
        head += ' ';
        return head + body;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        istringstream is(s);
        vector<int> sizes;
        int size;
        string rem;
        while (is >> size) {
            if (size == -1) {
                rem = is.str().substr((int)is.tellg()+1); // need skip one space
                break;
            }
            sizes.push_back(size);
        }
        vector<string> res;
        int start = 0;
        for (auto size : sizes) {
            res.push_back(rem.substr(start, size));
            start += size;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
    return 0;
}
