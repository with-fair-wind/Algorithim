/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <stack>
#include <vector>

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // process(root, res);
        // return res;

        if (root == nullptr)
            return vector<int>();
        vector<int> res;
        stack<TreeNode *> stackNode;
        stack<TreeNode *> stackPos;
        stackNode.push(root);
        while (!stackNode.empty())
        {
            TreeNode *node = stackNode.top();
            stackNode.pop();
            stackPos.push(node);
            if (node->left)
                stackNode.push(node->left);
            if (node->right)
                stackNode.push(node->right);
        }
        while (!stackPos.empty())
        {
            TreeNode *node = stackPos.top();
            stackPos.pop();
            res.push_back(node->val);
        }
        return res;
    }

    void process(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        process(root->left, res);
        process(root->right, res);
        res.push_back(root->val);
    }
};
// @lc code=end
