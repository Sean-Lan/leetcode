#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        void dfs(vector<int> &nums, int step, vector<bool> &used,
                vector<int> &currentResult, vector<vector<int>> &results) {
            if (step == nums.size()) {
                results.push_back(currentResult);
                return;
            }
            for (int i=0; i<nums.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    currentResult.push_back(nums[i]);
                    dfs(nums, step+1, used, currentResult, results);
                    used[i] = false;
                    currentResult.pop_back();
                }
            }
        }

    public:
        vector<vector<int>> permute(vector<int>& nums) {
            if (nums.empty()) return {};
            vector<int> currentResult;
            vector<vector<int>> results;
            vector<bool> used(nums.size());
            dfs(nums, 0, used, currentResult, results);
            return results;
        }
};

void printResults(const vector<vector<int>> &results) {
    for (auto &iv : results) {
        for (auto &i : iv)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    vector<int> nums = {1,2,3};
    Solution solution;
    printResults(solution.permute(nums));
}
