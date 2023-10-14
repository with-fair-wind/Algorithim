// @before-stub-for-debug-begin
#include "commoncppproblem24.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

#include <bits/stdc++.h>

using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// @lc code=start

// Definition for singly-linked list.

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *first = head, *second = head->next, *res = second;
        ListNode *next = nullptr, *prev = nullptr;
        while (first)
        {
            if (!second)
                break;
            next = second->next;
            first->next = next;
            second->next = first;
            if (prev)
                prev->next = second;
            prev = first;
            first = next;
            if (first)
                second = first->next;
        }
        return res;
    }
};
// @lc code=end
