/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (!num)
            return "0";
        bool isNeg = (num >> 31) & 1;
        if (isNeg)
            num = (~num) + 1;
        string result;
        while (num)
        {
            result += (num % 7 + '0');
            num /= 7;
        }
        reverse(result.begin(), result.end());
        if (isNeg)
            result.insert(result.begin(), '-');
        return result;
    }
};
// @lc code=end
