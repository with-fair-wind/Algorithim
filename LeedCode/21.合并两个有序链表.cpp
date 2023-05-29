// @before-stub-for-debug-begin
#include "commoncppproblem21.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *res = new ListNode;
        ListNode *cur = res;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val >= list2->val)
            {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
            else
            {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            }
        }
        cur->next = list1 == nullptr ? list2 : list1;
        return res->next;
    }
};
// @lc code=end
