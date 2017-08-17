/**
 *
 * Sean
 * 2017-08-17
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * Implement a data structure supporting the following operations:
 *
 * Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
 * Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
 * GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
 * GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
 * Challenge: Perform all these in O(1) time complexity.
 *
 */
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

// O(log(n)) solution with set and hash table
class AllOne {
    set<pair<int, string>> aSet;
    unordered_map<string, set<pair<int, string>>::iterator> table;
public:
    /** Initialize your data structure here. */
    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int weight = 1;
        if (table.count(key)) {
            auto it = table[key];
            weight = it->first + 1;
            aSet.erase(it);
        }
        table[key] = aSet.insert({weight, key}).first;
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (table.count(key)) {
            auto it = table[key];
            int weight = it->first - 1;
            aSet.erase(it);
            table.erase(key);
            if (weight > 0) {
                table[key] = aSet.insert({weight, key}).first;
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (aSet.empty()) return "";
        auto it = prev(aSet.end());
        return it->second;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (aSet.empty()) return "";
        return aSet.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */


int main() {
    return 0;
}
