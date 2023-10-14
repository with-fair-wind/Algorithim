// @before-stub-for-debug-begin
#include "commoncppproblem17.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <bits/stdc++.h>
#include <map>
using namespace std;

// @lc code=start
class Solution
{
public:
#if 0
    vector<string> f(string digits, int index, map<char, vector<char>> &num2strMap)
    {
        if (index == digits.length())
            return vector<string>{""};
        if (digits[index] == '1')
            return f(digits, index + 1, num2strMap);
        vector<string> nexts = f(digits, index + 1, num2strMap);
        vector<string> res;
        for (auto &tmp : nexts)
            for (const auto &cur : num2strMap[digits[index]])
                res.push_back(cur + tmp);
        return res;
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        map<char, vector<char>> num2strMap{
            {'0', {' '}},
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };

        return f(digits, 0, num2strMap);
    }
#else

    void f(string digits, string &output, map<char, vector<char>> &num2strMap, vector<string> &res)
    {
        if (digits.empty())
            res.push_back(output);
        if (digits[0] == '1')
            f(digits.substr(1), output, num2strMap, res);
        for (const auto &cur : num2strMap[digits[0]])
        {
            output += cur;
            f(digits.substr(1), output, num2strMap, res);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        map<char, vector<char>> num2strMap{
            {'0', {' '}},
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };
        vector<string> res;
        string output = "";
        f(digits, output, num2strMap, res);
        return res;
    }
#endif
};
// @lc code=end
