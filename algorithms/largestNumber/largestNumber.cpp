#include <iostream>
/**
 *
 * Sean
 * 2016-04-22
 * 
 * https://leetcode.com/problems/largest-number/
 *
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 *
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end(), [](int &a, int &b) {
                    string s1 = to_string(a);
                    string s2 = to_string(b);
                    return s1+s2 > s2+s1;
                    });
            string res;
            for (auto &i : nums)
                res += to_string(i);
            auto pos = res.find_first_not_of('0');
            return pos == string::npos ? "0" : res.substr(pos);
        }
};

int main() {
    vector<int> nums = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    Solution solution;
    string s = solution.largestNumber(nums);
    cout << s << endl;
}
