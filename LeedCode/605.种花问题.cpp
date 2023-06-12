/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

#include <vector>
using namespace std;

/**
 * 贪心
 * 能种花的地方
 *  当前位置没有花
 *  前面要么没有花, 要么是边界
 *  后面要么没有花, 要么是边界
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};
// @lc code=end
