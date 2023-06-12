/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

// Definition for a binary tree node.

class Solution
{
public:
    int lastnum = -1;
    int res = INT_MAX;

    int getMinimumDifference(TreeNode *root)
    {
        process(root);
        return res;
    }

    void process(TreeNode *root)
    {
        if (root == nullptr)
            return;
        process(root->left);
        if (lastnum == -1)
            lastnum = root->val;
        else
        {
            res = min(res, root->val - lastnum);
            lastnum = root->val;
        }
        process(root->right);
    }
};
// @lc code=end
