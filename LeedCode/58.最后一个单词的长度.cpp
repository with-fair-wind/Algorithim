/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <sstream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        return Ans2(s);
    }

    int Ans1(const string &s)
    {
        int res = 0;
        stringstream ss(s);
        string token;
        while (ss >> token)
            res = token.length();
        return res;
    }

    int Ans2(string s)
    {
        int res = 0;
        while (!s.empty() && s.back() == ' ')
            s.pop_back();
        for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
        {
            if (*iter != ' ')
                res++;
            else
                break;
        }
        return res;
    }
};
// @lc code=end
