// @before-stub-for-debug-begin
#include "commoncppproblem144.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // process(root, res);
        // return res;
        if (root == nullptr)
            return vector<int>();
        vector<int> res;
        stack<TreeNode *> stackNode;
        stackNode.push(root);
        while (!stackNode.empty())
        {
            TreeNode *node = stackNode.top();
            stackNode.pop();
            res.push_back(node->val);
            if (node->right)
                stackNode.push(node->right);
            if (node->left)
                stackNode.push(node->left);
        }
        return res;
    }

    void process(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        process(root->left, res);
        process(root->right, res);
    }
};
// @lc code=end
