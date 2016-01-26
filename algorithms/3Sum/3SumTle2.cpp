#include <utility>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            unordered_multiset<int> negatives;
            unordered_multiset<int> positives;
            vector<vector<int>> result;
            int zeroCnt = 0;
            for (auto &num : nums) {
                if (num == 0) ++zeroCnt;
                else if (num < 0) {
                    negatives.insert(num);
                } else {
                    positives.insert(num);
                }
            }

            
            int num1, num2, num3;
            // case 1: 2 negatives and one positive
            for (auto it = negatives.begin(); 
                 it!=negatives.end() && next(it)!=negatives.end(); 
                 ++it) {
                for (auto it2 = next(it); it2!=negatives.end(); ++it2) {
                    num1 = *it;
                    num2 = *it2;
                    if (num1 > num2) swap(num1, num2);
                    num3 = -(num1+num2);
                    if (positives.find(num3) != positives.end()) {
                        result.push_back({num1, num2, num3});
                    }
                }
            }            



            // case 2: one negative, one zero, and one positive
            if (zeroCnt) {
                for (auto it = negatives.begin(); it!=negatives.end(); ++it) {
                    num1 = *it;
                    num2 = 0;
                    num3 = -num1;
                    if (positives.find(num3) != positives.end())
                        result.push_back({num1, num2, num3});
                }
            }

            // case3: one negative, two positive
            for (auto it = positives.begin(); 
                 it!=positives.end() && next(it)!=positives.end();
                 ++it) {
                for (auto it2 = next(it); it2!=positives.end(); ++it2) {
                    num2 = *it;
                    num3 = *it2;
                    if (num2 > num3) swap(num2, num3);
                    num1 = -(num2+num3);
                    if (negatives.find(num1) != negatives.end())
                        result.push_back({num1, num2, num3});
                }
            }
            
            // case4: three zeros
            if (zeroCnt>=3) {
                result.push_back({0,0,0});
            }

            sort(result.begin(), result.end());
            auto last = unique(result.begin(), result.end());
            result.erase(last, result.end());

            return result;
        }
};

void printResult(const vector<vector<int>> &result) {
    for (auto ivec: result) {
        for (auto i : ivec) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    /* vector<int> nums = {-1,0,1,2,-1,-4}; */
    vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    /* vector<int> nums = {}; */
    /* vector<int> nums = {-1, 0, 1}; */
    /* vector<int> nums = {1,1,-2}; */
    Solution s;
    auto result = s.threeSum(nums);
    printResult(result);
    /* cout << "ok!" << endl; */
}
