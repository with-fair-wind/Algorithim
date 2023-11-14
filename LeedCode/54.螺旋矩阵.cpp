/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int L = 0, R = matrix[0].size() - 1;
        int U = 0, D = matrix.size() - 1;
        while (1)
        {
            for (int i = L; i <= R; i++)
                res.emplace_back(matrix[U][i]);
            if (++U > D)
                break;
            for (int i = U; i <= D; i++)
                res.emplace_back(matrix[i][R]);
            if (--R < L)
                break;
            for (int i = R; i >= L; i--)
                res.emplace_back(matrix[D][i]);
            if (--D < U)
                break;
            for (int i = D; i >= U; i--)
                res.emplace_back(matrix[i][L]);
            if (++L > R)
                break;
        }
        return res;
    }
};
// @lc code=end
