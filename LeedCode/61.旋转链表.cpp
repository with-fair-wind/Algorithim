// @before-stub-for-debug-begin
#include "commoncppproblem61.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

// Definition for singly-linked list.

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !k)
            return head;

        int count = 0;
        ListNode *cur = head, *last = nullptr;
        while (cur)
        {
            count++;
            last = cur;
            cur = cur->next;
        }
        k %= count;
        if (!k)
            return head;
        ListNode *prev = head;
        cur = head;
        int num = count - k;

        for (int i = 0; i < num; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        last->next = head;
        prev->next = nullptr;
        return cur;
    }
};
// @lc code=end
