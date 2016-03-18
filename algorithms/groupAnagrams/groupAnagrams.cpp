/**
 *
 * Sean
 * https://leetcode.com/problems/anagrams/
 *
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 *
 * Note:
 * For the return value, each inner list's elements must follow the lexicographic order.
 * All inputs will be in lower-case.
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// first sort the word to get the 'eigen' string
// use a multiset to keep the order of anagrams.
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, multiset<string>> groups;
            for (auto &s : strs) {
                string key = s;
                sort(key.begin(), key.end());
                groups[key].insert(s);
            }
            vector<vector<string>> result;
            for (auto &aPair : groups)
                result.push_back(vector<string>(aPair.second.begin(), aPair.second.end()));
            return result;
        }
};

int main() {
}
