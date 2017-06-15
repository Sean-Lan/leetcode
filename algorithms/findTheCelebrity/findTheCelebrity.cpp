#include <iostream>
#include <vector>
using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

// every call to `know` can eliminate a candidate
// if i knows j, i must not be the celebrity
// otherwise, j must not be the celebrity
//
// After n-1 calls to `knows`, there is one candidate left, and go for another pass to check whether he/she is the celebrity
class Solution {
public:
    int findCelebrity(int n) {
        int cur = 0;
        for (int i=1; i<n; ++i) {
            if (knows(cur, i)) cur = i;
        }
        for (int i=0; i<n; ++i) {
            if (cur != i && (!knows(i, cur) || knows(cur, i))) return -1;
        }
        return cur;
    }
};

int main() {
    return 0;
}
