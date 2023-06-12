/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string cur;
        string res;
        while (ss >> cur)
        {
            reverse(cur.begin(), cur.end());
            res += (cur + " ");
        }
        res.erase(res.end() - 1);
        return res;
    }
};
// @lc code=end
