/**
 *
 * Sean
 * 2017-07-13
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * Note: Duplicate elements are allowed.
 * insert(val): Inserts an item val to the collection.
 * remove(val): Removes an item val from the collection if present.
 * getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
 * Example:
 *
 * // Init an empty collection.
 * RandomizedCollection collection = new RandomizedCollection();
 *
 * // Inserts 1 to the collection. Returns true as the collection did not contain 1.
 * collection.insert(1);
 *
 * // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
 * collection.insert(1);
 *
 * // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
 * collection.insert(2);
 *
 * // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
 * collection.getRandom();
 *
 * // Removes 1 from the collection, returns true. Collection now contains [1,2].
 * collection.remove(1);
 *
 * // getRandom should return 1 and 2 both equally likely.
 * collection.getRandom();
 *
 */
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <random>
using namespace std;

// similar to no-dup allowed problem, but in this case, we need to use a index set in the index table
class RandomizedCollection {
    vector<int> nums;
    // val -> {index}
    unordered_map<int, unordered_set<int>> table;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool found = table.count(val);
        table[val].insert(nums.size());
        nums.push_back(val);
        return !found;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (table.count(val) == 0) return false;
        auto &indexes = table[val];
        auto it = indexes.begin();
        int pos = *it;
        indexes.erase(it);
        if (indexes.empty()) table.erase(val);
        if (pos == nums.size() -1) {
            nums.pop_back();
        } else {
            int tailVal = nums.back();
            nums.pop_back();
            auto &tailIndexes = table[tailVal];
            tailIndexes.erase(nums.size());
            tailIndexes.insert(pos);
            nums[pos] = tailVal;
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    return 0;
}

