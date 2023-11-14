// @before-stub-for-debug-begin
#include "commoncppproblem86.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less_H = nullptr, *less_L = nullptr;
        ListNode *big_H = nullptr, *big_L = nullptr;
        ListNode *next = nullptr;
        while (head)
        {
            next = head->next;
            head->next = nullptr;
            if (head->val < x)
            {
                if (!less_H)
                    less_H = head;
                else
                    less_L->next = head;
                less_L = head;
                head = next;
            }
            else if (head->val >= x)
            {
                if (!big_H)
                    big_H = head;
                else
                    big_L->next = head;
                big_L = head;
                head = next;
            }
        }
        if (less_L)
            less_L->next = big_H;
        return less_H ? less_H : big_H;
    }
};
// @lc code=end
