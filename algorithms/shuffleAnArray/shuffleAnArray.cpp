/**
 *
 * Sean Lan
 *
 * Shuffle a set of numbers without duplicates.
 *
 * Example:
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand(time(0));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = nums;
        for (int i=shuffled.size()-1; i>0; --i)
            swap(shuffled[i], shuffled[rand() % (i+1)]);
        return shuffled;
    }
};

int main() {}
