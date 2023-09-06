// @before-stub-for-debug-begin
#include "commoncppproblem7.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        string tmp = to_string(x);
        if (tmp[0] == '-')
        {
            std::string sub = tmp.substr(1);
            std::reverse(sub.begin(), sub.end());
            sub.insert(sub.begin(), '-');
            long long res = stoll(sub);
            if (res >= INT_MAX || res <= INT_MIN)
                return 0;
            return res;
        }
        else
        {
            std::reverse(tmp.begin(), tmp.end());
            long long res = stoll(tmp);
            if (res >= INT_MAX || res <= INT_MIN)
                return 0;
            return res;
        }
    }
};
// @lc code=end
