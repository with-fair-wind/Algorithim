// @before-stub-for-debug-begin
#include "commoncppproblem680.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int L = 0, R = s.length() - 1;
        while (L < R)
        {
            if (s[L] != s[R])
                return isPalindrome(s, ++L, R) || isPalindrome(s, --L, --R);
            else
            {
                L++;
                R--;
            }
        }
        return true;
    }

    bool isPalindrome(string s, int a, int b)
    {
        while (a < b)
        {
            if (s[a++] != s[b--])
                return false;
        }
        return true;
    }

    bool ans1(string s)
    {
        if (s == string(s.rbegin(), s.rend()))
            return true;
        for (int i = 0; i < s.length(); i++)
        {
            string tmp = s;
            tmp.erase(i, 1);
            if (tmp == string(tmp.rbegin(), tmp.rend()))
                return true;
        }
        return false;
    }
};
// @lc code=end
