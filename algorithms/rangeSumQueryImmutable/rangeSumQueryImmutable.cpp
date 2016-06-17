#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    private:
        vector<long long> sum;
    public:
        NumArray(vector<int> &nums) {
            if (nums.empty()) return;
            sum.reserve(nums.size());
            sum[0] = nums[0];
            for (int i=1; i<nums.size(); ++i)
                sum[i] = sum[i-1] + nums[i];
        }

        int sumRange(int i, int j) {
            if (i == 0)
                return sum[j];
            else
                return sum[j] - sum[i-1];
        }
};


// Your NumArray object will be instantiated and called as such:
// // NumArray numArray(nums);
// // numArray.sumRange(0, 1);
// // numArray.sumRange(1, 2);

int main() {}
