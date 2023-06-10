/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

#include <sstream>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
            res++;
        return res;
    }
};
// @lc code=end
