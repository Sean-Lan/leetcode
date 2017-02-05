#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int globalMax = 0;
        int curMax = 0;
        // max value after at most flip one zero
        int flipMax = 0;
        for (auto &i : nums) {
            if (i == 1) {
                ++ curMax;
                ++ flipMax;
            } else {
                // updating order matters
                // first update the value of `globalMax`
                globalMax = max(globalMax, flipMax);
                // then update the value of `flipmax`
                flipMax = curMax + 1;
                curMax = 0;
            }
        }
        globalMax = max(globalMax, flipMax);
        return globalMax;
    }
};

int main() {
    return 0;
}
