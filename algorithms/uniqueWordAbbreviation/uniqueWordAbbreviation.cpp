/**
 *
 * Sean
 * 2017-06-16
 *
 * https://leetcode.com/problems/unique-word-abbreviation/#/description
 *
 * An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
 *
 * a) it                      --> it    (no abbreviation)
 *
 *      1
 * b) d|o|g                   --> d1g
 *
 *               1    1  1
 *      1---5----0----5--8
 * c) i|nternationalizatio|n  --> i18n
 *
 *               1
 *      1---5----0
 * d) l|ocalizatio|n          --> l10n
 * Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
 *
 * Example:
 * Given dictionary = [ "deer", "door", "cake", "card" ]
 *
 * isUnique("dear") ->
 * false
 *
 * isUnique("cart") ->
 * true
 *
 * isUnique("cane") ->
 * false
 *
 * isUnique("make") ->
 * true
 *
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// hash table
class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> table;
    string toAbbr(const string& word) {
        int len = word.size();
        if (len <= 2) return word;
        return word[0] + to_string(len-2) + word[len-1];
    }
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto &word : dictionary) {
            table[toAbbr(word)].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = toAbbr(word);
        if (!table.count(abbr)) return true;
        auto &dict = table[abbr];
        if (dict.size() > 1) return false;
        return dict.count(word);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */

int main() {
    return 0;
}
