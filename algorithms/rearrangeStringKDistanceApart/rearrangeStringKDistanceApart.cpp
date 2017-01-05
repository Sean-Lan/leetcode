/**
 *
 * Sean
 * 2017-01-05
 *
 * https://leetcode.com/problems/rearrange-string-k-distance-apart/
 *
 * Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
 *
 * All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".
 *
 * Example 1:
 * str = "aabbcc", k = 3
 *
 * Result: "abcabc"
 *
 * The same letters are at least distance 3 from each other.
 * Example 2:
 * str = "aaabc", k = 3
 *
 * Answer: ""
 *
 * It is not possible to rearrange the string.
 * Example 3:
 * str = "aaadbbcc", k = 2
 *
 * Answer: "abacabcd"
 *
 * Another possible answer is: "abcabcda"
 *
 * The same letters are at least distance 2 from each other.
 *
 */
#include <unordered_map>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

// heap & greedy
class Solution {
public:
    string rearrangeString(string str, int k) {
        int size = str.size();
        // counts for different characters
        unordered_map<char, int> cnts;
        for (auto c : str)
            ++ cnts[c];
        // corner case
        if (k <= 1) return str;
        // rotated queue, make sure each character shows with at least `k` distance
        vector<char> rotated(k, 0);

        // use priority_queue as a *max heap*
        auto cmp = [&cnts](char c1, char c2) { return cnts[c1] < cnts[c2]; };
        priority_queue<char, vector<char>, decltype(cmp)> aQueue(cmp);

        for (auto &aPair : cnts)
            aQueue.push(aPair.first);

        // greedy, take the character has the largest count
        string res;
        while (!aQueue.empty()) {
            char c = aQueue.top();
            aQueue.pop();
            if (--cnts[c]) rotated[res.size()%k] = c;
            res.push_back(c);
            // push the availabe character into the heap
            if (rotated[res.size()%k]) {
                aQueue.push(rotated[res.size()%k]);
                rotated[res.size()%k] = 0;
            }
        }
        // distance requirements cannot be met
        if (res.size() != size) return "";
        return res;
    }
};


int main() {
    Solution solution;
    string str = "aa";
    int k = 2;
    cout << solution.rearrangeString(str, k) << endl;
    return 0;
}
