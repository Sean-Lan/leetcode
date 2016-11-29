/**
 *
 * Sean
 * 2016-11-29
 *
 * Assume you have an array of length n initialized with all 0's and are given k update operations.
 *
 * Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
 *
 * Return the modified array after all k operations were executed.
 *
 * Example:
 *
 * Given:
 *
 *     length = 5,
 *     updates = [
 *         [1,  3,  2],
 *         [2,  4,  3],
 *         [0,  2, -2]
 *     ]
 *
 * Output:
 *
 *     [-2, 0, 3, 5, 3]
 * Explanation:
 *
 * Initial state:
 * [ 0, 0, 0, 0, 0 ]
 *
 * After applying operation [1, 3, 2]:
 * [ 0, 2, 2, 2, 0 ]
 *
 * After applying operation [2, 4, 3]:
 * [ 0, 2, 5, 5, 3 ]
 *
 * After applying operation [0, 2, -2]:
 * [-2, 0, 3, 5, 3 ]
 * Hint:
 *
 * Thinking of using advanced data structures? You are thinking it too complicated.
 * For each update operation, do you really need to update all elements between i and j?
 * Update only the first and end element is sufficient.
 * The optimal time complexity is O(k + n) and uses O(1) extra space.
 *
 */
#include <vector>
using namespace std;

// add `inc` at the range beginning, and decrease `inc` at then range end + 1.
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);

        for (auto &op : updates) {
            arr[op[0]] += op[2];
            if (op[1] < length-1) arr[op[1]+1] -= op[2];
        }

        int curAdd = 0;
        for (int i=0; i<length; ++i) {
            curAdd += arr[i];
            arr[i] = curAdd;
        }
        return arr;
    }
};

int main() {
    return 0;
}
