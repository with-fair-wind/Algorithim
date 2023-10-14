/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    void f(string &path, int status, int n, vector<string> &res)
    {
        if (status < 0)
            return;
        if (n == 0)
        {
            res.push_back(path);
            return;
        }
        else if (!status)
        {
            path += '(';
            f(path, status + 1, n, res);
            path.pop_back();
        }
        else if (status == n)
        {
            path += ')';
            f(path, status - 1, n - 1, res);
            path.pop_back();
        }
        else
        {
            path += '(';
            f(path, status + 1, n, res);
            path.pop_back();

            path += ')';
            f(path, status - 1, n - 1, res);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string path;
        f(path, 0, n, res);
        return res;
    }
};
// @lc code=end
