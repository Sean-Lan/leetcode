/**
 *
 * Sean
 * 2015-05-06
 *
 * https://leetcode.com/problems/string-to-integer-atoi/
 * 
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, 
 * please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given 
 * input specs). You are responsible to gather all the input requirements up front.
 * 
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the
 * first non-whitespace character is found. Then, starting from this character, 
 * takes an optional initial plus or minus sign followed by as many numerical 
 * digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral 
 * number, which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral
 * number, or if no such sequence exists because either str is empty or it contains
 * only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the 
 * correct value is out of the range of representable values, INT_MAX (2147483647) 
 * or INT_MIN (-2147483648) is returned.
 *
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
    public:
        int myAtoi(string str) {
            string processed = preprocess(str);
            if (processed == "") 
                return 0;
            bool negative = false;
            if (processed[0] == '-')
                negative = true;
            int sum;
            string::size_type pos = 1;
            if (!negative) {
                sum = processed[pos++];
                while (pos!=processed.size()) {
                    /* check overflow */
                    if (sum > (INT_MAX - processed[pos])/10)
                        return INT_MAX;
                    sum = sum*10 + processed[pos];
                    ++pos;
                }
            } else {
                sum = -processed[pos++];
                while (pos!=processed.size()) {
                    /* check overflow */
                    if (sum < (INT_MIN + processed[pos])/10)
                        return INT_MIN;
                    sum = sum*10 - processed[pos];
                    ++pos;
                }
            }
            return sum;
        }
        
        /**
         *
         * Auxiliary function. Remove the space characters and dirty character of 
         * str, validate str, add sign characer in str and substract each digit 
         * character with '0'.
         * Return empty string if str is invalid.
         *
         */
        string preprocess(const string& str) {
            string processed;
            if (str == "")
                return processed;
            string::size_type pos = 0;
            while (isspace(str[pos]))
                ++pos;
            if ((str[pos] == '+' || str[pos] == '-') && isdigit(str[pos+1])) {
                processed.push_back(str[pos]);
                ++pos;
            } else if (isdigit(str[pos])) 
                processed.push_back('+');
            else    // Not a valid number
                return processed;
            while (pos!=str.size() && isdigit(str[pos])) {
                processed.push_back(str[pos] - '0');
                ++pos;
            }
            return processed;
        }
};

int main() {
    Solution solution;
    string str = "998";
    cout << "\"" << str << "\"" << endl;
    cout << solution.myAtoi(str) << endl;

    str = "-998";
    cout << "\"" << str << "\"" << endl;
    cout << solution.myAtoi(str) << endl;

    str = "++998";
    cout << "\"" << str << "\"" << endl;
    cout << solution.myAtoi(str) << endl;

    str = "llanndks-9981324123421432414312431";
    cout << "\"" << str << "\"" << endl;
    cout << solution.myAtoi(str) << endl;

    str = "       -99aaaabkda,dkslfj";
    cout << "\"" << str << "\"" << endl;
    cout << solution.myAtoi(str) << endl;

    str = "       -23124312234214324214314aaaabkda,dkslfj";
    cout << "\"" << str << "\"" << endl;
    cout << solution.myAtoi(str) << endl;

    str = "+2147483648";
    cout << "\"" << str << "\"" << endl;
    cout << solution.myAtoi(str) << endl;
    return 0;
}
