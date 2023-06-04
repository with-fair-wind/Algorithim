// @before-stub-for-debug-begin
#include "commoncppproblem83.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *res = head, *cur = head, *mid = head;
        while (cur)
        {
            int tmp = cur->val;
            cur = cur->next;
            if (cur == nullptr)
                return res;
            while (tmp == cur->val)
            {
                cur = cur->next;
                if (cur == nullptr)
                {
                    mid->next = nullptr;
                    return res;
                }
            }
            mid->next = cur;
            mid = mid->next;
        }
        return res;
    }
};
// @lc code=end
