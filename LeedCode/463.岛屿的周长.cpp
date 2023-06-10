// @before-stub-for-debug-begin
#include "commoncppproblem463.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        int res = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                    process(row, col, grid, i, j, res);
            }
        }
        return res;
    }

    void process(int row, int col, vector<vector<int>> &grid, int i, int j, int &res)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        res += 4;
        if (i + 1 < row)
            if (grid[i + 1][j])
                res--;
        if (i - 1 >= 0)
            if (grid[i - 1][j])
                res--;
        if (j + 1 < col)
            if (grid[i][j + 1])
                res--;
        if (j - 1 >= 0)
            if (grid[i][j - 1])
                res--;
        process(row, col, grid, i + 1, j, res);
        process(row, col, grid, i - 1, j, res);
        process(row, col, grid, i, j + 1, res);
        process(row, col, grid, i, j - 1, res);
    }
};
// @lc code=end
