// @before-stub-for-debug-begin
#include "commoncppproblem40.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
    vector<vector<int>> f(const vector<int> &candidates, int index, vector<int> &path, int target)
    {
        if (target == 0)
            return vector<vector<int>>{path};
        vector<vector<int>> res;
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] <= target)
            {
                path.push_back(candidates[i]);
                vector<vector<int>> next = f(candidates, i + 1, path, target - candidates[i]);
                res.insert(res.end(), next.begin(), next.end());
                path.pop_back();
            }
        }
        return res;
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        return f(candidates, 0, path, target);
    }
};
// @lc code=end
