/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    map<int, int> m_map;

public:
    TreeNode *f(const vector<int> &preorder, int l1, int r1, const vector<int> &inorder, int l2, int r2)
    {
        if (l1 > r1)
            return nullptr;
        if (l1 == r1)
            return new TreeNode(preorder[l1]);
        TreeNode *head = new TreeNode(preorder[l1]);
        int k = m_map[preorder[l1]];
        head->left = f(preorder, l1 + 1, l1 + k - l2, inorder, l2, k - 1);
        head->right = f(preorder, l1 + k - l2 + 1, r1, inorder, k + 1, r2);
        return head;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            m_map.insert(make_pair(inorder[i], i));

        return f(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end
