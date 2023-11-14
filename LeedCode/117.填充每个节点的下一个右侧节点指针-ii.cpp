// @before-stub-for-debug-begin
#include "commoncppproblem117.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

#include <bits/stdc++.h>

using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val, Node *_left, Node *_right, Node *_next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };
// @lc code=start

// Definition for a Node.

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        queue<Node *> nodeQue;
        nodeQue.push(root);
        Node *prev = nullptr;
        while (!nodeQue.empty())
        {
            int size = nodeQue.size();
            for (int i = 0; i < size; i++)
            {
                Node *cur = nodeQue.front();
                nodeQue.pop();
                if (!prev)
                    prev = cur;
                else
                {
                    prev->next = cur;
                    prev = cur;
                }
                if (cur->left)
                    nodeQue.push(cur->left);
                if (cur->right)
                    nodeQue.push(cur->right);
            }
            prev->next = nullptr;
            prev = nullptr;
        }
        return root;
    }
};
// @lc code=end
