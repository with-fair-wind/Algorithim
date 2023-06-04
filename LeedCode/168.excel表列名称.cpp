// @before-stub-for-debug-begin
#include "commoncppproblem168.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        std::string result;

        while (columnNumber)
        {
            int remainder = (columnNumber - 1) % 26; // 求余数，减1是为了保证余数在0-25的范围内
            char digit = 'A' + remainder;            // 将余数转换为对应的字母
            result += digit;                         // 将字母添加到结果字符串的前面
            columnNumber = (columnNumber - 1) / 26;  // 整数除以26，准备下一次迭代
        }

        return string(result.rbegin(), result.rend());
    }
};
// @lc code=end
