/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int rows = img.size(), cols = img[0].size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for (int centerx = 0; centerx < rows; centerx++)
        {
            for (int centery = 0; centery < cols; centery++)
            {
                int sum = 0, count = 0;
                for (int i = centerx - 1; i <= centerx + 1; i++)
                {
                    for (int j = centery - 1; j <= centery + 1; j++)
                    {
                        if (!(i < 0 || i == rows || j < 0 || j == cols))
                        {
                            sum += img[i][j];
                            count++;
                        }
                    }
                }
                res[centerx][centery] = sum / count;
            }
        }
        return res;
    }
};
// @lc code=end
