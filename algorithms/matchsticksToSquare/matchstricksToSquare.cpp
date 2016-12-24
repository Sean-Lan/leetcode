#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

class Solution {
    bool valid(vector<int> &edges) {
        int e0 = edges[0];
        for (int i=1; i<edges.size(); ++i)
            if (edges[i] != e0) return false;
        return true;
    }

    bool dfs(int index, vector<int> &masks, vector<int> &edges, vector<int> &nums, unordered_set<int> &visited) {
        if (index == nums.size()) {
            for (auto &e : edges) cout << e << " ";
            cout << endl;
            return valid(edges);
        }
        for (int i=0; i<4; ++i) {
            if (visited.count(masks[i]|(1<<index))) continue;
            masks[i] |= 1<<index;
            visited.insert(masks[i]);
            edges[i] += nums[index];
            if (dfs(index+1, masks, edges, nums, visited)) return true;
            edges[i] -= nums[index];
            masks[i] &= ~(1<<index);
        }
        return false;
    }

    public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) return false;
        unordered_set<int> visited;
        vector<int> edges(4, 0);
        vector<int> masks(4, 0);
        return dfs(0, masks, edges, nums, visited);
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 1, 1};
    cout << solution.makesquare(nums) << endl;
    return 0;
}
