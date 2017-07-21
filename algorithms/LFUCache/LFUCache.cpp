/**
 *
 * Sean
 * 2017-07-21
 *
 * https://leetcode.com/problems/lfu-cache/#/description
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LFUCache cache = new LFUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.get(3);       // returns 3.
 * cache.put(4, 4);    // evicts key 1.
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 */
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
    typedef list<pair<int, int>> lii;
    int capacity;
    int minFreq;
    unordered_map<int, int> freqs; // key => freq
    unordered_map<int, lii> freqLists; // freq => list({key, value})
    unordered_map<int, lii::iterator> m; // key => iterator of list({key, value})
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 1;
    }
    
    int get(int key) {
        if (!m.count(key)) {
            return -1;
        }
        // 1. find the pointer to pair in the list
        auto it = m[key];
        int value = it->second;
        int freq = freqs[key]++;
        // 2. find the list containg the pair and erase it
        auto &aList = freqLists[freq];
        aList.erase(it);
        // 3. move the pair to the list of next level (freq+1)
        auto &nextList = freqLists[freq+1];
        nextList.push_back({key, value});
        // 4. update map
        m[key] = prev(nextList.end());
        if (freq == minFreq && aList.empty()) ++minFreq;
        return value;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        
        // similar to get
        if (m.count(key)) {
            auto it = m[key];
            int freq = freqs[key]++;
            auto &aList = freqLists[freq];
            aList.erase(it);
            auto &nextList = freqLists[freq+1];
            nextList.push_back({key, value});
            m[key] = prev(nextList.end());
            if (freq == minFreq && aList.empty()) ++ minFreq;
            return;
        }
        
        // erase the pair with list frequency and is last recently used
        if (m.size() >= capacity) {
            auto &aList = freqLists[minFreq];
            int _key = aList.front().first;
            m.erase(_key);
            freqs.erase(_key);
            aList.pop_front();
        }
        
        // insert the pair into the min freq list
        freqs[key] = 1;
        auto &aList = freqLists[1];
        aList.push_back({key, value});
        m[key] = prev(aList.end());
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
    return 0;
}
