// @before-stub-for-debug-begin
#include "commoncppproblem203.h"
#include <string>
#include <vector>

using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start

// Definition for singly-linked list.

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *pre = head, *res = head, *cur = head;
        while (cur->val == val)
        {
            if (cur->next != nullptr)
            {
                cur = cur->next;
                pre = cur;
                res = cur;
            }
            else
                return nullptr;
        }
        if (pre->next != nullptr)
        {
            cur = pre->next;
            while (cur)
            {
                if (cur->val == val)
                {
                    pre->next = cur->next;
                    cur = cur->next;
                }
                else
                {
                    cur = cur->next;
                    pre = pre->next;
                }
            }
        }
        return res;
    }
};
// @lc code=end
