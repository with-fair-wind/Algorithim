/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        bool nozero = false;
        string res;
        for (int i = 31; i >= 0; i -= 4)
        {
            int tmp = num & (1 << (i - 3)) ? 1 : 0;
            tmp += num & (1 << (i - 2)) ? 2 : 0;
            tmp += num & (1 << (i - 1)) ? 4 : 0;
            tmp += num & (1 << (i)) ? 8 : 0;
            if (tmp != 0)
                nozero = true;
            if (nozero)
                res += tmp < 10 ? static_cast<char>('0' + tmp) : static_cast<char>('a' + tmp - 10);
        }
        return res;
    }
};
// @lc code=end
