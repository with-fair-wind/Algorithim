/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

#include <cctype>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (auto &ch : s)
            ch = tolower(ch);
        return s;
    }
};
// @lc code=end
