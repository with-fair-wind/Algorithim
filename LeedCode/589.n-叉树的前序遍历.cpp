/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
// @lc code=start

// Definition for a Node.

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (!root)
            return vector<int>();
        vector<int> res{root->val};
        for (int i = 0; i < root->children.size(); i++)
        {
            vector<int> cur = preorder(root->children[i]);
            res.insert(res.end(), cur.begin(), cur.end());
        }
        return res;
    }
};
// @lc code=end
