/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        ans2(nums1, m, nums2, n);
    }

    void ans1(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        map<int, int> mapNum;
        for (int i = 0; i < m; i++)
        {
            int cur = nums1[i];
            if (mapNum.find(cur) == mapNum.end())
                mapNum.insert(make_pair(cur, 1));
            else
                mapNum[cur]++;
        }
        for (const auto &cur : nums2)
        {
            if (mapNum.find(cur) == mapNum.end())
                mapNum.insert(make_pair(cur, 1));
            else
                mapNum[cur]++;
        }
        nums1.clear();
        for (const auto &cur : mapNum)
        {
            for (int i = 0; i < cur.second; i++)
                nums1.push_back(cur.first);
        }
    }

    void ans2(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int end1 = m - 1, end2 = n - 1;
        while (end2 >= 0 && end1 >= 0)
        {
            if (nums1[end1] > nums2[end2])
            {
                swap(nums1[end1 + n], nums1[end1]);
                end1--;
            }
            else
            {
                swap(nums1[end1 + n], nums2[end2--]);
                n--;
            }
        }
        while (n > 0)
        {
            swap(nums1[end1 + n], nums2[end2--]);
            n--;
        }
    }
};
// @lc code=end
