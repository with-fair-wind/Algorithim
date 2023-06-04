// @before-stub-for-debug-begin
#include "commoncppproblem119.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> arr[rowIndex + 1];
        arr[0] = vector<int>{1};
        vector<int> res;
        for (int i = 0; i <= rowIndex; i++)
        {
            if (i + 1 <= rowIndex)
            {
                arr[i].insert(arr[i].begin(), 0);
                arr[i].push_back(0);
                for (int j = 0; j < arr[i].size() - 1; j++)
                    arr[i + 1].push_back(arr[i][j] + arr[i][j + 1]);
                arr[i].erase(arr[i].begin());
                arr[i].pop_back();
            }
            else
                res = arr[i];
        }
        return res;
    }
};
// @lc code=end
