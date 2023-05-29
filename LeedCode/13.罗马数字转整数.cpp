/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (getchar(s[i]) >= getchar(s[i + 1]))
                res += getchar(s[i]);
            else
                res -= getchar(s[i]);
        }
        res += getchar(s[s.length() - 1]);
        return res;
    }

    int getchar(const char &ch)
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};
// @lc code=end
