/**
 *
 * Sean
 * 2016-08-01
 *
 * https://leetcode.com/problems/lru-cache/
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 */
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// Use a list to store the (key, value) pair by LRU order, i.e., the front is the least recently used while the back is the most recently used.
// Use a map to record key => pointer to the list node.
// *Note*: In some compliers, list::size() is linear complexity, make sure to use the map's size to obtain constant size checking complexity.
class LRUCache{
    typedef pair<int, int> ii;
    typedef list<ii>::iterator list_iter;
    int capacity;
    unordered_map<int, list_iter> cache;
    list<ii> raw;
    public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        int value = -1;
        if (cache.count(key)) {
            list_iter it = cache[key];
            value = (*it).second;
            raw.erase(it);
            it = raw.insert(raw.cend(), make_pair(key, value));
            cache[key] = it;
        }
        return value;
    }

    void set(int key, int value) {
        list_iter it;
        if (cache.count(key)) {
            it = cache[key];
            raw.erase(it);
        }
        it = raw.insert(raw.cend(), make_pair(key, value));
        cache[key] = it;
        if (cache.size() > capacity) {
            cache.erase(raw.front().first);
            raw.pop_front();
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.set(2, 1);
    cache.set(1, 1);
    cout << "2 -> " << cache.get(2) << endl;
    cache.set(4, 1);
    cout << "1 -> " << cache.get(1) << endl;
    cout << "2 -> " << cache.get(2) << endl;
    return 0;
}
