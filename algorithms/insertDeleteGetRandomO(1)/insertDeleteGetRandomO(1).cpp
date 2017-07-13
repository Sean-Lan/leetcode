/**
 *
 * Sean
 * 2017-07-13
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1/#/description
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 * Example:
 *
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 *
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 *
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 *
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 *
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 *
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 *
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 *
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 *
 */
#include <unordered_map>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    // value => index
    unordered_map<int, int> table;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (table.count(val)) return false;
        nums.push_back(val);
        table[val] = nums.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    // since only erase the last element in a vector costs constant time, we can always swap the to-be-deleted element
    // to the end of the vector, then erase it, just do additonal index maintaining work in constant time
    bool remove(int val) {
        if (table.count(val) == 0) return false;
        int pos = table[val];
        table.erase(val);
        if (pos == nums.size()-1) {
            nums.pop_back();
        } else {
           int tailVal = nums.back();
            nums[pos] = tailVal;
            table[tailVal] = pos;
            nums.pop_back();
        }
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    return 0;
}
