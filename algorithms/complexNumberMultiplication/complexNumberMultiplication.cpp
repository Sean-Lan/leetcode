/**
 *
 * Sean
 * 2017-07-19
 *
 * https://leetcode.com/problems/complex-number-multiplication/#/description
 *
 * Given two strings representing two complex numbers.
 *
 * You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
 *
 * Example 1:
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
 *
 * Example 2:
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 *
 * Note:
 *
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
 *
 */
#include <sstream>
#include <string>
using namespace std;

// good problem to practice sstream
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        istringstream isa(a);
        istringstream isb(b);
        int a1, b1;
        int a2, b2;
        isa >> a1; isa.get(); isa >> b1;
        isb >> a2; isb.get(); isb >> b2;

        ostringstream os;
        os << a1*a2-b1*b2 << "+" << a1*b2+a2*b1 << "i";

        return os.str();
    }
};

int main() {
    return 0;
}
