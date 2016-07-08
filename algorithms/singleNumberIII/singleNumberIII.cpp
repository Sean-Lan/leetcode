#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> singleNumber(vector<int>& nums) {
            int xorValue = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
            int mask = xorValue & (-xorValue);

            int a = 0;
            for (auto &i : nums)
                if (i & mask) a ^=i;
            int b = xorValue ^ a;
            return {a, b};
        }
};

int main() {}
