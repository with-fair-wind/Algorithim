/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        return printAllSubsequence_v2(s, t);
    }

    int printAllSubsquence(string str, string t)
    {
        string output;
        return func_v1(str, output, t);
    }

    int func_v1(string str, string output, string t)
    {
        if (str.empty())
            return output == t ? 1 : 0;
        return func_v1(str.substr(1), output, t) + func_v1(str.substr(1), output + str[0], t);
    }

    int printAllSubsequence_v2(const string &str, const string &t)
    {
        vector<char> chs(str.begin(), str.end());
        return process(chs, 0, t);
    }

    int process(vector<char> &chs, int i, const string &t)
    {
        // 如果i超过范围了，那前面[0~i-1]已经是一种结果了，直接打印就好了
        if (i == chs.size())
        {
            string res;
            for (char c : chs)
            {
                if (c != '\0')
                    res += c;
            }
            return res == t ? 1 : 0;
        }

        int res1 = process(chs, i + 1, t);
        char tmp = chs[i];
        chs[i] = '\0';
        int res2 = process(chs, i + 1, t);
        chs[i] = tmp;
        return res1 + res2;
    }
};
// @lc code=end
