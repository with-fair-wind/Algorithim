/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start

// Definition for a Node.

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> nodeMap;
        Node *cur = head;
        while (cur)
        {
            nodeMap.insert(make_pair(cur, new Node(cur->val)));
            cur = cur->next;
        }
        cur = head;
        while (cur)
        {
            nodeMap[cur]->next = cur->next ? nodeMap[cur->next] : nullptr;
            nodeMap[cur]->random = cur->random ? nodeMap[cur->random] : nullptr;
            cur = cur->next;
        }
        return nodeMap[head];
    }
};
// @lc code=end
