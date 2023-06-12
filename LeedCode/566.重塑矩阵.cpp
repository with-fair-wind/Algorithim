// @before-stub-for-debug-begin
#include "commoncppproblem566.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int row = mat.size(), col = mat[0].size();
        int area = row * col;
        if (r * c != area || r == row)
            return mat;
        vector<vector<int>> result;
        vector<int> tmp;
        for (int i = 0; i < row; i++)
            tmp.insert(tmp.end(), mat[i].begin(), mat[i].end());
        for (int i = 0; i < r; i++)
        {
            vector<int> cur;
            cur.insert(cur.end(), tmp.begin() + i * c, tmp.begin() + i * c + c);
            result.push_back(cur);
        }

        return result;
    }
};
// @lc code=end
