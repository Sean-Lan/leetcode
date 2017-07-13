/**
 *
 * Sean
 * 2017-07-13
 *
 * https://leetcode.com/problems/design-phone-directory/#/description
 *
 * Design a Phone Directory which supports the following operations:
 *
 * get: Provide a number which is not assigned to anyone.
 * check: Check if a number is available or not.
 * release: Recycle or release a number.
 * Example:
 *
 * // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
 * PhoneDirectory directory = new PhoneDirectory(3);
 *
 * // It can return any available phone number. Here we assume it returns 0.
 * directory.get();
 *
 * // Assume it returns 1.
 * directory.get();
 *
 * // The number 2 is available, so return true.
 * directory.check(2);
 *
 * // It returns 2, the only number that is left.
 * directory.get();
 *
 * // The number 2 is no longer available, so return false.
 * directory.check(2);
 *
 * // Release number 2 back to the pool.
 * directory.release(2);
 *
 * // Number 2 is available again, return true.
 * directory.check(2);
 *
 */
#include <unordered_set>
using namespace std;

// use a hash table as a recycle pool to help check whether a number is available in constant time
class PhoneDirectory {
    int maxVal;
    unordered_set<int> pool;
    int nextVal;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this -> maxVal = maxNumbers;
        this -> nextVal = 0;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (nextVal == maxVal && pool.empty()) return -1;
        if (nextVal < maxVal) return nextVal++;
        auto it = pool.begin();
        int val = *it;
        pool.erase(it);
        return val;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return !(number < nextVal && pool.count(number) == 0);
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (number < nextVal)
            pool.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

int main() {
    return 0;
}
