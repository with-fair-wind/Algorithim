// @before-stub-for-debug-begin
#include "commoncppproblem118.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        vector<int> arr[numRows];
        arr[0] = vector<int>{1};
        for (int i = 0; i < numRows; i++)
        {
            if (i + 1 < numRows)
            {
                arr[i].insert(arr[i].begin(), 0);
                arr[i].push_back(0);
                for (int j = 0; j < arr[i].size() - 1; j++)
                    arr[i + 1].push_back(arr[i][j] + arr[i][j + 1]);
                arr[i].erase(arr[i].begin());
                arr[i].pop_back();
                res.push_back(arr[i]);
            }
            else
                res.push_back(arr[i]);
        }

        return res;
    }
};
// @lc code=end
