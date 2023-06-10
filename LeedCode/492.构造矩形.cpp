/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int tmp = sqrt(area);
        if (tmp * tmp == area)
            return {tmp, tmp};
        while (tmp >= 1)
        {
            if (area % tmp == 0)
                return {area / tmp, tmp};
            tmp--;
        }
        return {};
    }
};
// @lc code=end
