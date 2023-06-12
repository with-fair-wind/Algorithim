/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

#include <string>

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
    string tree2str(TreeNode *root)
    {
        if (!root->left && !root->right)
            return to_string(root->val);
        string res = to_string(root->val);
        if (root->left && root->right)
        {
            res += ("(" + tree2str(root->left) + ")");
            res += ("(" + tree2str(root->right) + ")");
        }
        else if (!root->left && root->right)
            res += ("()(" + tree2str(root->right) + ")");
        else
            res += ("(" + tree2str(root->left) + ")");
        return res;
    }
};
// @lc code=end
