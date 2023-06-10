// @before-stub-for-debug-begin
#include "commoncppproblem482.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

#include <cctype>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        int count = 0;
        string res;
        for (char &cur : s)
        {
            cur = toupper(cur);
            if (cur != '-')
            {
                count++;
                res += cur;
            }
        }
        if (count <= k)
            return res;
        res = "";
        int pre = count % k;
        int index = 0;
        if (pre != 0)
        {
            int i = 0;
            while (i < pre)
            {
                if (s[index] == '-')
                {
                    index++;
                    continue;
                }
                res += s[index++];
                i++;
            }
            res += '-';
        }
        count = 0;
        while (index < s.length())
        {
            if (s[index] == '-')
            {
                index++;
                continue;
            }
            res += s[index++];
            count++;
            if (count % k == 0)
                res += '-';
        }
        if (*(res.rbegin()) == '-')
            res.erase(res.end() - 1);
        return res;
    }
};
// @lc code=end
