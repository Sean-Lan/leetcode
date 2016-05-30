#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<string> results;
        int size = nums.size();
        bool endChosen = false;
        int start = nums[0], end = -1;
        for (int i=1; i<size; ++i) {
            if (nums[i] == nums[i-1]+1) {
                end = nums[i];
                endChosen = true;
            } else {
                if (endChosen) {
                    results.push_back(to_string(start)+"->"+to_string(end));
                    endChosen = false;
                } else {
                    results.push_back(to_string(start));
                }
                start = nums[i];
            }
        }
        if (endChosen) {
            results.push_back(to_string(start)+"->"+to_string(end));
        } else {
            results.push_back(to_string(start));
        }
        return results;
    }
};

int main() {}
