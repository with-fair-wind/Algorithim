// @before-stub-for-debug-begin
#include "commoncppproblem415.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result;
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        int x, y, sum;
        while (i >= 0 || j >= 0 || add != 0)
        {
            x = i >= 0 ? num1[i] - '0' : 0;
            y = j >= 0 ? num2[j] - '0' : 0;
            sum = x + y + add;
            add = sum / 10;
            result += ('0' + sum % 10);
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string ans1(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int add = 0, index = 0;
        string res;
        char ch;
        int number1, number2, sum;
        while (index < num1.length() && index < num2.length())
        {
            number1 = num1[index] - '0';
            number2 = num2[index] - '0';
            sum = number1 + number2 + add;

            if (sum < 10)
            {
                ch = '0' + sum;
                add = 0;
            }
            else
            {
                ch = '0' + sum - 10;
                add = 1;
            }
            res += ch;
            index++;
        }
        if (add == 0)
        {
            if (num1.length() != num2.length())
                res += index == num1.length() ? num2.substr(index) : num1.substr(index);
        }
        else
        {
            if (num1.length() != num2.length())
            {
                string longstr = index == num1.length() ? num2 : num1;
                while (index < longstr.length())
                {
                    number2 = longstr[index] - '0';
                    sum = add + number2;

                    if (sum < 10)
                    {
                        ch = '0' + sum;
                        add = 0;
                    }
                    else
                    {
                        ch = '0' + sum - 10;
                        add = 1;
                    }
                    res += ch;
                    index++;
                }
                if (add == 1)
                    res += '1';
            }
            else
                res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// @lc code=end
