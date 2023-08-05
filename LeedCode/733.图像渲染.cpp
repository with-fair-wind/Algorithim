/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int row = image.size();
        int col = image[0].size();
        int ref = image[sr][sc];
        infect(image, row, col, sr, sc, color, ref);
        return image;
    }

    void infect(vector<vector<int>> &image, int row, int col, int sr, int sc, int color, int ref)
    {
        if (ref == color)
            return;
        if (sr < 0 || sr >= row || sc < 0 || sc >= col || image[sr][sc] != ref)
            return;
        image[sr][sc] = color;
        infect(image, row, col, sr - 1, sc, color, ref);
        infect(image, row, col, sr + 1, sc, color, ref);
        infect(image, row, col, sr, sc - 1, color, ref);
        infect(image, row, col, sr, sc + 1, color, ref);
    }
};
// @lc code=end
