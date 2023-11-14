// @before-stub-for-debug-begin
#include "commoncppproblem19.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (slow == head)
            return slow->next;
        prev->next = slow->next;
        return head;
    }
};
// @lc code=end
