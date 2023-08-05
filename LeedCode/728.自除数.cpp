/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;
        for (int i = left; i <= right; i++)
            if (isNatural(i))
                result.push_back(i);
        return result;
    }

    bool isNatural(int num)
    {
        int tmp = num;
        while (tmp)
        {
            int cur = tmp % 10;
            tmp /= 10;
            if (!cur)
                return false;
            if (num % cur != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
