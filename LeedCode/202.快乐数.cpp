/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <cmath>
#include <set>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> setHappy;
        while (n != 1)
        {
            if (setHappy.find(n) == setHappy.end())
                setHappy.insert(n);
            else
                return false;
            int tmp = 0;
            while (n)
            {
                tmp += pow(n % 10, 2);
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};
// @lc code=end
