/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res;
        int count = 0;
        for (const int &cur : nums)
        {
            if (count == 0)
            {
                res = cur;
                count = 1;
            }
            else
            {
                if (res == cur)
                    count++;
                else
                    count--;
            }
        }
        return res;
    }
};
// @lc code=end
