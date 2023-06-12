/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if (ops.empty())
            return m * n;
        int row = ops.size();
        int minRow = INT_MAX, minCol = INT_MAX;
        for (int i = 0; i < row; i++)
        {
            minRow = min(minRow, ops[i][0]);
            minCol = min(minCol, ops[i][1]);
        }
        return minRow * minCol;
    }
};
// @lc code=end
