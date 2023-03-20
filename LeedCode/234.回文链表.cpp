/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
// Definition for singly-linked list.

#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        return isPalindromeList_v3(head);
    }

    bool isPalindromeList_v1(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *cur = head;
        stack<ListNode *> stackNode;
        while (cur != nullptr)
        {
            stackNode.push(cur);
            cur = cur->next;
        }
        while (!stackNode.empty())
        {
            if (stackNode.top()->val == head->val)
            {
                stackNode.pop();
                head = head->next;
            }
            else
                return false;
        }
        return true;
    }

    bool isPalindromeList_v2(ListNode *head)
    {
        if (head == nullptr)
            return false;
        if (head->next == nullptr)
            return true;
        // 从中点的后面第一个节点开始压栈
        ListNode *slow = head->next, *quick = head;
        stack<ListNode *> stackNode;
        while (quick->next != nullptr && quick->next->next != nullptr)
        {
            slow = slow->next;
            quick = quick->next->next;
        }
        while (slow != nullptr)
        {
            stackNode.push(slow);
            slow = slow->next;
        }
        while (!stackNode.empty())
        {
            if (stackNode.top()->val == head->val)
            {
                stackNode.pop();
                head = head->next;
            }
            else
                return false;
        }
        return true;
    }

    bool isPalindromeList_v3(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *slow = head, *quick = head;
        while (quick->next != nullptr && quick->next->next != nullptr)
        {
            slow = slow->next;
            quick = quick->next->next;
        }
        ListNode *end = reverseLinkedList(slow), *tmp = end;
        while (head != nullptr && end != nullptr)
        {
            if (head->val == end->val)
            {
                head = head->next;
                end = end->next;
            }
            else
            {
                reverseLinkedList(tmp);
                return false;
            }
        }
        reverseLinkedList(tmp);
        return true;
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
