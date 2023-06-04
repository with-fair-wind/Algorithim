/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
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
    ListNode *reverseList(ListNode *head)
    {
        return reverseLinkedList(head);
    }
    ListNode *reverseLinkedList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// @lc code=end
