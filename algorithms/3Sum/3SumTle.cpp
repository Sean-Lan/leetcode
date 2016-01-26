#include <tuple>
#include <utility>
#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> Triplet;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<int> negativeVec;
            vector<int> positiveVec;
            unordered_set<int> negatives;
            unordered_set<int> positives;
            set<Triplet> result;
            int zeroCnt = 0;
            for (auto &num : nums) {
                if (num == 0) ++zeroCnt;
                else if (num < 0) {
                    negativeVec.push_back(num);
                    negatives.insert(num);
                } else {
                    positiveVec.push_back(num);
                    positives.insert(num);
                }
            }

            
            int num1, num2, num3;
            // case 1: 2 negatives and one positive
            for (int i=0; i<negativeVec.size(); ++i) {
                for (int j=i+1; j<negativeVec.size(); ++j) {
                    num1 = negativeVec[i];
                    num2 = negativeVec[j];
                    if (num1 > num2) swap(num1, num2);
                    num3 = -(num1+num2);
                    if (positives.find(num3) != positives.end())
                        result.insert(make_tuple(num1, num2, num3));
                }
            }

            // case 2: one negative, one zero, and one positive
            if (zeroCnt) {
                for (int i=0; i<negativeVec.size(); ++i) {
                    num1 = negativeVec[i];
                    num2 = 0;
                    num3 = -num1;
                    if (positives.find(num3) != positives.end())
                        result.insert(make_tuple(num1, num2, num3));
                }
            }

            // case3: one negative, two positive
            for (int i=0; i<positiveVec.size(); ++i) {
                for (int j=i+1; j<positiveVec.size(); ++j) {
                    num2 = positiveVec[i];
                    num3 = positiveVec[j];
                    if (num2 > num3) swap(num2, num3);
                    num1 = -(num2+num3);
                    if (negatives.find(num1) != negatives.end())
                        result.insert(make_tuple(num1, num2, num3));
                }
            }

            // case4: three zeros
            if (zeroCnt>=3) {
                result.insert(make_tuple(0, 0, 0));
            }

            vector<vector<int>> retVec;
            for (auto& triplet : result) {
                num1 = std::get<0>(triplet);
                num2 = std::get<1>(triplet);
                num3 = std::get<2>(triplet);
                cout << num1 << " " << num2 << " " << num3 << endl;
                retVec.push_back({num1, num2, num3});
            }
            return retVec;
        }
};
int main() {
    /* vector<int> nums = {-1,0,1,2,-1,-4}; */
    vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    /* vector<int> nums = {}; */
    /* vector<int> nums = {-1, 0, 1}; */
    Solution s;
    s.threeSum(nums);
    /* cout << "ok!" << endl; */
}
