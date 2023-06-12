/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

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
// 小套路」：一棵子树上的点在深度优先搜索序列（即先序遍历）中是连续的。 用KMP
// 哈希
class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return dfs(root, subRoot);
    }

    bool dfs(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;
        return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

    bool check(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if ((!root && subRoot) || (root && !subRoot) || root->val != subRoot->val)
            return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
};
// @lc code=end
