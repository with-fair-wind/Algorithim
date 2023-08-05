/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        for (const char &ch : letters)
            if (ch > target)
                return ch;
        return letters[0];
    }
};
// @lc code=end
