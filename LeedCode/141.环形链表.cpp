/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start

// Definition for singly-linked list.

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return false;
        ListNode *slow = head->next, *quick = head->next->next;
        while (slow != quick)
        {
            if (quick->next == nullptr || quick->next->next == nullptr)
                return false;
            slow = slow->next;
            quick = quick->next->next;
        }
        return true;
    }
};
// @lc code=end
