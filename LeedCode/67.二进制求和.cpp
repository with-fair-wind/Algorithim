// @before-stub-for-debug-begin
#include "commoncppproblem67.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int carry = 0;
        auto ita = a.rbegin(), itb = b.rbegin();
        while (ita != a.rend() && itb != b.rend())
        {
            char cha = *ita, chb = *itb;
            if (cha != chb)
            {
                char cur = carry == 0 ? '1' : '0';
                res.insert(res.begin(), cur);
                carry = ((cur == '1') ? 0 : 1);
            }
            else
            {
                res.insert(res.begin(), carry == 0 ? '0' : '1');
                carry = ((cha == '0') ? 0 : 1);
            }
            ita++;
            itb++;
        }
        if (ita == a.rend() && itb == b.rend() && carry == 1)
        {
            res.insert(res.begin(), '1');
            return res;
        }
        auto iter = (ita == a.rend() ? itb : ita);
        string &rest = (ita == a.rend() ? b : a);
        if (carry == 0)
        {
            while (iter != rest.rend())
            {
                res.insert(res.begin(), *iter);
                iter++;
            }
        }
        else
        {
            while (iter != rest.rend())
            {
                if (*iter == '0')
                {
                    res.insert(res.begin(), '1');
                    iter++;
                    break;
                }
                else
                {
                    res.insert(res.begin(), '0');
                    iter++;
                }
                if (iter == rest.rend() && res[0] == '0')
                    res.insert(res.begin(), '1');
            }
            while (iter != rest.rend())
            {
                res.insert(res.begin(), *iter);
                iter++;
            }
        }
        return res;
    }
};
// @lc code=end
