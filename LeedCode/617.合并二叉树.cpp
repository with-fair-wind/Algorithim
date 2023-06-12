/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 || !root2)
            return !root1 ? root2 : root1;
        TreeNode *res = new TreeNode(root1->val + root2->val);
        res->left = mergeTrees(root1->left, root2->left);
        res->right = mergeTrees(root1->right, root2->right);
        return res;
    }
};
// @lc code=end
