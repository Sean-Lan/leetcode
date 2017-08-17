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
#include <list>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// organize a list like the flowing:
// [1, { a,b,c }] -> [2,{ e,f,g }] -> [5,{ m,n }] -> [6,{ x,y,z }]
// and maintain a hash table mapping from key to a certain list node
//
// needs to maintain the ordering of the list and mapping of the hash table at the same time
struct Bucket {
    int value;
    unordered_set<string> keys;
};
class AllOne {
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> table;
public:
    /** Initialize your data structure here. */
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!table.count(key)) {
            table[key] = buckets.insert(buckets.begin(), {0, {key}});
        }

        auto it = table[key];
        auto nit = next(it);
        if (nit == buckets.end() || nit->value > it->value + 1) {
            nit = buckets.insert(nit, {it->value+1, {}});
        }

        nit->keys.insert(key);
        table[key] = nit;

        it->keys.erase(key);
        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!table.count(key)) return;

        auto it = table[key];
        table.erase(key);
        if (it->value > 1) {
            auto pit = prev(it);
            if (it == buckets.begin() || pit->value < it->value-1) {
                pit = buckets.insert(it, {it->value-1, {}});
            }
            pit->keys.insert(key);
            table[key] = pit;
        }

        it->keys.erase(key);
        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (buckets.empty()) return "";
        // printBuckets();
        return *(buckets.rbegin()->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (buckets.empty()) return "";
        return *(buckets.begin()->keys.begin());
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
