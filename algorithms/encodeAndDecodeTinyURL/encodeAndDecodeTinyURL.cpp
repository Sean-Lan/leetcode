/**
 *
 * Sean
 * 2017-03-06
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/
 *
 * TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
 *
 * Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work.
 * You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 *
 */
#include <unordered_map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// reference to https://discuss.leetcode.com/topic/81637/two-solutions-and-thoughts

const string ALPHANUMS = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string PREFIX = "http://tinyurl.com/";

class Solution {
    unordered_map<string, string> urls;

    string getRandomEncoded(int length) {
        string res;
        for (int i=0; i<length; ++i) {
            res.push_back(ALPHANUMS[rand()%ALPHANUMS.size()]);
        }
        return res;
    }

public:
    Solution() {
        srand(time(0));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encoded = getRandomEncoded(6);
        while (urls.count(encoded)) {
            encoded = getRandomEncoded(6);
        }
        urls[encoded] = longUrl;
        return PREFIX + encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[shortUrl.substr(PREFIX.size())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    return 0;
}
