// @before-stub-for-debug-begin
#include "commoncppproblem92.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// @lc code=start

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *begin = dummy;
        for (int i = 0; i < left - 1; i++)
            begin = begin->next;
        ListNode *prev = nullptr, *next = nullptr, *cur = begin->next;
        for (int i = 0; i < right - left + 1; i++)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        begin->next->next = next;
        begin->next = prev;
        return dummy->next;
    }
};
// @lc code=end
