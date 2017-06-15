/**
 *
 * Sean
 * 2017-06-15
 *
 * https://leetcode.com/problems/h-index-ii/#/description
 *
 * Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 *
 */
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

// typical bs search, find the first i which lets p ture
class Solution {
    // FFFFTTTTT
    int bs_search(int s, int e, function<bool(int)> p) {
        int mid;
        while (s < e) {
            mid = s + (e-s)/2;
            if (p(mid)) {
                e = mid;
            } else {
                s = mid+1;
            }
        }
        return s;
    }
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty() || citations.back() == 0) return 0;
        int n = citations.size();
        return n- bs_search(0, n-1, [&] (int i) {
            return citations[i] >= n-i;
        });
    }
};

int main() {
    return 0;
}
