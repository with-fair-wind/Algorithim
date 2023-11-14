/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

#include <bits/stdc++.h>

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
private:
    map<int, int> m_map;

public:
    TreeNode *f(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2)
    {
        if (l2 > r2)
            return nullptr;
        if (l2 == r2)
            return new TreeNode(postorder[r2]);
        TreeNode *head = new TreeNode(postorder[r2]);
        int index = m_map[postorder[r2]];
        head->left = f(inorder, l1, index - 1, postorder, l2, l2 + index - 1 - l1);
        head->right = f(inorder, index + 1, r1, postorder, r2 - r1 + index, r2 - 1);
        return head;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            m_map.insert(make_pair(inorder[i], i));

        return f(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
// @lc code=end
