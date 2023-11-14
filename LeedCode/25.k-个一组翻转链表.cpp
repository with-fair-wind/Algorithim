/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

//  Definitiosn for singly-linked list.

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head), *tmp = head;
        int n = 0;
        while (tmp)
        {
            n++;
            tmp = tmp->next;
        }

        ListNode *prev = nullptr, *next = nullptr, *begin = dummy, *cur = head;
        while (n >= k)
        {
            n -= k;
            for (int i = 0; i < k; i++)
            {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            ListNode *tmp = begin->next;
            begin->next->next = next;
            begin->next = prev;
            begin = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end
