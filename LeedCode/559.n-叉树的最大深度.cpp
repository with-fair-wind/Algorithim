/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */
#include <cmath>
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
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;
        int maxHeight = 0;
        for (int i = 0; i < root->children.size(); i++)
            maxHeight = max(maxHeight, maxDepth(root->children[i]));
        return maxHeight + 1;
    }
};
// @lc code=end
