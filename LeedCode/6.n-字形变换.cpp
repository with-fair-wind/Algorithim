/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
#if 0
        vector<list<char>> svec(numRows);
        int range = numRows + numRows - 2;
        int numAll = s.length() / range;
        int lastnum = s.length() % range;
        for (int i = 0; i < numAll; ++i)
        {
            string tmp = s.substr(i * range, range);
            for (int j = 0; j < tmp.length(); ++j)
            {
                if (j < numRows)
                    svec[j].push_back(tmp[j]);
                else
                    svec[numRows - 1 - (j - numRows + 1)].push_back(tmp[j]);
            }
        }
        string last = s.substr(numAll * range, lastnum);
        for (int i = 0; i < last.length(); ++i)
        {
            if (i < numRows)
                svec[i].push_back(last[i]);
            else
                svec[numRows - 1 - (i - numRows + 1)].push_back(last[i]);
        }

        string res;
        for (const auto &listcur : svec)
        {
            for (const auto &cur : listcur)
                res += cur;
        }
        return res;
#else
        vector<string> svec(numRows);
        int rowindex = 0, flag = -1;
        for (const auto &ch : s)
        {
            svec[rowindex].push_back(ch);
            if (rowindex == 0 || rowindex == numRows - 1)
                flag = -flag;
            rowindex += flag;
        }

        string res;
        for (const auto &cur : svec)
            res += cur;
        return res;

#endif
    }
};
// @lc code=end
