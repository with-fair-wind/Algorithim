// @before-stub-for-debug-begin
#include "commoncppproblem496.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <list>
#include <map>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> next(nums2.size());
        stack<int> MostStack; // 从大到小
        map<int, int> mapnums;
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++)
        {
            mapnums.insert(make_pair(nums2[i], i));
            while (!MostStack.empty() && nums2[i] > nums2[MostStack.top()])
            {
                int lastIndex = MostStack.top();
                MostStack.pop();
                next[lastIndex] = i;
            }
            MostStack.push(i);
        }
        while (!MostStack.empty())
        {
            int lastIndex = MostStack.top();
            MostStack.pop();
            next[lastIndex] = -1;
        }
        for (int i = 0; i < nums1.size(); i++)
            res.push_back(next[mapnums[nums1[i]]] != -1 ? nums2[next[mapnums[nums1[i]]]] : -1);

        return res;
    }
};
// @lc code=end
