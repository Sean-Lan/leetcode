/**
 *
 * Sean
 * 2017-05-21
 *
 * https://leetcode.com/problems/two-sum-iii-data-structure-design/#/description
 *
 * Design and implement a TwoSum class. It should support the following operations: add and find.
 *
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the value.
 *
 * For example,
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 *
 */
#include <unordered_map>
using namespace std;

// insert O(1), find O(n)
class TwoSum {
    unordered_map<int, int> cnts;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++ cnts[number];
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto &aPair : cnts) {
            int j = value - aPair.first;
            if (j == aPair.first) {
                if (aPair.second >= 2) return true;
            } else {
                if (cnts.count(j)) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
int main() {
    return 0;
}
