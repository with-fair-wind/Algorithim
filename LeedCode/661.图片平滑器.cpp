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
        for (int i = 0; i < cols; i++)
    }
};
// @lc code=end
