/**
 *
 * Sean
 * 2016-11-07
 *
 * https://leetcode.com/problems/longest-absolute-file-path/
 *
 * Suppose we abstract our file system by a string in the following manner:

 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 *
 * dir
 *     subdir1
 *     subdir2
 *         file.ext
 * The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
 *
 * The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
 *
 * dir
 *     subdir1
 *         file1.ext
 *         subsubdir1
 *     subdir2
 *         subsubdir2
 *             file2.ext
 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
 *
 * We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
 *
 * Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
 *
 * Note:
 * The name of a file contains at least a . and an extension.
 * The name of a directory or sub-directory will not contain a ..
 * Time complexity required: O(n) where n is the size of the input string.
 *
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item {
    Item(): nextPos(-1), length(0), level(0), isFile(false) {}
    int nextPos;
    int length;
    bool isFile;
    int level;
};

class Solution {
    // return next directory item.
    Item getNext(string &input, int start) {
        int i;
        Item item;
        for (i=start; i<input.size() & input[i] != '\n'; ++i) {
            if (input[i] == '\t') {
                // skip '\t'
                ++ start;
                ++ item.level;
            }
            if (input[i] == '.')
                item.isFile = true;
        }
        item.length = i - start;
        item.nextPos = i==input.size() ? i : i + 1;
        return item;
    }

    // if `Ls` has enough space, just update it; push_back otherwise.
    void pushIntoLs(vector<int> &Ls, Item &item) {
        if (Ls.size() > item.level) {
            // +1 for adding '/'
            Ls[item.level] = item.level == 0 ? item.length : Ls[item.level-1] + item.length + 1;
        } else {
            // +1 for adding '/'
            Ls.push_back(item.level == 0 ? item.length : Ls[item.level-1] + item.length + 1);
        }
    }

public:
    int lengthLongestPath(string input) {
        vector<int> Ls;
        int maxL = 0;
        Item item = getNext(input, 0);
        pushIntoLs(Ls, item);

        // only file counts
        if (item.isFile)
            maxL = max(maxL, Ls[item.level]);
        while (item.nextPos != input.size()) {
            item = getNext(input, item.nextPos);
            pushIntoLs(Ls, item);
            if (item.isFile)
                maxL = max(maxL, Ls[item.level]);
        }
        return maxL;
    }
};

int main() {
    Solution solution;
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << solution.lengthLongestPath(input) << endl;;
    return 0;
}
