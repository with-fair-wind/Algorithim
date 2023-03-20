/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start

#include <cmath>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        int num = 0;
        ListNode *cur1 = headA, *cur2 = headB;
        while (cur1)
        {
            num++;
            cur1 = cur1->next;
        }
        while (cur2)
        {
            num--;
            cur2 = cur2->next;
        }
        if (cur1 != cur2)
            return nullptr;
        cur1 = num > 0 ? headA : headB;
        cur2 = cur1 == headA ? headB : headA;
        num = abs(num);
        while (num != 0)
        {
            cur1 = cur1->next;
            num--;
        }
        while (cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};
// @lc code=end
