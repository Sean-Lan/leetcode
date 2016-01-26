#include <utility>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <functional>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            unordered_map<int, int> numCnt;
            for (auto &i : nums) {
                ++numCnt[i];
            }
            cout << nums.size() << endl;
            vector<int> uniqued = vector<int>(nums.begin(), unique(nums.begin(), nums.end()));
            cout << nums.size() << endl;
            int num1, num2, num3;

            // num1, num2, num3 are all different
            // num1 < num2 < num3
            int size = uniqued.size();
            for (int i=0; i+2<size; ++i) {
                num1 = uniqued[i];
                for (int j=i+1; j+1<size; ++j) {
                    num2 = uniqued[j];
                    num3 = -(num1+num2);
                    if (num3 <= num2) break;
                    if (numCnt.find(num3)!=numCnt.end())
                        result.push_back({num1, num2, num3});
                }
            }

            for (auto& num1 : uniqued) {
                if (numCnt[num1] >=2) {
                    num3 = - num1 << 1;
                    if (num3!=num1 && numCnt.find(num3)!=numCnt.end()) {
                        if (num3 < num1)
                            result.push_back({num3, num1, num1});
                        else
                            result.push_back({num1, num1, num3});
                    }
                }
            }

            // check 3 numbers are equal, i.e 3 zeros.
            if (numCnt[0] >= 3)
                result.push_back({0,0,0});

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
