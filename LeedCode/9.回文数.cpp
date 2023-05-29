/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string ori = to_string(x);
        return string(ori.rbegin(), ori.rend()) == ori;
    }
};
// @lc code=end
